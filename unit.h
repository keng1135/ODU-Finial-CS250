///keng Chu
///OLD DOMINION UNIVERSITY
///CS250 Finial Project
///May 5, 2016


class unit

{
public:

	unit(){ Roster = NULL; }
	unit(string n){ designation = n; Roster = NULL; }
	void ADDsoldier(soldier * n)



	{
		if (Roster == NULL) /// if roster is empty
		{
			Roster = n;
			unitinit = Roster->getinit();
			unitspeed = Roster->getspeed();
			unitatk = Roster->getatk();
			unitdef = Roster->getdef();
			n->setloc(loc[0], loc[1]);

		}

		else
		{

			current = Roster; ///make roster = current
			while (current->getnext() != NULL) ///if roster is not empty
			{
				current = current->getnext();
			}
			current->setnext(n);
			unitatk = unitatk + n->getatk();
			unitdef = unitdef + n->getdef();

			n->setloc(loc[0], loc[1]);
		}

		if (unitspeed > n->getspeed()){ unitspeed = n->getspeed(); }
		if (unitinit < n->getinit()){ unitinit = n->getinit(); }
	}

	void setloc(double x, double y)
	{
		loc[0] = x;
		loc[1] = y;
	}



	void AddNewSoldier(soldier *n)

	{

		new1 = n;  /// What ever input was enter is now in soldier n and n is going to be new1
		bool found = false;

		///checks the soldier id number to see if it goes to the top of the list
		if (new1->getidNumber() < Roster->getidNumber())
		{
			new1->setnext(Roster);
			Roster = new1;
			found = true;
		}
		else///checks if it goes in the middle of the list
		{
			current = Roster;
			previous = current;
			current = current->getnext();

			while (current != NULL)
			{
				if (current->getidNumber() < new1->getidNumber())
				{
					previous = current;
					current = current->getnext();

				}
				else
				{
					previous->setnext(new1);
					new1->setnext(current);
					current = NULL;///its time to quit
					found = true;

				}


			}
			if (!found)///checks if it goes to the very last
			{
				previous->setnext(new1);
			}
			///------------------------
			cout << endl << endl;
			current = Roster;
			while (current != NULL)
			{

				current = current->getnext();
			}
		}

		///Calculate the unit speed and initiative, unit speed is the slowest of the group, unit initiative is the highest of the group
		if (unitspeed > n->getspeed()){ unitspeed = n->getspeed(); }
		if (unitinit < n->getinit()){ unitinit = n->getinit(); }
		unitatk = unitatk + n->getatk();
		unitdef = unitdef + n->getdef();
	}


	void deletesoldier(int target)
	{
		current = Roster;
		previous = NULL;
		while (current != NULL)
		{
			if (current->getidNumber() != target)
			{
				previous = current;
				current = current->getnext();
			}
			else {
				if (previous == NULL)
				{
					Roster = current->getnext();
					unitatk = unitatk - current->getatk();
					unitdef = unitdef - current->getdef();
				}
				else
				{
					previous->setnext(current->getnext());
					current->setnext(NULL);

					unitatk = unitatk - current->getatk();
					unitdef = unitdef - current->getdef();

					delete current;

				}
				break;


			}
		}

	}

	void display()
	{


		///***********************************************************************
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
		WORD saved_attributes;

		/* Save current attributes */
		GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
		saved_attributes = consoleInfo.wAttributes;
		//*************************************************************************


		cout << designation << endl;
		current = Roster;
		unitspeed = 10;
		unitinit = 0;


		while (current != NULL)
		{

			current->display();
			if (unitspeed > current->getspeed())
			{
				unitspeed = current->getspeed();
			}
			if (unitinit < current->getinit())
			{
				unitinit = current->getinit();
			}

			current = current->getnext();

		}
		cout << endl;
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "*********** UNIT STATS ***********" << endl;
		SetConsoleTextAttribute(hConsole, saved_attributes); ///restore Color to normal
		void ResetColor();
		cout << "Unit initiative: " << unitinit << endl;
		cout << "Unit Speed: " << unitspeed << endl;
		cout << "Unit Attack: " << unitatk << endl;
		cout << "Unit Defense: " << unitdef << endl;

		cout << endl << endl;





	}

	void setLoc(double i, double j)
	{
		loc[0] = i;
		loc[1] = j;
	}

	void getLoc(double d[2])
	{
		d[0] = loc[0];
		d[1] = loc[1];
	}

	int getspeed(){ return unitspeed; }




private:
	soldier * Roster;
	soldier * current;
	soldier * previous;
	soldier * new1;
	soldier * delete1;

	string designation;

	int unitspeed = 0, unitinit = 0, unitdef = 0, unitatk = 0;
	double loc[2];


};
