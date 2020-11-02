#pragma once
#include <string>
#include <vector>

class Student
{
public:
	Student(std::string& name)
		: _name(std::forward<std::string>(name))
	{}



	bool is_friend(Student&);
	bool is_not_friend(Student&);



private:


	std::string _name;
	std::vector<std::string> _friends;
	std::vector<std::string> _not_friends;
	bool occupied = false;
};

