#ifndef CLSTRACKBOOKS_H
#define CLSTRACKBOOKS_H

#include "../../../Core/clsBook.h"
#include "../../../Core/clsTransaction.h"
#include "../../clsScreen.h"
class clsTrackBooks : protected clsScreen {
    private:
        // display trans detailes
        static void _DisplayTransDetailes(clsTransaction trans);
        // print book data
        static void _PrintBookData(clsBook book);
        // Get targetmember
        static clsBook _GetTargetBook();
        // Print transactions history
        static void _ShowTransHistory(int bookID);

    public:
        // track members screen
        static void TrackBooksScreen();
};

#endif // !CLSTRACKBOOKS_H
