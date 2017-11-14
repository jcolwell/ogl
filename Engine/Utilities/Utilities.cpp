//==================================================================================
// File: Utilities.cpp
// Desc: 
//==================================================================================

//==================================================================================
// INCLUDES
//==================================================================================
#include "Utilities.h"

#include <fstream>

//==================================================================================
// FUNCTIONS
//==================================================================================
char* Util::ReadFile(const char* path)
{
	std::ifstream file(path, std::ios::in);
	if (!file.is_open())
	{
		return nullptr;
	}

	std::string f;
	f.assign( std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
	file.close();

	char* memblock = new char[f.size()];
	memcpy( memblock, f.c_str(), f.size() );
	memblock[f.size()] = 0;

	return memblock;
}