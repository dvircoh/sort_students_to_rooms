#pragma once
#include <vector>
#include <string>
#include "IDataAccess.h"

class SortStudents
{
public:
	SortStudents(IDataAccess& dataAccess) : m_dataAccess(dataAccess) {};
	bool add_student_to_room(std::vector<Room>& rooms, const std::vector<std::string>& students, int i);
	void matching_students_to_the_room();
	bool each_student_have_friend(const Room& room) const;



private:
	IDataAccess& m_dataAccess;
};

