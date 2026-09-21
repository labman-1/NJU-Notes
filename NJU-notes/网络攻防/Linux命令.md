Linux 命令行的基本格式是：

```bash
命令 [选项] [参数]
```

例如：

```bash
ls -l /home
```

其中 `ls` 是命令，`-l` 是选项，`/home` 是参数。Linux 区分大小写，路径中 `/` 是根目录，`~` 是当前用户家目录，`.` 是当前目录，`..` 是上级目录。多用 `Tab` 补全，用 `man 命令` 或 `命令 --help` 查帮助。

## 1. 文件与目录

```bash
pwd                 # 显示当前目录
ls                  # 列出文件
ls -l               # 详细信息
ls -a               # 显示隐藏文件
ls -lh              # 文件大小更易读
cd /etc             # 进入目录
cd ..               # 返回上级
cd ~                # 回到家目录
cd -                # 回到上一个目录

mkdir dir           # 创建目录
mkdir -p a/b/c      # 递归创建目录
rmdir dir           # 删除空目录

touch file.txt      # 创建空文件或更新时间
cp file1 file2      # 复制文件
cp -r dir1 dir2     # 递归复制目录
mv file1 file2      # 移动或重命名
rm file             # 删除文件
rm -r dir           # 递归删除目录
rm -f file          # 强制删除

ln -s /path/target linkname   # 创建软链接
```

危险命令：`rm -rf` 删除后通常无法恢复，尤其不要执行 `rm -rf /`。

## 2. 查看和编辑文本

```bash
cat file.txt        # 输出整个文件
cat -n file.txt     # 带行号
less file.txt       # 分页查看，q 退出，/关键字 搜索
head -n 20 file     # 看前 20 行
tail -n 20 file     # 看后 20 行
tail -f logfile     # 实时跟踪日志

nano file.txt       # 简单编辑器
vim file.txt        # 强大编辑器，:wq 保存退出，:q! 不保存退出
```

## 3. 搜索与文本处理

```bash
grep "error" log.txt              # 搜索文本
grep -i "error" log.txt           # 忽略大小写
grep -r "error" /var/log          # 递归搜索
grep -n "error" log.txt           # 显示行号
grep -v "debug" log.txt           # 反选，排除包含 debug 的行

find . -name "*.log"              # 按文件名查找
find /var/log -type f -mtime -7   # 查找 7 天内修改的文件
find . -type f -size +100M        # 查找大于 100M 的文件

which python3       # 查看命令路径
whereis ls          # 查看命令相关文件
type cd             # 判断是内建命令还是外部命令

wc -l file          # 统计行数
sort file           # 排序
sort -n file        # 按数字排序
uniq -c             # 去重并计数，通常先 sort
cut -d: -f1 /etc/passwd   # 按分隔符取列
```

高级文本工具：

```bash
sed -i 's/old/new/g' file.txt     # 替换文本
awk '{print $1, $3}' file.txt     # 按列处理
```

## 4. 权限与用户

```bash
chmod +x script.sh        # 添加可执行权限
chmod 755 file            # rwxr-xr-x
chmod 644 file            # rw-r--r--
chown user:group file     # 修改所属用户和组
chown -R user:group dir   # 递归修改

sudo command              # 以 root 权限执行
su - username             # 切换用户

useradd -m username       # 创建用户
passwd username           # 设置密码
usermod -aG sudo username # 加入 sudo 组
userdel -r username       # 删除用户及家目录
id                        # 查看当前用户身份
whoami                    # 查看当前用户名
```

权限数字含义：`r=4`，`w=2`，`x=1`。`755 = rwxr-xr-x`，`644 = rw-r--r--`。

## 5. 进程与系统

```bash
ps aux                    # 查看所有进程
ps aux | grep nginx       # 查找 nginx 进程
top                       # 动态查看进程和资源
htop                      # 更友好的 top，可能需要安装

kill PID                  # 终止进程，默认 15
kill -9 PID               # 强制终止
pkill nginx               # 按名称终止
killall nginx             # 终止同名进程

jobs                      # 查看后台任务
bg                        # 后台继续
fg                        # 前台继续
Ctrl + C                  # 终止当前命令
Ctrl + Z                  # 挂起当前命令

nohup ./server > server.log 2>&1 &   # 后台运行并输出日志
```

