# AVL 树（严格平衡的 BST）

## 核心定义
- 平衡因子 `bf = h(左) - h(右)`，要求每个节点 `|bf| <= 1`
- 高度界：最坏情况结点数满足斐波那契递推 `N(h) = N(h-1) + N(h-2) + 1`
  → `h < 1.44 * log2(n+2)`，仍是 O(log n) 且常数最小（树最矮，查询最快）

## 四种失衡与旋转（记忆：失衡方向=插入路径最后两步，旋转=反方向掰回）
```
LL(左左) → 右旋一次          RR(右右) → 左旋一次
LR(左右) → 先对左孩子左旋，再对根右旋
RL(右左) → 先对右孩子右旋，再对根左旋
```
双旋的本质：折线先掰成直线，再按 LL/RR 处理。

## 必背骨架
```cpp
int H(Node* t) { return t ? t->h : 0; }              // 空树记 0
int bf(Node* t) { return H(t->l) - H(t->r); }
void pull(Node* t) { t->h = max(H(t->l), H(t->r)) + 1; }

Node* rotR(Node* t) {          // 右旋：左孩子上提
    Node* p = t->l;
    t->l = p->r; p->r = t;
    pull(t); pull(p);          // 顺序：先儿子后新根
    return p;
}
// 插入后回溯路上：
if (bf(t) > 1 && bf(t->l) >= 0) return rotR(t);      // LL
if (bf(t) > 1) { t->l = rotL(t->l); return rotR(t); } // LR
if (bf(t) < -1 && bf(t->r) <= 0) return rotL(t);      // RR
if (bf(t) < -1) { t->r = rotR(t->r); return rotL(t); } // RL
```

## 插入 vs 删除（考试高频对比）
| | 插入 | 删除 |
|---|---|---|
| 旋转次数 | **至多 1 次**（单旋或双旋）| 最坏 **O(log n) 次**（失衡向上传播）|
| 判断失衡类型 | 可看"新值在左还是右" | 必须看**较高一侧孩子**的 bf（`bf(child)>=0` 走单旋）|
| 恢复后是否继续 | 该处修复即全树平衡 | 回溯时每层都可能再失衡 |

完整模板: `D:\cxy\UniversityAffairs\CourseMaterials\数据结构\模板代码\AVL.cpp`（含删除，STRESS 每步验证 |bf|<=1）
