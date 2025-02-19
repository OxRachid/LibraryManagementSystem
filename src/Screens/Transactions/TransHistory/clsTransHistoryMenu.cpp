#include "../../../../headers/Screens/Transactions/TransHistory/clsTransHistoryMenu.h"
#include "../../../../headers/Lib/clsInputValidate.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// print main menu
void clsTransHistoryMenu::_PrintNenu() {
    system("clear");
    PrintHeaderScreen("LIST MENU SCREEN", "📍", Colors::Magenta);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();
    PrintHeaderScreen("List By", "📌", Colors::Magenta, false);
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] All" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] Borrowed" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] Returned" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[4] Exit" << endl;
    cout << Colors::GetMagenta() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}

// Get User Choice
clsTransHistoryMenu::enTransMenuOptions clsTransHistoryMenu::_GetUserChoice() {
    return (enTransMenuOptions)clsInputValidate::Readnumberbetween(1, 4, "\n * Select your option : ");
}

// perform options
void clsTransHistoryMenu::_PerformOption(enTransMenuOptions option) {
    switch (option) {
        case enTransMenuOptions::LIST_ALL: {
            _ListAll();
            break;
        }
        case enTransMenuOptions::LIST_BORROWED: {
            _ListBorrowed();
            break;
        }
        case enTransMenuOptions::LIST_RETURNED: {
            _ListReturned();
            break;
        }
        case enTransMenuOptions::EXIT: {
            break;
        }
    }
    // pause screen after each func finished
    if (option != enTransMenuOptions::EXIT) {
        // this trick just to pause termux screen until the user Contenu
        cout << " \n\n\n\n\n\nEnter any Key to Contenu ... " << endl;
        char Contenue = clsInputValidate::ReadChar();
        Contenue = ' ';
        cout << Contenue << endl;
    }
}
// List all
void clsTransHistoryMenu::_ListAll() {
    system("clear");
    cout << "soon";
}
// list borrowed
void clsTransHistoryMenu::_ListBorrowed() {
    system("clear");
    cout << "soon";
}
// list returned
void clsTransHistoryMenu::_ListReturned() {
    system("clear");
    cout << "soon";
}

// trans hustory screen
void clsTransHistoryMenu::TransHistoryMenuScreen() {
    enTransMenuOptions option;
    do {
        _PrintNenu();
        option = _GetUserChoice();
        _PerformOption(option);
    } while (option != enTransMenuOptions::EXIT);
}
