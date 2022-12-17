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
  cout << newDescription << endl;
  cout << description << endl;
}

//~room //never destroy rooms

void Room::getDescription() {
  // cout << *description << endl;
  cout << description << endl;
  cout << "There is a: ";
  //go though itemlist and cout
  for (int a = 0; a < itemList.size(); a++) {
    cout << itemList[a]->getName() << " ";
  }
  cout << " " << endl;
  
}

void Room::addItem(Item* thing) {
  itemList.push_back(thing);
}

void Room::removeItem(Item* thing) {
  for (int a = 0; a < itemList.size(); a++) {
    //if (strcmp(itemList[a]->getName(), *thing) == 0) {
    //  itemList.erase(itemList.begin()+a);
    //}
  }
}
