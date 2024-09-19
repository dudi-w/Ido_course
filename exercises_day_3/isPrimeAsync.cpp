#include <cmath>
#include <atomic>
#include <array>
#include <thread>

using ull = unsigned long long;

void isPrime(ull n, ull start, ull end, std::atomic<bool>& res){
    for(ull i = start; i < end+1 ; ++i){
        if(res == false){
            return;
        }
        if(n%i == 0){
            res = false;
        }
    }
}

bool isPrimeAsync(ull n){
    int const numOfThreads = 8;
    ull sqrt_n = static_cast<ull>(sqrt(n));
    ull unit = (sqrt_n/numOfThreads)+1;

    std::atomic<bool> res = true;
    std::array<std::jthread,numOfThreads> threads;
    for(int i = 0 ; i < numOfThreads; ++i){
        threads[i] = std::jthread(isPrime ,n ,2+(unit*i), 2+(unit*(i+1)),std::ref(res)); 
    }
    return res;
}