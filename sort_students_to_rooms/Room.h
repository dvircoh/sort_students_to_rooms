#pragma once
#include <set>
#include "Student.h"


class Room
{
public:
	Room(int size) : _size(size) {}
	bool is_full() const;
	void insert_student(Student*);



private:
	unsigned int _size;
	std::set<Student*> _room_members;



};

