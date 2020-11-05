#pragma once
#include <string>
#include <vector>

class Student
{
public:
	Student(std::string& name)
		: _name(std::forward<std::string>(name))
	{}



	bool is_friend(const Student&) const;
	bool is_not_friend(const Student&) const;
	std::string get_name() const;
	bool get_occupied() const;
	std::vector<std::string> get_friends() const;
	std::vector<std::string> get_not_friends() const;
	void set_occupied(const bool status);

private:


	std::string _name;
	std::vector<std::string> _friends;
	std::vector<std::string> _not_friends;
	bool _occupied = false;
};

