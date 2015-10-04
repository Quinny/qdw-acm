#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int main() {
    std::unordered_map<std::string, std::pair<std::string, int>> words;
    std::string s;
    std::vector<std::string> result;

    while (std::cin >> s) {
        if (s == "#")
            break;

        std::string cp = s;
        std::transform(cp.begin(), cp.end(), cp.begin(), ::tolower);
        std::sort(cp.begin(), cp.end());

        auto iter = words.find(cp);
        if (iter == words.end()) {
            words.insert({cp, {s, 1}});
        } else {
            ++iter->second.second;
        }
    }

    for (auto p : words) {
        if (p.second.second == 1)
            result.push_back(p.second.first);
    }

    std::sort(result.begin(), result.end());

    for (auto r : result)
        std::cout << r << std::endl;
}

