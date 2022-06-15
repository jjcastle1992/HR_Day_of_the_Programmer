#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
    string dateOfProgrammer = "";
    int targetDays = 256; //Day of the programmer
    bool leapYear = false;
    bool gregorian = false;
    bool transition = false;
    int daysOfTheMonth [] {0, 31, 28, 31, 30, 31, 30, 31, 31,
                           30, 31, 30, 31};
    string months [] {"ERROR", "01", "02","03","04", "05","06","07","08",
                      "09","10","11","12"};
    //Intake Year


    //Determine if the date is 1917 or before, 1918 (special case) or 1919 and after
    if (year <= 1917) {
        gregorian = false;
        transition = false;
    }

    else if (year == 1918) {
        gregorian = false;
        transition = true; //(1918 was NOT a leap year and Feb had 14 days)
        leapYear = false;
        daysOfTheMonth[2] = 15;
    }

    else if (year >= 1919) {
        gregorian = true;
        transition = false;
    }

    //determine if it is a leap year (1918 was NOT a leap year and Feb had 14 days)
    if (!transition) {
        if (gregorian) {
            //Gregorian leap years are EITHER
            // 1) Divisible by 400
            // 2) Divisible by 4, but NOT 100
            int fourHundredRemainder = 0;
            int isFourRemainder = 0;
            int notOneHundredRemainder = 0;
            fourHundredRemainder = year % 400;
            if (fourHundredRemainder == 0) {
                leapYear = true;
            }

            else {
                isFourRemainder = year % 4;
                notOneHundredRemainder = year % 100;
                if (isFourRemainder == 0 && notOneHundredRemainder != 0) {
                    leapYear = true;
                }
            }
        }
        else {
            //Julian Calendar leap years are just divisible by 4
            if ((year % 4) == 0) {
                leapYear = true;
            }
        }
    }


    //update an array of days in the month, of size 12, w/ elements 1-12 corresponding to Jan-Dec.
    // Note: Element 0 is not used to align index w/ month. All months except Feb will be constant.
    // Feb will equal 28 unless in a leap year. If leap year, then Feb = 29
    if (leapYear) {
        daysOfTheMonth[2] = 29;
    }

    //Find the 256th day of the year output as dd.mm.yyyy

    //Determine the month by determining how many element sums it takes to equal 256 days (the day of the Programmer)
    //# of days of the year (excluding Feb in all 3 cases)
    bool dayThreshold = false;
    int runningSum = 0;
    int monthIndex = 0;
    int excessDays = 0;
    while (!dayThreshold) {
        if (runningSum < targetDays) {
            runningSum += daysOfTheMonth[monthIndex];
            if (runningSum < targetDays) {
                monthIndex++;
            }
        }
        else {
            dayThreshold = true;
        }
    }

    string month = months[monthIndex];
    excessDays = runningSum - targetDays;
    int intDay = daysOfTheMonth[monthIndex] - excessDays;
    string day = to_string (intDay);
    string strYear = to_string (year);

    dateOfProgrammer = day + "." + month + "." + strYear;

    return dateOfProgrammer;
}

int main()
{
    int minYear = 1700;
    int maxYear = 2700;

    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    if (year >= minYear && year <= maxYear) {
        string result = dayOfProgrammer(year);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}
