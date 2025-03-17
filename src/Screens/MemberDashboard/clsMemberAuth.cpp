#include "../../../headers/Screens/MemberDashboard/clsMemberAuth.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include "../../../headers/Screens/MemberDashboard/clsMemberLogin.h"
#include "../../../headers/Screens/MemberDashboard/clsMemberRegister.h"
#include <iomanip>
#include <iostream>
using namespace std;

// Get user choice
clsMemberAuth::eAuthOptions clsMemberAuth::_GetUserChoice() {
    return static_cast<eAuthOptions>(clsInputValidate::Readnumberbetween(1, 3, "\n * select your option : "));
}
// print menu
void clsMemberAuth::_PrintMenu() {
    system("clear");
    PrintHeaderScreen("LOG IN OR REGISTER", "❓", Colors::Blue, false);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] Log in" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] Register" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] Exit" << endl;
    cout << Colors::GetBlue() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
// perform option
void clsMemberAuth::_PerformOption(eAuthOptions option) {
    switch (option) {
        case eAuthOptions::LOGIN: {
            _LoginScreen();
            break;
        }
        case eAuthOptions::REGISTER: {
            _RegisterScreen();
            break;
        }
        case eAuthOptions::EXIT: {
            break;
        }
        default:
            break;
    }
    // pause screen after each func finished
    if (option != eAuthOptions::EXIT) {
        // this trick just to pause termux screen until the user Contenu
        cout << " \n\n\n\n\n\nEnter any Key to Contenu for log in ... " << endl;
        char Contenue = clsInputValidate::ReadChar();
        Contenue = ' ';
        cout << Contenue << endl;
    }
}
// login screen
void clsMemberAuth::_LoginScreen() {
    system("clear");
    clsMemberLogin::MemberLogin();
}
// register screen
void clsMemberAuth::_RegisterScreen() {
    system("clear");
    clsMemberRegister::MemberRegisterScreen();
}

// handles login or register account functionality
void clsMemberAuth::MemberAuthScreen() {
    eAuthOptions option;
    do {
        _PrintMenu();
        option = _GetUserChoice();
        _PerformOption(option);
    } while (option != eAuthOptions::EXIT);
}
