#include <iostream>
#include <set>
#include <vector>

int days_lost(int days, const std::vector<int>& hartals) {
    std::set<int> lost;

    for (int d = 1; d <= days; ++d) {
        if (d % 7 != 0 && (d + 1) % 7 != 0) {
            for (int h : hartals) {
                if (d % h == 0)
                    lost.insert(d);
            }
        }
    }

    return lost.size();
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i != t; ++i) {
        int days;
        int n;

        std::cin >> days >> n;

        std::vector<int> hartals(n);

        for (int j = 0; j != n; ++j) {
            std::cin >> hartals[j];
        }

        std::cout << days_lost(days, hartals) << std::endl;
    }

    return 0;
}

