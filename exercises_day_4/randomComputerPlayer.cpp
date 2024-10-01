#include <time.h> 

#include "randomComputerPlayer.hpp"

cf::RandomComputerPlayer::RandomComputerPlayer()
: m_name("computer")
, m_shape("💻")
{
    srand(time(0));
}

int cf::RandomComputerPlayer::playStep() const
{ 
    return 1+(rand()%7);
}

std::string_view cf::RandomComputerPlayer::getName() const
{
    return m_name;
}

std::string_view cf::RandomComputerPlayer::getShape() const
{
    return m_shape;
}
