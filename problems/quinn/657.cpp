#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using point = std::pair<int, int>;

template <typename T>
using matrix = std::vector<std::vector<T>>;

bool on_board(point p, int w, int h) {
    return p.first >= 0 && p.second >= 0 && p.first < h && p.second < w;
}

std::vector<point> neighbours(point p, int w, int h) {
    std::vector<point> ret;
    std::vector<point> dir = {
        {0 , -1},
        {1, 0},
        {0, 1},
        {-1, 0}
    };
    for (auto d: dir) {
        if (on_board({p.first + d.first, p.second + d.second}, w, h))
            ret.push_back({p.first + d.first, p.second + d.second});
    }
    return ret;
}

void reset(matrix<bool>& m) {
    for (std::size_t i = 0; i < m.size(); ++i) {
        for (std::size_t j = 0; j < m[0].size(); ++j)
            m[i][j] = false;
    }
}

std::vector<point> floodfill(point p, matrix<char> board,
        matrix<bool>& visited, std::vector<char> on, char record) {
    std::queue<point> q;
    q.push(p);
    std::vector<point> ret;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        visited[t.first][t.second] = true;
        for (auto i: neighbours(t, board[0].size(), board.size())) {
            if (board[i.first][i.second] == record) {
                if (std::find(ret.begin(), ret.end(), i) == ret.end())
                    ret.push_back(i);
            }

            if (!visited[i.first][i.second] &&
                    std::find(on.begin(), on.end(),
                        board[i.first][i.second]) != on.end())
                q.push(i);

        }
    }

    return ret;
}

int dieInRegion(point p, matrix<char> board, matrix<bool>& visited) {
    auto xs = floodfill(p, board, visited, {'*', 'X'}, 'X');
    auto tmp = visited;
    reset(tmp);
    int ret = 0;
    for (auto i: xs) {
        if (!tmp[i.first][i.second])
            ++ret;
        floodfill(i, board, tmp, {'X'}, 'q');
    }
    return ret;
}

int main() {
    int w, h, throws = 1;
    while (true) {
        std::cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        matrix<char> board;
        matrix<bool> visited;
        for (int i = 0; i < h; ++i) {
            std::vector<char> v;
            std::vector<bool> v2;
            for (int j = 0; j < w; ++j) {
                char tmp;
                std::cin >> tmp;
                v.push_back(tmp);
                v2.push_back(false);
            }
            board.push_back(v);
            visited.push_back(v2);
        }

        std::vector<int> out;
        for (std::size_t i = 0; i < board.size(); ++i) {
            for (std::size_t j = 0; j < board[0].size(); ++j) {
                if (!visited[i][j] && board[i][j] != '.') {
                    out.push_back(
                        dieInRegion({i, j}, board, visited)
                    );
                }
            }
        }
        std::sort(out.begin(), out.end());
        std::cout << "Throw " << throws << std::endl;
        ++throws;
        for (auto i: out)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    return 0;
}
