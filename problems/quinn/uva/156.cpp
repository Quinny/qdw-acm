#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    std::unordered_map<std::string, std::pair<std::string, int>> dict;
    std::string s;
    while (std::cin >> s) {
        if (s == "#")
            break;
        auto cp = s;
        std::transform(cp.begin(), cp.end(), cp.begin(), ::tolower);
        std::sort(cp.begin(), cp.end());
        dict.insert({cp, {s, 0}});
        dict[cp].second++;
    }

    std::vector<std::string> out;
    for (auto i: dict) {
        if (i.second.second == 1)
            out.push_back(i.second.first);
    }
    std::sort(out.begin(), out.end());
    for (auto i: out)
        std::cout << i << std::endl;
    return 0;
}
