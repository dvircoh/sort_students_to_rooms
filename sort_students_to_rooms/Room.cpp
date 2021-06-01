#include "Room.h"


bool Room::is_full() const
{
	if (_room_members.size() < _size)
		return false;
	else return true;
}

void Room::insert_student(Student new_student)
{
	_room_members.push_back(new_student);
}

void Room::remove_last_student()
{
	_room_members.pop_back();
}

bool Room::no_not_friends_in_room(const std::string& student) const
{
	for (const auto& i : _room_members)
		if (i.is_not_friend(student))
			return false;
	return true;
}

const std::vector<Student>& Room::get_room_members() const
{
	return _room_members;
}

std::ostream& operator<<(std::ostream& os, const Room& rm)
{
	os << "members of room id " << rm._id << "	";
	for (auto i : rm._room_members)
		os << i.get_name() << "	";
	os << std::endl;
	return os;
}
