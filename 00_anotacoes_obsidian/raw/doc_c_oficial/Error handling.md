---
title: "Error handling"
source: "https://en.cppreference.com/c/error"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
### Error numbers

<table><tbody><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/error/errno">errno</a></p></td><td>macro which expands to POSIX-compatible thread-local error number variable<br>(macro variable)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/error/errno_macros">E2BIG, EACCES,..., EXDEV</a></p></td><td>macros for standard POSIX-compatible error conditions<br>(macro constant)</td></tr></tbody></table>

### Assertions

<table><tbody><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/error/assert">assert</a></p></td><td>aborts the program if the user-specified condition is not <code>true</code>. May be disabled for release builds<br>(function macro)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/error/static_assert">static_assert</a></p><p>(C11)(removed in C23)</p></td><td>issues a compile-time diagnostic if the value of a constant expression is false<br>(keyword macro)</td></tr></tbody></table>

<table><tbody><tr><td><h3>Bounds checking</h3><p>The standard library provides bounds-checked versions of some existing functions (gets, fopen, printf, strcpy, wcscpy, mbstowcs, qsort, getenv, etc). This functionality is <i>optional</i> and is only available if <code>__STDC_LIB_EXT1__</code> is defined. The following macros and functions support this functionality.</p><table><tbody><tr><td colspan="2"></td></tr><tr><td colspan="2"></td></tr><tr><td colspan="2"></td></tr><tr><td><p>errno_t</p><p>(C11)</p></td><td>a typedef for the type<pre><code>int</code></pre>, used to self-document functions that return values</td></tr><tr><td colspan="2"></td></tr><tr><td colspan="2"></td></tr><tr><td colspan="2"></td></tr><tr><td colspan="2"></td></tr><tr><td colspan="2"></td></tr><tr><td colspan="2"></td></tr><tr><td colspan="2"></td></tr><tr><td><p>rsize_t</p><p>(C11)</p></td><td>a typedef for the same type as size_t, used to self-document functions that range-check their parameters at runtime<br>(typedef)</td></tr><tr><td colspan="2"></td></tr><tr><td colspan="2"></td></tr><tr><td><p>RSIZE_MAX</p><p>(C11)</p></td><td>largest acceptable size for bounds-checked functions, expands to either constant or variable which may change at runtime (e.g. as the currently allocated memory size changes)<br>(macro variable)</td></tr><tr><td colspan="2"></td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/error/set_constraint_handler_s">set_constraint_handler_s</a></p><p>(C11)</p></td><td>set the error callback for bounds-checked functions<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/error/abort_handler_s">abort_handler_s</a></p><p>(C11)</p></td><td>abort callback for the bounds-checked functions<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/error/ignore_handler_s">ignore_handler_s</a></p><p>(C11)</p></td><td>ignore callback for the bounds-checked functions<br>(function)</td></tr></tbody></table><p>Note: implementations of bounds-checked functions are available as open-source libraries <a href="https://github.com/rurban/safeclib/">Safe C</a> and <a href="https://code.google.com/archive/p/slibc/">Slibc</a>, and as part of Watcom C. There is also an incompatible set of bounds-checked functions available in Visual Studio.</p></td><td>(since C11)</td></tr></tbody></table>

### Notes

Since C23, [static\_assert](https://en.cppreference.com/c/language/_Static_assert "c/language/ Static assert") is itself a keyword, which may also be a predefined macro, so `<assert.h>` no longer provides it.

### References

Extended content

### See also

<table><tbody><tr><td><p>(C99)(C99)(C99)</p></td><td>defines the error handling mechanism used by the common mathematical functions<br>(macro constant)</td></tr><tr><td colspan="2"><p><a href="https://en.cppreference.com/cpp/error">C++ documentation</a> for Error handling</p></td></tr></tbody></table>