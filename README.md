# Arcade-Database
Created by Kenneth Ly

This program takes aracade machine data from a text file and stores it into a binary search tree in order to 
establish a database for an arcade. This program can also read update files which contain commands that can
manipulate and edit the data within the binary search tree. The command logs are displayed to the console and the final
database is outputted to a file in breadth first order.

The program first reads data from a file formatted like so:

[NAME], [HIGHSCORE], [INITIALS], [PLAYS], [REVENUE]

The name is a string that consists of alphanumeric characters and can be multiple words. The highscore is an 
integer value, the initials are a string of 3 alphanumeric characters, the number of plays is an integer value, and 
the revenue is a floating point value rounded to two decimal places (the revenue will also be calculated and updated 
automatically based of the number of plays multiplied by 0.25). all of these terms are seperated by a comma. The program
will take all this data and store it as a game object then put that object into a database represented as a bianry search tree.

Then the program will take an update file that can perform a variety of commands to update or display the database.

Command List:


Add new game to database:

Adds a brand new entry into the database. Called by using the command code 1 before the statement.
The name is signified by encasing a string in quotation marks and all other elements being seperated by a space.

Format:

1 "[NAME]" [HIGHSCORE] [INITIALS] [PLAYS] [REVENUE]


Search Database For Name:

Searches the database for an arcade game with the given name. If found, outputs all of the games information into the console.
Called by using the command code 2 before the statement followed by a string of alphanumeric characters.

Format:

2 [NAME]


Update Game Entry:

Searches the database for an arcade game with the given name. If found, updates the game information and prints the newly updated entry to the console.
Called by using the command code 3 before the statement followed by a string of alphanumeric characters enclosed in double quotations.
then followed by a value repersenting which element to update and the updated value. 

Format:

3 "[NAME]" [1/2/3] [UPDATED VALUE]

 1- High score/
 2- Initials/
 3- Number of plays
 
 
 Delete Game Entry:
 
 Searches the database f0r an arcade game with the given name. If found, deletes the game and all its information from the database 
 and prints the deleted recoord to the console. Called by using the command code 4 before the statement followed by the name which is 
 a string of alphamueric characters.
 
 Format:
 
 4 [NAME]
 
 Sort Database:
 
 Sorts the database alphabetically based off each arcade games name and pprints the output to the console. Called by using the command code 5
 before the statemnet followed by either asc or dec to sort the database in ascending order or decsending order respectively.
 
 Format:
 
 5 [asc/des]
 
 

