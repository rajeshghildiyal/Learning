#include <stdio.h>
#include <map>
#include <iostream>

using namespace std;

class interval_map
{
private:
    map<int, char> m_map;
    char m_valBegin;
    
public:

    interval_map(char val) : m_valBegin(val)
    {}
    
    const map<int, char>& GetMap()
    {
        return m_map;
    }
    
	  void assign(int const& keyBegin, int const& keyEnd, char const& val ) 
	  {
        if (!(keyBegin < keyEnd))
        {
            return;
        }
        
        auto keyBeginLb = m_map.lower_bound(keyBegin);
        auto keyEndLb = m_map.lower_bound(keyEnd);
        auto keyEndUb = m_map.upper_bound(keyEnd);
        
        bool insertBegin = true;
        
        if (keyBeginLb == keyEndLb)
        {
            if (keyBeginLb != m_map.end())
            {
                // Do this only if KeyEnd and keyEnd lower_bound values are different.
                // When both are same, just erase existing entry for value.
                if (val == keyBeginLb->second)
                {
                    m_map.erase(keyBeginLb);
                }
                
                if (keyBeginLb == m_map.begin() && val == m_valBegin)
                {
                    insertBegin = false;
                }
                
                if (insertBegin)
                {
                    auto temp = keyBeginLb->second;
                    if (keyEnd < keyEndLb->first)
                    {
                        temp = (--keyBeginLb)->second;
                    }
                    m_map[keyEnd] = temp;
                }
            }
            else
            {
                if (m_valBegin == val)
                {
                    insertBegin = false;
                }
                m_map[keyEnd] = m_valBegin;
            }
        }
        else
        {
            bool insert = false;
            char insertVal = m_valBegin;
            
            if (keyEndLb != m_map.end())
            {
                if (keyEndLb == keyEndUb)
                {
                    insertVal = (--keyEndLb)->second;
                }
                else
                {
                    insertVal = keyEndLb->second;
                }
                
                if (keyBeginLb == m_map.begin() && val == m_valBegin)
                {
                    insertBegin = false;
                }
                
                if (!(val == keyEndLb->second))
                {
                    insert = true;
                }
                // Remove keyEndLb as well, therefore ++ on keyEndLb.
                ++keyEndLb;
            }
            else
            {
                insertVal = (--keyEndLb)->second;
                
                if ( !(val == insertVal))
                {
                    insert = true;
                }
            }
            // Erase all elements from keyBeginLb to keyEndLb
            m_map.erase(keyBeginLb, keyEndLb);
            
            if (insert)
            {
                m_map[keyEnd] = insertVal;
            }
        }
        
        if (insertBegin)
        {
            m_map[keyBegin] = val;
        }
	  }
};
	
int main()
{
    interval_map myMap('A');

    myMap.assign(1, 50, 'B');
    myMap.assign(50, 100, 'C');
    myMap.assign(50, 60, 'D');
    myMap.assign(55, 60, 'E');
    myMap.assign(40, 60, 'D');
    myMap.assign(-10, 10, 'F');
    myMap.assign(40, 49, 'G');
    myMap.assign(-15, -5, 'A');
    myMap.assign(-15, -10, 'A');
    myMap.assign(50, 51, 'K');
    
    for (auto& e : myMap.GetMap())
    {
        cout << "Key - " << e.first << ", Value - " << e.second << endl;
    }
    return 0;
}
