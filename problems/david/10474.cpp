#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int m, n;
    int c = 1;
    while (std::cin >> m >> n) {
        if (m == 0 && n == 0)
            return 0;

        std::cout << "CASE# " << c << ":" << std::endl;

        std::vector<int> v;
        for (int i = 0, tmp; i != m; ++i) {
            std::cin >> tmp;
            v.push_back(tmp);
        }

        std::sort(v.begin(), v.end());

        for (int i = 0, tmp; i != n; ++i) {
            std::cin >> tmp;
            auto iter = std::lower_bound(v.begin(), v.end(), tmp);
            if (*(iter) != tmp) {
                std::cout << tmp << " not found" << std::endl;
            } else {
                int idx = iter - v.begin();
                std::cout << tmp << " found at " << (idx+1) << std::endl;
            }
        }
    }
}

