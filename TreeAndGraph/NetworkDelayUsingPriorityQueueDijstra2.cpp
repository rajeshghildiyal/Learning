#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using Pair = std::pair<int, int>;
    struct CompareNode {
        bool operator()(const Pair &lhs, const Pair &rhs) const {
            return lhs.second > rhs.second;
        }
    };
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<pair<int, int>> g[N + 1]; // As node starting from 1 and not 0.
        priority_queue<Pair, vector<Pair>, CompareNode> pq;
        for (auto &v : times) {
            g[v[0]].push_back(make_pair(v[1], v[2]));
        }
        
        pq.push(make_pair(K, 0));
        vector<int> weights(N+1, INT_MAX);
        weights[K] = 0;
        
        while(!pq.empty()) {
            Pair t = pq.top();
            pq.pop();
            for(auto &p : g[t.first]) {
                int new_weight =  t.second + p.second;
                if (weights[p.first] > new_weight) {
                    weights[p.first] = new_weight;
                    pq.push(make_pair(p.first, new_weight));
                }
            }
        }
        
        int res = 0;
        for (int i = 1; i <= N; i++) {
            if (weights[i] == INT_MAX) return -1;
            res = max(res, weights[i]);
        }
        return res;
    }
};

int main ()
{
    vector<vector<int>> times;
    vector<int> t1 = {2,1,1};
    times.push_back(t1);
    
    vector<int> t2 = {2,3,1};
    times.push_back(t2);
    
    vector<int> t3 = {3,4,1};
    times.push_back(t3);
    
    int n = 4, k = 2;
  
    Solution s;
    cout << "networkDelayTime = " << s.networkDelayTime(times, 4, 2);

  return 0;
}
