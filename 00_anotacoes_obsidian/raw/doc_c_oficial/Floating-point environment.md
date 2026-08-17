---
title: "Floating-point environment"
source: "https://en.cppreference.com/c/numeric/fenv"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
The floating-point environment is the set of floating-point status flags and control modes supported by the implementation. It is thread-local, each thread inherits the initial state of its floating-point environment from the parent thread. Floating-point operations modify the floating-point status flags to indicate abnormal results or auxiliary information. The state of floating-point control modes affects the outcomes of some floating-point operations.

The floating-point environment access and modification is only meaningful when [#pragma STDC FENV\_ACCESS](https://en.cppreference.com/cpp/preprocessor/impl "cpp/preprocessor/impl") is set to `ON`. Otherwise the implementation is free to assume that floating-point control modes are always the default ones and that floating-point status flags are never tested or modified. In practice, few current compilers, such as HP aCC, Oracle Studio, and IBM XL, support the

```
#pragma
```
explicitly, but most compilers allow meaningful access to the floating-point environment anyway.

### Types

<table><tbody><tr><td colspan="2"></td></tr><tr><td><pre><code>fenv_t</code></pre></td><td>The type representing the entire floating-point environment</td></tr><tr><td><pre><code>fexcept_t</code></pre></td><td>The type representing all floating-point status flags collectively</td></tr></tbody></table>

### Functions

| [feclearexcept](https://en.cppreference.com/c/numeric/fenv/feclearexcept "c/numeric/fenv/feclearexcept")  (C99) | clears the specified floating-point status flags   (function) |
| --- | --- |
| [fetestexcept](https://en.cppreference.com/c/numeric/fenv/fetestexcept "c/numeric/fenv/fetestexcept")  (C99) | determines which of the specified floating-point status flags are set   (function) |
| [feraiseexcept](https://en.cppreference.com/c/numeric/fenv/feraiseexcept "c/numeric/fenv/feraiseexcept")  (C99) | raises the specified floating-point exceptions   (function) |
| [fegetexceptflagfesetexceptflag](https://en.cppreference.com/c/numeric/fenv/feexceptflag "c/numeric/fenv/feexceptflag")  (C99)(C99) | copies the state of the specified floating-point status flags from or to the floating-point environment   (function) |
| [fegetroundfesetround](https://en.cppreference.com/c/numeric/fenv/feround "c/numeric/fenv/feround")  (C99)(C99) | gets or sets rounding direction   (function) |
| [fegetenvfesetenv](https://en.cppreference.com/c/numeric/fenv/feenv "c/numeric/fenv/feenv")  (C99) | saves or restores the current floating-point environment   (function) |
| [feholdexcept](https://en.cppreference.com/c/numeric/fenv/feholdexcept "c/numeric/fenv/feholdexcept")  (C99) | saves the environment, clears all status flags and ignores all future errors   (function) |
| [feupdateenv](https://en.cppreference.com/c/numeric/fenv/feupdateenv "c/numeric/fenv/feupdateenv")  (C99) | restores the floating-point environment and raises the previously raise exceptions   (function) |

### Macros

| [FE\_ALL\_EXCEPTFE\_DIVBYZEROFE\_INEXACTFE\_INVALIDFE\_OVERFLOWFE\_UNDERFLOW](https://en.cppreference.com/c/numeric/fenv/FE_exceptions "c/numeric/fenv/FE exceptions")  (C99) | floating-point exceptions   (macro constant) |
| --- | --- |
| [FE\_DOWNWARDFE\_TONEARESTFE\_TOWARDZEROFE\_UPWARD](https://en.cppreference.com/c/numeric/fenv/FE_round "c/numeric/fenv/FE round")  (C99) | floating-point rounding direction   (macro constant) |
| [FE\_DFL\_ENV](https://en.cppreference.com/c/numeric/fenv/FE_DFL_ENV "c/numeric/fenv/FE DFL ENV")  (C99) | default floating-point environment   (macro constant) |

### References

- C23 standard (ISO/IEC 9899:2024):

- 7.6 Floating-point environment <fenv.h> (p: TBD)

- 7.31.4 Floating-point environment <fenv.h> (p: TBD)

- C17 standard (ISO/IEC 9899:2018):

- 7.6 Floating-point environment <fenv.h> (p: 150-156)

- C11 standard (ISO/IEC 9899:2011):

- 7.6 Floating-point environment <fenv.h> (p: 206-215)

- C99 standard (ISO/IEC 9899:1999):

- 7.6 Floating-point environment <fenv.h> (p: 187-196)

### See also

[C++ documentation](https://en.cppreference.com/cpp/numeric/fenv "cpp/numeric/fenv") for Floating-point environment