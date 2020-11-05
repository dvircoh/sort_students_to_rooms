#include "Student.h"

bool Student::is_friend(const Student& other) const
{
	for (auto i : _friends)
		if (i == other._name)
			return true;
	return false;
}

bool Student::is_not_friend(const Student& other) const
{
	for (auto i : _not_friends)
		if (i == other._name)
			return true;
	return false;
}



std::string Student::get_name() const { return _name; }
	

bool Student::get_occupied() const { return _occupied; }

std::vector<std::string> Student::get_friends() const { return _friends;}

std::vector<std::string> Student::get_not_friends() const { return _not_friends; }

void Student::set_occupied(const bool status)
{
	_occupied = status;
}
