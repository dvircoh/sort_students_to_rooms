#pragma once
#include <vector>
#include <iostream>
#include "Student.h"


class Room
{
public:
	Room(int size) : _size(size) {}
	bool is_full() const;
	void insert_student(std::string);
	friend std::ostream& operator<<(std::ostream& os, const Room& rm);
private:
	unsigned int _size;
	std::vector<std::string> _room_members;
};

