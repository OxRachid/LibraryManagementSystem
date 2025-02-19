#include "../../../headers/Screens/Members/clsListMembers.h"
#include "../../../headers/Core/clsMember.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Display Member data
void clsListMembers::_DisplayMemberData(clsMember member) {
    short width = 14;
    cout << Colors::GetBlue() << setfill(' ') << left << setw(width) << member.GetFullName() << left << setw(width - 5) << member.MemberRoleToString() << left << setw(width - 4) << member.GetAccountNumber() << left << setw(width) << member.GetPassword() << left << setw(width - 3) << member.GetTotalBorrowedBooks() << left << setw(width - 6) << member.AccountStatusToString() << Colors::RESET() << endl;
}

// list All Members
void clsListMembers::_ListAllMembers() {
    system("clear");
    // get members list from static vector
    const vector<clsMember> &vMembers = clsMember::GetMembersList();
    PrintHeaderScreen("All Members", to_string(vMembers.size()), Colors::Cyan, true);
    short width = 14;
    cout << Colors::GetCyan() << setfill(' ') << left << setw(width) << "Fullname" << left << setw(width - 5) << "Role" << left << setw(width - 4) << "A-Number" << left << setw(width) << "Password" << left << setw(width - 3) << "TB-Books" << left << setw(width - 6) << "Status" << Colors::RESET() << endl;
    cout << Colors::GetCyan() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
    if (vMembers.empty()) {
        cout << Colors::GetRed() << "          No Data Found" << Colors::RESET() << endl;
    } else {
        for (const clsMember &M : vMembers) {
            _DisplayMemberData(M);
        }
    }
    cout << Colors::GetCyan() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
// List only students
void clsListMembers::_ListStudents() {
    system("clear");
    // get students list from static vector
    const vector<clsMember> vStudents = clsMember::GetSpecificMembersList();
    PrintHeaderScreen("Students", to_string(vStudents.size()), Colors::Magenta, true);
    short width = 14;
    cout << Colors::GetMagenta() << setfill(' ') << left << setw(width) << "Fullname" << left << setw(width - 5) << "Role" << left << setw(width - 4) << "A-Number" << left << setw(width) << "Password" << left << setw(width - 3) << "TB-Books" << left << setw(width - 6) << "Status" << Colors::RESET() << endl;
    cout << Colors::GetMagenta() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
    if (vStudents.empty()) {
        cout << Colors::GetRed() << "          No Data Found" << Colors::RESET() << endl;
    } else {
        for (const clsMember &M : vStudents) {
            _DisplayMemberData(M);
        }
    }
    cout << Colors::GetMagenta() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
// List only Teachers
void clsListMembers::_ListTeachers() {
    system("clear");
    // get members list from static vector
    const vector<clsMember> vTeachers = clsMember::GetSpecificMembersList(false);
    PrintHeaderScreen("Teachers", to_string(vTeachers.size()), Colors::Yellow, true);
    short width = 14;
    cout << Colors::GetYellow() << setfill(' ') << left << setw(width) << "Fullname" << left << setw(width - 5) << "Role" << left << setw(width - 4) << "A-Number" << left << setw(width) << "Password" << left << setw(width - 3) << "TB-Books" << left << setw(width - 6) << "Status" << Colors::RESET() << endl;
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
    if (vTeachers.empty()) {
        cout << Colors::GetRed() << "          No Data Found" << Colors::RESET() << endl;
    } else {
        for (const clsMember &M : vTeachers) {
            _DisplayMemberData(M);
        }
    }
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}

void clsListMembers::_PrintMenu() {
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
void clsListMembers::_HandleUserChoice(enListOptions option) {
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
void clsListMembers::ListMembersScreen() {
    enListOptions option;
    do {
        _PrintMenu();
        option = (enListOptions)clsInputValidate::Readnumberbetween(1, 4, "\n * Select Your Option : ");
        _HandleUserChoice(option);
    } while (option != enListOptions::EXIT);
}
