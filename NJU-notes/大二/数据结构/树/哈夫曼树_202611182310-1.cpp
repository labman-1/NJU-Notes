// AVL 树：带高度的自平衡 BST。四种失衡 LL/RR/LR/RL，旋转修复。
// 编译: g++ -std=c++17 AVL.cpp -o avl && ./avl
// 对拍验证: g++ -std=c++17 -DSTRESS AVL.cpp -o avl_stress && ./avl_stress
#include <cstdio>
#include <algorithm>
using namespace std;

struct AVL {
    struct Node { int val, h; Node *l, *r; Node(int v):val(v),h(1),l(nullptr),r(nullptr){} };
    Node* root = nullptr;

    static int H(Node* t) { return t ? t->h : 0; }             // 空树高度记 0
    static int bf(Node* t) { return H(t->l) - H(t->r); }       // 平衡因子: 左高-右高
    static void pull(Node* t) { t->h = max(H(t->l), H(t->r)) + 1; }

    // 右旋(处理 LL)：左孩子 p 上提，p 的右子树挂给 t 的左边
    //        t              p
    //       / \            / \
    //      p   C   =>     A   t
    //     / \                / \
    //    A   B              B   C
    static Node* rotR(Node* t) {
        Node* p = t->l;
        t->l = p->r; p->r = t;
        pull(t); pull(p);              // 先更新变成儿子的 t，再更新新根 p
        return p;
    }
    static Node* rotL(Node* t) {       // 左旋(处理 RR)，与右旋完全对称
        Node* p = t->r;
        t->r = p->l; p->l = t;
        pull(t); pull(p);
        return p;
    }

    Node* _insert(Node* t, int x) {
        if (!t) return new Node(x);
        if (x < t->val) t->l = _insert(t->l, x);
        else if (x > t->val) t->r = _insert(t->r, x);
        else return t;
        pull(t);                                   // 回溯路上更新高度
        // 插入只会让平衡因子变为 +2 或 -2，四种情况：
        if (bf(t) > 1 && x < t->l->val) return rotR(t);            // LL: 右旋一次
        if (bf(t) < -1 && x > t->r->val) return rotL(t);           // RR: 左旋一次
        if (bf(t) > 1 && x > t->l->val) {                          // LR: 先左后右
            t->l = rotL(t->l); return rotR(t);
        }
        if (bf(t) < -1 && x < t->r->val) {                         // RL: 先右后左
            t->r = rotR(t->r); return rotL(t);
        }
        return t;                                  // 插入最多一次旋转即恢复
    }
    void insert(int x) { root = _insert(root, x); }

    // 删除：先按 BST 删除，回溯路上重新平衡。
    // 与插入不同：失衡可能一路向上传播，最坏旋转 O(log n) 次！
    // 判断失衡类型不能看"删的值从哪边来"，要看较高一侧孩子的 bf：
    Node* _erase(Node* t, int x) {
        if (!t) return nullptr;
        if (x < t->val) t->l = _erase(t->l, x);
        else if (x > t->val) t->r = _erase(t->r, x);
        else {
            if (!t->l || !t->r) {
                Node* ch = t->l ? t->l : t->r;
                delete t;
                return ch;
            }
            Node* pre = t->l;
            while (pre->r) pre = pre->r;
            t->val = pre->val;
            t->l = _erase(t->l, pre->val);
        }
        if (!t) return nullptr;                    // 删完可能整棵没了
        pull(t);
        if (bf(t) > 1 && bf(t->l) >= 0) return rotR(t);            // LL(含 L0): 右旋
        if (bf(t) > 1) { t->l = rotL(t->l); return rotR(t); }      // LR: 双旋
        if (bf(t) < -1 && bf(t->r) <= 0) return rotL(t);           // RR(含 R0): 左旋
        if (bf(t) < -1) { t->r = rotR(t->r); return rotL(t); }     // RL: 双旋
        return t;
    }
    void erase(int x) { root = _erase(root, x); }

    bool find(int x) {
        Node* p = root;
        while (p && p->val != x) p = x < p->val ? p->l : p->r;
        return p != nullptr;
    }

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
int realH(AVL::Node* t) { return t ? max(realH(t->l), realH(t->r)) + 1 : 0; }
bool checkBalance(AVL::Node* t) {   // 每个节点 |bf|<=1 且缓存高度正确
    if (!t) return true;
    if (abs(realH(t->l) - realH(t->r)) > 1) return false;
    if (t->h != realH(t)) return false;
    return checkBalance(t->l) && checkBalance(t->r);
}
void collect(AVL::Node* t, vector<int>& v) {
    if (!t) return;
    collect(t->l, v); v.push_back(t->val); collect(t->r, v);
}
int main() {
    mt19937 rng(12345);
    for (int round = 0; round < 20; round++) {
        AVL t; set<int> s;
        for (int i = 0; i < 3000; i++) {
            int op = rng() % 3, x = (int)(rng() % 400);
            if (op == 0) { t.insert(x); s.insert(x); }
            else if (op == 1) { t.erase(x); s.erase(x); }
            else assert(t.find(x) == (s.count(x) > 0));
            assert(checkBalance(t.root));           // 每一步都是合法 AVL
        }
        vector<int> v; collect(t.root, v);
        assert(v == vector<int>(s.begin(), s.end()));
    }
    puts("AVL STRESS OK");
    return 0;
}
#else
int main() {
    AVL t;
    // 依次插入 1..10：裸 BST 会退化成链，AVL 边插边旋，始终保持 |bf|<=1
    for (int x = 1; x <= 10; x++) t.insert(x);
    t.print();                    // 期望: 1 2 3 4 5 6 7 8 9 10
    printf("root=%d h=%d\n", t.root->val, t.root->h);   // 高度 O(log n)
    t.erase(5); t.erase(6);
    t.print();                    // 期望: 1 2 3 4 7 8 9 10
    return 0;
}
#endif
