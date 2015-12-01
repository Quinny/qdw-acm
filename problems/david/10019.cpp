#include <iostream>

unsigned hamming_weight(unsigned n) {
    unsigned c = 0;
    for (unsigned i = 0; i != 32; ++i) {
        if (n & (1 << i))
            ++c;
    }
    return c;
}

unsigned hex_bits(unsigned n) {
    unsigned c = 0;
    while (n > 0) {
        c += hamming_weight(n % 10);
        n /= 10;
    }
    return c;
}

int main() {
    unsigned n;
    std::cin >> n;

    while (std::cin >> n) {
        std::cout << hamming_weight(n) << " " << hex_bits(n) << std::endl;
    }

    return 0;
}
