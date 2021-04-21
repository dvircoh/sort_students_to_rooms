#include "Student.h"

bool Student::is_friend(const Student& other) const
{
	for (auto i : _friends)
		if (i._name == other._name)
			return true;
	return false;
}

bool Student::is_not_friend(const Student& other) const
{
	for (auto i : _not_friends)
		if (i._name == other._name)
			return true;
	return false;
}



std::string Student::get_name() const { return _name; }
	

bool Student::get_occupied() const { return _occupied; }

std::set<Student>& Student::get_friends()  { return this->_friends;}

std::set<Student>& Student::get_not_friends()  { return _not_friends; }

void Student::set_occupied(const bool status)
{
	_occupied = status;
}
