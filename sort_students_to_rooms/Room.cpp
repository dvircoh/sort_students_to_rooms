#include "Room.h"


bool Room::is_full()
{
	if (_room_members.size() < _size)
		return false;
	else return true;
}
void Room::insert_student(Student* new_student)
{
	_room_members.push_back(new_student);
}



