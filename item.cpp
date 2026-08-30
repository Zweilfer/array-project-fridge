#include <iostream>
#include <fstream>
#include <sstream>
#include "item.h"

Item fridge[MAX];
int countItem = 0;

void create() {
  ifstream file("fridge.txt");
  if(!file){
    cout << "No fridge file. Starting empty.";
    return;
  }
  countItem = 0;

  string line;
  while (getline(file, line)) {
    if (countItem >= MAX) break;

    stringstream ss(line);
    string name, type, expire;
    int qty;

    if (getline(ss, name, ',') &&
        getline(ss, type, ',') &&
        getline(ss, expire, ',') &&
        (ss >> qty)) {
      fridge[countItem].name = name;
      fridge[countItem].type = type;
      fridge[countItem].expire = expire;
      fridge[countItem].qty = qty;
      countItem++;
    }
  }
  file.close();
}

void display() {
    if (countItem == 0) {
        cout << "The fridge is empty.\n";
        return;
    }

    cout << "\n===== Fridge items =====\n";
    for (int i = 0; i < countItem; i++) {
        cout << i + 1 << ". "
             << fridge[i].name << " | "
             << fridge[i].type << " | expire "
             << fridge[i].expire << " | qty "
             << fridge[i].qty << "\n";
    }
}

void search() {
    int choice;
    string keyword;
    int found = 0;

    cout << "\nSearch by:\n1. Name\n2. Type (e.g. Meat, Veg)\nSelect: ";
    cin >> choice;
    cin.ignore();

    cout << "Enter keyword: ";
    getline(cin, keyword);

    cout << "\n===== Srerch Results =====\n";
    for (int i = 0; i < countItem; i++) {
        if ((choice == 1 && fridge[i].name == keyword) ||
            (choice == 2 && fridge[i].type == keyword)) {
            cout << "- " << fridge[i].name
                 << " | " << fridge[i].type
                 << " |expire " << fridge[i].expire
                 << " |qty " << fridge[i].qty << "\n";
            found = 1;
        }
    }

    if (!found) {
        cout << "No items found matching '" << keyword << "'.\n";
    }
}

void insert() {
  string name, type, expire;
  int qty;

  cout << "Enter item name: ";
  cin.ignore();
  getline(cin, name);

  cout << "Enter item type: ";
  getline(cin, type);

  cout << "Enter expiration date (YYYY-MM-DD): ";
  getline(cin, expire);

  cout << "Enter quantity: ";
  cin >> qty;

  int foundIndex = -1;
  for (int i = 0; i < countItem; i++) {
    if (fridge[i].name == name && fridge[i].type == type && fridge[i].expire == expire) {
      foundIndex = i;
      break;
    }
  }

  if (foundIndex != -1) {
    fridge[foundIndex].qty += qty;
    cout << "Item quantity updated successfully.\n";
  } else {
    if (countItem >= MAX) {
      cout << "Fridge is full. Cannot insert more items.\n";
      return;
    }
    fridge[countItem].name = name;
    fridge[countItem].type = type;
    fridge[countItem].expire = expire;
    fridge[countItem].qty = qty;
    countItem++;
    cout << "Item inserted successfully.\n";
  }
}

void deleteItem() {
  if (countItem == 0) {
    cout << "Fridge is empty.\n";
    return;
  }
  display();
  int choice;
  cout << "Enter item number to delete (1 to " << countItem << "): ";
  cin >> choice;
  if (choice < 1 || choice > countItem) {
    cout << "Invalid item number.\n";
    return;
  }
  for (int i = choice - 1; i < countItem - 1; i++) {
    fridge[i] = fridge[i + 1];
  }
  countItem--;
  cout << "Item deleted successfully.\n";
}

void pickItems() {
    int n, useQty;
    string name;
    string summary = "";

    if (countItem == 0) {
        cout << "No items to pick.\n";
        return;
    }

    display();
    cout << "How many items to pick: ";
    cin >> n;

    for (int k = 0; k < n; k++) {
        cin.ignore();
        cout << "Name of item " << k + 1 << ": ";
        getline(cin, name);

        cout << "Quantity to use: ";
        cin >> useQty;

        int found = -1;
        for (int i = 0; i < countItem; i++) {
            if (fridge[i].name == name) {
                found = i;
                break;
            }
        }

        if (found == -1) {
            cout << name << " not found.\n";
            continue;
        }

        if (useQty <= 0) {
            cout << "Invalid quantity.\n";
            continue;
        }

        if (useQty > fridge[found].qty) {
            cout << "Not enough stock. Remaining: " << fridge[found].qty << "\n";
            continue;
        }

        fridge[found].qty -= useQty;
        summary += fridge[found].name + " x " + to_string(useQty) + "\n";

        if (fridge[found].qty == 0) {
            for (int i = found; i < countItem - 1; i++) {
                fridge[i] = fridge[i + 1];
            }
            countItem--;
        }
    }

    cout << "\n===== Picked items =====\n" << summary;
    saveHistory(summary);
}

void checkExpire() {
    if (countItem == 0) {
    cout << "Fridge is empty.\n";
    return;
  }

  string currentDate;

  cout << "Enter current date (YYYY-MM-DD): ";
  cin >> currentDate;

  cout << "\n===== Expired Items =====\n";

  int found = 0;

  for (int i = 0; i < countItem; i++) {

    if (fridge[i].expire == currentDate) {
      cout << "- " << fridge[i].name
           << " | " << fridge[i].type
           << " | expire " << fridge[i].expire
           << " | qty " << fridge[i].qty << "\n";
     
        found = 1;

    }
  }
  if (!found) {
    cout << "No expired items found for the date " << currentDate << ".\n";
  }
}

void saveFile() {
    ofstream file("fridge.txt");
    if (!file) {
        cout << "Cannot save file.\n";
        return;
    }

    for (int i = 0; i < countItem; i++) {
        file << fridge[i].name << ","
             << fridge[i].type << ","
             << fridge[i].expire << ","
             << fridge[i].qty << "\n";
    }
    file.close();
    cout << "Fridge data saved.\n";
}

void saveHistory(const string &detail) {
    ofstream file("history.txt", ios::app);
    if (!file) return;

    file << "\n===== Picked items =====\n" << detail << "\n";
    file.close();
}
