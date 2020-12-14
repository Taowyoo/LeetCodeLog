// my binary search solution
// Time: O(nlog(n))
// Spacke: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.empty()) return {};
        vector<int> res;
        for(int i = 0; i < numbers.size(); ++i){
            int find = target - numbers[i];
            if(find < numbers[i]){
                int idx = binarySearch(numbers, 0, i-1, find);
                if(idx != -1)
                    return {idx + 1, i + 1};
            }
            else{
                int idx = binarySearch(numbers, i+1, numbers.size(), find);
                if(idx != -1)
                    return {i + 1, idx + 1};
            }
        }
        return {};
    }
private:
    int binarySearch(vector<int>& numbers,int lo, int hi, int target){
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(numbers[mid] == target) return mid;
            else if(numbers[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
};

// Two pointer
// Time: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target)
                return {low + 1, high + 1};
            else if (sum < target)
                ++low;
            else
                --high;
        }
        return {-1, -1};
    }
};
