#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

bool balanced(int small[], int caps[])
{
    for (int i = 0; i < 26; i++)
    {
        if ((small[i] && !caps[i]) || (caps[i] && !small[i]))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    string s("azABaabba");
    int small[26];
    int caps[26];
    
    memset(small, 0, sizeof(small));
    memset(caps, 0, sizeof(caps));
    
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 65 and s[i] <= 90)
        {
            caps[s[i] - 'A']++;
        }
        else
        {
            small[s[i] - 'a']++;
        }
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (small[i] && !caps[i])
        {
            mp[char(i + 'a')] = 1;
        }
        else if (!small[i] && caps[i])
        {
            mp[char(i + 'A')] = 1;
        }
    }
    
    memset(small, 0 , sizeof(small));
    memset(caps, 0, sizeof(caps));
    
    int start = -1;
    int end = -1;
    int i = 0;
    int st = 0;
    
    int minm = INT_MAX;
    while(i < s.length())
    {
        if (mp[s[i]])
        {
            while(st < i)
            {
                if (s[st] >= 65 && s[st] <= 90)
                {
                    caps[s[st] - 'A']--;
                }
                else
                {
                    small[s[st] - 'a']--;
                }
                st++;
            }
            ++i;
            st = i;
        }
        else
        {
           if (s[i] >= 65 && s[i] <= 90)
           {
               caps[s[i] - 'A']++;
           }
           else
           {
               small[s[i] - 'a']++;
           }
           
           while(1)
           {
               if (s[st] >= 65 && s[st] <= 90 && caps[s[st] - 'A'] > 1)
               {
                   caps[s[st] - 'A']--;
                   st++;
               }
               else if (s[st] >= 97 && s[st] <= 122 && small[s[st] - 'a'] > 1)
               {
                   small[s[st] - 'a']--;
                   st++;
               }
               else
               {
                   break;
               }
           }
           
           if (balanced(small, caps))
           {
               if (minm > i - st + 1)
               {
                   minm = i - st + 1;
                   start = st;
                   end = i;
               }
           }
           ++i;
        }
    }
    
    string ans;
    if (start == -1 || end == -1)
    {
        return -1;
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            ans += s[i];
        }
        cout << "Answer - " << ans << endl;
        cout << "Length - " << minm << endl;
    }
    return 0;
}
