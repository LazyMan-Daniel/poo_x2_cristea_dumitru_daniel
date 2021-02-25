#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"
#include <string.h>

void Movie::setName(const char nume[25])
{
	strcpy(name, nume);
}

const char* Movie::getName() const
{
	return name;
}

void Movie::setYear(int year)
{
	releaseYear = year;
}

int Movie::getYear(){
	return releaseYear;
}

void Movie::setScore(double score)
{
	if (score >= 1 && score <= 10)
	{
		imdbScore = score;
	}
}

double Movie::getScore()
{
	return imdbScore;
}

void Movie::setLength(int minutes)
{
}

int Movie::getLength()
{
	return 0;
}

