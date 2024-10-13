#include <limits>
#include <iostream>//todo remove

#include <cstdlib>
#include <ctime>

#include "minimaxPlayer.hpp"

cf::MinimaxComputerPlayer::MinimaxComputerPlayer(int depth, cf::gridType const& board, std::string_view opposingPlayerShape, std::string name, std::string shape)
: m_name(name)
, m_shape(shape)
, m_depth(depth)
, m_board(board)
, m_opposingPlayerShape(opposingPlayerShape)
{}

int cf::MinimaxComputerPlayer::playStep() const
{
    int bestMove = -1;
    int bestValue = std::numeric_limits<int>::min();
    int alpha = std::numeric_limits<int>::min();
    int beta = std::numeric_limits<int>::max();

    cf::gridType board = m_board;
    std::vector<int> stepsScore(board.size(),std::numeric_limits<int>::min());
    for(int col = 0; col < board.size(); ++col){
        if(board[col][0].empty()){
            makeMove(col, this->getShape(), board);
            int moveValue = minimax(board ,m_depth-1, false, alpha, beta);
            stepsScore[col] = moveValue;
            undoMove(col, this->getShape(), board);
            if(moveValue > bestValue){
                bestMove = col;
                bestValue = moveValue;
            }
            // alpha = std::max(alpha, bestValue);
            // std::cout<<"col = "<<col<<" bestMove = "<<bestMove<<"  moveValue =  "<<moveValue<<std::endl;
        }
    }
    // auto i = findRandomIndex(stepsScore)+1;
    // std::cout<<"i = "<<i<<std::endl;
    return findRandomIndex(stepsScore)+1;
}

std::string_view cf::MinimaxComputerPlayer::getName() const
{
    return m_name;
}

std::string_view cf::MinimaxComputerPlayer::getShape() const
{
    return m_shape;
}

void cf::MinimaxComputerPlayer::setOpposingPlayerShape(std::string& opposingPlayerShape)
{
    m_opposingPlayerShape = opposingPlayerShape;
    // std::cout<<m_opposingPlayerShape.getShape()<<std::endl;
}

void cf::MinimaxComputerPlayer::setNameAndShape(std::string name, std::string shape)
{
    m_name = name;
    m_shape = shape;
}

bool cf::MinimaxComputerPlayer::isBoardFull(cf::gridType const& board) const
{
    for(int col = 0; col < board.size(); ++col){
        if(isValidMove(col, board)){
            return false;
        }
    }
    return true;
}

int cf::MinimaxComputerPlayer::evaluate(cf::gridType& board) const
{
    for(int col = 0; col < board.size(); ++col){
        if(isWinningMove(col,this->getShape(), board)){
            return 1000;
        }
        if(isWinningMove(col,m_opposingPlayerShape,board)){
            return -1000;
        }
    }
    return 0;
}

int cf::MinimaxComputerPlayer::minimax(cf::gridType& board, int depth, bool maximizingPlayer, int alpha, int beta) const
{
    int score = evaluate(board);
    if(depth == 0 || score == 1000 || score == -1000 || isBoardFull(board)){
        return score;
    }

    if(maximizingPlayer){
        int maxEval = std::numeric_limits<int>::min();
        for(int col = 0; col < board.size(); ++col){
            if(isValidMove(col, board)){
                makeMove(col, this->getShape(), board);
                int eval = minimax(board, depth-1, false, alpha, beta);
                undoMove(col, this->getShape(), board);
                maxEval = std::max(maxEval, eval);
                alpha = std::max(alpha, eval);
                if(beta <= alpha){
                    break;
                }
            }
        }
        return maxEval;
    }else{
        int minEval = std::numeric_limits<int>::max();
        for(int col = 0; col < board.size(); ++col){
            if(isValidMove(col, board)){
                makeMove(col, m_opposingPlayerShape, board);
                int eval = minimax(board ,depth-1 , true, alpha, beta);
                undoMove(col, m_opposingPlayerShape, board);
                minEval = std::min(minEval, eval);
                beta = std::min(beta, eval);
                if(beta <= alpha){
                    break;
                }
            }
        }
        return minEval;
    }
}

bool cf::MinimaxComputerPlayer::isValidMove(int col, cf::gridType const &board) const
{
    return board[col][0].empty();
}

void cf::MinimaxComputerPlayer::makeMove(int col, std::string_view shape, cf::gridType& board) const
{
    for(int row = board[0].size() - 1; row >= 0; --row){
        if(board[col][row].empty()){
            board[col][row] = shape;
            break;
        }
    }
}

void cf::MinimaxComputerPlayer::undoMove(int col, std::string_view shape, cf::gridType &board) const
{
    for(int row = 0; row < board[0].size(); ++row){
        if(!board[col][row].empty() && board[col][row] == shape){
            board[col][row].clear();
            break;
        }
    }
}

bool cf::MinimaxComputerPlayer::isWinningMove(int col, std::string_view shape, cf::gridType const &board) const
{
    const int COLS = board.size();
    const int ROWS = board[0].size();
    const int CONNECT = 4;
    
    int row;
    for(row = board[0].size()-1; row >= 0 && !board[col][row].empty() ; --row);
    ++row;

    int count = 0;
    for(int c = 0; c < COLS; ++c){
        if(board[c][row] == shape){
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
        if(board[col][r] == shape){
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
    for (int r = row - std::min(row, col), c = col - std::min(row, col); r < ROWS && c < COLS; ++r, ++c) {
        if(board[c][r] == shape){
            ++count;
            if(count == CONNECT){
                return true;
            }
        }else{
            count = 0;
        }
    }
    
    // Check diagonal (top-right to bottom-left)
    count = 0;
    for(int r = row - std::min(row, COLS - 1 - col), c = col + std::min(row, COLS - 1 - col);r < ROWS && c >= 0; ++r, --c) {
        if(board[c][r] == shape){
            ++count;
            if(count == CONNECT){
                return true;
            }
        }else{
            count = 0;
        }
    }
    return false;
}

int cf::MinimaxComputerPlayer::findRandomIndex(std::vector<int> const& arr) {
    std::vector<int> positiveIndices;
    std::vector<int> zeroIndices;
    std::vector<int> negativeIndices;

    // Categorize the indices based on their values
    for(int i = 0; i < arr.size(); ++i){
        if(arr[i] > 0) {
            positiveIndices.push_back(i);
        }else if(arr[i] == 0) {
            zeroIndices.push_back(i);
        }else if(arr[i] >= -1000){
            negativeIndices.push_back(i);
        }
    }

    // Seed the random number generator
    std::srand(std::time(nullptr));

    // Return a random index based on the conditions
    if(!positiveIndices.empty()){
        return positiveIndices[std::rand() % positiveIndices.size()];
    }else if(!zeroIndices.empty()) {
        return zeroIndices[std::rand() % zeroIndices.size()];
    }else /*if(!negativeIndices.empty())*/{
        return negativeIndices[std::rand() % negativeIndices.size()];
    }

    // If the array is empty, return -1 (or handle the case as needed)
    return -1;
}
