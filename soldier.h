///keng Chu
///OLD DOMINION UNIVERSITY
///CS250 Finial Project
///May 5, 2016


class soldier



{
public:
	soldier(){ next = NULL; }///constructor
	~soldier(){};
	soldier(int i, int spd, int ini, int d, int a, double x, double y, char typ)
	{
		idNumber = i;
		speed = spd;
		atk = a;
		def = d;
		init = ini;
		type = typ;
		loc[0] = x;
		loc[1] = y;
		next = NULL;
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



		cout << "Soldier ID Number: " << idNumber << endl;
		cout << "Unit Type: ";
		if (type == 'i' | type == 'I'){
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "Infantry" << endl;
		}

		else {
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

			cout << "Calvary" << endl;
		}

		SetConsoleTextAttribute(hConsole, saved_attributes); ///restore Color to normal
		void ResetColor();

		cout << "Initiative: " << init << endl;
		cout << "Speed: " << speed << endl;
		cout << "Attack: " << atk << endl;
		cout << "Defense: " << def << endl;
		cout << "Location X: " << loc[0] << endl;
		cout << "Location Y: " << loc[1] << endl;


		cout << endl;
	}
	void setidNumber(int i){ idNumber = i; }
	void settype(char c){ type = c; }
	void setinit(int v){ init = v; }
	void setspeed(int s){ speed = s; }
	void setatk(int a){ atk = a; }
	void setdef(int d){ def = d; }

	void setnext(soldier*n){ next = n; }

	void setRate(int r){ Rate = r; }

	void setloc(double x, double y)
	{
		loc[0] = x;
		loc[1] = y;
	}
	int getidNumber(){ return idNumber; }
	int gettype(){ return type; }
	int getinit(){ return init; }
	int getspeed(){ return speed; }
	int getatk(){ return atk; }
	int getdef(){ return def; }
	int getRate(){ return Rate; }



	void makenew(int x){ next = new soldier; }
	soldier *getnext(){ return next; }



	void getloc(double L[2])
	{
		L[0] = loc[0];
		L[1] = loc[1];



	}



private:

	int idNumber;
	char type;
	char i;
	char c;
	int speed;
	int init;
	int atk;
	int def;
	double loc[2];

	int Rate;
	int rank;


	soldier * next;

};
