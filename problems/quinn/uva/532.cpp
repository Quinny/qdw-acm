#include <iostream>
#include <vector>
#include <queue>
#include <set>

struct point {
    int x, y, z;
    point() {};
    point(int a, int b, int c): x(a), y(b), z(c) {};
    point(std::initializer_list<int> l) {
        x = *(l.begin());
        y = *(l.begin() + 1);
        z = *(l.begin() + 2);
    }
    bool operator < (const point& p) const {
        int one[] = {x, y, z};
        int two[] = {p.x, p.y, p.z};
        int i = 0;
        while (i < 2 && one[i] == two[i])
            ++i;
        return one[i] < two[i];
    }

    bool operator == (const point& p) {
        return x == p.x && y == p.y && z == p.z;
    }
};

template <typename T>
using matrix = std::vector<std::vector<T>>;

bool on_board(const point& p, const std::vector<matrix<char>>& m) {
    return p.x >= 0 && p.y >= 0 && p.z >= 0
        && p.x < m[0][0].size() && p.y < m[0].size() && p.z < m.size();
}

std::vector<point> neighbours(point p, const std::vector<matrix<char>>& m) {
    std::vector<point> dv = {
        {0, 0, 1},
        {0, 0, -1},
        {0, 1, 0},
        {0, -1, 0},
        {1, 0, 0},
        {-1, 0, 0},
    };
    std::vector<point> ret;
    for (auto d: dv) {
        if (on_board({p.x + d.x, p.y + d.y, p.z + d.z}, m) &&
                m[p.z][p.y][p.x] != '#')
            ret.push_back({p.x + d.x, p.y + d.y, p.z + d.z});

    }
    return ret;
}

int escape_time(std::vector<matrix<char>> board, point start, point end) {
    std::queue<std::pair<point, int>> q;
    std::set<point> visited;

    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        if (t.first == end)
            return t.second;

        visited.insert(t.first);

        for (auto i: neighbours(t.first, board)) {
            if (visited.find(i) == visited.end()) {
                visited.insert(i);
                q.push({i, t.second + 1});
            }
        }
    }
    return -1;
}

int main() {
    int level, row, col;
    while (true) {
        std::cin >> level >> row >> col;
        if (level == 0 && row == 0 && col == 0)
            return 0;

        std::vector<matrix<char>> board;
        point start, end;
        for (int i = 0; i < level; ++i) {
            matrix<char> m;
            for (int j = 0; j < row; ++j) {
                std::vector<char> v;
                for (int k = 0; k < col; ++k) {
                    char c;
                    std::cin >> c;
                    if (c == 'S')
                        start = {k, j, i};
                    if (c == 'E')
                        end = {k, j, i};
                    v.push_back(c);
                }
                m.push_back(v);
            }
            board.push_back(m);
        }
        auto time = escape_time(board, start, end);
        if (time > 0)
            std::cout << "Escaped in " << time << " minute(s)." << std::endl;
        else
            std::cout << "Trapped!" << std::endl;
    }
    return 0;
}
