// https://leetcode.com/problems/bulls-and-cows/

// Solution - two pass
// traverse once to count bulls and number of chars except bulls
// then traverse other chars in the guess to check whether secret contains it, if contains it then reduce the corresponding count
// Time: O(n)
// Space: O(1)
class Solution {
public:
    /**
     * @brief Get the Hint string from guess and secret (2 pass version)
     * 
     * @param secret input secret string
     * @param guess input guess string
     * @return string bulls and cows string
     */
    string getHint(string secret, string guess) {
        int bull = 0;  // variable for counting bulls number
        int cow = 0;  // variable for counting cows number
        int count[10] = {};  // as these are only number, so use a fixed array to store count of numbers
        // first pass: count bulls and numbers except bulls
        for(int i = 0; i < secret.size(); ++i){
            if(secret[i] == guess[i]){
                ++bull;
            }
            else{
                count[secret[i] - '0'] += 1;
            }
        }
        // second pass: count cows from those number except bows
        for(int i = 0; i < secret.size(); ++i){
            if(secret[i] != guess[i]){  // only check cows
                // check whether guess[i] matched with one of the previous characters in the secret
                if(count[guess[i] - '0'] > 0){  
                    ++cow;
                    count[guess[i] - '0'] -= 1;  // reduce the one that has been matched
                }
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
        
    }
};

// One pass solution a
// Time: O(n)
// Space: O(1)
/**
 * @brief Get the Hint string from guess and secret (1 pass version a)
 * 
 * @param secret input secret string
 * @param guess input guess string
 * @return string bulls and cows string
 */
string getHint(string secret, string guess) {
    int bull = 0;  // variable for counting bulls number
    int cow = 0;  // variable for counting cows number
    int count_s[10] = {};  // as these are only number, so use a fixed array to store count of numbers
    int count_g[10] = {};  // as these are only number, so use a fixed array to store count of numbers
    // first pass: count bulls and numbers except bulls
    for(int i = 0; i < secret.size(); ++i){
        if(secret[i] == guess[i]){
            ++bull;
        }
        else{
            // if secret[i] appeared in guess, there is a cow
            if(count_g[secret[i] - '0']){
                // we only need to reduce the guess count of this character
                // because we has not yet add 1 for this character in secret count
                --count_g[secret[i] - '0'];
                ++cow;
            }
            // otherwise, store this character in secret count array
            else{
                count_s[secret[i] - '0'] += 1;
            }
            // if guess[i] appeared in secret, there is a cow
            if(count_s[guess[i] - '0']){
                // we only need to reduce the secret count of this character
                // because we has not yet add 1 for this character in guess count
                --count_s[guess[i] - '0'];
                ++cow;
            }
            // otherwise, store this character in guess count array
            else{
                count_g[guess[i] - '0'] += 1;
            }
        }
    }
    return to_string(bull) + "A" + to_string(cow) + "B";
    
}

// One pass solution b
// Time: O(n)
// Space: O(1)
// Hint:
// numbers[secret[i] - '0'] is negative only if this character appeared in the guess more times then in the secret 
// which means that this character in the secret can be matched with one of the previous characters in the guest and vice versa.
class Solution {
public:
    /**
     * @brief Get the Hint string from guess and secret (1 pass version)
     * 
     * @param secret input secret string
     * @param guess input guess string
     * @return string bulls and cows string
     */
    string getHint(string secret, string guess) {
        int bull = 0;  // variable for counting bulls number
        int cow = 0;  // variable for counting cows number
        int count[10] = {};  // as these are only number, so use a fixed array to store count of numbers

        // counting cows and bulls in one pass
        for(int i = 0; i < secret.size(); ++i){
            if(secret[i] != guess[i]){  // check cows

                // when meet a secret[i], numbers[secret[i] - '0'] is negative only if this character appeared in the guess more times then in the secret
                // which means that this character in the secret can be matched with one of the previous characters in the guest
                if (count[secret[i] - '0'] < 0)
                    ++cow;
                
                // when meet a guess[i], numbers[guess[i] - '0'] is positive only if this character appeared in the secret more times then in the guess
                // which means that this character in the guess can be matched with one of the previous characters in the secret
                if (count[guess[i] - '0'] > 0)
                    ++cow;
                
                count[guess[i] - '0'] -= 1;  // counting characters in guess string by subtracting
                count[secret[i] - '0'] += 1;  // counting characters in secret string by adding
            }
            else{  // check bulls
                ++bull;
            }
        }

        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};