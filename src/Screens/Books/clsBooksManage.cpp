#include "../../../headers/Screens/Books/clsBooksManage.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include "../../../headers/Screens/Books/ListBooks/clsListMenu.h"
#include "../../../headers/Screens/Books/clsAddNewBook.h"
#include "../../../headers/Screens/Books/clsDeleteBook.h"
#include "../../../headers/Screens/Books/clsFindBook.h"
#include "../../../headers/Screens/Books/clsUpdateBook.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// get user choice
clsBooksManage::enBooksManageOptions clsBooksManage::_GetUserChoice() {
    return (enBooksManageOptions)clsInputValidate::Readnumberbetween(1, 6, "\n * Select Your Option : ");
}

// print books menu
void clsBooksManage::_PrintBooksManageMenu() {
    system("clear");
    PrintHeaderScreen("BOOK MANAGE MENU SCREEN", "📖", Colors::Blue);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();
    PrintHeaderScreen("Book Manage Menu", "📋", Colors::Blue, false);
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] List Books" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] Add Book" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] Remove Book" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[4] Update Book" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[5] Find Book" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[6] Main Menu" << endl;
    cout << Colors::GetBlue() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}

// Perform Books manage options
void clsBooksManage::_PerformBooksManageOptions(enBooksManageOptions options) {
    switch (options) {
        case enBooksManageOptions::eListBooks: {
            _ListBooksScreen();
            break;
        }
        case enBooksManageOptions::eAddBook: {
            _AddBookScreen();
            break;
        }
        case enBooksManageOptions::eRemoveBook: {
            _RemoveBookScreen();
            break;
        }
        case enBooksManageOptions::eUpdateBook: {
            _UpdateBookScreen();
            break;
        }
        case enBooksManageOptions::eFindBook: {
            _FindBookScreen();
            break;
        }
        case enBooksManageOptions::eMainMenu: {
            break;
        }
    }

    // pause screen after each func finished
    if (options != enBooksManageOptions::eMainMenu) {
        // this trick just to pause termux screen until the user Contenu
        cout << " \n\n\n\n\n\nEnter any Key to Contenu ... " << endl;
        char Contenue = clsInputValidate::ReadChar();
        Contenue = ' ';
        cout << Contenue << endl;
    }
}

// list all Books
void clsBooksManage::_ListBooksScreen() {
    system("clear");
    clsListMenu::ListMenuScreen();
}
// Add book screen
void clsBooksManage::_AddBookScreen() {
    system("clear");
    clsAddNewBook::AddNewBookScreen();
}
// remove book screen
void clsBooksManage::_RemoveBookScreen() {
    system("clear");
    clsDeleteBook::DeleteBookScreen();
}
// update books
void clsBooksManage::_UpdateBookScreen() {
    system("clear");
    clsUpdateBook::UpdateBookScreen();
}
// find book
void clsBooksManage::_FindBookScreen() {
    system("clear");
    clsFindBook::FindBookScreen();
}

// books manage screen
void clsBooksManage::BooksManageScreen() {
    enBooksManageOptions Option;
    do {
        _PrintBooksManageMenu();
        Option = _GetUserChoice();
        _PerformBooksManageOptions(Option);
    } while (Option != enBooksManageOptions::eMainMenu);
}
