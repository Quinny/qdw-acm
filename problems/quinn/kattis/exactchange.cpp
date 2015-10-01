#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

int INF = 100000;
std::vector<int> d;
int mem[10002];

int opt(int i, int x, int c, std::vector<std::pair<int, int>>& ret) {
    if (x <= 0) {
        ret.push_back({-x, c});
        return 0;
    }

    if (i == -1) {
        return INF;
    }

    if (mem[x] != -1) {
        return mem[x] - 1;
    }

    int res = INF;
    res = std::min(res, 1 + opt(i - 1, x - d[i], c + 1, ret));
    res = std::min(res, opt(i - 1, x, c, ret));

    mem[x] = res;
    return res;
}

int main() {
    int cases;
    std::cin >> cases;
    for (int _ = 0; _ < cases; ++_) {
        memset(mem, -1, sizeof(mem));
        d.clear();
        int change;
        std::cin >> change;
        int n;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            int denom;
            std::cin >> denom;
            d.push_back(denom);
        }
        std::vector<std::pair<int, int>> res;
        opt(n - 1, change, 0, res);
        std::sort(res.begin(), res.end());
        std::cout << change + res[0].first << " " << res[0].second << std::endl;

        for (auto i: res) {
            if (i.first == 0)
                std::cout << i.second << std::endl;
        }
    }
    return 0;
}
