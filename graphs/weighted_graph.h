#include <map>
#include <vector>
#include <algorithm>
#include <queue>

template <typename T>
struct edge_compare {
    bool operator() (const std::pair<T, std::size_t>& p1,
                     const std::pair<T, std::size_t>& p2) {
        return p1.second < p2.second;
    }
};

template <typename T>
struct weighted_graph {
    using edge = std::pair<T, std::size_t>;
    using pq = std::priority_queue<
        edge,
        std::vector<edge>,
        edge_compare<T>
    >;

    std::map<T, std::vector<edge>> g_;

    void connect(const T& u, const T& v, std::size_t w = 0) {
        g_[u].push_back({v, w});
    }

    void disconnect(const T& u, const T& v) {
        auto it = std::find_if(g_[u].begin(), g_[u].end(),
                [v] (const edge& e) {
                    return e.first == v;
                }
        );
        g_[u].erase(it);
    }

    void disconnect(const T& u, const T& v, std::size_t w) {
        g_[u].erase({v, w});
    }

    std::vector<edge> operator[](const T& u) {
        return g_[u];
    }
};
