---
title: "Type support"
source: "https://en.cppreference.com/c/types"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
See also [type system overview](https://en.cppreference.com/c/language/types "c/language/types") and [arithmetic types defined by the language](https://en.cppreference.com/c/language/arithmetic_types "c/language/arithmetic types").

### Basic types

#### Additional basic types and convenience macros

<table><tbody><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/types/size_t">size_t</a></p></td><td>unsigned integer type returned by the <a href="https://en.cppreference.com/c/language/sizeof"><tt>sizeof</tt></a> operator<br>(typedef)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/types/ptrdiff_t">ptrdiff_t</a></p></td><td>signed integer type returned when subtracting two pointers<br>(typedef)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/types/nullptr_t">nullptr_t</a></p><p>(C23)</p></td><td>the type of the predefined null pointer constant <a href="https://en.cppreference.com/c/language/nullptr"><tt>nullptr</tt></a><br>(typedef)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/types/NULL">NULL</a></p></td><td>implementation-defined null pointer constant<br>(macro constant)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/types/max_align_t">max_align_t</a></p><p>(C11)</p></td><td>a type with alignment requirement as great as any other scalar type<br>(typedef)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/types/offsetof">offsetof</a></p></td><td>byte offset from the beginning of a struct type to specified member<br>(function macro)</td></tr><tr><td colspan="2"></td></tr><tr><td><p>bool</p><p>(C99)(removed in C23)</p></td><td>convenience macro, expands to <a href="https://en.cppreference.com/c/keyword/_Bool"><tt>_Bool</tt></a><br>(keyword macro)</td></tr><tr><td><p>true</p><p>(C99)(removed in C23)</p></td><td>expands to integer constant <code>1</code><br>(macro constant)</td></tr><tr><td><p>false</p><p>(C99)(removed in C23)</p></td><td>expands to integer constant <code>0</code><br>(macro constant)</td></tr><tr><td><p>__bool_true_false_are_defined</p><p>(C99)(deprecated in C23)</p></td><td>expands to integer constant <code>1</code><br>(macro constant)</td></tr><tr><td colspan="2"></td></tr><tr><td><p>alignas</p><p>(C11)(removed in C23)</p></td><td>convenience macro, expands to keyword <a href="https://en.cppreference.com/c/keyword/_Alignas"><tt>_Alignas</tt></a><br>(keyword macro)</td></tr><tr><td><p>alignof</p><p>(C11)(removed in C23)</p></td><td>convenience macro, expands to keyword <a href="https://en.cppreference.com/c/keyword/_Alignof"><tt>_Alignof</tt></a><br>(keyword macro)</td></tr><tr><td><p>__alignas_is_defined</p><p>(C11)(removed in C23)</p></td><td>expands to integer constant <code>1</code><br>(macro constant)</td></tr><tr><td><p>__alignof_is_defined</p><p>(C11)(removed in C23)</p></td><td>expands to integer constant <code>1</code><br>(macro constant)</td></tr><tr><td colspan="2"></td></tr><tr><td><p>noreturn</p><p>(C11)(deprecated in C23)</p></td><td>convenience macro, expands to <a href="https://en.cppreference.com/c/keyword/_Noreturn"><tt>_Noreturn</tt></a><br>(keyword macro)</td></tr></tbody></table>

#### Fixed width integer types (since C99)

#### Numeric limits

### Notes

| The type of `true` and `false` is  ``` int ``` rather than ``` _Bool ``` .  A program may undefine and perhaps then redefine the macros  ``` bool ``` , `true` and `false`. However, such ability is a deprecated feature. | (since C99)   (until C23) |
| --- | --- |
| The type of `true` and `false` is  ``` bool ``` . It is unspecified whether any of ``` bool ``` , ``` _Bool ``` , `true`, or `false` is implemented as a predefined macro.  If  ``` bool ``` , `true`, or `false` (but not ``` _Bool ``` ) is defined as a predefined macro, a program may undefine and perhaps redefine it. | (since C23) |

### Example

```
#include <stdalign.h>
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    printf("%d %d %d\n", true && false, true || false, !false);
    printf("%d %d\n", true ^ true, true + true);
    printf("%zu\n", alignof(short));
}
```

Possible output:

```
0 1 1
0 2
2
```

### References

- C23 standard (ISO/IEC 9899:2024):

- 7.15 Alignment <stdalign.h> (p: TBD)

- 7.18 Boolean type and values <stdbool.h> (p: TBD)

- 7.19 Common definitions <stddef.h> (p: TBD)

- 7.23 \_Noreturn <stdnoreturn.h> (p: TBD)

- 7.31.9 Boolean type and values <stdbool.h> (p: TBD)

- C17 standard (ISO/IEC 9899:2018):

- 7.15 Alignment <stdalign.h> (p: 196)

- 7.18 Boolean type and values <stdbool.h> (p: 210)

- 7.19 Common definitions <stddef.h> (p: 211)

- 7.23 \_Noreturn <stdnoreturn.h> (p: 263)

- 7.31.9 Boolean type and values <stdbool.h> (p: 332)

- C11 standard (ISO/IEC 9899:2011):

- 7.15 Alignment <stdalign.h> (p: 268)

- 7.18 Boolean type and values <stdbool.h> (p: 287)

- 7.19 Common definitions <stddef.h> (p: 288)

- C99 standard (ISO/IEC 9899:1999):

- 7.18 Boolean type and values <stdbool.h> (p: 253)

- C89/C90 standard (ISO/IEC 9899:1990):

- 4.1.5 Common definitions <stddef.h>

### See also

[C++ documentation](https://en.cppreference.com/cpp/types "cpp/types") for Type support library