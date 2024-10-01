#ifndef RANDOM_COMPUTER_PLAYER_HPP
#define RANDOM_COMPUTER_PLAYER_HPP

#include <string>

#include "IFplayer.hpp"

namespace cf { //Connect Four

class RandomComputerPlayer : public IPlayer
{
public:
    explicit RandomComputerPlayer();
    RandomComputerPlayer(RandomComputerPlayer const& other) = default;
    RandomComputerPlayer& operator=(RandomComputerPlayer const& other) = default;
    virtual ~RandomComputerPlayer() = default;

    int playStep() const override;
    std::string_view getName() const override;
    std::string_view getShape() const override;

private:
    std::string m_name;
    std::string m_shape;
};

}// namespace cf

#endif
