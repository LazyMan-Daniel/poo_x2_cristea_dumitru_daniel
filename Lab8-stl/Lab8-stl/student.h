#pragma once

#include <string>
#include <map>
#include <vector>

using std::vector;
using std::string;
using std::map;

// cititi din fisierul input.txt liniile de mai jos, toate operatiile cu siruri de caractere sa foloseasca std::string de forma <materie> spatiu <nota> <optional spatiu nota....> <optional spatiu nota....>
// pentru a separa campurile folositi functiile din std::string!
// toate campurile sunt separate printr-un spatiu, trebuie sa luati materia si sa adauga notele elevului folosind un obiect de tipul Student in main cu functia add_grade
// adaugati datele care lipsesc in clasa pentru a putea tine minte materiile si notele, si implementati cele 2 functii add_grade si print_all (vedeti ce face functia de printare, scrie deasupra ei)
// creati voi main-ul unde cititi din fisier, creati obiectul
// creati fisierele cpp necesare

/*
INPUT DE PUS IN FISIERUL input.txt
matematica 2
chimie 3 4 5
fizica 9
biologie 10
informatica 7
*/

class Student {


    map<string, vector<int>> noteStudent;
    // tip data unde puteti folosi cheie / valoare -> sa puteti adauga notele -> FOLOSITI STDLIB
public:
    // are capacitatea sa aiba mai multe note la aceeasi materie
    void add_grade(string course, unsigned short grade);

    // trece prin toate campurile folosind iteratori si afiseaza materia si notele de la materie
    void print_all() const;
};

