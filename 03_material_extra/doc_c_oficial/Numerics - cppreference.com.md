---
title: "Numerics - cppreference.com"
source: "https://en.cppreference.com/c/numeric"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
## Numerics

The C numerics library includes common mathematical functions and types, as well as support for random number generation.

### Common mathematical functions

The header [<math.h>](https://en.cppreference.com/c/header/math "c/header/math") provides [standard C library mathematical functions](https://en.cppreference.com/c/numeric/math "c/numeric/math") such as fabs, sqrt, and sin.

### Floating-point environment

The header [<fenv.h>](https://en.cppreference.com/c/header/fenv "c/header/fenv") defines [flags and functions related to exceptional floating-point state](https://en.cppreference.com/c/numeric/fenv "c/numeric/fenv"), such as overflow and division by zero.

### Pseudo-random number generation

The header [<stdlib.h>](https://en.cppreference.com/c/header/stdlib "c/header/stdlib") also includes C-style random number generation via srand and rand.

### Complex number arithmetic

The header [<complex.h>](https://en.cppreference.com/c/header/complex "c/header/complex") provides types and functions to work with [complex numbers](https://en.cppreference.com/c/numeric/complex "c/numeric/complex").

### Type-generic math

The header [<tgmath.h>](https://en.cppreference.com/c/header/tgmath "c/header/tgmath") provides some macros for a function which names XXX:

- real function:

- ```
	float
	```
	variant `XXXf`
- ```
	double
	```
	variant `XXX`
- ```
	long double
	```
	variant `XXXl`

- complex function:

- ```
	float
	```
	variant `cXXXf`
- ```
	double
	```
	variant `cXXX`
- ```
	long double
	```
	variant `cXXXl`

### Bit manipulation (since C23)

The header [<stdbit.h>](https://en.cppreference.com/c/header/stdbit "c/header/stdbit") provides macros and functions to work with the [byte ordering](https://en.cppreference.com/c/numeric/bit_manip#Macros "c/numeric/bit manip") and [byte and bit representation](https://en.cppreference.com/c/numeric/bit_manip#Functions "c/numeric/bit manip") of C objects.

### Checked integer arithmetic (since C23)

Provides some [type-generic macros](https://en.cppreference.com/c/language/generic "c/language/generic") for checked integer arithmetic:

<table><tbody><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/ckd_add">ckd_add</a></p><p>(C23)</p></td><td>checked addition operation on two integers<br>(type-generic function macro)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/ckd_sub">ckd_sub</a></p><p>(C23)</p></td><td>checked subtraction operation on two integers<br>(type-generic function macro)</td></tr><tr><td><p>(C23)</p></td><td>checked multiplication operation on two integers<br>(type-generic function macro)</td></tr></tbody></table>

### See also

[C++ documentation](https://en.cppreference.com/cpp/numeric "cpp/numeric") for Numerics library