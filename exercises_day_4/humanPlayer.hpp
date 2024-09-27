#ifndef HUMAN_PLAYER_HPP
#define HUMAN_PLAYER_HPP

#include <string>

#include "IFplayer.hpp"

namespace cf { //Connect Four

class HumanPlayer : public IPlayer
{
public:
    explicit HumanPlayer(std::string name, std::string shape);
    explicit HumanPlayer();
    HumanPlayer(HumanPlayer const& other) = default;
    HumanPlayer& operator=(HumanPlayer const& other) = default;
    virtual ~HumanPlayer() = default;

    int playStep() const override;
    std::string_view getName() const override;
    std::string_view getShape() const override;

private:
    std::string m_name;
    std::string m_shape;
};

}// namespace cf

#endif
