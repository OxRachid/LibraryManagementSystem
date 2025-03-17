#ifndef CLSLISTLOGINRECORD_H
#define CLSLISTLOGINRECORD_H

#include "../../../Core/clsUser.h"
#include "../../clsScreen.h"
class clsListLoginRecord : protected clsScreen {
    private:
        // Display log data
        static void _DisplayLogData(clsUser::stUserLogin log);

    public:
        // List All UserLogin
        static void ListLoginRecordScreen();
};

#endif // !CLSLISTLOGINRECORD_H
