
# 命令太多，怎么记

## 1. 先建立三个底层模型

记住这三个模型，很多命令你能“猜”出来：

**模型一：一切皆文件。** 磁盘、设备、管道、socket、`/proc` 都是文件，所以 `cat`、`echo`、重定向能作用于它们。

**模型二：文本流 + 小工具组合。** 每个命令只做一件事，通过管道组合出复杂功能。你不是在用一个命令，而是在搭一条流水线。

**模型三：命令 = 动词 + 名词 + 选项。** 命令名多是英文缩写，选项多是约定俗成的单字母。

## 2. 命令名几乎都是英文缩写

理解了词源，根本不用死记：

| 命令 | 来源 | 含义 |
|---|---|---|
| `ls` | list | 列出 |
| `cd` | change directory | 切换目录 |
| `pwd` | print working directory | 显示当前目录 |
| `cp` | copy | 复制 |
| `mv` | move | 移动/重命名 |
| `rm` | remove | 删除 |
| `mkdir` | make directory | 建目录 |
| `rmdir` | remove directory | 删空目录 |
| `cat` | concatenate | 连接并输出 |
| `grep` | global regular expression print | 全局正则搜索打印 |
| `sed` | stream editor | 流编辑器 |
| `awk` | 三位作者姓氏首字母 | 文本处理语言 |
| `chmod` | change mode | 改权限 |
| `chown` | change owner | 改属主 |
| `ps` | process status | 进程状态 |
| `df` | disk free | 磁盘剩余 |
| `du` | disk usage | 磁盘占用 |
| `tar` | tape archive | 打包 |
| `ssh` | secure shell | 安全远程登录 |
| `scp` | secure copy | 安全复制 |
| `man` | manual | 手册 |
| `ln` | link | 链接 |

## 3. 选项也有规律

大部分命令的常用选项高度一致，记住这套“通用选项语言”：

| 选项 | 通用含义 |
|---|---|
| `-r` / `-R` | recursive 递归 |
| `-f` | force 强制，或 file |
| `-v` | verbose 详细输出，或 version |
| `-i` | interactive 交互确认，或 ignore-case |
| `-n` | number 显示行号，或 dry-run |
| `-a` | all 全部（含隐藏） |
| `-l` | long 长格式，或 list |
| `-h` | human-readable 易读，或 help |
| `-q` | quiet 静默 |
| `-e` | execute 执行，或 regex |
| `-o` | output 输出文件 |
| `-p` | preserve 保留，或 port |
| `-t` | type 类型，或 tag |
| `-u` | update 更新，或 user |

组合选项也遵循约定：`ls -lah` = `-l -a -h`。

## 4. 按“任务”而不是“命令”来记

大脑记场景比记符号容易得多。建议按这张表来组织你的记忆：

| 我想做什么 | 命令 |
|---|---|
| 我在哪 / 去哪 | `pwd` `cd` |
| 有什么文件 | `ls` `find` |
| 看内容 | `cat` `less` `head` `tail` |
| 搜内容 | `grep` `find` |
| 改内容 | `sed` `awk` `vim` |
| 复制移动删除 | `cp` `mv` `rm` |
| 权限 | `chmod` `chown` `sudo` |
| 进程 | `ps` `top` `kill` `systemctl` |
| 磁盘 | `df` `du` |
| 网络 | `ip` `ss` `ping` `curl` `ssh` |
| 压缩 | `tar` `gzip` `zip` |
| 文本处理 | `sort` `uniq` `cut` `wc` `tr` |

## 5. 只背“核心 30 个”，其余靠查

真正高频的其实就二三十个。先把这些练到肌肉记忆：

```
ls cd pwd cp mv rm mkdir cat less head tail
grep find chmod chown sudo ps kill top
df du tar ssh systemctl echo man
```

其他命令知道“它存在、大概干什么”就够了，用的时候再查。**知道有这个东西，比背下它的参数重要得多。**

## 6. 通过动手而不是背诵来记

- 每天真实用一遍，比看十遍文档有效。
- 用 Anki 之类的间隔重复，只卡片化最核心的命令，不要贪多。
- 把常用命令写成 alias 或函数，用着用着就记住了：

```bash
alias ll='ls -lah'
alias gs='git status'
alias ..='cd ..'
```

