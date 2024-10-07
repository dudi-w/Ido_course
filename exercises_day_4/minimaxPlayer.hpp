#ifndef MINIMAX_COMPUTER_PLAYER_HPP
#define MINIMAX_COMPUTER_PLAYER_HPP

#include <string>
#include <iostream>//TODO

#include "IFplayer.hpp"
#include "gridPlay.hpp"

namespace cf { //Connect Four

class MinimaxComputerPlayer : public IPlayer
{
public:
    explicit MinimaxComputerPlayer(int depth, cf::gridType const& board, cf::IPlayer& opposingPlayer);
    MinimaxComputerPlayer(MinimaxComputerPlayer const& other) = default;
    MinimaxComputerPlayer& operator=(MinimaxComputerPlayer const& other) = default;
    virtual ~MinimaxComputerPlayer() = default;

    int playStep() const override;
    std::string_view getName() const override;
    std::string_view getShape() const override;
    void setPlayer(cf::IPlayer& opposingPlayer){m_opposingPlayer = opposingPlayer; std::cout<<m_opposingPlayer.getShape()<<std::endl;};
    void setnameAndShape(std::string name, std::string shape){m_name = name; m_shape = shape; std::cout<<this->getShape()<<std::endl;};

private:
    // int findBestMove(int depth) const;
    int evaluate(cf::gridType& board) const;
    int minimax(cf::gridType& board, int depth, bool maximizingPlayer, int alpha, int beta) const;
    bool isValidMove(int col, cf::gridType const& board) const;
    void makeMove(int col, cf::IPlayer const& player, cf::gridType& board) const;
    void undoMove(int col, cf::IPlayer const& player, cf::gridType& board) const;
    bool isWinningMove(int col, cf::IPlayer const& player, cf::gridType const& board) const;
    bool isBoardFull(cf::gridType const& board) const;


    
private:
    std::string m_name;
    std::string m_shape;

    int m_depth;
    cf::gridType const& m_board;
    // cf::gridType m_boardCopy;
    cf::IPlayer& m_opposingPlayer;//TODO const
};

}// namespace cf

#endif
