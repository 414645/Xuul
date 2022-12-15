#include <iostream>
#include <cstring>
//#include <vector>

#include "room.h"

using namespace std;

Room::Room() {
  //never called
}

Room::Room(char* newDescription) {  //, vector location?) {
  //strcpy(newDescription, description);
  //description = newDescription;
}

//~room //never destroy rooms

void Room::getDescription() {
  cout << "hello world";
  cout << *description << endl;
  cout << "On the floor you see:";
  //go though itemlist and cout
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
