#include "../../../../headers/Screens/UserDashboard/Members/clsResetMembers.h"
#include "../../../../headers/Core/clsMember.h"
#include "../../../../headers/Lib/clsInputValidate.h"
#include <iostream>
#include <string>
using namespace std;

// reset members info
void clsReset::ResetScreen() {
    PrintHeaderScreen("RESET", "📍", Colors::Red);
    cout << "\n\n";

    if (clsInputValidate::AskUser("\n * Reset All Members")) {
        if (clsMember::ResetMembers()) {
            cout << Colors::GetGreen() << " [ Reseted Done ]" << Colors::RESET() << endl;
        } else {
            cout << Colors::GetRed() << " [ Reset failed ]" << Colors::RESET() << endl;
        }
    } else {
        cout << Colors::GetRed() << " [ Reset Canceled ]" << Colors::RESET() << endl;
    }
}
