#include <iostream>
#include <string>

const std::string a[] = {
    "", "1", "22", "333", "4444", "55555",
    "666666", "7777777", "88888888", "999999999"
};

int main() {
    unsigned n;
    std::string total = "";
    std::cin >> n;

    while (n--) {
        unsigned amp, freq;
        std::cin >> amp >> freq;
        std::string output = "";
        while (freq--) {
            for (unsigned i = 1; i < amp; ++i)
                output += a[i] + "\n";

            for (unsigned k = amp; k > 0; --k)
                output += a[k] + "\n";

            if (freq || n)
                output += "\n";
        }
        total += output;
    }

    std::cout << total;
    return 0;
}
