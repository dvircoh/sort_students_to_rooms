#pragma once
#include "Student.h"
#include "Room.h"
#include <set>


class Input
{
public:
	static void input_from_teacher(std::set<Student>& students, std::vector<Room>& rooms);
	static void insert_students(std::set<Student>& students);
	static void insert_friends(std::set<Student>& students);
	static void insert_not_friends(std::set<Student>& students);
};
