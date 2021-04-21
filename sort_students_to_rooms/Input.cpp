#include "Input.h"
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::endl;



void Input::input_from_teacher(std::set<Student>& students, std::vector<Room>& rooms)
{
	insert_students(students);
	insert_friends(students);
	insert_not_friends(students);


}

void Input::insert_students(std::set<Student>& students)
{
	cout << "Hello dear teacher \n please insert the name of your student" << endl;

	int counter = 1;
	string name;
	cin >> name;

	do
	{  //don't secure
		
		if (students.count(Student(name)))
		{
			cout << "error : The student exists" << endl;
		}
		else
		{
			cout << "the name of the student is " << name << " it student number " << counter++ << endl;
			students.insert(Student(name));
		}
		cout << "if have more students insert name of student, else write 'end'" << endl;
		cin >> name;

	} while (!(name == "end"));

}


void Input::insert_friends(std::set<Student>& students)
{
	string name_of_friend;
	for (auto i : students)
	{
		do
		{
			cout << "please insert friend's name of " << i.get_name() << " if have not friends write 'end'" << endl;
			cin >> name_of_friend;
			if (students.count(name_of_friend) && !i.get_friends().count(Student(name_of_friend)) && name_of_friend != i.get_name())
				auto f = i.get_friends().emplace(Student(name_of_friend));
			else if(name_of_friend != "end")
				cout << "error : The student does not exist or the student alredy exist in the list of the friends" << endl;
		} while (name_of_friend != "end");
	}

}

void Input::insert_not_friends(std::set<Student>& students)
{
	string name_of_not_friend;
	for (auto i : students)
	{		
		do
		{
			cout << "please insert not friend's name of " << i.get_name() << " if have not not friends write 'end'" << endl;
			cin >> name_of_not_friend;
			if (students.count(name_of_not_friend) && !i.get_not_friends().count(name_of_not_friend) && name_of_not_friend != i.get_name() && !i.get_friends().count(name_of_not_friend))
				i.get_not_friends().insert(Student(name_of_not_friend));
			else cout << "error : The student does not exist or the student alredy exist in the list of the not_friends" << endl;
			
			
		} while (name_of_not_friend != "end");
	}

}