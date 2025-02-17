#include "../../../headers/Screens/Books/clsFindBook.h"
#include "../../../headers/Core/clsBook.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <linux/limits.h>
#include <string>
#include <vector>
using namespace std;

// get user choice
clsFindBook::eFindBy clsFindBook::_GetUserChoice() {
    return (eFindBy)clsInputValidate::Readnumberbetween(1, 5, "\n * Select Your Option : ");
}

// display single Book info
void clsFindBook::_DisplaySingleBookInfo(clsBook book) {
    cout << endl;
    PrintHeaderScreen("[Book Data]", "📘", Colors::Blue, false, 41);
    cout << Colors::GetBlue() << left << setw(20) << setfill(' ') << " ID" << " : " << book.GetID() << endl;
    cout << left << setw(20) << " Title" << " : " << book.GetTitle() << endl;
    cout << left << setw(20) << " Author" << " : " << book.GetAuthor() << endl;
    cout << left << setw(20) << " ISBN" << " : " << book.GetISBN() << endl;
    cout << left << setw(20) << " Edition" << " : " << book.GetEdition() << endl;
    cout << left << setw(20) << " Genre" << " : " << book.GetGenre() << endl;
    cout << left << setw(20) << " P-Date" << " : " << clsDate::ConvertDateToString(book.GetPublicationDate()) << endl;
    cout << left << setw(20) << " Total Copies" << " : " << book.GetTotalCopies() << endl;
    cout << left << setw(20) << " Available Copies" << " : " << book.GetAvailableCopies() << endl;
    cout << left << setw(20) << " Borrowed Copies" << " : " << book.GetBorrowedCopies() << endl;
    cout << setw(41) << setfill('-') << "" << Colors::RESET() << endl;
}

// Print single book record founded by ID or eISBN
void clsFindBook::_PrintSingleBook(clsBook book) {
    if (!book.isEmpty()) {
        _DisplaySingleBookInfo(book);
        cout << Colors::GetGreen() << "\n [ The Book Found ]" << Colors::RESET() << endl;
    } else {
        cout << Colors::GetRed() << "\n [ The Book Not Found ]" << Colors::RESET() << endl;
    }
}

// Print book table
void clsFindBook::_PrintBookTable(clsBook book) {
    short width = 25;
    cout << setfill(' ') << Colors::GetBoldBlue() << left << setw(width - 16) << book.GetID() << left << setw(width) << book.GetTitle() << left << setw(width) << book.GetAuthor() << left << setw(width) << book.GetISBN() << left << setw(width - 13) << clsDate::ConvertDateToString(book.GetPublicationDate()) << left << setw(width - 15) << book.GetEdition() << left << setw(width - 17) << book.GetTotalCopies() << left << setw(width - 17) << book.GetAvailableCopies() << left << setw(width - 17) << book.GetBorrowedCopies() << Colors::RESET() << endl;
}

// show books table founded by eTitle or eAuthor
void clsFindBook::_ShowAllBooksTable(vector<clsBook> vBooks) {
    PrintHeaderScreen("Books with Same Title", to_string(vBooks.size()), Colors::Yellow, false, 130);
    short width = 25;
    cout << Colors::GetBoldYellow() << setfill(' ') << left << setw(width - 16) << "ID" << left << setw(width) << "Title" << left << setw(width) << "Author" << left << setw(width) << "ISBN" << left << setw(width - 13) << "P-Date" << left << setw(width - 15) << "Edition" << left << setw(width - 17) << "To-cpy" << left << setw(width - 17) << "Av-cpy" << left << setw(width - 17) << "Bo-cpy" << Colors::RESET() << endl;
    cout << Colors::GetYellow() << setw(130) << setfill('-') << "" << Colors::RESET() << endl;
    if (vBooks.empty()) {
        cout << Colors::GetRed() << "          No Data Found" << Colors::RESET() << endl;
    } else {
        for (const clsBook &B : vBooks) {
            _PrintBookTable(B);
        }
    }
    cout << Colors::GetYellow() << setw(130) << setfill('-') << "" << Colors::RESET() << endl;
}

// Find by eID
void clsFindBook::FindByID() {
    int id = clsInputValidate::ReadNumber<int>("\n * Enter Book ID : ");
    clsBook book = clsBook::Find(id);
    _PrintSingleBook(book);
}
// Find by eISBN
void clsFindBook::FindByISBN() {
    string ISBN = clsInputValidate::ReadString("\n * Enter Book ISBN : ");
    clsBook book = clsBook::Find(ISBN);
    _PrintSingleBook(book);
}
// Find by eTitle
void clsFindBook::FindByTitle() {
    string title = clsInputValidate::ReadString("\n * Enter Book Title : ");
    vector<clsBook> vBooks = clsBook::GetBooksByTitle(title);
    _ShowAllBooksTable(vBooks);
}

// Find by eAuthor
void clsFindBook::FindByAuthor() {
    string Author = clsInputValidate::ReadString("\n * Enter Book Author : ");
    vector<clsBook> vBooks = clsBook::GetBooksByAuthor(Author);
    _ShowAllBooksTable(vBooks);
}

// Perform Find Options
void clsFindBook::_PerformFindOptions(eFindBy option) {
    switch (option) {
        case eFindBy::eID: {
            FindByID();
            break;
        }
        case eFindBy::eISBN: {
            FindByISBN();
            break;
        }
        case eFindBy::eTitle: {
            FindByTitle();
            break;
        }
        case eFindBy::eAuthor: {
            FindByAuthor();
            break;
        }
        case eFindBy::eExit: {
            break;
        }
        default:
            break;
    }

    // pause screen after each func finished
    if (option != eFindBy::eExit) {
        // this trick just to pause termux screen until the user Contenu
        cout << " \n\n\n\n\n\nEnter any Key to Contenu ... " << endl;
        char Contenue = clsInputValidate::ReadChar();
        Contenue = ' ';
        cout << Contenue << endl;
    }
}

// print find menu
void clsFindBook::_PrintFindMenu() {
    system("clear");
    PrintHeaderScreen("FIND BOOK SCREEN", "🔍", Colors::Cyan);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();
    PrintHeaderScreen("Find By", "📘🔍", Colors::Cyan, false);
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] By ID" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] By ISBN" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] By Title" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[4] By Author" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[5] Exit" << endl;
    cout << Colors::GetCyan() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}

// Find Book Screen
void clsFindBook::FindBookScreen() {
    eFindBy option;
    do {
        _PrintFindMenu();
        option = _GetUserChoice();
        _PerformFindOptions(option);
    } while (option != eFindBy::eExit);
}
