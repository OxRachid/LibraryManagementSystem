#include "../../../headers/Screens/Members/clsMemberManage.h"
#include "../../../headers/Core/clsMember.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include "../../../headers/Screens/Members/clsAddNewMember.h"
#include "../../../headers/Screens/Members/clsDeleteMember.h"
#include "../../../headers/Screens/Members/clsFindMember.h"
#include "../../../headers/Screens/Members/clsListMembers.h"
#include "../../../headers/Screens/Members/clsUpdateMember.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// get user choice
clsMemberManage::enMenuOptions clsMemberManage::_GetUserChoice() {
    return (enMenuOptions)clsInputValidate::Readnumberbetween(1, 6, "\n * Select Your Option : ");
}
// Print Member manage menu
void clsMemberManage::_DisplayMenu() {
    system("clear");
    PrintHeaderScreen("MEMBERS MANAGE MENU SCREEN", "👥", Colors::Magenta);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();
    PrintHeaderScreen("Members Manage Menu", "👥", Colors::Magenta, false);
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] List Members" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] Add Member" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] Delete Member" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[4] Update Member" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[5] Find Member" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[6] Main Menu" << endl;
    cout << Colors::GetMagenta() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
// List members screen
void clsMemberManage::_ListMembers() {
    system("clear");
    clsListMembers::ListMembersScreen();
}
// Add members screen
void clsMemberManage::_AddNewMember() {
    system("clear");
    clsAddNewMember::AddNewMemberScreen();
}
// Delete Members screen
void clsMemberManage::_DeleteMember() {
    system("clear");
    clsDeleteMember::DeleteMemberScreen();
}
// update members screen
void clsMemberManage::_UpdateMember() {
    system("clear");
    clsUpdateMember::UpdateMemberScreen();
}
// Find members screen
void clsMemberManage::_FindMember() {
    system("clear");
    clsFindMember::FindMemberScreen();
}

// perform member manage options
void clsMemberManage::_PerformMenuOption(enMenuOptions option) {
    switch (option) {
        case enMenuOptions::LIST_MEMBERS: {
            _ListMembers();
            break;
        }
        case enMenuOptions::ADD_MEMBER: {
            _AddNewMember();
            break;
        }
        case enMenuOptions::DELETE_MEMBER: {
            _DeleteMember();
            break;
        }
        case enMenuOptions::UPDATE_MEMBER: {
            _UpdateMember();
            break;
        }
        case enMenuOptions::FIND_MEMBER: {
            _FindMember();
            break;
        }
        case enMenuOptions::EXIT: {
            break;
        }
        default:
            break;
    }
    // pause screen after each func finished
    if (option != enMenuOptions::EXIT) {
        // this trick just to pause termux screen until the user Contenu
        cout << " \n\n\n\n\n\nEnter any Key to Contenu ... " << endl;
        char Contenue = clsInputValidate::ReadChar();
        Contenue = ' ';
        cout << Contenue << endl;
    }
}

// Member manage screen
void clsMemberManage::MemberManageScreen() {
    enMenuOptions option;
    do {
        _DisplayMenu();
        option = _GetUserChoice();
        _PerformMenuOption(option);
    } while (option != enMenuOptions::EXIT);
}
