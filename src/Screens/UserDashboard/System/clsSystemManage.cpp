#include "../../../../headers/Screens/UserDashboard/System/clsSystemManage.h"
#include "../../../../headers/Lib/clsInputValidate.h"
#include "../../../../headers/Screens/UserDashboard/System/clsStatistics.h"
#include "../../../../headers/Screens/UserDashboard/System/clsUpdateSystem.h"
#include "../../../../headers/Screens/UserDashboard/System/clsUserChangePass.h"
#include <asm-generic/errno.h>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// print menu
void clsSystemManage::_PrintMenu() {
    system("clear");
    PrintHeaderScreen("SYSTEM MANAGE MENU", "🔧", Colors::Cyan);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();
    PrintHeaderScreen("Menu", "🔦", Colors::Cyan, false);
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] Update system" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] Statistics" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] Change Password" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[4] Exit" << endl;
    cout << Colors::GetCyan() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
// get user choice
clsSystemManage::eMenuOptions clsSystemManage::_GetUserChoice() {
    return static_cast<eMenuOptions>(clsInputValidate::Readnumberbetween(1, 4, "\n * select your option : "));
}
// Perform option
void clsSystemManage::_PerformOption(eMenuOptions option) {
    switch (option) {
        case eMenuOptions::UPDATE_SYSTEM: {
            _UpdateSystem();
            break;
        }
        case eMenuOptions::STATISTICS: {
            _Statistics();
            break;
        }
        case eMenuOptions::CHANGE_PASSWORD: {
            _ChangePassword();
            break;
        }
        case eMenuOptions::EXIT: {
            break;
        }
        default:
            break;
    }
    // pause screen after each func finished
    if (option != eMenuOptions::EXIT) {
        // this trick just to pause termux screen until the user Contenu
        cout << " \n\n\n\n\n\nEnter any Key to Contenu ... " << endl;
        char Contenue = clsInputValidate::ReadChar();
        Contenue = ' ';
        cout << Contenue << endl;
    }
}
// UPDATE_SYSTEM
void clsSystemManage::_UpdateSystem() {
    system("clear");
    clsUpdateSystem::UpdateSystemScreen();
}

// STATISTICS
void clsSystemManage::_Statistics() {
    system("clear");
    clsStatistics::StatisticsScreen();
}
// CHANGE_PASSWORD
void clsSystemManage::_ChangePassword() {
    system("clear");
    clsUserChangePass::UserChangePassScreen();
}

// system manage
void clsSystemManage::SystemManageScreen() {
    eMenuOptions Option;
    do {
        _PrintMenu();
        Option = _GetUserChoice();
        _PerformOption(Option);
    } while (Option != eMenuOptions::EXIT);
}
