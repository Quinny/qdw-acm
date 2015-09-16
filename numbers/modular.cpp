#include <iostream>

// finding the last x digits of 2 ^ n
// easily generalizable

int main() {
    long n = 1000;
    long cut = 10e10;
    long ret = 1;

    for (int i = 0; i < n; ++i)
        ret = (2 * ret) % cut;
    std::cout << ret << std::endl;
    return 0;
}
