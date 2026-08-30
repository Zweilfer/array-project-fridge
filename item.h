#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

const int MAX = 100;

struct Item{
  string name;
  string type;
  string expire;
  int  qty;
};

extern Item fridge[MAX];
extern int countItem;

void create();
void display();
void search();
void insert();
void deleteItem();
void pickItems();
void checkExpire();
void saveFile();
void saveHistory(coust string &detail);

#endif
