---
title: "C Standard Library headers"
source: "https://en.cppreference.com/c/header"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
The interface of C standard library is defined by the following collection of headers.

| [<assert.h>](https://en.cppreference.com/c/header/assert "c/header/assert") | [Conditionally compiled macro that compares its argument to zero](https://en.cppreference.com/c/error "c/error") |
| --- | --- |
| [<complex.h>](https://en.cppreference.com/c/header/complex "c/header/complex") (since C99) | [Complex number arithmetic](https://en.cppreference.com/c/numeric/complex "c/numeric/complex") |
| [<ctype.h>](https://en.cppreference.com/c/header/ctype "c/header/ctype") | [Functions to determine the type contained in character data](https://en.cppreference.com/c/string/byte "c/string/byte") |
| [<errno.h>](https://en.cppreference.com/c/header/errno "c/header/errno") | [Macros reporting error conditions](https://en.cppreference.com/c/error "c/error") |
| [<fenv.h>](https://en.cppreference.com/c/header/fenv "c/header/fenv") (since C99) | [Floating-point environment](https://en.cppreference.com/c/numeric/fenv "c/numeric/fenv") |
| [<float.h>](https://en.cppreference.com/c/header/float "c/header/float") | [Limits of floating-point types](https://en.cppreference.com/c/types/limits#Limits_of_floating-point_types "c/types/limits") |
| [<inttypes.h>](https://en.cppreference.com/c/header/inttypes "c/header/inttypes") (since C99) | [Format conversion of integer types](https://en.cppreference.com/c/types/integer "c/types/integer") |
| [<iso646.h>](https://en.cppreference.com/c/header/iso646 "c/header/iso646") (since C95) | [Alternative operator spellings](https://en.cppreference.com/c/language/operator_alternative "c/language/operator alternative") |
| [<limits.h>](https://en.cppreference.com/c/header/limits "c/header/limits") | [Ranges of integer types](https://en.cppreference.com/c/types/limits "c/types/limits") |
| [<locale.h>](https://en.cppreference.com/c/header/locale "c/header/locale") | [Localization utilities](https://en.cppreference.com/c/locale "c/locale") |
| [<math.h>](https://en.cppreference.com/c/header/math "c/header/math") | [Common mathematics functions](https://en.cppreference.com/c/numeric/math "c/numeric/math") |
| [<setjmp.h>](https://en.cppreference.com/c/header/setjmp "c/header/setjmp") | [Nonlocal jumps](https://en.cppreference.com/c/program "c/program") |
| [<signal.h>](https://en.cppreference.com/c/header/signal "c/header/signal") | [Signal handling](https://en.cppreference.com/c/program "c/program") |
| [<stdalign.h>](https://en.cppreference.com/c/header/stdalign "c/header/stdalign") (since C11)(deprecated in C23) | [`alignas` and `alignof`](https://en.cppreference.com/c/types "c/types") convenience macros |
| [<stdarg.h>](https://en.cppreference.com/c/header/stdarg "c/header/stdarg") | [Variable arguments](https://en.cppreference.com/c/variadic "c/variadic") |
| [<stdatomic.h>](https://en.cppreference.com/c/header/stdatomic "c/header/stdatomic") (since C11) | [Atomic operations](https://en.cppreference.com/c/thread#Atomic_operations "c/thread") |
| [<stdbit.h>](https://en.cppreference.com/c/header/stdbit "c/header/stdbit") (since C23) | [Macros to work with the byte and bit representations of types](https://en.cppreference.com/c/numeric#Bit_manipulation "c/numeric") |
| [<stdbool.h>](https://en.cppreference.com/c/header/stdbool "c/header/stdbool") (since C99)(deprecated in C23) | [Macros for boolean type](https://en.cppreference.com/c/types "c/types") |
| [<stdckdint.h>](https://en.cppreference.com/c/header/stdckdint "c/header/stdckdint") (since C23) | [Macros for performing checked integer arithmetic](https://en.cppreference.com/c/numeric#Checked_integer_arithmetic "c/numeric") |
| [<stddef.h>](https://en.cppreference.com/c/header/stddef "c/header/stddef") | [Common macro definitions](https://en.cppreference.com/c/types "c/types") |
| [<stdint.h>](https://en.cppreference.com/c/header/stdint "c/header/stdint") (since C99) | [Fixed-width integer types](https://en.cppreference.com/c/types/integer "c/types/integer") |
| [<stdio.h>](https://en.cppreference.com/c/header/stdio "c/header/stdio") | [Input/output](https://en.cppreference.com/c/io "c/io") |
| [<stdlib.h>](https://en.cppreference.com/c/header/stdlib "c/header/stdlib") | General utilities: [memory management](https://en.cppreference.com/c/memory "c/memory"), [program utilities](https://en.cppreference.com/c/program "c/program"), [string conversions](https://en.cppreference.com/c/string "c/string"), [random numbers](https://en.cppreference.com/c/numeric/random "c/numeric/random"), [algorithms](https://en.cppreference.com/c/algorithm "c/algorithm") |
| [<stdmchar.h>](https://en.cppreference.com/c/header/stdmchar "c/header/stdmchar") (since C29) | Text transcode |
| [<stdnoreturn.h>](https://en.cppreference.com/c/header/stdnoreturn "c/header/stdnoreturn") (since C11)(deprecated in C23) | [noreturn](https://en.cppreference.com/c/language/_Noreturn "c/language/ Noreturn") convenience macro |
| [<string.h>](https://en.cppreference.com/c/header/string "c/header/string") | [String handling](https://en.cppreference.com/c/string/byte "c/string/byte") |
| [<tgmath.h>](https://en.cppreference.com/c/header/tgmath "c/header/tgmath") (since C99) | [Type-generic math](https://en.cppreference.com/c/numeric/tgmath "c/numeric/tgmath") (macros wrapping math.h and complex.h) |
| [<threads.h>](https://en.cppreference.com/c/header/threads "c/header/threads") (since C11) | [Thread library](https://en.cppreference.com/c/thread "c/thread") |
| [<time.h>](https://en.cppreference.com/c/header/time "c/header/time") | [Time/date utilities](https://en.cppreference.com/c/chrono "c/chrono") |
| [<uchar.h>](https://en.cppreference.com/c/header/uchar "c/header/uchar") (since C11) | [UTF-16 and UTF-32 character utilities](https://en.cppreference.com/c/string/multibyte "c/string/multibyte") |
| [<wchar.h>](https://en.cppreference.com/c/header/wchar "c/header/wchar") (since C95) | [Extended multibyte and wide character utilities](https://en.cppreference.com/c/string/wide "c/string/wide") |
| [<wctype.h>](https://en.cppreference.com/c/header/wctype "c/header/wctype") (since C95) | [Functions to determine the type contained in wide character data](https://en.cppreference.com/c/string/wide "c/string/wide") |

### Feature test macros (since C23)

Feature test macros are defined in corresponding headers respectively since C23. Note that not all headers contain such a macro.

<table><thead><tr><th>#</th><th>Header</th><th>Macro name</th><th>Value</th></tr></thead><tbody><tr><td>1</td><td><a href="https://en.cppreference.com/c/header/assert"><tt><assert.h></tt></a></td><td><code>__STDC_VERSION_ASSERT_H__</code></td><td><code>202311L</code></td></tr><tr><td>2</td><td><a href="https://en.cppreference.com/c/header/complex"><tt><complex.h></tt></a></td><td><code>__STDC_VERSION_COMPLEX_H__</code></td><td><code>202311L</code></td></tr><tr><td>3</td><td><a href="https://en.cppreference.com/c/header/ctype"><tt><ctype.h></tt></a></td><td colspan="2"><small>N/A</small></td></tr><tr><td>4</td><td><a href="https://en.cppreference.com/c/header/errno"><tt><errno.h></tt></a></td><td colspan="2"><small>N/A</small></td></tr><tr><td>5</td><td><a href="https://en.cppreference.com/c/header/fenv"><tt><fenv.h></tt></a></td><td><code>__STDC_VERSION_FENV_H__</code></td><td><code>202311L</code></td></tr><tr><td>6</td><td><a href="https://en.cppreference.com/c/header/float"><tt><float.h></tt></a></td><td><code>__STDC_VERSION_FLOAT_H__</code></td><td><code>202311L</code></td></tr><tr><td>7</td><td><a href="https://en.cppreference.com/c/header/inttypes"><tt><inttypes.h></tt></a></td><td><code>__STDC_VERSION_INTTYPES_H__</code></td><td><code>202311L</code></td></tr><tr><td>8</td><td><a href="https://en.cppreference.com/c/header/iso646"><tt><iso646.h></tt></a></td><td colspan="2"><small>N/A</small></td></tr><tr><td>9</td><td><a href="https://en.cppreference.com/c/header/limits"><tt><limits.h></tt></a></td><td><code>__STDC_VERSION_LIMITS_H__</code></td><td><code>202311L</code></td></tr><tr><td>10</td><td><a href="https://en.cppreference.com/c/header/locale"><tt><locale.h></tt></a></td><td colspan="2"><small>N/A</small></td></tr><tr><td>11</td><td><a href="https://en.cppreference.com/c/header/math"><tt><math.h></tt></a></td><td><code>__STDC_VERSION_MATH_H__</code></td><td><code>202311L</code></td></tr><tr><td>12</td><td><a href="https://en.cppreference.com/c/header/setjmp"><tt><setjmp.h></tt></a></td><td><code>__STDC_VERSION_SETJMP_H__</code></td><td><code>202311L</code></td></tr><tr><td>13</td><td><a href="https://en.cppreference.com/c/header/signal"><tt><signal.h></tt></a></td><td colspan="2"><small>N/A</small></td></tr><tr><td>14</td><td><a href="https://en.cppreference.com/c/header/stdalign"><tt><stdalign.h></tt></a></td><td colspan="2"><small>N/A</small></td></tr><tr><td>15</td><td><a href="https://en.cppreference.com/c/header/stdarg"><tt><stdarg.h></tt></a></td><td><code>__STDC_VERSION_STDARG_H__</code></td><td><code>202311L</code></td></tr><tr><td>16</td><td><a href="https://en.cppreference.com/c/header/stdatomic"><tt><stdatomic.h></tt></a></td><td><code>__STDC_VERSION_STDATOMIC_H__</code></td><td><code>202311L</code></td></tr><tr><td>17</td><td><a href="https://en.cppreference.com/c/header/stdbit"><tt><stdbit.h></tt></a></td><td><code>__STDC_VERSION_STDBIT_H__</code></td><td><code>202311L</code></td></tr><tr><td>18</td><td><a href="https://en.cppreference.com/c/header/stdbool"><tt><stdbool.h></tt></a></td><td colspan="2"><small>N/A</small></td></tr><tr><td>19</td><td><a href="https://en.cppreference.com/c/header/stdckdint"><tt><stdckdint.h></tt></a></td><td><code>__STDC_VERSION_STDCKDINT_H__</code></td><td><code>202311L</code></td></tr><tr><td>20</td><td><a href="https://en.cppreference.com/c/header/stddef"><tt><stddef.h></tt></a></td><td><code>__STDC_VERSION_STDDEF_H__</code></td><td><code>202311L</code></td></tr><tr><td>21</td><td><a href="https://en.cppreference.com/c/header/stdint"><tt><stdint.h></tt></a></td><td><code>__STDC_VERSION_STDINT_H__</code></td><td><code>202311L</code></td></tr><tr><td>22</td><td><a href="https://en.cppreference.com/c/header/stdio"><tt><stdio.h></tt></a></td><td><code>__STDC_VERSION_STDIO_H__</code></td><td><code>202311L</code></td></tr><tr><td>23</td><td><a href="https://en.cppreference.com/c/header/stdlib"><tt><stdlib.h></tt></a></td><td><code>__STDC_VERSION_STDLIB_H__</code></td><td><code>202311L</code></td></tr><tr><td>24</td><td><a href="https://en.cppreference.com/c/header/stdmchar"><tt><stdmchar.h></tt></a></td><td><code>__STDC_VERSION_STDMCHAR_H__</code></td><td><code>2029??L</code></td></tr><tr><td>25</td><td><a href="https://en.cppreference.com/c/header/stdnoreturn"><tt><stdnoreturn.h></tt></a></td><td colspan="2"><small>N/A</small></td></tr><tr><td>26</td><td><a href="https://en.cppreference.com/c/header/string"><tt><string.h></tt></a></td><td><code>__STDC_VERSION_STRING_H__</code></td><td><code>202311L</code></td></tr><tr><td>27</td><td><a href="https://en.cppreference.com/c/header/tgmath"><tt><tgmath.h></tt></a></td><td><code>__STDC_VERSION_TGMATH_H__</code></td><td><code>202311L</code></td></tr><tr><td>28</td><td><a href="https://en.cppreference.com/c/header/threads"><tt><threads.h></tt></a></td><td colspan="2"><small>N/A</small></td></tr><tr><td>29</td><td><a href="https://en.cppreference.com/c/header/time"><tt><time.h></tt></a></td><td><code>__STDC_VERSION_TIME_H__</code></td><td><code>202311L</code></td></tr><tr><td>30</td><td><a href="https://en.cppreference.com/c/header/uchar"><tt><uchar.h></tt></a></td><td><code>__STDC_VERSION_UCHAR_H__</code></td><td><code>202311L</code></td></tr><tr><td>31</td><td><a href="https://en.cppreference.com/c/header/wchar"><tt><wchar.h></tt></a></td><td><code>__STDC_VERSION_WCHAR_H__</code></td><td><code>202311L</code></td></tr><tr><td>32</td><td><a href="https://en.cppreference.com/c/header/wctype"><tt><wctype.h></tt></a></td><td colspan="2"><small>N/A</small></td></tr></tbody></table>

### References

- C23 standard (ISO/IEC 9899:2024):

- 7.1.2 Standard headers

- C17 standard (ISO/IEC 9899:2018):

- 7.1.2 Standard headers (p: 131-132)

- C11 standard (ISO/IEC 9899:2011):

- 7.1.2 Standard headers (p: 181-182)

- C99 standard (ISO/IEC 9899:1999):

- 7.1.2 Standard headers (p: 165)

- C89/C90 standard (ISO/IEC 9899:1990):

- 4.1.2 Standard headers

### See also

[C++ documentation](https://en.cppreference.com/cpp/header "cpp/header") for C++ Standard Library headers