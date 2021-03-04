#include "canvas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

Canvas::Canvas(int lines, int columns)
{
	if (lines <= 128 && columns <= 128) {
		linie = lines;
		coloana = columns;
	}
	clear();
}

void Canvas::set_pixel(int x, int y, char value)
{
	s[x][y] = value;
}

void Canvas::set_pixels(int count, ...)
{
	int x;
	int y;
	char p;
	va_list v2;
	va_start(v2, count);
	for (int i = 0; i < count; i++)
	{
		x = va_arg(v2, int);
		y = va_arg(v2, int);
		p = va_arg(v2, char);
		set_pixel(x, y, p);
	}
	va_end(v2);
	//printf("%d\n", sum);
}

void Canvas::clear()
{
	for (int i = 0; i < linie; i++)
		for (int j = 0; j < coloana; j++)
			s[i][j] = ' ';
}

void Canvas::print() const
{
	for (int i = 0; i < linie; i++)
	{
		for (int j = 0; j < coloana; j++)
			printf("%c", s[i][j]);
		printf("\n");
	}
}