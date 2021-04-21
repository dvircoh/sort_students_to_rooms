#pragma once
#include <string>
#include <vector>
#include <set>

class Student
{
public:
	Student(std::string& name)
		: _name(name)
	{}



	bool is_friend(const Student&) const;
	bool is_not_friend(const Student&) const;
	std::string get_name() const;
	bool get_occupied() const;
	std::set<Student>& get_friends();
	std::set<Student>& get_not_friends();
	void set_occupied(const bool status);
	inline bool operator==(const Student& other) const 
								{ return _name == other._name;}
	inline bool operator<(const Student& other) const 
								{ return _name < other._name; }
	
private:


	std::string _name;
	std::set<Student > _friends;
	std::set<Student > _not_friends;
	bool _occupied = false;
};

