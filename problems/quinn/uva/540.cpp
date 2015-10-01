#include <iostream>
#include <map>
#include <vector>
#include <queue>

template <typename T>
struct team_queue {
    std::vector<std::queue<T>> line;

    std::map<T, std::size_t> person_to_team;
    std::map<std::size_t, std::size_t> team_to_pos;

    std::size_t team_id = 0;

    void register_team(const std::vector<T>& team) {
        for (auto i: team)
            person_to_team[i] = team_id;
        ++team_id;
    }

    void enqueue(const T& x) {
        auto team = person_to_team[x];
        if (team_to_pos.find(team) == team_to_pos.end()) {
            std::queue<T> q;
            q.push(x);
            team_to_pos[team] = line.size();
            line.push_back(q);
        }
        else {
            auto teampos = team_to_pos[team];
            if (line[teampos].empty()) {
               team_to_pos[team] = line.size();
               std::queue<T> q;
               q.push(x);
               line.push_back(q);
            }
            else
                line[team_to_pos[team]].push(x);
        }
    }

    T dequeue() {
        std::size_t di = 0;
        while (line[di].empty())
            ++di;
        auto f = line[di].front();
        line[di].pop();
        return f;
    }
};

int main() {
    int n;
    int tcase = 0;
    while (true) {
        std::cin >> n;
        if (n == 0) break;
        ++tcase;
        team_queue<int> q;
        for (int _ = 0; _ < n; ++_) {
            int team_size;
            std::vector<int> team;
            std::cin >> team_size;
            for (int i = 0; i < team_size; ++i) {
                int p;
                std::cin >> p;
                team.push_back(p);
            }
            q.register_team(team);
        }
        std::string command;
        std::cout << "Scenario #" << tcase << std::endl;
        while (true) {
            std::cin >> command;
            if (command == "STOP") {
                std::cout << std::endl;
                break;
            }
            if (command == "ENQUEUE") {
                int arg;
                std::cin >> arg;
                q.enqueue(arg);
            }
            if (command == "DEQUEUE") {
                std::cout << q.dequeue() << std::endl;
            }
        }
    }
    return 0;
}
