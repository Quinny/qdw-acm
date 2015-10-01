#include <iostream>
#include <set>
#include <queue>
#include "../../../union-find/union_find.h"

int main() {
    int cases;
    std::cin >> cases;
    while (cases--) {
        int n, m;

        std::cin >> n >> m;
        int f1, f2;
        union_find<int> uf;
        while (m--) {
            std::cin >> f1 >> f2;
            if (!uf.connected(f1, f2))
                uf.connect(f1, f2);
        }
        std::size_t out = 0;
        for (auto i: uf.sizes)
            out = std::max(out, i.second);
        std::cout << out << std::endl;
    }
    return 0;
}
