class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        priority_queue<int> pq1(players.begin(), players.end()), pq2(trainers.begin(), trainers.end());
        long long matchings = 0;
        while(!pq1.empty() && !pq2.empty()) {
            if(pq1.top() <= pq2.top()) {
                matchings++;
                pq2.pop();
            }
            pq1.pop();
        }
        return matchings;
    }
};