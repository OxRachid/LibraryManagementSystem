#include "../../headers/Lib/clsPerson.h"
#include <iostream>
#include <string>
using namespace std;

// constructor parameter
clsPerson::clsPerson(string firstname, string lastname, string email, string phone) {
    _FirstName = firstname;
    _LastName = lastname;
    _Email = email;
    _Phone = phone;
}

// Setter
void clsPerson::SetFirstName(string firstname) {
    _FirstName = firstname;
}
void clsPerson::SetLastName(string lastname) {
    _LastName = lastname;
}
void clsPerson::SetEmail(string email) {
    _Email = email;
}
void clsPerson::SetPhone(string phone) {
    _Phone = phone;
}

// Getter
string clsPerson::GetFirstName() {
    return _FirstName;
}
string clsPerson::GetLastName() {
    return _LastName;
}
string clsPerson::GetEmail() {
    return _Email;
}
string clsPerson::GetPhone() {
    return _Phone;
}
string clsPerson::GetFullName() {
    return _FirstName + " " + _LastName;
}
