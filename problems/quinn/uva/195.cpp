#include <iostream>
#include <algorithm>

bool cmp(char a, char b) {
    if (std::isupper(a) && std::isupper(b))
        return a < b;
    if (std::islower(a) && std::islower(b))
        return a < b;

    if (std::islower(a)) {
        a -= 'a' - 'A';
        return a < b;
    }
    b -= ('a' - 'A');
    return a <= b;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        std::sort(s.begin(), s.end(), cmp);
        do {
            std::cout << s << std::endl;
        } while (std::next_permutation(s.begin(), s.end(), cmp));
    }
    return 0;
}
