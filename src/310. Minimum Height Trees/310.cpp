/*
 * File: 310.cpp
 * File Created: 2021-01-12 14:51:01 -08:00
 * Author: Taowyoo (caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/minimum-height-trees/
 * -----
 * Last Modified: 2021-01-12 14:51:03 -08:00
 * Modified By: Taowyoo (caoyxsh@outlook.com>)
 * -----
 * Copyright 2020 - 2021
 */

class Solution {
public:

    struct Node
    {
        unordered_set<int> neighbor;
        bool isLeaf()const{return neighbor.size()==1;}
    };

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        vector<int> buffer1;
        vector<int> buffer2;
        vector<int>* pB1 = &buffer1;
        vector<int>* pB2 = &buffer2;
        if(n==1)
        {
            buffer1.push_back(0);
            return buffer1;
        }
        if(n==2)
        {
            buffer1.push_back(0);
            buffer1.push_back(1);
            return buffer1;
        }

        // build the graph
        vector<Node> nodes(n);
        for(auto& p : edges)
        {
            nodes[p[0]].neighbor.insert(p[1]);
            nodes[p[1]].neighbor.insert(p[0]);
        }

        // find all leaves
        for(int i=0; i<n; ++i)
        {
            if(nodes[i].isLeaf()) pB1->push_back(i);
        }

        // remove leaves layer-by-layer            
        while(1)
        {
            for(int i : *pB1)
            {
                for(auto n: nodes[i].neighbor)
                {
                    nodes[n].neighbor.erase(i);
                    if(nodes[n].isLeaf()) pB2->push_back(n);
                }
            }
            if(pB2->empty())
            {
                return *pB1;
            }
            pB1->clear();
            swap(pB1, pB2);
        }

    }
};