#include <iostream>
#include <vector>
#include <queue>
#include <set>

template <typename T>
using matrix = std::vector<std::vector<T>>;
using point = std::pair<int, int>;

bool on_board(point p, int w, int h) {
    return p.first >= 0 && p.second >= 0 && p.first <= w && p.second <= h;
}

point translate(point p1, point p2) {
    return {p1.first + p2.first, p1.second + p2.second};
}

std::vector<point> neighbours(point p, int w, int h) {
    std::vector<point> dv = {
        {0, -1},
        {1,  0},
        {0,  1},
        {-1, 0}
    };
    std::vector<point> ret;

    for (auto i: dv) {
        if (on_board(translate(p, i), w, h))
            ret.push_back(translate(p, i));
    }
    return ret;
}

template <typename T>
void floodfill(matrix<T>& board, matrix<bool>& visited,
        point p, const T& target, const T& source) {
    std::queue<point> q;
    q.push(p);
    visited[p.first][p.second] = true;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        board[t.first][t.second] = source;

        for (auto i: neighbours(t, board[0].size(), board.size())) {
            if (board[i.first][i.second] == target) {
                visited[i.first][i.second] = true;
                q.push(i);
            }
        }
    }
}
int main() {
    matrix<char> b = {
        {'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'w', 'w', 'w', 'w', 'w'},
        {'x', 'w', 'x', 'x', 'w', 'w'},
        {'x', 'w', 'x', 'x', 'w', 'w'},
        {'x', 'x', 'x', 'x', 'x', 'x'}
    };

    matrix<bool> visited;
    for (auto i: b) {
        std::vector<bool> v;
        for (auto j: i)
            v.push_back(false);
        visited.push_back(v);
    }

    floodfill(b, visited, {1, 1}, 'w', 'q');
    for (auto i: b) {
        for (auto j: i)
            std::cout << j;
        std::cout << std::endl;
    }
    return 0;
}
