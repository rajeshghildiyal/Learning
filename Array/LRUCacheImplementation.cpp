#include <stdio.h>
#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;

class LRUCache
{
    int m_numOfStrings;
    list<string> m_cache;
    
    unordered_map<string, list<string>::iterator> m_stringMap;
    
public:
    
    LRUCache(int n) : m_numOfStrings(n)
    {}
    
    void ReadString(const string& str)
    {
        // String present in cache
        auto itr = m_stringMap.find(str);
        if (itr != m_stringMap.end())
        {
            m_cache.erase(itr->second);
        }
        else if (m_cache.size() == m_numOfStrings)
        {
            auto itr = m_cache.back();
            m_cache.pop_back();
            m_stringMap.erase(itr);
        }
        
        m_cache.push_front(str);
        m_stringMap[str] = m_cache.begin();
    }
    
    void DisplayCache()
    {
        cout << "Cache Content" << endl;
        for (auto str : m_cache)
        {
            cout << str << " ";
        }
        cout << endl;
    }
};

int main()
{
    LRUCache lru(3);
    lru.ReadString("abc");
    lru.DisplayCache();
    lru.ReadString("abc");
    lru.DisplayCache();
    lru.ReadString("abc");
    
    lru.DisplayCache();
    
    lru.ReadString("abc");
    lru.DisplayCache();
    
    lru.ReadString("abc");
    lru.DisplayCache();
    
    lru.ReadString("abc");
    lru.DisplayCache();
    
    return 0;
}
