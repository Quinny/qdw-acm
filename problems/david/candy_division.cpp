#include <iostream>
#include <set>
#include <cmath>

std::set<uint64_t> divisors(uint64_t n) {
    std::set<uint64_t> ret;
    uint64_t root = static_cast<uint64_t>(std::sqrt(n));

    for (uint64_t i = 1; i <= root; ++i) {
        if (n % i == 0) {
            ret.insert(i);
            ret.insert(n / i);
        }
    }

    return ret;
}

int main() {

    uint64_t n;
    std::cin >> n;

    std::set<uint64_t> s = divisors(n);

    for (auto i : s)
        std::cout << (i - 1) << " ";
    std::cout << std::endl;

    return 0;
}
