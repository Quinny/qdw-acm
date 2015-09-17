#include <iostream>
#include <cmath>

void find_missing(unsigned);
unsigned summation(unsigned);

int main() {
    unsigned n;
    while (std::cin >> n) {
        if (n == 0)
            break;
        find_missing(n);
    }
    return 0;
}

void find_missing(unsigned n) {
    auto root = std::sqrt(2 * n);
    unsigned check = std::floor(root);
    unsigned sum = summation(check);

    if (sum > n) {
        std::cout << (sum - n) << " " << check << std::endl;
    } else {
        check = std::ceil(root);
        sum = summation(check);
        std::cout << (sum - n) << " " << check << std::endl;
    }
}

unsigned summation(unsigned n) {
    return (n * (n + 1)) / 2;
}

