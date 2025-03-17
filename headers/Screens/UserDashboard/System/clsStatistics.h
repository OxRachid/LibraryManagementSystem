#ifndef CLSSTATISTICS_H
#define CLSSTATISTICS_H

#include "../../../Core/clsTransaction.h"
#include "../../clsScreen.h"
class clsStatistics : protected clsScreen {
    private:
        // books report
        static void _BooksReport();
        // members report
        static void _MembersReport();
        // Transactions report
        static void _TransactionsReport();
        //  users report
        static void _UsersReport();
        // print line percentage
        static void _PrintLinePercentage(int Total, float length);

    public:
        // update system
        static void StatisticsScreen();
};

#endif // !CLSSTATISTICS_H
