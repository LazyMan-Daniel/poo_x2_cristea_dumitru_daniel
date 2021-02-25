#pragma once

class Movie
{ 
	char name[256];
	int releaseYear;
	double imdbScore;
	int lengthMinutes;
	int passedYears;

public:
	void setName(const char nume[25]);
	const char* getName() const;
	void setYear(int year);
	int getYear();
	void setScore(double score);
	double getScore();
	void setLength(int minutes);
	int getLength();



};

