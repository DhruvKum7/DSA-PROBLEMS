class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<pair<int,int>>> mp;
        for (auto &v : meetings) {
            int a = v[0], b = v[1], t = v[2];
            mp[t].push_back({a, b});
        }

        vector<bool> knowsecret(n, false);
        knowsecret[0] = true;
        knowsecret[firstPerson] = true;

        for (auto &it : mp) {
            auto &per = it.second;

            unordered_map<int, vector<int>> adj;
            queue<int> q;
            unordered_set<int> vis;

            for (auto &ed : per) {
                adj[ed.first].push_back(ed.second);
                adj[ed.second].push_back(ed.first);
            }

            for (auto &ed : per) {
                if (knowsecret[ed.first] && !vis.count(ed.first)) {
                    q.push(ed.first);
                    vis.insert(ed.first);
                }
                if (knowsecret[ed.second] && !vis.count(ed.second)) {
                    q.push(ed.second);
                    vis.insert(ed.second);
                }
            }

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (!knowsecret[v] && !vis.count(v)) {
                        knowsecret[v] = true;
                        vis.insert(v);
                        q.push(v);
                    }
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (knowsecret[i]) result.push_back(i);
        }
        return result;
    }
};
