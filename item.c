#include <stdio.h>
#include <string.h>
#include "item.h"

Item fridge[MAX];
int count = 0;

void create() {
  
}

void display() {
  if(count == 0){
    printf("The fridge is empty.\n");
    return 0;  
  }
  print("\n===== Fridge items =====\n");
  for (int i =0; i< count; i++){
    printf("%d. %s | %s | expire %s | qty %d\n", i + 1, fridge[i].name, fridge[i].type, fridge[i].expire, fridge[i].qty);
  }
}

void search() {
  
}

void insert() {
  
}

void deleteItem() {
  
}

void pickItems() {
  
}

void checkExpire() {
  
}

void saveFile() {
  FILE *fp = fopen("fridge.txt", "w");
  if(fp == NULL) {
    print("Cannot save file.\n");
    return;
  }

  for (int i = 0; i < count; i++) {
    fprintf(fp, "%s,%s,%s,%d\n", fridge[i].name, fridge[i].type, fridge[i].expire, fridge[i].qty);
  }
  fclose(fp);
  print("Fridge data saved.\n");
}

void saveHistory(const char *detail){
  FILE *fp = fopen("history.txt", "a");
  if (fp == NULL) return;

  fprint(fp, "===== Picked items =====\n%s\n", detail);
  fclose(fp);
}
