#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class Node{
    public:
        int ID;
        int weight;
        Node(int ID, int weight): ID(ID), weight(weight) {}
    };
    
    struct CompareNode {
        bool operator()(const Node &lhs, const Node &rhs) const {
            return lhs.weight > rhs.weight; // top element is going to be minimum. This is min_heap. Default is max_healp.
        }
    };
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<pair<int, int>> g[N + 1]; // As node starting from 1 and not 0.
        priority_queue<Node, vector<Node>, CompareNode> pq;
        // Create graph adjacency list
        for (auto &v : times) {
            g[v[0]].push_back(make_pair(v[1], v[2]));
        }
        
        // Push staring node in priority queue.
        pq.push(Node(K, 0));
        vector<int> weights(N+1, INT_MAX);
        weights[K] = 0;
        
        while(!pq.empty()) {
            Node t = pq.top();
            pq.pop();
            for(auto &p : g[t.ID]) {
                int new_weight =  t.weight + p.second;
                if (weights[p.first] > new_weight) {
                    weights[p.first] = new_weight;
                    pq.push(Node(p.first, new_weight));
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
  
    Solution s;
    cout << "networkDelayTime = " << s.networkDelayTime(times, 4, 2);

  return 0;
}
