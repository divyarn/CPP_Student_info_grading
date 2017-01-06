#include <algorithm>
#include <string>
#include <ios>
#include <iostream>
#include <iomanip>
#include <stdexcept> 
#include <vector>
#include "Student_info.h"
#include "grade.h" 
 
using std::string;		using std::streamsize;
using std::vector;		using std::cout;
using std::cin;			using std::setprecision;
using std::sort;		using std::max;
using std::domain_error; using std::endl;


int main(){
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen =0;
		
	while(read(cin,record)){
		maxlen = max(record.name.size(),maxlen);
		students.push_back(record);
	}
		
	//compare function usage here
	sort(students.begin(),students.end(),compare);
	
	for(vector<Student_info>::size_type i=0; i!=students.size();i++){
		//write out the names and records of each of the student 
		cout << students[i].name 
			 << string(maxlen + 1 - students[i].name.size(),' ');
			 
		//compute and write the grade
		try{
			cout << students[i].homework.size()<<endl;	
			double final_grade = grade(students[i]); 
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				 << setprecision(prec);
		}catch(domain_error e){
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}
