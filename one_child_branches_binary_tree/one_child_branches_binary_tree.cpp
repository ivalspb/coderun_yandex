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
    };
    btree_node Head;

    void ins_btree(int x, btree_node* vertex)
    {
        if (!vertex->val)
        {
            vertex = new btree_node;
            vertex->val = x;
        }
        else
        {
            if (x != vertex->val)
            {
                if (x < vertex->val)
                    ins_btree(x, vertex->left);
                else// if (x > vertex->val)
                    ins_btree(x, vertex->right);
            }
        }
    }

};


int main()
{
    int num;
    btree btr;
    do
    {
        cin >> num;
        if (num) 
            btr.ins_btree(num,&btr.Head);
    } while (num);
    set<int> res;

    return 0;
}
