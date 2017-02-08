///keng Chu
///OLD DOMINION UNIVERSITY
///CS250 Finial Project
///May 5, 2016



#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <ctime>
#include <fstream>
#include <Windows.h>
using namespace std;
#include "soldier.h"
#include "unit.h"



int main()
{



	fstream foutB;
	fstream foutR;
	fstream fout;


	soldier s;
	s.setidNumber(100);
	s.settype('I');
	s.setspeed(2);
	s.setinit(3);
	s.setatk(1);
	s.setdef(5);
	s.setloc(45.6, 75.3);
	s.display();
	cout << "*************************" << endl;


	soldier * soldier1;
	soldier * newsoldier;
	soldier * removesoldier;



	unit * unit1;
	unit1 = new unit("************* Red Team *************");
	unit1->setloc(89, 45);


	unit * unit2;
	unit2 = new unit("************* Blue Team *************");
	unit2->setloc(60, 28);




	///*****************************************************************************************************
	///Random number generator
	default_random_engine generator;
	uniform_int_distribution<int>distribution(1, 5); ///random number generated for integer
	uniform_real_distribution<double>distributeL(-100.0, 100.0);///random number generated for location
	srand(time(NULL));
	///*****************************************************************************************************








	int i, init, speed, atk, def, t, newIdNumber, removeIdNumber, unitspeed;
	int N = 1;
	double L[2], L2[2], x, y;
	char typ, moving;
	char selection;
	int userInput;
	char a, b, c, d, e, A, B, C, D, E;


	cout << "How many Soldier to display: "; cin >> userInput;
	cout << endl << endl;



	for (int i = 1; i <= userInput; i++)
	{




		init = distribution(generator);
		speed = distribution(generator);
		atk = distribution(generator);
		def = distribution(generator);
		t = distribution(generator);
		if (t > 4){ typ = 'C'; }  ///80% should be infantry and 20% calvary
		else{ typ = 'I'; }
		x = distributeL(generator);
		y = distributeL(generator);


		soldier1 = new soldier(i * 2, speed, init, def, atk, x, y, typ);
		unit1->ADDsoldier(soldier1);


		init = distribution(generator);
		speed = distribution(generator);
		atk = distribution(generator);
		def = distribution(generator);
		t = distribution(generator);
		if (t > 4){ typ = 'C'; }  ///80% should be infantry and 20% calvary
		else{ typ = 'I'; }
		x = distributeL(generator);
		y = distributeL(generator);

		soldier1 = new soldier(i + 200, speed, init, def, atk, x, y, typ);
		unit2->ADDsoldier(soldier1);

	}

	soldier1 = new soldier;


	unit1->display();

	unit2->display();



	cout << "Please enter selection: " << endl;
	cout << "[A] Add Soldier to Red Team: " << endl;
	cout << "[B] Add Soldier to Blue Team: " << endl;
	cout << "[C] Delete Soldier Red Team: " << endl;
	cout << "[D] Delete Soldier Blue Team: " << endl;
	cout << "[E]  Start Simulation" << endl;
	cout << endl;


	cin >> selection;

	cout << endl;



	while (selection == 'a' || selection == 'A' || selection == 'b' || selection == 'B' || selection == 'C' || selection == 'c' || selection == 'D' || selection == 'd')
	{

		switch (selection)
		{
		case 'A' | 'a':
			cout << "Red Team New Soldier ID Number: ";
			cin >> newIdNumber;
			cout << endl;


			init = distribution(generator);
			speed = distribution(generator);
			atk = distribution(generator);
			def = distribution(generator);
			t = distribution(generator);
			if (t > 4){ typ = 'C'; }  ///80% should be infantry and 20% calvary
			else{ typ = 'I'; }
			x = distributeL(generator);
			y = distributeL(generator);

			newsoldier = new soldier(newIdNumber, speed, init, def, atk, x, y, typ);

			unit1->AddNewSoldier(newsoldier);
			unit1->display();
			unit2->display();
			break;

		case 'B' | 'b':
			cout << "Red Team New Soldier ID Number: ";
			cin >> newIdNumber;
			cout << endl;


			init = distribution(generator);
			speed = distribution(generator);
			atk = distribution(generator);
			def = distribution(generator);
			t = distribution(generator);
			if (t > 4){ typ = 'C'; }  ///80% should be infantry and 20% calvary
			else{ typ = 'I'; }
			x = distributeL(generator);
			y = distributeL(generator);

			newsoldier = new soldier(newIdNumber, speed, init, def, atk, x, y, typ);

			unit2->AddNewSoldier(newsoldier);
			unit1->display();
			unit2->display();
			break;

		case 'C' | 'c':

			cout << "Red Team Remove Id: ";
			cin >> removeIdNumber;
			cout << endl;
			unit1->deletesoldier(removeIdNumber);
			unit1->display();
			unit2->display();



			cout << endl;
			break;

		case 'D' | 'd':

			cout << "Blue Team Remove Id: ";
			cin >> removeIdNumber;
			cout << endl;
			unit2->deletesoldier(removeIdNumber);
			unit1->display();
			unit2->display();



			cout << endl;
			break;


		}

		cout << "Please enter selection: " << endl;
		cout << "[A] Add Soldier to Red Team: " << endl;
		cout << "[B] Add Soldier to Blue Team: " << endl;
		cout << "[C] Delete Soldier Red Team: " << endl;
		cout << "[D] Delete Soldier Blue Team: " << endl;
		cout << "[E] Start Simulation" << endl;
		cout << endl;



		cin >> selection;

	}

	if (selection == 'E' || selection == 'e')
	{

		fstream foutB;
		fstream foutR;
		fstream fout;



		int N = 1;


		unit1->getLoc(L);
		unit2->getLoc(L2);
		fout.open("imgcount.txt", ios::out);
		foutB.open("UnitB.dat", ios::out);
		foutR.open("UnitR.dat", ios::out);
		foutB << L[0] << " " << L[1] << endl;
		foutR << L2[0] << " " << L2[1] << endl;
		fout << "N = " << N << endl;
		fout.close();


		system("copy imgcount.txt+command_orig.txt  command.txt");
		system("gnuplot command.txt");

		N++;

		foutB.close();
		foutR.close();



		cout << "\n(A) Move Blue" << endl;
		cout << "(B) Move Red" << endl;
		cout << "(C) Redisplay" << endl;
		cout << "(D) EXIT" << endl;
		cin >> moving;

		while (moving == 'A' || moving == 'a' || moving == 'B' || moving == 'b' || moving == 'C' || moving == 'c')
		{
			if (moving == 'A' || moving == 'a')
			{

				unitspeed = unit1->getspeed();
				L[0] = L[0] - unitspeed;
				L[1] = L[1] - unitspeed;


				fout.open("imgcount.txt", ios::out);
				foutB.open("UnitB.dat", ios::out);
				foutR.open("UnitR.dat", ios::out);
				foutB << L[0] << " " << L[1] << endl;
				foutR << L2[0] << " " << L2[1] << endl;
				fout << "N = " << N << endl;
				fout.close();


				system("copy imgcount.txt+command_orig.txt  command.txt");
				system("gnuplot command.txt");

				N++;

				foutB.close();
				foutR.close();

			}
			if (moving == 'B' || moving == 'b')
			{
				unitspeed = unit2->getspeed();
				L2[0] = L2[0] - unitspeed;
				L2[1] = L2[1] - unitspeed;


				fout.open("imgcount.txt", ios::out);
				foutB.open("UnitB.dat", ios::out);
				foutR.open("UnitR.dat", ios::out);
				foutB << L[0] << " " << L[1] << endl;
				foutR << L2[0] << " " << L2[1] << endl;
				fout << "N = " << N << endl;
				fout.close();


				system("copy imgcount.txt+command_orig.txt  command.txt");
				system("gnuplot command.txt");

				N++;

				foutB.close();
				foutR.close();


			}
			if (moving == 'C' || moving == 'c')
			{

				fout.open("imgcount.txt", ios::out);
				foutB.open("UnitB.dat", ios::out);
				foutR.open("UnitR.dat", ios::out);
				foutB << L[0] << " " << L[1] << endl;
				foutR << L2[0] << " " << L2[1] << endl;
				fout << "N = " << N << endl;
				fout.close();


				system("copy imgcount.txt+command_orig.txt  command.txt");
				system("gnuplot command.txt");

				N++;

				foutB.close();
				foutR.close();

			}
			cout << "\n(A) Move Blue" << endl;
			cout << "(B) Move Red" << endl;
			cout << "(C) Redisplay" << endl;
			cout << "(D) EXIT" << endl;
			cin >> moving;
		}
	}
	else


		cout << "GOODBYE!" << endl << endl;



	system("pause");
	return 0;


};
