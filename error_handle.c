#include "shell.h"

/**
 * errors - prints errors
 * @error: error number
 * Return: void
 */

void errors(int error)
{
	char *error_message = NULL;

	switch (error)
	{
		case 1:
			error_message = ERR_FORK;
			break;
		case 2:
			error_message = "Error";
			break;
		case 3:
			error_message = ERR_MALLOC;
			break;
		case 4:
			error_message = ERR_PATH;
			break;
		default:
			return;
	}

	perror(error_message);
}
