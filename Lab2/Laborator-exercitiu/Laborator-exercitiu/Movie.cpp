#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"
#include <string.h>
#include < ctime >

void Movie::set_name(const char nume[256])
{
	strcpy(name, nume);
}

const char* Movie::get_name() const
{
	return name;
}

void Movie::set_year(int year)
{
	releaseYear = year;
}

int Movie::get_year() const {
	return releaseYear;
}

void Movie::set_score(double score)
{
	if (score >= 1 && score <= 10)
	{
		imdbScore = score;
	}
}

double Movie::get_score() const
{
	return imdbScore;
}

void Movie::set_length(int minutes)
{
	lengthMinutes = minutes;
}

int Movie::get_length() const
{
	return lengthMinutes;
}

int Movie::get_passed() const
{
	time_t t = time(nullptr);
	tm* my_time = localtime(&t);
	return (my_time->tm_year + 1900 - releaseYear);
}
