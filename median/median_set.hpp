#ifndef _DV_MEDIAN_SET_
#define _DV_MEDIAN_SET_

#include <set>

template <typename T>
class median_set {
    private:
    std::multiset<T> small;
    std::multiset<T> large;

    public:
    median_set() : small(), large() { }

    std::size_t size() const { return small.size() + large.size(); }

    // Return the median between the two sets O(1)
    T median() const {
        std::size_t small_size = small.size();
        std::size_t large_size = large.size();

        if (small_size == large_size) {
            return (*(small.rbegin()) + *(large.begin())) / 2;
        } else if (small_size > large_size) {
            return *(small.rbegin());
        } else {
            return *(large.begin());
        }
    }

    void insert(const T& n) {
        std::size_t small_size = small.size();
        std::size_t large_size = large.size();

        if (small_size == large_size) {
            if (small_size == 0) {
                small.insert(n);
            } else {
                T large_min = *(large.begin());
                if (n < large_min)
                    small.insert(n);
                else
                    large.insert(n);
            }
        }

        else if (small_size > large_size) {
            T small_max = *(small.rbegin());
            if (n <= small_max) {
                small.erase(std::prev(small.end()));
                large.insert(small_max);
                small.insert(n);
            } else {
                large.insert(n);
            }
        }

        else if (large_size > small_size) {
            T large_min = *(large.begin());
            if (n >= large_min) {
                large.erase(large.begin());
                small.insert(large_min);
                large.insert(n);
            } else {
                small.insert(n);
            }
        }
    }

    // Remove a single instance of n from the set
    void erase(const T& n) {
        std::size_t small_size = small.size();
        std::size_t large_size = large.size();

        if (small_size == large.size()) {
            T large_min = *(large.begin());
            if (n < large_min) {
                small.erase(small.find(n));
            } else {
                large.erase(large.find(n));
            }
            return;
        }

        else if (small_size > large_size) {
            T small_max = *(small.rbegin());
            if (n <= small_max) {
                small.erase(small.find(n));
            } else {
                large.erase(large.find(n));
                small.erase(std::prev(small.end()));  // can't del rev iterator
                large.insert(small_max);
            }
        }

        else if (small_size < large_size) {
            T large_min = *(large.begin());
            if (n >= large_min) {
                large.erase(large.find(n));
            } else {
                small.erase(small.find(n));
                large.erase(large.begin());
                small.insert(large_min);
            }
        }
    }
};

#endif
