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
  int choice;
  char keyword[50]
  int found  = 0;

  printf("\nSerch by:\n1. Name\n2. Type (e.g. Meat, Veg)\nSelect: ");
  scanf("%d", &choice);
  printf("Enter keyword: );
  scanf(" %[^\n]", keyword);

  printf("\n--- Srerch Results ---n");
  for (int i = 0; i < count; i++){
     if ((choice == 1 && strcasecmp(fridge[i].name, keyword) == 0)||
         (choice == 2 && strcasecmp(fridge[i].type, keyword) == 0)) {
         printf("- %s | %s |expire %s |qty %d/n" fridge[i].name, fridge[i].type, fridge[i].expire, fridge[i].qty);
         found = 1;
     }
  }
  if (!found) {
      print("No items found matching '%s'.\n", keyword);
  }
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
