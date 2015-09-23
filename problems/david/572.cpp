#include <iostream>
#include <string>
#include <sstream>

void visit_deposit(bool** grid, bool** visited, int m, int n, int y, int x) {
    visited[y][x] = true;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if ((y+i) >= 0 && (y+i) < m && (x+j) >= 0 && (x+j) < n) {
                if (grid[y+i][x+j] && !visited[y+i][x+j]) {
                    visit_deposit(grid, visited, m, n, y+i, x+j);
                }
            }
        }
    }
}


int num_deposits(bool** grid, bool** visited, int m, int n) {
    int deposits = 0;
    for (int i = 0; i != m; ++i) {
        for (int j = 0; j != n; ++j) {
            if (grid[i][j] && !visited[i][j]) {
                ++deposits;
                visit_deposit(grid, visited, m, n, i, j);
            }
        }
    }
    return deposits;
}

int main() {
    int m;
    int n;

    while (true) {
        std::cin >> m >> n;
        if (m == 0) {
            return 0;
        }

        bool** grid = new bool* [m];
        bool** visited = new bool* [m];

        for (int i = 0; i != m; ++i) {
            grid[i] = new bool[n];
            visited[i] = new bool[n];
        }

        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                grid[i][j] = 0;
                visited[i][j] = 0;
            }
        }

        std::string s;
        for (int i = 0; i != m; ++i) {
            std::cin >> s;
            for (unsigned j = 0; j < s.length(); ++j) {
                if (s[j] == '@') {
                    grid[i][j] = true;
                }
            }
        }

        std::cout << num_deposits(grid, visited, m, n) << std::endl;

        for (int i = 0; i != m; ++i) {
            delete[] grid[i];
            delete[] visited[i];
        }
        delete[] grid;
        delete[] visited;
    }

    return 0;
}

