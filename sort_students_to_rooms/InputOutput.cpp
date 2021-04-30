#include "InputOutput.h"
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::endl;

InputOutput::InputOutput(IDataAccess& dataAccess) : m_dataAccess(dataAccess) {}

void InputOutput::input_from_teacher()
{
	insert_students();
	insert_friends();
	insert_not_friends();
	insert_room_details();

}

void InputOutput::insert_students()
{
	cout << "Hello dear teacher \nplease insert the name of your student" << endl;
	string name;
	do
	{
		cin >> name;
		m_dataAccess.add_student(name);
		cout << "if have more students insert name of student, else write 'end'" << endl;
	} while (!(name == "end"));
}


void InputOutput::insert_friends()
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

void InputOutput::insert_not_friends()
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

void InputOutput::insert_room_details()
{
	int i = 1;
	cout << "please insert size of room number" << i << endl;
	int room_size;
	do
	{
		cin >> room_size;	//don't secure (if type string)
		if (room_size < 1)
			std::cout << "error : Room size must be big then 0" << std::endl;
		else
		{
			m_dataAccess.add_room(i, room_size);
			cout << "room number" << i << "added" << endl;
			i++;
		}
		cout << "if have more room insert his size, else insert 0" << endl;
	} while (room_size);
}

void InputOutput::print_rooms()
{
	auto rooms = m_dataAccess.get_rooms();
	for (auto i : rooms)
		cout << i << endl;
}