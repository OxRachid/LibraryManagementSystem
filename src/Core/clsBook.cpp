#include "../../headers/Core/clsBook.h"
#include "../../headers/Lib/clsString.h"
#include "../../headers/Lib/clsUtil.h"
#include "../../headers/Lib/constants.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string BooksListFile = "data/BooksList.txt";

// Initialize the static vector
vector<clsBook> clsBook::_vBooksList = {};

// constructor parameter
clsBook::clsBook(enMode mode, int id, string title, string author, string ISBN, short edition, string genre, clsDate date, short totatcopies, short availablecopies, short borrowedcopies)
    : _Mode(mode),
      _ID(id),
      _Title(title),
      _Author(author),
      _ISBN(ISBN),
      _Edition(edition),
      _Genre(genre),
      _PublicationDate(date),
      _TotalCopies(totatcopies),
      _AvailableCopies(availablecopies),
      _BorrowedCopies(borrowedcopies) {}

// Copy constructor
clsBook::clsBook(const clsBook &other) {
    _Mode = other._Mode;
    _ID = other._ID;
    _Title = other._Title;
    _Author = other._Author;
    _ISBN = other._ISBN;
    _Edition = other._Edition;
    _Genre = other._Genre;
    _PublicationDate = other._PublicationDate;
    _TotalCopies = other._TotalCopies;
    _AvailableCopies = other._AvailableCopies;
    _BorrowedCopies = other._BorrowedCopies;
}

// Assignment operator
clsBook &clsBook::operator=(const clsBook &other) {
    if (this != &other) { // Check for self-assignment
        _Mode = other._Mode;
        _ID = other._ID;
        _Title = other._Title;
        _Author = other._Author;
        _ISBN = other._ISBN;
        _Edition = other._Edition;
        _Genre = other._Genre;
        _PublicationDate = other._PublicationDate;
        _TotalCopies = other._TotalCopies;
        _AvailableCopies = other._AvailableCopies;
        _BorrowedCopies = other._BorrowedCopies;
    }
    return *this;
}

// setter
void clsBook::SetTitle(string title) {
    _Title = title;
}
void clsBook::SetAuthor(string author) {
    _Author = author;
}
void clsBook::SetISBN(string ISBN) {
    _ISBN = ISBN;
}
void clsBook::SetGenre(string genre) {
    _Genre = genre;
}
void clsBook::SetPublicationDate(clsDate date) {
    _PublicationDate = date;
}
void clsBook::SetEdition(short edition) {
    _Edition = edition;
}
void clsBook::SetTotalCopies(short totatcopies) {
    _TotalCopies = totatcopies;
}
void clsBook::SetAvailableCopies(short availablecopies) {
    _AvailableCopies = availablecopies;
}
void clsBook::SetBorrowedCopies(short borrowedcopies) {
    _BorrowedCopies = borrowedcopies;
}
// getter
int clsBook::GetID() const {
    return _ID;
}
string clsBook::GetTitle() const {
    return _Title;
}
string clsBook::GetAuthor() const {
    return _Author;
}
string clsBook::GetISBN() const {
    return _ISBN;
}
string clsBook::GetGenre() const {
    return _Genre;
}
clsDate clsBook::GetPublicationDate() const {
    return _PublicationDate;
}
short clsBook::GetEdition() const {
    return _Edition;
}
short clsBook::GetTotalCopies() const {
    return _TotalCopies;
}
short clsBook::GetAvailableCopies() const {
    return _AvailableCopies;
}
short clsBook::GetBorrowedCopies() const {
    return _BorrowedCopies;
}

int clsBook::TotalBooks_Size() {
    return _vBooksList.size();
}
int clsBook::AvailableBooks_Size() {
    vector<clsBook> vAvailables = GetAvailableBooks();
    return vAvailables.size();
}

// is empty
bool clsBook::isEmpty() {
    return (_Mode == enMode::EmptyMode);
}

// Get empty book obj
clsBook clsBook::_GetEmptyBookObj() {
    return clsBook(enMode::EmptyMode, // Mode
        DEFAULT_INT,                  // ID
        EMPTY_STR,                    // Title
        EMPTY_STR,                    // Author
        EMPTY_STR,                    // ISBN
        DEFAULT_INT,                  // Edition
        EMPTY_STR,                    // Genre
        DEFAULT_DATE,                 // PublicationDate
        DEFAULT_INT,                  // TotalCopies
        DEFAULT_INT,                  // AvailableCopies
        DEFAULT_INT                   // BorrowedCopies
    );
}

