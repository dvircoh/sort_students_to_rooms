#include <vector>
#include "InputOutput.h"
#include "MemoryAccess.h"
#include "SortStudents.h"
#include "SQliteDataAccess.h"



int main()
{
	SQliteDataAccess data;
	MemoryAccess dataAcess;
	InputOutput input_output(&dataAcess);
	input_output.input_from_teacher();
	SortStudents sort(&dataAcess);
	sort.matching_students_to_the_room();
	input_output.print_rooms();

	return 0;
}
