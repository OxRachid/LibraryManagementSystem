#ifndef CLSFINDBOOK_H
#define CLSFINDBOOK_H

#include "../../Core/clsBook.h"
#include "../clsScreen.h"
#include <vector>
class clsFindBook : protected clsScreen {
    private:
        // enum for Find Options
        enum eFindBy {
            eID = 1,
            eISBN = 2,
            eTitle = 3,
            eAuthor = 4,
            eExit = 5
        };

        // Print single book record founded by ID or eISBN
        static void _PrintSingleBook(clsBook Books);
        // display Book info
        static void _DisplaySingleBookInfo(clsBook book);
        // show books founded by eTitle or eAuthor
        static void _ShowAllBooksTable(vector<clsBook> vBooks);
        // Print book table
        static void _PrintBookTable(clsBook book);

        // print find menu
        static void _PrintFindMenu();
        // Read user choice
        static eFindBy _GetUserChoice();
        // Perform Find Options
        static void _PerformFindOptions(eFindBy option);
        // Find by eID
        static void FindByID();
        // Find by eISBN
        static void FindByISBN();
        // Find by eTitle
        static void FindByTitle();
        // Find by eAuthor
        static void FindByAuthor();

    public:
        // Find Book Screen
        static void FindBookScreen();
};

#endif // !CLSFINDBOOK_H
