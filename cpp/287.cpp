// my solution
// Time: O(n)
// Space: O(1)
// Explaination:
// Traverse the vector, put each number x to nums[x-1]
// when the x is not at index x-1 but x == nums[x-1], then x is the Duplicate Number
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            int val_pos = nums[i] - 1;
            if(nums[i] == nums[val_pos]){
                if(i != val_pos) return nums[i];
                else {
                    ++i;
                    continue;
                }
            }
            while(nums[i] != nums[val_pos]){
                swap(nums[i],nums[val_pos]);
                if(i == val_pos) break;
                val_pos = nums[i] - 1;
            }
        }
        return -1;
    }
};

// similar idea better Opproach
// Floyd's Tortoise and Hare (Cycle Detection)
// Note: Floyd's algorithm: https://en.wikipedia.org/wiki/The_Tortoise_and_the_Hare
/*
Floyd's algorithm consists of two phases and uses two pointers, usually called tortoise and hare.

In phase 1, hare = nums[nums[hare]] is twice as fast as tortoise = nums[tortoise]. 
Since the hare goes fast, it would be the first one who enters the cycle and starts to run around the cycle.
At some point, the tortoise enters the cycle as well, and since it's moving slower the hare catches the tortoise up at some intersection point. 
Now phase 1 is over, and the tortoise has lost.

Note that the intersection point is not the cycle entrance in the general case.

To compute the intersection point, let's note that the hare has traversed twice as many nodes as the tortoise,
i.e. 2d(tortoise)=d(hare), that means

2(F + a) = F + nC + a, where nn is some integer.

Hence the coordinate of the intersection point is F + a = nC.

In phase 2, we give the tortoise a second chance by slowing down the hare, so that it now moves with the speed of tortoise: 
tortoise = nums[tortoise], hare = nums[hare]. 
The tortoise is back at the starting position, and the hare starts from the intersection point.

Let's show that this time they meet at the cycle entrance after FF steps.

    The tortoise started from zero, so its position after FF steps is FF.

    The hare started at the intersection point F + a = nC, so its position after F steps is nC + FnC+F, that is the same point as FF.

    So the tortoise and the (slowed down) hare will meet at the entrance of the cycle.
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Find the intersection point of the two runners.
        int tortoise = nums[0];  // slow
        int hare = nums[0];  // fast
        do {
          tortoise = nums[tortoise];
          hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Find the "entrance" to the cycle.
        tortoise = nums[0];
        while (tortoise != hare) {
          tortoise = nums[tortoise];
          hare = nums[hare];
        }

        return hare;
    }
};

// Other Opproaches
// Binary Search on value (not usually on array)
// Time: O(nlog(n))
// Space: O(1)
int findDuplicate(vector<int>& nums) {
    int n=nums.size()-1;
    int low=1;
    int high=n;
    int mid;
    while(low<high){
        mid=(low+high)/2;
        int count=0;
        for(int num:nums){
            if(num<=mid) count++;
        }
        if(count>mid) high=mid;
        else low=mid+1; 
    }
    return low;
}
// Sort the vector
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums);
        for (int i = 1; i < nums.length(); i++) {
            if (nums[i] == nums[i-1]) {
                return nums[i];
            }
        }
        return -1;
    }
};

// Use Set
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) {
                return num;
            }
            seen.emplace(num);
        }
        return -1;
    }
};