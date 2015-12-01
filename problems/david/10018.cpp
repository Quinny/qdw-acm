#include <iostream>

unsigned reverse(unsigned n) {
    unsigned rev = 0;
    while (n > 0) {
        rev = (rev * 10) + (n % 10);
        n /= 10;
    }
    return rev;
}

bool palindrome(unsigned n) {
    return n == reverse(n);
}

void iterations(unsigned n) {
    unsigned c = 0;
    do {
        ++c;
        n += reverse(n);
    } while (!palindrome(n));
    std::cout << c << " " << n << std::endl;
}

int main() {
    unsigned n;
    std::cin >> n;

    while (std::cin >> n) {
        iterations(n);
    }

    return 0;
}
