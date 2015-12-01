#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <locale>
#include <set>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    map<char, int> frequency;
    for (int i = 0; i <= cases; ++i) {
        string s;
        getline(cin, s);
        for (auto c : s) {
            if (isalpha(c))
                frequency[toupper(c)]++;
        }
    }

    map<int, set<char>> results;
    for (auto i = frequency.begin(); i != frequency.end(); ++i) {
        results[i->second].insert(i->first);
    }    

    for (auto i = results.rbegin(); i != results.rend(); i++) {
        for (auto j = i->second.begin(); j != i->second.end(); ++j) {
            cout << *j << " ";
            cout << i->first << endl;
        }
    }
}
