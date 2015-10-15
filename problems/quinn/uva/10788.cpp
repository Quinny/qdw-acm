#include <iostream>
#include <string>

std::string substring(std::string s, std::size_t start, std::size_t end) {
    std::string ret = "";

    if (start > end)
        return "";

    if (start == end) {
        std::string x;
        x += s[start];
        return x;
    }

    for (std::size_t i = start; i <= end; ++i) {
        ret += s[i];
    }
    return ret;
}

bool expception_palindrome(std::string s) {
    int c = 0;
    for (std::size_t i = 0; i < s.size(); ++i) {
        if (s[i] == s[i + 1]) {
            ++c;
            ++i;
        }
        if (c == 2) return true;
    }
    return false;
}

bool is_palindrome(std::string s) {
    if (s.size() % 2 != 0)
        return false;

    std::size_t i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        ++i; --j;
    }
    /*for (std::size_t i = 0; i != s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1])
            return false;
    }*/

    return true;
}

int num_solutions(std::string s) {
    if (s.size() == 0)
        return 1;
//    if (is_palindrome(s))
//        return 1;
    if (s.size() % 2 != 0)
        return 0;

    int ret = is_palindrome(s);
    std::size_t i = 0, j = s.size() - 1;

    if (ret && expception_palindrome(s)) {
        return 2;
    }

    if (!ret) {
        while (s[i] == s[j] && i < j) {
            ++i;
            --j;
            std::string sub = substring(s, i, j);
            ret += num_solutions(sub);
            if (ret > 1)
                return ret;
        }
    }

    std::string tmp = "";
    for (std::size_t idx = 0; idx != s.size(); ++idx) {
        tmp += s[idx];
        if (is_palindrome(tmp) && tmp != s) {
            ret += num_solutions(substring(s, idx+1, s.size() - 1));
            if (ret > 1)
                return ret;
        }
    }


    for (std::size_t idx = 1; idx != s.size() - 1; ++idx) {
        if (s[0] == s[idx]) {
            if (is_palindrome(substring(s, 0, idx)))
                    continue;
            auto one = num_solutions(substring(s, 1, idx - 1));
            auto two = num_solutions(substring(s, idx + 1, s.size() - 1));
            if (one >= 1 && two >= 1) {
                ++ret;
                if (one >= 2 || two >= 2)
                    ++ret;
            }
            if (ret > 1)
                return ret;
        }
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

