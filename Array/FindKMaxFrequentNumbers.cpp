#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <map>

// This is optional as by default priority_queue is max_heap. Use > to make it min_heap.
class Comparator
{
public:
    bool operator()(const pair<int, int>& left, const pair<int, int>& right)
    {
       return ((left.first < right.first) || ((left.first == right.first) && (left.second < right.second))) ? true : false;
    }
};

void FindKMaxFrequencyNumbers(vector<int>& arr, int k, vector<int>& res)
{
   priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> pq;
   map<int, int> frequencyMap;
  
   for (auto& element : arr)
   {
      frequencyMap[element]++;
   }
  
   for (auto& element : frequencyMap)
   {
      pq.push(make_pair(element.second, element.first));
   }
  
   while(k--)
   {
      auto& val = pq.top();
      //cout << val.second << " ";
      res.push_back(val.second);
      pq.pop();
   }
}

int main() {
  
  vector<int> arr = {3, -1, -4, -4, 5, 2, 6, -1, -4, -1, -5, -1};
  int k = 5;
  vector<int> res;
  FindKMaxFrequencyNumbers(arr, k, res);
  for (auto& element : res)
  {
    cout << element << " ";
  }
  return 0;
}
