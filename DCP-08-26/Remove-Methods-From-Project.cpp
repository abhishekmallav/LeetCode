class Solution {
public:
    void dfs(int curr, vector<vector<int>>& adj, vector<int>& inDegree,
             vector<bool>& suspicious) {
        suspicious[curr] = true;
        for (int& ngbr : adj[curr]) {
            inDegree[ngbr]--;
            if (!suspicious[ngbr]) {
                dfs(ngbr, adj, inDegree, suspicious);
            }
        }
    }

    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        vector<bool> suspicious(n, false);
        for (auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        dfs(k, adj, inDegree, suspicious);

        vector<int> result;
        bool cannotRemove = false;

        for (int i = 0; i < n; i++) {
            if (suspicious[i] && inDegree[i] > 0) {
                cannotRemove = true;
                break;
            }
            if (!suspicious[i]) {
                result.push_back(i);
            }
        }
        if (cannotRemove) {
            vector<int> vec(n);
            for (int i = 0; i < n; i++) {
                vec[i] = i;
            }
            return vec;
        }

        return result;
    }
};