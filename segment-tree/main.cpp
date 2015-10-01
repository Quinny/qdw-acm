#include "segment_tree.h"
#include <iostream>

int main() {
    std::vector<int> v{1,2,3,4};
    segment_tree<int> t(v);
    
    std::cout <<
        t.sum_range(0, 1)
    << std::endl;
    return 0;
}
