#include "../../../../headers/Screens/UserDashboard/Members/clsMemberManage.h"
#include "../../../../headers/Lib/clsInputValidate.h"
#include "../../../../headers/Screens/UserDashboard/Members/ListMembers/clsListMembersMenu.h"
#include "../../../../headers/Screens/UserDashboard/Members/clsAddNewMember.h"
#include "../../../../headers/Screens/UserDashboard/Members/clsDeleteMember.h"
#include "../../../../headers/Screens/UserDashboard/Members/clsFindMember.h"
#include "../../../../headers/Screens/UserDashboard/Members/clsResetMembers.h"
#include "../../../../headers/Screens/UserDashboard/Members/clsUpdateMember.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// get user choice
clsMemberManage::enMenuOptions clsMemberManage::_GetUserChoice() {
    return (enMenuOptions)clsInputValidate::Readnumberbetween(1, 7, "\n * Select Your Option : ");
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
    cout << setw(width) << setfill(' ') << " " << left << "[6] Reset" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[7] Main Menu" << endl;
    cout << Colors::GetMagenta() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
// List members screen
void clsMemberManage::_ListMembers() {
    system("clear");
    clsListMembersMenu::ListMembersMenuScreen();
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
// Reset members screen
void clsMemberManage::_Reset() {
    system("clear");
    clsReset::ResetScreen();
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
        case enMenuOptions::RESET: {
            _Reset();
            break;
        }
        case enMenuOptions::EXIT: {
            break;
        }
        default:
            break;
    }
    // pause screen after each func finished
    if (option != enMenuOptions::EXIT && option != enMenuOptions::LIST_MEMBERS) {
        // this trick just to pause termux screen until the user Contenu
        cout << " \n\n\n\n\n\nEnter any Key to Contenu ... " << endl;
        char Contenue = clsInputValidate::ReadChar();
        Contenue = ' ';
        cout << Contenue << endl;
    }
}

// Member manage screen
void clsMemberManage::MemberManageScreen() {
    // check permisdions
    if (!CheckPermissionRights(clsUser::ePermissionFunc::MEMBER_MANAGE)) {
        return;
    }

    enMenuOptions option;
    do {
        _DisplayMenu();
        option = _GetUserChoice();
        _PerformMenuOption(option);
    } while (option != enMenuOptions::EXIT);
}
