#include "../../../union-find/union_find.h"
#include <iostream>

int main() {
    int cases;
    std::cin >> cases;
    std::string s;
    std::getline(std::cin, s);
    std::getline(std::cin, s);
    while (cases--) {
        std::string s;
        std::getline(std::cin, s);
        union_find<char> uf;
        for (char c = 'A'; c <= s[0]; ++c)
            uf.init_vertex(c);
        while (true) {
            std::getline(std::cin, s);
            if (s.size() == 0)
                break;
            if (!uf.connected(s[0], s[1]))
                uf.connect(s[0], s[1]);
        }
        std::cout << uf.components << std::endl;
        if (cases)
            std::cout << std::endl;
    }
    return 0;
}
