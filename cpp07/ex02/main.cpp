#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    Array<int> emptyArr;
    std::cout << emptyArr.size() << std::endl;

    Array<int> arr(5);
    for (unsigned int i = 0; i < arr.size(); i++) {
        arr[i] = (i + 1) * 10;
    }

    Array<int> copyArr(arr);
    copyArr[0] = 999;
    std::cout << arr[0] << " " << copyArr[0] << std::endl;

    Array<int> assignedArr;
    assignedArr = arr;
    assignedArr[0] = 555;
    std::cout << arr[0] << " " << assignedArr[0] << std::endl;

    const Array<int> constArr = arr;
    std::cout << constArr[2] << std::endl;

    try
    {
        arr[10] = 42;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    Array<std::string> strArr(2);
    strArr[0] = "Hello";
    strArr[1] = "42";
    std::cout << strArr[0] << " " << strArr[1] << std::endl;

    return 0;
}