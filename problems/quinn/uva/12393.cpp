#include <iostream>
#include <algorithm>
#include <vector>

bool all_greater(const std::vector<int>& v, int than) {
    int rolling = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (rolling < 0)
            return false;
        rolling += v[i];
    }
    return rolling >= 0;
}

int num_valid(std::vector<int>& v) {
    int ret = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (all_greater(v, 0))
            ++ret;
        std::rotate(v.begin(), v.begin() + 1, v.end());
    }
    return ret;
}

int main() {
    int n;
    while (true) {
        std::cin >> n;
        if (n == 0)
            break;
        std::vector<int> v;
        for (int i = 0; i < n; ++i) {
            int tmp;
            std::cin >> tmp;
            v.push_back(tmp);
        }
        std::cout << num_valid(v) << std::endl;
    }
    return 0;
}
