#include <iostream>
#include <fstream>
#include <sstream>
#include "item.h"

Item fridge[MAX];
int countItem = 0;

void create() {
  
}

void display() {
    if (countItem == 0) {
        cout << "The fridge is empty.\n";
        return;
    }

    cout << "\n----- Fridge items -----\n";
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

    cout << "\nSerch by:\n1. Name\n2. Type (e.g. Meat, Veg)\nSelect: ";
    cin >> choice;
    cin.ignore();

    cout << "Enter keyword: ";
    getline(cin, keyword);

    cout << "\n===== Srerch Results =====n";
    for (int i = 0; i < countItem; i++) {
        if ((choice == 1 && fridge[i].name == keyword) ||
            (choice == 2 && fridge[i].type == keyword)) {
            cout << "- " << fridge[i].name
                 << " | " << fridge[i].type
                 << " |expire " << fridge[i].expire
                 << " |qty " << fridge[i].qty << "/n";
            found = 1;
        }
    }

    if (!found) {
        cout << "No items found matching '" << keyword << "'.\n";
    }
}

void insert() {
  if (countItem >= MAX) {
    cout << "Fridge is full. Cannot insert more items.\n";
    return;
  } else {
    cout << "Enter item name: ";
    cin.ignore();
    getline(cin, fridge[countItem].name);

    cout << "Enter item type: ";
    getline(cin, fridge[countItem].type);

    cout << "Enter expiration date (YYYY-MM-DD): ";
    getline(cin, fridge[countItem].expire);

    cout << "Enter quantity: ";
    cin >> fridge[countItem].qty;

    countItem++;
    cout << "Item inserted successfully.\n";
  }
}

void deleteItem() {
  
}

void pickItems() {
  
}

void checkExpire() {
  
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

    file << "===== Picked items =====\n" << detail << "\n";
    file.close();
}
