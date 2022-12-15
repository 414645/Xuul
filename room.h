#ifndef Room_H
#define Room_H

#include <iostream>
#include <vector>
#include "item.h"

using namespace std;

class Room {
 public:
  Room();
  Room(char*);
  //~Room //I think its never needed
  void getDescription();
  //I would say char* but just having the room describe iself
  void addItem(Item*);
  void removeItem(Item*);
  //make more sofisitcated later + accurate
 private:
  char* description = new char[80];
  //list of items
  vector<Item*> itemList;
  //exits
};

#endif
