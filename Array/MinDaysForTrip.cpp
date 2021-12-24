#include <stdio.h>
#include <map>
#include <vector>
#include <set>
#include <limits.h>
#include <iostream>
using namespace std;

bool AllDestVisited(map<int, int>& destMap, set<int>& dests)
{
    for (auto e : dests)
    {
        if (destMap.find(e) == destMap.end())
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> A = {2,1,1,3,3,4,2,1,2,1,2,2,3,4};
    map<int, int> destMap;
    int minDays = INT_MAX;
    int startIndex = 0;
    set <int> dests;
    
    for (auto item : A)
    {
        dests.insert(item - 1);
    }
    
    for (int i = 0; i < A.size(); i++)
    {
        destMap[A[i] - 1]++;
        
        while (destMap[A[startIndex] - 1] > 1)
        {
            destMap[A[startIndex] - 1]--;
            ++startIndex;
        }
        
        if (AllDestVisited(destMap, dests))
        {
            minDays = min(minDays, i - startIndex + 1);
        }
    }
    cout << "Min days = " << minDays;
    return minDays;
}
