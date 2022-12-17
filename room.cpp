#include <iostream>
#include <cstring>
//#include <vector>

#include "room.h"

using namespace std;

Room::Room() {
  //never called
}

Room::Room(char* newDescription) {  //, vector location?) {
  strcpy(description, (newDescription));
  //cout << newDescription << endl;
  //cout << description << endl;
}

//~room //never destroy rooms

void Room::getDescription() {
  //description
  cout << description << endl;
  //items
  cout << "There is a: ";
  //go though itemlist and cout
  for (int a = 0; a < itemList.size(); a++) {
    cout << itemList[a]->getName() << " ";
  }
  cout << " " << endl;
  //exits (infinite plane all directions)
  for (int a = 0; a < exitList.size(); a++) {
    //here is the infinite part
    //since all it is simpler to just know
    //then to take a input, besides you
    //dont have to get rid of first cout
    //with another if (since inventory)
    if (a == 0) {
      cout << "There are Exits: ";
      cout << "NORTH";
    }
    else if (a == 1) {
      cout << "EAST";
    }
    else if (a == 2) {
      cout << "SOUTH";
    }
    else if (a == 3) {
      cout << "WEST";
    }
    else if (a == 4) {
      cout << "PORTAL";
    }
    cout << " ";
  }
  cout << " " << endl;
}

void Room::addExit(Room* exit) {
  exitList.push_back(exit);
}

Room* Room::getExit(int direction) {
  //0 north, 1 east, 2 south, 3 west
  return(exitList[direction]);
}

void Room::addItem(Item* thing) {
  //cout << "dropped" << thing->getName() << endl;
  itemList.push_back(thing);
}

void Room::removeItem(char* thing, Room* inventory) {
  //if thing is "" type 3 words once and it might work
  for (int a = 0; a < itemList.size(); a++) {
    //cout << "list " << itemList[a]->getName() << endl;
    //cout << "thing" <<  thing << endl;
    if (strcmp((itemList[a]->getName()), thing) == 0) {
      //add to inventory
      cout << thing << endl;
      inventory->addItem(itemList[a]);
      //erase
      itemList.erase(itemList.begin()+a);
    }
  }
}

bool Room::compItem(char* thing) {
  //like delete go thought list
  for (int a = 0; a < itemList.size(); a++) {
    if (strcmp((itemList[a]->getName()), thing) == 0) {
      //found it
      return(true);
    }
  }
  return(false);
}
