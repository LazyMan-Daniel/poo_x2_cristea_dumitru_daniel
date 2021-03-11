#include "MyLibrary.h"
#include <stdarg.h>

MyLibrary::MyLibrary(const MyLibrary& ten) : output_stream(ten.output_stream)
{

	this->books_count = ten.books_count;
	this->books = new int[this->books_count];
	for(int i=0;i< this->books_count;i++)
	this->books[i] = ten.books[i];
}

MyLibrary::MyLibrary(std::ostream& output_stream) : output_stream(output_stream)
{}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int* books) : output_stream(output_stream), books_count(books_count)
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
	int count =1;
	for (int i = 0; i < strlen(books_values); i++) {
		if (books_values[i] == ';')
			count++;
	}
    int nr = 0;
	books = new int[count];
	books_count = 0;
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
	books[books_count++] = nr;
	books_count = count;
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...) : output_stream(output_stream)
{
	books = new int[books_count];
	this->books_count = books_count;
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

void MyLibrary::print_books() const
{
	if (books_count == 0)
		output_stream << "Found - 1 books \n";
	else {
		output_stream << "Found " << books_count << " books\n";
		for (int i = 0; i < books_count; i++)
			output_stream << books[i] << "\n";
	}
}

void MyLibrary::update_book_id_by_index(unsigned book_index, int book_id)
{
	if(book_index < this->books_count)
	books[book_index] = book_id;
}

int MyLibrary::get_books_count() const
{
	return books_count;
}

int MyLibrary::get_book_id_by_index(int index) const
{
	return books[index];
}
