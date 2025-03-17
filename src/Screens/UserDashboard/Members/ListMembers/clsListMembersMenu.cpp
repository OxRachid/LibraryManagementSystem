#include "../../../../../headers/Screens/UserDashboard/Members/ListMembers/clsListMembersMenu.h"
#include "../../../../../headers/Lib/clsInputValidate.h"
#include "../../../../../headers/Screens/UserDashboard/Members/ListMembers/clsListAll.h"
#include "../../../../../headers/Screens/UserDashboard/Members/ListMembers/clsListStudents.h"
#include "../../../../../headers/Screens/UserDashboard/Members/ListMembers/clsListTeachers.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// list All Members
void clsListMembersMenu::_ListAllMembers() {
    system("clear");
    clsListAll::ListAllMembersScreen();
}
// List only students
void clsListMembersMenu::_ListStudents() {
    system("clear");
    clsListStudents::ListStudentsScreen();
}
// List only Teachers
void clsListMembersMenu::_ListTeachers() {
    system("clear");
    clsListTeachers::ListTeachersScreen();
}

void clsListMembersMenu::_PrintMenu() {
    system("clear");
    PrintHeaderScreen("LIST OPTIONS SCREEN", "📍", Colors::Blue);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();
    PrintHeaderScreen("List By", "📌", Colors::Blue, false);
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] All Members" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] Students" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] Teachers" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[4] Exit" << endl;
    cout << Colors::GetBlue() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}

// list members screen
void clsListMembersMenu::_HandleUserChoice(enListOptions option) {
    switch (option) {
        case enListOptions::ALL_MEMBERS: {
            _ListAllMembers();
            break;
        }
        case enListOptions::ONLY_STUDENTS: {
            _ListStudents();
            break;
        }
        case enListOptions::ONLY_TEACHERS: {
            _ListTeachers();
            break;
        }
        case enListOptions::EXIT: {
            break;
        }
    }
    // pause screen after each func finished
    if (option != enListOptions::EXIT) {
        // this trick just to pause termux screen until the user Contenu
        cout << " \n\n\n\n\n\nEnter any Key to Contenu ... " << endl;
        char Contenue = clsInputValidate::ReadChar();
        Contenue = ' ';
        cout << Contenue << endl;
    }
}

// List Members Screen
void clsListMembersMenu::ListMembersMenuScreen() {
    enListOptions option;
    do {
        _PrintMenu();
        option = (enListOptions)clsInputValidate::Readnumberbetween(1, 4, "\n * Select Your Option : ");
        _HandleUserChoice(option);
    } while (option != enListOptions::EXIT);
}
