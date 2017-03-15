#include "Utility.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>

using namespace std;

Utility::Utility()
{
}

std::string Utility::getFilePathAsProperString(System::String^ filePath) {
	return msclr::interop::marshal_as<std::string>(filePath);
}

std::string Utility::getCurrentDirectory() {
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}
