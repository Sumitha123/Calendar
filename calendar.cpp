//
//  calendar.cpp
//  Calendar
//
//  Created by Sumitha on 9/26/16.
//  Copyright © 2016 Sumitha. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
int dayStart(int year)
{
    int a,b,c,dayStart_;
    a = (year - 1)/ 4;
    b = (year - 1)/ 100;
    c = (year - 1)/ 400;
    dayStart_ = (year + a - b + c) %7;
    return dayStart_;
}

int main() {
    
    
    int year,month,n;
    int day_start;
    
    
    //Get the year as input from user
    while (1) {
        cout << "Enter the year :";
        cin >> year;
        if (year > 0)
            break;
        else
            cout << "Error : Enter a valid year! \n";
    }
    
    //Get the start month (in number format) as input from user
    while (1) {
        cout << "Enter the month(in number format) :";
        cin >> month;
        if ((month > 0)&(month<=12))
            break;
        else
            cout << "Error : Enter a valid month between 1 and 12! \n";
    }
   
    //Get the number of months as input from user
    while (1) {
        cout << "Enter the number of months : ";
        cin >> n;
        if (n > 0)
            break;
        else
            cout << "Error : Enter a valid number of months! \n";
    }
   
    

    //Enter the number of days in each month.month_[2] = 29 if leap year.
    int month_[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    //Finding whether the given year is a leap year
    if((year%4==0&year%100!=0)||(year%400)==0)
        month_[1] = 29;
    
    // Find the day for start date of the year
    day_start = dayStart(year);
    
    //Initializing counter for the number of months
    int counter = 0;
    
    //Looping through the months to print the calendar for each month.
    for(int k = 0;k<n;k++)
    {
        int d = 0;
        int monthVal = month + k;
        //Start the counter if entered numner of months is greater than 12.
        if(monthVal > 12)
        {
            monthVal = monthVal%12;
            if (monthVal == 0) {
                monthVal = 12;
            }
        
            if((counter == 0)||((counter%12)==0)){
                    year = year+1;
                    day_start = dayStart(year);
                    if((year%4==0&year%100!=0)||(year%400)==0)
                        month_[1] = 29;
                    else
                        month_[1] = 28;
                
            }
            
            counter++;
        }
  
    //Find the start date of the start month
    for(int i = 0;i<(monthVal-1);i++)
    {
        d = d+month_[i];
    }
        d = d%7;
    
    int monthDay = day_start + d;
    if (monthDay>=7)
        monthDay = monthDay%7;
    
    int p = monthDay;
    int q = monthDay;
    
        //Print the month and year
        switch (monthVal) {
            case 1:
                cout << "Jan " << year << "\n";
                break;
            case 2:
                cout << "Feb " << year<< "\n";
                break;
            case 3:
                cout << "Mar " << year<< "\n";
                break;
            case 4:
                cout << "Apr " << year<< "\n";
                break;
            case 5:
                cout << "May " << year<< "\n";
                break;
            case 6:
                cout << "June " << year<< "\n";
                break;
            case 7:
                cout << "July " << year<< "\n";
                break;
            case 8:
                cout << "Aug " << year<< "\n";
                break;
            case 9:
                cout << "Sept " << year<< "\n";
                break;
            case 10:
                cout << "Oct " << year<< "\n";
                break;
            case 11:
                cout << "Nov " << year<< "\n";
                break;
            case 12:
                cout << "Dec " << year<< "\n";
                break;
            default:
                break;
        }
        
    //Printing the Calendar.
    cout<<"-------------------------------------\n";
    cout<<setw(5)<<"Sun"<<setw(5)<<"Mon"<<setw(5)<<"Tue"<<setw(5)<<"Wed"<<setw(5)<<"Thur"<<setw(5)<<"Fri"<<setw(5)<<"Sat"<<"\n";
    cout<<"-------------------------------------\n";
    for(int i =1;i<=month_[monthVal-1];i++)
    {
        cout<<setw(5);
        while(p!=0)
        {
            p--;
            cout<<"  ";
            cout << setw(5);
        }
     
        cout << i;
        if(q==6)
        {
            cout << "\n";
        }
        
        cout<<setw(5);
        
        q++;
        if(q==7)
        {
            q=0;
            
        }
    }
        
    cout << "\n\n";
    }
    
    return 0;
}
