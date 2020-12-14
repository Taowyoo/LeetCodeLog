// https://leetcode.com/problems/minimum-time-difference

// my solution: sorting the time counting in minutes, then get min difference
// Time: O(sort)
// Space: O(n)
class Solution
{
    /**
     * @brief Get Minutes from time string 
     * 
     * @param str Time string in form of: "00:00", "23:59"
     * @return int Minutes number
     */
    int getMinute(string &str)
    {
        int hours = stoi(str.substr(0, 2));
        int mins = stoi(str.substr(3, 2));
        return hours * 60 + mins;
    }
    /**
     * @brief Get the minimum difference of minutes between two minutes
     * 
     * @param time1 Minutes number 1
     * @param time2 Minutes number 2
     * @return int Minimon difference of minutes
     */
    int getMinuteDiff(int time1, int time2)
    {
        if (time1 > time2)
            return getMinuteDiff(time2, time1);
        return min(time1 + 24 * 60 - time2, time2 - time1);
    }

public:
    /**
     * @brief Find the minimum minutes difference between any two time points in the list
     * 
     * @param timePoints Time strings list
     * @return int Minimum minutes difference
     */
    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> times;
        for (string &time : timePoints)
        {
            times.emplace_back(getMinute(time));
        }
        sort(times.begin(), times.end());
        int ans = INT_MAX;
        for (int i = 1; i < times.size(); ++i)
        {
            ans = min(ans, getMinuteDiff(times[i - 1], times[i]));
        }
        ans = min(ans, getMinuteDiff(times.front(), times.back()));
        return ans;
    }
};

// Another solution
// use Bucket to store all timePoints
// Time: O(n)
// Space: O(n)
class Solution {
    /**
     * @brief Get Minutes from time string 
     * 
     * @param str Time string in form of: "00:00", "23:59"
     * @return int Minutes number
     */
    int getMinute(string& it){
        int h1 = it[0] - '0', h2 = it[1] - '0';
        int m1 = it[3] - '0', m2 = it[4] - '0';
        
        int hrs = 10 * h1 + h2;
        return (10 * m1 + m2) + 60 * hrs;
    }
public:
    /**
     * @brief Find the minimum minutes difference between any two time points in the list
     * 
     * @param timePoints Time strings list
     * @return int Minimum minutes difference
     */
    int findMinDifference(vector<string>& timePoints) {
        // as there are only 24*60 timePoints, we can use a array to store them
        bool mark[24*60] = {0};
        int min = INT_MAX, max = INT_MIN;
        // one pass to tag all occurred timePoints and find max and min minutes for further loop
        for(string& time : timePoints){
            int minutes = getMinute(time);
            min = std::min(min, minutes);
            max = std::max(max, minutes);
            // if there is a duplicated timePoints, the result should be 0 
            if(mark[minutes]) return 0;
            mark[minutes] = true;  // mark the time
        }
        int minDiff = INT_MAX, prev = 0;
        for(int i = min; i <= max; i++){   //set the range from min to max as an optimization.
            if(mark[i]){
                if(i == min){   
                    //the min and max is the special case, it looks like :
                    //0---min----max-----1440, so we have two directions to calculate the distance
                    minDiff = std::min(minDiff, std::min(max - min, 1440 - max + min));
                }else{
                    //normal case: just one direction.
                    minDiff = std::min(minDiff, i - prev);
                }
                prev = i;
            }
        }
        return minDiff;
    }
};