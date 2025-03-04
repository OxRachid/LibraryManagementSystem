#include "../../../headers/Screens/Books/clsResetBooks.h"
#include "../../../headers/Core/clsBook.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iostream>
#include <string>
using namespace std;

// reset members info
void clsResetBooks::ResetBooksScreen() {
    PrintHeaderScreen("RESET", "📍", Colors::Red);
    cout << "\n\n";

    if (clsInputValidate::AskUser("\n * Reset All Books")) {
        if (clsBook::ResetBooks()) {
            cout << Colors::GetGreen() << " [ Reseted Done ]" << Colors::RESET() << endl;
        } else {
            cout << Colors::GetRed() << " [ Reset failed ]" << Colors::RESET() << endl;
        }
    } else {
        cout << Colors::GetRed() << " [ Reset Canceled ]" << Colors::RESET() << endl;
    }
}
