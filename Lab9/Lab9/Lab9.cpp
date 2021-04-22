#include <iostream>
#include "Map.h"

int main()

{

	Map<int, const char*> m;

	m[10] = "C++";

	m.Set(20, "test");
	// m[20] = "test";

	m[30] = "Poo";



	for (auto [key, value, index] : m)

	{

		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

	}
	printf("\n");


	m[20] = "result";

	for (auto [key, value, index] : m)

	{

		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

	}
	printf("\n");

	m.Delete(20);

	for (auto [key, value, index] : m)

	{

		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

	}
	printf("\n");

	m.Clear();



	for (auto [key, value, index] : m)

	{

		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

	}
	printf("\n");



	return 0;

}