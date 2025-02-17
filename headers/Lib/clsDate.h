#ifndef CLSDATE_H
#define CLSDATE_H
#include <random>
#include <string>
using namespace std;

class clsDate {
    private:
        short _Year;
        short _Mon;
        short _Day;
        short _Hour;
        short _Min;
        short _Sec;

    public:
        // constructor definition
        clsDate();
        // constructor parameter (string)
        clsDate(string date);
        // constructor parameter (intiger)
        clsDate(short year, short mon, short day);
        // constructor parameter (Number of days)
        clsDate(short days, short year);
        // setter
        void SetYear(short year);
        void SetMonth(short mon);
        void SetDay(short day);
        // getter
        short GetYear();
        short GetMonth();
        short GetDay();
        // get system date
        static clsDate GetSystemDate();
        // get system date in string
        static string GetDateAndTime();
        // check is validate date (static)
        static bool isValid(short year, short mon, short day);
        // check is validate date (object)
        bool isValid();

        // print date
        void Print();

        // is leap year
        static bool isLeapYear(short Year);

        //********** Year ***************
        static short NumberOfDaysInYear(short Year);
        short NumberOfDaysInYear();
        static short NumberOfHoursInYear(short Year);
        short NumberOfHoursInYear();
        static short NumberOfMinutsInYear(short Year);
        short NumberOfMinutsInYear();
        static short NumberOfSecondsInYear(short Year);
        short NumberOfSecondsInYear();

        //******** Months ***********
        static short NumberOfDaysInMonth(short Year, short Month);
        short NumberOfDaysInMonth();
        static short NumberOfHoursInMonth(short Year, short Month);
        short NumberOfHoursInMonth();
        static short NumberOfMinutsInMonth(short Year, short Month);
        short NumberOfMinutsInMonth();
        static short NumberOfSecondsInMonth(short Year, short Month);
        short NumberOfSecondsInMonth();

