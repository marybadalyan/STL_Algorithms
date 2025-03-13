#include <iostream>
#include <vector>
#include "atlAlg.h"

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {3, 4};

    // Test find_if_not
    auto it1 = stlAlg::find_if_not(vec1.begin(), vec1.end(), [](int i) { return i < 3; });
    if (it1 != vec1.end()) {
        std::cout << "First element not less than 3: " << *it1 << std::endl;
    } else {
        std::cout << "All elements are less than 3" << std::endl;
    }

    // Test all_of
    bool all = stlAlg::all_of(vec1.begin(), vec1.end(), [](int i) { return i > 0; });
    std::cout << "All elements are greater than 0: " << std::boolalpha << all << std::endl;

    // Test find_if
    auto it2 = stlAlg::find_if(vec1.begin(), vec1.end(), [](int i) { return i == 3; });
    if (it2 != vec1.end()) {
        std::cout << "Found element equal to 3: " << *it2 << std::endl;
    } else {
        std::cout << "Element equal to 3 not found" << std::endl;
    }

    // Test any_of
    bool any = stlAlg::any_of(vec1.begin(), vec1.end(), [](int i) { return i == 3; });
    std::cout << "Any element equal to 3: " << std::boolalpha << any << std::endl;

    // Test for_each
    std::cout << "Elements in vec1: ";
    stlAlg::for_each(vec1.begin(), vec1.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;

    // Test search
    auto it3 = stlAlg::search(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());
    if (it3 != vec1.end()) {
        std::cout << "Subsequence found starting at position: " << std::distance(vec1.begin(), it3) << std::endl;
    } else {
        std::cout << "Subsequence not found" << std::endl;
    }

    // Test find_end
    auto it4 = stlAlg::find_end(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());
    if (it4 != vec1.end()) {
        std::cout << "Last occurrence of subsequence found starting at position: " << std::distance(vec1.begin(), it4) << std::endl;
    } else {
        std::cout << "Last occurrence of subsequence not found" << std::endl;
    }

    return 0;
}