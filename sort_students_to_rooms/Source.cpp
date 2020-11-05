#include <vector>
#include "Student.h"
#include "Room.h"
#include <iostream>


using std::cout;
using std::cin;
using std::string;
using std::endl;

void input_from_teacher(std::vector<Student> &students, std::vector<Room> &rooms);
void insert_students_name(std::vector<Student>& students);
void insert_friends(std::vector<Student>& students);
void insert_not_friends(std::vector<Student>& students);



int main()
{

	std::vector<Student> students;
	std::vector<Room> rooms;

	input_from_teacher(students, rooms);

	return 0;
}


void input_from_teacher(std::vector<Student> &students, std::vector<Room> &rooms)
{
	insert_students_name(students);
	insert_friends(students);
	insert_not_friends(students);
	

}

void insert_students_name(std::vector<Student>& students)
{
	cout << "Hello dear teacher \n please insert the name of your student" << endl;

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


void insert_friends(std::vector<Student>& students)
{

	for (auto i : students)
	{
		string name_of_friend;

		cout << "please insert friend's name of " << i.get_name() << " if have not friends write 'end'" << endl;
		while (!(name_of_friend == "end"))
		{
			cin >> name_of_friend;
			i.get_friends().push_back(name_of_friend);
			cout << "please insert friend's name of " << i.get_name() << " if have not more friends write 'end'" << endl;
		}
	}

}

void insert_not_friends(std::vector<Student>& students)
{
	for (auto i : students)
	{
		string name_of_not_friend;

		cout << "please insert not friend's name of " << i.get_name() << " if have not not friends write 'end'" << endl;
		while (!(name_of_not_friend == "end"))
		{
			cin >> name_of_not_friend;
			i.get_not_friends().push_back(name_of_not_friend);
			cout << "please insert not friend's name of " << i.get_name() << " if have not not more friends write 'end'" << endl;
		}
	}

}


