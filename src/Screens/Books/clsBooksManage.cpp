#include "../../../headers/Screens/Books/clsBooksManage.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include "../../../headers/Screens/Books/ListBooks/clsListMenu.h"
#include "../../../headers/Screens/Books/clsAddNewBook.h"
#include "../../../headers/Screens/Books/clsDeleteBook.h"
#include "../../../headers/Screens/Books/clsFindBook.h"
#include "../../../headers/Screens/Books/clsResetBooks.h"
#include "../../../headers/Screens/Books/clsUpdateBook.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// get user choice
clsBooksManage::eMenuOptions clsBooksManage::_GetUserChoice() {
    return (eMenuOptions)clsInputValidate::Readnumberbetween(1, 7, "\n * Select Your Option : ");
}

// print books menu
void clsBooksManage::_PrintBooksManageMenu() {
    system("clear");
    PrintHeaderScreen("BOOK MANAGE SCREEN", "📖", Colors::Blue);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();
    PrintHeaderScreen("Menu", "📋", Colors::Blue, false);
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] List Books" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] Add Book" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] Remove Book" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[4] Update Book" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[5] Find Book" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[6] Reset" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[7] Main Menu" << endl;
    cout << Colors::GetBlue() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}

// Perform Books manage options
void clsBooksManage::_PerformBooksManageOptions(eMenuOptions options) {
    switch (options) {
        case eMenuOptions::LIST_BOOKS: {
            _ListBooksScreen();
            break;
        }
        case eMenuOptions::ADD_BOOK: {
            _AddBookScreen();
            break;
        }
        case eMenuOptions::REMOVE_BOOK: {
            _RemoveBookScreen();
            break;
        }
        case eMenuOptions::UPDATE_BOOK: {
            _UpdateBookScreen();
            break;
        }
        case eMenuOptions::FIND_BOOK: {
            _FindBookScreen();
            break;
        }
        case eMenuOptions::RESET: {
            _ResetBookScreen();
            break;
        }
        case eMenuOptions::MAINMENU: {
            break;
        }
    }

    // pause screen after each func finished
    if (options != eMenuOptions::MAINMENU) {
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

// RESET
void clsBooksManage::_ResetBookScreen() {
    system("clear");
    clsResetBooks::ResetBooksScreen();
}

// books manage screen
void clsBooksManage::BooksManageScreen() {

    // check permisdions
    if (!CheckPermissionRights(clsUser::ePermissionFunc::BOOK_MANAGE)) {
        return;
    }

    eMenuOptions Option;
    do {
        _PrintBooksManageMenu();
        Option = _GetUserChoice();
        _PerformBooksManageOptions(Option);
    } while (Option != eMenuOptions::MAINMENU);
}
