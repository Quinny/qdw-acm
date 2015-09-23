#include <iostream>
#include <vector>
#include <map>
#include <set>

int subset_sums(const std::vector<int>& s, std::size_t index,
        int target, int current) {
    if (index == s.size())
        return target == current;
    int count = target == current;
    for (auto i = index; i < s.size(); ++i)
        count += subset_sums(s, i + 1, target, current + s[i]);
    return count;
}

int main() {
    int n, target;
    while (std::cin >> n >> target) {
        std::vector<int> s;
        for (int i = 0; i < n; ++i) {
            int tmp;
            std::cin >> tmp;
            s.push_back(tmp);
        }
        std::cout << subset_sums(s, 0, target, 0) << std::endl;
    }
    return 0;
}
