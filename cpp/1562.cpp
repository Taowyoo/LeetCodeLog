// Count the Length of Groups
// Explanation
// count[i] means the length of the group.
// When we set bit a, where a = A[i],
// we check the length of group on the left length[a - 1]
// also the length of group on the right length[a + 1].
// Then we update length[a], length[a - left], length[a + right] to left + right + 1.

// Note that the length value is updated on the leftmost and the rightmost bit of the group.
// The length value inside the group may be out dated.

// As we do this, we also update the count of length.
// If count[m] > 0, we update res to current step index i + 1.
// Time : O(n)
// Space : O(n)
int findLatestStep(vector<int>& A, int m) {
    int res = -1, n = A.size();
    vector<int> length(n + 2), count(n + 1);
    for (int i = 0; i < n; ++i) {
        int a = A[i], left = length[a - 1], right = length[a + 1];
        length[a] = length[a - left] = length[a + right] = left + right + 1;
        count[left]--;
        count[right]--;
        count[length[a]]++;
        if (count[m])
            res = i + 1;
    }
    return res;
}
//============================================================================================
// Union Find
// Thought process:

// On first thought it seems like a union find data structure might help to union two groups into one.
// We can also note that using a union find data structure we can also store the counts of each group and update them when union'ing.
// We need to somehow reverse map these counts, as in what's required in the question is the count(m) of these groups (where group size = m), thus let's also try and maintain the count of groups of size x
// Now all we need to do is keep a track of the reverse map and record the last step where the groupCounts[m]>0.

class Solution {
public:
    vector<int> parent,Rank,count,groupCounts;	//Basic union find related storages (groupCounts stores # of groups of size `i`- our reverse mapping)
    int Find(int x)
    {
        return parent[x]==x?x:parent[x]=Find(parent[x]);
    }
    void Union(int x,int y)			//Modified union to update groupCounts
    {
        int xset=Find(x),yset=Find(y);
        if(xset!=yset)
        {
            groupCounts[count[xset]]--,groupCounts[count[yset]]--;//Union'ing would change the groupSize of current x and y groups.
            count[xset]=count[yset]=count[xset]+count[yset];		//Size of groups of x and y now are now size(x)+size(y)
            groupCounts[count[xset]]++;
            Rank[xset]<Rank[yset]?parent[xset]=yset:parent[yset]=xset;
            if(Rank[xset]==Rank[yset])
                Rank[xset]++;
        }
    }
    int findLatestStep(vector<int>& arr, int m)
    {
        parent.resize(arr.size()+1),Rank.resize(arr.size()+1,0);			//Few lines for basic initialization.
        for(int i=1;i<=arr.size();i++)
            parent[i]=i;
        vector<bool> visited(arr.size()+1,false);
        count.resize(arr.size()+1,1);			//Currently all groups are of size 1
        groupCounts.resize(arr.size()+1,0);
        int last=-1,step=1;						//Last stores the result, step is the current step (We can move this to a for loop)
        for(int &i:arr)
        {
            groupCounts[1]++;					//We always chose a new number whose current groupSize is 1 so we increase the groupCount[1] (Reverse Map)
            if(i+1<=arr.size()&&visited[i+1])	//Union i and i+1 if i+1'th bit was previously set
                Union(i,i+1);
            if(i-1>0&&visited[i-1])				//Union i and i-1 if i-1'th bit was previously set
                Union(i,i-1);
            visited[i]=true;
            if(groupCounts[m])					//If counts of group of size m is > 0 (This means we have a group of size m at current step, update `last`)
                last=step;
            step++;
        }
        return last;
    }
};