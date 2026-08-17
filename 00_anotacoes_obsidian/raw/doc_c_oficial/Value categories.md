---
title: "Value categories"
source: "https://en.cppreference.com/c/language/value_category"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
Each [expression](https://en.cppreference.com/c/language/expressions "c/language/expressions") in C (an operator with its arguments, a function call, a constant, a variable name, etc) is characterized by two independent properties: a [type](https://en.cppreference.com/c/language/type#Type "c/language/type") and a [value category](https://en.cppreference.com/c/language/expressions#General "c/language/expressions").

Every expression belongs to one of three value categories: lvalue, non-lvalue object (rvalue), and function designator.

### Lvalue expressions

Lvalue expression is any expression with [object type](https://en.cppreference.com/c/language/type#Type_groups "c/language/type") other than the type

```
void
```
, which potentially designates an [object](https://en.cppreference.com/c/language/object "c/language/object") (the behavior is undefined if an lvalue does not actually designate an object when it is evaluated). In other words, lvalue expression evaluates to the *object identity* . The name of this value category (“left value”) is historic and reflects the use of lvalue expressions as the left-hand operand of the assignment operator in the CPL programming language.

Lvalue expressions can be used in the following *lvalue contexts* :

- as the operand of the [address-of operator](https://en.cppreference.com/c/language/operator_member_access "c/language/operator member access") (except if the lvalue designates a [bit-field](https://en.cppreference.com/c/language/bit_field "c/language/bit field") or was declared [register](https://en.cppreference.com/c/language/storage_duration "c/language/storage duration")).
- as the operand of the pre/post [increment and decrement operators](https://en.cppreference.com/c/language/operator_incdec "c/language/operator incdec").
- as the left-hand operand of the [member access](https://en.cppreference.com/c/language/operator_member_access "c/language/operator member access") (dot) operator.
- as the left-hand operand of the [assignment and compound assignment](https://en.cppreference.com/c/language/operator_assignment "c/language/operator assignment") operators.

If an lvalue expression is used in any context other than [`sizeof`](https://en.cppreference.com/c/language/sizeof "c/language/sizeof"), [`_Alignof`](https://en.cppreference.com/c/language/_Alignof "c/language/ Alignof"), or the operators listed above, non-array lvalues of any complete type undergo [lvalue conversion](https://en.cppreference.com/c/language/conversion "c/language/conversion"), which models the memory load of the value of the object from its location. Similarly, array lvalues undergo [array-to-pointer conversion](https://en.cppreference.com/c/language/conversion "c/language/conversion") when used in any context other than

```
sizeof
```
, `_Alignof`, address-of operator, or array initialization from a string literal.

The semantics of [`const`](https://en.cppreference.com/c/language/const "c/language/const") / [`volatile`](https://en.cppreference.com/c/language/volatile "c/language/volatile") / [`restrict`](https://en.cppreference.com/c/language/restrict "c/language/restrict") -qualifiers and [atomic](https://en.cppreference.com/c/language/atomic "c/language/atomic") types apply to lvalues only (lvalue conversion strips the qualifiers and removes atomicity).

The following expressions are lvalues:

- identifiers, including function named parameters, provided they were declared as designating objects (not functions or enumeration constants)
- [string literals](https://en.cppreference.com/c/language/string_literal "c/language/string literal")
- (C99) [compound literals](https://en.cppreference.com/c/language/compound_literal "c/language/compound literal")
- parenthesized expression if the unparenthesized expression is an lvalue
- the result of a member access (dot) operator if its left-hand argument is lvalue
- the result of a member access through pointer `**->**` operator
- the result of the indirection (unary `*****`) operator applied to a pointer to object
- the result of the subscription operator (`**[]**`)

#### Modifiable lvalue expressions

A *modifiable lvalue* is any lvalue expression of complete, non-array type which is not [const](https://en.cppreference.com/c/language/const "c/language/const") -qualified, and, if it's a struct/union, has no members that are [const](https://en.cppreference.com/c/language/const "c/language/const") -qualified, recursively.

Only modifiable lvalue expressions may be used as arguments to increment/decrement, and as left-hand arguments of assignment and compound assignment operators.

### Non-lvalue object expressions

Known as *rvalues* , non-lvalue object expressions are the expressions of object types that do not designate objects, but rather values that have no object identity or storage location. The address of a non-lvalue object expression cannot be taken.

The following expressions are non-lvalue object expressions:

- integer, character, and floating constants
- all operators not specified to return lvalues, including

- any function call expression
- any cast expression (note that compound literals, which look similar, are lvalues)
- member access operator (dot) applied to a non-lvalue structure/union, `f().x`, `(x, s1).a`, `(s1 = s2).m`
- results of all arithmetic, relational, logical, and bitwise operators
- results of increment and decrement operators (note: pre-forms are lvalues in C++)
- results of assignment operators (note: also lvalues in C++)
- the conditional operator (note: is lvalue in C++ if both the second and third operands are lvalues of the same type)
- the comma operator (note: is lvalue in C++ if the second operand is)
- the address-of operator, even if neutralized by application to the result of unary `*****` operator

As a special case, expressions of type

```
void
```
are assumed to be non-lvalue object expressions that yield a value which has no representation and requires no storage.

| Note that a struct/union rvalue that has a member (possibly nested) of array type does in fact designate an object with [temporary lifetime](https://en.cppreference.com/c/language/lifetime "c/language/lifetime"). This object can be accessed through lvalue expressions that form by indexing the array member or by indirection through the pointer obtained by array-to-pointer conversion of the array member. | (since C99) |
| --- | --- |

### Function designator expression

A function designator (the identifier introduced by a [function declaration](https://en.cppreference.com/c/language/function_declaration "c/language/function declaration")) is an expression of function type. When used in any context other than the address-of operator, [`sizeof`](https://en.cppreference.com/c/language/sizeof "c/language/sizeof"), and [`_Alignof`](https://en.cppreference.com/c/language/_Alignof "c/language/ Alignof") (the last two generate compile errors when applied to functions), the function designator is always converted to a non-lvalue pointer to function. Note that the function-call operator is defined for pointers to functions and not for function designators themselves.

### References

- C23 standard (ISO/IEC 9899:2024):

- 6.3.2.1 Lvalues, arrays, and function designators (p: 48-49)

- C17 standard (ISO/IEC 9899:2018):

- 6.3.2.1 Lvalues, arrays, and function designators (p: 40)

- C11 standard (ISO/IEC 9899:2011):

- 6.3.2.1 Lvalues, arrays, and function designators (p: 54-55)

- C99 standard (ISO/IEC 9899:1999):

- 6.3.2.1 Lvalues, arrays, and function designators (p: 46)

- C89/C90 standard (ISO/IEC 9899:1990):

- 3.2.2.1 Lvalues and function designators

### See also

[C++ documentation](https://en.cppreference.com/cpp/language/value_category "cpp/language/value category") for Value categories