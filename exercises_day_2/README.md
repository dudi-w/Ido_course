## Day 2: C++ Programming - Multithreading and Thread-Safe Data Structures

#### Exercise 1: Incrementing a Value Using Multiple Threads
Create programs that increment a value from zero to 10 million using two different threads. Implement the following versions:

1. An unsafe program without protection.

2. A program with protection of the critical sections using a mutex.

3. A program with protection of the critical sections using a binary semaphore.

#### Exercise 2: Thread-Safe Linked List
Implement a thread-safe linked list data structure. You may choose to use a built-in data structure or implement it from scratch. Use any appropriate protection mechanism to ensure thread safety.

Note: When compiling C++ programs that involve threads, remember to link the pthread library using the `-pthread` flag during compilation.

Example compilation command:
```bash
g++ -pthread your_program.cpp -o your_program
```