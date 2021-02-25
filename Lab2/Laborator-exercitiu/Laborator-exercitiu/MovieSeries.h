#pragma once
#include "Movie.h"
class MovieSeries
{
	int count;
	Movie* movieSeries[17];

public:
	void init();
	void add(Movie* m1);
	void sort();
	void print();

};

