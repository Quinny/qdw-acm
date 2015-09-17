#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // sum from 1...14134 is juuuuuust above 10^8
    const std::size_t top = 14143;
    std::vector<int> sums;
    for (std::size_t i = 0; i < top; ++i)
        sums.push_back((i * (i + 1)) / 2);

    std::size_t n;
    while (true) {
        std::cin >> n;
        if (n == 0)
            break;
        auto it = std::upper_bound(sums.begin(), sums.end(), n);
        std::cout << *it - n << " " << it - sums.begin() << std::endl;
    }
    return 0;
}
