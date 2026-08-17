---
title: "Type-generic math (since C99)"
source: "https://en.cppreference.com/c/numeric/tgmath"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
The header [<tgmath.h>](https://en.cppreference.com/c/header/tgmath "c/header/tgmath") includes the headers [<math.h>](https://en.cppreference.com/c/header/math "c/header/math") and [<complex.h>](https://en.cppreference.com/c/header/complex "c/header/complex") and defines several [type-generic macros](https://en.cppreference.com/c/language/generic "c/language/generic") that determine which real or, when applicable, complex function to call based on the types of the arguments.

For each macro, the parameters whose corresponding real type in the unsuffixed [<math.h>](https://en.cppreference.com/c/header/math "c/header/math") function is

```
double
```
are known as *generic parameters* (for example, both parameters of are generic parameters, but only the first parameter of is a generic parameter).

When a [<tgmath.h>](https://en.cppreference.com/c/header/tgmath "c/header/tgmath") 's macro is used the types of the arguments passed to the generic parameters determine which function is selected by the macro as described below. If the types of the arguments are not [compatible](https://en.cppreference.com/c/language/type#Compatible_types "c/language/type") with the parameter types of the selected function, the behavior is undefined (e.g. if a complex argument is passed into a real-only [<tgmath.h>](https://en.cppreference.com/c/header/tgmath "c/header/tgmath") 's macro: `float complex fc; ceil(fc);` or `double complex dc; double d; fmax(dc, d);` are examples of undefined behavior).

Note: type-generic macros were implemented in implementation-defined manner in C99, but C11 keyword [\_Generic](https://en.cppreference.com/c/keyword/_Generic "c/keyword/ Generic") makes it possible to implement these macros in portable manner.

### Complex/real type-generic macros

For all functions that have both real and complex counterparts, a type-generic macro `XXX` exists, which calls either of:

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

An exception to the above rule is the `fabs` macro (see the table below).

The function to call is determined as follows:

- If any of the arguments for the generic parameters is imaginary, the behavior is specified on each function reference page individually (in particular, `sin`, `cos`, `tag`, `cosh`, `sinh`, `tanh`, `asin`, `atan`, `asinh`, and `atanh` call *real* functions, the return types of `sin`, `tan`, `sinh`, `tanh`, `asin`, `atan`, `asinh`, and `atanh` are imaginary, and the return types of `cos` and `cosh` are real).
- If any of the arguments for the generic parameters is complex, then the complex function is called, otherwise the real function is called.
- If any of the arguments for the generic parameters is
	```
	long double
	```
	, then the
	```
	long double
	```
	variant is called. Otherwise, if any of the parameters is
	```
	double
	```
	or integer, then the
	```
	double
	```
	variant is called. Otherwise,
	```
	float
	```
	variant is called.

The type-generic macros are as follows:

<table><tbody><tr><th>Type-generic<br>macro</th><th colspan="3">Real function<br>variants</th><th colspan="3">Complex function<br>variants</th></tr><tr><th></th><th><pre><code>float</code></pre></th><th><pre><code>double</code></pre></th><th><pre><code>long double</code></pre></th><th><pre><code>float</code></pre></th><th><pre><code>double</code></pre></th><th><pre><code>long double</code></pre></th></tr><tr><th>fabs</th><td><a href="https://en.cppreference.com/c/numeric/math/fabs"><tt>fabsf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/fabs"><tt>fabs</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/fabs"><tt>fabsl</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/cabs"><tt>cabsf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/cabs"><tt>cabs</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/cabs"><tt>cabsl</tt></a></td></tr><tr><th>exp</th><td><a href="https://en.cppreference.com/c/numeric/math/exp"><tt>expf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/exp"><tt>exp</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/exp"><tt>expl</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/cexp"><tt>cexpf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/cexp"><tt>cexp</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/cexp"><tt>cexpl</tt></a></td></tr><tr><th>log</th><td><a href="https://en.cppreference.com/c/numeric/math/log"><tt>logf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/log"><tt>log</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/log"><tt>logl</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/clog"><tt>clogf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/clog"><tt>clog</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/clog"><tt>clogl</tt></a></td></tr><tr><th>pow</th><td><a href="https://en.cppreference.com/c/numeric/math/pow"><tt>powf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/pow"><tt>pow</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/pow"><tt>powl</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/cpow"><tt>cpowf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/cpow"><tt>cpow</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/cpow"><tt>cpowl</tt></a></td></tr><tr><th>sqrt</th><td><a href="https://en.cppreference.com/c/numeric/math/sqrt"><tt>sqrtf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/sqrt"><tt>sqrt</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/sqrt"><tt>sqrtl</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/csqrt"><tt>csqrtf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/csqrt"><tt>csqrt</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/csqrt"><tt>csqrtl</tt></a></td></tr><tr><th>sin</th><td><a href="https://en.cppreference.com/c/numeric/math/sin"><tt>sinf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/sin"><tt>sin</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/sin"><tt>sinl</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/csin"><tt>csinf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/csin"><tt>csin</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/csin"><tt>csinl</tt></a></td></tr><tr><th>cos</th><td><a href="https://en.cppreference.com/c/numeric/math/cos"><tt>cosf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/cos"><tt>cos</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/cos"><tt>cosl</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/ccos"><tt>ccosf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/ccos"><tt>ccos</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/ccos"><tt>ccosl</tt></a></td></tr><tr><th>tan</th><td><a href="https://en.cppreference.com/c/numeric/math/tan"><tt>tanf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/tan"><tt>tan</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/tan"><tt>tanl</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/ctan"><tt>ctanf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/ctan"><tt>ctan</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/ctan"><tt>ctanl</tt></a></td></tr><tr><th>asin</th><td><a href="https://en.cppreference.com/c/numeric/math/asin"><tt>asinf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/asin"><tt>asin</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/asin"><tt>asinl</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/casin"><tt>casinf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/casin"><tt>casin</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/casin"><tt>casinl</tt></a></td></tr><tr><th>acos</th><td><a href="https://en.cppreference.com/c/numeric/math/acos"><tt>acosf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/acos"><tt>acos</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/acos"><tt>acosl</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/cacos"><tt>cacosf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/cacos"><tt>cacos</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/cacos"><tt>cacosl</tt></a></td></tr><tr><th>atan</th><td><a href="https://en.cppreference.com/c/numeric/math/atan"><tt>atanf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/atan"><tt>atan</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/atan"><tt>atanl</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/catan"><tt>catanf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/catan"><tt>catan</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/catan"><tt>catanl</tt></a></td></tr><tr><th>sinh</th><td><a href="https://en.cppreference.com/c/numeric/math/sinh"><tt>sinhf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/sinh"><tt>sinh</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/sinh"><tt>sinhl</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/csinh"><tt>csinhf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/csinh"><tt>csinh</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/csinh"><tt>csinhl</tt></a></td></tr><tr><th>cosh</th><td><a href="https://en.cppreference.com/c/numeric/math/cosh"><tt>coshf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/cosh"><tt>cosh</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/cosh"><tt>coshl</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/ccosh"><tt>ccoshf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/ccosh"><tt>ccosh</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/ccosh"><tt>ccoshl</tt></a></td></tr><tr><th>tanh</th><td><a href="https://en.cppreference.com/c/numeric/math/tanh"><tt>tanhf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/tanh"><tt>tanh</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/tanh"><tt>tanhl</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/ctanh"><tt>ctanhf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/ctanh"><tt>ctanh</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/ctanh"><tt>ctanhl</tt></a></td></tr><tr><th>asinh</th><td><a href="https://en.cppreference.com/c/numeric/math/asinh"><tt>asinhf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/asinh"><tt>asinh</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/asinh"><tt>asinhl</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/casinh"><tt>casinhf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/casinh"><tt>casinh</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/casinh"><tt>casinhl</tt></a></td></tr><tr><th>acosh</th><td><a href="https://en.cppreference.com/c/numeric/math/acosh"><tt>acoshf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/acosh"><tt>acosh</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/acosh"><tt>acoshl</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/cacosh"><tt>cacoshf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/cacosh"><tt>cacosh</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/cacosh"><tt>cacoshl</tt></a></td></tr><tr><th>atanh</th><td><a href="https://en.cppreference.com/c/numeric/math/atanh"><tt>atanhf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/atanh"><tt>atanh</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/atanh"><tt>atanhl</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/catanh"><tt>catanhf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/catanh"><tt>catanh</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/catanh"><tt>catanhl</tt></a></td></tr></tbody></table>

### Real-only functions

For all functions that do not have complex counterparts, with the exception of `modf`, a type-generic macro `XXX` exists, which calls either of the variants of a real function:

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

The function to call is determined as follows:

- If any of the arguments for the generic parameters is
	```
	long double
	```
	, then the
	```
	long double
	```
	variant is called. Otherwise, if any of the arguments for the generic parameters is
	```
	double
	```
	, then the
	```
	double
	```
	variant is called. Otherwise,
	```
	float
	```
	variant is called.

<table><tbody><tr><th>Type-generic<br>macro</th><th colspan="3">Real function<br>variants</th></tr><tr><th></th><th><pre><code>float</code></pre></th><th><pre><code>double</code></pre></th><th><pre><code>long double</code></pre></th></tr><tr><th>atan2</th><td><a href="https://en.cppreference.com/c/numeric/math/atan2"><tt>atan2f</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/atan2"><tt>atan2</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/atan2"><tt>atan2l</tt></a></td></tr><tr><th>cbrt</th><td><a href="https://en.cppreference.com/c/numeric/math/cbrt"><tt>cbrtf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/cbrt"><tt>cbrt</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/cbrt"><tt>cbrtl</tt></a></td></tr><tr><th>ceil</th><td><a href="https://en.cppreference.com/c/numeric/math/ceil"><tt>ceilf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/ceil"><tt>ceil</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/ceil"><tt>ceill</tt></a></td></tr><tr><th>copysign</th><td><a href="https://en.cppreference.com/c/numeric/math/copysign"><tt>copysignf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/copysign"><tt>copysign</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/copysign"><tt>copysignl</tt></a></td></tr><tr><th>erf</th><td><a href="https://en.cppreference.com/c/numeric/math/erf"><tt>erff</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/erf"><tt>erf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/erf"><tt>erfl</tt></a></td></tr><tr><th>erfc</th><td><a href="https://en.cppreference.com/c/numeric/math/erfc"><tt>erfcf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/erfc"><tt>erfc</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/erfc"><tt>erfcl</tt></a></td></tr><tr><th>exp2</th><td><a href="https://en.cppreference.com/c/numeric/math/exp2"><tt>exp2f</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/exp2"><tt>exp2</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/exp2"><tt>exp2l</tt></a></td></tr><tr><th>expm1</th><td><a href="https://en.cppreference.com/c/numeric/math/expm1"><tt>expm1f</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/expm1"><tt>expm1</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/expm1"><tt>expm1l</tt></a></td></tr><tr><th>fdim</th><td><a href="https://en.cppreference.com/c/numeric/math/fdim"><tt>fdimf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/fdim"><tt>fdim</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/fdim"><tt>fdiml</tt></a></td></tr><tr><th>floor</th><td><a href="https://en.cppreference.com/c/numeric/math/floor"><tt>floorf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/floor"><tt>floor</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/floor"><tt>floorl</tt></a></td></tr><tr><th>fma</th><td><a href="https://en.cppreference.com/c/numeric/math/fma"><tt>fmaf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/fma"><tt>fma</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/fma"><tt>fmal</tt></a></td></tr><tr><th>fmax</th><td><a href="https://en.cppreference.com/c/numeric/math/fmax"><tt>fmaxf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/fmax"><tt>fmax</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/fmax"><tt>fmaxl</tt></a></td></tr><tr><th>fmin</th><td><a href="https://en.cppreference.com/c/numeric/math/fmin"><tt>fminf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/fmin"><tt>fmin</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/fmin"><tt>fminl</tt></a></td></tr><tr><th>fmod</th><td><a href="https://en.cppreference.com/c/numeric/math/fmod"><tt>fmodf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/fmod"><tt>fmod</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/fmod"><tt>fmodl</tt></a></td></tr><tr><th>frexp</th><td><a href="https://en.cppreference.com/c/numeric/math/frexp"><tt>frexpf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/frexp"><tt>frexp</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/frexp"><tt>frexpl</tt></a></td></tr><tr><th>hypot</th><td><a href="https://en.cppreference.com/c/numeric/math/hypot"><tt>hypotf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/hypot"><tt>hypot</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/hypot"><tt>hypotl</tt></a></td></tr><tr><th>ilogb</th><td><a href="https://en.cppreference.com/c/numeric/math/ilogb"><tt>ilogbf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/ilogb"><tt>ilogb</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/ilogb"><tt>ilogbl</tt></a></td></tr><tr><th>ldexp</th><td><a href="https://en.cppreference.com/c/numeric/math/ldexp"><tt>ldexpf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/ldexp"><tt>ldexp</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/ldexp"><tt>ldexpl</tt></a></td></tr><tr><th>lgamma</th><td><a href="https://en.cppreference.com/c/numeric/math/lgamma"><tt>lgammaf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/lgamma"><tt>lgamma</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/lgamma"><tt>lgammal</tt></a></td></tr><tr><th>llrint</th><td><a href="https://en.cppreference.com/c/numeric/math/rint"><tt>llrintf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/rint"><tt>llrint</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/rint"><tt>llrintl</tt></a></td></tr><tr><th>llround</th><td><a href="https://en.cppreference.com/c/numeric/math/round"><tt>llroundf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/round"><tt>llround</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/round"><tt>llroundl</tt></a></td></tr><tr><th>log10</th><td><a href="https://en.cppreference.com/c/numeric/math/log10"><tt>log10f</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/log10"><tt>log10</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/log10"><tt>log10l</tt></a></td></tr><tr><th>log1p</th><td><a href="https://en.cppreference.com/c/numeric/math/log1p"><tt>log1pf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/log1p"><tt>log1p</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/log1p"><tt>log1pl</tt></a></td></tr><tr><th>log2</th><td><a href="https://en.cppreference.com/c/numeric/math/log2"><tt>log2f</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/log2"><tt>log2</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/log2"><tt>log2l</tt></a></td></tr><tr><th>logb</th><td><a href="https://en.cppreference.com/c/numeric/math/logb"><tt>logbf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/logb"><tt>logb</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/logb"><tt>logbl</tt></a></td></tr><tr><th>lrint</th><td><a href="https://en.cppreference.com/c/numeric/math/rint"><tt>lrintf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/rint"><tt>lrint</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/rint"><tt>lrintl</tt></a></td></tr><tr><th>lround</th><td><a href="https://en.cppreference.com/c/numeric/math/round"><tt>lroundf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/round"><tt>lround</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/round"><tt>lroundl</tt></a></td></tr><tr><th>nearbyint</th><td><a href="https://en.cppreference.com/c/numeric/math/nearbyint"><tt>nearbyintf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/nearbyint"><tt>nearbyint</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/nearbyint"><tt>nearbyintl</tt></a></td></tr><tr><th>nextafter</th><td><a href="https://en.cppreference.com/c/numeric/math/nextafter"><tt>nextafterf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/nextafter"><tt>nextafter</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/nextafter"><tt>nextafterl</tt></a></td></tr><tr><th>nexttoward</th><td><a href="https://en.cppreference.com/c/numeric/math/nextafter"><tt>nexttowardf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/nextafter"><tt>nexttoward</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/nextafter"><tt>nexttowardl</tt></a></td></tr><tr><th>remainder</th><td><a href="https://en.cppreference.com/c/numeric/math/remainder"><tt>remainderf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/remainder"><tt>remainder</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/remainder"><tt>remainderl</tt></a></td></tr><tr><th>remquo</th><td><a href="https://en.cppreference.com/c/numeric/math/remquo"><tt>remquof</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/remquo"><tt>remquo</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/remquo"><tt>remquol</tt></a></td></tr><tr><th>rint</th><td><a href="https://en.cppreference.com/c/numeric/math/rint"><tt>rintf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/rint"><tt>rint</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/rint"><tt>rintl</tt></a></td></tr><tr><th>round</th><td><a href="https://en.cppreference.com/c/numeric/math/round"><tt>roundf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/round"><tt>round</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/round"><tt>roundl</tt></a></td></tr><tr><th>scalbln</th><td><a href="https://en.cppreference.com/c/numeric/math/scalbn"><tt>scalblnf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/scalbn"><tt>scalbln</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/scalbn"><tt>scalblnl</tt></a></td></tr><tr><th>scalbn</th><td><a href="https://en.cppreference.com/c/numeric/math/scalbn"><tt>scalbnf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/scalbn"><tt>scalbn</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/scalbn"><tt>scalbnl</tt></a></td></tr><tr><th>tgamma</th><td><a href="https://en.cppreference.com/c/numeric/math/tgamma"><tt>tgammaf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/tgamma"><tt>tgamma</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/tgamma"><tt>tgammal</tt></a></td></tr><tr><th>trunc</th><td><a href="https://en.cppreference.com/c/numeric/math/trunc"><tt>truncf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/trunc"><tt>trunc</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/math/trunc"><tt>truncl</tt></a></td></tr></tbody></table>

### Complex-only functions

For all complex number functions that do not have real counterparts, a type-generic macro `cXXX` exists, which calls either of the variants of a complex function:

- ```
	float complex
	```
	variant `cXXXf`
- ```
	double complex
	```
	variant `cXXX`
- ```
	long double complex
	```
	variant `cXXXl`

The function to call is determined as follows:

- If any of the arguments for the generic parameters is real, complex, or imaginary, then the appropriate complex function is called.

<table><tbody><tr><th>Type-generic<br>macro</th><th colspan="3">Complex function<br>variants</th></tr><tr><th></th><th><pre><code>float</code></pre></th><th><pre><code>double</code></pre></th><th><pre><code>long double</code></pre></th></tr><tr><th>carg</th><td><a href="https://en.cppreference.com/c/numeric/complex/carg"><tt>cargf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/carg"><tt>carg</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/carg"><tt>cargl</tt></a></td></tr><tr><th>conj</th><td><a href="https://en.cppreference.com/c/numeric/complex/conj"><tt>conjf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/conj"><tt>conj</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/conj"><tt>conjl</tt></a></td></tr><tr><th>creal</th><td><a href="https://en.cppreference.com/c/numeric/complex/creal"><tt>crealf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/creal"><tt>creal</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/creal"><tt>creall</tt></a></td></tr><tr><th>cimag</th><td><a href="https://en.cppreference.com/c/numeric/complex/cimag"><tt>cimagf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/cimag"><tt>cimag</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/cimag"><tt>cimagl</tt></a></td></tr><tr><th>cproj</th><td><a href="https://en.cppreference.com/c/numeric/complex/cproj"><tt>cprojf</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/cproj"><tt>cproj</tt></a></td><td><a href="https://en.cppreference.com/c/numeric/complex/cproj"><tt>cprojl</tt></a></td></tr></tbody></table>

### Example

```
#include <stdio.h>
#include <tgmath.h>

int main(void)
{
    int i = 2;
    printf("sqrt(2) = %f\n", sqrt(i)); // argument type is int, calls sqrt

    float f = 0.5;
    printf("sin(0.5f) = %f\n", sin(f)); // argument type is float, calls sinf

    float complex dc = 1 + 0.5*I;
    float complex z = sqrt(dc); // argument type is float complex, calls csqrtf
    printf("sqrt(1 + 0.5i) = %f+%fi\n",
           creal(z),  // argument type is float complex, calls crealf
           cimag(z)); // argument type is float complex, calls cimagf
}
```

Output:

```
sqrt(2) = 1.414214
sin(0.5f) = 0.479426
sqrt(1 + 0.5i) = 1.029086+0.242934i
```

### References

- C23 standard (ISO/IEC 9899:2024):

- 7.25 Type-generic math <tgmath.h> (p: TBD)

- C17 standard (ISO/IEC 9899:2018):

- 7.25 Type-generic math <tgmath.h> (p: 272-273)

- C11 standard (ISO/IEC 9899:2011):

- 7.25 Type-generic math <tgmath.h> (p: 373-375)

- C99 standard (ISO/IEC 9899:1999):

- 7.22 Type-generic math <tgmath.h> (p: 335-337)