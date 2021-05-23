// https://leetcode.com/problems/day-of-the-week/

static int mouths[12]={31,28,31,30,31,30,31,31,30,31,30,31};  // array of day numbers of 12 month
static string weeks[7]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"};  // array of names of days in a week
class Solution {
    /**
     * @brief Get the number of days from 01/01/1970 according to input date
     * 
     * @param day input day
     * @param month input month
     * @param year input year
     * @return int number of days from 01/01/1970
     */
    int getDays(const int day, const int month, const int year) const {
        int days = 0;
        // add days of full years before this year
        for(int i = 1970 ; i < year; ++i){
            days += ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)?366:365;
        }
        // modify the number of days in February this year
        mouths[1] = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 29 : 28;
        // add days of full months before today in this year
        for(int i = 1 ; i < month; ++i){
            days += mouths[i - 1];
        }
        // finally add the days of this month
        return days + day;
    }
public:
    /**
     * @brief get the day of week of input specific date
     * 
     * @param day input day number
     * @param month input month number
     * @param year input year number
     * @return string the name of specific day of week
     */
    string dayOfTheWeek(int day, int month, int year) {
        // by minusing number of days from 01/01/1970 by 31/8/2020(Monday) to get the number of day of week
        int week = (getDays(day,  month,  year) - getDays(31,8,2020)) % 7;
        // check the case that week < 0
        return weeks[week >= 0 ? week : (7+week)];
    }
    
};