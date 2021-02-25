#define _CRT_SECURE_NO_WARNINGS
#include "MovieSeries.h"
#include <stdio.h>

void MovieSeries::init()
{
	count = 0;
}

void MovieSeries::add(Movie* m1)
{
	movieSeries[count] = m1;
	count++;
}

void MovieSeries::sort()
{
	int i, j;
	Movie* aux;
	for(i=0;i<count-1;i++)
		for(j=i+1;j<count;j++)
		if(movieSeries[i]->get_passed()< movieSeries[j]->get_passed())
		{
			aux = movieSeries[i];
			movieSeries[i] = movieSeries[j];
			movieSeries[j] = aux;
		}

}

void MovieSeries::print()
{
	int i;
	for (i = 0; i < count; i++)
	{
		printf("Filmul %s a aparut in anul %d, adica in urma cu %d ani. Are nota %f pe IMDB si are lungimea de %d minute\n",
			movieSeries[i]->get_name(), movieSeries[i]->get_year(), movieSeries[i]->get_passed(), movieSeries[i]->get_score(),
			movieSeries[i]->get_length());
	}
}
