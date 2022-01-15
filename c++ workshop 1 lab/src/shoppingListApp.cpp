//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       1 (lab)
// Date:           Jan 16, 2021
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "File.h"
#include "ShoppingList.h"
#include "Utils.h"

// set to false when compling on Linux
const bool APP_OS_WINDOWS = false;

using namespace std;
using namespace sdds;

int listMenu();

int main() {
   bool done = false;
   loadList();
   while (!done) {
      system(APP_OS_WINDOWS ? "cls" : "clear");
      switch (listMenu()) {
      case 1:
         toggleBought();
         break;
      case 2:
         addItemToList();
         break;
      case 3:
         removeItemfromList();
         break;
      case 4:
         removeBoughtItems();
         break;
      case 5:
         clearList();
         break;
      default:
         done = true;
      }
   }
   saveList();
   return 0;
}

int listMenu() {
   cout << "-->>> My Shopping List <<<--" << endl;
   displayList();
   cout << "----------------------------" << endl
      << "1- Toggle bought Item" << endl
      << "2- Add Shopping Item" << endl
      << "3- Remove Shopping Item" << endl
      << "4- Remove bought Items" << endl
      << "5- Clear List" << endl
      << "0- Exit" << endl << "> ";
   return readInt(0, 5);
}