- 读别人的脚本，遇到不懂的命令立刻查，带着上下文记得最牢。

## 7. 别死记复杂命令，学会“组合”

不要背 `awk '{print $1}' access.log | sort | uniq -c | sort -rn | head`，而是理解每一步：

```
取第一列 -> 排序 -> 去重计数 -> 按数量倒序 -> 取前10
```

理解流水线，就能临时搭出来，不需要背。

---

# 需要时如何快速查找

## 1. 忘了参数：`man` 和 `--help`

```bash
man ls              # 完整手册，q 退出，/关键字 搜索
man 5 passwd        # 指定章节，5 是文件格式
man -k keyword      # 按关键字搜手册，等价 apropos
whatis ls           # 一句话说明
ls --help           # 快速帮助，通常比 man 简洁
help cd             # bash 内建命令用 help，man 查不到
```

man 手册章节：

| 章节 | 内容 |
|---|---|
| 1 | 用户命令 |
| 2 | 系统调用 |
| 3 | 库函数 |
| 5 | 文件格式 |
| 7 | 杂项/约定 |
| 8 | 系统管理命令 |

man 里导航：`/关键字` 搜索，`n` 下一个，`Shift+G` 到底，`q` 退出。

## 2. 想要看得懂的简明示例：`tldr`

`man` 太啰嗦，`tldr` 只给最常用的几个例子：

```bash
sudo apt install tldr
tldr tar
tldr grep
```

输出是社区维护的实例，非常适合“我就想快速知道怎么用”。

## 3. 不知道用什么命令：`apropos` 或直接描述任务

```bash
apropos "list files"
apropos "disk usage"
```

或者直接用自然语言问搜索引擎/AI：“linux 怎么找出占用端口 8080 的进程”，通常比翻 man 快。

## 4. 忘了以前敲过什么：history 和 Ctrl+R

```bash
history                 # 看历史
history | grep ssh      # 搜历史
Ctrl + R                # 反向增量搜索，最常用
!!                      # 重复上一条
sudo !!                 # 上一条加 sudo
!123                    # 执行历史编号 123
!grep                   # 执行最近一条以 grep 开头的命令
```

强烈推荐装 **fzf**，`Ctrl+R` 变成模糊搜索，效率翻倍：

```bash
sudo apt install fzf
```

## 5. 命令到底被解析成什么

```bash
type ls             # 是别名、内建还是外部命令
which python3       # 外部命令路径
whereis ls          # 二进制、源码、man 位置
command -V ls
alias               # 看所有别名
set -x              # 打开调试，显示每条命令展开后的样子
```

注意 `ls` 在 bash 里可能是别名，`type ls` 一看便知，这能解释很多“为什么行为和文档不一样”。

## 6. 想理解复杂管道：explainshell

把命令贴到 **explainshell.com**，它会逐段拆解每个参数的含义，非常适合学习别人的一行流。

## 7. 记住“查找路径”这个决策树

```
忘了参数        -> cmd --help 或 man cmd
想要示例        -> tldr cmd
不知道用啥命令  -> apropos 关键字 / 搜索引擎 / AI
忘了敲过啥      -> history | grep / Ctrl+R
想搞懂一行流    -> explainshell.com
想确认命令来源  -> type / which / whereis
bash 内建       -> help cmd
```

## 8. 建立自己的速查表

最有效的办法是维护一个自己的笔记文件，比如 `~/cheatsheet.md`，只记录**你实际用过、踩过坑**的命令。别人的速查表你记不住，自己踩坑总结的才记得牢。

配一个快速打开的函数：

```bash
cheat() { less ~/cheatsheet.md; }
```

再配合 `Ctrl+R` 搜历史，基本覆盖 90% 的“我忘了怎么写”场景。

---

# 四、一句话总结
- **记忆的本质**：不背命令，背模型（一切皆文件、文本流、组合）、背词源、背选项规律、背任务场景；只把核心 30 个练成肌肉记忆。
- **查找的本质**：`--help` / `man` / `tldr` 解决参数，`apropos` / AI 解决“用什么命令”，`history` / `Ctrl+R` 解决“我以前怎么写的”，`type` / `explainshell` 解决“这行到底是什么”。