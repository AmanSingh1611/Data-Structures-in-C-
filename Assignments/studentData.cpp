#include <iostream>
#include "student.cpp"
using namespace std;
int main(){
    students *s1 = new students();
    s1 ->name="Aman Kumar Singh";
    s1 ->rollnumber= 16;
    s1->show();
}