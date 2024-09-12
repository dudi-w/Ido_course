#include <thread>
#include <iostream>
#include <atomic>
#include <functional>
#include <mutex>
#include <semaphore>

void unsafeIncrument(uint& v, size_t amount){
    for(size_t i = 0; i < amount; ++i){
        ++v;
    }
}

void atomicSafeIncrument(std::atomic<uint>& v, size_t amount){
    for(size_t i = 0; i < amount; ++i){
        ++v;
    }
}

void mutexSafeIncrument(uint& v, size_t amount, std::mutex& mt){
    mt.lock();
    unsafeIncrument(v,amount);
    mt.unlock();
}

void uniqueLockSafeIncrument(uint& v, size_t amount, std::mutex& mt){
    std::unique_lock<std::mutex> lock(mt);
    unsafeIncrument(v,amount);
}

void semaphoreSafeIncrument(uint& v, size_t amount, std::binary_semaphore& mt){
    mt.acquire();
    unsafeIncrument(v,amount);
    mt.release();
}

void runUnsafeIncrument(){
    uint val = 0;
    std::thread t1(unsafeIncrument,std::ref(val),10000000);
    std::thread t2(unsafeIncrument,std::ref(val),10000000);
    t1.join();
    t2.join();
    std::cout<<"runUnsafeIncrument : val = "<<val<<std::endl;
}

void runAtomicSafeIncrument(){
    std::atomic<uint> val = 0;
    std::thread t1(atomicSafeIncrument,std::ref(val),10000000);
    std::thread t2(atomicSafeIncrument,std::ref(val),10000000);
    t1.join();
    t2.join();
    std::cout<<"atomicSafeIncrument : val = "<<val<<std::endl;
}

void runMutexSafeIncrument(){
    uint val = 0;
    std::mutex mt;
    std::thread t1(mutexSafeIncrument,std::ref(val),10000000, std::ref(mt));
    std::thread t2(mutexSafeIncrument,std::ref(val),10000000, std::ref(mt));
    t1.join();
    t2.join();
    std::cout<<"mutexSafeIncrument : val = "<<val<<std::endl;
}

void runSemaphoreSafeIncrument(){
    uint val = 0;
    std::binary_semaphore bs(1);
    std::thread t1(semaphoreSafeIncrument,std::ref(val),10000000, std::ref(bs));
    std::thread t2(semaphoreSafeIncrument,std::ref(val),10000000, std::ref(bs));
    t1.join();
    t2.join();
    std::cout<<"semaphoreSafeIncrument : val = "<<val<<std::endl;
}

void runUniqueLockSafeIncrument(){
    uint val = 0;
    std::mutex mt;
    std::thread t1(uniqueLockSafeIncrument,std::ref(val),10000000, std::ref(mt));
    std::thread t2(uniqueLockSafeIncrument,std::ref(val),10000000, std::ref(mt));
    t1.join();
    t2.join();
    std::cout<<"uniqueLockSafeIncrument : val = "<<val<<std::endl;
}

int main(int argc, char const *argv[])
{
    runUnsafeIncrument();
    runAtomicSafeIncrument();
    runMutexSafeIncrument();
    runSemaphoreSafeIncrument();
    runUniqueLockSafeIncrument();
    return EXIT_SUCCESS;
}