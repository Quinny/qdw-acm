#include <iostream>
#include "../../union-find/union_find.h"

int main() {
    int t;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        union_find<char> groups;

        std::string s;
        while (std::getline(std::cin, s)) {
            if (s.size() == 1)
                break;
        }

        char c = s[0];
        for (char a = 'A'; a <= c; ++a) {
            groups.init_vertex(a);
        }

        while (std::getline(std::cin, s)) {
            if (s.size() == 0)
                break;
            if (!groups.connected(s[0], s[1]))
                groups.connect(s[0], s[1]);
        }

        std::cout << groups.components << std::endl;

        // fuck UVA
        if (i != t)
            std::cout << std::endl;
    }

    return 0;
}

