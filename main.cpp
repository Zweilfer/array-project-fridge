#include <iostream>
#include "item.h"
using namespace std;

int main() {
  int menu;
  create();

  do {
    cout << "\n===== Fridge Inventory System =====\n";
    cout << "1. Display all items\n";
    cout << "2. Search\n";
    cout << "3. Insert item\n";
    cout << "4. Delete item\n";
    cout << "5. Pick items\n";
    cout << "6. Check expired items\n";
    cout << "7. Save file\n";
    cout << "8. Check near-expire\n";
    cout << "9. Sort by expiration date\n";
    cout << "10. Delete expired items\n";
    cout << "11. Edit item\n";
    cout << "0. Exit\n";
    cout << "Select menu: ";

    if (!(cin >> menu)) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Invalid input. Please enter a number.\n";
      menu = -1;
      continue;
    }

    switch (menu) {
      case 1: display(); break;
      case 2: search(); break;
      case 3: insert(); break;
      case 4: deleteItem(); break;
      case 5: pickItems(); break;
      case 6: checkExpire(); break;
      case 7: saveFile(); break;
      case 8: checkNearExpire(); break;
      case 9: sortByExpire(); break;
      case 10: deleteExpired(); break;
      case 11: editItem(); break;
      case 0: {
        char saveChoice;
        cout << "Save fridge data before exit? (y/n): ";
        cin >> saveChoice;

        if (saveChoice == 'y' || saveChoice == 'Y') {
          saveFile();
        } else {
          cout << "Exit without saving.\n";
        }

        cout << "Goodbye.\n";
        break;
      }
      default:
        cout << "Invalid menu.\n";
        break;
    }
  } while (menu != 0);

  return 0;
}
