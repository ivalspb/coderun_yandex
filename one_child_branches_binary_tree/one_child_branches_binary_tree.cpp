/*
* 124. ����� �������

* 
��� ��������� ������ ������, ������������ �� �������� ���������, �������� ������ ���� ������, ������� ������ ������ ������, � ������� �����������.

������ �����
�������� ������������������ ����� �����,�������������� �����. ��������� �� ��� ������.

������ ������
�������� ������ ��������� ������.
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct btree
{
    struct btree_node
    {
        int val=0;
        btree_node *left=nullptr, *right=nullptr;
       /* btree_node() { new btree_node; }
        ~btree_node() { delete this; }*/
    };
    btree_node *Head;

    btree() {
        Head = new btree_node;
    }
    ~btree() {
        delete Head;
    }

    void ins_btree(int x, btree_node* vertex)
    {
        
        if (!vertex->val)
        {
            vertex->val = x;
        }
        else
        {
            if (x != vertex->val)
            {
                if (x < vertex->val)
                {
                    if(!vertex->left) 
                        vertex->left= new btree_node;
                    ins_btree(x, vertex->left);
                }
                else// if (x > vertex->val)
                {
                    if (!vertex->right) 
                        vertex->right = new btree_node;
                    ins_btree(x, vertex->right);
                }
            }
        }
    }

};

void dfs(const btree& btr, vector<int>& visited,  btree::btree_node* vertex, set<int>& res)
{
    if (!(vertex->left && vertex->right))
    {
        res.insert(vertex->val);
        visited.push_back(vertex->val);
    }
    else if (vertex->left)
        dfs(btr, visited, vertex->left, res);
}

int main()
{
    int num;
    btree btr{};
    size_t sz = 0;
    do
    {
        cin >> num;
        if (num) 
        {
            sz++;
            btr.ins_btree(num, btr.Head);
        }
    } while (num);
    set<int> res;
    vector<int>visited(sz);


    return 0;
}
