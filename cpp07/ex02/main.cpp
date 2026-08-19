#include <iostream>
#include "Array.hpp"

int main() {
    Array<int> emptyArr;
    std::cout << emptyArr.size() << std::endl;

    Array<int> arr(5);
    for (unsigned int i = 0; i < arr.size(); i++) {
        arr[i] = i * 5;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    Array<int> copyArr(arr);
    copyArr[0] = 76;
    
    std::cout << arr[0] << std::endl;
    std::cout << copyArr[0] << std::endl;

    try {
        arr[10] = 42;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    Array<std::string> strArr(2);
    strArr[0] = "Hello";
    strArr[1] = "42";
    std::cout << strArr[0] << " " << strArr[1] << std::endl;

    return 0;
}
