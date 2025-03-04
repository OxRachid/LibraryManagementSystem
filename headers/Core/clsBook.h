#ifndef CLSBOOK_H
#define CLSBOOK_H

#include "../Lib/clsDate.h"
#include "../Screens/clsScreen.h"
#include <string>
#include <vector>

class clsBook : protected clsScreen {
    private:
        // Static vector to store all books
        static vector<clsBook> _vBooksList;
        // enum for Obj mode
        enum enMode {
            EmptyMode = 1,
            UpdateMode = 2,
            AddBookMode = 3
        };
        enMode _Mode;
        int _ID = 0;
        string _Title = "";
        string _Author = "";
        string _ISBN = "";
        short _Edition = 1;
        string _Genre = "";
        clsDate _PublicationDate;
        short _TotalCopies = 0;
        short _AvailableCopies = 0;
        short _BorrowedCopies = 0;

        // Get empty book obj
        static clsBook _GetEmptyBookObj();
        // _Convert Line To Book Record
        static clsBook _LineToBook(string line, string seperator = "|");
        // _Convert book record To line
        string _BookToLine(string seperator = "|");
        // add book helper
        void _AddBook();
        // delete book helper
        bool _deletebook();
        // Update book helper
        void _Updatebook();

    public:
        // constructor parameter
        clsBook(enMode mode, int id, string title, string author, string ISBN, short edition, string genre, clsDate date, short totatcopies, short availablecopies, short borrowedcopies);
        // Copy constructor
        clsBook(const clsBook &other);
        // Assignment operator
        clsBook &operator=(const clsBook &other);

        // setter
        void SetTitle(string title);
        void SetAuthor(string author);
        void SetISBN(string isbn);
        void SetGenre(string genre);
        void SetPublicationDate(clsDate date);
        void SetEdition(short edition);
        void SetTotalCopies(short totatcopies);
        void SetAvailableCopies(short availablecopies);
        void SetBorrowedCopies(short borrowedcopies);
        // getter
        int GetID() const;
        string GetTitle() const;
        string GetAuthor() const;
        string GetISBN() const;
        string GetGenre() const;
        clsDate GetPublicationDate() const;
        short GetEdition() const;
        short GetTotalCopies() const;
        short GetAvailableCopies() const;
        short GetBorrowedCopies() const;
        // is empty
        bool isEmpty();

        // get add new book obj
        static clsBook GetAddNewBookObj(string ISBN);
        // Find book by  (title, author, edition)
        static clsBook Find(string title, string author, short edition);
        // Find book by  (ISBN)
        static clsBook Find(string BookISBN);
        // Find book by  (ID)
        static clsBook Find(int BookID);
        // Find book by title
        static vector<clsBook> GetBooksByTitle(string title);
        // Find book by title
        static vector<clsBook> GetBooksByAuthor(string author);
        // is book exist (title, author, edition)
        static bool isBookExist(string title, string author, short edition);
        // is book exist (ISBN)
        static bool isBookExist(string ISBN);
        // is Book ID exist
        static bool isBookExist(int ID);
        // Load books list data from file
        static void LoadBooksFromFile();
        // save books list data to file
        static void SaveBooksToFile();
        // Get book list from static  vector
        static vector<clsBook> &GetBooksList();
        // get available books
        static vector<clsBook> GetAvailableBooks();
        // Is book available
        static bool isBookAvailable(int BookID);
        // enum for saving mode
        enum enSaveMode {
            SaveFailed = 1,
            SaveSuccess = 2
        };
        // save
        enSaveMode save();
        // delete book
        bool Delete();
        // Borrow book to member
        bool Borrow();
        // Return book to member
        bool ReturnBook();
        // Reset books
        static bool ResetBooks();
};

#endif // !CLSBOOK_H
