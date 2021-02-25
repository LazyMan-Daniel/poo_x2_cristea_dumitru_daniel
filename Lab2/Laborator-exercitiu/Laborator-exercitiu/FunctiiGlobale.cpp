#include "FunctiiGlobale.h"
#include "Movie.h"

int movie_compare_name(Movie& m1, Movie& m2)
{
	return 1;
}

int movie_compare_year(Movie m1, Movie m2)
{
	return compare_number(m1.get_year(), m2.get_year());
}

int movie_compare_score(Movie& m1, Movie& m2)
{
	return compare_number(m1.get_score(), m2.get_score());
}

int movie_compare_length(Movie& m1, Movie& m2)
{
	return compare_number(m1.get_length(), m2.get_length());
}

int movie_compare_passed_years(Movie& m1, Movie& m2)
{
	return compare_number(m1.get_passed(), m2.get_passed());
}

int compare_number(int n1, int n2)
{
	if (n1 < n2) return -1;
	if (n1 == n2) return 0;
	return 1;
}
