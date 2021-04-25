#include "Input.h"
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::endl;

Input::Input(IDataAccess& dataAccess) : m_dataAccess(dataAccess) {}

void Input::input_from_teacher()
{
	insert_students();
	insert_friends();
	insert_not_friends();


}

void Input::insert_students()
{
	cout << "Hello dear teacher \nplease insert the name of your student" << endl;

	string name;
	cin >> name;

	do
	{  
		m_dataAccess.add_student(name);
		cout << "if have more students insert name of student, else write 'end'" << endl;
		cin >> name;

	} while (!(name == "end"));

}


void Input::insert_friends()
{
	string name_of_friend;
	std::vector<std::string> students = m_dataAccess.get_students_names();

	for (auto i : students)
	{
		do
		{
			cout << "please insert friend's name of " << i << " if have not friends write 'end'" << endl;
			cin >> name_of_friend;
			m_dataAccess.add_friend(i, name_of_friend);
		} while (name_of_friend != "end");
	}

}

void Input::insert_not_friends()
{
	string name_of_not_friend;
	std::vector<std::string> students = m_dataAccess.get_students_names();
	for (auto i : students)
	{		
		do
		{
			cout << "please insert not friend's name of " << i << " if have not not friends write 'end'" << endl;
			cin >> name_of_not_friend;
			m_dataAccess.add_not_friend(i, name_of_not_friend);			
		} while (name_of_not_friend != "end");
	}

}