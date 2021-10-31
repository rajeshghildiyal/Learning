#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool DivideArrayIntoHalf(std::vector<int>& a, map<int, int>& first, map<int, int>& second)
{
    int S = 0;
    for (auto& e : a)
    {
        S += e;
    }
    
    // Odd sum, so not possible to divide equally.
    if (S&1)
    {
        return false;
    }

    
    first[a[0]] = 1;
    for (int i = 1; i < a.size(); i++)
    {
        second[a[i]]++;
    }
    
    int sDash = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sDash += a[i];
        if (sDash == S/2)
        {
            return true;
        }
        else if (sDash < S/2)
        {
            int x = (S/2) - sDash;
            if (second[x] > 0)
            {
                // Remove element from second and add to first;
                first[x]++;
                second[x]--;
                return true;
            }
        }
        else
        {
            int x = sDash - (S / 2);
            if (first[x] > 0)
            {
                // Remove element from first and add to second.
                first[x]--;
                second[x]++;
                return true;
            }
        }
        first[a[i+1]]++;
        second[a[i+1]]--;
    }
    return 0;
}

int main()
{
    std::vector<int> a = {1,2,4,5,1,3};
    map<int, int> first, second;
    
    if (DivideArrayIntoHalf(a, first, second))
    {
        cout << "First Half - ";
        for (auto& e : first)
        {
            if (e.second)
            {
                cout << e.first << " ";
            }
        }
    
        cout << "Second Half - ";
        for (auto& e : second)
        {
            if (e.second)
            {
                cout << e.first << " ";
            }
        }
    }
    else
    {
        cout << "Not possible to divide";
    }
}
