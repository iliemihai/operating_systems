Chapter 06: Processes
=====================

ex 6.1
------
Compile the program in Example 6-1 (mem_segments.c), and list its size using ls -l. Although the program contains an array (mbuf) that is around 10 MB in size, the executable file is much smaller than this. Why is this?

Response: The mbuf is a static uninitialized data and therefore the program is not needed to allocate space for uninitialized data. Executable need to record the location and size for the uninitialized data segment, and the space is allocated at runtime by program loader.
If you look for the running process in memory, you can see that it will have apr 10MB:
ps aux | grep mem_segmetns
cat /proc/<ID>/status

VmPeak:	   14416 kB
VmSize:	   14416 kB
VmLck:	       0 kB
VmPin:	       0 kB
VmHWM:	     644 kB
VmRSS:	     644 kB


ex 6.2
------
is longjmp_ref_func.c and long_jmp_v2.c where e see the value for local variable in function after return.

ex 6.3 
------
Implement setenv() and unsetenv() using getenv(), putenv(), and, where necessary, code that directly modifies environ. Your version of unsetenv() should check to see whether there are multiple definitions of an environment variable, and remove them all (which is what the glibc version of unsetenv() does). 
