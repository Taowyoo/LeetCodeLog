/*
 * File: 787.cpp
 * File Created: 2021-01-12 14:33:57 -08:00
 * Author: Taowyoo (caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/cheapest-flights-within-k-stops/
 * -----
 * Last Modified: 2021-01-12 14:33:59 -08:00
 * Modified By: Taowyoo (caoyxsh@outlook.com>)
 * -----
 * Copyright 2020 - 2021
 */

class Solution {
    /**
     * @brief  bellman ford.just run it k+1 iterations.
     * 
     */
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> c(n, 1e8);
        c[src] = 0;

        for(int z = 0; z <= K; z++){
            vector<int> C(c);
            for(auto e: flights)
                C[e[1]] = min(C[e[1]], c[e[0]] + e[2]);
            c = C;
        }
        return c[dst] == 1e8 ? -1 : c[dst];
    }
};