// Get empty book obj
clsBook clsBook::GetAddNewBookObj(string ISBN) {
    // set Book Id
    int ID = clsUtil::GenerateNumber(5);
    while (isBookExist(ID)) {
        ID = clsUtil::GenerateNumber(5);
    }

    return clsBook(enMode::AddBookMode, // Mode
        ID,                             // ID
        EMPTY_STR,                      // Title
        EMPTY_STR,                      // Author
        ISBN,                           // ISBN
        1,                              // Edition
        EMPTY_STR,                      // Genre
        clsDate(),                      // PublicationDate
        DEFAULT_INT,                    // TotalCopies
        DEFAULT_INT,                    // AvailableCopies
        DEFAULT_INT                     // BorrowedCopies
    );
}

// _Convert Line To Book Record
clsBook clsBook::_LineToBook(string line, string seperator) {
    vector<string> vStr = clsString::Split(line, seperator);
    return clsBook(enMode::UpdateMode, // Mode
        stoi(vStr[0]),                 // ID
        vStr[1],                       // Title
        vStr[2],                       // Author
        vStr[3],                       // ISBN
        stoi(vStr[4]),                 // Edition
        vStr[5],                       // Genre
        clsDate(vStr[6]),              // PublicationDate
        stoi(vStr[7]),                 // TotalCopies
        stoi(vStr[8]),                 // AvailableCopies
        stoi(vStr[9])                  // BorrowedCopies
    );
}

// _Convert book record To line
string clsBook::_BookToLine(string seperator) {
    string line = "";
    line += to_string(_ID) + seperator;
    line += _Title + seperator;
    line += _Author + seperator;
    line += _ISBN + seperator;
    line += to_string(_Edition) + seperator;
    line += _Genre + seperator;
    line += clsDate::ConvertDateToString(_PublicationDate) + seperator;
    line += to_string(_TotalCopies) + seperator;
    line += to_string(_AvailableCopies) + seperator;
    line += to_string(_BorrowedCopies);

    return line;
}

// Find book by  (title, author, edition)
clsBook clsBook::Find(string title, string author, short edition) {
    auto it = find_if(_vBooksList.begin(), _vBooksList.end(), [&](const clsBook &book) {
        return (clsString::FormatForComparison(book._Title) == clsString::FormatForComparison(title) && clsString::FormatForComparison(book._Author) == clsString::FormatForComparison(author) && book._Edition == edition);
    });
    if (it != _vBooksList.end()) {
        return *it;
    }
    return _GetEmptyBookObj();
}

// Find book by  (ISBN)
clsBook clsBook::Find(string BookISBN) {
    auto it = find_if(_vBooksList.begin(), _vBooksList.end(), [&](const clsBook &book) {
        return (clsString::FormatForComparison(book.GetISBN()) == clsString::FormatForComparison(BookISBN));
    });
    if (it != _vBooksList.end()) {
        return *it;
    }
    return _GetEmptyBookObj();
}

// Find book by  (ID)
clsBook clsBook::Find(int BookID) {
    auto it = find_if(_vBooksList.begin(), _vBooksList.end(), [&](const clsBook &book) {
        return book.GetID() == BookID;
    });
    if (it != _vBooksList.end()) {
        return *it;
    }
    return _GetEmptyBookObj();
}

// Find book by title
vector<clsBook> clsBook::GetBooksByTitle(string title) {
    vector<clsBook> vBooks;
    for (clsBook &B : _vBooksList) {
        if (clsString::FormatForComparison(B.GetTitle()) == clsString::FormatForComparison(title)) {
            vBooks.push_back(B);
        }
    }
    return vBooks;
}

// Find book by title
vector<clsBook> clsBook::GetBooksByAuthor(string author) {
    vector<clsBook> vBooks;
    for (clsBook &B : _vBooksList) {
        if (clsString::FormatForComparison(B.GetAuthor()) == clsString::FormatForComparison(author)) {
            vBooks.push_back(B);
        }
    }
    return vBooks;
}

// is book exist (title, author, edition)
bool clsBook::isBookExist(string title, string author, short edition) {
    clsBook book = Find(title, author, edition);
    return (!book.isEmpty());
}
// is book exist (ISBN)
bool clsBook::isBookExist(string ISBN) {
    clsBook book = Find(ISBN);
    return (!book.isEmpty());
}

