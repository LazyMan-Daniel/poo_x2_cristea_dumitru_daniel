#pragma once
struct Printer {
    static void print_add(int, int);
    static void print_add(int, int, int);
    static void print_add(double, double);
    static void print_add(double, double, double);
    // prints the sum of a list of integers
    static void print_add(int count, ...);
    // adds the strings togheter by allocating the memory dynamically
    // and then prints it
    // if any of the strings is nullptr, it will be treated as empty
    static void print_add(const char*, const char*);
};
