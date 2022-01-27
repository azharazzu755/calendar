#include<stdio.h>
#include<string.h>
int calculate(int day, int month, int year, int option)
{
	
	long int days=0, yearday=0, limit, i, j; month-=1; day-=1;
	int starting, end;
	
	
	for(j=5; j<=year; j++)
	{
		days=0;
		if(j==year) 
		{
			
			limit=month;
			for(i=1;i<=limit;i++)
			{
			
					
				if(i<8 && i!=2)      // upto august
				{
					if(i%2==0) days+=30;
					
					else days+=31;
				}
				else if(i!=2 && i>=8){	// after august
					if(i%2==0) days+=31;
					
					else days+=30;
				}
				else if(i==2)
				{
					if((j%4!=0)||(j%100==0&&j%400!=0)) days+=28;    // leap year calculation
					else days+=29;
				}    
			}
		}
		
		else {
			if((j%4!=0)||(j%100==0&&j%400!=0)) days+=365;    // leap year calculation
					else days+=366;
		}
	
		yearday+=days;
	
	}
	int dayorder=(yearday+day)%7;
	if(option==0)
	return (dayorder);
	else return (yearday+day);
}


void calculatemonth(int month, int year)
{
	
	char string[10000];
	strcpy(string,"");
	printf("\n");
	printf("\t===================================================\n");
	char monthname[12][20]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	printf("\t\t    ");
	printf("\t  %s",monthname[month-1]);
	printf("  ");
	printf("%d\n", year);
	printf("\t===================================================\n");
	printf(" \n");
	printf("%s","\tSun\tMon\tTue\tWed\tThu\tFri\tSat\n\n");
	int spacereq=calculate(1,month,year,0),i, days=daycounter(month,year);
	if (spacereq==0) spacereq=7;
	for(i=1;i<spacereq;i++)
	{
		printf("\t");
	}
	printf("\t");
	int margin=spacereq;
	for(i=1;i<=days;i++)
	{
		printf("%d",i);
		printf("\t");
		if(margin==7){
			printf("\n\n\t");
			margin=0;
		}margin++;
	}
	printf("\n\n");
	printf("\t===================================================\n\n\n");
}
int daycounter(int month, int year)
{
	
	int i=month,j=year,days;
	if(i<8 && i!=2)      // upto august
	{
		if(i%2==0) days=30;
		
		else days=31;
	}
	else if(i!=2 && i>=8){	// after august
		if(i%2==0) days=31;
		
		else days=30;
	}
	else if(i==2)
	{
		if((j%4!=0)||(j%100==0&&j%400!=0)) days=28;    // leap year calculation
		else days=29;
	} 
	return days;
}

void calculateyear(int year)
{
	int i;
	for(i=1;i<=12;i++)
	{
		calculatemonth(i,year);
	}
	
	
}
void select(int day, int month, int year)
{
	int dayorder=0;
	if(month==0 && day==0){ calculateyear(year); printf("\n"); system("pause"); system("cls");  } //year
	else if(day==0 && month!=0 && year!=0) {calculatemonth(month, year); printf("\n"); system("pause"); system("cls"); }//month
	else if(day>=1 && month>=1 && year>=5)                                                //day
	{
		system("cls");
		dayorder=calculate(day, month, year,0);
		char days[][15]={"Saturday","Sunday", "Monday", "Tuesday", "Wednesday", "Thrusday", "Friday"}; 
		printf("\n\n=======================================\n\n");
		printf("  The day of %d - %d - %d is %s \n\n",day,month,year, days[dayorder]);
		printf("=======================================\n\n");
		system("pause"); system("cls");
	}
	else
	{
		printf("\n:::::::: Enter the proper date ::::::::\n"); system("pause"); system("cls");
	}
	
}
void instructions()
{
	printf("INSTRUCTIONS: \n\n");
	printf("    * Enter a valid date to show the DAY or MONTH or YEAR\n\n");
	printf("    * With option 4, You can calculate the Number of days\n      between two dates\n\n");// for day counter
	
	
}

int menu()
{
	system("cls");
		printf("==========================================================\n\n");
		printf("=======================  CALENDER  =======================\n\n");
		printf("==========================================================\n\n");
	int choice;
	int day=0, month=0, year=0;
	printf(" 1. Show Day\n\n 2. Show Month\n\n 3. Show Year\n\n 4. Show Day Difference\n\n 5. Exit\n\nEnter Your Choice: "); scanf("%d", &choice); system("cls");
	switch(choice)
	{
		case 1:
			printf("\n\n=====================\n\n");
			printf("   Day   : "); scanf("%d", &day);
			printf("   Month : "); scanf("%d", &month);
			printf("   Year  : "); scanf("%d", &year);
			system("cls");
			if(day>0 && day<=31 && month>=1 && month<=12 && year>=5) select(day,month,year);
			else {printf(":::::::: Enter the proper date ::::::::\n");system("pause"); }return ; 
			break;
		case 2:
			printf("\n\n=====================\n\n");
		 	printf("   Month : "); scanf("%d", &month);
		    printf("   Year  : "); scanf("%d", &year);
		    system("cls");
		    if(month>=1 && month<=12 && year>=5) select(0 ,month ,year);
			else {printf(":::::::: Enter the proper date ::::::::\n");system("pause");};
			return ;
		    break;
		case 3:
			printf("\n\n=====================\n\n");
			printf("   Year  : "); scanf("%d", &year); system("cls");
			if(year>=5)select(0,0,year);
			else{printf(":::::::: Enter the proper date ::::::::\n");system("pause");
			}
			break;
		case 4:
			system("cls");
			int day1=0, day2=0,i; int date1[3], date2[3];
			for(i=0;i<2;i++){
			printf("\n\n=====================\n\n");
			printf("Enter the date of %d\n\n", i+1);
			printf("   Day   : "); scanf("%d", &day);
			printf("   Month : "); scanf("%d", &month);
			printf("   Year  : "); scanf("%d", &year);
			system("cls");
			if(day>0 && day<=31 && month>=1 && month<=12 && year>=5 ){
				if(i==0){
					date1[0]=day;
					date1[1]=month;
					date1[2]=year;
					day1=calculate(day,month,year,1);
				} 
				else if(i==1) {
					date2[0]=day;
					date2[1]=month;
					date2[2]=year;
					day2=calculate(day,month,year,1);
				}
			} 
			else {printf(":::::::: Enter the proper date ::::::::\n");system("pause"); return ;}
			}
			system("cls");
			int pday=(day1>day2?day1-day2:day2-day1);
			printf("\n\n===============================================================\n\n");
			printf("     There are %d days between %d - %d - %d and %d - %d - %d", pday, date1[0], date1[1], date1[2], date2[0], date2[1], date2[2]);
			printf("\n\nAlternate Units: \n\n");
			printf("     %d Weeks and %d Days\n", pday/7, pday%7);
			printf("     %d Hours\n", pday*24);
			printf("     %d Minutes\n", pday*24*60);
			printf("\n\n===============================================================\n\n");
			system("pause"); system("cls");
			break;
		case 5:
			 return 5665;
		default:
			printf("Enter the Proper Option");
			return ;
			
	}
}

int main()
{
	int day,month,year;
	
		printf("==========================================================\n\n");
		printf("=======================  CALENDER  =======================\n\n");
		printf("==========================================================\n\n");
		instructions();
		system("pause"); system("cls");
	
	
	while(1){
		
		int status;
		status=menu();
		if(status==5665) return 0; 
	

	
}
	
}
