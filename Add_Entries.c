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

#include <stdio.h>                                                                                //Standard Input Output                                   
#include <string.h>                                                                               //String Functions

char StudentList[1000][50];    									  //List Of Students                                                                             
int avg=0;											  //Value Of Average
int total=0;											  //Value Of Total Marks                                                                                               
int i=0,n=0; 											  //Frequently Used Variables                 
int marks[5];											  //Marks In Each Subject
char grade[5];                                                                                    //Grade In Each Subject                                                                    
char name[20],rfile[70];                                                                          //Name Of Files
char rollno[20],fatname[20],motname[20];                                                          //Frequently Used
void printheader()                                                                                //Frequently Printed                                                       
{  
	printf("\n****************************************************************************");
	printf("\n*                                                                          *");
	printf("\n*                      ABES Engineering College,Ghaziabad                  *");
	printf("\n*                              Year:2019-20                                *");
	printf("\n*                                                                          *");
	printf("\n*                                                                          *");
}
int avrage()											    //Calculates Average
{
	for(int i=0;i<5;i++)
	{
		total=marks[i]+total;
	}	
	return (total/5);
}
void printfooter()                                                                                  //Frequently Printed
{
	printf("\n*                                                                          *");
	printf("\n*                                                                          *");
	printf("\n****************************************************************************\n");
}
void Ugrade()                                                                                        //Updates The Grade List Acc To Marks
{
	for(i=0;i<5;i++)
	{
	if(marks[i]>90)
		grade[i]='A';
	else if(marks[i]<=90 && marks[i]>80)
		grade[i]='B';
	else if(marks[i]<=80 && marks[i]>70)
		grade[i]='C';
	else if(marks[i]<=70 && marks[i]>60)
		grade[i]='D';
	else if(marks[i]<=60 && marks[i]>50)
		grade[i]='E';
	else if(marks[i]<=50)
		grade[i]='F';
	}
}
void inputs()                                                                                     //Takes Input
{
	system("cls");                                                                            //Clears The Console
	printheader();                                                                            //Prints Header
	printf("\n*                                                                          *");
	printf("\r*      Enter Student 11 Digit Roll No:");
	gets(rollno);
	printf("*                                                                          *");
	printf("\r*      Enter Student name:");
	gets(name);
	printf("*                                                                          *");
	printf("\r*      Enter Student's Father name:");
	gets(fatname);
	printf("*                                                                          *");
	printf("\r*      Enter Student's Mother name:");
	gets(motname);
	for(i=0;i<5;i++)                                                                           //Marks In Each Subject
	{
		printf("*                                                                          *");
		printf("\r*      Enter Marks Of Subject (Out Of 100)%d:",i+1);
		scanf("%d",&marks[i]);
	}
	printf("*                                                                          *");
	printfooter();                                                                              //Prints Footer
	printf("");

}
void output()                                                                                       //Prints Output
{
	system("cls");                                                                              //Clears The Console
	system("color E4");                                                                         //Changes The Color Of Console
	printheader();                                                                              //Print Header
	avg=avrage();										    //Calculate Average
	total=avg*5;
	printf("\r*                           MarkSheet 2019-2020                            *");
	printf("\n*                                                                          *");
	printf("\n*                                                                          *");
	printf("\r*             Student's Roll No:");
	puts(rollno);
	printf("*                                                                          *");
	printf("\r*             Student's Name:");
	puts(name);
	printf("*                                                                          *");
	printf("\r*             Father's Name:");
	puts(fatname);
	printf("*                                                                          *");
	printf("\r*             Mother's Name:");
	puts(motname);
	printf("*                                                                          *");
	printf("\n*   Subjects:    Sub1       Sub2         Sub3       Sub4        Sub5       *");
	printf("\n*                                                                          *");
	printf("\r*   Marks:       %d         %d           %d         %d          %d ",marks[0],marks[1],marks[2],marks[3],marks[4]);
	printf("\n*                                                                          *");
	printf("\r*   Grade:       %c          %c            %c          %c           %c ",grade[0],grade[1],grade[2],grade[3],grade[4]);
	printf("\n*                                                                          *");
	printf("\n*                                                                          *");
	printf("\r*             Total Marks Obtained :%d/500",total);
	printf("\n*                                                                          *");
	printf("\r*             Percent :%d%%",avg);
	printf("\n*                                                                          *");
	printf("\r*             Status:");
	if(avg>50)
	{
		printf("PASS");
	}
	else
	{
		printf("FAIL");
	}
		
		
}
void printfile()                                                                                      //Saves The Entry 
{
	FILE* result;                                                                                 //File Pointer
	strcat(rfile,"..\\Students\\");						                      //Location To Save Entry
	strcat(rfile,rollno);                                                                         //Creates FileName
	strcat(rfile,name);									      //Creates FileName
	strcat(rfile,".bin");									      //Adds Extension .bin
	result=fopen(rfile,"w");                                                                      //Opens File
	fprintf(result,"****************************************************************************");
	fprintf(result,"\n*                                                                          *");
	fprintf(result,"\n*                      ABES Engineering College,Ghaziabad                  *");
	fprintf(result,"\n*                              Year:2019-20                                *");
	fprintf(result,"\n*                                                                          *");
	fprintf(result,"\n*                           MarkSheet 2019-2020                            *");
	fprintf(result,"\n*                                                                          *");
	fprintf(result,"\n*                                                                          *%c",'\r');
	fprintf(result,"*             Student's Roll No:%s\n",rollno);
	fprintf(result,"*                                                                          *%c",'\r');
	fprintf(result,"*             Student's Name:%s\n",name);
	fprintf(result,"*                                                                          *%c",'\r');
	fprintf(result,"*             Father's Name:%s\n",fatname);
	fprintf(result,"*                                                                          *%c",'\r');
	fprintf(result,"*             Mother's Name:%s\n",motname);
	fprintf(result,"*                                                                          *");
	fprintf(result,"\n*   Subjects:    Sub1       Sub2         Sub3       Sub4        Sub5       *");
	fprintf(result,"\n*                                                                          *%c",'\r');
	fprintf(result,"*   Marks:       %d         %d           %d         %d          %d ",marks[0],marks[1],marks[2],marks[3],marks[4]);
	fprintf(result,"\n*                                                                          *%c",'\r');
	fprintf(result,"*   Grade:       %c          %c            %c          %c           %c ",grade[0],grade[1],grade[2],grade[3],grade[4]);
	fprintf(result,"\n*                                                                          *");
	fprintf(result,"\n*                                                                          *%c",'\r');
	fprintf(result,"*             Total Marks Obtained :%d/500",total);
	fprintf(result,"\n*                                                                          *%c",'\r');
	fprintf(result,"*             Percent :%d%%",avg);
	fprintf(result,"\n*                                                                          *%c",'\r');
	fprintf(result,"*             Status:");
	if(avg>50)
	{
		fprintf(result,"PASS");
	}
	else
	{
		fprintf(result,"FAIL");
	}
	fprintf(result,"\n*                                                                          *");
	fprintf(result,"\n*                                                                          *");
	fprintf(result,"\n****************************************************************************\n");
}
void ConInitialization()                                                                               //Initializes The Console
{
	system("md ../Students");					                               //Creates Directory To Store Data
	system("cls");                                                                                 //Clears The Console
	system("title ADD DETAILS");                                                                   //Title Change Of Prompt
	system("color 4B");	                                                                       //Color Change Of Console
}
int main()                                                                                             //MAIN Function
{
	char ch;                                                                                       //Check The Input
	ConInitialization();                                                                           //Decorate The Console	
	inputs();                                                                                      //Take Inputs                      
	Ugrade();                                                                                      //Update Grade Variable
	output();                                                                                      //Prints Output
	printf("\n*                                                                          *");	
	printf("\n*                                                                          *");	
	printf("\n*                                                                          *");	
	printf("\r*            Do You Wish To Save The Data? Yes(Y) No(N) : ");
	scanf("%*c%c",&ch);
	if(ch=='Y'||ch=='y')                                                                            //Asks If User Wants To Save Entry                                            
	{
			printfile();                                                                    //Prints Content To File
			printf("*                                                                          *");	
			printf("\n*                                                                          *");	
			printf("\n*                                                                          *");	
			printf("\r*                   All Entries Have Been Saved ");
	}
	else if(ch=='N'||ch=='n')                                                                       //Else IF User Opts No
	{
			printf("*                                                                          *");	
			printf("\n*                                                                          *");	
			printf("\n*                                                                          *");	
			printf("\r*                         Entries Not Saved ");
	}
	else                                                                                            //In case Of Wrong Input
	{
			printf("*                                                                          *");	
			printf("\n*                                                                          *");	
			printf("\n*                                                                          *");	
			printf("\r*                     Wrong Input!!! Nothing Saved ");
	}
	printfooter();	                                                                                //Print Footer
	system("pause");                                                                                //Halts The System
	system("print");                                                                                //Calls The Program Which Prints List Of Entries
}