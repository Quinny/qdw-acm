#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i != t; ++i) {
        int n;
        int h;
        std::cin >> n >> h;

        std::string s;
        for (int j = 0; j != n; ++j) {
            if (j < n - h) {
                s += '0';
            } else {
                s += '1';
            }
        }

        do {
            std::cout << s << std::endl;
        } while (std::next_permutation(s.begin(), s.end()));
        if (i < t - 1)
            std::cout << std::endl;

    }
}
