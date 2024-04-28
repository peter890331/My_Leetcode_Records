class Solution {

    // 全域變數。
    int subtree[300005];            // 整數陣列，用於存儲各個點的子樹大小。
    vector<int> next[300005];       // 陣列，每個元素都是一個整數向量，用於存儲每個節點的相鄰節點。
    int visited[300005];            // 整數陣列，用於標記節點是否被訪問過。
    vector<int> ans;

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        ans.resize(n);                              // 調整全域變數 ans 的大小。

        for (auto& edge: edges){                    // 遍歷 edges 存儲每個節點的相鄰節點。
            next[edge[0]].push_back(edge[1]);
            next[edge[1]].push_back(edge[0]);
        }

        // Step 2.
        visited[0] = 1;                             // 根節點 0 已經 visit 過。
        dfs(0);                                     // compute the substree size for every node.

        // Step 3.
        for (int i=1; i<n; i++) visited[i] = 0;     // 重置 visited.
        ans[0] = dfs2(0);                           // compute the sum of distances towards root (0).

        // Step 4.
        for (int i=1; i<n; i++) visited[i] = 0;     // 重置 visited.
        dfs3(0, n);                                 // compute the sum of distances towards every node, 
                                                    // by f(child) = f(parent) + n - 2 * subtree_size(child).

        return ans;
    }

    // Step 2.
    int dfs(int cur){                               // compute the substree size for every node.
        int sum = 1;                                // 至少含有當前的節點。
        for (int x: next[cur]){
            if (visited[x] == 1) continue;
            visited[x] = 1;
            sum += dfs(x);                          // 遞迴。
        }
        subtree[cur] = sum;                         // the substree size for every node.
        return sum;
    }

    // Step 3.
    int dfs2(int cur){                              // compute the sum of distances towards root (0).
        int sum = 0;
        for (int x: next[cur]){
            if (visited[x] == 1) continue;
            visited[x] = 1;
            sum += dfs2(x);                         // 遞迴。
        }
        sum += subtree[cur] - 1;
        return sum;
    }

    // Step 4.
    void dfs3(int cur, int n){                      // compute the sum of distances towards every node, 
        for (int x: next[cur]){
            if (visited[x] == 1) continue;
            visited[x] = 1;
            int b = subtree[x];
            int a = n - b;
            ans[x] = ans[cur] + a - b;              // by f(child) = f(parent) + n - 2 * subtree_size(child).
            dfs3(x, n);                             // 遞迴。
        }
    }

};


// Re-root
// f(child) = f(parent) + a - b
// b = subtree_size(child)
// a  = n - b
// f(child) = f(parent) + a - b => f(child) = f(parent) + n - 2 * subtree_size(child)

// f(2) = f(0) + (n - 2為根的子樹) - 2為根的子樹 => f(2) = f(0) + n - 2 * 2為根的子樹

// Steps:
// 1. pick a root, ex: 0.
// 2. compute the substree size for every node. => 各個點為根的子樹
// 3. compute the sum of distances towards root. => f(root) => f(parent) => f(0)
// 4. compute the sum of distances towards every node, 
// by f(child) = f(parent) + n - 2 * subtree_size(child).
// => f(node) => f(child) => f(2)

// Reference from 【每日一题】LeetCode 834. Sum of Distances in Tree, https://youtu.be/vPureKiDAgI.