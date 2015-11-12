#include <iostream>
#include <algorithm>

bool is_upper(char c) {
    return 'A' <= c && c <= 'Z';
}

bool is_lower(char c) {
    return 'a' <= c && c <= 'z';
}

bool compare(char a, char b) {
    if (is_upper(a)) {
        if (is_upper(b))
            return a < b;
        else
            return a <= b - 32;
    } else {
        if (is_upper(b))
            return a - 32 < b;
        else
            return a < b;
    }
}

void print_permutations(std::string s) {
    std::sort(s.begin(), s.end(), compare);
    do {
        std::cout << s << std::endl;
    } while (std::next_permutation(s.begin(), s.end(), compare));
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i != n; ++i) {
        std::string s;
        std::cin >> s;

        print_permutations(s);
    }

    return 0;
}

