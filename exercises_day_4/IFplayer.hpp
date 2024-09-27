#ifndef IPLAYER_HPP
#define IPLAYER_HPP

#include <string_view>

namespace cf { //Connect Four

class IPlayer
{
public:
    virtual ~IPlayer() = default;

    virtual int playStep() const = 0;
    virtual std::string_view getName() const = 0;
    virtual std::string_view getShape() const = 0;
};

}// namespace cf

#endif
