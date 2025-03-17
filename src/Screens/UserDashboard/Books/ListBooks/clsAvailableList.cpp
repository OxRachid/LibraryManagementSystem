#include "../../../../../headers/Screens/UserDashboard/Books/ListBooks/clsAvailableList.h"
#include "../../../../../headers/Core/clsBook.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// print book data
void clsAvailableList::_PrintBook(clsBook book) {
    short width = 25;
    cout << setfill(' ') << Colors::GetCyan() << left << setw(width - 16) << book.GetID() << left << setw(width) << book.GetTitle() << left << setw(width) << book.GetAuthor() << left << setw(width) << book.GetISBN() << left << setw(width - 13) << clsDate::ConvertDateToString(book.GetPublicationDate()) << left << setw(width - 15) << book.GetEdition() << left << setw(width - 17) << book.GetTotalCopies() << left << setw(width - 17) << book.GetAvailableCopies() << left << setw(width - 17) << book.GetBorrowedCopies() << Colors::RESET() << endl;
}

// Books list screen
void clsAvailableList::AvailableListScreen() {
    // Get books list from static vector
    const vector<clsBook> &vAvailables = clsBook::GetAvailableBooks();
    PrintHeaderScreen("AVAILABLE LIST", to_string(vAvailables.size()), Colors::Blue, true, 130);
    short width = 25;
    cout << Colors::GetBoldBlue() << setfill(' ') << left << setw(width - 16) << "ID" << left << setw(width) << "Title" << left << setw(width) << "Author" << left << setw(width) << "ISBN" << left << setw(width - 13) << "P-Date" << left << setw(width - 15) << "Edition" << left << setw(width - 17) << "To-cpy" << left << setw(width - 17) << "Av-cpy" << left << setw(width - 17) << "Bo-cpy" << Colors::RESET() << endl;
    cout << Colors::GetBoldBlue() << setw(130) << setfill('-') << "" << Colors::RESET() << endl;
    if (vAvailables.empty()) {
        cout << Colors::GetRed() << "                              No Data Found" << Colors::RESET() << endl;
    } else {
        for (const clsBook &A : vAvailables) {
            _PrintBook(A);
        }
    }
    cout << Colors::GetBoldBlue() << setw(130) << setfill('-') << "" << Colors::RESET() << endl;
}
