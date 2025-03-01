#include "../../../../headers/Screens/Books/ListBooks/clsAllBooksList.h"
#include "../../../../headers/Core/clsBook.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// print book data
void clsAllBooksList::_PrintBook(clsBook book) {
    short width = 25;
    cout << setfill(' ') << Colors::GetBoldBlue() << left << setw(width - 16) << book.GetID() << left << setw(width) << book.GetTitle() << left << setw(width) << book.GetAuthor() << left << setw(width) << book.GetISBN() << left << setw(width - 13) << clsDate::ConvertDateToString(book.GetPublicationDate()) << left << setw(width - 15) << book.GetEdition() << left << setw(width - 17) << book.GetTotalCopies() << left << setw(width - 17) << book.GetAvailableCopies() << left << setw(width - 17) << book.GetBorrowedCopies() << Colors::RESET() << endl;
}

// Books list screen
void clsAllBooksList::AllBooksListScreen() {
    // Get books list from static vector
    const vector<clsBook> &vBooksList = clsBook::GetBooksList();
    PrintHeaderScreen("ALL BOOKS LIST", to_string(vBooksList.size()), Colors::Yellow, true, 130);
    short width = 25;
    cout << Colors::GetYellow() << setfill(' ') << left << setw(width - 16) << "ID" << left << setw(width) << "Title" << left << setw(width) << "Author" << left << setw(width) << "ISBN" << left << setw(width - 13) << "P-Date" << left << setw(width - 15) << "Edition" << left << setw(width - 17) << "To-cpy" << left << setw(width - 17) << "Av-cpy" << left << setw(width - 17) << "Bo-cpy" << Colors::RESET() << endl;
    cout << Colors::GetYellow() << setw(130) << setfill('-') << "" << Colors::RESET() << endl;
    if (vBooksList.empty()) {
        cout << Colors::GetRed() << "                                   No Data Found" << Colors::RESET() << endl;
    } else {
        for (const clsBook &B : vBooksList) {
            _PrintBook(B);
        }
    }
    cout << Colors::GetYellow() << setw(130) << setfill('-') << "" << Colors::RESET() << endl;
}
