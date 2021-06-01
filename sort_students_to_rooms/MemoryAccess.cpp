#include "MemoryAccess.h"
#include <iostream>

int MemoryAccess::counter_of_students = 0;

bool MemoryAccess::student_is_exist(std::string& name) const
{
	return m_students.count(name);
}

bool MemoryAccess::friend_is_exist(std::string& student, std::string& friend_name) const
{
	return m_students.find(student)->second.is_friend(friend_name);
}

bool MemoryAccess::not_friend_is_exist(std::string& student, std::string& not_friend_name) const
{
	return m_students.find(student)->second.is_not_friend(not_friend_name);
}

void MemoryAccess::add_student(std::string& name)
{
	if (student_is_exist(name))
	{
		std::cout << "error : The student exists" << std::endl;
	}
	else
	{
		if (name == "end")
			return;
		std::cout << "the name of the student is " << name << " it student number " << ++counter_of_students << std::endl;
		m_students.insert(std::map<std::string, Student>::value_type(name, Student(name)));
	}

}

void MemoryAccess::add_friend(std::string& student, std::string& friend_name)
{
	if (student_is_exist(friend_name) && !friend_is_exist(student ,friend_name) && friend_name != student && friend_name != "end")
		m_students.find(student)->second.add_friend(friend_name);
	else if (friend_name != "end")
		std::cout << "error : The student does not exist or the student alredy exist in the list of the friends" << std::endl;
}

void MemoryAccess::add_not_friend(std::string& student, std::string& not_friend_name)
{

	if (student_is_exist(not_friend_name) && !friend_is_exist(student, not_friend_name) && not_friend_name != student && !not_friend_is_exist(student, not_friend_name) && not_friend_name != "end")
		m_students.find(student)->second.add_not_friend(not_friend_name);
			else if (not_friend_name != "end")
				std::cout << "error : The student does not exist or the student alredy exist in the list of the not_friends" << std::endl;
}

std::vector<std::string> MemoryAccess::get_students_names() const
{
	std::vector<std::string> names;
	for (const auto& i : m_students)
	{
		names.push_back(i.first);
	}
	return names;
}

void MemoryAccess::add_room(int room_id, int room_size)
{
	m_rooms.push_back(Room(room_id, room_size));
}

std::vector<Room> MemoryAccess::get_rooms()
{
	return m_rooms;
}

void MemoryAccess::populate_rooms(std::vector<Room>& rooms)
{
	m_rooms = rooms;
}

Student MemoryAccess::get_student(const std::string& name) 
{
	return m_students.find(name)->second;
}