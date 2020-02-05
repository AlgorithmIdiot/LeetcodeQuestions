#ifndef SELECTIONSORT_STUDENT_H
#define SELECTIONSORT_STUDENT_H
#include<iostream>
#include<string>

class Student{
public: // for the struct, no need to add "public:"
	std::string name;
	int score;
	bool operator<(const Student &otherStudent){
		return score<otherStudent.score;
	}
	friend std::ostream& operator<<(std::ostream &os, const Student &student){
		os<<"Student: "<<student.name<<" "<<student.score<<std::endl;
		return os;
	}
};

#endif
