#include <iostream>

#include "isPrimeSync.cpp"
#include "isPrimeAsync.cpp"
#include "timeCounter.cpp"

int main(int argc, char const *argv[])
{
    ull n = std::stoull(argv[1]);
    std::cout<<std::boolalpha<<measureTime("isPrimeSync",isPrimeSync,n)<<std::endl;;
    std::cout<<std::boolalpha<<measureTime("isPrimeAsync",isPrimeAsync,n)<<std::endl;;
    return EXIT_SUCCESS;
}
