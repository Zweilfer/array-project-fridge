#include <iostream>
#include "item.h"
using namespace std;

int main() {
  int menu;
  create();

  do{
    cout << "\n===== Fridge Inventory System =====\n";
        cout << "1. Display all items\n";
        cout << "2. Search\n";
        cout << "3. Insert item\n";
        cout << "4. Delete item\n";
        cout << "5. Pick items\n";
        cout << "6. Check expired items\n";
        cout << "7. Save file\n";
        cout << "0. Exit\n";
        cout << "Select menu: ";
        cin >> menu;

    switch (menu){
      case 1: display(); break;
            case 2: search(); break;
            case 3: insert(); break;
            case 4: deleteItem(); break;
            case 5: pickItems(); break;
            case 6: checkExpire(); break;
            case 7: saveFile(); break;
            case 0: cout << "Goodbye.\n"; break;
            default: cout << "Invalid menu.\n";
    } while (menu != 0);

    return 0;
  }
