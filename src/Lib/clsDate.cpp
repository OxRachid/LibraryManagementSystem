#include "../../headers/Lib/clsDate.h"
#include "../../headers/Lib/clsString.h"
#include <asm-generic/siginfo.h>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// constructor definition
clsDate::clsDate() {
    time_t t = time(0);
    tm *now = localtime(&t);

    _Year = now->tm_year + 1900;
    _Mon = now->tm_mon + 1;
    _Day = now->tm_mday;
    _Hour = now->tm_hour;
    _Min = now->tm_min;
    _Sec = now->tm_sec;
}
// constructor parameter (string)
clsDate::clsDate(string strDate) {
    vector<string> vStr = clsString::Split(strDate, "/");
    _Year = stoi(vStr[0]);
    _Mon = stoi(vStr[1]);
    _Day = stoi(vStr[2]);
}
// constructor parameter (shortiger)
clsDate::clsDate(short year, short mon, short day) {
    _Year = year;
    _Mon = mon;
    _Day = day;
}
// constructor parameter (Number of days)
clsDate::clsDate(short TotalDays, short year) {
    _Year = year;
    _Mon = 1;

    short DaysInMonth = 0;
    while (true) {
        DaysInMonth = NumberOfDaysInMonth(_Year, _Mon);
        if (TotalDays > DaysInMonth) {
            TotalDays -= DaysInMonth;
            _Mon++;
        } else {
            _Day = TotalDays;
            break;
        }

        if (_Mon > 12) {
            break;
        }
    }
}

// setter
void clsDate::SetYear(short year) {
    _Year = year;
}
void clsDate::SetMonth(short mon) {
    _Mon = mon;
}
void clsDate::SetDay(short day) {
    _Day = day;
}

// getter
short clsDate::GetYear() {
    return _Year;
}
short clsDate::GetMonth() {
    return _Mon;
}
short clsDate::GetDay() {
    return _Day;
}

// convert date to string (static)
string clsDate::ConvertDateToString(clsDate date) {
    return (to_string(date._Year) + "/" + to_string(date._Mon) + "/" + to_string(date._Day));
}

// convert date to string (static)
string clsDate::ConvertDateToString(short Year, short Month, short Day) {
    return (to_string(Year) + "/" + to_string(Month) + "/" + to_string(Day));
}
// convert date to string (obj)
string clsDate::ConvertDateToString() {
    return clsDate::ConvertDateToString(_Year, _Mon, _Day);
}

// get system date
clsDate clsDate::GetSystemDate() {
    clsDate date;
    time_t t = time(0);
    tm *now = localtime(&t);

    date._Year = now->tm_year + 1900;
    date._Mon = now->tm_mon + 1;
    date._Day = now->tm_mday;
    return date;
}

// get system date in string
string clsDate::GetDateAndTime() {
    clsDate date;
    return ConvertDateToString(date._Year, date._Mon, date._Day) + ", " + to_string(date._Hour) + ":" + to_string(date._Min) + ":" + to_string(date._Sec);
}

// check is validate date (static)
bool clsDate::isValid(short year, short mon, short day) {
    return !(year < 1 || day < 1 || day > clsDate::NumberOfDaysInMonth(year, mon));
}
// check is validate date (object)
bool clsDate::isValid() {
    return clsDate::isValid(_Year, _Mon, _Day);
}

void clsDate::Print() {
    cout << _Year << "/" << _Mon << "/" << _Day << endl;
}

