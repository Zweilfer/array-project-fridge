#ifndef ITEM_H
#define ITEM_H

#define MAX 100

typedef struct {
  char name[50];
  char type[30];
  char expire[20];
  int  qty;
} Item;

extern Item fridge[MAX];
extern int count;

void create();
void display();
void search();
void insert();
void deleteItem();
void pickItem();
void checkExpire();
void saveFile();
void saveHistory(coust char *detail);

#endif
