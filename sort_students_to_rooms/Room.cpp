#include "Room.h"


bool Room::is_full() const
{
	if (_room_members.size() < _size)
		return false;
	else return true;
}

void Room::insert_student(std::string new_student)
{
	_room_members.push_back(new_student);
}


std::ostream& operator<<(std::ostream& os, const Room& rm)
{
	for (auto i : rm._room_members)
		os << i << "	";
	os << std::endl;
	return os;
}
