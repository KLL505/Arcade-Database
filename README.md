# Arcade-Database
Created by Kenneth Ly

This program takes aracade machine data from a text file and stores it into a binary search tree in order to 
establish a database for an arcade. This program can also read update files which contain commands that can
manipulate and edit the data within the binary search tree. 

The program first reads data from a file formatted like so:
[NAME], [HIGHSCORE], [INITIALS], [PLAYS], [REVENUE]

The name is a string that consists of alphanumeric characters and can be multiple words. The highscore is an 
integer value, the initials are a string of 3 alphanumeric characters, the number of plays is an integer value, and 
the revenue is a floating point value rounded to two decimal places (the revenue will also be calculated and updated 
automatically based of the number of plays multiplied by 0.25). all of these terms are seperated by a comma.
