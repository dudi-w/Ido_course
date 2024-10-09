#include "connect4management.hpp"
#include "humanPlayer.hpp"
#include "randomComputerPlayer.hpp"
#include "minimaxPlayer.hpp"

int main(int argc, char const *argv[])
{
    cf::GridPlay board;
    // cf::HumanPlayer hp1("dudi","🤖");
    // cf::RandomComputerPlayer rcp;
    cf::MinimaxComputerPlayer mmcp1(5,board.getGrid(),"💻");
    cf::MinimaxComputerPlayer mmcp2(5,board.getGrid(), mmcp1.getShape(), "mmcp1", "💻");
    // mmcp1.setPlayer(mmcp2);
    // mmcp1.setNameAndShape("mmcp1", "💻");

    cf::Connect4Management cfm(mmcp1, mmcp2, board);
    cfm.play();
    
    return EXIT_SUCCESS;
}
