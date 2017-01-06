#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error; using std::vector;

double grade(double a,double b,double c){
	return 0.2*a + 0.4*b + 0.4*c;
}
double grade(double midterm, double final, const vector<double>& hw){
	if(hw.size()==0) throw domain_error("Student hasn't done any homework grade2 function called");
	return 0.2*midterm + 0.4*final + 0.4*median(hw);
}
double grade(const Student_info& si){
	if(si.homework.size()==0) throw domain_error("Student hasn't done any homework");
	return 0.2*si.midterm + 0.4*si.final + 0.4*median(si.homework);
}
