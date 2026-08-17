---
title: "C keywords"
source: "https://en.cppreference.com/c/keyword"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
This is a list of reserved keywords in C. Since they are used by the language, these keywords are not available for re-definition. As an exception, they are not considered reserved in [attribute-tokens](https://en.cppreference.com/c/language/attributes "c/language/attributes") (since C23)

| [`alignas`](https://en.cppreference.com/c/keyword/alignas "c/keyword/alignas") (C23)   [`alignof`](https://en.cppreference.com/c/keyword/alignof "c/keyword/alignof") (C23)   [`auto`](https://en.cppreference.com/c/keyword/auto "c/keyword/auto")   [`bool`](https://en.cppreference.com/c/keyword/bool "c/keyword/bool") (C23)   [`break`](https://en.cppreference.com/c/keyword/break "c/keyword/break")   [`case`](https://en.cppreference.com/c/keyword/case "c/keyword/case")   [`char`](https://en.cppreference.com/c/keyword/char "c/keyword/char")   [`const`](https://en.cppreference.com/c/keyword/const "c/keyword/const")   [`constexpr`](https://en.cppreference.com/c/keyword/constexpr "c/keyword/constexpr") (C23)   [`continue`](https://en.cppreference.com/c/keyword/continue "c/keyword/continue")   [`default`](https://en.cppreference.com/c/keyword/default "c/keyword/default")   [`do`](https://en.cppreference.com/c/keyword/do "c/keyword/do")   [`double`](https://en.cppreference.com/c/keyword/double "c/keyword/double")   [`else`](https://en.cppreference.com/c/keyword/else "c/keyword/else")   [`enum`](https://en.cppreference.com/c/keyword/enum "c/keyword/enum") | [`extern`](https://en.cppreference.com/c/keyword/extern "c/keyword/extern")   [`false`](https://en.cppreference.com/c/keyword/false "c/keyword/false") (C23)   [`float`](https://en.cppreference.com/c/keyword/float "c/keyword/float")   [`for`](https://en.cppreference.com/c/keyword/for "c/keyword/for")   [`goto`](https://en.cppreference.com/c/keyword/goto "c/keyword/goto")   [`if`](https://en.cppreference.com/c/keyword/if "c/keyword/if")   [`inline`](https://en.cppreference.com/c/keyword/inline "c/keyword/inline") (C99)   [`int`](https://en.cppreference.com/c/keyword/int "c/keyword/int")   [`long`](https://en.cppreference.com/c/keyword/long "c/keyword/long")   [`nullptr`](https://en.cppreference.com/c/keyword/nullptr "c/keyword/nullptr") (C23)   [`register`](https://en.cppreference.com/c/keyword/register "c/keyword/register")   [`restrict`](https://en.cppreference.com/c/keyword/restrict "c/keyword/restrict") (C99)   [`return`](https://en.cppreference.com/c/keyword/return "c/keyword/return")   [`short`](https://en.cppreference.com/c/keyword/short "c/keyword/short")   [`signed`](https://en.cppreference.com/c/keyword/signed "c/keyword/signed") | [`sizeof`](https://en.cppreference.com/c/keyword/sizeof "c/keyword/sizeof")   [`static`](https://en.cppreference.com/c/keyword/static "c/keyword/static")   [`static_assert`](https://en.cppreference.com/c/keyword/static_assert "c/keyword/static assert") (C23)   [`struct`](https://en.cppreference.com/c/keyword/struct "c/keyword/struct")   [`switch`](https://en.cppreference.com/c/keyword/switch "c/keyword/switch")   [`thread_local`](https://en.cppreference.com/c/keyword/thread_local "c/keyword/thread local") (C23)   [`true`](https://en.cppreference.com/c/keyword/true "c/keyword/true") (C23)   [`typedef`](https://en.cppreference.com/c/keyword/typedef "c/keyword/typedef")   [`typeof`](https://en.cppreference.com/c/keyword/typeof "c/keyword/typeof") (C23)   [`typeof_unqual`](https://en.cppreference.com/c/keyword/typeof_unqual "c/keyword/typeof unqual") (C23)   [`union`](https://en.cppreference.com/c/keyword/union "c/keyword/union")   [`unsigned`](https://en.cppreference.com/c/keyword/unsigned "c/keyword/unsigned")   [`void`](https://en.cppreference.com/c/keyword/void "c/keyword/void")   [`volatile`](https://en.cppreference.com/c/keyword/volatile "c/keyword/volatile")   [`while`](https://en.cppreference.com/c/keyword/while "c/keyword/while") | [`_Alignas`](https://en.cppreference.com/c/keyword/_Alignas "c/keyword/ Alignas") (C11)(deprecated in C23)   [`_Alignof`](https://en.cppreference.com/c/keyword/_Alignof "c/keyword/ Alignof") (C11)(deprecated in C23)   [`_Atomic`](https://en.cppreference.com/c/keyword/_Atomic "c/keyword/ Atomic") (C11)   [`_BitInt`](https://en.cppreference.com/index.php?title=c/keyword/_BitInt&action=edit&redlink=1 "c/keyword/ BitInt (page does not exist)") (C23)   [`_Bool`](https://en.cppreference.com/c/keyword/_Bool "c/keyword/ Bool") (C99)(deprecated in C23)   [`_Complex`](https://en.cppreference.com/c/keyword/_Complex "c/keyword/ Complex") (C99)   [`_Decimal128`](https://en.cppreference.com/c/keyword/_Decimal128 "c/keyword/ Decimal128") (C23)   [`_Decimal32`](https://en.cppreference.com/c/keyword/_Decimal32 "c/keyword/ Decimal32") (C23)   [`_Decimal64`](https://en.cppreference.com/c/keyword/_Decimal64 "c/keyword/ Decimal64") (C23)   [`_Generic`](https://en.cppreference.com/c/keyword/_Generic "c/keyword/ Generic") (C11)   [`_Imaginary`](https://en.cppreference.com/c/keyword/_Imaginary "c/keyword/ Imaginary") (C99)   [`_Noreturn`](https://en.cppreference.com/c/keyword/_Noreturn "c/keyword/ Noreturn") (C11)(deprecated in C23)   [`_Static_assert`](https://en.cppreference.com/c/keyword/_Static_assert "c/keyword/ Static assert") (C11)(deprecated in C23)   [`_Thread_local`](https://en.cppreference.com/c/keyword/_Thread_local "c/keyword/ Thread local") (C11)(deprecated in C23) |
| --- | --- | --- | --- |

The most common keywords that begin with an underscore are generally used through their convenience macros:

| Keyword | Used as | Defined in |
| --- | --- | --- |
| [`_Alignas`](https://en.cppreference.com/c/keyword/_Alignas "c/keyword/ Alignas") (C11)(deprecated in C23) | [alignas](https://en.cppreference.com/c/types "c/types") (removed in C23) | `stdalign.h` |
| [`_Alignof`](https://en.cppreference.com/c/keyword/_Alignof "c/keyword/ Alignof") (C11)(deprecated in C23) | [alignof](https://en.cppreference.com/c/types "c/types") (removed in C23) | `stdalign.h` |
| [`_Atomic`](https://en.cppreference.com/c/keyword/_Atomic "c/keyword/ Atomic") (C11) | [atomic\_bool, atomic\_int,...](https://en.cppreference.com/c/thread "c/thread") | `stdatomic.h` |
| [`_BitInt`](https://en.cppreference.com/index.php?title=c/keyword/_BitInt&action=edit&redlink=1 "c/keyword/ BitInt (page does not exist)") (C23) | (no macro) |  |
| [`_Bool`](https://en.cppreference.com/c/keyword/_Bool "c/keyword/ Bool") (C99)(deprecated in C23) | [bool](https://en.cppreference.com/c/types "c/types") (removed in C23) | `stdbool.h` |
| [`_Complex`](https://en.cppreference.com/c/keyword/_Complex "c/keyword/ Complex") (C99) | [complex](https://en.cppreference.com/c/numeric/complex/complex "c/numeric/complex/complex") | `complex.h` |
| [`_Decimal128`](https://en.cppreference.com/c/keyword/_Decimal128 "c/keyword/ Decimal128") (C23) | (no macro) |  |
| [`_Decimal32`](https://en.cppreference.com/c/keyword/_Decimal32 "c/keyword/ Decimal32") (C23) | (no macro) |  |
| [`_Decimal64`](https://en.cppreference.com/c/keyword/_Decimal64 "c/keyword/ Decimal64") (C23) | (no macro) |  |
| [`_Generic`](https://en.cppreference.com/c/keyword/_Generic "c/keyword/ Generic") (C11) | (no macro) |  |
| [`_Imaginary`](https://en.cppreference.com/c/keyword/_Imaginary "c/keyword/ Imaginary") (C99) | [imaginary](https://en.cppreference.com/c/numeric/complex/imaginary "c/numeric/complex/imaginary") | `complex.h` |
| [`_Noreturn`](https://en.cppreference.com/c/keyword/_Noreturn "c/keyword/ Noreturn") (C11)(deprecated in C23) | [noreturn](https://en.cppreference.com/c/types "c/types") | `stdnoreturn.h` |
| [`_Static_assert`](https://en.cppreference.com/c/keyword/_Static_assert "c/keyword/ Static assert") (C11)(deprecated in C23) | [static\_assert](https://en.cppreference.com/c/error/static_assert "c/error/static assert") (removed in C23) | `assert.h` |
| [`_Thread_local`](https://en.cppreference.com/c/keyword/_Thread_local "c/keyword/ Thread local") (C11)(deprecated in C23) | [thread\_local](https://en.cppreference.com/c/thread/thread_local "c/thread/thread local") (removed in C23) | `threads.h` |

Some keywords are deprecated and retained as alternative spellings for compatibility purposes. These can be used wherever the keyword can.

| Keyword | Alternative spelling |
| --- | --- |
| `alignas` (C23) | `_Alignas` (C11)(deprecated in C23) |
| `alignof` (C23) | `_Alignof` (C11)(deprecated in C23) |
| `bool` (C23) | `_Bool` (C99)(deprecated in C23) |
| `static_assert` (C23) | `_Static_assert` (C11)(deprecated in C23) |
| `thread_local` (C23) | `_Thread_local` (C11)(deprecated in C23) |

It is unspecified whether any of the spellings of these keywords, their alternate forms, or `true` and `false` is implemented as a predefined macro.

Each name that begins with a double underscore `**__**` or an underscore `**_**` followed by an uppercase letter is reserved: see [identifier](https://en.cppreference.com/c/language/identifier#Reserved_identifiers "c/language/identifier") for details.

Note that digraphs `<%`, `%>`, `<:`, `:>`, `%:`, and `%:%:` provide an [alternative way to represent standard tokens](https://en.cppreference.com/c/language/operator_alternative "c/language/operator alternative").

The following tokens are recognized by the [preprocessor](https://en.cppreference.com/c/preprocessor "c/preprocessor") when they are used *within* the context of a preprocessor directive:

| [if](https://en.cppreference.com/c/preprocessor/conditional "c/preprocessor/conditional")   [elif](https://en.cppreference.com/c/preprocessor/conditional "c/preprocessor/conditional")   [else](https://en.cppreference.com/c/preprocessor/conditional "c/preprocessor/conditional")   [endif](https://en.cppreference.com/c/preprocessor/conditional "c/preprocessor/conditional") | [ifdef](https://en.cppreference.com/c/preprocessor/conditional "c/preprocessor/conditional")   [ifndef](https://en.cppreference.com/c/preprocessor/conditional "c/preprocessor/conditional")   [elifdef](https://en.cppreference.com/c/preprocessor/conditional "c/preprocessor/conditional") (C23)   [elifndef](https://en.cppreference.com/c/preprocessor/conditional "c/preprocessor/conditional") (C23)   [define](https://en.cppreference.com/c/preprocessor/replace "c/preprocessor/replace")   [undef](https://en.cppreference.com/c/preprocessor/replace "c/preprocessor/replace") | [include](https://en.cppreference.com/c/preprocessor/include "c/preprocessor/include")   [embed](https://en.cppreference.com/c/preprocessor/embed "c/preprocessor/embed") (C23)   [line](https://en.cppreference.com/c/preprocessor/line "c/preprocessor/line")   [error](https://en.cppreference.com/c/preprocessor/error "c/preprocessor/error")   [warning](https://en.cppreference.com/c/preprocessor/error "c/preprocessor/error") (C23)   [pragma](https://en.cppreference.com/c/preprocessor/impl "c/preprocessor/impl") | [defined](https://en.cppreference.com/c/preprocessor/conditional "c/preprocessor/conditional")   [\_\_has\_include](https://en.cppreference.com/c/preprocessor/include "c/preprocessor/include") (C23)   [\_\_has\_embed](https://en.cppreference.com/c/preprocessor/embed "c/preprocessor/embed") (C23)   [\_\_has\_c\_attribute](https://en.cppreference.com/c/language/attributes#Attribute_testing "c/language/attributes") (C23) |
| --- | --- | --- | --- |

The following tokens are recognized by the preprocessor when they are used *outside* the context of a preprocessor directive:

[\_Pragma](https://en.cppreference.com/c/preprocessor/impl "c/preprocessor/impl") (C99)

The following additional keywords are classified as extensions and conditionally-supported:

[asm](https://en.cppreference.com/c/language/asm "c/language/asm")  
[`fortran`](https://en.cppreference.com/c/keyword/fortran "c/keyword/fortran")

### References

- C23 standard (ISO/IEC 9899:2024):

- 6.4.1 Keywords (p: 53)

- J.5.9 The fortran keyword (p: 601)

- J.5.10 The asm keyword (p: 601)

- C17 standard (ISO/IEC 9899:2018):

- 6.4.1 Keywords (p: 42-43)

- J.5.9 The fortran keyword (p: 422)

- J.5.10 The asm keyword (p: 422)

- C11 standard (ISO/IEC 9899:2011):

- 6.4.1 Keywords (p: 58-59)

- C99 standard (ISO/IEC 9899:1999):

- 6.4.1 Keywords (p: 50)

- C89/C90 standard (ISO/IEC 9899:1990):

- 3.1.1 Keywords

### See also

[C++ documentation](https://en.cppreference.com/cpp/keyword "cpp/keyword") for C++ keywords