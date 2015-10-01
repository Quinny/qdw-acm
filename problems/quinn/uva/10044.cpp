#include "../../graphs/directed_graph.h"
#include <iostream>
#include <map>
#include <queue>

std::map<std::string, int> erdos_dists(directed_graph<std::string> g) {
    std::map<std::string, int> visited;
    std::queue<std::string> q;

    int in_next_level = 0, in_cur_level = 1, cur_level = 1;
    q.push("Erdos, P.");
    visited["Erdos, P."] = 0;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        for (auto i: g[t]) {
            if (visited.find(i) == visited.end()) {
                q.push(i);
                visited[i] = cur_level;
                ++in_next_level;
            }
        }

        --in_cur_level;
        if (in_cur_level == 0) {
            ++cur_level;
            in_cur_level = in_next_level;
            in_next_level = 0;
        }
    }

    return visited;
}

void rtrim(std::string& s) {
    while (s.back() == ',' || s.back() == ' ' || s.back() == ':')
        s.pop_back();
}

bool read_name(std::string& s) {
    char c;
    int commas = 0;
    s = "";

    while (commas != 2) {
        std::cin >> c;
        s += c;
        if (c == ',') {
            s += " ";
            ++commas;
        }
        if (c == ':') {
            rtrim(s);
            return false;
        }
    }
    rtrim(s);
    return true;
}

int main() {
    int cases;
    std::cin >> cases;
    for (int _ = 0; _ < cases; ++_) {
        int p, n;
        std::cin >> p >> n;
        directed_graph<std::string> g;

        std::string name;
        for (int i = 0; i < p; ++i) {
            std::vector<std::string> names;
            while (read_name(name))
                names.push_back(name);
            names.push_back(name);

            std::getline(std::cin, name);

            for (int i = 0; i < names.size(); ++i) {
                for (int j = i + 1; j < names.size(); ++j) {
                    g.connect(names[i], names[j]);
                    g.connect(names[j], names[i]);
                }
            }

        }
        auto dists = erdos_dists(g);

        std::cout << "Scenario " << _ + 1 << std::endl;
        for (int i = 0; i < n; ++i) {
            std::string name;
            std::getline(std::cin, name);
            std::cout << name << " ";
            if (dists.find(name) == dists.end())
                std::cout << "infinity";
            else
                std::cout << dists[name];
            std::cout << std::endl;
        }
    }
    return 0;
}
