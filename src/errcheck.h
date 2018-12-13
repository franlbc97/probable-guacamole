#pragma once
#ifndef ERRCHECK_H
#define ERRCHECK_H
#include <fmod_errors.h>
#include <iostream>

static void ERRCHECK(FMOD_RESULT result) {
	if (result != FMOD_OK) {
		std::cout << FMOD_ErrorString(result) << std::endl;
		// printf("FMOD error %d - %s", result, FMOD_ErrorString(result));
		system("PAUSE");
		exit(-1);
	}
}
#endif // !ERRCHECK_H

