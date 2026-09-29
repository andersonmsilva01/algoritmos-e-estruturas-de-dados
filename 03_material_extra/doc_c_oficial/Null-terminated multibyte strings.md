---
title: "Null-terminated multibyte strings"
source: "https://en.cppreference.com/c/string/multibyte"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
A null-terminated multibyte string (NTMBS), or "multibyte string", is a sequence of nonzero bytes followed by a byte with value zero (the terminating null character).

Each character stored in the string may occupy more than one byte. The encoding used to represent characters in a multibyte character string is locale-specific: it may be UTF-8, GB18030, EUC-JP, Shift-JIS, etc. For example, the char array `{'\xe4','\xbd','\xa0','\xe5','\xa5','\xbd','\0'}` is an NTMBS holding the string `"你好"` in UTF-8 multibyte encoding: the first three bytes encode the character 你, the next three bytes encode the character 好. The same string encoded in GB18030 is the char array `{'\xc4', '\xe3', '\xba', '\xc3', '\0'}`, where each of the two characters is encoded as a two-byte sequence.

In some multibyte encodings, any given multibyte character sequence may represent different characters depending on the previous byte sequences, known as "shift sequences". Such encodings are known as state-dependent: knowledge of the current shift state is required to interpret each character. An NTMBS is only valid if it begins and ends in the initial shift state: if a shift sequence was used, the corresponding unshift sequence has to be present before the terminating null character. Examples of such encodings are BOCU-1 and [SCSU](https://www.unicode.org/reports/tr6).

A multibyte character string is layout-compatible with [null-terminated byte string](https://en.cppreference.com/c/string/byte "c/string/byte") (NTBS), that is, can be stored, copied, and examined using the same facilities, except for calculating the number of characters. If the correct locale is in effect, I/O functions also handle multibyte strings. Multibyte strings can be converted to and from wide strings using the following locale-dependent conversion functions:

### Functions

<table><tbody><tr><td colspan="2"><h5>Multibyte/wide character conversions</h5></td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/mblen">mblen</a></p></td><td>returns the number of bytes in the next multibyte character<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/mbtowc">mbtowc</a></p></td><td>converts the next multibyte character to wide character<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/wctomb">wctombwctomb_s</a></p><p>(C11)</p></td><td>converts a wide character to its multibyte representation<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/mbstowcs">mbstowcsmbstowcs_s</a></p><p>(C11)</p></td><td>converts a narrow multibyte character string to wide string<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/wcstombs">wcstombswcstombs_s</a></p><p>(C11)</p></td><td>converts a wide string to narrow multibyte character string<br>(function)</td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/mbsinit">mbsinit</a></p><p>(C95)</p></td><td>checks if the mbstate_t object represents initial shift state<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/btowc">btowc</a></p><p>(C95)</p></td><td>widens a single-byte narrow character to wide character, if possible<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/wctob">wctob</a></p><p>(C95)</p></td><td>narrows a wide character to a single-byte narrow character, if possible<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/mbrlen">mbrlen</a></p><p>(C95)</p></td><td>returns the number of bytes in the next multibyte character, given state<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/mbrtowc">mbrtowc</a></p><p>(C95)</p></td><td>converts the next multibyte character to wide character, given state<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/wcrtomb">wcrtombwcrtomb_s</a></p><p>(C95)(C11)</p></td><td>converts a wide character to its multibyte representation, given state<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/mbsrtowcs">mbsrtowcsmbsrtowcs_s</a></p><p>(C95)(C11)</p></td><td>converts a narrow multibyte character string to wide string, given state<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/wcsrtombs">wcsrtombswcsrtombs_s</a></p><p>(C95)(C11)</p></td><td>converts a wide string to narrow multibyte character string, given state<br>(function)</td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/mbrtoc8">mbrtoc8</a></p><p>(C23)</p></td><td>converts a narrow multibyte character to UTF-8 encoding<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/c8rtomb">c8rtomb</a></p><p>(C23)</p></td><td>converts UTF-8 string to narrow multibyte encoding<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/mbrtoc16">mbrtoc16</a></p><p>(C11)</p></td><td>converts a narrow multibyte character to UTF-16 encoding<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/c16rtomb">c16rtomb</a></p><p>(C11)</p></td><td>converts a UTF-16 character to narrow multibyte encoding<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/mbrtoc32">mbrtoc32</a></p><p>(C11)</p></td><td>converts a narrow multibyte character to UTF-32 encoding<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/c32rtomb">c32rtomb</a></p><p>(C11)</p></td><td>converts a UTF-32 character to narrow multibyte encoding<br>(function)</td></tr></tbody></table>

### Types

<table><tbody><tr><td colspan="2"></td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/mbstate_t">mbstate_t</a></p><p>(C95)</p></td><td>conversion state information necessary to iterate multibyte character strings<br>(class)</td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/char8_t">char8_t</a></p><p>(C23)</p></td><td>8-bit character type<br>(typedef)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/char16_t">char16_t</a></p><p>(C11)</p></td><td>16-bit character type<br>(typedef)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/string/multibyte/char32_t">char32_t</a></p><p>(C11)</p></td><td>32-bit character type<br>(typedef)</td></tr></tbody></table>

### Macros

<table><tbody><tr><td colspan="2"></td></tr><tr><td><p>MB_LEN_MAX</p></td><td>maximum number of bytes in a multibyte character, for any supported locale<br>(macro constant)</td></tr><tr><td colspan="2"></td></tr><tr><td><p>MB_CUR_MAX</p></td><td>maximum number of bytes in a multibyte character, in the current locale<br>(macro variable)</td></tr></tbody></table>

### References

- C23 standard (ISO/IEC 9899:2024):

- 7.10 Sizes of integer types <limits.h> (p: TBD)

- 7.22 General utilities <stdlib.h> (p: TBD)

- 7.28 Unicode utilities <uchar.h> (p: TBD)

- 7.29 Extended multibyte and wide character utilities <wchar.h> (p: TBD)

- 7.31.12 General utilities <stdlib.h> (p: TBD)

- 7.31.16 Extended multibyte and wide character utilities <wchar.h> (p: TBD)

- K.3.6 General utilities <stdlib.h> (p: TBD)

- K.3.9 Extended multibyte and wide character utilities <wchar.h> (p: TBD)

- C17 standard (ISO/IEC 9899:2018):

- 7.10 Sizes of integer types <limits.h> (p: TBD)

- 7.22 General utilities <stdlib.h> (p: TBD)

- 7.28 Unicode utilities <uchar.h> (p: TBD)

- 7.29 Extended multibyte and wide character utilities <wchar.h> (p: TBD)

- 7.31.12 General utilities <stdlib.h> (p: TBD)

- 7.31.16 Extended multibyte and wide character utilities <wchar.h> (p: TBD)

- K.3.6 General utilities <stdlib.h> (p: TBD)

- K.3.9 Extended multibyte and wide character utilities <wchar.h> (p: TBD)

- C11 standard (ISO/IEC 9899:2011):

- 7.10 Sizes of integer types <limits.h> (p: 222)

- 7.22 General utilities <stdlib.h> (p: 340-360)

- 7.28 Unicode utilities <uchar.h> (p: 398-401)

- 7.29 Extended multibyte and wide character utilities <wchar.h> (p: 402-446)

- 7.31.12 General utilities <stdlib.h> (p: 456)

- 7.31.16 Extended multibyte and wide character utilities <wchar.h> (p: 456)

- K.3.6 General utilities <stdlib.h> (p: 604-614)

- K.3.9 Extended multibyte and wide character utilities <wchar.h> (p: 627-651)

- C99 standard (ISO/IEC 9899:1999):

- 7.10 Sizes of integer types <limits.h> (p: 203)

- 7.20 General utilities <stdlib.h> (p: 306-324)

- 7.24 Extended multibyte and wide character utilities <wchar.h> (p: 348-392)

- 7.26.12 Extended multibyte and wide character utilities <wchar.h> (p: 402)

- C89/C90 standard (ISO/IEC 9899:1990):

- 4.1.4 Limits <float.h> and <limits.h>

### See also

[C++ documentation](https://en.cppreference.com/cpp/string/multibyte "cpp/string/multibyte") for Null-terminated multibyte strings