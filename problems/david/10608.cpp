#include <iostream>
#include "../../union-find/union_find.h"

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i != t; ++i) {
        int n, m;
        std::cin >> n >> m;

        union_find<int> groups;

        for (int j = 0; j != m; ++j) {
            int a, b;
            std::cin >> a >> b;
            if (!groups.connected(a, b))
                groups.connect(a, b);
        }

        unsigned long size = 0;
        for (auto p : groups.sizes) {
            size = std::max(size, p.second);
        }

        std::cout << size << std::endl;
    }
}

