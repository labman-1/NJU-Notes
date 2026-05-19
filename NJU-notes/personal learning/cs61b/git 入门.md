# Git 命令详解

Git 是目前最流行的分布式版本控制系统，掌握常用命令是高效协作的基础。下面从最核心的概念出发，系统性地讲解各个常用命令及其典型用法。

---

## 一、Git 的三大区域

在讲解命令前，先理解 Git 管理的三个区域：

| 区域 | 说明 |
|------|------|
| **工作目录（Working Directory）** | 存放实际文件的目录，你直接编辑修改的地方。 |
| **暂存区（Staging Area / Index）** | 一个临时存放待提交修改的区域。`git add` 将工作区改动放入暂存区。 |
| **本地仓库（Repository）** | Git 保存所有版本记录的地方。`git commit` 将暂存区内容永久存入仓库。 |
| **远程仓库（Remote Repository）** | 托管在网络上的仓库副本，用于多人协作。 |

---

## 二、配置命令

首次使用 Git 需要配置用户信息（每次提交都会记录）。

```bash
# 设置全局用户名和邮箱（影响所有仓库）
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"

# 设置当前仓库的专属信息（不带 --global）
git config user.name "Project Name"

# 查看配置
git config --list
git config user.name

# 设置别名（可选）
git config --global alias.co checkout
git config --global alias.st status
```

---

## 三、创建与克隆仓库

```bash
# 1. 在本地初始化一个仓库
git init

# 2. 克隆远程仓库到本地
git clone <远程仓库URL> [目录名]

# 例子
git clone https://github.com/user/repo.git myrepo
```

- `git init` 会在当前目录生成 `.git` 隐藏文件夹（即本地仓库）。
- `git clone` 自动设置远程仓库别名 `origin`，并检出默认分支。

---

## 四、核心工作流程：暂存与提交

### `git status` —— 查看当前状态
```bash
git status               # 显示工作目录和暂存区状态
git status -s            # 简洁输出（short）
```
输出中红色表示未暂存的修改，绿色表示已暂存。

### `git add` —— 将修改添加到暂存区
```bash
git add <file>           # 添加单个文件
git add .                # 添加当前目录所有修改（不包括删除？其实包括）
git add -A               # 添加所有变化（包括删除、新增、修改）
git add -p               # 交互式分块添加（可逐块选择是否暂存）
```

### `git commit` —— 将暂存区内容提交到仓库
```bash
git commit -m "提交信息"                         # 直接附带提交信息
git commit -m "feat: add login page" -m "详细描述"  # 多行信息
git commit -a -m "跳过暂存直接提交"               # 仅对已跟踪的文件相当于自动 add + commit
```

> **注意**：`-a` 不会自动添加未被跟踪的新文件（untracked files）。

### `git log` —— 查看提交历史
```bash
git log                    # 完整历史
git log --oneline          # 一行显示
git log --graph            # 图形化显示分支合并
git log --author="name"    # 按作者过滤
git log -p                 # 显示每次提交的 diff
git log --since="2024-01-01"  # 按时间过滤
```

### `git diff` —— 查看差异
```bash
git diff                   # 工作区 vs 暂存区（未暂存的修改）
git diff --staged          # 暂存区 vs 最近一次提交（即将提交的内容）
git diff HEAD              # 工作区 vs 最近一次提交
git diff <commit1> <commit2>   # 两个提交之间的差异
```

---

## 五、分支操作

分支是 Git 的精髓，允许并行开发。

### 创建与切换分支
```bash
git branch                     # 列出本地分支（当前分支带 *）
git branch <branch-name>       # 创建分支（基于当前 HEAD）
git branch -r                  # 列出远程分支
git branch -a                  # 列出所有分支（本地+远程）

git checkout <branch-name>     # 切换到已有分支（旧式）
git switch <branch-name>       # 切换到已有分支（推荐，Git 2.23+）
git switch -c <new-branch>     # 创建并切换到新分支（相当于 checkout -b）
```

### 合并分支
```bash
# 将 feature 分支合并到当前分支（通常先切到目标分支）
git checkout main
git merge feature

# 合并时创建一次新的合并提交（--no-ff）
git merge --no-ff feature
```

### 变基（Rebase）
变基可以使提交历史更线性，但需谨慎使用（尤其对公共分支）。
```bash
git checkout feature
git rebase main                # 将 feature 分支的基变为 main 的最新提交
```

### 删除分支
```bash
git branch -d <branch>         # 删除已合并的分支
git branch -D <branch>         # 强制删除未合并的分支（危险）
```

### 冲突解决
当合并冲突发生时，Git 会在冲突文件中标记：
```
<<<<<<< HEAD
当前分支的内容
=======
合并进来的分支内容
>>>>>>> feature
```
手动编辑后 `git add` 该文件，然后 `git commit` 完成合并。

---

## 六、远程仓库操作

### 查看与添加远程仓库
```bash
git remote -v               # 显示远程仓库别名和 URL
git remote add origin <URL> # 添加名为 origin 的远程仓库
git remote remove origin    # 移除远程仓库
git remote rename old new   # 重命名远程仓库别名
```

### 推送与拉取
```bash
git push origin main        # 将本地 main 分支推送到远程 origin
git push -u origin main     # -u 建立跟踪关系（以后可简写 git push）
git push --all origin       # 推送所有本地分支
git push origin --delete feature  # 删除远程分支

git pull origin main        # 等价于 git fetch + git merge
git fetch origin            # 只下载远程数据，不自动合并
git fetch --prune           # 清理本地已删除的远程分支记录

# 拉取远程分支并自动合并（推荐先 fetch 再手动合并）
git pull --rebase           # 用 rebase 方式合并（保持线性历史）
```

