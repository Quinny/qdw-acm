#include <iostream>
#include <vector>

double sum(const std::vector<double>& nums) {
    double sum = 0;
    for (double i : nums)
        sum += i;
    return sum;
}

bool can_move(double cs_avg, double econ_avg, double move) {
    return move < cs_avg && move > econ_avg;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i != t; ++i) {
        int m, n;
        std::cin >> m >> n;

        std::vector<double> cs(m);
        std::vector<double> econ(n);

        for (int j = 0; j != m; ++j) {
            std::cin >> cs[j];
        }

        for (int j = 0; j != n; ++j) {
            std::cin >> econ[j];
        }

        double cs_avg = sum(cs) / m;
        double econ_avg = sum(econ) / n;

        int count = 0;
        for (double move : cs) {
            if (can_move(cs_avg, econ_avg, move))
                ++count;
        }

        std::cout << count << std::endl;
    }
}

