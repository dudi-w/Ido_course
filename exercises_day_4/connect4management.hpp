#ifndef CONNECT_4_MANAGEMENT_HPP
#define CONNECT_4_MANAGEMENT_HPP

#include "IFplayer.hpp"
#include "gridPlay.hpp"

namespace cf {

class Connect4Management
{
public:
    explicit Connect4Management(cf::IPlayer& player1, cf::IPlayer& player2, cf::GridPlay& grid);
    Connect4Management(Connect4Management const& other) = default;
    Connect4Management& operator=(Connect4Management const& other) = default;
    ~Connect4Management() = default;

    void play();

private:
    bool isGameOver(int i, int j) const;
    std::pair<int,int> makeStep(cf::IPlayer& player) const;

private:
    cf::IPlayer& m_player1;
    cf::IPlayer& m_player2;
    cf::GridPlay& m_grid;

    bool m_steps;
};

}// namespace cf

#endif
