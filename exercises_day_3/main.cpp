#include <iostream>

#include "isPrimeSync.cpp"
#include "isPrimeAsync.cpp"
#include "timeCounter.cpp"

int main(int argc, char const *argv[])
{
    std::cout<<std::boolalpha<<measureTime("isPrimeSync",isPrimeSync,12963097176472289281)<<std::endl;;
    std::cout<<std::boolalpha<<measureTime("isPrimeAsync",isPrimeAsync,12963097176472289281)<<std::endl;;
    return EXIT_SUCCESS;
}
