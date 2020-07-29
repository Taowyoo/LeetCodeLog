// my solution
class Solution {
public:
    bool isUgly(int num) {
        if(num < 1) return false;
        while(num > 1){
            int last = num;
            if(num % 2 == 0) num/=2;
            if(num % 3 == 0) num/=3;
            if(num % 5 == 0) num/=5;
            if(last == num) return false;
        }
        return true;
    }
};

// better one
class Solution {
public:
    bool isUgly(int num) {
        for (int i=2; i<6 && num; i++)
            while (num % i == 0)
                num /= i;
        return num == 1;
    }
};