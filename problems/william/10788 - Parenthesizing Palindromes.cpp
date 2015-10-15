#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> dp;

bool is_palindrome(std::string s) {
    if (s.size() % 2 != 0)
        return false;

    std::size_t i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        ++i; --j;
    }
    return true;
}

int is_valid(const string& s) {
    if (s.size() == 0) 
        return 1;
    else if (s.size() % 2 == 1)
        return 0;
    
    int solution_count = 0;    
    if (is_palindrome(s)) {
        solution_count++;
        if (s.substr(1, s.size() -2).size() != 0) {
            int result;
            if (dp.find(s.substr(1, s.size() - 2)) != dp.end())
                result = dp[s.substr(1, s.size() - 2)];
            else {
                result = solution_count+= is_valid(s.substr(1, s.size() - 2));
                dp[s.substr(1, s.size() - 2)] = result;
            }
        }
    }

    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j < s.size(); ++j) { 
            int first, second;
            if (dp.find(s.substr(i, j - i)) != dp.end())
                first = dp[s.substr(i, j - i)];
            else {
                first = is_valid(s.substr(i, j - i));
                dp[s.substr(i, j - i)] = first;
            }

            if (dp.find(s.substr(j, s.size())) != dp.end())
                second = dp[s.substr(j, s.size())];
            else {
                second = is_valid(s.substr(j, s.size()));
                dp[s.substr(j, s.size())] = second;
            }
            solution_count+= first * second; // multiple of each side. 0 if any side has no solution
        }
    }
    return solution_count;
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        string s;
        cin >> s;
        cout << "Case " << i + 1 << ": ";
        int count = is_valid(s);
        if (count > 1)
            cout << "Valid, Multiple" << endl;
        else if (count == 1)
            cout << "Valid, Unique" << endl;
        else 
            cout << "Invalid" << endl;
    }
    return 0;    
}

