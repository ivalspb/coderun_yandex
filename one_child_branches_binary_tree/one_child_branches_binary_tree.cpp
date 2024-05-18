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
    int val;
    btree_node* parent, *left, *right;
};
btree_node Head;

bool greater_branch(int x, btree_node* vertex)
{
    if (x > vertex->val) return false;
    if (vertex->left == nullptr && vertex->right == nullptr) return true;
    if (!vertex->left) return greater_branch(x, vertex->right);
    if (!vertex->right) return greater_branch(x, vertex->left);
    return greater_branch(x, vertex->left) && greater_branch(x, vertex->right);
}

bool less_branch(int x, btree_node* vertex)
{
    if (x < vertex->val) return false;
    if (vertex->left == nullptr && vertex->right == nullptr) return true;
    if (!vertex->left) return less_branch(x, vertex->right);
    if (!vertex->right) return less_branch(x, vertex->left);
    return less_branch(x, vertex->left) && less_branch(x, vertex->right);
}


void ins_btree(int x, btree_node* vertex)
{
    if (x != vertex->val)
    {
        btree_node* new_node = new btree_node;
        if()
    }
}

};


int main()
{
    int num;
    vector<btree_node>v;
    do
    {
        cin >> num;
        if (num) 
            //v.push_back(num);
    } while (num);
    set<int> res;

    return 0;
}
