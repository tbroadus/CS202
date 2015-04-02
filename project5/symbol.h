#include "stringLib.h"
#include <iostream>
using namespace std;

class symbol{
	public:
		char* getName();
		void setName(char*);
		int getbonus();
		void setbonus(int);
		void printSym();
		symbol();
		~symbol();
	private:			
		char* name;
		int bonus;
		bool hasBonus;
};