系统服务：

```bash
systemctl status nginx
systemctl start nginx
systemctl stop nginx
systemctl restart nginx
systemctl enable nginx    # 开机自启
systemctl disable nginx
journalctl -u nginx -f    # 查看服务日志
```

## 6. 磁盘与系统信息

```bash
df -h                     # 查看磁盘使用
du -sh *                  # 查看当前目录各文件/目录大小
du -sh /var/log           # 查看指定目录大小
free -h                   # 查看内存
uname -a                  # 查看内核和系统信息
uptime                    # 查看运行时间和负载
date                      # 查看日期时间
cal                       # 查看日历
```

## 7. 压缩与归档

```bash
tar -czvf archive.tar.gz dir/     # 打包并 gzip 压缩
tar -xzvf archive.tar.gz          # 解压
tar -tzvf archive.tar.gz          # 查看内容

gzip file                         # 压缩为 file.gz
gunzip file.gz                    # 解压

zip -r archive.zip dir/           # 创建 zip
unzip archive.zip                 # 解压 zip
```

## 8. 网络

```bash
ip addr                  # 查看 IP 地址
ip route                 # 查看路由
ping -c 4 example.com    # 测试连通性
ss -tulnp                # 查看监听端口，需权限显示进程
curl -I https://example.com      # 查看 HTTP 响应头
curl -O https://example.com/file # 下载文件
wget https://example.com/file    # 下载文件

ssh user@host            # 远程登录
scp file user@host:/path # 远程复制
scp -r dir user@host:/path
rsync -avz source/ user@host:/dest/   # 同步文件
```

## 9. 软件包管理

不同发行版不同：

Debian/Ubuntu：

```bash
sudo apt update
sudo apt upgrade
sudo apt install nginx
sudo apt remove nginx
apt search nginx
```

RHEL/CentOS/Fedora：

```bash
sudo dnf install nginx
sudo dnf update
sudo dnf remove nginx
```

Arch Linux：

```bash
sudo pacman -Syu
sudo pacman -S nginx
sudo pacman -Rns nginx
```

## 10. 重定向、管道和通配符

```bash
command > file        # 标准输出覆盖到文件
command >> file       # 追加到文件
command 2> error.log  # 错误输出到文件
command &> all.log    # 标准输出和错误都写入
command < file        # 从文件读取输入

command1 | command2   # 管道：前一个命令输出作为后一个输入
ps aux | grep nginx
cat access.log | grep "500" | wc -l

*       # 匹配任意字符
?       # 匹配一个字符
[abc]   # 匹配 a、b 或 c
```

## 11. 帮助与历史

```bash
man ls              # 查看手册
ls --help           # 查看简要帮助
history             # 查看历史命令
history | grep ssh
Ctrl + R            # 反向搜索历史命令
!!                  # 执行上一条命令
sudo !!             # 用 sudo 执行上一条命令
```

## 12. 常用组合示例

```bash
# 查看当前目录下各目录大小并按大小排序
du -sh * | sort -h

# 实时查看 Nginx 日志中的 500 错误
tail -f /var/log/nginx/access.log | grep "500"

# 查找大于 1G 的文件
find / -type f -size +1G 2>/dev/null

# 查看监听端口
ss -tulnp

# 查看占用 CPU 最高的进程
ps aux --sort=-%cpu | head
```

## 学习建议

先熟练掌握：`ls`、`cd`、`pwd`、`cp`、`mv`、`rm`、`cat`、`less`、`grep`、`find`、`chmod`、`ps`、`kill`、`df`、`du`、`tar`、`ssh`、`systemctl`。遇到不会的命令，优先查：

```bash
man 命令
命令 --help
```

最重要的是：执行 `rm`、`chown`、`chmod`、`dd`、`mkfs` 等命令前，先确认当前目录和参数，避免误操作。