#include <vector>
#include <iostream>

int kadane(const std::vector<int> v) {
    int current = v[0], ret = v[0];
    for (std::size_t i = 1; i < v.size(); ++i) {
        current = current < 0 ? v[i] : current + v[i];
        ret = std::max(ret, current);
    }
    return ret;
}

int two_d_kadane(const std::vector<std::vector<int>>& m) {
    int ret = m[0][0];
    for (std::size_t left = 0; left < m.size(); ++left) {
        std::vector<int> tmp(m.size(), 0);
        for (std::size_t right = left; right < m.size(); ++right) {
            for (std::size_t i = 0; i < m[0].size(); ++i)
                tmp[i] += m[i][right];
            ret = std::max(ret, kadane(tmp));
        }
    }
    return ret;
}

int main() {
    return 0;
}
