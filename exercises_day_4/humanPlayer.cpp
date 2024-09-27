#include <iostream>

#include "humanPlayer.hpp"

cf::HumanPlayer::HumanPlayer(std::string name, std::string shape)
: m_name{name}
, m_shape{shape}
{}

cf::HumanPlayer::HumanPlayer()
{
    std::cout<<"Choose a player name"<<std::endl;
    std::string result;
    std::cin.clear();
    std::cin>>m_name;

    std::cout<<"Choose a imoji (like 🤥 😡 😁 🤓)"<<std::endl;
    result.clear();
    std::cin.clear();
    std::cin>>m_shape; 
}

int cf::HumanPlayer::playStep() const
{
    std::cout<<"Choose a number from 1 to 7"<<std::endl;
    std::string result;
    std::cin.clear();
    std::cin>>result;
    int n = stoi(result);
    if(n > 0 && n < 8){
    std::cout<<n<<result<<std::endl;
        return n;
    }
    return 0;
}

std::string_view cf::HumanPlayer::getName() const
{
    return m_name;
}

std::string_view cf::HumanPlayer::getShape() const
{
    return m_shape;
}
