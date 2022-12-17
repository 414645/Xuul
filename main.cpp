#include <iostream>
#include <vector>
#include <cstring>

#include "room.h"
#include "item.h"

using namespace std;

//by Ryan Veith
//12/16/2022
//this is the main class of the Zuul assignemnt
//it creats all the rooms, with thier description and exits
//it creats items
//it does the user interface

//GO <invalid answer> defaults to NORTH

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
  
  //create exits (manual since I keep mixing up rooms)
  //also lets me play with non linear space without
  //screwing everything up
  //keep geting confused on
  //wraping the edges of the world
  //(this is why letter# cordinats have been added)
  //start a
  a1->addExit(a4); //north
  a1->addExit(b1); //east
  a1->addExit(a2); //south
  a1->addExit(d1); //west
  
  a2->addExit(a1); //north
  a2->addExit(b2); //east
  a2->addExit(a3); //south
  a2->addExit(d2); //west

  a3->addExit(a2); //north
  a3->addExit(b3); //east
  a3->addExit(a4); //south
  a3->addExit(d3); //west

  a4->addExit(a3); //north
  a4->addExit(b4); //east
  a4->addExit(a1); //south
  a4->addExit(d4); //west

  //start b
  b1->addExit(b4); //north
  b1->addExit(c1); //east
  b1->addExit(b2); //south
  b1->addExit(a1); //west
  
  b2->addExit(b1); //north
  b2->addExit(c2); //east
  b2->addExit(b3); //south
  b2->addExit(a2); //west

  b3->addExit(b2); //north
  b3->addExit(c3); //east
  b3->addExit(b4); //south
  b3->addExit(a3); //west

  b4->addExit(b3); //north
  b4->addExit(c4); //east
  b4->addExit(b1); //south
  b4->addExit(a4); //west

  //start c
  c1->addExit(c4); //north
  c1->addExit(d1); //east
  c1->addExit(c2); //south
  c1->addExit(b1); //west
  
  c2->addExit(c1); //north
  c2->addExit(d2); //east
  c2->addExit(c3); //south
  c2->addExit(b2); //west

  c3->addExit(c2); //north
  c3->addExit(d3); //east
  c3->addExit(c4); //south
  c3->addExit(b3); //west

  c4->addExit(c3); //north
  c4->addExit(d4); //east
  c4->addExit(c1); //south
  c4->addExit(b4); //west

  //start d
  d1->addExit(d4); //north
  d1->addExit(a1); //east
  d1->addExit(d2); //south
  d1->addExit(c1); //west
  
  d2->addExit(d1); //north
  d2->addExit(a2); //east
  d2->addExit(d3); //south
  d2->addExit(c2); //west

  d3->addExit(d2); //north
  d3->addExit(a3); //east
  d3->addExit(d4); //south
  d3->addExit(c3); //west

  d4->addExit(d3); //north
  d4->addExit(a4); //east
  d4->addExit(d1); //south
  d4->addExit(c4); //west
  
  //create the items and put in rooms
  //item 1: BOOK
  char* item1 = new char[10];
  strcpy(item1, "BOOK");
  Item* thing1 = new Item(item1);
  a1->addItem(thing1);
  //item 2: CRYSTAL
  char* item2 = new char[10];
  strcpy(item2, "CRYSTAL");
  Item* thing2 = new Item(item2);
  a1->addItem(thing2);
  //item 3: MAGIC (why is magic an item? becasue I said so
  char* item3 = new char[10];
  strcpy(item3, "MAGIC");
  Item* thing3 = new Item(item3);
  a1->addItem(thing3);
  //item 4: GOAT (initial idea was bison in US history)
  char* item4 = new char[10];
  strcpy(item4, "GOAT");
  Item* thing4 = new Item(item4);
  a1->addItem(thing4);
  //item 5: CD
  char* item5 = new char[10];
  strcpy(item5, "CD"); //music disk or something
  Item* thing5 = new Item(item5);
  a1->addItem(thing5);
  
  //starting room
  currentRoom = a1;

  //inventory
  char* backpack = new char[80];
  strcpy(backpack, "In your large backpack");
  Room* inventory = new Room(backpack);

  //start text
  //write a better intro? I like this one though...
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
      //currentRoom->getDescription();
      int endLocation = 0; //default north
      //find direction
      if (strcmp(endInput, "NORTH") == 0) {
        //cout << "go north";
	endLocation = 0;
      }
      if (strcmp(endInput, "EAST") == 0) {
	//cout << "go east";
	endLocation = 1;
      }
      if (strcmp(endInput, "SOUTH") == 0) {
        //go south
	endLocation = 2;
      }
      if (strcmp(endInput, "WEST") == 0) {
        //go north
	endLocation = 3;
      }
      if (strcmp(endInput, "PORTAL") == 0) {
        //go north
	endLocation = 4;
      }
      //go direction
      cout << endLocation;
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
