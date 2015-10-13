#include <iostream>
#include <string>

std::string substring(std::string s, std::size_t start, std::size_t end) {
    std::string ret = "";

    if (start >= end)
        return ret;

    for (std::size_t i = start; i <= end; ++i) {
        ret += s[i];
    }
    return ret;
}

bool is_palindrome(std::string s) {
    if (s.size() % 2 != 0)
        return false;

    for (std::size_t i = 0; i != s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1])
            return false;
    }

    return true;
}

int num_solutions(std::string s) {
    if (s.size() == 0)
        return 1;
    if (is_palindrome(s))
        return 1;
    if (s.size() % 2 != 0)
        return 0;

    int ret = 0;
    std::size_t i = 0, j = s.size() - 1;

    while (s[i] == s[j] && i < j) {
        ++i;
        --j;

        std::string sub = substring(s, i, j);
        ret += num_solutions(sub);
    }

    std::string tmp = "";
    for (std::size_t idx = 0; idx != s.size(); ++idx) {
        tmp += s[idx];
        if (is_palindrome(tmp) && tmp != s)
            ret += num_solutions(substring(s, idx+1, s.size() - 1));
    }

    return ret;
}

int main() {
    int n;
    std::cin >> n;

    int solns;
    for (int i = 0; i != n; ++i) {
        std::string s;
        std::cin >> s;
        solns = num_solutions(s);

        std::cout << "Case " << (i + 1) << ": ";

        if (solns > 1) {
            std::cout << "Valid, Multiple" << std::endl;
        } else if (solns == 1) {
            std::cout << "Valid, Unique" << std::endl;
        } else {
            std::cout << "Invalid" << std::endl;
        }
    }

    return 0;
}

