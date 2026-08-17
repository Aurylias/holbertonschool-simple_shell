#include "simple_shell.h"

/**
* error_free - If an error occur, print it and free the pointer
*
* @error: The string to print with perror
* @pointer: The pointer to free
*/

void error_free(char *error, char *pointer)
{
	perror(error);
	free(pointer);
}
