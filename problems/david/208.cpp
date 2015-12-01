#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <set>
#include <queue>

// A directed graph implementation for contest use
// Members are intentionally left public for ease of use in
// contest style programming

template <typename T>
struct directed_graph {
    // maps vertex to set of neighbour nodes
    std::map<T, std::set<T>> g_;
    // keeps track of the number of incoming edges for a given vertex
    // useful for topological sort
    std::map<T, std::size_t> incoming_count_;

    void connect(const T& u, const T& v) {
        // ensure each vertex is represented in the incoming map
        incoming_count_.insert({u, 0});
        g_[u].insert(v);
        ++incoming_count_[v];
    }

    void insert(const T& u) {
        incoming_count_.insert({u, 0});
    }

    void disconnect(const T& u, const T& v) {
        g_[u].erase(v);
        --incoming_count_[v];
    }

    bool connected(const T& u, const T& v) {
        std::set<T> tmp = g_[u];
        return tmp.find(v) != tmp.end();
    }

    std::set<T> operator[] (const T& u) {
        return g_[u];
    }
};

unsigned paths(directed_graph<unsigned>, directed_graph<unsigned>, unsigned);
void print_paths(
    directed_graph<unsigned>,
    directed_graph<unsigned>,
    std::vector<unsigned>,
    std::set<unsigned>,
    unsigned,
    unsigned,
    unsigned&
);

unsigned max = 0;

int main() {
    unsigned n;
    unsigned c = 0;

    while (std::cin >> n) {
        directed_graph<unsigned> g;
        directed_graph<unsigned> floyd;
        unsigned u, v;
        max = 0;
        ++c;
        while (std::cin >> u >> v) {
            if (u == 0 && v == 0)
                break;
            max = std::max(u, max);
            max = std::max(v, max);
            g.connect(u, v);
            g.connect(v, u);
            floyd.connect(u, v);
            floyd.connect(v, u);
        }

        for (unsigned i = 1; i <= max; ++i) {
            for (unsigned j = 1; j  <= max; ++j) {
                for (unsigned k = 1; k <= max; ++k) {
                    if (floyd.connected(i, j) && floyd.connected(j, k))
                        floyd.connect(i, k);
                }
            }
        }

        std::cout << "CASE " << c << ':' << std::endl;
        unsigned num_paths = paths(g, floyd, n);
        std::cout <<
            "There are " << num_paths <<
            " routes from the firestation to streecorner " <<
            n << '.' <<
        std::endl;
    }

    return 0;
}

unsigned paths(directed_graph<unsigned> g, directed_graph<unsigned> floyd, unsigned n) {
    unsigned paths = 0;
    std::vector<unsigned> path;
    std::set<unsigned> visited;

    path.push_back(1U);
    visited.insert(1U);

    print_paths(g, floyd, path, visited, 1U, n, paths);
    return paths;
}

void print_paths(
    directed_graph<unsigned> g,
    directed_graph<unsigned> floyd,
    std::vector<unsigned> path,
    std::set<unsigned> visited,
    unsigned cur,
    unsigned end,
    unsigned& paths
) {
    if (cur == end) {
        ++paths;
        for (unsigned i = 0; i != path.size(); ++i) {
            if (i)
                std::cout << ' ';
            std::cout << path[i];
        }
        std::cout << std::endl;
        return;
    }

    for (unsigned i = 1; i <= max; ++i) {
        if (visited.find(i) != visited.end())
            continue;
        if (!g.connected(cur, i))
            continue;
        if (!floyd.connected(i, end))
            continue;

        path.push_back(i);
        visited.insert(i);

        print_paths(g, floyd, path, visited, i, end, paths);

        path.erase(std::prev(path.end()));
        visited.erase(i);
    }
}

