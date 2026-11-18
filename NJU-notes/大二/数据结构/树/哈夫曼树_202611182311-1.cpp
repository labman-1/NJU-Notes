// 伸展树 Splay：不存任何平衡信息，靠"访问到的节点旋转到根"获得摊还 O(log n)
// 核心是 splay 操作的双旋策略：
//   一字型(自己、父亲、祖父同侧) → 先转父亲，再转自己
//   之字型(z 形)                 → 连转自己两次
//   父亲就是根                   → 单旋一次
// 为什么不一路单旋？单旋虽然也能到根，但访问路径长度不收缩，摊还界退化为 O(n)；
// 双旋每步都把访问路径长度减半，才能证明整个操作序列摊还 O(log n)。
// 编译: g++ -std=c++17 伸展树.cpp -o splay && ./splay
// 对拍验证: g++ -std=c++17 -DSTRESS 伸展树.cpp -o splay_stress && ./splay_stress
#include <cstdio>
using namespace std;

struct Splay {
    struct Node { int val; Node *l, *r, *pa; Node(int v):val(v),l(nullptr),r(nullptr),pa(nullptr){} };
    Node* root = nullptr;

    // 单旋：把 x 转到父亲的位置（带父指针的三叉链）
    void rotate(Node* x) {
        Node *p = x->pa, *g = p->pa;
        if (p->l == x) { p->l = x->r; if (x->r) x->r->pa = p; x->r = p; }
        else           { p->r = x->l; if (x->l) x->l->pa = p; x->l = p; }
        x->pa = g; p->pa = x;
        if (!g) root = x;
        else if (g->l == p) g->l = x;
        else g->r = x;
    }

    // 把 x 旋转到根：一字先转父、之字先转己
    void splay(Node* x) {
        while (x->pa) {
            Node *p = x->pa, *g = p->pa;
            if (!g) rotate(x);                            // 父即根：单旋收尾
            else {
                if ((g->l == p) == (p->l == x)) rotate(p); // 一字型：先转父
                else rotate(x);                            // 之字型：先转己
                rotate(x);
            }
        }
    }

    // 查找：找到则转到根；找不到也把路径末端转上来（摊还分析需要）
    bool find(int x) {
        Node *p = root, *last = nullptr;
        while (p) {
            last = p;
            if (x == p->val) break;      // 找到提前停（否则相等时会一路向右走）
            p = x < p->val ? p->l : p->r;
        }
        if (last) splay(last);
        return last && last->val == x;
    }

    void insert(int x) {
        if (!root) { root = new Node(x); return; }
        Node *p = root, *last = nullptr;
        while (p) {
            last = p;
            if (x == p->val) { splay(p); return; }   // 已存在：不重复插入，转上根即可
            p = x < p->val ? p->l : p->r;
        }
        Node* n = new Node(x);
        n->pa = last;
        if (x < last->val) last->l = n; else last->r = n;
        splay(n);                     // 新节点上根
    }

    // 删除：先 find 把 x 转到根，摘掉根后合并左右子树：
    // 左子树最大者 splay 到左子树根，此时它无右孩子，直接接上右子树
    void erase(int x) {
        if (!find(x)) return;         // 此刻 x 就是 root
        Node *L = root->l, *R = root->r;
        delete root;
        if (!L) { root = R; if (R) R->pa = nullptr; return; }
        L->pa = nullptr;
        root = L;
        Node* m = L;
        while (m->r) m = m->r;
        splay(m);                     // m 上根后右子树必空
        m->r = R;
        if (R) R->pa = m;
        root = m;
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
void collect(Splay::Node* t, vector<int>& v) {
    if (!t) return;
    collect(t->l, v); v.push_back(t->val); collect(t->r, v);
}
bool checkPa(Splay::Node* t, Splay::Node* pa) {   // 父指针一致性
    if (!t) return true;
    if (t->pa != pa) return false;
    return checkPa(t->l, t) && checkPa(t->r, t);
}
int main() {
    mt19937 rng(12345);
    for (int round = 0; round < 20; round++) {
        Splay t; set<int> s;
        for (int i = 0; i < 3000; i++) {
            int op = rng() % 3, x = (int)(rng() % 400);
            if (op == 0) { t.insert(x); s.insert(x); }
            else if (op == 1) { t.erase(x); s.erase(x); }
            else assert(t.find(x) == (s.count(x) > 0));
            assert(checkPa(t.root, nullptr));      // 每步后父指针链一致
        }
        vector<int> v; collect(t.root, v);
        assert(v == vector<int>(s.begin(), s.end()));
    }
    puts("Splay STRESS OK");
    return 0;
}
#else
int main() {
    Splay t;
    for (int x = 1; x <= 10; x++) t.insert(x);
    t.print();                    // 期望: 1 2 3 4 5 6 7 8 9 10（中序仍是 BST）
    t.find(1);                    // 访问 1 后它应成为根
    printf("root=%d\n", t.root->val);   // 期望: 1（最近访问的节点最靠近根）
    t.erase(5);
    t.print();                    // 期望: 1 2 3 4 6 7 8 9 10
    return 0;
}
#endif
