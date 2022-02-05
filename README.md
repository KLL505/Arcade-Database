# Arcade-Database
Created by Kenneth Ly

This program takes arcade machine data from a text file and stores it into a binary search tree in order to 
establish a database for an arcade. This program can also read update files which contain commands that can
manipulate and edit the data within the binary search tree. The command logs are displayed to the console and the final
database is outputted to a file in breadth-first order.

The program first reads data from a file formatted like so:

[NAME], [HIGHSCORE], [INITIALS], [PLAYS], [REVENUE]

The name is a string that consists of alphanumeric characters and can be multiple words. The high score is an 
integer value, the initials are a string of 3 alphanumeric characters, the number of plays is an integer value, and 
the revenue is a floating-point value rounded to two decimal places (the revenue will also be calculated and updated 
automatically based of the number of plays multiplied by 0.25). all of these terms are separated by a comma. The program
will take all this data and store it as a game object then put that object into a database represented as a binary search tree.

Then the program will take an update file that can perform a variety of commands to update or display the database.

Command-List:


Add new game to database:

Adds a brand new entry into the database. Called by using command code 1 before the statement.
The name is signified by encasing a string in quotation marks and all other elements being separated by a space.

Format:

1 "[NAME]" [HIGHSCORE] [INITIALS] [PLAYS] [REVENUE]


Search Database For Name:

Searches the database for an arcade game with the given name. If found, outputs all of the games information into the console.
Called by using the command code 2 before the statement followed by a string of alphanumeric characters.

Format:

2 [NAME]


Update Game Entry:

Searches the database for an arcade game with the given name. If found, update the game information and prints the newly updated entry to the console.
Called by using the command code 3 before the statement followed by a string of alphanumeric characters enclosed in double quotations.
then followed by a value representing which element to update and the updated value. 

Format:

3 "[NAME]" [1/2/3] [UPDATED VALUE]

 1- High score/
 2- Initials/
 3- Number of plays
 
 
 Delete Game Entry:
 
 Searches the database for an arcade game with the given name. If found, deletes the game and all its information from the database 
 and prints the deleted record to the console. Called by using the command code 4 before the statement followed by the name which is 
 a string of alphanumeric characters.
 
 Format:
 
 4 [NAME]
 
 Sort Database:
 
 Sorts the database alphabetically based on each arcade game's name and prints the output to the console. Called by using the command code 5
 before the statement followed by either "asc" or "des" to sort the database in ascending order or descending order respectively.
 
 Format:
 
 5 [asc/des]


*cidercade.dat is the sample data file and update1.txt is the sample update file provided to test this program
 

