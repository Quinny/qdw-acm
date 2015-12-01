#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

int main() {
    int d, d1, d2, v1, v2, t1, t2, ti, tf;
    while (cin >> d >> d1 >> d2 >> v1 >> v2 >> t1 >> t2 >> ti >> tf) {
        int current_time = ti;
        int total_distance = d1 + d2 + d;
        vector<int> east_cars;
        vector<int> west_cars;
        int addEast = 0;
        int addWest = 0;
        int meet = 0;
        int preMeet = 0;

        current_time = 0;
        int limit = t1 * t2;

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

        // Simulation Loop :)
        while (current_time < limit) {
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
                            float travel_time = float((west - east_cars[i]))/float((v1 + v2)); // time to meet
                            float meet_position = (travel_time * v1) + east_cars[i]; // position of meeting
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

        int range = tf - ti;
        cout << meet + preMeet <<  endl;
        cout << ((range / limit) * meet) << endl;
    }
}
