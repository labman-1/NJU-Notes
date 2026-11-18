// 二叉搜索树 BST：查找/插入/删除 + 中序遍历
// 编译: g++ -std=c++17 BST.cpp -o bst && ./bst
// 对拍验证: g++ -std=c++17 -DSTRESS BST.cpp -o bst_stress && ./bst_stress
#include <cstdio>
using namespace std;

struct BST {
    struct Node { int val; Node *l, *r; Node(int v):val(v),l(nullptr),r(nullptr){} };
    Node* root = nullptr;

    // 查找 O(h)：沿"左小右大"一路下降；h 为树高，最坏退化成 O(n)
    bool find(int x) {
        Node* p = root;
        while (p && p->val != x) p = x < p->val ? p->l : p->r;
        return p != nullptr;
    }
    // 插入 O(h)：递归插入子树、返回子树新根，父链自动接好（相等则忽略）
    Node* _insert(Node* t, int x) {
        if (!t) return new Node(x);
        if (x < t->val) t->l = _insert(t->l, x);
        else if (x > t->val) t->r = _insert(t->r, x);
        return t;
    }
    void insert(int x) { root = _insert(root, x); }

    // 删除 O(h)，三种情况：
    //  ①叶子 ②独子：孩子顶替（叶子的"孩子"是空，正好统一处理）
    //  ③双孩子：用中序前驱(左子树最大)的值替换，再转去左子树删前驱
    Node* _erase(Node* t, int x) {
        if (!t) return nullptr;
        if (x < t->val) t->l = _erase(t->l, x);
        else if (x > t->val) t->r = _erase(t->r, x);
        else {
            if (!t->l || !t->r) {              // 情况①②
                Node* ch = t->l ? t->l : t->r;
                delete t;
                return ch;
            }
            Node* pre = t->l;                  // 情况③：找中序前驱
            while (pre->r) pre = pre->r;
            t->val = pre->val;                 // 只换值，不动结构
            t->l = _erase(t->l, pre->val);
        }
        return t;
    }
    void erase(int x) { root = _erase(root, x); }

    // 中序遍历必有序 —— 这是 BST 的灵魂性质，一切平衡树都靠它
    void inorder(Node* t) {
        if (!t) return;
        inorder(t->l); printf("%d ", t->val); inorder(t->r);
    }
    void print() { inorder(root); printf("\n"); }
};

#ifdef STRESS
#include <cassert>
#include <random>
#include <set>
#include <vector>
int main() {
    mt19937 rng(12345);
    for (int round = 0; round < 20; round++) {
        BST t; set<int> s;
        for (int i = 0; i < 3000; i++) {
            int op = rng() % 3, x = (int)(rng() % 400);
            if (op == 0) { t.insert(x); s.insert(x); }
            else if (op == 1) { t.erase(x); s.erase(x); }
            else assert(t.find(x) == (s.count(x) > 0));
        }
        vector<int> v;
        BST::Node* stk[1000]; int top = 0;     // 手动栈收集中序，避免递归
        auto* p = t.root;
        while (p || top) {
            while (p) { stk[top++] = p; p = p->l; }
            p = stk[--top]; v.push_back(p->val); p = p->r;
        }
        assert(v == vector<int>(s.begin(), s.end()));
    }
    puts("BST STRESS OK");
    return 0;
}
#else
int main() {
    BST t;
    int a[] = {5, 3, 8, 1, 4, 7, 9, 2};
    for (int x : a) t.insert(x);
    t.print();                    // 期望: 1 2 3 4 5 7 8 9
    t.erase(5);                   // 删有两个孩子的根
    t.print();                    // 期望: 1 2 3 4 7 8 9
    t.erase(1);                   // 删叶子
    t.print();                    // 期望: 2 3 4 7 8 9
    printf("find 7: %s, find 6: %s\n", t.find(7) ? "yes" : "no",
           t.find(6) ? "yes" : "no");
    return 0;
}
#endif
