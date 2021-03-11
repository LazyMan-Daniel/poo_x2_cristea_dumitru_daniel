#include "MyLibrary.h"
#include <stdarg.h>

MyLibrary::MyLibrary(std::ostream& output_stream) : output_stream(output_stream)
{}

MyLibrary::MyLibrary(std::ostream & output_stream, unsigned books_count, int* books): output_stream(output_stream), books_count(books_count)
{
    this->books = new int[books_count];
    for (int i = 0; i < books_count; i++)
        this->books[i] = books[i];
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max) : output_stream(output_stream), books_count(books_count)
{   
	books = new int[books_count];
	for (int i = 0; i < books_count; i++)
	{
		books[i] = min + (rand() % (max - min));
	}
}

MyLibrary::MyLibrary(std::ostream& output_stream, const char* books_values) : output_stream(output_stream)
{
	int nr = 0;
	books = new int[100];

	for (int i = 0; i < strlen(books_values); i++) {
		if (books_values[i] != ';')
		{
			nr = nr * 10 + (books_values[i] - '0');
		}
		else
		{
			books[books_count++] = nr;
			nr = 0;
		}
	}
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...) : output_stream(output_stream)
{
	books = new int[books_count];
	va_list v1;
	va_start(v1, books_count);
	for (int i = 0; i < books_count; i++)
	{
		books[i] = va_arg(v1, int);
	}
	va_end(v1);
}

MyLibrary::~MyLibrary() {
    delete[] books;
}

void MyLibrary::print_books()
{
	if (books_count == 0)
		output_stream << "Found - 1 books";
	else {
		for (int i = 0; i < books_count; i++)
			output_stream << books[i];
	}
}
