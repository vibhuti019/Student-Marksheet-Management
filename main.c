/* 
 *
 * Project On:
 * DataBase Management Using C Language
 *
 * Created By:
 * Vibhuti Singh
 * 
 *
 */

#include <stdio.h>                                                                                    //Standard Input Output

void printfooter()                                                                                    //Prints Header
{
	printf("\n*                                                                          *");
	printf("\n*                                                                          *");
	printf("\n****************************************************************************\n");
}
void printheader()                                                                                     //Prints Footer
{
	printf("\n****************************************************************************");
	printf("\n*                                                                          *");
	printf("\n*                      ABES Engineering College,Ghaziabad                  *");
	printf("\n*                              Year:2019-20                                *");
	printf("\n*                                                                          *");
	printf("\n*                                                                          *");
}
char menu()                                                                                             //Prints Menu
{
	char ch;                                                                     			//What User Opts
	system("color F1");                                                                             //Change Color Of Console
  	system("cls");                                                                                  //Clears The Screen                                                                              
	printheader();                                                                                  //Prints The Header
	printf("\n*                                                                          *");
	printf("\r*                      COLLEGE MARKSHEET DATA MANAGEMENT");
	printf("\n*                                                                          *");
	printf("\n*                                                                          *");
	printf("\n*                           -: CHOOSE AN OPTION :-                         *");
	printf("\n*                                                                          *");
	printf("\n*                               1) ADD ENTRY                               *");
	printf("\n*                               2) MANAGE ENTRIES                          *");
	printf("\n*                               3) EXIT                                    *");
	printf("\n*                                                                          *");
	printf("\n*                                                                          *");
	printf("\r*                             Enter Choice:");	
	scanf("%c",&ch);
	printf("*                                                                          *");
	return ch;                                                                                      //Returns Users Option
}
int main()                                                                                              //MAIN Fuction
{
	printf("*                                                                          *");
	char ch;                                                                                        //What User Opts
	ch = menu();
	if(ch=='1')                                                                                     //IF User Opts Option 1
	{
		printf("\n*                                                                          *");
		printf("\n*                                ADD ENTRY...                              *");
		printfooter();
		system("pause");                                                                        //Halts The Console
		system("addentries");	                                                                //Opens The Program Which Add Entries
	}
	else if(ch=='2')                                                                                //IF User Opts Option 2
	{
		printf("\n*                                                                          *");
		printf("\n*                              MANAGE ENTRY...                             *");
		printfooter();
		system("pause");                                                                        //Halts The Console
		system("print");                                                                        //Program TO Print Entries

	}
	else if(ch=='3')                                                                                //IF User Opts Option 3
	{
		printf("\n*                                                                          *");
		printf("\n*                               EXIT PROGRAM...                            *");
		printfooter();                                                                          //Print Footer
	}
	else                                                                                            //IF Wrong Input
	{
		printf("\n*                                                                          *");
		printf("\n*                          WRONG INPUT                                     *");
		printfooter();                                                                          //Print Footer
		system("pause");                                                                        //Halts The Console
		system("main");                                                                         //Reopens The Same Output Window
	}
}