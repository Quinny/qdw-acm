#include <iostream>
#include <vector>
#include <set>

int days_missed(const std::vector<int>& hartals, int total_days) {
    std::set<int> missed;
    for (auto h: hartals) {
        for (int j = h; j <= total_days; j += h) {
            if (j % 7 != 6 && j % 7 != 0)
                missed.insert(j);
        }
    }
    return missed.size();
}

int main() {
    int cases;
    std::cin >> cases;
    while (cases--) {
        int days;
        std::cin >> days;
        int n;
        std::cin >> n;
        std::vector<int> h(n, 0);
        for (int i = 0; i < n; ++i)
            std::cin >> h[i];
        std::cout << days_missed(h, days) << std::endl;
    }
    return 0;
}
