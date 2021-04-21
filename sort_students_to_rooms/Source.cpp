#include <vector>
#include "Input.h"





int main()
{

	std::set<Student> students;
	std::vector<Room> rooms;
	
	Input::input_from_teacher(students, rooms);

	return 0;
}








