#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d, d1, d2, v1, v2, t1, t2, ti, tf;
int total_distance;

/*
int east_start(int v, int t, int ti) {
    int pos = ti * v;
    while (pos > 0) {
        pos -= v * t;
    }
    return pos + (v * t);
}

int west_start(int v, int t, int ti, int td) {
    int pos = td - (ti * v);
    while (pos < td) {
        pos += v * t;
    }
    return pos - (v * t);
}
*/

int east_start(int v, int t, int ti) {
    if (ti % t == 0)
        return 0;
    if (ti < 0) {
        ti *= -1;
        return (v * t) - (v * (ti % t));
    }
    return v * (ti % t);
}

int west_start(int v, int t, int ti, int td) {
    if (ti % t == 0)
        return td;
    if (ti < 0) {
        ti *= 1;
        return td - ((v * t) - (v * (ti % t)));
    }
    return td - (v * (ti % t));
}

int simulate(int start, int end, vector<int>& east_cars, vector<int>& west_cars) {
    int addEast = 0;
    int addWest = 0;
    int meet = 0;
    int current_time = start;

    // Simulation Loop :)
    while (current_time < end) {
        // Determines when to add new cars
        if (addEast == t1) {
            east_cars.push_back(0);
            addEast = 1;
        }
        else
            addEast++;

        if (addWest == t2) {
            west_cars.push_back(total_distance);
            addWest = 1;
        }
        else
            addWest++;

        // Remove unnecessary Westbound cars
        for (auto i = 0U; i < west_cars.size(); ++i) {
            if (west_cars[i] <= d1)
                west_cars.erase(west_cars.begin() + i);
        }

        // Remove unecessary east bound cars and calculate which west bound ones we will meet
        for (auto i = 0U; i < east_cars.size(); ++i) {
            if (east_cars[i] >= (d1 + d)) {
                east_cars.erase(east_cars.begin() + i);
            }
            else {
                // calculating west bound cars I will pass WITHIN the tunnel
                for (auto west : west_cars) {
                    if (west > east_cars[i] && west <= (east_cars[i] + v1 + v2)) {
                        double travel_time = double((west - east_cars[i])) / double((v1 + v2)); // time to meet
                        double meet_position = (travel_time * v1) + east_cars[i]; // position of meeting
                        // cout << current_time << " " << meet_position << " " << d1 << " " <<  d1 + d << endl;
                        if (meet_position > d1 && meet_position < (d1 + d))
                            meet++;
                    }
                }
                east_cars[i] += v1;
            }
        }

        for (auto i = 0U; i < west_cars.size(); ++i) {
            west_cars[i] -= v2;
        }
        current_time++;
    }

    return meet;
}

int main() {
    while (cin >> d >> d1 >> d2 >> v1 >> v2 >> t1 >> t2 >> ti >> tf) {
        total_distance = d1 + d2 + d;
        int preMeet = 0;

        vector<int> east_cars;
        vector<int> west_cars;
        // int limit = t1 * t2;

        // These are needed to shift the start positions by an offset of ti
        int e_start = east_start(v1, t1, ti);
        int w_start = west_start(v2, t2, ti, total_distance);

        // Populate with already existing cars
        for (int i = e_start; i <= (d1 + d); i += (t1 * v1))
            east_cars.push_back(i);
        for (int i = w_start; i >= d1; i -= (t2 * v2))
            west_cars.push_back(i);

        // Check for cars currently overlapping
        for (auto east : east_cars) {
            for (auto west : west_cars) {
                if ((east == west) && east > d1 && east < (d1 + d))
                    preMeet++;
            }
        }

        if ((t1 * t2) >= (tf - ti)) {
            cout << simulate(ti, tf, east_cars, west_cars) + preMeet << endl;
        } else {
            int range = tf - ti;
            int limit = t1 * t2;
            int period = simulate(0, limit, east_cars, west_cars);

            int start = range % limit;
            if (start < 0)
                start *= -1;
            int leftovers = simulate(0, start, east_cars, west_cars);

            cout << ((range / limit) * period) + leftovers + preMeet << endl;
        }
    }
}

