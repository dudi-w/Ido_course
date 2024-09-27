#include "connect4management.hpp"
#include "humanPlayer.hpp"

int main(int argc, char const *argv[])
{
    cf::GridPlay board;
    cf::HumanPlayer hp1("dudi","😺");
    cf::HumanPlayer hp2("shoshi","🎃");

    cf::Connect4Management cfm(hp1,hp2,board);
    cfm.play();
    return EXIT_SUCCESS;
}
