#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>

template <typename T>
struct directed_graph {
    std::map<T, std::set<T>> g_;
    std::map<T, std::size_t> incoming_count_;

    void connect(const T& u, const T& v) {
        incoming_count_.insert({u, 0});
        g_[u].insert(v);
        ++incoming_count_[v];
    }

    void add(const T& u) {
        incoming_count_.insert({u, 0});
    }

    void disconnect(const T& u, const T& v) {
        g_[u].erase(v);
        --incoming_count_[v];
    }

    std::set<T> operator[] (const T& u) {
        return g_[u];
    }
};

template <typename T>
using matrix = std::vector<std::vector<T>>;

using point = std::pair<int, int>;

template <typename T>
matrix<T> fill(int m, int n) {
    matrix<T> ret;
    for (int i = 0; i < n; ++i)
        ret.emplace_back(m, 0);
    return ret;
}

bool is_upper(char c) {
    return c >= 'A' && c <= 'Z';
}

bool is_digit(char c) {
    return c >= '1' && c <= '9';
}

int to_base(std::string s, int base, char offset = '0') {
    int pow = 1;
    int ret = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        ret += (s[i] - offset) * pow;
        pow *= base;
    }
    return ret;
}

std::vector<point> parse_deps(std::string s) {
    std::vector<point> ret;
    for (int i = 1; i < s.size(); ++i) {
        int j = i;
        std::string tmp;
        while (j < s.size() && is_upper(s[j])) {
            tmp += s[j];
            ++j;
        }
        int x = to_base(tmp, 26, 'A' - 1);
        tmp.clear();

        while (j < s.size() && is_digit(s[j])) {
            tmp += s[j];
            ++j;
        }
        int y = to_base(tmp, 10);
        ret.push_back({y - 1, x - 1});

        i = j;
    }

    return ret;
}

void compute(directed_graph<point> g, matrix<int>& sheet) {
    std::queue<point> q;
    for (auto i: g.incoming_count_) {
        if (i.second == 0)
            q.push(i.first);
    }

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        for (auto i: g[t]) {
            g.disconnect(t, i);
            sheet[i.first][i.second] += sheet[t.first][t.second];
            if (g.incoming_count_[i] == 0)
                q.push(i);
        }
    }
}

template <typename T>
std::ostream& operator << (std::ostream& os, const matrix<T>& m) {
    for (auto i: m) {
        for (int j = 0; j < i.size(); ++j) {
            os << i[j];
            if (j + 1 != i.size())
                os << " ";
        }
        os << std::endl;
    }
    return os;
}

int main() {
    int cases;
    std::cin >> cases;
    while (cases--) {
        int m, n;
        std::cin >> m >> n;
        auto sheet = fill<int>(m, n);
        directed_graph<point> g;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int n;
                if (std::cin >> n) {
                    sheet[i][j] = n;
                    g.add({i, j});
                }
                else {
                    std::cin.clear();
                    std::string s;
                    std::cin >> s;
                    auto deps = parse_deps(s);
                    for (auto d: deps)
                        g.connect(d, {i, j});
                }
            }
        }
        compute(g, sheet);
        std::cout << sheet;
    }
    return 0;
}
