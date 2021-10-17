#pragma once
#include "IDataAccess.h"
#include "sqlite_modern_cpp\sqlite_modern_cpp.h"

class SQliteDataAccess : public IDataAccess
{
public:
	SQliteDataAccess(std::string pathToDb = R"(db_files\students_db.db)") : m_db(pathToDb) 
		{
		init();
		}

	~SQliteDataAccess() = default;

	//student's method
	void add_student(std::string & name) override;
	void add_friend(std::string & student, std::string & name) override;
	void add_not_friend(std::string & student, std::string & name) override;
	std::vector<std::string> get_students_names() override;
	Student get_student(const std::string & name) override;


	//room method
	void add_room(int room_id, int room_size) override;
	std::vector<Room> get_rooms() override;
	void populate_rooms(std::vector<Room>&rooms) override;
private:
	void init();
	sqlite::database m_db;
};

