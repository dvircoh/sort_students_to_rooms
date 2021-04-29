#pragma once
#include "IDataAccess.h"
#include "Student.h"
#include "Room.h" 
#include <map>

class MemoryAccess : public IDataAccess
{
public:
	~MemoryAccess() = default;

	//student's method
	void add_student(std::string name) override;
	void add_friend(std::string student, std::string name) override;
	void add_not_friend(std::string student, std::string name) override;
	std::vector<std::string> get_students_names() const override;

	//room method
	void add_room(int room_size) override;
	std::vector<Room> get_rooms() override;

private:
	bool student_is_exist(std::string name) const;
	bool friend_is_exist(std::string student, std::string friend_name) const;
	bool not_friend_is_exist(std::string student, std::string not_friend_name) const;

	std::map<std::string, Student> m_students;
	std::vector<Room> m_rooms;
	static int counter_of_students;
};
