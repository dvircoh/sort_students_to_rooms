#include <vector>
#include "Student.h"
#include "Room.h"
#include <iostream>


using std::cout;
using std::cin;
using std::string;
using std::endl;

void input_from_teacher(std::vector<Student> students, std::vector<Room> rooms);



int main()
{
	std::vector<Student> students;
	std::vector<Room> rooms;

	input_from_teacher(students, rooms);

	return 0;
}


void input_from_teacher(std::vector<Student> students, std::vector<Room> rooms)
{
	cout<<"Hello dear teacher \n please insert the name of your student"<<endl;
	
	int counter = 1;
	string name;
	cin >> name;

	do 
	{  //don't secure
		cout << "the name of the student is " << name << " it student number " << counter++ << endl;
		students.push_back(Student(name));
		cout << "if have more students insert name of student, else write 'end'" << endl;
		cin >> name;

	} while (!(name == "end"));






}