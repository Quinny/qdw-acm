#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <string>

using namespace std;

string traverse (map<string, vector<string>> graph, string city, string destination, set<string> visited, string s) {
    vector<string> solutions;
    for (auto i : graph[city]) {
        if (visited.find(i) == visited.end()) {
            visited.insert(i);
            if (i == destination) {
                solutions.push_back(s+destination[0]);
            } else {
                string return_result = traverse(graph, i, destination, visited, s+i[0]);
                if (return_result != "")
                    solutions.push_back(return_result);
            }
        } 
    }

    string to_return = "";
    for (auto i : solutions) {
        if (to_return == "") {
            to_return = i;
        }
        else {
            if (to_return.size() > i.size())
                to_return = i;
        }   
    }
    return to_return;
}

int main() {

    int cases;
    cin >> cases;
    string junk;
    getline(cin, junk);
    for (int i = 0; i < cases; ++i) {
        int m, n;
        map<string, vector<string>> graph;
        vector<pair<string, string>> query_pairs;
        cin >> m >> n;
        for (int j = 0; j < m; ++j) {
            string s1, s2;
            cin >> s1 >> s2;
            graph[s1].push_back(s2);
            graph[s2].push_back(s1);
        }
        for (int j = 0; j < n; ++j) {
            string s1, s2;
            cin >> s1 >> s2;
            query_pairs.push_back({s1, s2});
        }

        for (auto &iter : query_pairs) {
            set<string> visited;
            string s = "";
            s+= iter.first.at(0);
            cout << traverse(graph, iter.first, iter.second, visited, s) << endl;
        }
        if (i != cases - 1)
            cout << endl;
    }
    return 0;
}

