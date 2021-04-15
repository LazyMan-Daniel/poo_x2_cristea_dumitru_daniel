#include "student.h"
#include <map>
#include <vector>
#include <iostream>

void Student::add_grade(string course, unsigned short grade)
{
	noteStudent[course].push_back(grade);
}

void Student::print_all() const
{
	auto it=noteStudent.begin();

	for (it = noteStudent.begin(); it != noteStudent.end(); it++) {
	
		string materie=it->first;
		vector<int> note = it->second;

		for (auto it2 = note.begin(); it2 != note.end(); it2++) {
			std::cout <<materie<<' ' <<*it2 << '\n';
		}
			
		
	
	}

}
