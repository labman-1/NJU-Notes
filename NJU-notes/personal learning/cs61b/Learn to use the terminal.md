The terminal is an application that allows you to run all sorts of programs, as well as manipulate files in your own computer. It is a powerful but also dangerous tool, so please be careful with using some of these commands. On Unix-like operating systems, the Terminal application will provide you with everything that you need. On macOS, for example, you can use Spotlight to search for the Terminal application.

Here are some important ones that you may find useful in this course:

- `cd`: change your working directory
    
    ```
      cd hw
    ```
    
    This command will change your directory to `hw`.
    
- `pwd`: present working directory
    
    ```
      pwd
    ```
    
    This command will tell you the full absolute path for the current directory you are in if you are not sure where you are.
    
- `.`: means your current directory
    
    ```
      cd .
    ```
    
    This command will change your directory to the current directory (aka. do nothing).
    
- `..`: means one parent directory above your current directory
    
    ```
      cd ..
    ```
    
    This command will change your directory to its parent. If you are in /workspace/day1/, the command will place you in /workspace/.
    
- `ls`: list files/folders in directory
    
    ```
      ls
    ```
    
    This command will list all the files and folders in your current directory.
    
    ```
      ls -l
    ```
    
    This command will list all the files and folders in your current directory with timestamps and file permissions. This can help you double-check if your file updated correctly or change the read-write- execute permissions for your files.
    
- `mkdir`: make a directory
    
    ```
      mkdir dirname
    ```
    
    This command will make a directory within the current directory called `dirname`.
    
- `rm`: remove a file
    
    ```
      rm file1
    ```
    
    This command will remove file1 from the current directory. It will not work if `file1` does not exist.
    
    ```
      rm -r dir1
    ```
    
    This command will remove the `dir1` directory recursively. In other words, it will delete all the files and directories in `dir1` in addition to `dir1` itself. Be careful with this command!
    
- `cp`: copy a file
    
    ```
      cp lab1/original lab2/duplicate
    ```
    
    This command will copy the `original` file in the `lab1` directory and and create a `duplicate` file in the `lab2` directory.
    
- `mv`: move or rename a file
    
    ```
      mv lab1/original lab2/original
    ```
    
    This command moves `original` from `lab1` to `lab2`. Unlike `cp`, mv does not leave original in the `lab1` directory.
    
    ```
      mv lab1/original lab1/newname
    ```
    
    This command does not move the file but rather renames it from `original` to `newname`.
    

There are some other useful tricks when navigating on a command line:

- Your shell can complete file names and directory names for you with _tab completion_. When you have an incomplete name (for something that already exists), try pressing the `tab` key for autocomplete or a list of possible names.
    
- If you want to retype the same instruction used recently, press the `up` key on your keyboard until you see the correct instruction. This saves typing time if you are doing repetitive instructions.