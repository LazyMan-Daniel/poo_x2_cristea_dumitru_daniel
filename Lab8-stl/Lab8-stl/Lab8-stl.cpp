#include <iostream>
#include "student.h"
#include <fstream>
#include <string>

using std::string;


int main()
{

    std::ifstream fin("input.txt");
    if (!fin.is_open()) {
        std::cout << "Nu s-a gasit fisierul\n";
        return 0;
    }

    Student stud;

    string in;

    while (!fin.eof()) {
        std::getline(fin, in);
        string::iterator it;

        string materie;
        for (it = in.begin(); (*it) != ' '; it++) {
            materie += *it;
        }

        int nota = 0;
        while (it != in.end()) {
            if (*it != ' ') {
                if ((it + 1) != in.end() && *it == '1' && *(it + 1) == '0')
                {
                    nota = 10; it++;
                }
                else {
                    nota = *(it)-'0';
                }
               
                stud.add_grade(materie, nota);
                nota = 0;
                
            }
            it++;
        }

    }
    stud.print_all();

}

