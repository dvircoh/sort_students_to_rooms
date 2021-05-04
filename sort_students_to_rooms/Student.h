#pragma once
#include <string>
#include <vector>
#include <set>
#include <iostream>

class Student
{
public:
	Student(std::string name) : _name(name) {}
	bool is_friend(const std::string& name) const;
	bool is_not_friend(const std::string& name) const;
	std::string get_name() const;
	void add_friend(std::string name_of_friend);
	void add_not_friend(std::string name_of_not_friend);
	friend std::ostream& operator<<(std::ostream& os, const Student& st);
private:
	std::string _name;
	std::set<std::string> _friends;
	std::set<std::string> _not_friends;
};

