https://gcc.gnu.org/onlinedocs/gcc-4.4.2/gcc/Inline.html

If you are writing a header file to be included in ISO C89 programs, write `__inline__` instead of inline

To inline is to remove the function call and place it's contents directly where the call would be made.
This often removes the overhead of calling a function.
It is not always optimal, because of code bloat (code getting too big and not fitting into cache),
so most compilers will ignore all inline directives and do what they feel is best.

When a function is both inline and static, if all calls to the function are integrated into the caller, and the function's
address is never used, then the function's own assembler code is never referenced.
