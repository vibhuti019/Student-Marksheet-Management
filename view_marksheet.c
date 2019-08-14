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

#include <stdio.h>                                                    //Standard Input Output
#include <stdlib.h>						      //Standard Library
#include <string.h>						      //String Handling

void print(char file_name[])					      //Prints The Content Of The Selected Entry(Invoked By Previous Program)
{
	char ch;					              //getch() Variable
	FILE *fp;						      //File Pointer
	fp = fopen(file_name, "r");                                   //Read Mode
     	if (fp == NULL)
	{
        	perror("Error while opening the file.\n");
		printf("\n%s",file_name);
       		exit(EXIT_FAILURE);
       	}
        while((ch = fgetc(fp)) != EOF)			               //Prints Content
        	printf("%c", ch);
	fclose(fp);
}
int main(int argv,char *args[])						//MAIN FUNCTION
{
	char file_name[70];						//Path To Selected Entry 
	file_name[0]='\0';
     	strcat(file_name,"..\\Students\\");				//Giving Path To Selected Variables
	strcat(file_name,args[1]);
	system("title MARKSHEET VIEWER");			        //Title To Command Prompt
	system("color E4");                                             //Changes The Color Of Program
	system("cls");						        //Clears The Screen
	print(file_name);						//Prints The Entry
	if(args[2]=='\0')                                               //IF No Argument (Print)
	{
	system("pause");						//Halts The Program
	system("print");                                                //Back To View Entries
	}
	else                                                            //IF Chosen To Print Entries
	{
		system("start print.exe");                              //Back To View Entries
		system("exit");                                         //Exit Console
		exit(0);						//Exit The Program
	}
	return 0;
}