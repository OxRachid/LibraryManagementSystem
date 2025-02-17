#ifndef CLSPERSON_H
#define CLSPERSON_H

#include <iostream>
#include <string>
using namespace std;

class clsPerson {
    private:
        string _FirstName;
        string _LastName;
        string _Email;
        string _Phone;

    public:
        // constructor parameter
        clsPerson(string firstname, string lastname, string email, string phone);
        // Setter
        void SetFirstName(string firstname);
        void SetLastName(string lastname);
        void SetEmail(string email);
        void SetPhone(string phone);
        // Getter
        string GetFirstName();
        string GetLastName();
        string GetFullName();
        string GetEmail();
        string GetPhone();
};

#endif // !CLSPERSON_H