bool clsDate::isLeapYear(short Year) {
    return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

//********** Year ***************
short clsDate::NumberOfDaysInYear(short Year) {
    return (clsDate::isLeapYear(Year) ? 366 : 365);
}
short clsDate::NumberOfDaysInYear() {
    return clsDate::NumberOfDaysInYear(_Year);
}

short clsDate::NumberOfHoursInYear(short Year) {
    return NumberOfDaysInYear(Year) * 24;
}
short clsDate::NumberOfHoursInYear() {
    return clsDate::NumberOfHoursInYear(_Year);
}

short clsDate::NumberOfMinutsInYear(short Year) {
    return NumberOfHoursInYear(Year) * 60;
}
short clsDate::NumberOfMinutsInYear() {
    return clsDate::NumberOfMinutsInYear(_Year);
}

short clsDate::NumberOfSecondsInYear(short Year) {
    return NumberOfMinutsInYear(Year) * 60;
}
short clsDate::NumberOfSecondsInYear() {
    return clsDate::NumberOfSecondsInYear(_Year);
}

//******** Months ***********

short clsDate::NumberOfDaysInMonth(short Year, short Month) {
    if (Month <= 0 || Month > 12)
        return 0;
    short NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? clsDate::isLeapYear(Year) ? 29 : 28 : NumberOfDays[Month - 1];
}
short clsDate::NumberOfDaysInMonth() {
    return clsDate::NumberOfDaysInMonth(_Year, _Mon);
}

short clsDate::NumberOfHoursInMonth(short Year, short Month) {
    return clsDate::NumberOfDaysInMonth(Year, Month) * 24;
}
short clsDate::NumberOfHoursInMonth() {
    return clsDate::NumberOfHoursInMonth(_Year, _Mon);
}

short clsDate::NumberOfMinutsInMonth(short Year, short Month) {
    return clsDate::NumberOfHoursInMonth(Year, Month) * 60;
}
short clsDate::NumberOfMinutsInMonth() {
    return clsDate::NumberOfMinutsInMonth(_Year, _Mon);
}

short clsDate::NumberOfSecondsInMonth(short Year, short Month) {
    return NumberOfMinutsInMonth(Year, Month) * 60;
}
short clsDate::NumberOfSecondsInMonth() {
    return clsDate::NumberOfSecondsInMonth(_Year, _Mon);
}

// Day of week order (static)
short clsDate::DayOfWeekOrder(short Year, short Month, short Day) {
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
// Day of week order (object)
short clsDate::DayOfWeekOrder() {
    return clsDate::DayOfWeekOrder(_Year, _Mon, _Day);
}

// day short name (static)
string clsDate::DayShortName(short IndexOfDay) {
    string DaysName[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return DaysName[IndexOfDay];
}
// day short name (object)
string clsDate::DayShortName() {
    return clsDate::DayShortName(DayOfWeekOrder());
}
// month short name (static)
string clsDate::MonthShortName(short IndexOfMonth) {
    string MonthsName[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return MonthsName[IndexOfMonth - 1];
}
// month short name (static)
string clsDate::MonthShortName() {
    return clsDate::MonthShortName(_Mon);
}

// Print month calander (static)
void clsDate::MonthCalander(short Year, short Month) {
    short NumberOfDays = clsDate::NumberOfDaysInMonth(Year, Month);
    short DayOrder = clsDate::DayOfWeekOrder(Year, Month, 1);
    cout << " ---------------" << clsDate::MonthShortName(Month) << "-----------------" << endl << endl;
    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
    for (short i = 0; i < DayOrder; i++) {
        cout << setw(5) << "";
    }
    for (short i = 1; i <= NumberOfDays; i++) {
        if (DayOrder == 7) {
            cout << endl;
            DayOrder = 0;
        }
        cout << setw(5) << i;
        DayOrder++;
    }
    cout << "\n\n -----------------------------------" << endl;
}
// Print month calander (obj)
void clsDate::MonthCalander() {
    MonthCalander(_Year, _Mon);
}

// Print Year calander (static)
void clsDate::YearCalander(short Year) {
    for (short i = 1; i <= 12; i++) {
        clsDate::MonthCalander(Year, i);
    }
}
// Print Year calander (obj)
void clsDate::YearCalander() {
    YearCalander(_Year);
}

// total days from the begining of year (static)
short clsDate::TotalDaysFromTheBeginingOfYear(short Year, short Month, short Day) {

    short TotalDays = 0;
    for (short i = 1; i < Month; i++) {
        TotalDays += clsDate::NumberOfDaysInMonth(Year, i);
    }
    return TotalDays + Day;
}
// total days from the begining of year (obj)
short clsDate::TotalDaysFromTheBeginingOfYear() {
    return TotalDaysFromTheBeginingOfYear(_Year, _Mon, _Day);
}

// Add days to date
void clsDate::AddDays(short NumberOfDays) {
    // we add total days from the begining of year to NumberOfDays to start counting from first month
    NumberOfDays += TotalDaysFromTheBeginingOfYear(_Year, _Mon, _Day);
    short DaysInMonth = 0;
    _Mon = 1;
    while (true) {
        DaysInMonth = NumberOfDaysInMonth(_Year, _Mon);
        if (NumberOfDays > DaysInMonth) {
            NumberOfDays -= DaysInMonth;
            _Mon++;

            if (_Mon > 12) {
                _Mon = 1;
                _Year++;
            }
        } else {
            _Day = NumberOfDays;
            break;
        }
    }
}

// is date1 befor date2 (static)
bool clsDate::isDate1BeforDate2(clsDate date1, clsDate date2) {
    return (date1._Year < date2._Year) ? true : ((date1._Year == date2._Year) ? ((date1._Mon < date2._Mon) ? true : ((date1._Mon == date2._Mon) ? (date1._Day < date2._Day) : false)) : false);
}
// is date1 befor date2 (obj)
bool clsDate::isDate1BeforDate2(clsDate date2) {
    return isDate1BeforDate2(*this, date2);
}

// is date1 equal date2 (static)
bool clsDate::isDate1EqualDate2(clsDate date1, clsDate date2) {
    return (date1._Year == date2._Year ? (date1._Mon == date2._Mon ? (date1._Day == date2._Day ? true : false) : false) : false);
}
// is date1 equal date2 (obj)
bool clsDate::isDate1EqualDate2(clsDate date2) {
    return isDate1EqualDate2(*this, date2);
}

// is date1 after date2 (static)
bool clsDate::isDate1AfterDate2(clsDate date1, clsDate date2) {
    return !(clsDate::isDate1BeforDate2(date1, date2)) && !(clsDate::isDate1EqualDate2(date1, date2));
}
// is date1 after date2 (obj)
bool clsDate::isDate1AfterDate2(clsDate date2) {
    return isDate1AfterDate2(*this, date2);
}

// is last day in month (static)
bool clsDate::isLastDayInMonth(clsDate date) {
    return (date._Day == clsDate::NumberOfDaysInMonth(date._Year, date._Mon));
}
// is last day in month (obj)
bool clsDate::isLastDayInMonth() {
    return isLastDayInMonth(*this);
}

// is last month in year (static)
bool clsDate::isLastMonthInYear(short month) {
    return (month == 12);
}
// is last month in year (obj)
bool clsDate::isLastMonthInYear() {
    return isLastMonthInYear(_Mon);
}

// swap dates (static)
void clsDate::SwapDates(clsDate &date1, clsDate &date2) {
    clsDate TempDate = date1;
    date1 = date2;
    date2 = TempDate;
}

// Get deffirence in days (static)
short clsDate::DifferenceInDays(clsDate date1, clsDate date2, bool IncludeEndDay) {
    short DeffDays = 0;
    short SwapFlagValue = 1;
    if (!isDate1BeforDate2(date1, date2)) {
        clsDate::SwapDates(date1, date2);
        SwapFlagValue = -1;
    }

    while (clsDate::isDate1BeforDate2(date1, date2)) {
        DeffDays++;
        date1 = clsDate::AddOneDay(date1);
    }
    return (IncludeEndDay) ? ++DeffDays * SwapFlagValue : DeffDays * SwapFlagValue;
}
// Get deffirence in days (obj)
short clsDate::DifferenceInDays(clsDate date2, bool IncludeEndDay) {
    return DifferenceInDays(*this, date2, IncludeEndDay);
}

// increase date by one day (static)
clsDate clsDate::AddOneDay(clsDate date) {
    if (clsDate::isLastDayInMonth(date)) {
        if (clsDate::isLastMonthInYear(date._Mon)) {
            date._Day = 1;
            date._Mon = 1;
            date._Year++;
        } else {
            date._Day = 1;
            date._Mon++;
        }
    } else {
        date._Day++;
    }

    return date;
}
// increase date by one day (obj)
void clsDate::AddOneDay() {
    *this = AddOneDay(*this);
}

// Add x days (static)
clsDate clsDate::AddxDays(clsDate date, short xDays) {
    for (short i = 1; i <= xDays; i++) {
        date = clsDate::AddOneDay(date);
    }
    return date;
}
// Add x days (obj)
void clsDate::AddxDays(short xDays) {
    *this = AddxDays(*this, xDays);
}

// Add one week (static)
clsDate clsDate::AddOneWeek(clsDate date) {
    for (int i = 1; i <= 7; i++) {
        date = clsDate::AddOneDay(date);
    }

    return date;
}
// Add one week (obj)
void clsDate::AddOneWeek() {
    *this = AddOneWeek(*this);
}

// Add x weeks (static)
clsDate clsDate::AddxWeeks(clsDate date, short xWeeks) {
    for (int i = 0; i < xWeeks; i++) {
        date = clsDate::AddOneWeek(date);
    }
    return date;
}
// Add x weeks (obj)
void clsDate::AddxWeeks(short xWeeks) {
    *this = AddxWeeks(*this, xWeeks);
}

// Add one month (static)
clsDate clsDate::AddOneMonth(clsDate date) {
    if (clsDate::isLastMonthInYear(date._Mon)) {
        date._Mon = 1;
        date._Year++;
    } else
        date._Mon++;

    // last check day in date should not exceed max days in the current month
    //  example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
    //  be 28/2/2022
    short NumberOfDays = clsDate::NumberOfDaysInMonth(date._Year, date._Mon);
    if (date._Day > NumberOfDays)
        date._Day = NumberOfDays;

    return date;
}
// Add one month (obj)
void clsDate::AddOneMonth() {
    *this = AddOneMonth(*this);
}
// Add x months (static)
clsDate clsDate::AddxMonths(clsDate date, short xMonths) {
    for (int i = 0; i < xMonths; i++) {
        date = clsDate::AddOneMonth(date);
    }
    return date;
}
// Add x months (obj)
void clsDate::AddxMonth(short xMonths) {
    *this = AddxMonths(*this, xMonths);
}

// Add one year (static)
clsDate clsDate::AddOneYear(clsDate date) {
    date._Year++;
    return date;
}
// Add one year (obj)
void clsDate::AddOneYear() {
    _Year++;
}
// Add x years (static)
clsDate clsDate::AddxYears(clsDate date, short xYears) {
    date._Year += xYears;
    return date;
}
// Add x years (obj)
void clsDate::AddxYears(short xYears) {
    _Year += xYears;
}

// Add one decade (static)
clsDate clsDate::AddOneDecade(clsDate date) {
    date._Year += 10;
    return date;
}
// Add one decade (obj)
void clsDate::AddOneDecade() {
    _Year += 10;
}
// Add x decades (static)
clsDate clsDate::AddxDecades(clsDate date, short xDecades) {
    date._Year += (xDecades * 10);
    return date;
}
// Add x decades (obj)
void clsDate::AddxDecades(short xDecades) {
    _Year += (xDecades * 10);
}

// Add one Century (static)
clsDate clsDate::AddOneCentury(clsDate date) {
    date._Year += 100;
    return date;
}
// Add one Century (obj)
void clsDate::AddOneCentury() {
    _Year += 100;
}

// Add one Millennium (static)
clsDate clsDate::AddOneMillennium(clsDate date) {
    date._Year += 1000;
    return date;
}
// Add one Millennium (obj)
void clsDate::AddOneMillennium() {
    _Year += 1000;
}

// Decrease one day (static)
clsDate clsDate::DecreaseOneDay(clsDate date) {
    if (date._Day == 1) {
        if (date._Mon == 1) {
            date._Mon = 12;
            date._Year--;
        } else {
            date._Mon--;
        }
        date._Day = clsDate::NumberOfDaysInMonth(date._Year, date._Mon);
    } else {
        date._Day--;
    }
    return date;
}
// Decrease one day (obj)
void clsDate::DecreaseOneDay() {
    *this = DecreaseOneDay(*this);
}
// Decrease x days (static)
clsDate clsDate::DecreaseXDays(clsDate date, short xDays) {
    for (short i = 0; i < xDays; i++) {
        date = clsDate::DecreaseOneDay(date);
    }
    return date;
}
// Decrease x days (obj)
void clsDate::DecreaseXDays(short xDays) {
    *this = DecreaseXDays(*this, xDays);
}

// Decrease one week (static)
clsDate clsDate::DecreaseOneWeek(clsDate date) {
    for (short i = 0; i < 7; i++) {
        date = clsDate::DecreaseOneDay(date);
    }
    return date;
}
// Decrease one week (obj)
void clsDate::DecreaseOneWeek() {
    *this = DecreaseOneWeek(*this);
}
// Decrease x weeks (static)
clsDate clsDate::DecreaseXWeeks(clsDate date, short xWeeks) {
    for (short i = 0; i < xWeeks; i++) {
        date = clsDate::DecreaseOneWeek(date);
    }
    return date;
}
// Decrease x weeks (obj)
void clsDate::DecreaseXWeeks(short xWeeks) {
    *this = DecreaseXWeeks(*this, xWeeks);
}

// Decrease one month (static)
clsDate clsDate::DecreaseOneMonth(clsDate date) {
    if (date._Mon == 1) {
        date._Mon = 12;
        date._Year--;
    } else {
        date._Mon--;
    }

    // last check day in date should not exceed max days in the current month
    //  example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
    //  be 28/2/2022
    short NumberOfDays = clsDate::NumberOfDaysInMonth(date._Year, date._Mon);
    if (date._Day > NumberOfDays)
        date._Day = NumberOfDays;

    return date;
}
// Decrease one month (obj)
void clsDate::DecreaseOneMonth() {
    *this = DecreaseOneMonth(*this);
}
// Decrease x Months (static)
clsDate clsDate::DecreaseXMonths(clsDate date, short xMonths) {
    for (short i = 0; i < xMonths; i++) {
        date = DecreaseOneMonth(date);
    }
    return date;
}
// Decrease x Months (obj)
void clsDate::DecreaseXMonths(short xMonths) {
    *this = DecreaseXMonths(*this, xMonths);
}

// Decrease one Year (static)
clsDate clsDate::DecreaseOneYear(clsDate date) {
    date._Year--;
    return date;
}
// Decrease one Year (obj)
void clsDate::DecreaseOneYear() {
    _Year--;
}
// Decrease x Years (static)
clsDate clsDate::DecreaseXYears(clsDate date, short xYears) {
    date._Year -= xYears;
    return date;
}
// Decrease x Years (obj)
void clsDate::DecreaseXYears(short xYears) {
    _Year -= xYears;
}

// Decrease one Decade (static)
clsDate clsDate::DecreaseOneDecade(clsDate date) {
    date._Year -= 10;
    return date;
}
// Decrease one Decade (obj)
void clsDate::DecreaseOneDecade() {
    _Year -= 10;
}
// Decrease x Decades (static)
clsDate clsDate::DecreaseXDecades(clsDate date, short xDecades) {
    date._Year -= (xDecades * 10);
    return date;
}
// Decrease x Decades (obj)
void clsDate::DecreaseXDecades(short xDecades) {
    _Year -= (xDecades * 10);
}

// Decrease one Century (static)
clsDate clsDate::DecreaseOneCentury(clsDate date) {
    date._Year -= 100;
    return date;
}
// Decrease one Century (obj)
void clsDate::DecreaseOneCentury() {
    _Year -= 100;
}
// Decrease one Millennium (static)
clsDate clsDate::DecreaseOneMillennium(clsDate date) {
    date._Year -= 1000;
    return date;
}
// Decrease one Millennium (obj)
void clsDate::DecreaseOneMillennium() {
    _Year -= 1000;
}

// is End of week (static)
bool clsDate::isEndOfWeek(clsDate date) {
    return (clsDate::DayOfWeekOrder(date._Year, date._Mon, date._Day) == 6);
}
// is End of week (obj)
bool clsDate::isEndOfWeek() {
    return isEndOfWeek(*this);
}

// is weekend (static)
bool clsDate::isWeekend(clsDate date) {
    short Weekend = clsDate::DayOfWeekOrder(date._Year, date._Mon, date._Day);
    return (Weekend == 6 || Weekend == 0);
}
// is weekend (obj)
bool clsDate::isWeekend() {
    return isWeekend(*this);
}

// is businuss day (static)
bool clsDate::isBusinessDay(clsDate date) {
    return (!clsDate::isWeekend(date));
}
// is businuss day (obj)
bool clsDate::isBusinessDay() {
    return isBusinessDay(*this);
}

// days until end of week (static)
short clsDate::DaysUntilEndOfWeek(clsDate date) {
    return (6 - clsDate::DayOfWeekOrder(date._Year, date._Mon, date._Day));
}
// days until end of week (obj)
short clsDate::DaysUntilEndOfWeek() {
    return DaysUntilEndOfWeek(*this);
}

// Days until end of month (static)
short clsDate::DaysUntilEndOfMonth(clsDate date) {
    short NumberOfDays = clsDate::NumberOfDaysInMonth(date._Year, date._Mon);
    return (NumberOfDays - date._Day) + 1;
}
// Days until end of month (obj)
short clsDate::DaysUntilEndOfMonth() {
    return DaysUntilEndOfMonth(*this);
}

// Days until end of year (static)
short clsDate::DaysUntilEndOfYear(clsDate date) {
    clsDate EndOfYearDate;
    EndOfYearDate._Day = 31;
    EndOfYearDate._Mon = 12;
    EndOfYearDate._Year = date._Year;

    return clsDate::DifferenceInDays(date, EndOfYearDate, true);
}
// Days until end of year (obj)
short clsDate::DaysUntilEndOfYear() {
    return DaysUntilEndOfYear(*this);
}

// Calculate Business Days
short clsDate::CalculateBusinessDays(clsDate DateFrom, clsDate DateTo) {
    short Days = 0;
    while (clsDate::isDate1BeforDate2(DateFrom, DateTo)) {
        if (clsDate::isBusinessDay(DateFrom))
            Days++;

        DateFrom = clsDate::AddOneDay(DateFrom);
    }

    return Days;
}

// Calculate Vacation Days
short clsDate::CalculateVacationDays(clsDate DateFrom, clsDate DateTo) {
    return clsDate::CalculateBusinessDays(DateFrom, DateTo);
}

// Calculate Vacation Return Date
clsDate clsDate::CalculateVacationReturnDate(clsDate DateFrom, short VacationDays) {
    // Handle zero or negative vacation days
    if (VacationDays <= 0)
        return DateFrom;

    short Counter = 0;
    while (Counter < VacationDays) {
        if (clsDate::isBusinessDay(DateFrom)) {
            Counter++;
        }
        DateFrom = clsDate::AddOneDay(DateFrom);
    }

    // Ensure return day is a business day
    while (!clsDate::isBusinessDay(DateFrom)) {
        DateFrom = clsDate::AddOneDay(DateFrom);
    }
    return DateFrom;
}
// compare date (static)
clsDate::enCompareDates clsDate::CompareDates(clsDate date1, clsDate date2) {
    if (clsDate::isDate1BeforDate2(date1, date2)) {
        return eBefor;
    } else if (clsDate::isDate1EqualDate2(date1, date2)) {
        return eEqual;
    } else
        return eAfter;
}
// compare date (obj)
clsDate::enCompareDates clsDate::CompareDates(clsDate Date2) {
    return clsDate::CompareDates(*this, Date2);
}
