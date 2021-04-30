#pragma once
#include<vector>
#include<string>
#include "Room.h"

class IDataAccess
{
public:
	virtual ~IDataAccess() = default;

	//student's method
	//virtual bool student_is_exist(std::string name) const = 0;
	//virtual bool friend_is_exist(std::string name) const = 0;
	//virtual bool not_friend_is_exist(std::string name) const = 0;
	virtual void add_student(std::string name) = 0;
	virtual void add_friend(std::string student, std::string name) = 0;
	virtual void add_not_friend(std::string student, std::string name) = 0;
	virtual std::vector<std::string> get_students_names() const = 0;

	//room method
	virtual void add_room(int room_id, int room_size) = 0;
	virtual std::vector<Room> get_rooms() = 0;

};



