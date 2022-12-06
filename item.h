#ifndef Item_H
#define Item_H

#include <iostream>

class Item {
 public:
  Item();
  //
  //~Item
  // never needed, could destory/make itenms if I wanted later
  char* getName();
 private:
  char* name;
};

#endif
