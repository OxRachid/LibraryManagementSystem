#include "../../headers/Screens/clsWhoAreYou.h"
#include "../../headers/Lib/clsInputValidate.h"
#include "../../headers/Screens/MemberDashboard/clsMemberAuth.h"
#include "../../headers/Screens/UserDashboard/clsUserLogin.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

// print menu
void clsWhoAreYou::_PrintMenu() {
    system("clear");
    PrintHeaderScreen("Who Are You", "❓", Colors::Magenta, false);
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] Admin" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] Member" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] Exit" << endl;
    cout << Colors::GetMagenta() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
// Get user choice
clsWhoAreYou::eLoginOptions clsWhoAreYou::_GetUserChoice() {
    return static_cast<eLoginOptions>(clsInputValidate::Readnumberbetween(1, 3, "\n * selec your option : "));
}
// perform option
void clsWhoAreYou::_PerformOption(eLoginOptions option) {
    switch (option) {
        case eLoginOptions::USER_LOGIN: {
            _UserLogin();
            exit(0);
            break;
        }
        case eLoginOptions::MEMBER_AUTH: {
            _MemberAuth();
            break;
        }
        case eLoginOptions::EXIT: {
            break;
        }
    }
}
// user login screen
void clsWhoAreYou::_UserLogin() {
    system("clear");
    while (true) {
        if (!clsUserLogin::UserLogin()) {
            break;
        }
    }
}
// member login screen
void clsWhoAreYou::_MemberAuth() {
    system("clear");
    clsMemberAuth::MemberAuthScreen();
}

// Who are you screen
void clsWhoAreYou::WhoAreYouScreen() {
    eLoginOptions option;
    do {
        _PrintMenu();
        option = _GetUserChoice();
        _PerformOption(option);
    } while (option != eLoginOptions::EXIT);
}
