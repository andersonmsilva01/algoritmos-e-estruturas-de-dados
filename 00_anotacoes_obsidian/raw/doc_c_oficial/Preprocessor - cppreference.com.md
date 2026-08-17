---
title: "Preprocessor - cppreference.com"
source: "https://en.cppreference.com/c/preprocessor"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
## Preprocessor

The preprocessor is executed at [translation phase 4](https://en.cppreference.com/c/language/translation_phases#Phase_4 "c/language/translation phases"), before the compilation. The result of preprocessing is a single file which is then passed to the actual compiler.

### Directives

The preprocessing directives control the behavior of the preprocessor. Each directive occupies one line and has the following format:

- `#` character
- preprocessing instruction (one of `define`, `undef`, `include`, `if`, `ifdef`, `ifndef`, `else`, `elif`, `elifdef`, `elifndef` (since C23), `endif`, `line`, `embed` (since C23), `error`, `warning` (since C23), `pragma`) [^1]
- arguments (depends on the instruction)
- line break.

The null directive (`#` followed by a line break) is allowed and has no effect.

### Capabilities

The preprocessor has the source file translation capabilities:

- **[conditionally](https://en.cppreference.com/c/preprocessor/conditional "c/preprocessor/conditional")** compile of parts of source file (controlled by directive `#if`, `#ifdef`, `#ifndef`, `#else`, `#elif`, `#elifdef`, `#elifndef` (since C23) and `#endif`).
- **[replace](https://en.cppreference.com/c/preprocessor/replace "c/preprocessor/replace")** text macros while possibly concatenating or quoting identifiers (controlled by directives `#define` and `#undef`, and operators `#` and `##`)
- **[include](https://en.cppreference.com/c/preprocessor/include "c/preprocessor/include")** other files (controlled by directive `#include` and checked with `__has_include` (since C23))
- cause an **[error](https://en.cppreference.com/c/preprocessor/error "c/preprocessor/error")** or **[warning](https://en.cppreference.com/c/preprocessor/error "c/preprocessor/error")** (since C23) (controlled by directive `#error` or `#warning` respectively(since C23))

The following aspects of the preprocessor can be controlled:

- **[implementation defined](https://en.cppreference.com/c/preprocessor/impl "c/preprocessor/impl")** behavior (controlled by directive `#pragma` and operator `_Pragma` (since C99))
- **[file name and line information](https://en.cppreference.com/c/preprocessor/line "c/preprocessor/line")** available to the preprocessor (controlled by directives `#line`)

### Footnotes

### Example

### References

- C23 standard (ISO/IEC 9899:2024):

- 6.10 Preprocessing directives (p: TBD)

- C17 standard (ISO/IEC 9899:2018):

- 6.10 Preprocessing directives (p: 117-129)

- C11 standard (ISO/IEC 9899:2011):

- 6.10 Preprocessing directives (p: 160-178)

- C99 standard (ISO/IEC 9899:1999):

- 6.10 Preprocessing directives (p: 145-162)

- C89/C90 standard (ISO/IEC 9899:1990):

- 3.8 Preprocessing directives

### See also

[C documentation](https://en.cppreference.com/c/preprocessor/replace#Predefined_macros "c/preprocessor/replace") for Predefined Macro Symbols

[C documentation](https://en.cppreference.com/c/symbol_index/macro "c/symbol index/macro") for Macro Symbol Index

[C++ documentation](https://en.cppreference.com/cpp/preprocessor "cpp/preprocessor") for Preprocessor

[^1]: These are the directives defined by the standard. The standard does not define behavior for other directives: they might be ignored, have some useful meaning, or make the program ill-formed. Even if otherwise ignored, they are removed from the source code when the preprocessor is done. A common non-standard extension is the directive [#warning](https://en.cppreference.com/c/preprocessor/error "c/preprocessor/error") which emits a user-defined message during compilation.(until C23)