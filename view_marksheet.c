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

void print(char file_name[],char args[])			      //Prints The Content Of The Selected Entry(Invoked By Previous Program)
{
	char path[170];						      //Stores The Path Of The File
	const char* temp = getenv("TEMP");			      //Stores Location Temp Folder
	char ch;					              //getch() Variable
	FILE *fp;						      //File Pointer
	FILE *fo;
	snprintf(path, 170 - 1, "%s\\tStu.bin", temp);		      //Appends Path Variable
	fo = fopen(path,"w");					      //Opens A Temporary File
	fp = fopen(file_name, "r");                                   //Read Mode
     	if (fp == NULL||fo==NULL)	
	{
        	perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
       	}
        while((ch = fgetc(fp)) != EOF)			               //Prints Content
	{	
        	printf("%c", ch);
		fprintf(fo,"%c",ch);				       //Prints Content To A Temp FIle
	}
	fclose(fp);
	fclose(fo);
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
	print(file_name,args[2]);					//Prints The Entry
	if(args[2]=='\0')                                               //IF No Argument (Print)
	{
	printf("\r");
	system("echo **************************************************************************** ");
	system("pause");						//Halts The Program
	system("print");                                                //Back To View Entries
	}
	else                                                            //IF Chosen To Print Entries
	{
		
		system("cls");						//Clears The Screen
		system("sprint");                                       //Back To View Entries
		exit(0);						//Exit The Program
	}
	return 0;
}
