#pragma once
#include "IDataAccess.h"
#include <set>


class Input
{
public:
	Input(IDataAccess& dataAccess);
	void input_from_teacher();

private:
	void insert_students();
	void insert_friends();
	void insert_not_friends();
	IDataAccess& m_dataAccess;
};
