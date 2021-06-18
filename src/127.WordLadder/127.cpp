/*
 * @Author: Nick Cao
 * @Date: 2021-06-18 12:42:22
 * @LastEditTime: 2021-06-18 13:01:22
 * @LastEditors: Nick Cao
 * @Description: https://leetcode.com/problems/word-ladder/
 * @FilePath: /LeetCodeLog/src/127.WordLadder/127.cpp
 */

/**
 * @brief Generate adjacent matrix and use BFS on it
 * Time: O(M^2*N)
 * Space: O(M^2*N)
 */
class Solution {
    int isConnected(string& a, string& b){
        int dif = 0;
        for(int i = 0; i < a.size(); ++i){
            if(a[i]!=b[i]) ++dif;
            if(dif>1) return 0;
        }
        return 1;
    }
    void printMat(vector<vector<int>>& m){
        for(int i = 0; i < m.size(); ++i){
            for(int j = 0; j < m[i].size(); ++j){
                printf("%2d ",m[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // coner case: endword not in list
        auto endWordIt = find(begin(wordList),end(wordList),endWord);
        if(end(wordList) == endWordIt) return 0;
        int endWordIdx = endWordIt - begin(wordList);
        // printf("endWordIdx: %d\n",endWordIdx);
        // vertex array
        vector<string> vertexs = wordList;
        
        vertexs.push_back(beginWord);
        int N = vertexs.size();
        // printf("N %d\n",N);        
        int beginWordIdx = N-1;
        // generate adjacent matrix
        vector<vector<int>> mat(N,vector<int>(N,0));
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                mat[i][j] = mat[j][i] = isConnected(vertexs[i],vertexs[j]);
            }
        }
        // shortest path 
        int last = 0;
        queue<pair<int,int>> qq;
        qq.push(pair(beginWordIdx,1));
        
        while(!qq.empty()){
            int cur = qq.front().first;
            last = qq.front().second;
            qq.pop();
            for(int i = 0; i < N-1; ++i){
                if(mat[cur][i]>0 ){
                    mat[cur][i]=mat[i][cur] = -1;
                    if(i==endWordIdx) return last+1;
                    qq.push(pair(i,last+1));
                }
            }
        }
        return 0;
    }
};


/**
 * @brief Bidirectional BFS
 * 
 */
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        // Use hashset to store words to speed up finding
        unordered_set<string>dic(wordList.begin(),wordList.end());
        if(dic.count(endWord)==0)return 0;
        int l = beginWord.length();
        // create two hashset: one for source words, one for dst words
        unordered_set<string> s1,s2;
        s1.insert(beginWord);
        s2.insert(endWord);
        int ret = 0;

        // bidirectional BFS
        while (!s1.empty() && !s2.empty()) {
            // always BFS from smaller group as source group
            if(s1.size()>s2.size())
                swap(s1,s2);
            unordered_set<string>s;
            ret++;
            // check each word in the group
            for (string word : s1) {
              // change each charater to find the next word in the dst group
              // or in the original word list
                for(int i=0;i<l;i++){
                    char c=word[i];
                    for(int j='a';j<='z';j++){
                       word[i]=j;
                       if(s2.count(word)) return ret+1;
                       if(dic.count(word)){
                           s.insert(word);
                           dic.erase(word);
                       }
                   }
                    word[i]=c;
                }
                
            }
            s1=s;
        }
        return 0; 
    }
};