#include "../../../../headers/Screens/Books/ListBooks/clsListMenu.h"
#include "../../../../headers/Lib/clsInputValidate.h"
#include "../../../../headers/Screens/Books/ListBooks/clsAllBooksList.h"
#include "../../../../headers/Screens/Books/ListBooks/clsAvailableList.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

// Get user choice
clsListMenu::eListOptions clsListMenu::_GetUserChoice() {
    return (eListOptions)clsInputValidate::Readnumberbetween(1, 3, "\n * Select your option : ");
}
// print menu
void clsListMenu::_PrintMenu() {
    system("clear");
    PrintHeaderScreen("LIST MENU SCREEN", "📍", Colors::Magenta);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();
    PrintHeaderScreen("List By", "📌", Colors::Magenta, false);
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] All" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] Available" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] Exit" << endl;
    cout << Colors::GetMagenta() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
// perform option
void clsListMenu::_PerformOption(eListOptions option) {
    switch (option) {
        case eListOptions::LIST_ALL: {
            _ListAllBooks();
            break;
        }
        case eListOptions::LIST_AVAILABLE: {
            _ListAvailableBooks();
            break;
        }
        case eListOptions::EXIT: {
            break;
        }
    }
    // pause screen after each func finished
    if (option != eListOptions::EXIT) {
        // this trick just to pause termux screen until the user Contenu
        cout << " \n\n\n\n\n\nEnter any Key to Contenu ... " << endl;
        char Contenue = clsInputValidate::ReadChar();
        Contenue = ' ';
        cout << Contenue << endl;
    }
}
// List All
void clsListMenu::_ListAllBooks() {
    system("clear");
    clsAllBooksList::AllBooksListScreen();
}
// List available
void clsListMenu::_ListAvailableBooks() {
    system("clear");
    clsAvailableList::AvailableListScreen();
}

// List books menu
void clsListMenu::ListMenuScreen() {
    eListOptions option;
    do {
        _PrintMenu();
        option = _GetUserChoice();
        _PerformOption(option);
    } while (option != eListOptions::EXIT);
}
