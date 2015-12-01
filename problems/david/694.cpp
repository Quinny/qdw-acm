#include <iostream>

int64_t steps(int64_t a, int64_t l) {
    unsigned c = 1;

    while (a != 1) {
        if (a & 1)
            a = (3 * a) + 1;
        else
            a /= 2;

        if (a > l)
            break;

        ++c;
    }

    return c;
}

int main() {
    int64_t a, l;
    unsigned c = 1;
    while (std::cin >> a >> l) {
        if (a < 0 && l < 0)
            break;

        printf("Case %u: A = %ld, limit = %ld, number of terms = %ld\n", c, a, l, steps(a, l));

        ++c;
    }

    return 0;
}

