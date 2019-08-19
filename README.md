# Restaurant_Waiting_Managment
C program that will implement a customer waiting list that might be used by a restaurant. When people want to be seated in the restaurant, they give their name and group size to the host/hostess and then wait until those in front of them have been seated.

Input:

q - to quit the program

? - to list the accepted commands

a - to add a group to the wait list

c - to add a call-ahead group to the wait list

w - to specify a call-ahead group is now waiting in the restaurant

r - to retrieve the first waiting group that can fit at the available table size

l - list how many groups are ahead of the named group

d - display the wait list information

To use the program clone the repositry and type make.

Here are additionla details about the program:

The system does not take reservations for a specific time and date (i.e. table of 4 for 7pm on Saturday), but it will allow for a group to call ahead and get their name on the waiting list before they arrive. Note: these call-ahead groups will still need to check in when they arrive so the host/hostess knows they are waiting in the restaurant.

Groups are added to the wait list when they call-ahead or when they arrive at the restaurant. Groups are always added to the end of the wait list. The system will require that each name used be unique. So when a group is added to the wait list, the system must make sure that no other group is already using that name.

When a table with N seats becomes available in the restaurant, the system returns the name of the first group that is in the restaurant and can sit at a table with N seats (i.e. the number of seats at the table is greater than or equal to the number of people in that group). Note that the group selected may not be the first (or even the second or third) group on the wait list.

This program will NOT keep track of how many tables the restaurant actually has, nor how many people can sit at each table. The host/hostess is expected to know that information and will enter the appropriate values when needed.
