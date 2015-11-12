#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n, q;

    int cases = 1;
    while (std::cin >> n >> q) {
        if (n == 0 && q == 0)
            break;

        std::cout << "CASE# " << ":" << cases << std::endl;

        std::vector<int> v(n);
        for (int i = 0; i != n; ++i)
            std::cin >> v[i];

        std::sort(v.begin(), v.end());

        int query;
        for (int i = 0; i != q; ++i) {
            std::cin >> query;
            auto iter = std::lower_bound(v.begin(), v.end(), query);

            if (*(iter) != query || iter == v.end())
                std::cout << query << " not found " << std::endl;
            else
                std::cout << query << " found at " << (1 + iter - v.begin()) << std::endl;
        }
    }

    return 0;
}
