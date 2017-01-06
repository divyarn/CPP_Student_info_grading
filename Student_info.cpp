#include "Student_info.h"
#include "grade.h"
#include <iostream>
#include <vector>
#include <stdexcept>

using std::istream; using std::vector;
using std::domain_error;

bool compare(const Student_info& s1,const Student_info& s2){
	return s1.name < s2.name;
}

istream& read(istream& is, Student_info& s){
	is >> s.name >> s.midterm >> s.final;
	read_hw(is,s.homework);
	std::cout << "size of homework" << s.homework.size();
	return is;
}
istream& read_hw(istream& in, vector<double>& hw){
	if(in){
		hw.clear();
		std::cout << "reading homework";
		double x;
		while(in>>x) hw.push_back(x);
		in.clear();
	}
	return in;
}
bool fgrade(const Student_info& s){
	return grade(s)<60;
}

