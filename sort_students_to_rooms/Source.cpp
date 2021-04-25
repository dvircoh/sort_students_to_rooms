#include <vector>
#include "Input.h"
#include "MemoryAccess.h"




int main()
{

	
	MemoryAccess dataAcess;
	Input input(dataAcess);
	input.input_from_teacher();

	return 0;
}








