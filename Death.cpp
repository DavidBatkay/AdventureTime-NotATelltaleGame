#include <iostream>
#include <fstream>
#include "Death.h"
#include "EnterFunction.h"
#include "Repeat.h"
#include "Menu.h"
#include <Windows.h>
bool death() {
	pressEnter();
	std::ifstream fin("stats.txt");
	int death0;
	int death1;
	int secret0;
	int start0;
	int wins0;

	fin >> death0;
	fin >> secret0;
	fin >> start0;
	fin >> wins0;
	death1 = death0 + 1;
	std::ofstream fout("stats.txt");
	fout << death1 << " " << secret0 << " " << start0 << " " << wins0 << std::endl;
	int deathani = 20;
	for (int i = 20; i >= 0; i--) {
		Sleep(50);
		system("CLS");
		std::cout << repeat("\n", 25) << R"(                                                                               |   YOUR HP   | )";
		while (true) {
			std::cout << repeat("[]", i);
			switch (i) {
			case 13:
				system("Color 06");
				break;
			case 7:
				system("Color 0D");
				break;
			case 1:
				system("Color 04");
				break;
			}
			break;
		}
	}
	Sleep(1000);
	system("CLS");


	std::cout << repeat("\n", 22) << R"(                                                                                                                                                  
			YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU     DDDDDDDDDDDDD      IIIIIIIIIIEEEEEEEEEEEEEEEEEEEEEEDDDDDDDDDDDDD              !!! 
			Y:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U     D::::::::::::DDD   I::::::::IE::::::::::::::::::::ED::::::::::::DDD          !!:!!
			Y:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U     D:::::::::::::::DD I::::::::IE::::::::::::::::::::ED:::::::::::::::DD        !:::!
			Y::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU     DDD:::::DDDDD:::::DII::::::IIEE::::::EEEEEEEEE::::EDDD:::::DDDDD:::::D       !:::!
			YYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U        D:::::D    D:::::D I::::I    E:::::E       EEEEEE  D:::::D    D:::::D      !:::!
			   Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U        D:::::D     D:::::DI::::I    E:::::E               D:::::D     D:::::D     !:::!
			    Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U        D:::::D     D:::::DI::::I    E::::::EEEEEEEEEE     D:::::D     D:::::D     !:::!
			     Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U        D:::::D     D:::::DI::::I    E:::::::::::::::E     D:::::D     D:::::D     !:::!
			      Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U        D:::::D     D:::::DI::::I    E:::::::::::::::E     D:::::D     D:::::D     !:::!
			       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U        D:::::D     D:::::DI::::I    E::::::EEEEEEEEEE     D:::::D     D:::::D     !:::!
			       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U        D:::::D     D:::::DI::::I    E:::::E               D:::::D     D:::::D     !!:!!
			       Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U        D:::::D    D:::::D I::::I    E:::::E       EEEEEE  D:::::D    D:::::D       !!! 
			       Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U      DDD:::::DDDDD:::::DII::::::IIEE::::::EEEEEEEE:::::EDDD:::::DDDDD:::::D            
			    YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU       D:::::::::::::::DD I::::::::IE::::::::::::::::::::ED:::::::::::::::DD         !!! 
			    Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU         D::::::::::::DDD   I::::::::IE::::::::::::::::::::ED::::::::::::DDD          !!:!!
			    YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU           DDDDDDDDDDDDD      IIIIIIIIIIEEEEEEEEEEEEEEEEEEEEEEDDDDDDDDDDDDD              !!! 
                                                                                                                                                    
	)" << std::endl;
	pressEnter("to go back to the main menu\n");
	system("CLS");
	return true;

};