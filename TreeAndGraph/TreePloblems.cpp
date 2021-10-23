#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>

using namespace std;

struct node
{
    int data;
    int hd;
    node *left, *right;
    
    node(int val) : data(val), hd(0), left(nullptr), right(nullptr)
    {}
};

class LeftViewOfTree
{
int maxLevel = -1;

public:
void LeftView(node* root, int level, std::list<int>& result)
{
    if (root == nullptr)
    {
        return;
    }
        
    if (maxLevel < level)
    {
        maxLevel = level;
        result.push_front(root->data);
    }
    
    LeftView(root->left, level + 1, result);
    //LeftView(root->right, level + 1, result);
}
};

class RightViewOfTree
{
    
int maxLevel = -1;

public:
void RightView(node* root, int level, std::list<int>& result)
{
    if (root == nullptr)
    {
        return;
    }
        
    if (maxLevel < level)
    {
        maxLevel = level;
        result.push_back(root->data);
    }
    
    RightView(root->right, level + 1, result);
    //LeftView(root->right, level + 1, result);
}
};

class BottomViewOfTree
{
    public:
    void BottomView(node* root, std::map<int, int>& m, int hd)
    {
        if (!root)
        {
            return;
        }
        
        m[hd] = root->data;
        
        BottomView(root->left, m, hd - 1);
        BottomView(root->right, m, hd + 1);
    }
};

class TopViewOfTree
{
    public:
    void TopView(node* root, map<int, int>& m, int hd)
    {
        if (!root)
        {
            return;
        }
        
        //m.insert(std::make_pair(hd, root->data));
        if (m.count(hd) == 0)
        {
            m[hd] = root->data;
        }
        TopView(root->left, m, hd - 1);
        TopView(root->right, m, hd + 1);
    }
    
    void TopViewInterative(node* root)
    {
        if (!root)
        {
            return;
        }
        
        map<int, int> m;
        std::queue<node*> q;
        root->hd = 0;
        q.push(root);
        
        while(!q.empty())
        {
            node* curr = q.front();
            q.pop();
            
            if (!m.count(curr->hd))
            {
                m[curr->hd] = curr->data;
            }
            
            if (curr->left)
            {
                curr->left->hd = curr->hd - 1;
                q.push(curr->left);
            }
            
            if (curr->right)
            {
                curr->right->hd = curr->hd + 1;
                q.push(curr->right);
            }
        }
        
        cout << "\nTop View Iterative way  - ";
        for (auto key : m)
        {
            cout << key.second << " ";
        }
    }
};

class SpiralViewOfTree
{
    int height(node* root)
    {
        if (!root)
        {
            return 0;
        }
        
        int lh = height(root->left);
        int rh = height(root->right);
        return (lh > rh) ? lh + 1 : rh + 1;
    }
    
    void PrintGivenLevel(node* root, int level, bool order)
    {
        if (!root)
        {
            return;
        }
        else if (level == 0)
        {
            cout << root->data << " ";
        }
        else
        {
            if (order)
            {
                PrintGivenLevel(root->left, level - 1, order);
                PrintGivenLevel(root->right, level - 1, order);
            }
            else
            {
                PrintGivenLevel(root->right, level - 1, order);
                PrintGivenLevel(root->left, level - 1, order);   
            }
        }
    }
    
    public:
    void SpiralView(node* root)
    {
        int h = height(root);
        bool order = false;
        for (int i = 0; i < h; i++)
        {
            PrintGivenLevel(root, i, order);
            order = !order;
        }
    }
    
    void SpiralViewIterative(node* root)
    {
        if (!root)
        {
            return;
        }
        
        stack<node*> s1, s2;
        s1.push(root);
        
        while(!s1.empty() || !s2.empty())
        {
            while(!s1.empty())
            {
                node* curr = s1.top();
                cout << curr->data << " ";
                s1.pop();
                                    
                if (curr->right)
                {
                    s2.push(curr->right);
                }
                if (curr->left)
                {
                    s2.push(curr->left);
                }

            }
            
            while(!s2.empty())
            {
                node* curr = s2.top();
                cout << curr->data << " ";
                s2.pop();
                
                if (curr->left)
                {
                    s1.push(curr->left);
                }
                
                if (curr->right)
                {
                    s1.push(curr->right);
                }
            }
        }
    }
    
    void SpiralViewUsingDQ(node* root)
    {
        if (!root)
        {
            return;
        }
        
        std::list<node*> dq;
        dq.push_back(root);
        
        bool reverse = true;
        
        while(!dq.empty())
        {
            int n = dq.size();
            if (!reverse)
            {
                while(n-- > 0)
                {
                    node* curr = dq.front();
                    cout << curr->data << " ";
                    dq.pop_front();
                    
                    if (curr->left)
                    {
                        dq.push_back(curr->left);
                    }
                    if (curr->right)
                    {
                        dq.push_back(curr->right);
                    }
                }
                reverse = !reverse;
            }
            else
            {
                while(n-- > 0)
                {
                    node* curr = dq.back();
                    cout << curr->data << " ";
                    dq.pop_back();
                    
                    if (curr->right)
                    {
                        dq.push_front(curr->right);
                    }
                    if (curr->left)
                    {
                        dq.push_front(curr->left);
                    }
                    reverse = !reverse;
                }
            }
        }
    }
};

class MirrorTree
{
private:
    void Mirror(node* root)
    {
        if (!root)
        {
            return;
        }
        
        Mirror(root->left);
        Mirror(root->right);
        
        node* temp = root->left;
        root->left = root->right;
        root->right = root->left;
    }
    
public:
    void MirrorTree(node* root)
    {
        Mirror(root);
    }
    
    void MirrorIterative(node* root)
    {
        if(!root)
        {
            return;
        }
        
        std::queue<node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            node* curr = q.front();
            q.pop();
            
            swap(curr->left, curr->right);
            
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }
};

class MirrorTree
{
public:
    bool AreMirror(node* root1, node* root2)
    {
        if (!root1 && !root2)
        {
            return true;
        }
        
        if (!root1 || !root2)
        {
            return false;
        }
        
        return (root1->data == root2->data) &&
                AreMirror(root1->left, root2->right) &&
                AreMirror(root1->right, root2->left);
    }
};

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    
    root->left->left = new node(4);
    root->left->right = new node(5);
    
    root->right->right = new node(6);
    
    std::list<int> result;
    LeftViewOfTree* left = new LeftViewOfTree();
    left->LeftView(root->left, 0, result);
    
    RightViewOfTree* right = new RightViewOfTree();
    right->RightView(root, 0, result);

    cout << "OutlineView of tree is - "; 
    for(auto key : result)
    {
        cout << key << " ";
    }
    delete left;
    delete right;
    
    BottomViewOfTree bottomView;
    map<int, int> m;
    bottomView.BottomView(root, m, 0);
    cout << "\nBottomView of tree is - "; 
    for(auto key : m)
    {
        cout << key.second << " ";
    }
    
    TopViewOfTree topView;
    m.clear();
    topView.TopView(root, m, 0);
    cout << "\nTopView of tree is - "; 
    for(auto key : m)
    {
        cout << key.second << " ";
    }
    
    topView.TopViewInterative(root);
    
    cout << "\nSpiralView of tree is - ";
    SpiralViewOfTree spiralView;
    spiralView.SpiralView(root);
    
    cout << "\nSpiralView Iterative of tree is - ";
    spiralView.SpiralViewIterative(root);
    
    cout << "\nSpiralView DQ of tree is - ";
    spiralView.SpiralViewUsingDQ(root);
    return 0;
}
