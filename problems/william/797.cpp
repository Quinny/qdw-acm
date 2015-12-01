#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

        // Populate with already existing cars
        for (int i = 0; i <= (d1 + d); i+=(t1 * v1))
            east_cars.push_back(i);
        for (int i = total_distance; i>= d1; i-=(t2 * v2))
            west_cars.push_back(i);

        // Check for cars currently overlapping
        for (auto east : east_cars) {
            for (auto west : west_cars) {
                if ((east == west) && east > d1 && east < (d1 + d))
                    preMeet++;    
            }
        }
        // Simulation Loop :)
        while (current_time < ti + 1) {
            // Determines when to add new cars
            if (addEast == t1)
                east_cars.push_back(0);
            else 
                addEast++;
            if (addWest == t2)
                west_cars.push_back(total_distance);
            else
                addWest++;
            
            // Remove unnecessary Westbound cars
            for (auto i = 0; i < west_cars.size(); ++i) {
                if (west_cars[i] <= d1) 
                    west_cars.erase(find(west_cars.begin(), west_cars.end(), west_cars[i]));
            }
            
            // Remove unecessary east bound cars and calculate which west bound ones we will meet
            for (auto i = 0; i < east_cars.size(); ++i) {
                if (east_cars[i] >= (d1 + d)) {
                    east_cars.erase(find(east_cars.begin(), east_cars.end(), east_cars[i]));
                }
                else {
                    // calculating west bound cars I will pass WITHIN the tunnel 
                    for (auto west : west_cars) {
                        if (west > east_cars[i] && west <= (east_cars[i] + v1 + v2)) {
                            float travel_time = float((west - east_cars[i]))/float((v1 + v2)); // time to meet
                            float meet_position = (travel_time * v1) + east_cars[i]; // position of meeting
                            if (meet_position  > d1 && meet_position < (d1 + d))
                                meet++;
                        }
                    } 
                    east_cars[i] += v1;
                }
            }

            for (auto i = 0; i < west_cars.size(); ++i) {
                west_cars[i] -= v2;
            }
            current_time++;
        }

        cout << (meet * abs(tf - ti)) + preMeet << endl; 
    }
}
