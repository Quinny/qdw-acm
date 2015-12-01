#include <iostream>
#include <vector>

int main() {
    int d, d1, d2, v1, v2, t1, t2, ti, tf;

    // Treat d1 + d + d2 as width of simulation
    while (std::cin >> d >> d1 >> d2 >> v1 >> v2 >> t1 >> t2 >> ti >> tf) {
        std::vector<int> east;
        std::vector<int> west;

        for (int i = 0; i < d1 + d; i += v1 * t1)
            east.push_back(i);
        for (int i = d1 + d2 + d; i > d1; i -= v2 * t2)
            west.push_back(i);


    }
}
