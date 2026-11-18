// 红黑树：近似平衡的 BST（std::map/set 的底层数据结构）
// 五条性质：
//  ①节点非红即黑 ②根是黑 ③叶(nil哨兵)是黑 ④红节点孩子必黑(无连续红) ⑤任一节点到其后代叶子的路径上黑节点数相同(黑高一致)
// 由④⑤可证 h <= 2*log2(n+1)：查找仍是 O(log n)，但修改时代价比 AVL 低(插入至多 2 次旋转)
// 本模板实现插入；删除情况多、代码长，工程中直接用 std::map，考试掌握删除思想即可
// 编译: g++ -std=c++17 红黑树.cpp -o rb && ./rb
// 对拍验证: g++ -std=c++17 -DSTRESS 红黑树.cpp -o rb_stress && ./rb_stress
#include <cstdio>
using namespace std;

struct RBTree {
    struct Node { int val; bool red; Node *l, *r, *pa; };
    Node* nil;    // 哨兵：黑色，代替一切空指针，父子链永不为空，省掉大量判空
    Node* root;

    RBTree() {
        nil = new Node{0, false, nullptr, nullptr, nullptr};
        nil->l = nil->r = nil->pa = nil;
        root = nil;
    }

    void rotL(Node* x) {          // 左旋：右孩子 y 上提
        Node* y = x->r;
        x->r = y->l;
        if (y->l != nil) y->l->pa = x;
        y->pa = x->pa;
        if (x->pa == nil) root = y;
        else if (x == x->pa->l) x->pa->l = y;
        else x->pa->r = y;
        y->l = x;
        x->pa = y;
    }
    void rotR(Node* x) {          // 右旋：左孩子 y 上提（与左旋对称）
        Node* y = x->l;
        x->l = y->r;
        if (y->r != nil) y->r->pa = x;
        y->pa = x->pa;
        if (x->pa == nil) root = y;
        else if (x == x->pa->l) x->pa->l = y;
        else x->pa->r = y;
        y->r = x;
        x->pa = y;
    }

    bool find(int x) {
        Node* p = root;
        while (p != nil && p->val != x) p = x < p->val ? p->l : p->r;
        return p != nil;
    }

    void insert(int v) {
        Node *y = nil, *x = root;             // 普通 BST 插入，新节点染红
        while (x != nil) {
            y = x;
            if (v == x->val) return;          // 已存在则忽略(CLRS 假设键互异，这里显式处理)
            x = v < x->val ? x->l : x->r;
        }
        Node* z = new Node{v, true, nil, nil, y};
        if (y == nil) root = z;
        else if (v < y->val) y->l = z;
        else y->r = z;
        insertFix(z);                         // 染红可能违反"无连续红"，向上修复
    }

    // 修复口诀（以 z 的父在祖父左侧为例，右侧对称）：
    //  叔红  → 父叔变黑、祖父变红，z 上移到祖父（只变色不旋转，可能继续向上）
    //  叔黑 + 之字(z 是右孩子) → 先左旋父，变成一字情形
    //  叔黑 + 一字(z 是左孩子) → 父变黑、祖父变红，右旋祖父 —— 结束
    void insertFix(Node* z) {
        while (z->pa->red) {                  // 父黑则已合法；父红则祖父必存在且黑
            Node* g = z->pa->pa;
            if (z->pa == g->l) {
                Node* u = g->r;               // 叔叔
                if (u->red) {                 // case 1: 叔红
                    z->pa->red = u->red = false;
                    g->red = true;
                    z = g;
                } else {
                    if (z == z->pa->r) { z = z->pa; rotL(z); }   // case 2: 之字转一字
                    z->pa->red = false; g->red = true;           // case 3: 一字
                    rotR(g);
                }
            } else {                          // 对称：父在祖父右侧
                Node* u = g->l;
                if (u->red) {
                    z->pa->red = u->red = false;
                    g->red = true;
                    z = g;
                } else {
                    if (z == z->pa->l) { z = z->pa; rotR(z); }
                    z->pa->red = false; g->red = true;
                    rotL(g);
                }
            }
        }
        root->red = false;                    // 性质②根必黑
    }

    void inorder(Node* t) {
        if (t == nil) return;
        inorder(t->l);
        printf("%d%c ", t->val, t->red ? 'r' : 'b');   // 顺便打印颜色
        inorder(t->r);
    }
    void print() { inorder(root); printf("\n"); }
};

#ifdef STRESS
#include <algorithm>
#include <cassert>
#include <random>
#include <set>
#include <vector>
int realH(RBTree::Node* t, RBTree::Node* nil) { return t == nil ? 0 : max(realH(t->l, nil), realH(t->r, nil)) + 1; }
// 检查④无连续红 ⑤黑高一致 BST序，返回黑高；返回 -1 表示违规
int check(RBTree::Node* t, RBTree::Node* nil) {
    if (t == nil) return 1;                        // 哨兵是黑，黑高记 1
    if (t->red && (t->l->red || t->r->red)) return -1;
    if (t->l != nil && t->l->val >= t->val) return -1;
    if (t->r != nil && t->r->val <= t->val) return -1;
    int lh = check(t->l, nil), rh = check(t->r, nil);
    if (lh == -1 || rh == -1 || lh != rh) return -1;
    return lh + (t->red ? 0 : 1);
}
void collect(RBTree::Node* t, RBTree::Node* nil, vector<int>& v) {
    if (t == nil) return;
    collect(t->l, nil, v); v.push_back(t->val); collect(t->r, nil, v);
}
int maxh = 0;
int main() {
    mt19937 rng(12345);
    for (int round = 0; round < 20; round++) {
        RBTree t; set<int> s;
        for (int i = 0; i < 3000; i++) {
            int x = (int)(rng() % 400);
            t.insert(x); s.insert(x);
            assert(!t.root->red);                  // 根必须黑
            assert(check(t.root, t.nil) != -1);    // 每步后五条性质均成立
            assert(t.find(x) && s.count(x));
        }
        vector<int> v; collect(t.root, t.nil, v);
        assert(v == vector<int>(s.begin(), s.end()));
        maxh = max(maxh, realH(t.root, t.nil));
    }
    printf("RBTree STRESS OK (max height = %d, 理论上界 2*log2(400+1)≈17)\n", maxh);
    return 0;
}
#else
int main() {
    RBTree t;
    for (int x = 1; x <= 10; x++) t.insert(x);   // 最容易触发各种修复 case 的序列
    t.print();                    // 期望中序: 1b 2r 3b 4r 5b 6r 7b 8r 9b 10r 之一(颜色可自行验证性质)
    printf("root=%d %s\n", t.root->val, t.root->red ? "red" : "black");
    return 0;
}
#endif
