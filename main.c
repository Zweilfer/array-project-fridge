#include <stdio.h>
#include "item.h"

int main() {
  int menu;
  create();

  do{
    printf("\n===== Fridge Inventory System =====\n");
    printf("1. Display all items in fridge\n");
    printf("2. Search\n");
    printf("3. Insert item\n");
    printf("4. Delete item\n");
    printf("5. Pick items\n");
    printf("6. Check expired items\n");
    printf("7. Save file\n")
    printf("0. Exit");
    printf("Select menu: ")
    scanf("%d", &menu);

    switch (menu){
      case 1: display(); break;
      case 2: search(); break;
      case 3: insert(); break;
      case 4: deleteItem(); break;
      case 5: pickItem(); break;
      case 6: checkExpire(); break;
      case 7: saveFile(); break;
      case 0: printf("Goodbye.\n"); break;
      default: printf("Invalid menu.\n");
    } while (menu != 0);

    return 0;
  }
