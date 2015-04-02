/***************************************************************************/
/*			       				  		   */
/*PROGRAM: Project 5							   */
/*									   */
/*AUTHOR: Tirrell Broadus					           */
/*									   */
/*Date: March 4, 2015						           */
/*									   */
/*REVISIONS: 5							           */
/*									   */
/*PURPOSE: To create and use a class ADT, and review pointers,             */
/*dynamic memory, file i/o, and c-style strings                            */
/*                                                     			   */
/***************************************************************************/

#include<iostream>    //headers
#include<stdlib.h>
#include<fstream>
#include<ctime>
#include"stringLib.h"
#include"symbol.h"
using namespace std;

	// function prototypes
void readsymbolfile(symbol* sptr);   			//function to read  in symbol file						
int randomNum();					//function to generate random number 
void fillRandomly(symbol* sptr, symbol* symset);  	//function to randomly fill slotmachine from symbols file			
void pickASpot(symbol* sptr); 				//function to allow user to choose a stop
void printToScreen(symbol* sptr);			//function to print configuration to screen

		
int main()
{

							
	symbol* symset = new symbol[6];		//dymanicallly allocating symbol array
	symbol* symsetHome = symset;		//pointer to symbol array 
	symbol* slotmachine = new symbol[10];	//dynamically allocating slotmachine array
	symbol* sptr = slotmachine;		//setting pointer to slotmachine array
    	srand(time(NULL));			//so random numbers change with time	
	int selection;				//to use menu					
	bool running = true;			//bool statement			
        readsymbolfile(symset);			//reads symbol file	
	fillRandomly(sptr, symset);		//randomly fills symbols into slotmachine
	
	do{
							//print the menu
		cout << "Computer Science 202" << endl;
		cout << "====================" << endl;
		cout << "1. Put in name of file and read in file" << endl;
		cout << "2. Populate a new slot machine" << endl;
		cout << "3. Print the machine configuration to screen" << endl;
		cout << "4. Pick a stop" << endl;	
		cout << "5. Quit program" << endl;
		

		cin >> selection;
	
		switch(selection)
	     {
		case 1:
			readsymbolfile(symset);		//reads in symbol file, gets name from user			
		     break;

	        case 2: 
			fillRandomly(sptr, symset);	//fills slotmachine randomly	
		    break;
		case 3:
			printToScreen(sptr);		//print the machine configuration to screen
		    break;
		case 4:
		        pickASpot(sptr);		//user picks a rows and column to stop slot machine after generating
		   break;
		case 5:
			running = false;		//stops program
		    break;
	  
		
	      }		
	}while(running);

	delete[] sptr;		//deallocating memory
	sptr = NULL;
	delete[] symset;	//deallocating memory
	symset = NULL;	
	
    return 0;
}

/*************************************************************************/
void readsymbolfile(symbol* sptr)			//reads in symbols file
{
		char* filename= new char[20];
		
	
		cout << "Please type in the filename, hint, it is symbols" << endl;
		cin >> filename;			//read in filename
		ifstream fin;    			//declare variable
		int tempBonus;	   
		fin.open(filename); 			//open file
		char* temp = new char[20];		//dynamically allocate temp array for names
		

		for(int i=0; i<6; i++)			//loops through row of symbol file and reads in name, bonus, 
		{				
			fin >> temp;			//copy name from the temp into 		
			(*sptr).setName(temp);		
			
			fin >> tempBonus;
			(*sptr).setbonus(tempBonus);			//read in bonus
			
			sptr++;	
		}
							//increment pointer
		
		
	
		fin.close();			//close file
		delete[] temp;			//delete memory for temp array
		delete[] filename;		//deallocate memory for filename
		temp = NULL;			//set temp pointer to null
		filename = NULL;	 	//set filename pointer to null
}
	
/*********************************************************************/

void fillRandomly(symbol* sptr, symbol* symset)   //fills slot machine randomly, option 2 on menu
{
	int index;
	symbol* randPtr;		//pointer for random stop				
	
	for(int j=0; j<10; j++)		//looping through symbols
	{
		randPtr = symset;		//setting randPtr to sptr
					//running random
		index = rand() % 6;
		for(int z=0; z<index; z++)
		{
			randPtr++;
		}	
				
		(*sptr).setName( (*randPtr).getName() );
		(*sptr).setbonus( (*randPtr).getbonus() );
		sptr++;
	}
		
}
/******************************************************************************/	
 
void printToScreen(symbol* sptr)		//function that prints machine configuration to screen, option 3 in menu
{
			
	for(int i=0; i<10; i++)		//looping through symbols
	{		
               	(*sptr).printSym();
										
		 sptr++;	
	}
				
} 
	
/*****************************************************************************************/

void pickASpot(symbol* sptr)					//allows user input, option 5 on menu
{								
							//declare variable row
	int stop;
										
	cout << "pick a stop for row between 1-10" << endl;	//asking user to pick a stop for row
	cin >> stop;								
				
	for(int j=0; j<stop-1; j++)			//increment symbols ptr
	{
		sptr++;						
	}							
	(*sptr).printSym();	
	cout << endl;
}	

/********************************************************************************/



	
