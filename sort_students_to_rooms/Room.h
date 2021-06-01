#pragma once
#include <vector>
#include <iostream>
#include "Student.h"


class Room
{
public:
	Room(int id, int size) : _id(id), _size(size) {}
	bool is_full() const;
	void insert_student(Student);
	void remove_last_student();
	bool no_not_friends_in_room(const std::string& student) const;
	const std::vector<Student>& get_room_members() const;
	friend std::ostream& operator<<(std::ostream& os, const Room& rm);
private:
	unsigned int _id;
	unsigned int _size;
	std::vector<Student> _room_members;
};

