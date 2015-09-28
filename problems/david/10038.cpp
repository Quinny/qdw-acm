#include <iostream>
#include <vector>
#include <set>

long long qabs(long long x) {
    if (x < 0)
        return -1 * x;
    return x;
}

int main() {
    unsigned n;
    int tmp;
    while (std::cin >> n) {
        std::vector<int> v;
        for (unsigned i = 0; i < n; ++i) {
            std::cin >> tmp;
            v.push_back(tmp);
        }

        std::set<int> check;

        for (std::size_t i = 0; i < v.size() - 1; ++i) {
            long long idx = qabs(v[i] - v[i+1]);
            if (idx >= 1 && idx <= n - 1) {
                check.insert(idx);
            } else {
                break;
            }
        }
        if (check.size() == n - 1)
            std::cout << "Jolly";
        else
            std::cout << "Not jolly";
        std::cout << std::endl;
    }
}

