// my solution
// time: O(n)
// memory: O(1)
class Solution {
public:
    int compress(vector<char>& chars) {
        int j = 0; // number of new compressed chars also used for index
        for (int i = 0; i < chars.size(); i++) {
            // count number of same char
            int count = 1;
             while ((i + 1 < chars.size()) && (chars[i] == chars[i + 1])){
                count++;    
                i++;
            }
            // override new chars
            chars[j++] = char(chars[i]);
            if(count > 1)
                for(char ch : to_string(count))
                    chars[j++] = ch;
        }
        return j;
    }
};