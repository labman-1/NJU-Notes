// 线索二叉树(Threaded Binary Tree)：
// n 个节点的二叉链表有 n+1 个空指针 —— 一半以上的指针域被浪费。
// 线索树让空左指针存"中序前驱"、空右指针存"中序后继"（tag=1 标记这是线索不是孩子），
// 于是不用栈、不用递归就能中序遍历，找前驱/后继接近 O(1)。
// Morris 遍历(LeetCode O(1) 空间遍历)就是它的临时版：借指针、遍历完再还。
// 编译: g++ -std=c++17 线索二叉树.cpp -o thread && ./thread
#include <cstdio>
using namespace std;

struct ThreadTree {
    struct Node {
        char val;
        Node *l, *r;
        int ltag, rtag;              // 0=孩子指针  1=线索(前驱/后继)
        Node(char v):val(v),l(nullptr),r(nullptr),ltag(0),rtag(0){}
    };
    Node* root = nullptr;
    Node* pre = nullptr;             // 线索化时"中序里上一个访问的节点"

    // 中序线索化：本质就是中序遍历，访问节点时顺手连前后驱线索
    void threading(Node* p) {
        if (!p) return;
        threading(p->l);                            // 1. 左
        if (!p->l) { p->l = pre; p->ltag = 1; }     // 2. 根：无左孩子 -> 左指针指向前驱
        if (pre && !pre->r) { pre->r = p; pre->rtag = 1; } // 前驱无右孩子 -> 其右指针指向我
        pre = p;
        threading(p->r);                            // 3. 右
    }
    void build() { pre = nullptr; threading(root); }

    // 找中序后继：有线索直接拿；无线索(有右孩子)则右子树的最左节点
    Node* next(Node* p) {
        if (p->rtag == 1) return p->r;
        Node* q = p->r;
        while (q && q->ltag == 0) q = q->l;   // 最后一个节点 rtag=0 且 r=null -> 返回 null
        return q;
    }

    // 线索中序遍历：先走到最左，然后反复取后继 —— 无栈无递归
    void inorder() {
        Node* p = root;
        while (p && p->ltag == 0) p = p->l;   // 中序第一个节点 = 最左
        for (; p; p = next(p)) printf("%c ", p->val);
        printf("\n");
    }
};

int main() {
    //         A
    //        / \
    //       B   C
    //      / \    \
    //     D   E    F
    // 中序应为: D B E A C F
    ThreadTree t;
    t.root = new ThreadTree::Node('A');
    t.root->l = new ThreadTree::Node('B');
    t.root->r = new ThreadTree::Node('C');
    t.root->l->l = new ThreadTree::Node('D');
    t.root->l->r = new ThreadTree::Node('E');
    t.root->r->r = new ThreadTree::Node('F');
    t.build();                    // 线索化
    t.inorder();                  // 期望: D B E A C F

    // 验证线索真的连上了：D 是中序第一个，前驱线索指向 null；后继线索指向 B
    auto* D = t.root->l->l;
    printf("D: ltag=%d(前驱=%s), rtag=%d, 后继=%c\n",
           D->ltag, D->l ? "非空" : "null",
           D->rtag, D->r ? D->r->val : '?');   // 期望: ltag=1(前驱=null), rtag=1, 后继=B
    // E 的后继应是 A（跨子树的线索，这正是线索树的价值）
    auto* E = t.root->l->r;
    printf("E 的后继 = %c\n", t.next(E)->val);   // 期望: A
    return 0;
}
