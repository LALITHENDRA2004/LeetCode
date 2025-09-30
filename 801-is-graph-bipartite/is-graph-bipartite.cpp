class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        queue<int> q;

        for(int i = 0 ; i < graph.size() ; i++) {
            if(color[i] == -1) {
                q.push(i);
                color[i] = 0;

                while(!q.empty()) {
                    int parent = q.front();
                    q.pop();

                    for(int child : graph[parent]) {
                        if(color[child] != -1) {
                            if (color[child] == color[parent]) return false;
                        }
                        else {
                            q.push(child);
                            color[child] = color[parent] ^ 1;
                        }
                    }
                }
            }
        }

        return true;
    }
};