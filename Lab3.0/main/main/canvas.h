#pragma once
class Canvas
{

    int linie, coloana;
    char s[128][128];

public:
    // calls clear
    Canvas(int lines, int columns);

    void set_pixel(int x, int y, char value);

    // tuples of x, y, value
    void set_pixels(int count, ...);
    void clear();
    void print() const;
};

