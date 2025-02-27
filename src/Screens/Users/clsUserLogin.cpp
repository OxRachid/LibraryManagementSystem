#include "../../../headers/Screens/Users/clsUserLogin.h"
#include "../../../headers/Core/global.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include "../../../headers/Screens/clsMainMenuScreen.h"
#include <cstdlib>
#include <iostream>
using namespace std;

bool clsUserLogin::dataleaded = false;

void clsUserLogin::UserLogin() {
    system("clear");
    PrintHeaderScreen("USER LOGIN", "🔏", Colors::Blue);
    cout << "\n\n\n";

    if (!dataleaded) {
        // load Users from file
        clsUser::LoadUsersFromFile();
        // lead UsersLogin list
        clsUser::LoadUsersLogin();
    }

    string username, password;
    bool CheckLogin = false;
    do {
        if (CheckLogin) {
            system("clear");
            PrintHeaderScreen("USER LOGIN", "🔏", Colors::Blue);
            cout << "\n\n\n";
            cout << Colors::GetRed() << " [ username or password is incorrect ]\n" << Colors::RESET() << endl;
        }
        username = clsInputValidate::ReadString(" ⊙ username : ");
        password = clsInputValidate::ReadString(" ⊙ password : ");
        CurrUser = clsUser::Find(username, password);
        CheckLogin = CurrUser.isEmpty();
    } while (CheckLogin);
    // create log for login activity
    CurrUser.LogUserLogin();
    // after login is succes we go to admin dashboard
    clsMainMenuScreen::MainMenuScreen();
}