        // Day of week order (static)
        static short DayOfWeekOrder(short Year, short Month, short Day);
        // Day of week order (object)
        short DayOfWeekOrder();
        // day short name (static)
        static string DayShortName(short IndexOfDay);
        // day short name (object)
        string DayShortName();
        // month short name (static)
        static string MonthShortName(short IndexOfMonth);
        // month short name (static)
        string MonthShortName();
        // convert date to string (static)
        static string ConvertDateToString(clsDate date);
        // convert date to string (static)
        static string ConvertDateToString(short Year, short Month, short Day);
        // convert date to string (obj)
        string ConvertDateToString();
        // Print month calander (static)
        static void MonthCalander(short Year, short Month);
        // Print month calander (obj)
        void MonthCalander();
        // Print Year calander (static)
        static void YearCalander(short Year);
        // Print Year calander (obj)
        void YearCalander();
        // total days from the begining of year (static)
        static short TotalDaysFromTheBeginingOfYear(short Year, short Month, short Day);
        // total days from the begining of year (obj)
        short TotalDaysFromTheBeginingOfYear();
        // Add days to date
        void AddDays(short NumberOfDays);
        // is date1 befor date2 (static)
        static bool isDate1BeforDate2(clsDate date1, clsDate date2);
        // is date1 befor date2 (obj)
        bool isDate1BeforDate2(clsDate date2);
        // is date1 equal date2 (static)
        static bool isDate1EqualDate2(clsDate date1, clsDate date2);
        // is date1 equal date2 (obj)
        bool isDate1EqualDate2(clsDate date2);
        // is date1 after date2 (static)
        static bool isDate1AfterDate2(clsDate date1, clsDate date2);
        // is date1 after date2 (obj)
        bool isDate1AfterDate2(clsDate date2);
        // is last day in month (static)
        static bool isLastDayInMonth(clsDate date);
        // is last day in month (obj)
        bool isLastDayInMonth();
        // is last month in year (static)
        static bool isLastMonthInYear(short month);
        // is last month in year (obj)
        bool isLastMonthInYear();
        // swap dates (static)
        static void SwapDates(clsDate &date1, clsDate &date2);
        // Get deffirence in days (static)
        static short DifferenceInDays(clsDate date1, clsDate date2, bool IncludeEndDay = false);
        // Get deffirence in days (obj)
        short DifferenceInDays(clsDate date2, bool IncludeEndDay = false);
        // Add one day (static)
        static clsDate AddOneDay(clsDate date);
        // Add one day (obj)
        void AddOneDay();
        // Add x days (static)
        static clsDate AddxDays(clsDate date, short xDays);
        // Add x days (obj)
        void AddxDays(short xDays);
        // Add one week (static)
        static clsDate AddOneWeek(clsDate date);
        // Add one week (obj)
        void AddOneWeek();
        // Add x weeks (static)
        static clsDate AddxWeeks(clsDate date, short xWeeks);
        // Add x weeks (obj)
        void AddxWeeks(short xWeeks);
        // Add one month (static)
        static clsDate AddOneMonth(clsDate date);
        // Add one month (obj)
        void AddOneMonth();
        // Add x months (static)
        static clsDate AddxMonths(clsDate date, short xMonths);
        // Add x months (obj)
        void AddxMonth(short xMonths);
        // Add one year (static)
        static clsDate AddOneYear(clsDate date);
        // Add one year (obj)
        void AddOneYear();
        // Add x years (static)
        static clsDate AddxYears(clsDate date, short xYears);
        // Add x years (obj)
        void AddxYears(short xYears);
        // Add one decade (static)
        static clsDate AddOneDecade(clsDate date);
        // Add one decade (obj)
        void AddOneDecade();
        // Add x decades (static)
        static clsDate AddxDecades(clsDate date, short xDecades);
        // Add x decades (obj)
        void AddxDecades(short xDecades);
        // Add one Century (static)
        static clsDate AddOneCentury(clsDate date);
        // Add one Century (obj)
        void AddOneCentury();
        // Add one Millennium (static)
        static clsDate AddOneMillennium(clsDate date);
        // Add one Millennium (obj)
        void AddOneMillennium();
        // Decrease one day (static)
        static clsDate DecreaseOneDay(clsDate date);
        // Decrease one day (obj)
        void DecreaseOneDay();
        // Decrease x days (static)
        static clsDate DecreaseXDays(clsDate date, short xDays);
        // Decrease x days (obj)
        void DecreaseXDays(short xDays);
        // Decrease one week (static)
        static clsDate DecreaseOneWeek(clsDate date);
        // Decrease one week (obj)
        void DecreaseOneWeek();
        // Decrease x weeks (static)
        static clsDate DecreaseXWeeks(clsDate date, short xWeeks);
        // Decrease x weeks (obj)
        void DecreaseXWeeks(short xWeeks);
        // Decrease one month (static)
        static clsDate DecreaseOneMonth(clsDate date);
        // Decrease one month (obj)
        void DecreaseOneMonth();
        // Decrease x Months (static)
        static clsDate DecreaseXMonths(clsDate date, short xMonths);
        // Decrease x Months (obj)
        void DecreaseXMonths(short xMonths);
        // Decrease one Year (static)
        static clsDate DecreaseOneYear(clsDate date);
        // Decrease one Year (obj)
        void DecreaseOneYear();
        // Decrease x Years (static)
        static clsDate DecreaseXYears(clsDate date, short xYears);
        // Decrease x Years (obj)
        void DecreaseXYears(short xYears);
        // Decrease one Decade (static)
        static clsDate DecreaseOneDecade(clsDate date);
        // Decrease one Decade (obj)
        void DecreaseOneDecade();
        // Decrease x Decades (static)
        static clsDate DecreaseXDecades(clsDate date, short xDecades);
        // Decrease x Decades (obj)
        void DecreaseXDecades(short xDecades);
        // Decrease one Century (static)
        static clsDate DecreaseOneCentury(clsDate date);
        // Decrease one Century (obj)
        void DecreaseOneCentury();
        // Decrease one Millennium (static)
        static clsDate DecreaseOneMillennium(clsDate date);
        // Decrease one Millennium (obj)
        void DecreaseOneMillennium();
        // is End of week (static)
        static bool isEndOfWeek(clsDate date);
        // is End of week (obj)
        bool isEndOfWeek();
        // is weekend (static)
        static bool isWeekend(clsDate date);
        // is weekend (obj)
        bool isWeekend();
        // is businuss day (static)
        static bool isBusinessDay(clsDate date);
        // is businuss day (obj)
        bool isBusinessDay();
        // days until end of week (static)
        static short DaysUntilEndOfWeek(clsDate date);
        // days until end of week (obj)
        short DaysUntilEndOfWeek();
        // Days until end of month (static)
        static short DaysUntilEndOfMonth(clsDate date);
        // Days until end of month (obj)
        short DaysUntilEndOfMonth();
        // Days until end of year (static)
        static short DaysUntilEndOfYear(clsDate date);
        // Days until end of year (obj)
        short DaysUntilEndOfYear();
        // Calculate Business Days
        static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo);
        // Calculate Vacation Days
        static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo);
        // Calculate Vacation Return Date
        static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays);
        // enum for date compare
        enum enCompareDates {
            eBefor = -1,
            eEqual = 0,
            eAfter = 1
        };
        // compare date (static)
        static enCompareDates CompareDates(clsDate date1, clsDate date2);
        // compare date (obj)
        enCompareDates CompareDates(clsDate Date2);
};
#endif // !CLSDATE_H
