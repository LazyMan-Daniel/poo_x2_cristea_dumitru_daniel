#pragma once

class Movie
{ 
	char name[256];
	unsigned releaseYear;
	double imdbScore;
	int lengthMinutes;
	int passedYears;

public:
	void set_name(const char nume[25]);
	const char* get_name() const;
	void set_year(int year);
	int get_year() const;
	void set_score(double score);
	double get_score() const;
	void set_length(int minutes);
	int get_length() const;
	int get_passed() const;


};

