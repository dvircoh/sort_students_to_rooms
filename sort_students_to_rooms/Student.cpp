#include "Student.h"

bool Student::is_friend(const std::string& name) const
{
	return _friends.count(name);
}

bool Student::is_not_friend(const std::string& name) const
{
	return _not_friends.count(name);
}

void Student::add_friend(std::string name_of_friend)
{
	_friends.emplace(name_of_friend);
}
void Student::add_not_friend(std::string name_of_not_friend)
{
	_not_friends.emplace(name_of_not_friend);
}

std::string Student::get_name() const { return _name; }
	

bool Student::get_occupied() const { return _occupied; }

//std::set<Student>& Student::get_friends()  { return this->_friends;}

//std::set<Student>& Student::get_not_friends()  { return _not_friends; }

void Student::set_occupied(const bool status)
{
	_occupied = status;
}
