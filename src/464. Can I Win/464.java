
// my solution - recursion with memory
public class Solution {
    /**
     * Can first player win the game:
     *   Two players take turns adding, to a running total, any integer from 1 to maxChoosableInteger.
     *   The player who first causes the running total to reach or exceed desiredTotal wins. 
     * @param maxChoosableInteger Max value of choosable coins
     * @param desiredTotal Targe total value player aim to reach
     * @return
     */
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        // check corner cases:
        // 1. first player directly win if desiredTotal <= 0
        if (desiredTotal <=0 ) return true;
        // 2. if sum of given coins < desiredTotal, no one can win
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        // use recursion with memory to check all possibilities
        return canIWin(desiredTotal, new int[maxChoosableInteger], new HashMap<>());
    }
    /**
     * Use recursion to test all possibilities of picking coins cases, use a array to record picking state.
     * Hash state array and record checked state to avoid extra check.
     * @param total Current target total
     * @param state Current state of picking: use 1 for picked, 0 for unpicked
     * @param hashMap HashMap to store checked state
     * @return boolean Wether first player can win from current state
     */
    private boolean canIWin(int total, int[] state, HashMap<Integer, Boolean> hashMap) {
        // use hash method in Arrays library which is faster than convert it to String
        int curr = Arrays.hashCode(state);
        // if checked before, return checked result
        if (hashMap.containsKey(curr)) return hashMap.get(curr);
        // for each unpicked state coin, recursively try it
        for (int i = 0; i < state.length; i++) {
            // take unpicked coins
            if (state[i]==0) {
                // set corresponding state -> picked
                state[i]=1;
                // first player win under two cases:
                // 1. current total < coin value just picked, which means first player has reach the target, first player win
                // 2. recursively the second player lose
                if (total <= i+1 || !canIWin(total-(i+1), state, hashMap)) {
                    // updated checked state
                    hashMap.put(curr, true);
                    // restore corresponding state -> unpicked
                    state[i]=0;
                    return true;
                }
                // restore corresponding state -> unpicked
                state[i]=0;
                // then try next unpicked coin
            }
        }
        // updated checked state
        hashMap.put(curr, false);
        // if all coins tried cannot win, first player lose
        return false;
    }
}