### 跟踪远程分支
```bash
git checkout -b local-branch origin/remote-branch   # 创建并跟踪远程分支
git branch -u origin/remote-branch                  # 为当前分支设置跟踪
```

---

## 七、撤销与回退操作

| 场景 | 命令 |
|------|------|
| **撤销工作区的修改**（未暂存） | `git checkout -- <file>` 或 `git restore <file>`（推荐） |
| **从暂存区撤销**（unstage） | `git reset HEAD <file>` 或 `git restore --staged <file>` |
| **撤销最近一次提交**（保留修改到工作区） | `git reset --soft HEAD~1` |
| **撤销最近一次提交**（丢弃修改） | `git reset --hard HEAD~1`（**危险！** 会丢失提交内容） |
| **撤销某次历史提交**（用新提交反向操作） | `git revert <commit-hash>`（安全，推荐用于公共分支） |
| **重置到某个提交**（丢弃该提交之后的所有历史） | `git reset --hard <commit-hash>`（仅本地使用） |

> **`reset` vs `revert`**：  
> `reset` 是移动分支指针，常用于本地；`revert` 是创建一次新的反转提交，不会改变历史，适合公共分支。

### 恢复已删除的分支或丢失的提交
```bash
git reflog                # 显示所有 HEAD 移动记录（可找回丢失的提交）
git checkout <commit-hash>  # 临时切换到该提交
git branch recover-branch <commit-hash>  # 基于该提交创建分支
```

---

## 八、标签（Tag）

标签常用于标记版本发布（如 v1.0.0）。

```bash
# 创建标签
git tag v1.0.0                    # 轻量标签（只是指针）
git tag -a v1.0.0 -m "发布1.0"   # 附注标签（包含作者、日期、信息）

# 查看标签
git tag                           # 列出所有标签
git tag -l "v1.*"                 # 搜索标签
git show v1.0.0                   # 查看标签详情

# 推送标签到远程
git push origin v1.0.0            # 推送单个标签
git push origin --tags            # 推送所有本地标签

# 删除标签
git tag -d v1.0.0                 # 删除本地标签
git push origin --delete v1.0.0   # 删除远程标签
```

---

## 九、储藏（Stash）

当需要临时切换分支但不想提交当前工作区修改时使用。

```bash
git stash                    # 保存当前工作区修改（包括暂存区？默认只保存工作区修改，加 --include-untracked 保存未跟踪文件）
git stash save "描述信息"     # 带描述的储藏
git stash list               # 查看储藏列表
git stash apply stash@{0}    # 应用某个储藏（但不删除）
git stash pop                # 应用最新的储藏并将其删除
git stash drop stash@{0}     # 删除指定储藏
git stash clear              # 清除所有储藏
```

**常用小技巧**：  
```bash
git stash -u                 # 储藏时同时包括未跟踪的文件（untracked files）
git stash --patch            # 交互式选择部分修改储藏
```

---

## 十、其他常用命令

### 1. `git blame` —— 逐行查看文件修改者和提交
```bash
git blame file.txt
```

### 2. `git bisect` —— 二分法定位引入 bug 的提交
```bash
git bisect start
git bisect bad               # 标记当前提交为坏
git bisect good <commit>     # 标记一个已知的好提交
# Git 会自动 checkout 中间提交，测试后标记 git bisect good 或 bad
git bisect reset             # 结束查找回到原分支
```

### 3. `git grep` —— 在仓库中搜索文本
```bash
git grep "search_term"
git grep -n "pattern"        # 显示行号
git grep --count "pattern"   # 统计每个文件出现次数
```

### 4. `git clean` —— 移除未跟踪的文件
```bash
git clean -n                 # 预览将要删除的文件
git clean -f                 # 强制删除未跟踪的文件
git clean -fd                # 删除未跟踪的文件和目录
```

### 5. `git archive` —— 打包仓库
```bash
git archive --format=zip HEAD > project.zip
```

---

## 十一、常见工作流程示例

### 日常开发流程
```bash
git checkout -b feature/login    # 创建新功能分支
# 编辑文件...
git add .                        # 暂存所有修改
git commit -m "add login form"   # 提交
git push -u origin feature/login # 推送到远程
# 然后发起 Pull Request (PR) / Merge Request (MR)

# 之后合并到 main
git checkout main
git pull origin main             # 获取最新
git merge feature/login          # 合并
git push origin main             # 推送
```

### 修复紧急 bug 并提交
```bash
git stash                        # 保存当前工作
git checkout -b hotfix/crash main
# 修复代码...
git commit -a -m "fix crash on startup"
git push origin hotfix/crash
git checkout feature/login
git stash pop                    # 恢复之前的工作
```

---

## 十二、总结与最佳实践

1. **多用分支**：主分支只用于发布，开发在特性分支进行。
2. **提交信息规范**：推荐使用 Conventional Commits（如 `feat:`, `fix:`, `docs:` 等）。
3. **公共分支避免强制推送**：不要对已推送的公共分支使用 `git push --force`，确需覆盖时使用 `--force-with-lease`。
4. **养成 `git status` 的习惯**：操作前先看状态，避免误操作。
5. **学习 `git reflog`**：它能拯救你的误操作（如 `--hard` 后恢复）。
6. **使用 Git 图形化工具（如 Git GUI, SourceTree, VS Code 集成）** 辅助理解，但命令行更加灵活和通用。

掌握以上命令足以应对绝大多数日常开发场景。如果遇到更复杂的需求（如子模块、交互式变基、工作树等），可以进一步深入官方文档或通过 `git help <command>` 查阅。