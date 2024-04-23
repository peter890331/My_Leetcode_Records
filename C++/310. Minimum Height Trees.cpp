class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};         // 如果只有一個節點，直接返回。
        if (n == 2) return {0,1};       // 如果只有兩個節點，直接返回。


        vector<vector<int>> next(n);    // 任何一個節點各有那些相鄰的節點。
        vector<int> degree(n);          // 任何一個節點有幾個相鄰的節點。

        for (auto edge: edges){
            int a = edge[0];
            int b = edge[1];
            degree[a]++;                // a至少有一度，也就是至少有一個相鄰的節點，就是b。
            degree[b]++;                // b至少有一度，也就是至少有一個相鄰的節點，就是a。
            next[a].push_back(b);       // a的相鄰節點有一個b。
            next[b].push_back(a);       // b的相鄰節點有一個a。
        }

        // 剝洋蔥。
        queue<int> q;           // 最外層節點。
        vector<int> visited(n); // 剝過的節點。

        // 先找最外層節點。
        for (int i=0; i<n; i++){
            if (degree[i]==1)   // 最外層節點。
                q.push(i);
        }

        int count = 0;
        while (!q.empty()){
            int len = q.size();                 // 目前最外層節點有幾個。
            while (len--){
                int current = q.front();
                q.pop();                        // 剝掉一個最外層節點。
                count++;
                visited[current] = 1;           // 標記剝過的節點。
                for (int next_: next[current]){
                    degree[next_]--;            // 下一層節點的degree-1。
                    if (degree[next_] == 1)     // 變成最外層節點。
                    q.push(next_);              // 最外層節點。
                }
            }
            if (count == n-1 || count == n-2)   // 剝到剩下一個或兩個節點就是最根的節點。
                break;
        }

        vector<int> ans;            // 最根的節點。
        for (int i=0; i<n; i++){
            if (visited[i] == 0)    // 如果沒剝過就是最根的節點。
                ans.push_back(i);
        }
        return ans;
    }
};

// 剝洋蔥，把最外層的節點依次剝掉。
// 無向圖的拓樸排序。
// Reference from 【每日一题】LeetCode 310. Minimum Height Trees, https://youtu.be/2BaulnY_ssM.