---
title: "Expressions - cppreference.com"
source: "https://en.cppreference.com/c/language/expressions"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
## Expressions

An expression is a sequence of *operators* and their *operands*, that specifies a computation.

Expression evaluation may produce a result (e.g., evaluation of `2 + 2` produces the result `4`), may generate side-effects (e.g. evaluation of `printf("%d", 4)` sends the character `'4'` to the standard output stream), and may designate objects or functions.

#### General

- [value categories](https://en.cppreference.com/c/language/value_category "c/language/value category") (lvalue, non-lvalue object, function designator) classify expressions by their values
- [order of evaluation](https://en.cppreference.com/c/language/eval_order "c/language/eval order") of arguments and subexpressions specifies the order in which intermediate results are obtained

### Operators

<table><tbody><tr><th colspan="7">Common operators</th></tr><tr><td><a href="https://en.cppreference.com/c/language/operator_assignment">assignment</a></td><td><a href="https://en.cppreference.com/c/language/operator_incdec">increment<br>decrement</a></td><td><a href="https://en.cppreference.com/c/language/operator_arithmetic">arithmetic</a></td><td><a href="https://en.cppreference.com/c/language/operator_logical">logical</a></td><td><a href="https://en.cppreference.com/c/language/operator_comparison">comparison</a></td><td><a href="https://en.cppreference.com/c/language/operator_member_access">member<br>access</a></td><td><a href="https://en.cppreference.com/c/language/operator_other">other</a></td></tr><tr><td><p><code>a = b a += b a -= b a *= b a /= b a %= b a &= b a |= b a ^= b a <<= b a >>= b</code></p></td><td><p><code>++a --a a++ a--</code></p></td><td><p><code>+a -a a + b a - b a * b a / b a % b ~a a & b a | b a ^ b a << b a >> b</code></p></td><td><p><code>!a a && b a || b</code></p></td><td><p><code>a == b a != b a < b a > b a <= b a >= b</code></p></td><td><p><code>a[b] *a &a a->b a.b</code></p></td><td><p><code>a(...) a, b (type) a a ? b : c sizeof</code><br><br></p><pre><code>_Alignof</code></pre><br>(since C11)<br>(until C23)<br><br><pre><code>alignof</code></pre><br>(since C23)<p></p></td></tr></tbody></table>

- [operator precedence](https://en.cppreference.com/c/language/operator_precedence "c/language/operator precedence") defines the order in which operators are bound to their arguments
- [alternative representations](https://en.cppreference.com/c/language/operator_alternative "c/language/operator alternative") are alternative spellings for some operators

#### Conversions

- [Implicit conversions](https://en.cppreference.com/c/language/conversion "c/language/conversion") take place when types of operands do not match the expectations of operators
- [Casts](https://en.cppreference.com/c/language/cast "c/language/cast") may be used to explicitly convert values from one type to another.

#### Other

- [constant expressions](https://en.cppreference.com/c/language/constant_expression "c/language/constant expression") can be evaluated at compile time and used in compile-time context (non-VLA(since C99)array sizes, static initializers, etc)

| - [generic selections](https://en.cppreference.com/c/language/generic "c/language/generic") can execute different expressions depending on the types of the arguments | (since C11) |
| --- | --- |

| - Floating-point arithmetic may raise exceptions and report errors as specified in [math\_errhandling](https://en.cppreference.com/c/numeric/math/math_errhandling "c/numeric/math/math errhandling") - The standard [#pragmas](https://en.cppreference.com/c/preprocessor/impl "c/preprocessor/impl") `FENV_ACCESS`, `FP_CONTRACT`, and `CX_LIMITED_RANGE` as well as the [floating-point evaluation precision](https://en.cppreference.com/c/types/limits/FLT_EVAL_METHOD "c/types/limits/FLT EVAL METHOD") and [rounding direction](https://en.cppreference.com/c/numeric/fenv/FE_round "c/numeric/fenv/FE round") control the way floating-point arithmetic are executed. | (since C99) |
| --- | --- |

### Primary expressions

The operands of any operator may be other expressions or they may be *primary expressions* (e.g. in `1 + 2 * 3`, the operands of operator+ are the subexpression `2 * 3` and the primary expression `1`).

Primary expressions are any of the following:

1) Constants and literals (e.g. `2` or `"Hello, world"`)

2) Suitably declared [identifiers](https://en.cppreference.com/c/language/identifier "c/language/identifier") (e.g. `n` or `printf`)

| 3) [Generic selections](https://en.cppreference.com/c/language/generic "c/language/generic") | (since C11) |
| --- | --- |

Any expression in parentheses is also classified as a primary expression: this guarantees that the parentheses have higher precedence than any operator.

#### Constants and literals

Constant values of certain types may be embedded in the source code of a C program using specialized expressions known as literals (for lvalue expressions) and constants (for non-lvalue expressions)

- [integer constants](https://en.cppreference.com/c/language/integer_constant "c/language/integer constant") are decimal, octal, or hexadecimal numbers of integer type.
- [character constants](https://en.cppreference.com/c/language/character_constant "c/language/character constant") are individual characters of type
	```
	int
	```
	suitable for conversion to a character type or of type
	```
	char8_t
	```
	,
	```
	char16_t
	```
	,
	```
	char32_t
	```
	, or
	```
	wchar_t
	```
- [floating constants](https://en.cppreference.com/c/language/floating_constant "c/language/floating constant") are values of type
	```
	float
	```
	,
	```
	double
	```
	, or
	```
	long double
	```

| - predefined constants [`true` / `false`](https://en.cppreference.com/c/language/bool_constant "c/language/bool constant") are values of type 	``` 	bool 	``` - predefined constant [`nullptr`](https://en.cppreference.com/c/language/nullptr "c/language/nullptr") is a value of type nullptr\_t | (since C23) |
| --- | --- |

- [string literals](https://en.cppreference.com/c/language/string_literal "c/language/string literal") are sequences of characters of type `char[]`, `char8_t[]` (since C23), `char16_t[]`, `char32_t[]`,(since C11) or `wchar_t[]` that represent null-terminated strings

| - [compound literals](https://en.cppreference.com/c/language/compound_literal "c/language/compound literal") are values of struct, union, or array type directly embedded in program code | (since C99) |
| --- | --- |

### Unevaluated expressions

The operands of the```
sizeof
```
[operator](https://en.cppreference.com/c/language/sizeof "c/language/sizeof") are expressions that are not evaluated. Thus, `size_t n = sizeof(printf("%d", 4));` does not perform console output.

| The operands of the [`_Alignof`](https://en.cppreference.com/c/language/_Alignof "c/language/ Alignof") (until C23) [`alignof`](https://en.cppreference.com/c/language/alignof "c/language/alignof") (since C23) operator, the controlling expression of a [generic selection](https://en.cppreference.com/c/language/generic "c/language/generic"), and size expressions of VLAs that are operands of `_Alignof` (until C23)  ``` alignof ``` are also expressions that are not evaluated. | (since C11) |
| --- | --- |

### References

- C23 standard (ISO/IEC 9899:2024):

- 6.5 Expressions (p: TBD)

- 6.6 Constant expressions (p: TBD)

- C17 standard (ISO/IEC 9899:2018):

- 6.5 Expressions (p: 55-75)

- C11 standard (ISO/IEC 9899:2011):

- 6.5 Expressions (p: 76-105)

- C99 standard (ISO/IEC 9899:1999):

- 6.5 Expressions (p: 67-94)

- C89/C90 standard (ISO/IEC 9899:1990):

- 3.3 EXPRESSIONS

### See also

[C++ documentation](https://en.cppreference.com/cpp/language/expressions "cpp/language/expressions") for Expressions