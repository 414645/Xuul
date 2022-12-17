#include <iostream>
#include <vector>
#include <cstring>

#include "room.h"
#include "item.h"

using namespace std;

//by Ryan Veith
//12/16/2022
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
  //a1
  char* a1text = new char[80];
  strcpy(a1text, "You are in room A1");
  Room* a1 = new Room(a1text);
  //a2
  char* a2text = new char[80];
  strcpy(a2text, "You are in room A2");
  Room* a2 = new Room(a2text);
  //a3
  char* a3text = new char[80];
  strcpy(a3text, "You are in room A3");
  Room* a3 = new Room(a3text);
  //a4
  char* a4text = new char[80];
  strcpy(a4text, "You are in room A4");
  Room* a4 = new Room(a4text);
  //b1
  char* b1text = new char[80];
  strcpy(b1text, "You are in room B1");
  Room* b1 = new Room(b1text);
  //b2
  char* b2text = new char[80];
  strcpy(b2text, "You are in room B2");
  Room* b2 = new Room(b2text);
  //b3
  char* b3text = new char[80];
  strcpy(b3text, "You are in room B3");
  Room* b3 = new Room(b3text);
  //b4
  char* b4text = new char[80];
  strcpy(b4text, "You are in room B4");
  Room* b4 = new Room(b4text);
  //c1
  char* c1text = new char[80];
  strcpy(c1text, "You are in room C1");
  Room* c1 = new Room(c1text);
  //c2
  char* c2text = new char[80];
  strcpy(c2text, "You are in room C2");
  Room* c2 = new Room(c2text);
  //c3
  char* c3text = new char[80];
  strcpy(c3text, "You are in room C3");
  Room* c3 = new Room(c3text);
  //c4
  char* c4text = new char[80];
  strcpy(c4text, "You are in room C4");
  Room* c4 = new Room(c4text);
  //d1
  char* d1text = new char[80];
  strcpy(d1text, "You are in room D1");
  Room* d1 = new Room(d1text);
  //d2
  char* d2text = new char[80];
  strcpy(d2text, "You are in room D2");
  Room* d2 = new Room(d2text);
  //d3
  char* d3text = new char[80];
  strcpy(d3text, "You are in room D3");
  Room* d3 = new Room(d3text);
  //d4
  char* d4text = new char[80];
  strcpy(d4text, "You are in room D4");
  Room* d4 = new Room(d4text);
  
  //create exits (manual since easy enough)
  //more because keep geting confused on
  //wraping the edges of the world
  a1->addExit(a4); //north
  a1->addExit(b1); //east
  a1->addExit(a2); //south
  a1->addExit(d1); //west
  
  
  //create items
  char* item1 = new char[10];
  strcpy(item1, "BOOK");
  Item* thing1 = new Item(item1);
  a1->addItem(thing1);
  
  //starting room
  currentRoom = a1;

  //inventory
  char* backpack = new char[80];
  strcpy(backpack, "In your large backpack");
  Room* inventory = new Room(backpack);

  //start text
  //write a better into later
  cout << "Xuul is a fun game, type HELP!" << endl;
  
  //begin user input
  while (quit == false) {
    //reprint (or inital)
    currentRoom->getDescription();
    
    //char input[80];
    cin.getline(input, 80);
    
    //parse first and second word
    //first figurs out # of spaces
    //if 1 space runs first strtok
    //if 2 runs second one
    //(no third since annoying to type)
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
      //CONFRIM is hard to type so just checks for a second space
      cout << "GO <place> CONFIRM" << endl;
      cout << "GET <item> CONFIRM" << endl;
      cout << "DROP <item> CONFRIM" << endl;
      cout << "LIST" << endl;
      cout << "HELP" << endl;
      cout << "QUIT" << endl;
      //cout << "(CONFIM is hard to";
      //cout << "type so a space works too)" << endl;
    }
    else if (strcmp(input, "LIST") == 0) {
      //list backpack
      inventory->getDescription();
    }
    else if (strcmp(startInput, "GO") == 0) {
      //
      //cout << "go" << endl;
      //currentRoom->getDescription();
      //a1->getDescription();
      int endLocation = 0; //default north
      if (strcmp(endInput, "NORTH") == 0) {
        //go north
	endLocation = 0;
      }
      currentRoom = currentRoom->getExit(endLocation);
      
    }
    else if (strcmp(startInput, "GET") == 0) {
      cout << "got ";
      currentRoom->removeItem(endInput, inventory);
    }
    else if (strcmp(startInput, "DROP") == 0) {
      cout << "dropped ";
      inventory->removeItem(endInput, currentRoom);
      
    }
    else {
      cout << "command not recognized, type HELP" << endl;
    }
  }
}
