#include "SortStudents.h"

void SortStudents::matching_students_to_the_room()
{
	auto students = m_dataAccess->get_students_names();
	auto rooms = m_dataAccess->get_rooms(); 
	if (add_student_to_room(rooms, students, 0))
		m_dataAccess->populate_rooms(rooms);
	else std::cout << "impossible mission" << std::endl;
}

bool SortStudents::add_student_to_room(std::vector<Room>& rooms, const std::vector<std::string>& students, int index_student)
{	 
	if (index_student == students.size())
	{
		if(check_rooms(rooms))
			return true;
		else return false;
	}
	
	for (auto j : rooms)
	{
		if (!j.is_full() && j.no_not_friends_in_room(students[index_student]))
		{
			j.insert_student(m_dataAccess->get_student(students[index_student]));
			if(j.is_full())
				if (!each_student_have_friend(j)) //if this a final room check that to each student have a friend 
				{
					j.remove_last_student();
					continue;
				}
					
			if (add_student_to_room(rooms, students, index_student + 1))
				return true;
			else
			{
				j.remove_last_student();
			}
		}
		
	}
	return false;
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

bool SortStudents::check_rooms(std::vector<Room> rooms)
{
	for (auto room : rooms)
		if (!each_student_have_friend(room))
			return false;
	return true;
}