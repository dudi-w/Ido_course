#include <limits>
#include <iostream>//todo remove

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

    for(int col = 0; col < board.size(); ++col){
        if(board[col][0].empty()){
            makeMove(col, this->getShape(), board);
            int moveValue = minimax(board ,m_depth-1, false, alpha, beta);
            undoMove(col, this->getShape(), board);
            if(moveValue > bestValue){
                bestMove = col;
                bestValue = moveValue;
            }
            alpha = std::max(alpha, bestValue);
        std::cout<<"bestMove = "<<bestMove<<"  moveValue =  "<<moveValue<<std::endl;
        }
    }
    return bestMove+1;
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

// int cf::MinimaxComputerPlayer::findBestMove(int depth) const
// {
//     int bestMove = -1;
//     int bestValue = std::numeric_limits<int>::min();
//     int alpha = std::numeric_limits<int>::min();
//     int beta = std::numeric_limits<int>::max();

//     cf::gridType board = board;

//     for(int col = 0; col < board.size(); ++col){
//         if(board[col][0].empty()){
//             makeMove(col, *this, board);
//             int moveValue = minimax(board ,depth - 1, false, alpha, beta);
//             undoMove(col,*this, board);
//             if(moveValue > bestValue){
//                 bestMove = col;
//                 bestValue = moveValue;
//             }
//             alpha = std::max(alpha, bestValue);
//         }
//     }
//     return bestMove;
// }

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
                // if(beta <= alpha){
                //     break;
                // }
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
                // if(beta <= alpha){
                //     break;
                // }
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


// const int ROWS = 6;
// const int COLS = 7;
// const int PLAYER = 1;
// const int AI = 2;

// class ConnectFour {
// private:
//     std::vector<std::vector<int>> board;

// public:
//     ConnectFour() : board(ROWS, std::vector<int>(COLS, 0)){}

//     bool isValidMove(int col){
//         return board[0][col] == 0;
//     }

//     void makeMove(int col, int player){
//         for(int row = ROWS - 1; row >= 0; row--){
//             if(board[col][row] == 0){
//                 board[col][row] = player;
//                 break;
//             }
//         }
//     }

//     void undoMove(int col){
//         for(int row = 0; row < ROWS; row++){
//             if(board[col][row] != 0){
//                 board[col][row] = 0;
//                 break;
//             }
//         }
//     }

//     bool isWinningMove(int col, cf::IPlayer& player){
//         int row;
//         for(row = ROWS - 1; row >= 0 && board[col][row] != ; row--);
        
//         if(row < 0){
//             return false;
//         }

//         // Check horizontal
//         int count = 0;
//         for(int c = std::max(0, col - 3); c < std::min(COLS, col + 4); c++){
//             if(board[row][c] == player) count++;
//             else count = 0;
//             if(count == 4) return true;
//         }

//         // Check vertical
//         count = 0;
//         for(int r = row; r < std::min(ROWS, row + 4); r++){
//             if(board[r][col] == player) count++;
//             else break;
//         }
//         if(count == 4) return true;

//         // Check diagonal (top-left to bottom-right)
//         count = 0;
//         for(int i = -3; i <= 3; i++){
//             int r = row + i;
//             int c = col + i;
//             if(r < 0 || r >= ROWS || c < 0 || c >= COLS) continue;
//             if(board[r][c] == player) count++;
//             else count = 0;
//             if(count == 4) return true;
//         }

//         // Check diagonal (top-right to bottom-left)
//         count = 0;
//         for(int i = -3; i <= 3; i++){
//             int r = row + i;
//             int c = col - i;
//             if(r < 0 || r >= ROWS || c < 0 || c >= COLS) continue;
//             if(board[r][c] == player) count++;
//             else count = 0;
//             if(count == 4) return true;
//         }

//         return false;
//     }

//     bool isBoardFull(){
//         for(int col = 0; col < COLS; ++col){
//             if(isValidMove(col)) return false;
//         }
//         return true;
//     }

//     int evaluate(){
//         for(int col = 0; col < COLS; ++col){
//             if(isWinningMove(col, AI)) return 1000;
//             if(isWinningMove(col, PLAYER)) return -1000;
//         }
//         return 0;
//     }

//     int minimax(int depth, bool maximizingPlayer, int alpha, int beta){
//         int score = evaluate();
        
//         if(depth == 0 || score == 1000 || score == -1000 || isBoardFull()){
//             return score;
//         }

//         if(maximizingPlayer){
//             int maxEval = std::numeric_limits<int>::min();
//             for(int col = 0; col < COLS; ++col){
//                 if(isValidMove(col)){
//                     makeMove(col, AI);
//                     int eval = minimax(depth - 1, false, alpha, beta);
//                     undoMove(col);
//                     maxEval = std::max(maxEval, eval);
//                     alpha = std::max(alpha, eval);
//                     if(beta <= alpha) break;
//                 }
//             }
//             return maxEval;
//         } else {
//             int minEval = std::numeric_limits<int>::max();
//             for(int col = 0; col < COLS; ++col){
//                 if(isValidMove(col)){
//                     makeMove(col, PLAYER);
//                     int eval = minimax(depth - 1, true, alpha, beta);
//                     undoMove(col);
//                     minEval = std::min(minEval, eval);
//                     beta = std::min(beta, eval);
//                     if(beta <= alpha) break;
//                 }
//             }
//             return minEval;
//         }
//     }

//     int findBestMove(int depth){
//         int bestMove = -1;
//         int bestValue = std::numeric_limits<int>::min();
//         int alpha = std::numeric_limits<int>::min();
//         int beta = std::numeric_limits<int>::max();

//         for(int col = 0; col < COLS; ++col){
//             if(isValidMove(col)){
//                 makeMove(col, AI);
//                 int moveValue = minimax(depth - 1, false, alpha, beta);
//                 undoMove(col);

//                 if(moveValue > bestValue){
//                     bestMove = col;
//                     bestValue = moveValue;
//                 }
//                 alpha = std::max(alpha, bestValue);
//             }
//         }

//         return bestMove;
//     }
// };

