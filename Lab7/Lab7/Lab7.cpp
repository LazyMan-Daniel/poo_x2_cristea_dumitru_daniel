#include "set.h"

struct WeirdCompare {
    bool asc;

    WeirdCompare() : WeirdCompare(true) {
    }
    WeirdCompare(bool asc) : asc(asc) {
    }

    bool operator()(const size_t& l, const size_t& r) const {
        if (asc) {
            return l % 10 < r % 10;
        }
        return l % 10 > r % 10;
    }
};

int main() {
    // implementati tot din  main
    Set<unsigned> unsigned_set;
    unsigned_set.add(5).add(3).add(1);
   // std::cout << unsigned_set;
    /**
    Set<int, std::greater<int>> int_set;
    int_set.add(-1).add(-5).add(10).add(1234).add(-5).add(-1);
    std::cout << int_set;

    Set<size_t, WeirdCompare> size_set(0, WeirdCompare(true));
    size_set.add(5).add(5_kib).add(5 * 1024 + 2).add(0).add(10_gib).add(5120_mib + 2).add(5_gib);
    std::cout << size_set;

    Set<size_t, WeirdCompare> size_set2(0, WeirdCompare(false));
    size_set2.add(5).add(5_kib).add(5 * 1024 + 2).add(0).add(10_gib).add(5120_mib + 2).add(5_gib);
    std::cout << size_set2; */
}