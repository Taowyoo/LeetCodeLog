class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for(int i = 0; i < s.size() - 1 ; ++i){
            res += isSpecial(s[i],s[i+1])? -getNumber(s[i]) : getNumber(s[i]);
        }
        return res + getNumber(s.back());
    }
    int getNumber(char ch){
        switch(ch){
            case 'I':{
                return 1;
            }
            case 'V':{
                return 5;
            }
            case 'X':{
                return 10;
            }
            case 'L':{
                return 50;
            }            
            case 'C':{
                return 100;
            }            
            case 'D':{
                return 500;
            }            
            case 'M':{
                return 1000;
            }
        }
        return -1;
    }
    bool isSpecial(char ch1, char ch2){
        switch(ch1){
            case 'I' :{
                if(ch2 == 'V' || ch2 == 'X' )
                    return true;
                break;
            }
            case 'X' :{
                if(ch2 == 'L' || ch2 == 'C' )
                    return true;
                break;
            }
            case 'C' :{
                if(ch2 == 'D' || ch2 == 'M' )
                    return true;
                break;
            }
            default:{
                return false;
            }
        }
        return false;
    }
    
};