#include "Room.h"


bool Room::is_full() const
{
	if (_room_members.size() < _size)
		return false;
	else return true;
}

void Room::insert_student(Student* new_student)
{
	new_student->set_occupied(true);
	_room_members.insert(new_student);
	
}



