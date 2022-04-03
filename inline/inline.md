https://gcc.gnu.org/onlinedocs/gcc-4.4.2/gcc/Inline.html

If you are writing a header file to be included in ISO C89 programs, write `__inline__` instead of `inline`

To `inline` is to remove the function call and place it's contents directly where the call would be made.
This often removes the overhead of calling a function.
It is not always optimal, because of code bloat (code getting too big and not fitting into cache),
so most compilers will ignore all inline directives and do what they feel is best.

When a function is both `inline` and `static`, if all calls to the function are integrated into the caller, and the function's
address is never used, then the function's own assembler code is never referenced.

GCC does not `inline` any functions when not optimizing unless you specify the ``always_inline'` attribute for the function, like this:

`/* Prototype.  */`
`inline void foo (const char) __attribute__((always_inline));`

The remainder of this section is specific to GNU C89 inlining.

When an `inline` function is not `static`, then the compiler must assume that there may be calls from other source files; since a global symbol can be defined only once in any program, the function must not be defined in the other source files, so the calls therein cannot be integrated. Therefore, a non-static inline function is always compiled on its own in the usual fashion.

If you specify both `inline` and `extern` in the function definition, then the definition is used only for inlining. In no case is the function compiled on its own, not even if you refer to its address explicitly. Such an address becomes an external reference, as if you had only declared the function, and had not defined it.

This combination of `inline` and `extern` has almost the effect of a macro. The way to use it is to put a function definition in a header file with these keywords, and put another copy of the definition (lacking `inline` and `extern`) in a library file. The definition in the header file will cause most calls to the function to be inlined. If any uses of the function remain, they will refer to the single copy in the library.
