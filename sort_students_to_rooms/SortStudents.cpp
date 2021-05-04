#include "SortStudents.h"

void SortStudents::matching_students_to_the_room()
{
	auto students = m_dataAccess.get_students_names();
	auto rooms = m_dataAccess.get_rooms(); //attention! memory problem
	if (add_student_to_room(rooms, students, 0))
		m_dataAccess.populate_rooms(rooms);
}

bool SortStudents::add_student_to_room(std::vector<Room>& rooms, const std::vector<std::string>& students, int i)
{
	if (i == students.size())
			return true;
	for (auto& j : rooms)
	{
		if (!j.is_full() && j.no_not_friends_in_room(students[i]))
		{
			j.insert_student(students[i]);
			if(j.is_full())
				if (!each_student_have_friend(j)) //if this a final room check that to each student have a friend 
					return false;
			return add_student_to_room(rooms, students, i + 1);
		}
		else return false;
	}
		
}

bool SortStudents::each_student_have_friend(const Room& room) const
{
	for (const auto& student : room.get_room_members())
		for (const auto& friends : room.get_room_members())
			if (student.is_friend(friends.get_name()))
				break;
			else if (&friends == &room.get_room_members().back())
				return false;
	return true;
}