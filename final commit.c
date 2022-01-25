#include<stdio.h>
#include<string.h>
int calculate(int day, int month, int year)
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
	
	return (dayorder);
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
	int spacereq=calculate(1,month,year),i, days=daycounter(month,year);
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
		dayorder=calculate(day, month, year);
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
	printf("    * Enter a valid date to show the DAY\n\n");
	printf("    * Enter a ZERO in day and a valid month \n      and year to show MONTH \n\n");
	printf("    * Enter ZERO in day and month. \n      And enter a valid year to show the whole YEAR\n\n");
	printf("Example:\n\n");
	printf("To show day: \n\n");
	printf("   Day: xx\n   Month: y\n   Year: zzzz\n\n");
	printf("To show month: \n\n");
	printf("   Day: 0\n   Month: y\n   Year: zzzz\n\n");
	printf("To show year: \n\n");
	printf("   Day: 0\n   Month: 0\n   Year: zzzz\n\n"); 
	
}

int main()
{
	int day,month,year; int display=0;
	if(display==0)
	{
		printf("==========================================================\n\n");
		printf("=======================  CALENDER  =======================\n\n");
		printf("==========================================================\n\n");
		display=1;
		instructions();
		system("pause"); system("cls");
	}
	if(display==1){
	
	while(1){
	
	printf("\n\n   ==================\n\n");
	printf("   Day   : "); scanf("%d", &day);
	printf("   Month : "); scanf("%d", &month);
	printf("   Year  : "); scanf("%d", &year);
	system("cls");
	
	if(day<=31 && month<=12 && year>=5) select(day,month,year);
	
	else {printf(":::::::: Enter the proper date ::::::::\n");system("pause"); system("cls");}
	 }
	
	}
	
	return 0;
}
