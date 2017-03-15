#pragma once
#include <string>
#include <windows.h>
ref class Utility
{
public:
	Utility();
	static std::string getFilePathAsProperString(System::String^ filePath);
	static std::string getCurrentDirectory();
};

