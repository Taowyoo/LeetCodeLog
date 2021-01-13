/*
 * File: 1042.cpp
 * File Created: 2021-01-12 14:54:03 -08:00
 * Author: Taowyoo (caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/flower-planting-with-no-adjacent/
 * -----
 * Last Modified: 2021-01-12 14:54:09 -08:00
 * Modified By: Taowyoo (caoyxsh@outlook.com>)
 * -----
 * Copyright 2020 - 2021
 */

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> res(N);
        vector<vector<int>> G(N);
        // create adjacent list
        for (vector<int>& p : paths) {
            G[p[0] - 1].push_back(p[1] - 1);
            G[p[1] - 1].push_back(p[0] - 1);
        }
        // iterate over all gardens
        for (int i = 0; i < N; ++i) {
            // record all colors used by adjacent garden
            int colors[5] = {};
            for (int j : G[i])
                colors[res[j]] = 1;
            // find one unused color to plant flower for current garden
            for (int c = 4; c > 0; --c)
                if (!colors[c])
                    res[i] = c;
        }
        return res;
    }
};