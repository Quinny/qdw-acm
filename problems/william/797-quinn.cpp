#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int east_neg_offset(int v, int t, int ti) {
    int pos = ti * v;
    int times = -1 * pos / (t * v);
    if (pos % (t * v) == 0)
        return 0;
    else
        return pos + (times * (t * v)) + (t * v);
}

int east_pos_offset(int v, int t, int ti) {
    int pos = ti * v;
    int times = pos / (t * v);
    if (pos % (t * v) == 0)
        return 0;
    else
        return pos - (times * (t * v));
}

int west_neg_offset(int v, int t, int ti, int total_distance) {
    int pos = ti * v;
    int times = -1 * pos / (t * v);
    if (pos % (t * v) == 0)
        return total_distance;
    else
        return pos + (times * (t * v)) + total_distance;
}

int west_pos_offset(int v, int t, int ti, int total_distance) {
    int pos = total_distance + (ti * v);
    int times = pos / (t * v);
    if (pos % (t % v) == 0)
        return total_distance;
    else
        return pos - (times * (t * v));

}

int main() {
    int d, d1, d2, v1, v2, t1, t2, ti, tf;
    while (cin >> d >> d1 >> d2 >> v1 >> v2 >> t1 >> t2 >> ti >> tf) {
        int current_time = ti;
        int total_distance = d1 + d2 + d;
        vector<int> east_cars;
        vector<int> west_cars;

        // Quinn
        vector<int> east_spots(total_distance + 1, 0);
        vector<int> west_spots(total_distance + 1, 0);

        int addEast = 0;
        int addWest = 0;
        int meet = 0;
        int preMeet = 0;

        int east_start = 0, west_start = total_distance;
        if (ti < 0) {
            east_start = east_neg_offset(v1, t1, ti);
            west_start = west_neg_offset(v2, t2, ti, total_distance);
        } else if (ti > 0) {
            east_start = east_pos_offset(v1, t1, ti);
            west_start = west_neg_offset(v2, t2, ti, total_distance);
        }

        // Populate with already existing cars
        for (int i = 0; i <= (d1 + d); i+=(t1 * v1)) {
            ++east_spots[i];
            east_cars.push_back(i);
        }
        for (int i = total_distance; i>= d1; i-=(t2 * v2)) {
            ++west_spots[i];
            west_cars.push_back(i);
        }

        // Check for cars currently overlapping
        /*for (auto east : east_cars) {
            for (auto west : west_cars) {
                if ((east == west) && east > d1 && east < (d1 + d))
                    preMeet++;
            }
        }*/

        for (unsigned i = 0; i < east_spots.size(); ++i) {
            preMeet += std::min(east_spots[i], west_spots[i]);
        }

        // Simulation Loop :)
        while (current_time < tf) {
            // Determines when to add new cars
            if (addEast == t1) {
                east_cars.push_back(0);
                ++east_spots[0];
                addEast = 1;
            }
            else
                addEast++;

            if (addWest == t2) {
                west_cars.push_back(total_distance);
                addWest = 1;
                ++west_cars[total_distance];
            }
            else
                addWest++;

            // Remove unnecessary Westbound cars
            for (unsigned i = 0; i < west_cars.size(); ++i) {
                if (west_cars[i] <= d1)
                    west_cars.erase(west_cars.begin() + i);
            }

            // Remove unecessary east bound cars and calculate which west bound ones we will meet
            for (unsigned i = 0; i < east_cars.size(); ++i) {
                if (east_cars[i] >= (d1 + d)) {
                    east_cars.erase(east_cars.begin() + i);
                }
                else {
                    // calculating west bound cars I will pass WITHIN the tunnel
                    for (int j = 0; j < v1 + v2; ++j) {
                        if (west_spots[east_cars[i] + j] > 0) {
                            float travel_time = float(j)/float((v1 + v2)); // time to meet
                            float meet_position = (travel_time * v1) + east_cars[i]; // position of meeting
                            if (meet_position > d1 && meet_position < (d1 + d))
                                meet += west_spots[east_cars[i] + j];
                        }
                    }
                    --east_spots[east_cars[i]];
                    east_cars[i] += v1;
                    if (east_cars[i] <= total_distance)
                        ++east_spots[east_cars[i]];
                }
            }

            for (unsigned i = 0; i < west_cars.size(); ++i) {
                --west_spots[west_cars[i]];
                west_cars[i] -= v2;
                if (west_cars[i] >= 0)
                    ++west_spots[west_cars[i]];
            }
            current_time++;
        }

        cout << meet + preMeet <<  endl;
    }
}
