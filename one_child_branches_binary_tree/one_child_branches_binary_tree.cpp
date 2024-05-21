/*
* 124. Вывод листьев

* 
Для бинарного дерева поиска, построенного на заданных элементах, выведите список всех вершин, имеющих только одного ребёнка, в порядке возрастания.

Формат ввода
Вводится последовательность целых чисел,оканчивающаяся нулем. Построить по ней дерево.

Формат вывода
Выведите список требуемых вершин.
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
        if(!vertex) vertex = new btree_node;
        if (!vertex->val)
        {
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
    btree btr{};
    do
    {
        cin >> num;
        if (num) 
            btr.ins_btree(num,btr.Head);
    } while (num);
    set<int> res;

    return 0;
}
