- The command line typed by the user consists of a name and zero or more arguments, all separated by one or more spaces. If name is a built-in command, the
shell handles it immediately and waits for the next command line. Otherwise,
the shell assumes that name is an executable file, which it loads and runs in the
context of an initial child process (job). The process group ID for the job is
identical to the PID of the child.
- Each job is identified by either a process ID (PID) or a job ID (JID), which
is a small arbitrary positive integer assigned by the shell. JIDs are denoted on
the command line by the prefix ‘%’. For example, ‘%5’ denotes JID 5, and ‘5’
denotes PID 5
- If the command line ends with an ampersand, then the shell runs the job in
the background. Otherwise, the shell runs the job in the foreground.
- Typing Ctrl+C (Ctrl+Z) causes the kernel to send a SIGINT (SIGTSTP) signal
to your shell, which then forwards it to every process in the foreground process
group
- The jobs built-in command lists all background jobs.

- The bg job built-in command restarts job by sending it a SIGCONT signal
and then runs it in the background. The job argument can be either a PID or
a JID.
- The fg job built-in command restartsjob by sending it a SIGCONT signal and
then runs it in the foreground.
-  The shell reaps all of its zombie children. If any job terminates because it
receives a signal that was not caught, then the shell prints a message to the
terminal with the job’s PID and a description of the offending signal.

```bash
linux> ./shell Run your shell program
>bogus
bogus: Command not found. Execve can’t find executable
>foo 10
Job 5035 terminated by signal: Interrupt User types Ctrl+C
>foo 100 &
[1] 5036 foo 100 &
>foo 200 &
[2] 5037 foo 200 &
>jobs
[1] 5036 Running foo 100 &
[2] 5037 Running foo 200 &
>fg %1
Job [1] 5036 stopped by signal: Stopped User types Ctrl+Z
>jobs
[1] 5036 Stopped foo 100 &
[2] 5037 Running foo 200 &
>bg 5035
5035: No such process
>bg 5036
[1] 5036 foo 100 &
>/bin/kill 5036
Job 5036 terminated by signal: Terminated
> fg %2 Wait for fg job to finish
>quit
linux> 
# Back to the Unix shell
```