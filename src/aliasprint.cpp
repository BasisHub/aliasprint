// aliasprint.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc <2){
		std::cout<<"use: aliasprint.exe \\\\server\\printer";
		return 0;
	}

	std::ofstream myfile;
	
	myfile.open (argv[1]);

	for (std::string line; std::getline(std::cin, line);) {
        myfile << line << std::endl;
    }

	myfile.close();
    return 0;
}


