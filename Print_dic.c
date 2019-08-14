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

#include <stdio.h>                                                                                 //Standard Input Output
#include <string.h>                                                                                //String Handling
#include <dirent.h>                                                                                //Directory Handling


char StudentList[1000][50];                                                                        //List Of Students                      
int  i=0,n=0;                                                                                      //Used Frequently
void printfooter()                                                                                 //Prints Footer
{
	printf("\n*                                                                          *");
	printf("\n*                                                                          *");
	printf("\n****************************************************************************\n");
}
void printheader()                                                                                 //Prints Header
{
	printf("\n****************************************************************************");
	printf("\n*                                                                          *");
	printf("\n*                      ABES Engineering College,Ghaziabad                  *");
	printf("\n*                              Year:2019-20                                *");
	printf("\n*                                                                          *");
	printf("\n*                                                                          *");
}
int USList()                                                                                        //Updates Array Of Students List
{
	DIR *d;                                                                                     //Directory Variable
	struct dirent *dir;                                                                         //Reqd Directory Variable
	d = opendir("..\\Students");                                                                //Directory Where Students List Is Stored
	while((dir = readdir(d)) != NULL)                                                           //Counts The Number Of Entries
	{
    		if ( !strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..") )
    		{
		} 
		else 
		{	
		        n++;
		}
	}
	rewinddir(d);
	while((dir = readdir(d)) != NULL)                                                            //Updates The Array Of Students List 
	{
    		if ( !strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..") )
    		{}
    		else 
		{
        		strcpy(StudentList[i],dir->d_name);
        		i++;
    		}
	}
	rewinddir(d);
}
void printSList()                                                                                    //Prints The Student List
{	
	int j;                                                                                       //Loop Variable
	printheader();                                                                               //Prints Header
        printf("\n*                                                                          *");
	printf("\n*    Index          Student Roll No                Student Name            *");	
	for(i=0;i<n; i++)                                                                            //First Prints 11 Digit Roll No Then Name
	{
		printf("\n*                                                                          *");
		printf("\r*    %d                ",i+1);
		for(j=0;j<11||StudentList[i][j]=='\0';j++)
		{
			printf("%c",StudentList[i][j]);
		}
		printf("                    ");
		for(j=11;StudentList[i][j]!='.'||StudentList[i][j]=='\0';j++)
			printf("%c",StudentList[i][j]);
	}
}
int index_valid(int index)                                                                                 //Prompts When Correct Index Value Is Input
{
	char view_file[140]={'\0'};                                                                        //The File To View
	char ch;											   //Choose Option
	printf("*                                                                          *");
	printf("\n*                                                                          *");
	printf("\n*                                                                          *");
	printf("\r*               Chosen Record No : %d",index);
	printf("\n*                                                                          *");
	printf("\r*          View(V) Or Remove(R) Or Print(P) This Record : ");
	scanf("%*c%c",&ch);
	printf("*                                                                          *");
	if(ch=='V'||ch=='v'||ch=='P'||ch=='p')								   //IF User Opts To Print Or View The Student Entry
	{
		strcpy(view_file,"view \"");                                                               //view (The Program Which Views Student Details)
		strcat(view_file,StudentList[index-1]);
		strcat(view_file," \"");	
		if(ch=='p'||ch=='P')                                                                       //view Can Handle Argument If User Wants To Entry   
		{
		strcat(view_file," P > ..\\\"      ");
		for(i=0;view_file[i]!='>';i++);
		i=i+7;
		for(int j=0;StudentList[index-1][j]!='.';j++,i++)
		{
			view_file[i]=StudentList[index-1][j];
		}
		view_file[i]='\0';
		strcat(view_file,".txt\"");
		}
		printfooter();                                                                             //Prints Footer
		system("pause");                                                                           //Halts The System
		system(view_file);                                                                         //View OR Print The File
		return 0;
	}
	else if(ch=='R' || ch=='r')                                                                        //IF User Opts To Delete Entry
	{
		view_file[0]='\0';
		strcpy(view_file,"del ..\\Students\\\"");
		strcat(view_file,StudentList[index-1]);
		strcat(view_file,"\"");
		system(view_file);
		printf("\n*                                                                          *");
		printf("\r*               Index No %d Successfully Removed",index);
		printfooter();                                                                              //Prints Footer
		system("pause");                                                                            //Halts The Console
		system("print");                                                                            //Prints Updated List (Same Program Reruns)
		return 0;
	}
	else                                                                                                //In Case Of Wrong Input
	{
		printf("*                                                                          *");
		printf("\n*                                                                          *");
		printf("\r*                Wrong Input!!!");
		printfooter();                                                                               //Prints Footer
		system("pause");                                                                             //Halts The Console
		system("print");                                                                             //Prints The Same Output
	}
}
int main()                                                                                                   //MAIN FUNCTION
{
	int index;                                                                                           //Index Choice By User
	char ch;
	system("color AF");                                                                                  //Changes Color Of Console
	system("title STUDENT LIST");                                                                        //Changes Title Of COnsole
	system("cls");                                                                                       //Clears The Console
	USList();                                                                                            //Updates The List Of Students
	printSList();                                                                                        //Prints The List Of Students
	printf("\n*                                                                          *");
	printf("\n*                                                                          *");
	printf("\r*          Enter Index No Of The Student(0:Main Menu):");
	scanf("%d",&index);
	if(index>n&&index>0)                                                                                  //IF Invalid Index Is Input
	{
		printf("*                                                                          *");
		printf("\n*                                                                          *");
		printf("\r*                  Index No Invalid");
		printfooter();                                                                                //Prints Footer
		system("pause");                                                                              //Halts The Console
		system("main");                                                                               //Reprints The Same Output
		return 0;
	}
	else if(index==0)                                                                                     //IF User Opts To Return Back
	{
		printf("*                                                                          *");
		printf("\n*                                                                          *");
		printfooter();                                                                                 //Prints Footer
		system("pause");                                                                               //Halts The Console
		system("main");                                                                                //Takes Back To First Window
	}
	else                                                                                                   //If Valid Index Is Input
	{
		index_valid(index);
	}
}