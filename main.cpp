#include <iostream>
#include <vector>
#include <cstring>

//#include room.h
//#include item.h

using namespace std;

//by Ryan Veith

//this is the main class of the Zuul assignemnt
/*
4 by 4 = 16 rooms
room.h
room.cpp
item.h
item.cpp
main.cpp

room needs:
"description"
vector<item>
(up to) 4 exits //everything will be 2d euclidian space

item needs:
"name"

main needs:
printItem(vector)
printRoom(room)
currentRoom somehow //2d so corinate grid if all else fails
some wincondition

commands
GO (place) //north south east west
HELP
GET (item)
DROP (item)
QUIT
  
 */

//void listInventory

int main() {
  //write a better into later
  cout << "Xuul is a fun game, type HELP" << endl;

  //variables needed later?
  bool quit = false;
  char input[80];
  
  //begin user input
  while (quit == false) {
    //char input[80];
    cin.getline(input, 80);
    if (strcmp(input, "QUIT") == 0) {
      quit = true;
    }
    else if (strcmp(input, "HELP") == 0) {
      cout << "The commands are:" << endl;
      cout << "GO <place>" << endl;
      cout << "GET <item>" << endl;
      cout << "DROP <item>" << endl;
      cout << "HELP" << endl;
      cout << "QUIT" << endl;
    }
    else {
      cout << "command not recognized, type HELP" << endl;
    }
  }
}
