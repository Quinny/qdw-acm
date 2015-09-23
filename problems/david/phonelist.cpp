#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include "../../trie/trie.h"

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i != t; ++i) {
        int n;
        std::string num;
        trie dict;
        std::vector<std::string> numbers;

        std::cin >> n;

        for (int j = 0; j != n; ++j) {
            std::cin >> num;
            dict.insert(num);
            numbers.push_back(num);
        }

        bool found = false;
        for (auto n : numbers) {
            if (dict.any_prefix(n)) {
                std::cout << "NO" << std::endl;
                found = true;
                break;
            }
        }

        if (!found)
            std::cout << "YES" << std::endl;

    }

    return 0;
}

