#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Return true if s1 > s2
bool compare(std::string s1, std::string s2) {
    unsigned i = 0;
    if (s1.size() < s2.size()) {
        for (; i != s1.size(); ++i) {
            if (s1[i] < s2[i])
                return false;
            if (s1[i] > s2[i])
                return true;
        }
        if (s2[i - 1] < s2[i])
            return false;
        return true;
    } else {
        for (; i != s2.size(); ++i) {
            if (s1[i] < s2[i])
                return false;
            if (s1[i] > s2[i])
                return true;
        }
        if (s2.size() == s1.size())
            return false;
        if (s1[i - 1] < s1[i])
            return true;
        return false;
    }
}

int main() {
    unsigned n;

    while (std::cin >> n) {
        if (n == 0)
            break;

        std::string s;
        std::vector<std::string> v(n);

        for (unsigned i = 0; i != n; ++i)
            std::cin >> v[i];

        std::sort(v.begin(), v.end(), compare);

        std::string ret = "";
        for (auto i : v)
            ret += i;

        std::cout << ret << std::endl;
    }
    return 0;
}

