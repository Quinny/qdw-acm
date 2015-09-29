#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    unsigned n;
    while (std::cin >> n) {
        std::vector<int> v(n, 0);
        for (unsigned i = 0; i < n; ++i)
            std::cin >> v[i];

        std::set<int> check;
        for (std::size_t i = 0; i < v.size() - 1; ++i) {
            long long idx = std::abs(v[i] - v[i+1]);
            if (idx >= 1 && idx <= n - 1)
                check.insert(idx);
            else
                break;
        }

        if (check.size() == n - 1)
            std::cout << "Jolly";
        else
            std::cout << "Not jolly";
        std::cout << std::endl;
    }
    return 0;
}

