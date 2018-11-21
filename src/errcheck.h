#pragma once
#include <fmod.h>
#include <fmod_errors.h>
#include <iostream>

void ERRCHECK(FMOD_RESULT result) {
	if (result != FMOD_OK) {
		std::cout << FMOD_ErrorString(result) << std::endl;
		// printf("FMOD error %d - %s", result, FMOD_ErrorString(result));
		system("PAUSE");
		exit(-1);
	}
}