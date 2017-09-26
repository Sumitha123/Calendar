# Calendar

Program gets the year, start month and number of months to be printed as inputs from the use. If the user enters negative value or invalid data, then it prompts an error message.

Based on the input year, dayStart_ function  finds the start day of the year.

Next, we determine if the given year is a leap year. Number of days in each month is stored in an array. The number of days in February is 29, if leap year else 28.

The biggest for loop loops through the number of months and prints the calendar month by month.

A counter is initialized. Year is incremented by 1 as soon as the counter goes past 12 and the counter is reset again.

The start day of each month is calculated based on the start day of the particular year by counting forward.




