#pragma once
#include <vector>
#include <string>
#include "IDataAccess.h"

class SortStudents
{
public:
	SortStudents(IDataAccess& dataAccess) : m_dataAccess(dataAccess) {};
	bool suitable_for_the_room(int room_id, std::string new_student);
	std::vector<Room> matching_students_to_the_room();



private:
	IDataAccess& m_dataAccess;
};

