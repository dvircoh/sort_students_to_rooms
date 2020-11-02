#pragma once
#include <vector>
#include "Student.h"


class Room
{
public:
	Room(int size) : _size(size) {}
	bool is_full();
	void insert_student(Student*);



private:
	int _size;
	std::vector<Student*> _room_members;



};

