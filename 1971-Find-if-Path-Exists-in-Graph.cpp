class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {

        unordered_map<int, vector<int>> graph;

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<int> qq;
        unordered_set<int> visit;

        qq.push(source);
        visit.insert(source);

        while (!qq.empty()) {
            int node = qq.front();
            qq.pop();

            if (node == destination) {
                return true;
            }
            for (int ngbr : graph[node]) {
                if (visit.find(ngbr) == visit.end()) {
                    visit.insert(ngbr);
                    qq.push(ngbr);
                }
            }
        }
        return false;
    }
};