# Operating System Lab (CSE 3242)

1. Create child and parent process
2. Effect of wait in child and parent process relationship
3. Check parent process of orphan process
4. Use exclp() to execute a separate exe file as child process
5. Check how multi-threading helps us to execute multiple processes at the same time. (a. Check global and local variable variable effect c. Check thread race problem)
6. Study about system calls: exit(), wait(), read(), open()
7. Write a program to learn read() from keyboard file and write() into monitor file
8. Write a program to read from a normal file/conventional file and display to monitor using open() read() write() system calls.
9. Write a program to write a normal file/conventional file using open() read() write() system calls.
10. Write a program to create a named pipe using mkfifo() system call.
11. Write a program to write in a named pipe what is read from the keyboard using open() read() write() system calls.
12. Write a program to read from a named pipe and display to monitor using open() read() write() system calls.
13. Write a chat-room using a named pipe. (a. Start from one end and one by one message. b. Start from both ends and message simultaneously)
14. Investigate what would happened if you try to open a named pipe for reading multiple times.
15. Implement a unnamed pipe to send specific message (Say "Don't wait for me") from a child process to parent process to inform not to wait for the child process. 
16. Investigate if two separate process try to read a named pipe first and then write to the pipe.
17. Investigate when race condition occurs in a multi-threaded program.
18. Find a solution to avoid race condition in a multi-threaded program.
19. Check how many core you have in your system. Create 4 more process than your core and use a for loop to understand how os schedule the process in different core. Each core should have three thread. Use get_cpu() to read the assigned core and set_cpu() to set the core for each thread. 
20. If we lock the thread twice, without unlocking it, what would happen? Investigate it.
21. If you have two thread and you use two mutex for each thread, what would happen for each combination? Investigate it. Example:

```
mutex_lock(key1)
mutex_lock(key2)
##-- Critical Section --##
mutex_lock(key1)
mutex_lock(key2)
```
22. Inter-Process Communication (Shared Memory)
23. Zombie Process
24. Signal 
25. Stack Smashing
