#include <iostream>
#include <chrono>
#include <functional>

template<typename Func, typename... Args>
auto measureTime(const std::string& funcName, Func&& func, Args&&... args){
    
    auto start = std::chrono::high_resolution_clock::now();  // Start timing

    // Run the function and capture its return value
    auto result = std::forward<Func>(func)(std::forward<Args>(args)...);

    auto end = std::chrono::high_resolution_clock::now();    // End timing

    // Calculate duration in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Function '" << funcName << "' execution took: " 
              << duration.count() << " ms\n";

    return result;  // Return the result of the executed function
}

