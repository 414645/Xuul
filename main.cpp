#include <iostream>
#include <vector>
#include <cstring>

#include "room.h"
#include "item.h"

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

  //char* for strtok start is first command end is second
  //anthing after second ' ' is ignored
  char* startInput = new char[40]; //should be 4 but I am paranoid
  char* endInput = new char[40];

  //intilixation
  vector<Room*> roomList;
  Room* currentRoom = new Room();

  //create rooms
  char loretext[80] = "hello world :)";
  char* description = loretext;
  Room* a1 = new Room(description);

  cout << "Lore: " << loretext << endl;
  cout << "Info: " << *description << endl;
  
  //create items

  //starting room
  currentRoom = a1;
  
  //begin user input
  while (quit == false) {
    //char input[80];
    cin.getline(input, 80);
    
    //parse first and second word
    //first figurs out # of spaces
    //if 1 space runs first strtok
    //if 2 runs second one
    int spaceNumber = 0;
    for (int a = 0; a < 80; a++) {
      if (input[a] == ' ') {
	spaceNumber++;
      }
    }
    if (spaceNumber > 0) {
      startInput = strtok(input, " "); 
    }
    if (spaceNumber > 1) {
      endInput = strtok(NULL, " ");
    }

    //do something with the user input
    if (strcmp(input, "QUIT") == 0) {
      quit = true;
    }
    else if (strcmp(input, "HELP") == 0) {
      //list commands
      cout << "The commands are:" << endl;
      cout << "GO <place>" << endl;
      cout << "GET <item>" << endl;
      cout << "DROP <item>" << endl;
      cout << "LIST" << endl;
      cout << "HELP" << endl;
      cout << "QUIT" << endl;
    }
    else if (strcmp(input, "LIST") == 0) {
      //list backpack
      cout << "In your back pack you have: " << endl;
    }
    else if (strcmp(startInput, "GO") == 0) {
      //
      cout << "go" << endl;
      currentRoom->getDescription();
      //      if (strcmp(endImput, "UP") == 0) {
	//go up
      //}
    }
    else if (strcmp(startInput, "GET") == 0) {
      //
      cout << "get" << endl;
    }
    else if (strcmp(startInput, "DROP") == 0) {
      //
      cout << "drop" << endl;
    }
    else {
      cout << "command not recognized, type HELP" << endl;
    }
  }
}
