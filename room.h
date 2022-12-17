#ifndef Room_H
#define Room_H

#include <iostream>
#include <vector>
#include "item.h"

//The room class had a description of the room
//It also had a list of items in the room
//(one room is also used as your invantory)

using namespace std;

class Room {
 public:
  Room();
  Room(char*);
  //~Room //I think its never needed
  void getDescription();
  //I would say char* but just having the room describe iself
  void addItem(Item*);
  //compitem added to check win condition
  //returns true if name of item is same as an item in room
  bool compItem(char*);
  void removeItem(char*, Room*);
  //decided to make all exits added though fucnction
  //more start code needed but can have new exits open
  //no delete exit needed for my current game
  void addExit(Room*);
  Room* getExit(int);
 private:
  char* description = new char[80];
  //list of items
  vector<Item*> itemList;
  //exits
  vector<Room*> exitList;
  //I could make exits a class
  //It deserves it more then Item but for 2d it is fine
  //to assume directions since no wierd ones
};

#endif
