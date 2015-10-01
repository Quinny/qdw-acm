#include <vector>
#include <iostream>

int kadane(const std::vector<int>& v) {
    int current = v[0], ret = v[0];
    for (std::size_t i = 1; i < v.size(); ++i) {
        current = current < 0 ? v[i] : current + v[i];
        ret = std::max(ret, current);
    }
    return ret;
}

int main() {
    int n, p;
    std::cin >> n >> p;
    std::vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp - p);
    }
    std::cout << kadane(v) << std::endl;
    return 0;
}