// is Book ID exist
bool clsBook::isBookExist(int ID) {
    clsBook book = Find(ID);
    return (!book.isEmpty());
}

// Get book list from static  vector
vector<clsBook> &clsBook::GetBooksList() {
    return _vBooksList;
}

// get available books
vector<clsBook> clsBook::GetAvailableBooks() {
    vector<clsBook> vAvailables;
    for (clsBook &b : _vBooksList) {
        if (b.GetAvailableCopies() > 0) {
            vAvailables.push_back(b);
        }
    }
    return vAvailables;
}
// Is book available
bool clsBook::isBookAvailable(int BookID) {
    vector<clsBook> vAvailables = GetAvailableBooks();
    for (clsBook &b : vAvailables) {
        if (b.GetID() == BookID) {
            return true;
        }
    }
    return false;
}

// Load books list data from file
void clsBook::LoadBooksFromFile() {
    // Clear the vector before loading data
    _vBooksList.clear();

    fstream Myfile;
    Myfile.open(BooksListFile, ios::in);
    if (Myfile.is_open()) {
        string line = "";
        while (getline(Myfile, line)) {
            clsBook book = _LineToBook(line);
            _vBooksList.push_back(book);
        }
        Myfile.close();
    }
}
// save books list data to file
void clsBook::SaveBooksToFile() {
    fstream Myfile;
    Myfile.open(BooksListFile, ios::out);
    if (Myfile.is_open()) {
        for (clsBook &book : _vBooksList) {
            Myfile << book._BookToLine() << endl;
        }
        Myfile.close();
    }
}

// add book helper
void clsBook::_AddBook() {
    // Add new book to vector
    _vBooksList.push_back(*this);
    // Save updated list
    SaveBooksToFile();
}

// delete book helper
bool clsBook::_deletebook() {
    // search for book by its Id in vector
    auto it = find_if(_vBooksList.begin(), _vBooksList.end(), [&](const clsBook &book) {
        return (book.GetID() == this->GetID());
    });
    // if book found then delete it from vector
    if (it != _vBooksList.end()) {
        // Remove the book from the vector
        _vBooksList.erase(it);
        return true;
    }
    // book not found
    return false;
}

// delete book
bool clsBook::Delete() {
    // Delete book from vector
    if (_deletebook()) {
        // save updated vector to file
        SaveBooksToFile();
        // Erase data from original book obj
        *this = _GetEmptyBookObj();
        return true;
    }
    //  book not found
    return false;
}

// Update book helper
void clsBook::_Updatebook() {
    // update book in vector
    auto it = find_if(_vBooksList.begin(), _vBooksList.end(), [&](clsBook &book) {
        return book.GetID() == this->GetID();
    });

    // if the target book found we replaced it with new version
    if (it != _vBooksList.end()) {
        *it = *this;
        // save updated vector to file
        SaveBooksToFile();
    }
}

// Borrow book to member
bool clsBook::Borrow() {
    if (_TotalCopies < 1 || _AvailableCopies < 1) {
        return false;
    }
    // decrease availablecopies
    --_AvailableCopies;
    // increase borrowedcopies
    ++_BorrowedCopies;
    // Update book in vector and save it to file
    _Updatebook();
    return true;
}

// Return book to member
bool clsBook::ReturnBook() {
    if (_BorrowedCopies < 1) {
        return false;
    }
    // increase availablecopies
    ++_AvailableCopies;
    // decrease borrowedcopies
    --_BorrowedCopies;
    // Update book in vector and save it to file
    _Updatebook();
    return true;
}

// Reset books
bool clsBook::ResetBooks() {
    if (!_vBooksList.empty()) {
        for (clsBook &book : _vBooksList) {
            book.SetAvailableCopies(book.GetTotalCopies());
            book.SetBorrowedCopies(0);
        }
        // save updated vector to file
        SaveBooksToFile();
        return true;
    }
    return false;
}

// save
clsBook::enSaveMode clsBook::save() {
    switch (_Mode) {
        case enMode::EmptyMode: {
            return enSaveMode::SaveFailed;
            break;
        }
        case enMode::AddBookMode: {
            // ensure changing Addbookmode to updatebookmode befor adding book to vector
            _Mode = enMode::UpdateMode;
            _AddBook();
            return enSaveMode::SaveSuccess;
            break;
        }
        case enMode::UpdateMode: {
            _Updatebook();
            return enSaveMode::SaveSuccess;
            break;
        }
        default:
            break;
    }
    return enSaveMode::SaveFailed;
}
