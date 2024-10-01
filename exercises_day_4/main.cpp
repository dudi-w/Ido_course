#include "connect4management.hpp"
#include "humanPlayer.hpp"
#include "randomComputerPlayer.hpp"

int main(int argc, char const *argv[])
{
    cf::GridPlay board;
    cf::HumanPlayer hp1("dudi","😺");
    cf::RandomComputerPlayer rcp;

    cf::Connect4Management cfm(hp1,rcp,board);
    cfm.play();
    
    return EXIT_SUCCESS;
}
