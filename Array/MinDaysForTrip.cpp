#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> A = {2,1,1,3,2,1,4,3,1,2};
    vector<int> destIndexCounter(A.size(), 0);
    
    if (A.size() <= 1)
    {
        return A.size();
    }
    
    int startDayIndex = 0;
    int endDayIndex = 0;
    
    for (int i = 0; i < A.size(); i++)
    {
        destIndexCounter[A[i] - 1]++;
        
        if (A[i] == A[i-1])
        {
            continue;
        }
        
        endDayIndex = i;
        
        while (destIndexCounter[A[startDayIndex] - 1] > 1)
        {
            destIndexCounter[A[startDayIndex] - 1]--;
            startDayIndex++;
        }
    }
    
    cout << "Min days = " << endDayIndex - startDayIndex + 1;

    return 0;
}
