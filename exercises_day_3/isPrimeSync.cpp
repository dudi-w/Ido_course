#include <cmath>

using ull = unsigned long long;

bool isPrimeSync(ull n){
    ull sqrt_n = sqrt(n);
    for(ull i = 2; i < sqrt_n+1; ++i){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}