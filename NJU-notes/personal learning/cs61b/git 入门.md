## add, commit and push
To push your code, we’ll be using the following three commands: `add`, `push`, and `commit`. Don’t worry about the details yet, and simply follow the steps below:

1. Open a terminal window and navigate to the folder containing your `sp21-s***` repository, **NOT** your `snaps-sp21-s***` repo. If you type the “ls” command, you should see your lab1 folder sitting there.
2. Enter the following command to confirm that you’re in the right directory.
    
    ```
     $ git status
    ```
    
    If everything is working correctly you should see something like:
    
    ```
     On branch master
     Changes not staged for commit:
       (use "git add <file>..." to update what will be committed)
       (use "git restore <file>..." to discard changes in working directory)
         modified:   lab1/Collatz.java
    ```
    
    What Git is telling you is that you’ve changed something about your lab1/Collatz.java folder that GitHub has not recorded. **Make sure that it says lab1/Collatz.java, not just Collatz.java**. If it says just Collatz.java, you should use `cd..` to go up one directory.
    
3. Enter the command
    
    ```
     $ git add lab1/*
    ```
    
4. Enter the following command to confirm that add worked properly.
    
    ```
     $ git status
    ```
    
    If everything is working correctly, you should see something like:
    
    ```
     On branch master
     Changes to be committed:
       (use "git restore --staged <file>..." to unstage)
             modified:   lab1/Collatz.java
    ```
    
    Now Git is telling you that it is acknowledging that you want to record the changes you made to Collatz.java.
    
5. Enter the command
    
    ```
     $ git commit -m "done with Collatz"
    ```
    
    When you do this, Git will make a recording of the changes you made to Collatz.java. It will also record the message “done with Collatz” along with the recording. These messages can be helpful if you’re looking to find a specific change at some point in the past. We’ll discuss further in a later lab. It will also print some output the terminal, and you’ll see something like below, though the number of insertions and deletions may be different.
    
    ```
     [master e2c138b] done with Collatz
     1 file changed, 15 insertions(+), 1 deletion(-)
    ```
    
6. As before, enter the git status command.
    
    ```
     $ git status
    ```
    
    If commit worked correctly, you should see something like:
    
    ```
     On branch master
     nothing to commit, working tree clean
    ```
    
    The fact that the “working tree” is “clean” means that all of your work is backed up.
    
7. Refresh the URL for your repo on GitHub.com. You’ll see that your changes STILL aren’t showing up. This is because we have one last step.
8. Enter the command:
    
    ```
     $ git push origin master
    ```
    
9. Refresh the URL for your repo on GitHub.com. You should see that your changes to Collatz.java are now visible, along with the message you entered.

Note that normally you won’t enter `git status` after every single command. We were only doing this to make sure that you entered the commands correctly. The three commands that we entered that were actually necessary to get your code on GitHub are summarized below:

```
git add lab1/*
git commit -m "done with Collatz"
git push origin master
```
### Q&A
**Q: Why wouldn’t people just use Dropbox (or similar)?** Dropbox is backing up everything at sporadic intervals. When writing programs, we often want to make backups at specific times and only of specific files. For example, when you finally get a program working, you might want to back it up at that point so you can come back to it if you break it later. Also the ability to add a message makes it easy to organize the backups so you can find the ones you want.

**What does add do?** Add marks a file (or set of files) as something you want to backup.

**What does commit do?** Commit creates a backup with the given message.

**If commit makes a backup but not to GitHub, where did it back up my files?** On your own computer!

**What good is a backup on your own computer?** If you want to go back to an old version, you can do that using git using other commands. By storing the backup locally, restoring old backups is very fast and doesn’t require an internet connection.

**What if my computer dies, isn’t the backup made by commit lost?** Yes. That’s why there’s a push command.

**Why not do add, commit, and push in one command?** Sometimes you only want to add a small number of files, so you might call add on only those files before finally doing a commit. And sometimes you want to make commits but don’t want to push, for example because you don’t have internet access or because you’re working on code that is too sensitive to be placed on any internet site.

**How do I see the history of old backups and how do I restore them?** If you want to see old commits, you can use `git log`, and you can use `git checkout` to restore old copies of your code. We’ll cover these later. Alternately you can also use the web interface at GitHub.com to explore and even download old copies.

## “控制时间线”
### 一、 如何获取 Commit ID（查看历史的“经纬度”）

在回退之前，你得知道你要去哪。每个 Commit 都有一个唯一的“身份证号”（SHA-1 校验和）。

*   **查看详细日志**：
    ```bash
    git log
    ```
    你会看到一长串字符（如 `commit a7d3b2f...`），这就是 **Commit ID**。
*   **查看精简日志（专家推荐）**：
    ```bash
    git log --oneline --graph --all
    ```
    这会显示前 7 位的简短 ID（通常前 7 位就足够区分了）和清晰的**分支结构图**。

---

### 二、 如何开辟分支（创造“多重宇宙”）

分支（Branch）是 Git 的灵魂。比如你想写一个新的功能，但不想弄乱现在的代码：

1.  **创建新分支**：
    ```bash
    git branch feature-x  # 创建一个叫 feature-x 的分支
    ```
2.  **切换到新分支**：
    ```bash
    git checkout feature-x  # 切换过去
    # 或者用现代命令：git switch feature-x
    ```
    *提示：你可以用一条命令搞定创建并切换：`git checkout -b feature-x`*
3.  **在新分支上操作**：
    现在你可以放心地 `add` 和 `commit`。这些记录只会存在于 `feature-x` 宇宙，`master` 宇宙的代码纹丝不动。
4.  **合并回主分支**：
    当你觉得新功能写好了，先切换回 master，再合并：
    ```bash
    git checkout master
    git merge feature-x
    ```

---

### 三、 如何回退旧版本代码（操作“时空穿梭”）

根据你的后悔程度，有三种方式：

#### 1. 只是想“看一眼”某个文件（瞬间移动）
如果你想把 `LinkedListDeque.java` 恢复到昨天的某个版本，但**不想**删除今天的其他工作：
```bash
git checkout <commit_id> LinkedListDeque.java
```
这会把特定文件变回去，你再 `add` 和 `commit` 一次即可。

#### 2. 彻底回退到过去（读档重来）
如果你今天写得一塌糊涂，想彻底让整个文件夹回到 ID 为 `a1b2c3d` 的状态：
```bash
git reset --hard a1b2c3d
```
**警告**：这会删除你在这个 ID 之后所有的未提交工作。它是**破坏性**的。

#### 3. 安全地撤销某次提交（反向修正）
如果你已经把代码 push 到了 GitHub，这时候不能用 `reset`（因为会破坏远程的历史），要用 `revert`：
```bash
git revert <commit_id>
```
这会产生一个新的提交，内容是把那个 ID 做的改动全部“反向操作”回去。

---

### 四、 专家视角的实战场景：你的 Project 2 预演

想象你在做 Gitlet 的时候：
1.  你已经写好了 `add` 功能。
2.  你想尝试一种天才的 `commit` 算法，但怕改坏。
3.  **操作**：
    *   `git checkout -b try-new-algorithm`
    *   随便改，随便测。
    *   **成了**：`git checkout master` -> `git merge try-new-algorithm`。
    *   **败了**：`git checkout master`，然后直接把那个失败的分支删了，你依然拥有那个完美的初始版本。

### 总结“新工具包”：

*   **看 ID**：`git log --oneline`
*   **建分支**：`git checkout -b <name>`
*   **切回主线**：`git checkout master`
*   **暴力回退**：`git reset --hard <ID>`
