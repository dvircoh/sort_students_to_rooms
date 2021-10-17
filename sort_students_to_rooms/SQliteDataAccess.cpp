#include "SQliteDataAccess.h"

void SQliteDataAccess::init()
{
    try {
        m_db << "begin;";
        m_db << R"(CREATE TABLE IF NOT EXISTS `Students` (
	                    `StudentName`	TEXT NOT NULL,
	                    PRIMARY KEY(`StudentName`)
                    );)";

        m_db << R"(CREATE TABLE IF NOT EXISTS `Friends` (
	                    `StudentName`	TEXT NOT NULL,
	                    `FriendName`	TEXT NOT NULL,
	                    FOREIGN KEY(StudentName) REFERENCES Students(StudentName)
						FOREIGN KEY(FriendName) REFERENCES Students(StudentName)
                    );)";

		m_db << R"(CREATE TABLE IF NOT EXISTS `NotFriends` (
	                    `StudentName`	TEXT NOT NULL,
	                    `NotFriendName`	TEXT NOT NULL,
	                    FOREIGN KEY(StudentName) REFERENCES Students(StudentName)
						FOREIGN KEY(NotFriendName) REFERENCES Students(StudentName)
                    );)";

		m_db << "CREATE TABLE IF NOT EXISTS Rooms ("
			"roomId INTEGER PRIMERY KEY AUTOINCREMENT NOT NULL,"
			"size INT NOT NULL);";

		m_db << "CREATE TABLE IF NOT EXISTS RoomMembers ("
			"StudentName TEXT NOT NULL,"
			"roomId      INTEGER NOT NULL,"
			"FOREIGN KEY(StudentName) REFERENCES Students(StudentName)"
			"FOREIGN KEY(roomId) REFERENCES Rooms(roomId)"
			"UNIQUE (StudentName));";
			
		m_db << "commit;";

    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void SQliteDataAccess::add_student(std::string& name)
{
	try {
		m_db << "INSERT INTO Students (StudentName) VALUES (?);"
			<< name;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
void SQliteDataAccess::add_friend(std::string& student, std::string& name)
{
	try {
		m_db << "INSERT INTO Friends (StudentName,FriendName) VALUES (?,?);"
			<< student
			<< name;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
void SQliteDataAccess::add_not_friend(std::string& student, std::string& name)
{
	try {
		m_db << "INSERT INTO NotFriends (StudentName,NotFriendName) VALUES (?,?);"
			<< student
			<< name;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
std::vector<std::string> SQliteDataAccess::get_students_names()
{
	std::vector<std::string> students_names;
	m_db << "SELECT StudentName FROM Students;"
		>> [&](std::string studentName) {
		students_names.push_back(studentName);
	};
	return students_names;
}
Student SQliteDataAccess::get_student(const std::string& name)
{
	Student stud(name);

	m_db << "SELECT FriendName FROM Friends WHERE StudentName = (?)"
		<< name
		>> [&](std::string friendName) {
		stud.add_friend(friendName);
	};

	m_db << "SELECT NotFriendName FROM NotFriends WHERE StudentName = (?)"
		<< name
		>> [&](std::string notFriendName) {
		stud.add_not_friend(notFriendName);
	};
	
	return stud;
}


//room method
void SQliteDataAccess::add_room(int room_id, int room_size)
{
	m_db << "INSERT INTO rooms (roomId, size) VALUES (?,?)"
		<< room_id
		<< room_size;
}
std::vector<Room> SQliteDataAccess::get_rooms()
{
	std::vector<Room> rooms;

	return rooms;
}
void SQliteDataAccess::populate_rooms(std::vector<Room>& rooms)
{

}

