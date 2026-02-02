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