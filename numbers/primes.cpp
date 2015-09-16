#include <iostream>

bool is_prime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    std::cout << is_prime(5) << is_prime(13) << is_prime(65) << std::endl;
    return 0;
}
