#include <iostream>
#include <chrono>
#include <functional>


#define createFunctionAndName(func) std::make_pair<std::function<void()> ,std::string>(func, #func)

template<typename Func, typename... Args>
void measureTime(const std::string& funcName, Func&& func, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();  // Start timing

    std::forward<Func>(func)(std::forward<Args>(args)...);   // Run the function

    auto end = std::chrono::high_resolution_clock::now();    // End timing

    // Calculate duration in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Function '" << funcName << "' execution took: " 
              << duration.count() << " ms\n"<<__func__;
}

// Example function to be timed
void exampleFunction(int n) {
    for (int i = 0; i < n; ++i);  // Dummy loop to consume time
}

void foo1(void){}

int main() {
    std::vector<std::pair<std::function<void()> ,std::string>> myFuncVector;
    myFuncVector.push_back(createFunctionAndName(foo1));
    measureTime("exampleFunction", exampleFunction, 100000000);  // Measure time for exampleFunction
    return 0;
}
