---
title: "Complex number arithmetic"
source: "https://en.cppreference.com/c/numeric/complex"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
| If the macro constant `__STDC_NO_COMPLEX__` is defined by the implementation, the complex types, the header [<complex.h>](https://en.cppreference.com/c/header/complex "c/header/complex") and all of the names listed here are not provided. | (since C11) |
| --- | --- |

The C programming language, as of C99, supports complex number math with the three built-in types

```
double _Complex
```
,
```
float _Complex
```
, and
```
long double _Complex
```
(see [\_Complex](https://en.cppreference.com/c/keyword/_Complex "c/keyword/ Complex")). When the header [<complex.h>](https://en.cppreference.com/c/header/complex "c/header/complex") is included, the three complex number types are also accessible as
```
double complex
```
,
```
float complex
```
,
```
long double complex
```
.

In addition to the complex types, the three imaginary types may be supported:

```
double _Imaginary
```
,
```
float _Imaginary
```
, and
```
long double _Imaginary
```
(see [\_Imaginary](https://en.cppreference.com/c/keyword/_Imaginary "c/keyword/ Imaginary")). When the header [<complex.h>](https://en.cppreference.com/c/header/complex "c/header/complex") is included, the three imaginary types are also accessible as
```
double imaginary
```
,
```
float imaginary
```
, and
```
long double imaginary
```
.

Standard arithmetic operators `+`, `-`, `*`, `/` can be used with real, complex, and imaginary types in any combination.

| A compiler that defines `__STDC_IEC_559_COMPLEX__` is recommended, but not required to support imaginary numbers. POSIX recommends checking if the macro \_Imaginary\_I is defined to identify imaginary number support. | (since C99)   (until C11) |
| --- | --- |
| Imaginary numbers are supported if `__STDC_IEC_559_COMPLEX__` or `__STDC_IEC_60559_COMPLEX__` (since C23) is defined. | (since C11) |

<table><tbody><tr><td colspan="2"></td></tr><tr><td colspan="2"></td></tr><tr><td colspan="2"><h5>Types</h5></td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/imaginary">imaginary</a></p><p>(C99)</p></td><td>imaginary type macro<br>(keyword macro)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/complex">complex</a></p><p>(C99)</p></td><td>complex type macro<br>(keyword macro)</td></tr><tr><td colspan="2"><h5>The imaginary constant</h5></td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/Imaginary_I">_Imaginary_I</a></p><p>(C99)</p></td><td>the imaginary unit constant i<br>(macro constant)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/Complex_I">_Complex_I</a></p><p>(C99)</p></td><td>the complex unit constant i<br>(macro constant)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/I">I</a></p><p>(C99)</p></td><td>the complex or imaginary unit constant i<br>(macro constant)</td></tr><tr><td colspan="2"><h5>Manipulation</h5></td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/CMPLX">CMPLXCMPLXFCMPLXL</a></p><p>(C11)(C11)(C11)</p></td><td>constructs a complex number from real and imaginary parts<br>(function macro)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/creal">crealcrealfcreall</a></p><p>(C99)(C99)(C99)</p></td><td>computes the real part of a complex number<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/cimag">cimagcimagfcimagl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the imaginary part a complex number<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/cabs">cabscabsfcabsl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the magnitude of a complex number<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/carg">cargcargfcargl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the phase angle of a complex number<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/conj">conjconjfconjl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the complex conjugate<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/cproj">cprojcprojfcprojl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the projection on Riemann sphere<br>(function)</td></tr><tr><td colspan="2"><h5>Exponential functions</h5></td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/cexp">cexpcexpfcexpl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the complex base-e exponential<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/clog">clogclogfclogl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the complex natural logarithm<br>(function)</td></tr><tr><td colspan="2"><h5>Power functions</h5></td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/cpow">cpowcpowfcpowl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the complex power function<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/csqrt">csqrtcsqrtfcsqrtl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the complex square root<br>(function)</td></tr><tr><td colspan="2"><h5>Trigonometric functions</h5></td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/csin">csincsinfcsinl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the complex sine<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/ccos">ccosccosfccosl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the complex cosine<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/ctan">ctanctanfctanl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the complex tangent<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/casin">casincasinfcasinl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the complex arc sine<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/cacos">cacoscacosfcacosl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the complex arc cosine<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/catan">catancatanfcatanl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the complex arc tangent<br>(function)</td></tr><tr><td colspan="2"><h5>Hyperbolic functions</h5></td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/csinh">csinhcsinhfcsinhl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the complex hyperbolic sine<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/ccosh">ccoshccoshfccoshl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the complex hyperbolic cosine<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/ctanh">ctanhctanhfctanhl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the complex hyperbolic tangent<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/casinh">casinhcasinhfcasinhl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the complex arc hyperbolic sine<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/cacosh">cacoshcacoshfcacoshl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the complex arc hyperbolic cosine<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/complex/catanh">catanhcatanhfcatanhl</a></p><p>(C99)(C99)(C99)</p></td><td>computes the complex arc hyperbolic tangent<br>(function)</td></tr></tbody></table>

### Notes

The following function names are potentially(since C23) reserved for future addition to [<complex.h>](https://en.cppreference.com/c/header/complex "c/header/complex") and are not available for use in the programs that include that header: cerf, cerfc, cexp2, cexpm1, clog10, clog1p, clog2, clgamma, ctgamma, csinpi, ccospi, ctanpi, casinpi, cacospi, catanpi, ccompoundn, cpown, cpowr, crootn, crsqrt, cexp10m1, cexp10, cexp2m1, clog10p1, clog2p1, clogp1(since C23), along with their - `f` and - `l` suffixed variants.

Although the C standard names the inverse hyperbolic with "complex arc hyperbolic sine" etc., the inverse functions of the hyperbolic functions are the area functions. Their argument is the area of a hyperbolic sector, not an arc. The correct names are "complex inverse hyperbolic sine" etc. Some authors use "complex area hyperbolic sine" etc.

A complex or imaginary number is infinite if one of its parts is infinite, even if the other part is NaN.

A complex or imaginary number is finite if both parts are neither infinities nor NaNs.

A complex or imaginary number is a zero if both parts are positive or negative zeroes.

While MSVC does provide a [`<complex.h>`](https://learn.microsoft.com/en-us/cpp/c-runtime-library/complex-math-support) header, it does not implement complex numbers as native types, but as

```
struct
```
s, which are incompatible with standard C complex types and do not support the `+`, `-`, `*`, `/` operators.

### Example

```
#include <complex.h>
#include <stdio.h>
#include <tgmath.h>

int main(void)
{
    double complex z1 = I * I;     // imaginary unit squared
    printf("I * I = %.1f%+.1fi\n", creal(z1), cimag(z1));

    double complex z2 = pow(I, 2); // imaginary unit squared
    printf("pow(I, 2) = %.1f%+.1fi\n", creal(z2), cimag(z2));

    double PI = acos(-1);
    double complex z3 = exp(I * PI); // Euler's formula
    printf("exp(I*PI) = %.1f%+.1fi\n", creal(z3), cimag(z3));

    double complex z4 = 1 + 2 * I, z5 = 1 - 2 * I; // conjugates
    printf("(1+2i)*(1-2i) = %.1f%+.1fi\n", creal(z4 * z5), cimag(z4 * z5));
}
```

Output:

```
I * I = -1.0+0.0i
pow(I, 2) = -1.0+0.0i
exp(I*PI) = -1.0+0.0i
(1+2i)*(1-2i) = 5.0+0.0i
```

### References

Extended content

### See also

[C++ documentation](https://en.cppreference.com/cpp/numeric/complex "cpp/numeric/complex") for Complex number arithmetic