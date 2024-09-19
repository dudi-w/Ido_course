## Day 3: C++ Programming - Prime Number Checker with Multi-threading

#### Exercise 1: Implement the isPrimeSync function
This function should accept an integer as input and return a boolean indicating whether the number is prime.
Use a linear algorithm to check for primality.
This function should run in a single thread.

#### Exercise 2: Implement the isPrimeAsync function
This function should accept an integer to check and the number of threads to use.
Divide the work of checking primality among the specified number of threads (5 in this case).
Ensure proper synchronization between threads to avoid race conditions.
Return a boolean indicating whether the number is prime.

#### In the main function:
Use std::chrono to measure and print the execution time for both the single-threaded and multi-threaded versions.
Ensure that both versions produce the same result for correctness.

## Run and test

to run the tests on the exercises in this folder
```sh
g++ -std=c++20 -pthread -o main main.cpp
./main
```