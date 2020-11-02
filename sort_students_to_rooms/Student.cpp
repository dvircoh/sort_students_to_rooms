#include "Student.h"

bool Student::is_friend(Student& other)
{
	for (auto i : _friends)
		if (i == other._name)
			return true;
	return false;
}

bool Student::is_not_friend(Student& other)
{
	for (auto i : _not_friends)
		if (i == other._name)
			return true;
	return false;
}



