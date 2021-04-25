#pragma once
#include <string>
#include <vector>
#include <set>

class Student
{
public:
	Student(std::string name)
		: _name(name)
	{}



	bool is_friend(const std::string&) const;
	bool is_not_friend(const std::string&) const;
	std::string get_name() const;
	bool get_occupied() const;
	std::set<std::string>& get_friends();
	std::set<std::string>& get_not_friends();
	void add_friend(std::string name_of_friend);
	void add_not_friend(std::string name_of_not_friend);
	void set_occupied(const bool status);
	//inline bool operator==(const Student& other) const 
	//							{ return _name == other._name;}
	//inline bool operator<(const Student& other) const 
	//							{ return _name < other._name; }
	
private:


	std::string _name;
	std::set<std::string> _friends;
	std::set<std::string> _not_friends;
	bool _occupied = false;
};

