class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        int pos = 1;
        while(num){
            int val = num % 10;
            res = getRoman(val, pos) + res;
            num /= 10;
            ++pos;
        }
        return res;
    }
    string getRoman(int num,int pos){
        string res = "";
        char ch5,ch10,ch1;
        switch(pos){
            case 4 :{
                res = string(num,'M');
                return res;
            }
            case 3 :{
                ch1 = 'C';
                ch5 = 'D';
                ch10 = 'M';
                break;
            }
            case 2 :{
                ch1 = 'X';
                ch5 = 'L';
                ch10 = 'C';
                break;
            }
            case 1 :{
                ch1 = 'I';
                ch5 = 'V';
                ch10 = 'X';
                break;
            }
        }
        if(num == 9){
            res += ch1;
            res += ch10;
        }
        else if(num > 4){
            res += ch5;
            res += string(num-5,ch1);
        }
        else if(num == 4){
            res += ch1;
            res += ch5;
        }
        else{
            res = string(num,ch1);
        }
        return res;
    }
};