#include <iostream>
#include <tuple>
#include <thread>
#include <chrono>

#include "connect4management.hpp"

using namespace std::chrono_literals;

cf::Connect4Management::Connect4Management(cf::IPlayer &player1, cf::IPlayer &player2, cf::GridPlay& grid)
: m_player1(player1)
, m_player2(player2)
, m_grid(grid)
, m_steps(false)
{
    if(m_player1.getShape() == m_player2.getShape()){
        std::cout<<"Both players have the same shape\nI change the shape of a player with the name"<<player1.getName()<<"the next shape 🤑"<<std::endl;
        //todo change emoji
    }
}

void cf::Connect4Management::play()
{
    int i,j;
    do{
        if(!m_steps){
            std::tie(i,j) = makeStep(m_player1);
        }else{
            std::tie(i,j) = makeStep(m_player2);
        }
        m_steps = !m_steps;
    }while(!isGameOver(i,j));
    winMessage();
}

bool cf::Connect4Management::isGameOver(int lastCol, int lastRow) const
{
    const int COLS = m_grid.getGrid().size();
    const int ROWS = m_grid.getGrid()[0].size();
    const int CONNECT = 4;
    auto board = m_grid.getGrid();
    auto shape = board[lastCol][lastRow];
    
    // Check horizontal
    int count = 0;
    for(int c = 0; c < COLS; ++c){
        if(board[c][lastRow] == shape){
            ++count;
            if(count == CONNECT){
                return true;
            }
        }else{
            count = 0;
        }
    }
    
    // Check vertical
    count = 0;
    for(int r = 0; r < ROWS; ++r){
        if(board[lastCol][r] == shape){
            ++count;
            if(count == CONNECT){
                return true;
            }
        }else{
            count = 0;
        }
    }
    
    // Check diagonal (top-left to bottom-right)
    count = 0;
    for (int r = lastRow - std::min(lastRow, lastCol), c = lastCol - std::min(lastRow, lastCol); r < ROWS && c < COLS; ++r, ++c) {
        if(board[r][c] == shape){
            count++;
            if(count == CONNECT){
                return true;
            }
        }else{
            count = 0;
        }
    }
    
    // Check diagonal (top-right to bottom-left)
    count = 0;
    for(int r = lastRow - std::min(lastRow, COLS - 1 - lastCol), c = lastCol + std::min(lastRow, COLS - 1 - lastCol);r < ROWS && c >= 0; ++r, --c) {
        if(board[r][c] == shape){
            count++;
            if(count == CONNECT){
                return true;
            }
        }else{
            count = 0;
        }
    }
    
    // Check if board is full
    for(int c = 0; c < COLS; ++c){
        if(board[c][0].empty()){
            return false;
        }
    }
    return false;
}

std::pair<int,int> cf::Connect4Management::makeStep(cf::IPlayer &player) const
{
    int i = 0;
    int j = 0;
    while(!(i = player.playStep()) || !m_grid.isEmptyCell(--i,j)){
        std::cout<<"Something is wrong, please try again"<<std::endl;
    }
    m_grid.insert(i,j,player.getShape());
    do{
        std::this_thread::sleep_for(100ms);
        m_grid.display();
    }while(m_grid.move(i,j-1,i,++j));
    return std::pair<int,int>(i,j-1);
}

void cf::Connect4Management::winMessage() const
{
    std::string mess = "Player ";
    cf::IPlayer& winPlayer = !m_steps ? m_player2 : m_player1;
    mess += winPlayer.getName();
    mess += " ";
    mess += winPlayer.getShape();
    mess += " has won!!!\nCongratulations";
    std::cout<<mess<<std::endl;
}
