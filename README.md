What is this?
=============

This code consists of wrapper functions that filter parameters of potentially
"unsafe" libc functions (like `gets`) to make them usable without the risk of
of buffer overflows.

How does it work?
=================

Code is instrumented with AddressSanitizer and wrapper functions around
(potentially) unsafe libc functions use information from AddressSanitizer to
prevent buffer overflows. Our libc can mitigate unterminated strings,
wrong length information and overflows in unsafe functions like `gets`.

How to build the toolchain
==========================

```
git clone https://github.com/llvm-mirror/llvm
(cd llvm/tools && git clone https://github.com/llvm-mirror/clang)
(cd llvm/projects && git clone https://github.com/pekd/compiler-rt)
(cd llvm/projects && git checkout safe)
mkdir llvm-build && cd llvm-build
CC=clang CXX=clang++ cmake -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_ASSERTIONS=ON -DLLVM_TARGETS_TO_BUILD=X86 ~/git/llvm
make
export PATH=$(pwd)/bin:$PATH
```

How to build a program using the safe libc
==========================================

To compile with ASan, use the `compile-asan` script (and edit the
`CLANG_PATH` if necessary):

```
./compile-asan -o gets examples/gets.c
```

To compile with Intel MPX and GCC Pointer Bounds Checker, use the
`compile-mpx` script:

```
./compile-mpx -o gets examples/gets.c
```


And in the real world?
======================

… it can prevent exploitation of vulnerabilities without crashing the program,
as long as a libc function call with invalid parameters causes the overflow.
For example, check out the bugs below:

- CVE-2017-9047 ([Bug report](http://www.openwall.com/lists/oss-security/2017/05/15/1))
- CVE-2017-14493 ([Google blogpost](https://security.googleblog.com/2017/10/behind-masq-yet-more-dns-and-dhcp.html))
- CVE-2017-14496 ([Google blogpost](https://security.googleblog.com/2017/10/behind-masq-yet-more-dns-and-dhcp.html))
