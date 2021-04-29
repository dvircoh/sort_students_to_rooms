#include <vector>
#include "InputOutput.h"
#include "MemoryAccess.h"




int main()
{

	
	MemoryAccess dataAcess;
	InputOutput input_output(dataAcess);
	input_output.input_from_teacher();

	//logic

	input_output.print_rooms();

	return 0;
}
