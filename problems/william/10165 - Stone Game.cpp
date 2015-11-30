#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (!n)
            break;
        vector<int> piles;
        for (int i = 0; i < n; ++i) {
            int val;
            cin >> val;
            piles.push_back(val);
        }

        int c = piles[0];
        for (int j = 1; j < n; ++j) 
            c = c ^ piles[j];
        if (!c)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}
