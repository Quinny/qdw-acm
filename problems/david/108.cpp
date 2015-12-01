#include <vector>
#include <iostream>

// maximum subsequence for a 1d array
int kadane(const std::vector<int> v) {
    int current = v[0], ret = v[0];
    for (std::size_t i = 1; i < v.size(); ++i) {
        current = current < 0 ? v[i] : current + v[i];
        ret = std::max(ret, current);
    }
    return ret;
}

// maximum sub rectangle for a 2d array
int two_d_kadane(const std::vector<std::vector<int>>& m) {
    int ret = m[0][0];
    for (std::size_t left = 0; left < m[0].size(); ++left) {
        std::vector<int> tmp(m.size(), 0);
        for (std::size_t right = left; right < m[0].size(); ++right) {
            for (std::size_t i = 0; i < m.size(); ++i)
                tmp[i] += m[i][right];
            // sum between 2 rows and columns and then use kadanes 1d
            // to find the maximum subsequence within
            ret = std::max(ret, kadane(tmp));
        }
    }
    return ret;
}

int main() {
    unsigned n;
    std::cin >> n;

    std::vector<std::vector<int>> v(n, std::vector<int>(n));

    for (unsigned i = 0; i != n; ++i) {
        for (unsigned j = 0; j != n; ++j) {
            std::cin >> v[i][j];
        }
    }

    std::cout << two_d_kadane(v) << std::endl;

    return 0;
}
