#include <iostream>                 //0.6 map update
#include <string>
#include <algorithm>
#include <stdlib.h> //strand,rand
#include <time.h> //time
#include <fstream>
#include <Windows.h>
#include <WinUser.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <conio.h>
#include "Art.h"
#include "Repeat.h"
#include "Monika.h"
#include "Map.h"
#include "Menu.h"
#include "EnterFunction.h"
#include "Death.h"
using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds




static void fullscreen()
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}


int ss = 0, x;
string ppb = "PEPPERMINT BUTLER", ice = "ICE KING", bub = "PRINCESS BUBBLEGUM";
static bool game()
{
	string player_name, answer;
	int start;
	char choice;

	x = 1;


	ss++;
	srand(time(NULL));
	int nrx = rand() % 100;
	if (nrx < 10) {
		ifstream fin("stats.txt");

		int death0;
		int secret0;
		int secret1;
		int start0;
		int wins0;

		fin >> death0;
		fin >> secret0;
		fin >> start0;
		fin >> wins0;

		secret1 = secret0 + 1;
		ofstream fout("stats.txt");
		fout << death0 << " " << secret1 << " " << start0 << " " << wins0 << endl;
	}
	int h;
	char options;
	while (x == 1) {
		h = 1;
		//menu1();


		int pointer = 0, hoj = 0, hubba = 1;
		while (hubba == 1)
		{

			system("cls");

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			if (nrx < 10) {

				copyscreen();
				menu2();
			}
			else {
				copyscreen();
				menu1();
				//bigfig font
			}

			for (int i = 0; i < 3; ++i)
			{
				if (i == pointer)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				}
				std::cout << Menu[i] << endl;
			}

			while (true)
			{
				if (GetAsyncKeyState(VK_UP) != 0)
				{
					pointer -= 1;
					if (pointer == -1)
					{
						pointer = 2;
					}
					break;
				}
				else if (GetAsyncKeyState(VK_DOWN) != 0)
				{
					pointer += 1;
					if (pointer == 3)
					{
						pointer = 0;
					}
					break;
				}
				else if (GetAsyncKeyState(VK_RETURN) != 0)
				{
					switch (pointer)
					{
						case 0:
						{
							if (hoj == 1) {
								hubba++;start = 2;
							}
							else {
								hoj++;
							}
						} break;
						case 1:
						{
							hubba++;start = 1;
						} break;
						case 2:
						{
							return false;
						} break;
					}
					break;
				}
			}

			Sleep(150);
		}

		//std::cin.clear();
		//Sleep(250);




		pointer = 0;
		system("CLS");
		switch (start)
		{
		case 1:
			while (h == 1)
			{
				system("CLS");

				int pointerr = 0, haj = 0, hubbah = 1;
				while (hubbah <= 1)
				{
					system("cls");

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					for (int i = 0; i < 6; ++i)
					{
						if (i == pointerr)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
							std::cout << Menuu[i] << endl;
						}
						else
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
							std::cout << Menuu[i] << endl;
						}
					}
					while (true)
					{
						
						if (GetAsyncKeyState(VK_UP) != 0)
						{
							
							pointerr -= 1;
							if (pointerr == -1)
							{
								pointerr = 5;
							}
							break;
						}
						if (GetAsyncKeyState(VK_DOWN) != 0)
						{

							pointerr += 1;
							if (pointerr == 6)
							{
								pointerr = 0;
							}
							break;
						}
						if (GetAsyncKeyState(VK_RETURN) != 0) 
						{
							switch (pointerr)
							{
							case 0:
							{
								hubbah++;
								options = 'v';
							} break;
							case 1:
							{
								hubbah++;
								options = 'u';
							} break;
							case 2:
							{
								hubbah++;
								options = 'y';
							} break;
							case 3:
							{
								hubbah++;
								options = 'c';
							} break;
							case 4:
							{
								hubbah++;
								options = 'a';
							} break;
							case 5:
							{
								options = 'q';
								h++;
								hubbah++;
							} break;
							}
							break;
						}
					}
					Sleep(150);
				}
				switch (options) {
				case 'v':
				{
					system("CLS");
					ifstream fin("stats.txt");

					int death0;
					int secret0;
					int start0;
					int wins0;

					fin >> death0;
					fin >> secret0;
					fin >> start0;
					fin >> wins0;
					string reset;
					std::cout << "Death count: " << death0 << endl;
					std::cout << "Secret menus: " << secret0 << endl;
					std::cout << "Starts: " << start0 << endl;
					std::cout << "Wins: " << wins0 << endl;
					//Sleep(5000);
					std::cout << "Write [DEL] to reset your stats\nPress [ENTER] to go back" << std::endl;
					std::getline(std::cin, reset);
					system("CLS");

					if (reset == "del" || reset == "DEL") {
						system("CLS");
						ifstream fin("stats.txt");
						ofstream fout("stats.txt");
						fout << '0' << " " << '0' << " " << '0' << " " << '0' << endl;

					}
				}break;
				case 'u':
				{
					system("CLS");
					std::ifstream f("updatelog.txt");

					if (f.is_open()) {
						std::cout << f.rdbuf()<<'\n';
					}
					pressEnter("to go back");
					system("CLS");
				}break;
				case 'y':
				{
					system("CLS");
					std::ifstream f("weaponlog.txt");

					if (f.is_open()) {
						std::cout << f.rdbuf()<<'\n';


					}
					pressEnter("to go back");
					system("CLS");
				}break;
				case 'a':
				{
					system("CLS");
					ifstream fin("achievements.lkt");
					int wi, sli;
					fin >> wi;
					fin >> sli;

					ofstream fout("achievements.lkt");
					fout << wi << " " << sli << endl;
					if (wi == 0) {
						std::cout << "1. ?????\n";
					}
					else {
						std::cout << "1. YOU BEAT ICE KING\n";
					}
					if (sli == 0) {
						std::cout << "2. ?????\n";
					}
					else {
						std::cout << "2. YOU LOST WHILE USING A STAND\n";
					}
					pressEnter("to go back");
					system("CLS");
				}break;
				case 'q':
				{
					system("CLS");
					//Sleep(150);
					h++;
				}break;
				case 'c':
				{
					system("CLS");
					credits();
					pressEnter("to go back");
					system("CLS");
				}break;
				}
			}break;

		case 2:
		{
			ifstream fin("stats.txt");

			int death0;
			int secret0;
			int start0;
			int start1;
			int wins0;

			fin >> death0;
			fin >> secret0;
			fin >> start0;
			fin >> wins0;

			start1 = start0 + 1;
			ofstream fout("stats.txt");
			fout << death0 << " " << secret0 << " " << start1 << " " << wins0 << endl;
			system("CLS");
			int wo = 0;
			while (wo < 1) {
				std::cout << R"(

  _                   _  _                         
 | |    ___  __ _  __| |(_) _ _   __ _             
 | |__ / _ \/ _` |/ _` || || ' \ / _` |  
 |____|\___/\__,_|\__,_||_||_||_|\__, | 
                                 |___/             

 )" << endl;
				Sleep(150);
				system("CLS");
				std::cout << R"(

  _                   _  _                         
 | |    ___  __ _  __| |(_) _ _   __ _             
 | |__ / _ \/ _` |/ _` || || ' \ / _` |  _    
 |____|\___/\__,_|\__,_||_||_||_|\__, | (_) 
                                 |___/             

 )" << endl;
				Sleep(150);
				system("CLS");
				std::cout << R"(

  _                   _  _                         
 | |    ___  __ _  __| |(_) _ _   __ _             
 | |__ / _ \/ _` |/ _` || || ' \ / _` |  _   _   
 |____|\___/\__,_|\__,_||_||_||_|\__, | (_) (_) 
                                 |___/             

 )" << endl;
				Sleep(150);
				system("CLS");
				std::cout << R"(

  _                   _  _                         
 | |    ___  __ _  __| |(_) _ _   __ _             
 | |__ / _ \/ _` |/ _` || || ' \ / _` |  _   _   _ 
 |____|\___/\__,_|\__,_||_||_||_|\__, | (_) (_) (_)
                                 |___/             

 )" << endl;
				Sleep(150);
				system("CLS");
				wo++;
			}
			std::cout << R"(
















                                                                                                                                                      
                                                                         d888888o. 8888888 8888888888   .8.          8 888888888o. 8888888 8888888888 
                                                                       .`8888:' `88.     8 8888        .888.         8 8888    `88.      8 8888       
                                                                       8.`8888.   Y8     8 8888       :88888.        8 8888     `88      8 8888       
                                                                       `8.`8888.         8 8888      . `88888.       8 8888     ,88      8 8888       
                                                                        `8.`8888.        8 8888     .8. `88888.      8 8888.   ,88'      8 8888       
                                                                         `8.`8888.       8 8888    .8`8. `88888.     8 888888888P'       8 8888       
                                                                          `8.`8888.      8 8888   .8' `8. `88888.    8 8888`8b           8 8888       
                                                                      8b   `8.`8888.     8 8888  .8'   `8. `88888.   8 8888 `8b.         8 8888       
                                                                      `8b.  ;8.`8888     8 8888 .888888888. `88888.  8 8888   `8b.       8 8888       
                                                                       `Y8888P ,88P'     8 8888.8'       `8. `88888. 8 8888     `88.     8 8888       

)";
			while (wo < 6)
			{
				system("Color 04");
				system("Color 0C");
				wo++;
			}
			system("CLS");
			x++;

		}break;
		}
		break;

	}
	system("Color 0A");
	butler();

	std::cout << ppb << ": Oh, I didn't see you there !\n";
	pressEnter();
	std::cin.ignore();
	
	bool first_time = true;
	while (player_name.empty())
	{
		if (!first_time) {
			butler();
			std::cout << ppb << ": Oh, I didn't see you there !\nPress [ENTER] to continue\n\n" << std::endl;
		}
		std::cout << ppb << ": What's your name, adventurer?\n";
		std::cout << "YOU: ";
		getline(std::cin, player_name);
		system("CLS");
		first_time = false;
	}
	if (player_name == "Diavolo" || player_name == "diavolo") {
		while (true) {
			system("Color 04");
			std::cout << "Kuwa-\n";
			//sleep_for(nanoseconds(10));
			sleep_until(system_clock::now() + seconds(1));
		}
	}

	if (player_name == "Mcnutt" || player_name == "mcnutt") {
		std::cout << ppb << ": oh, you wanna talk to me now?\n";
		std::cout << "YOU GUESSED THATS IT (You ended it all)\n";
		return death();
		//return main();
	}
	std::cout << ppb << ": Welcome to The Land of Ooo, " << player_name << "!" << endl;
	pressEnter();
	std::cout << "???: Help! Someone help me !\n";
	std::cout << player_name << ": Who was that?\n";
	pressEnter();
	system("CLS");
	system("Color 0B");
	kidnap();
	pressEnter();

	while (answer.empty() || (toupper(answer.at(0)) != 'Y' ) && (toupper(answer.at(0)) != 'N' ))
	{
		system("CLS");
		system("Color 0A");
		std::cout << ppb << ": Oh no! Princess Bubblegum! \n";
		std::cout << ice << ": Hahahaha! You will never catch me!\n";
		std::cout << ppb << ": Can you help us rescue Princess Bubblegum? (Y / N)\n";
		getline(std::cin, answer);
	}


	if (toupper(answer.at(0)) == 'N') {
		std::cout << player_name << ": No,not really...\n";
		std::cout << ppb << ": You are a bad person.\n";
		pressEnter();
		std::cout << "*You died from cringe*\n";
		return death();
		//return main();

	}
	else {
		std::cout << player_name << ": Sure,i'll try...\n";
		std::cout << ppb << ": Thank you so much !\n";

	}
	pressEnter();
	std::cout << player_name << ": Yeah whatever,but how do i fight him ?\n";
	std::cout << ppb << ": You need to find a weapon. Search around before going to the Ice Kingdom.\n";
	std::cout << ppb << ": Here, take this map.\n";
	pressEnter();
	int loc = 7;
	int wpn = rand() % 100;
	int DMG;
	int HP;
	while (loc > 6 || loc < -1) {
		system("CLS");
		system("Color 0B");
		map();
		std::cin >> loc;
	}
	system("CLS");
	system("Color 0A");
	switch (loc)
	{
	case -1:
		std::cout << "Searching around Morioh...\n";
		pressEnter();
		std::cout << "You found a STAND ARROW\n";
		pressEnter(" to use it\n");
		if (wpn < 30) {
			std::cout << player_name << ": Yare Yare Daze , I got STAR PLATINUM\n";
			DMG = 180, HP = 999;
			std::cout << "YOUR NEW STATS ARE:\nHP= " << HP << "   DMG= " << DMG << " - " << DMG + 10 << endl;
			pressEnter();
		}
		else {
			if (wpn < 50) {
				std::cout << player_name << ": Dojyaan , I got D4C\n";
				DMG = 150, HP = 500;
				std::cout << "YOUR NEW STATS ARE:\nHP= " << HP << "   DMG= " << DMG << " - " << DMG + 10 << endl;
				pressEnter();
			}
			else {
				if (wpn < 85) {
					std::cout << player_name << ": Ni wa yume ga aru , I got Gold Experience\n";
					DMG = 90, HP = 200;
					std::cout << "YOUR NEW STATS ARE:\nHP= " << HP << "   DMG= " << DMG << " - " << DMG + 10 << endl;
					pressEnter();
				}
				else {
					std::cout << "THE STAND ARROW KILLED YOU\n";
					return death();
					//return main();
				}
			}
		}
		break;
	case 0:
		std::cout << "Searching around The Candy Kingdom...\n";
		pressEnter();
		std::cin.ignore();
		if (wpn > 10) {
			std::cout << player_name << ": WOW! I found a CANDY SWORD\n";
			DMG = 10, HP = 100;
			std::cout << "YOUR NEW STATS ARE:\nHP= " << HP << "   DMG= " << DMG << " - " << DMG + 10 << endl;
			pressEnter();
		}
		else {
			std::cout << "YOU GOT STABBED BY A RANDOM ROGUE!\n";
			return death();
			//return main();
		}
		break;
	case 1:
		marcy();
		std::cout << "MARCELINE: Hey, how can i help you?\n";
		std::cout << player_name << ": I am looking for a weapon to defeat the Ice King. Do you mind if i look around?\n";
		pressEnter();
		std::cin.ignore();
		if (wpn < 25) {
			std::cout << player_name << ": WOW! I found MARCELINE'S AX BASS\n";
			DMG = 35, HP = 100;
			std::cout << "YOUR NEW STATS ARE:\nHP= " << HP << "   DMG= " << DMG << " - " << DMG + 10 << endl;
			pressEnter();
		}
		else {
			if (wpn < 40) {
				std::cout << player_name << ": WOW! I found MARCELINE'S AX BASS and a +20 HP BLOOD POTION\n";
				DMG = 35, HP = 120;
				std::cout << "YOUR NEW STATS ARE:\nHP= " << HP << "   DMG= " << DMG << " - " << DMG + 10 << endl;
				pressEnter();
			}
			else {
				std::cout << "YOU GOT YOUR BLOOD SUCKED OUT BY MARCELINE!\n";
				return death();
				//return main();
			}
		}
		break;
	case 2:
		std::cout << "Searching around The Grass Lands...\n";
		pressEnter();
		std::cin.ignore();
		if (wpn < 20) {
			std::cout << player_name << ": WOW! I found FINN'S DEMON BLOOD SWORD!\n";
			DMG = 47, HP = 130;
			std::cout << "YOUR NEW STATS ARE:\nHP= " << HP << "   DMG= " << DMG << " - " << DMG + 10 << endl;
			pressEnter();
		}
		else {
			if (wpn < 65) {
				std::cout << player_name << ": WOW! I found FINN'S SWORD and FINN'S HAT!\n";
				DMG = 14, HP = 110;
				std::cout << "YOUR NEW STATS ARE:\nHP= " << HP << "   DMG= " << DMG << " - " << DMG + 10 << endl;
				pressEnter();
			}
			else {
				if (wpn < 90) {
					std::cout << player_name << ": WOW! I found JAKE THE MAGICAL DOG!\n";
					std::cout << "JAKE: 'sup\n";
					pressEnter();
					jakethedog();
					std::cout << "JAKE: How can i help you, " << player_name << "?\n";
					std::cout << player_name << " I need you to help me save PRINCESS BUBBLEGUM!\n";
					pressEnter();
					if (wpn > 80) {
						system("CLS");
						jakemonster();
						std::cout << "JAKE: YOU CAME TO THE WRONG PLACE BUDDY!\n";
						pressEnter("to fight!");
						HP = 100;
						DMG = 10;
						int CDMG;
						int JHP = 100;
						int JDMG;
						int Stance;
						int dodgechance;
						int blockchance;
						int chargechance;
						while (JHP > 0 && HP > 0) {
							system("CLS");
							std::cout << "|   YOUR HP   | ";
							int playerhealthmajor = HP / 5;
							int playerhealthminor = HP % 5;
							while (playerhealthmajor > 0) {
								std::cout << "[]";
								playerhealthmajor--;
							}
							while (playerhealthminor > 0) {
								std::cout << ".";
								playerhealthminor--;
							}
							std::cout << " " << HP << endl;
							std::cout << "|   JAKE HP   | ";
							int jakehealthmajor = JHP / 5;
							int jakehealthminor = JHP % 5;
							while (jakehealthmajor > 0) {
								std::cout << "[]";
								jakehealthmajor--;
							}
							while (jakehealthminor > 0) {
								std::cout << ".";
								jakehealthminor--;
							}
							std::cout << " " << JHP << endl;
							int Istance = rand() % 9 + 1;//attack,block
							Stance = 4;
							//std::cout << Istance<<endl;//verify
							CDMG = DMG + rand() % 10;
							JDMG = rand() % 10 + 10;
							if (Istance > 5) {
								std::cout << "*JAKE TAKES A DEFENSIVE STANCE*\n";
								while (Stance < 1 || Stance>2) {
									std::cout << "*CHOOSE A STANCE*\n[1] ATTACK\n[2] CHARGE\n";
									std::cin >> Stance;
									if (Stance == 2) {
										chargechance = rand() % 10 + 1;
										std::cout << "*YOU CHARGE*\n";
										if (chargechance > 5) {
											std::cout << "You charged successfully !\n";
											std::cout << "You deal " << CDMG << " damage" << endl;
											JHP = JHP - CDMG;
										}
										if (chargechance < 6) {
											std::cout << "You missed !\n";
											std::cout << "JAKE deals " << JDMG / 2 << " damage" << endl;
											HP = HP - JDMG / 2;
										}
									}
									if (Stance == 1) {
										std::cout << "*YOU ATTACK*\n";
										blockchance = rand() % 10 + 1;
										if (blockchance < 6) {
											std::cout << "JAKE blocked successfully ! \n";
											std::cout << "You deal " << CDMG / 3 << " damage" << endl;
											JHP = JHP - CDMG / 3;
											std::cout << "JAKE deals " << JDMG / 2 << " damage" << endl;
											HP = HP - JDMG / 2;
										}
										if (blockchance > 5) {
											std::cout << "JAKE failed to block !\n";
											std::cout << "You deal " << CDMG << " damage" << endl;
											JHP = JHP - CDMG;
											std::cout << "JAKE deals " << JDMG / 2 << " damage" << endl;
											HP = HP - JDMG / 2;
										}
									}
								}
							}
							else {
								std::cout << "*JAKE TAKES A OFFENSIVE STANCE*\n";
								while (Stance < 1 || Stance>3) {
									std::cout << "*CHOOSE A STANCE*\n[1] ATTACK\n[2] BLOCK\n[3] DODGE\n";
									std::cin >> Stance;
									if (Stance == 1) {

										std::cout << "*YOU ATTACK*\n";
										std::cout << "You deal " << CDMG << " damage" << endl;
										JHP = JHP - CDMG;
										std::cout << "JAKE deals " << JDMG << " damage" << endl;
										HP = HP - JDMG;
									}
									if (Stance == 2) {

										std::cout << "*YOU BLOCK*\n";
										blockchance = rand() % 10 + 1;
										if (blockchance < 6) {
											std::cout << "You blocked successfully ! \n";
											std::cout << "You deal " << CDMG / 2 << " damage" << endl;
											JHP = JHP - CDMG / 2;
											std::cout << "JAKE deals " << JDMG / 4 << " damage" << endl;
											HP = HP - JDMG / 4;
										}
										if (blockchance > 5) {
											std::cout << "You failed to block !\n";
											std::cout << "You deal " << CDMG / 2 << " damage" << endl;
											JHP = JHP - CDMG / 2;
											std::cout << "JAKE deals " << JDMG << " damage" << endl;
											HP = HP - JDMG;
										}
									}
									if (Stance == 3) {

										std::cout << "*YOU DODGE*\n";
										dodgechance = rand() % 10 + 1;
										if (dodgechance < 5) {
											std::cout << "You dodged successfully !\n";
										}
										if (dodgechance > 4 && dodgechance < 9) {
											std::cout << "You dodged partially !\n";
											std::cout << "JAKE deals " << JDMG / 3 << " damage" << endl;
											HP = HP - JDMG / 3;
										}
										if (dodgechance > 8) {
											std::cout << "You failed to dodge !\n";
											std::cout << "JAKE deals " << JDMG << " damage" << endl;
											HP = HP - JDMG;
										}
									}
								}

							}
							pressEnter();
							std::cin.ignore();
						}

						if (HP < 1) {
							if (loc == -1) {
								ifstream fin("achievements.lkt");
								int wi, sli, slf;
								fin >> wi;
								fin >> sli;

								slf = 1;
								ofstream fout("achievements.lkt");
								fout << wi << " " << slf << endl;
							}
							return death();
							//return main();
						}
						else {
							{
								ifstream fin("stats.txt");
								int t = 1;
								int death0;
								int secret0;
								int start0;
								int wins0;
								int wins1;

								fin >> death0;
								fin >> secret0;
								fin >> start0;
								fin >> wins0;

								wins1 = wins0 + 1;
								ofstream fout("stats.txt");
								fout << death0 << " " << secret0 << " " << start0 << " " << wins1 << endl;
							}
						}

					}
					system("CLS");
					std::cout << "JAKE: Ok. I will help you.\n";
					DMG = 33, HP = 115;
					std::cout << "YOUR NEW STATS ARE:\nHP= " << HP << "   DMG= " << DMG << " - " << DMG + 10 << endl;
					pressEnter();
				}
				else {
					std::cout << "YOU GOT BRUTALLY MURDERED BY BMO!\n";
					return death();
					//return main();
				}
			}
		}
		break;
	case 3:
		std::cout << "Searching around The Mountain Kingdom...\n";
		pressEnter();
		std::cin.ignore();
		if (wpn < 50) {
			std::cout << player_name << ": WOW! I found a RARE ADVENTURER SWORD\n";
			DMG = 15, HP = 100;
			std::cout << "YOUR NEW STATS ARE:\nHP= " << HP << "   DMG= " << DMG << " - " << DMG + 10 << endl;
			pressEnter();
		}
		else {
			if (wpn < 80) {
				std::cout << player_name << ": WOW! I found a COMMON SWORD\n";
				DMG = 10, HP = 100;
				std::cout << "YOUR NEW STATS ARE:\nHP= " << HP << "   DMG= " << DMG << " - " << DMG + 10 << endl;
				pressEnter();
			}
			else {
				std::cout << "YOU FELL OFF A MOUNTAIN!\n";
				return death();
				//return main();
			}
		}
		break;
	case 4:
		std::cout << "Searching around The Fire Kingdom...\n";
		pressEnter();
		std::cin.ignore();
		if (wpn < 20) {
			std::cout << player_name << ": WOW! I found a RARE ADVENTURER SWORD and COMMON ARMOUR\n";
			DMG = 15, HP = 110;
			std::cout << "YOUR NEW STATS ARE:\nHP= " << HP << "   DMG= " << DMG << " - " << DMG + 10 << endl;
			pressEnter();
		}
		else {
			if (wpn < 45) {
				std::cout << player_name << ": WOW! I found THE GLOWING SWORD\n";
				DMG = 50, HP = 100;
				std::cout << "YOUR NEW STATS ARE:\nHP= " << HP << "   DMG= " << DMG << " - " << DMG + 10 << endl;
				pressEnter();
			}
			else {
				std::cout << "YOU GOT COOKED!\n";
				return death();
				//return main();
			}
		}
		break;
	case 5:
		std::cout << "Searching around The Desert Lands...\n";
		pressEnter();
		std::cin.ignore();
		if (wpn < 70) {
			std::cout << player_name << ": WOW! I found a RARE BONE SWORD and BONE ARMOUR\n";
			DMG = 20, HP = 120;
			std::cout << "YOUR NEW STATS ARE:\nHP= " << HP << "   DMG= " << DMG << " - " << DMG + 10 << endl;
			pressEnter();
		}
		else {
			if (wpn < 80) {
				std::cout << player_name << ": WOW! I found *NOTUNG*\n";
				DMG = 56, HP = 100;
				std::cout << "YOUR NEW STATS ARE:\nHP= " << HP << "   DMG= " << DMG << " - " << DMG + 10 << endl;
				pressEnter();
			}
			else {
				std::cout << "YOU GOT KILLED BY A BUTTERFLY WITH A LASER GUN!\n";
				return death();
				//return main();
			}
		}
		break;

	case 6:
		std::cout << "Searching around The Forest of Trees...\n";
		pressEnter();
		std::cin.ignore();
		if (wpn < 40) {
			std::cout << player_name << ": WOW! I found THE GRASS SWORD\n";
			DMG = 30, HP = 105;
			std::cout << "YOUR NEW STATS ARE:\nHP= " << HP << "   DMG= " << DMG << " - " << DMG + 10 << endl;
			pressEnter();
		}
		else {
			std::cout << "YOU GOT LOST IN THE FOREST AND DIED OF HUNGER!\n";
			return death();
			//return main();
		}
		break;
	}
	// end of location selection
	std::cout << player_name << ": Now i can go to the Ice Kingdom to rescue Princess Bubblegum.\n";
	pressEnter("to go to the ICE KINGDOM");
	std::cout << "Going to the Ice Kingdom";
	for (int i = 0; i < 3; i++) {
		Sleep(150);
		std::cout << ".";
	}
	system("Color 0B");
	std::cout << R"(    
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(. %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ %( @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ *%% %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@% %%%* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ %%%%% @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ,%%%%%.*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@@@@@@@@@# %%%%%%% @@@@@@@@/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@@@@@@@@ #%%%%%%% @@@@@@@#  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.,./@@@@@@@,,%%%%%%%%,,@@@@@@ % #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ %( @@@@@@# %%%%%%%%%% @@@@@,,%/ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.,%% &@@@@@ (%%%%%%%%%% (@@@@ %%% &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ %%%,*@@@@*,%%%%%%%%%%%( @@@ (%%%,*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,,%%%% @@@& %%%%%%%%%%%%% @@( %%%%# @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ %%%%% %@@ (%%%%%%%%%%%%%.*@ %%%%%% %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*.%%%%%* @( %%%%%%%%%%%%%%# ,*%%%%%%*.@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ %%%%%%% & %%%%%%%%%%%%%%%%  %%%%%%%% @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/.%%%%%%%. ,%%%%%%%%.. . %%%%%%%%%%%%% #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ %%    /%%%%%%%%%  /(   ,,  #%%%%%%%    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/   ,  ,,  %%%%%%( ,..,,,, , (%%%%* ,   .  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ % * ** ., %%%%%%# ,. ,,,  , (%%%% , .,, . @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/.%  ,      %%%%%%%  ... .,,. (%%%%    ,    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ %%%%,    %%%%%%%%%%%( . , ,%%%%%%%%%/   , &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/.%%%%%%%%%%%%%%%%%%%%%%%/%%%%%%%%%%%%%%%%%*,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #%%%%%%%%%%//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%. &@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@( %%%%%%,   *. @*                         &@##% */#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #%%( ,@ #  *@@@@@@. &&&&&&&&&&&&&&&&&.,@@@@@%. *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#   @@@@@ (&&&&#   &@@ *&&&&&&&&&&&&&( @&.  / @( @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#,   */&@@@@@@@@@./&&&&&&&&&&%,  %&&&&&&&&&&  /%&&&&&,,@/.@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,  (&@@@@@@@@@@@@@@@@@@@@@ (&&&&&&&,  .&&&&&&&&&&&&&&&%    %&&% @@* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&. (@@@@@@@@@@@@@@@@@@@@@@@@@@@# &&&&&&& %@@@ &&&&&&&&&&&&&& &@@% &&&/*@@@ (@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@% #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@& &&&&&%%&&(../ &&&&&&&&&&&&&&&##(%&&&&% @@@@( @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #@@@*    *@@@@@@@@@@@@&@@@@@@@@@& &&&&, @& ((*(&&&& , (&&&&&&&% @@  %&&,  ,@@@@@ *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%  .%@@@@@@@@@@@@@@@@@@@@ /@@@@@@@@#.&* #@@@@@@ ,&&% ,@@@ *&&&&&&,.@@@@@   @@@@@@@@@/ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@% ,@@@@@@@@@@@@@@@@@@@@@@@@# @@@@@@@@@& #@@@@@@@@@@@* &@@@@@@ %&&&&&,,@@@@@@@@@@@@@@@@@@@ ,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/ @@@&(.          .......     @@@@@@@@@@@@@@@@@@@@@(   .@@@@@@@% &&&&&/ @@@@@@@@@@@@@@@@@@@@@      ,(&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&%/.      ......................... ,@@@@@@@@@@@@@@@@@@@@@@( .....   /@@ ,&&&&& &@@@@&. .@@@@@@@@@@@@@  ........    *&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(,     ...................................  &@@@@@@@@@@@@@@@@@@@@@@@# ///// &(  .  #&&&&# *    .(.@@@@@@@@@@@@@& ...............   *&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%   ...........................................  @@@@@@@@@@@@@@@@@@@@@@@@@@/    / .////   %&&&& * .... (@@@@@@@@@@@@@@, ....................   #@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@#   .........................                ........ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@ % /////, **  %&&&&  ... .@@@@@@@@@@@@@@@@ @@@@%/   ................  .%@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@(   ................     /(# ............................ /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ .// .@ //.  &&&&% .. #@@@@@@@@@@@@@@@@@# @@@@@@@@@@#,   .............  ,@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@%  ..............    ,%@@@@@@@@/ ............................ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/  * ** .. %&&&* @@@@@@@@@@@@@@@@@@@@@ &@@@@@@@@@@@@@@@,  .............  *@@@@@@@@@@@@
@@@@@@@@@@@@@&. ..............  (@@@@@@@@@@@@@@@. ........................... ,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@& %&&&.(@@@@@@@@@@@@@@@@@@@@* @@@@@@@@@@@@@@@@@@%   ............  *@@@@@@@@@
@@@@@@@@@@/ ..............  ,@@@@@@@@@@@@@@@@@@@ ............................ (@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ %&&% @@@@@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@(  ...........  (@@@@@@@
@@@@@@@@, ............  .@@@@@@@@@@@@@@@@@@@@@@. ............................ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ,&&# @@@@@@@@@@@@@@@@@@@@ #@@@@@@@@@@@@@@@@@@@@@@@@%  ....... ,&&* &@@@@
@@@@@( (&  ........  /@@@@@@@@@@@@@@@@@@@@@@@@  ............................. @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@# %&% @@@@@@@@@@@@@@@@@@@,.@@@@@@@@@@@@@@@@@@@@@@@@@@@&  ..  %,#.    &@@
@@@( ,  ,%  ....  #@@@@@@@@@@@@@@@@@@@@@@@@@@  .............................. %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ /&# @@@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/ *%%.    &@@@
@@#*/ ,  *&%.  ,@@@@@@@@@@@@@@@@@@@@@@@@@@@& ................................ *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@( &/ @@@@@@@@@@@@@@@@@(.@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#.  #@&@@@
@@@#/&*   /&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@( .................................  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ // @@@@@@@@@@@@@@@@(.@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@. ................................... (@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ . @@@@@@@@@@@@@@@*.@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@. ..................................... &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@. @@@@@@@@@@@@@@ ,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&  ......................................  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@% .........................................  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@# ............................................ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  .............................................. &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#.@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@* ................................................. @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&  .................................................. @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ..................................................  @@@@( @@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(@@ &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@%  ..................................................  @@@% .@@@@@ &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@& @@& @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@  ..................................................        @@@@@   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   /@ &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@.  ........................................................  &&&.  ...  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@/ .....................................................................  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ (@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@&  ..................................................................... /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@. ...................................................................... #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@% ....................................................................... ,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@. ........................................................................  /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ..........................................................................   .&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&  .............................................................................  &@@@@@/#@@@@@@@@@@@@@@@@@@@@@@@@@@ #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@  .............................................................................  #@@@% @@@@@@@@@#@@@@@*.@@@@@@@@ (@@@@@@@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ..............................................................................   .* @@@@@@@@**@@@@*.@@@@@, (@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@* ..................................................................................  #@@@@@@ %@@@,/@(   /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&  .................................................................................. &@@&  .  &   ... &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@. ................................................................................   ......  ..... @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%   .......................................................................................... ,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#   ................................................................................   (@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%,   .....................................................................   ,&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#    .......................................................     /&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%*,           ......................         .,%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                                                                       
)" << endl;
	std::cout << ice << ": You're gonna have to get through me first!\n" << endl;
	pressEnter("to fight!");
	system("CLS");
	system("Color 0A");
	int CDMG;
	int IHP = 200;
	int IDMG;
	int Stance;
	int dodgechance;
	int blockchance;
	int chargechance;
	bool firstTurn = true;
	while (IHP > 0 && HP > 0) {
		if (!firstTurn) {
			pressEnter();
			cin.ignore();
		}
		firstTurn = false;
		system("CLS");
		std::cout << "|   YOUR HP   | ";
		int playerhealthmajor = HP / 5;
		int playerhealthminor = HP % 5;
		/*while (playerhealthmajor > 0) {
			std::cout << "[]";
			playerhealthmajor--;
		}*/
		/*while (playerhealthminor > 0) {
			std::cout << ".";
			playerhealthminor--;
		}*/
		std::cout << repeat("[]", playerhealthmajor);
		std::cout << repeat(".", playerhealthminor);
		std::cout << " " << HP << endl;
		std::cout << "| ICE KING HP | ";
		int icehealthmajor = IHP / 5;
		int icehealthminor = IHP % 5;
		while (icehealthmajor > 0) {
			std::cout << "[]";
			icehealthmajor--;
		}
		while (icehealthminor > 0) {
			std::cout << ".";
			icehealthminor--;
		}
		std::cout << " " << IHP << endl;
		int Istance = rand() % 9 + 1;//attack,block
		Stance = 4;
		//std::cout << Istance<<endl;//verify
		CDMG = DMG + rand() % 10;
		IDMG = rand() % 10 + 15;
		//std::cout << IDMG;//verify
		if (Istance > 5) {
			std::cout << "*" << ice << " TAKES A DEFENSIVE STANCE*\n";
			while (Stance < 1 || Stance>2) {
				std::cout << "*CHOOSE A STANCE*\n[1] ATTACK\n[2] CHARGE\n";
				std::cin >> Stance;
				if (Stance == 2) {
					chargechance = rand() % 10 + 1;
					std::cout << "*YOU CHARGE*\n";
					if (chargechance > 5) {
						std::cout << "You charged successfully !\n";
						std::cout << "You deal " << CDMG << " damage" << endl;
						IHP = IHP - CDMG;
					}
					if (chargechance < 6) {
						std::cout << "You missed !\n";
						std::cout << "ICE KING deals " << IDMG / 2 << " damage" << endl;
						HP = HP - IDMG / 2;
					}
				}
				if (Stance == 1) {

					std::cout << "*YOU ATTACK*\n";
					blockchance = rand() % 10 + 1;
					if (blockchance < 6) {
						std::cout << "ICE KING blocked successfully ! \n";
						std::cout << "You deal " << CDMG / 3 << " damage" << endl;
						IHP = IHP - CDMG / 3;
						std::cout << "ICE KING deals " << IDMG / 2 << " damage" << endl;
						HP = HP - IDMG / 2;
					}
					if (blockchance > 5) {
						std::cout << "ICE KING failed to block !\n";
						std::cout << "You deal " << CDMG << " damage" << endl;
						IHP = IHP - CDMG;
						std::cout << "ICE KING deals " << IDMG / 2 << " damage" << endl;
						HP = HP - IDMG / 2;
					}
				}
			}
		}
		else {
			std::cout << "*" << ice << " TAKES A OFFENSIVE STANCE*\n";
			while (Stance < 1 || Stance>3) {
				std::cout << "*CHOOSE A STANCE*\n[1] ATTACK\n[2] BLOCK\n[3] DODGE\n";
				std::cin >> Stance;
				if (Stance == 1) {

					std::cout << "*YOU ATTACK*\n";
					std::cout << "You deal " << CDMG << " damage" << endl;
					IHP = IHP - CDMG;
					std::cout << "ICE KING deals " << IDMG << " damage" << endl;
					HP = HP - IDMG;
				}
				if (Stance == 2) {

					std::cout << "*YOU BLOCK*\n";
					blockchance = rand() % 10 + 1;
					if (blockchance < 6) {
						std::cout << "You blocked successfully ! \n";
						std::cout << "You deal " << CDMG / 2 << " damage" << endl;
						IHP = IHP - CDMG / 2;
						std::cout << "ICE KING deals " << IDMG / 4 << " damage" << endl;
						HP = HP - IDMG / 4;
					}
					if (blockchance > 5) {
						std::cout << "You failed to block !\n";
						std::cout << "You deal " << CDMG / 2 << " damage" << endl;
						IHP = IHP - CDMG / 2;
						std::cout << "ICE KING deals " << IDMG << " damage" << endl;
						HP = HP - IDMG;
					}
				}
				if (Stance == 3) {

					std::cout << "*YOU DODGE*\n";
					dodgechance = rand() % 10 + 1;
					if (dodgechance < 5) {
						std::cout << "You dodged successfully !\n";
					}
					if (dodgechance > 4 && dodgechance < 9) {
						std::cout << "You dodged partially !\n";
						std::cout << "ICE KING deals " << IDMG / 3 << " damage" << endl;
						HP = HP - IDMG / 3;
					}
					if (dodgechance > 8) {
						std::cout << "You failed to dodge !\n";
						std::cout << "ICE KING deals " << IDMG << " damage" << endl;
						HP = HP - IDMG;
					}
				}
			}

		}


	}
	std::cin.ignore();

	if (HP < 1) {
		if (loc == -1) {
			ifstream fin("achievements.lkt");
			int wi, sli, slf;
			fin >> wi;
			fin >> sli;

			slf = 1;
			ofstream fout("achievements.lkt");
			fout << wi << " " << slf << endl;
		}
		return death();
		//return main();
	}
	else {
		system("CLS");
		system("Color 0B");
		std::cout << R"(########&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#(%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&%%%%%%
########&%(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((/,%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&%%%%%%
########&(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((*##,/////////////////////////////////////////////////////////////////&%%%%%%
#########/////////////////////////////////////////////////////////////////*%%*#((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((#%%%%%%
########/////////////////////////////////////////////////////////////////,#%%#*#################################################################%%%%%%
################################################################%(((((((#*%%%%*/////////%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
########################################################################/#%%%%#*/////((/%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
###################################################################(((((*%%%%%%,((((#((/%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#################################################################((#&&&(#%%%%%%(#%%%***,((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((( .%%%(/(,%%%%%%%%.*,/%%&*,*************************************************************
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%((/////*#%%%%%%%%/(//((/%*(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((,%&.//((*%%%%%%%%%%,((##,%%*############################################################
(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((//%%/(((((%%%%%%%%%%*%%/*%%%*%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#############################################################/%%%%.((.%%%%%%%%%%%#,*#.%%%%*(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%,%%%%((//%%%%%%%%%%%%*#*%%%%%,(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
&&&&&&&&&&&&%/*/#/((,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,#%%%%%,,#%%%%*/,*%%%%#(,%%%%%(,**********************************************************
&&&&&&&&&&&&%/*/#/((*(((/%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&,*%%%%%%,%%%.(#,.*,*%%%*%%%%%%**&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&(((*(,%%&&&&&&&&&&&&&
&&&&&&&&&&&&%/*/#/((*/((/#/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*,*.%%%%%%%%.,.,,*,..,%%%%%%%%,(#,*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%##(((*(,%%&&&&&&&&&&&&&
&&&&&&&&&&&&%/*/#/((*(((/#/*/%&&&&&&&&&&&&&&&&&&&&&&&&&&&(*.,,, &%%%%%%.,.,**,.,,%%%%%%%,(((,..(%%%%%%%%%%%%%%%%%%%%%%%%%%%%#%*/#(((*(,%%&&&&&&&&&&&&&
&&&&&&&&&&&&%/*/#/((*/((/#/*/*(((%%%%%%%%%%%%%%%%%%%%%%%%,.,.,,,,%%%%%%.*.,,*,.,.%%%%%%%,,,,...%&&&&&&&&&&&&&&&&&&&&&&&&%(/*((*/#(((*(,%%&&&&&&&&&&&&&
&&&&&&&&&&&&%/*/#/((*(((/#/*/*((**/*(#####################*.,,.%%%%%%%%.,..,*...,%%%%%%%%%.,..(((((((((((((((((((((#(*(((//*((*/#(((*(,%%&&&&&&&&&&&&&
&&&&&&&&&&&&%/*/#/((*/((/#/*/*((**/*((#*/(((((((((((((((((/(,%%%%%%%%%%%,.,.,,.(%%%%%%%%%%%%(%*//////////////////#(((*(((//*((*/#(((*(,%%&&&&&&&&&&&&&
&&&&&&&&&&&&%/*/#/((*(((/#/*/*((**/*((#*,*#%%%%%%%%%%%%%%/(%%%%%%%%%%%%%%%/.,%%%%%%%%%%%%%%%%/./(((((((((((((((#/((((*(((//*((*/#(((*(,%%&&&&&&&&&&&&&
&&&&&&&&&&&&%/*/#/((*/((/#/*/*((**/*((#*,*#.%%%%%%%%%%%%,@@@@*&%#*,,,*//((#####((/*,.,,(%&*@@@@,/((((((((((((*/#/((((*(((//*((*/#(((*(,%%&&&&&&&&&&&&&
&&&&&&&&&&&&%/*/#/((*(((/#/*/*((**/*((#*,/#.*%%%%%%%%%*&@@@@/&&&&&.**.%&&&&&&&&&/,.@./%&&&&#@@@@//(((((((((/#*/#/((((*(((//*((*/#(((*(,%%&&&&&&&&&&&&&
&&&&&&&&&&&&%/*/#/((*/((/#/*/*((**/*((#*,*#.*#&&&&&%*%@@@@@/&&(.&@%.%&&&&&&&&&&&&&%/,,/,(&&%#@@@@&.%%%%%%%/,#*/#/((((*(((//*((*/#(((*(,%%&&&&&&&&&&&&&
&&&&&&&&&&&&%/*/#/((*(((/#/*/*((**/*((#*,/#.*#%%%%,%@@@@@@*&&&&&&/@@*&&&&&&&&&&&&&%%@%&&&&&&%(@@@@@#/####%/,#*/#/((((*(((//*((*/#(((*(,%%&&&&&&&&&&&&&
&&&&&&&&&&&&%/*/#/((*/((/#/*/*((**/*((#*,*#.*#*&,&@@@@@@@,&&&&&&&&&&/&&&&&&&&&&&&&##&&&&&&&&&&/@@@@@@*%&/%/,#*/#/((((*(((//*((*/#(((*(,%%&&&&&&&&&&&&&
&&&&&&&&&&&&%/*/#/((*(((/#/*/*((**/*((#*.*, .  &@@@@@@@@*&&&&%/,&&&&&&%/*&&&&&&#*%&&&&&.&//&&&&*@@@@@@@..**,#*/#/((((*(((//*((*/#(((*(,%%&&&&&&&&&&&&&
&&&&&&&&&&&&%/*/#/((*/((/#/*/*(/,   ........ &@@@@@@@@@*&(*%@@@@.&&%*@@@,&&&&&&(#@@//&&*@@@@@(*%*@@@@@@@& ........  .,/((//*((*/#(((*(,%%&&&&&&&&&&&&&
&&&&&&&&&&&&%/*/#/((*(((/*  .............. (@@@@@@@@@@@@@@@@@@@@@/@@@@@@,&&&&&&(#@@@@@@@@@@@@@@@@@@@@@@@@@( ..............  /(*/#(((*(,%%&&&&&&&&&&&&&
&&&&&&&&&&&&%/*/#/((*. ............   ....@@@@@@@@@@@@@@@@@@@@@@@@@@&(, .&&&&&&( ./&@@@@@@@@@@@@@@@@@@@@@@@@ .... ............. .(((*(,%%&&&&&&&&&&&&&
&&&&&&&&&&&&%/*/#* .......... .*//#/ .. #@@@@@@@@@@@@@@@@@@@@@@%..&@@/...&&&&&&/..@@@ . .@@@@@@@@@@@@@@@@@@@@/ ... /%/(/, ......... ,#,%%&&&&&&&&&&&&&
&&&&&&&&&&&&%/* ......... *//(/(## ... @@@@@@@@@@@@@@@@@@@@@/#@@ ..  . . %&&&&&*.. ... .. @#/@@@@@@@@@@@@@@@@@% .... %%#(*#(( ........ #%&&&&&&&&&&&&&
&&&&&&&&&&&%/ ........ */**//###/ ....@@@@@@@@@@@@@@@@@@@@*....,..@*..%@(%&&&&&*@@%*,@@ ..,/...@@@@@@@@@@@@@@@@% .... #&&&%((/*% ....... .#%%%%%%%%%%%
%%%%%%%%%%* ....... (&%*/*/////, ....@@@@@@@@@@@@@@@@@@@@,..@,.. @*&@@@@##&&&&&*@@@@@@@%..../...@@@@@@@@@@@@@@@@# .... ,(((((/,&&&. ...... ,%%%%%%%%%%
########( ....... *&&&&&%%%%%%......@@@@@@@@@@@@@@@@@@@@@&.@@@*.&@@@@@@@&(&&&&%*@@@@@@@@@@@%((&@@@@@@@@@@@@@@@@@@/ .... ,(((((%&&&&&........ *%%%%%%%%
%%%%%%%, ....... (#####&&&&&&..... #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/&&&&%/@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@...... ,#####%&&&&&* ....... %&%&%&%
######......... ((((((%%%%%%......,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*&&&&##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@# ..... ,%%%%%#(((((* ....... #%%%%%
((((#......... /(((((%%%%%%...... (@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/%&&&(&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@....... ,/////(#####* ....... /((((
%%%%. ....... *%%%%%(/////,...... &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#(&&&/@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@........ /%%%%%/****/......... ((((
%#%/ ........ ######(((((/ ...... @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*&&&*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@......... #%%%%%*////* ........ (((
((( ........ ./////(((((( ....... &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*&&&*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.......... ###########...........((
##, ........ /(((((%%#%%,........ %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(#&#/@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@& ...........%%%%%*****. ........ %%
/( ......... /////(##### ........ /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&/&(%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/........... /((((/****, ..........#
#* ......... .....///// ...........@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*&/@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@............. (((((((((/ ......... #
# ...........////////// .......... /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(%*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,..............,(((#,,,,, ......... *
# ...........####(****............. #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@( .............. &&&&/,,,, ...........
% ..........,%%%%%%%%& ............. #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.................,((((**** .......... 
. ..........,%%%%****,............... %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.................. ////***/ .......... 
*...........,&%%%#### .................@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@% ................. (###//// .......... 
,..........     *###% ..................@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@....................,###(((( .......... 
/ ......... .,,,*///*.................. @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.................... ***(%%%........... 
&,(,#%%%&%(#/((/****................... @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@ .................. ,,,,///((*%##(#//*%
((((/((*#/(((((,,,,, ..................,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@% *@,...................,,,,####/%/%,&,###
((((/,.(**####(***** ................. (@##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@& @# @...................... ,...*////**,*.((((
%%%%%%(%(%&&&%(((((* ..................  #@ &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@( *@  *..................... ,,,,,*///*%%%*%%%%
%%%%%%(%(%&&&&&&&&&,................... / . @ .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ... ....................... *////////*%%%*%%%%
%%%%%%(%(%%********........................ ...,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(............................ /%%%%%%%/*%%%*%%%%
%%%%%%(%(%%%%%%%%%% ............................/@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@& ..............................*********%%%*%%%%
%%%%%%(%%%%%%%%%%%% .............................*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@% ...............................//////////(#*%%%%
%%%%%############## ..............................,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@( ............................... *****************
&&&&&&&&&&&&&&&&&&& ............................... %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,................................. (((((((((((((((((
................... .................................,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@( .................................. .................
///////////////////................................... (@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@% .................................... ,,,,,,,,,,,,,,,,,
###################,.................................... &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@( ...................................... .................
%%%%%%%%%%%%%%%%%%%,......................................,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,.........................................                  
///////////////////*........................................@@@@@@@@@@@@@@@@@@@@@@@@@@@& ...........................................                  
%%%%%%%%%%%%%%%%%%%(....................................... @@@@@@@@@@@@@@@@@@@@@%..@@ ............................................. ,,,,,,,,,,,,,,,,,
,,,,,,,,,,,,,,,,,,,, .......................................@@@((@@@@/ &@@( ##. .. &................................................ (((((((((((((((((
%%%%%%%%%%%%%%%%%%%% .........................................,@@&.. (&, ........................................................... .................
%%%%%%%%%%%%%%%%%%%% ........................................   ....................................................................,&&&&&&&&&&&&&&&&&
((((((((((((((((((((/.............................................................................................................. /#################
%%%%%%%%%%%%%%%%%%%%%/ ........................................................................................................... /##################
%%%%%%%%%%%%%%%%%%%%%/(/(,  .................................................................................................  *,/*%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%/(/(*(*(**,   ...................................................................................   ,/(//,#,/*%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%/(/(*(*(*/((**/***,..    .............................................................    ..,*/((/(/(((//,#,/*%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%/(/(*(*(*/((**/****,/#(.(/,#,#,#**/.,,. .                                 . .,,/*/(,%/.,%(/**///(/(/((///,#,/*%%%%%%%%%%%%%%%%%%%
)" << endl;
		std::cout << ice << ": Ok,Ok ! I give up . You win!\n";
		pressEnter(); system("CLS"); system("Color 0A");
		std::cout << "PRINCESS BUBBLEGUM: Thank you for saving me!\n";
		std::cout << player_name << ": Oh it was nothing really...\n";

		pressEnter();
		system("CLS");
		system("Color 04");
		std::cout << R"(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/&&#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%&&&#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&*,..  .  . .,/%,(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%/   .                    .  .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(&&&&%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#                                    /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/&&&&&(@@@@@@@@@#/(###%%%&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&..                                     .. .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#&&&&&&&*&/###################/&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@* . .                               .           #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#&&&&&&&&#/#######################/&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@(.                                                  ,*(/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*&@@@@,@(&&&&&&&&&&&&%/########################/@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@&                                     .             *@@@@@@@*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*@@@@@@@@(&&&&&&&&&&&&&&&&&&&(/#####################(@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@,                                              &@@@. @@@@@@@@&&@/**#&&@@@@@@@@@@@@@@@@@@&%#***@@@@@@@@&#((/###%%%&&&&&&&&&&&&&&&&&((################(@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@. .                                            #@@@@@@/@@@&*&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&###################(#//#%&&&&&&&&&&%((#########(@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@.                                             ,@@@@@@@@@/@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(###############################(#%&&&&&&&&&%#((#&@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@(        .                         .         .@@@@@@@@@@@@#@@@@@@@@@@@@@@#*/#&&&&&&&%((*,/#@@@@@@@@@@@@@(%#*/((#################################((&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@.                                           %@@@@@@@@@@@@@@#@@@@@@@(/@&&&&&&&&&&&&&&&&&&&@%,.,&(,&@@@@@@*@@@@@@@@@@@@@@#/#############################&//#@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@                                           &@@@@@@@@@@@@@@@,@@@#/&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#(@@@#@@.@@@@@@@@@@@@@@@@@&#/#########################/@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@#                                          @@@@@@@@@@@@@@@@@*@#%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&/%@@@@@@@@@@@@@@@@@@@@@@@&*########################%&@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@%                                         @@@@@@@@(,*/ @@@@@*,&&&&&&&, /&&&@&&&&&&&&&&&&&&&&#  %&&&&&&&@/@@@@#/#%/*@@@@@@@@@@@@@@(########################%%@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@%                                        *@@@@@@@@@@@@@@@@@%,&@&&&&&&&%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%@@@@@@@@@@@@@@@@@@@@@@@@*##########################@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@                                        #@@@@@@@@@@@@@@@@@/##&&&&&&&&&&&#&&&&&&&&&&&&&&&&&&&&&&&&&&&&@&&#@@@@@@@@@@@@@@@@@@@@@@@##########################%@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@                                        #@@@@@@@@@@@@@@@@@@@/&&&&&&&&&&&&&*&&&&&@&&&&&&&&&&&&&&&&&&&&/@@@@@@@@@@@@@@@@@@@@@@@@@@(#########################%&@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@                                        %@@@@@@@@@@@@@@@@@@@*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#@@@@@@@@@@@@@@@@@@@@@@@@@*##########################/@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@(                                       &@@@@@@@@@@@@@@#&@@%@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@&&%@%(@@@@@@@@@@@@@@@@@@@@/###########################&@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@,                                       @@@@@@@@@@@@((/@@@@@,&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%@@@@@(/#@@@@@@@@@@@@@@@@@##############(#############/@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@                                       .@@@@@@@@..&&&&/@@@@@@@&,&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&/#@@@@@@@@(&&#,@@@@@@@@@@@@@&(##############(#############%@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@,                                         #(.&@@@@,&&&&,#@@@@@@@@@@(*%&&&&&&&&&&&&&&&&&&&&&@&&&#*%@@@@@@@@@@@@(&&&*@@&*#@@@@@@@@&(###############/############*@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@                                              *@@@@ #,(%,((((*/@@@@@@@@@@@@@@(/*,*,,,**%&#&@@@@@@@@@@@&//*,*(((,(((,@@/####(&@@@@@############(####/###########%(@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@*                             /@@@@,           .@@@@*((((*/(((((((((((#*,,../*((((..*./(*,..,*/,#(((((((((((((((.(((*@@/#####/@@@@%###########*###(###/##########%&@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@*                            @@@@@@@@@%          @@@@,((((*((((((((((((((((((((((((((((((((((((((((((((((((((((((*((((@@*######,@@@*##########/#(/(///////##########@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@                             @@@@@@@@@@@*         /@@.,((((,((((((((((((((((((((((((((((((((((((((((((((((((((((((/((,@@@(######,*.*/#########*//////////////(#######*@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@&                             @@@@@@@@@@@@@         .@@,/#(((*(((((((((((((((((((((((((((((((((((((((((//(%,*/(//(((/(*(*@@(#####,****/#######*/////////////////*#######(@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@,  %                          .@@@@@@@@@@@@@          @@.(*/((*((((((((,,,*,,**..*(((((((((((((((*/&&&&&&&&&&&&&&&&&&(*(((@&#####**,***########////////////////////#######%@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@#                           /,@@@(@@@@@@@@          @@*(((*((((*&&&&&&&&&&&&&&&@&&&&&*((((,%&&&&&&&&&&&&&&&&&&&&&&&&(.(*@&#####,*.***#######*///////////////////((########@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@*                            */(*(*@@@@@@@@          @@&(((((&&&&@&&&&&&&&&&&&&&&&&&&&&@&&&((&&&&&&/*,((((((((/*(%&&&/.//@#######//**/#######*////////////////////########(@@@@@@@@@@@@@@
@@@@@@@@@@@@@@.                             */////@@@@@@@&          @@@,(/@.&@&&&&&&&(//((((/*,&&&&&&&&&&&&&&&&&%**(((((((((((((,((/((*@@(#####,////(########///////////////////*#########/@@@@@@@@@@@@@
@@@@@@@@@@@@@(                              *////*@@@@@@@@          @@@@/(*&(%&&(*((((((((((/*&@@&&&%*/&&&&&&&&&&&&&&&/,/(((((/%&&,/((#@@(####(////(##########*////////////////(###########/@@@@@@@@@@@@
@@@@@@@@@@@@&                               /(///*@@@@@@@@         ,@@@@@#((((/,&#((((/,%&&&&&&&&&&%,((((((**&&&&&&&&&&&&&&&&&&&&&&&&/@@@(####*////*############(///////////*###############%@@@@@@@@@@@
@@@@@@@@@@@@.                                //(/,@@@@@@@@         /@@@@@@@./&&@&&&&&&&&&&&&&&&&/(((((((((((((((,*&&&&&&&&&&&&&&&&@&&@@@@(###(//////###########*/////////////(###############@@@@@@@@@@@
@@@@@@@@@@@&                               /. ////@@@@@@@@      .  &@@@@@@@@#*(&&&&&&&&&&&&%*((((((((((((((((((((((((((*(%&@@@%#**(/&@@@@/###/////*###########///////**//////(###############/@@@@@@@@@@
@@@@@@@@@@@                                ///(/(*@@@@@@@@     .. %@@@@@@@@@&/((*%@&&@&,(((((((((((((((((((((((((((((((((((((((((((*&@@@@(####/////##############/&@@@@@&&%###################&@@@@@@@@@
@@@@@@@@@@@                                //(///,@@@@@@@@     * #@@@@@@@@@@&(((((((((((((((((((((((((((((((((((((((((((((((((((((((&@@@@(######*/(##############(&@@@@@@(####################/@@@@@@@@@
@@@@@@@@@@#                                ///,.,,@@@@@@@&     @@@@@@@@@@@@@@/(((((((((((((((((((((((((((((((((((((((((((((((((((((*@@@@@(#######(################(@@@@@@(####################(@@@@@@@@@
@@@@@@@@@@&                                 ///. .@@@@@@@&    .@@@@@@@@@@@@@@.(((((((((((((((((((((((((((((((((((((((((((((((((((((/&@@@@(########################&@@@@@@(#####################/@@@@@@@@
@@@@@@@@@@#                                 *////*@@@@@@@&(   #@@@@@@@@@@@@@@%(((((((((((((((((((((((((((((((((((((((((((((((((((((/&@@@@(######/################*@@@@@@@*#####################(@@@@@@@@
@@@@@@@@@@*                                  /////%@@@@@@@(   #@@@@@@@@@@@@@@@/((((((((((((((((((((((((((((((((((((((((((((((((((((*@@@@@%######(################.@@@@@@@*######################@@@@@@@@
@@@@@@@@@@#                                  /////&@@@@@@@*@#  @@@@@@@@@@@@@@@*((((((((((((((((((((((((((((((((((((((((((((((((((((*@@@@@%#######################/@@@@@@@(#####################(@@@@@@@@
@@@@@@@@@@@  @/                              /////.@@@@@@@(@@@@@@@@@@@@@@@@@@@*,/((((((((((((((((((((((((((((((((((((((((((((((/((/@@@@@@@(#####################*&@@@@@@%#######################(@@@@@@@
@@@@@@@@@@@@@@@                              /////(%@@@@@@#@@@@@@@@@@@@@@@@@@@%******** *(((/(/(((#((((*(/*(.,,. ,,***************.@@@@@@@(####(################*@@@@@@@*######################%(@@@@@@@
@@@@@@@@@@@@@@@                              //////*@@@@@@@(@@@@@@@@@@@@@@@@@@@***************************************************%@@@@@@@@(###%###############%#@@@@@@@*######################%&@@@@@@@)" << endl;




		pressEnter();

		int winani = 5;
		while (winani > 0) {
			std::cout << ".";
			system("CLS");
			std::cout << repeat(R"(

)", winani);
			int hah = 0;

			std::cout << R"(
















                                                                                                                                                                                                                                   
                              YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU     WWWWWWWW                           WWWWWWWWIIIIIIIIIINNNNNNNN        NNNNNNNN      !!! 
                              Y:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN:::::::N       N::::::N     !!:!!
                              Y:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN::::::::N      N::::::N     !:::!
                              Y::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU     W::::::W                           W::::::WII::::::IIN:::::::::N     N::::::N     !:::!
                              YYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U       W:::::W           WWWWW           W:::::W   I::::I  N::::::::::N    N::::::N     !:::!
                                 Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U        W:::::W         W:::::W         W:::::W    I::::I  N:::::::::::N   N::::::N     !:::!
                                  Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U         W:::::W       W:::::::W       W:::::W     I::::I  N:::::::N::::N  N::::::N     !:::!
                                   Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U          W:::::W     W:::::::::W     W:::::W      I::::I  N::::::N N::::N N::::::N     !:::!
                                    Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U           W:::::W   W:::::W:::::W   W:::::W       I::::I  N::::::N  N::::N:::::::N     !:::!
                                     Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U            W:::::W W:::::W W:::::W W:::::W        I::::I  N::::::N   N:::::::::::N     !:::!
                                     Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U             W:::::W:::::W   W:::::W:::::W         I::::I  N::::::N    N::::::::::N     !!:!!
                                     Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U              W:::::::::W     W:::::::::W          I::::I  N::::::N     N:::::::::N      !!! 
                                     Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U               W:::::::W       W:::::::W         II::::::IIN::::::N      N::::::::N          
                                  YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU                 W:::::W         W:::::W          I::::::::IN::::::N       N:::::::N      !!! 
                                  Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU                    W:::W           W:::W           I::::::::IN::::::N        N::::::N     !!:!!
                                  YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU                       WWW             WWW            IIIIIIIIIINNNNNNNN         NNNNNNN      !!! 
                                                                                                                                                                                       
                                                                                                                                                                                       
                                                                                                                                                                                       
                                                                                                                                                                                       
                                                                                                                                                                                       
                                                                                                                                                                                       
                                                                                                                                                                                       

    
)" << endl;
			winani--;
			while (hah < 2)
			{
				system("Color 04");
				system("Color 0C");
				hah++;
			}
		}
		Sleep(200);
		int hah = 0;



		{
			ifstream fin("stats.txt");
			int t = 1;
			int death0;
			int secret0;
			int start0;
			int wins0;
			int wins1;

			fin >> death0;
			fin >> secret0;
			fin >> start0;
			fin >> wins0;

			wins1 = wins0 + 1;
			ofstream fout("stats.txt");
			fout << death0 << " " << secret0 << " " << start0 << " " << wins1 << endl;
		}

		{
			ifstream fin("achievements.lkt");
			int wi, wf, sli;
			fin >> wi;
			fin >> sli;

			wf = 1;
			ofstream fout("achievements.lkt");
			fout << wf << " " << sli << endl;
		}
		system("CLS");
		system("Color 0C");
		//Sleep(1000);
		system("CLS");
		////return main();
	}



	std::cout << endl;
	return true;
}

int main()
{
	fullscreen();
	system("Color 0A");
	
	system("CLS");
	srand(time(NULL));
	int nrm = rand() % 100;
	if (ss == 0 && nrm == 99) {
		system("Color E0");
		kernel();
		return 0;
	}
	gameLoop = true;
	while (gameLoop) {
		gameLoop = game();
	}
	
}

