#include "organizer.h"
#include "logger.h"
#include <filesystem>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string folder_path;
	cout << "Enter the folder path to organize: ";
	getline(cin, folder_path);

	organize_files(folder_path);

	return 0;
}


