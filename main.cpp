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
    bool leapYear = false;
    int daysOfTheMonth [] {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //Intake Year

    //Determine if the date is 1917 or before or 1918 or after

    //determine if it is a leap year

    // If it is 1917 or prior, leap years are divisible only by 4

    //if it is 1918 or after, leap years are divisible by 400 OR divisible by 4 but not 100.

    //update an array of days in the month, of size 12, w/ elements 1-12 corresponding to Jan-Dec.
    // Note: Element 0 is not used to align index w/ month. All months except Feb will be constant.
    // Feb will equal 28 unless in a leap year. If leap year, then Feb = 29

    //Find the 256th day of the year output as dd.mm.yyyy

    return dateOfProgrammer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

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
