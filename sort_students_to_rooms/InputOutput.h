#pragma once
#include "IDataAccess.h"
#include <set>


class InputOutput
{
public:
	InputOutput(IDataAccess& dataAccess);
	void input_from_teacher();
	void print_rooms();

private:
	void insert_students();
	void insert_friends();
	void insert_not_friends();
	void insert_room_details();

	IDataAccess& m_dataAccess;
};
