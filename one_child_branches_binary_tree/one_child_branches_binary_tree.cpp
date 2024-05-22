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
//#include <map>
#include <queue>

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

void bfs(const btree& btr, queue<btree::btree_node*>visited,  btree::btree_node* vertex, set<int>& res)
{
    visited.push(vertex);
    if (!(vertex->left && vertex->right)) 
        res.insert(vertex->val);
    if (vertex->left)
        bfs(btr, visited, vertex->left, res);
    if (vertex->right)
        bfs(btr, visited, vertex->right, res);

}

int main()
{
    int num;
    btree btr{};
    queue<btree::btree_node*>visited;
    do
    {
        cin >> num;
        if (num) 
        {
            btr.ins_btree(num, btr.Head);
        }
    } while (num);
    set<int> res;
    bfs(btr, visited, btr.Head, res);

    return 0;
}
