#include <iostream>
#include <vector>
#include <queue>
#include <utility>

std::vector<std::pair<int, int>> neighbours(std::pair<int, int> pos) {
    std::vector<std::pair<int, int>> dir = {
        {-2, -1},
        {-2, 1},
        {2, -1},
        {2, 1},
        {-1, -2},
        {1, -2},
        {-1, 2},
        {1, 2}
    };

    std::vector<std::pair<int, int>> ret;

    for (auto d: dir) {
        if (pos.first + d.first >= 0 && pos.first + d.first < 8
            && pos.second + d.second >= 0 && pos.second + d.second < 8) {
            ret.push_back({pos.first + d.first, pos.second + d.second});
        }
    }

    return ret;
}

int num_moves(std::pair<int, int> start, std::pair<int, int> end) {
    bool visited[8][8];

    for (int i = 0; i != 8; ++i) {
        for (int j = 0; j != 8; ++j) {
            visited[i][j] = false;
        }
    }

    visited[start.first][start.second] = true;

    std::queue<std::pair<std::pair<int, int>, int> > q;
    q.push({start, 0});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        if (cur.first == end) {
            return cur.second;
        }

        for (auto i: neighbours(cur.first)) {
            if (!visited[i.first][i.second]) {
                visited[i.first][i.second] = true;
                q.push({i, cur.second + 1});
            }
        }
    }

    return -1;  // error
}

int main() {
    std::string pos1;
    std::string pos2;

    while (std::cin >> pos1 >> pos2) {
        std::pair<int, int> start = {pos1[0] - 'a', pos1[1] - '1'};
        std::pair<int, int> end = {pos2[0] - 'a', pos2[1] - '1'};

        std::cout <<
            "To get from " <<
            pos1 <<
            " to " <<
            pos2 <<
            " takes " <<
            num_moves(start, end) <<
            " knight moves." <<
            std::endl
        ;
    }

    return 0;
}
