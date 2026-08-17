---
title: "Declarations - cppreference.com"
source: "https://en.cppreference.com/c/language/declarations"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
## Declarations

A *declaration* is a C language construct that introduces one or more [identifiers](https://en.cppreference.com/c/language/identifier "c/language/identifier") into the program and specifies their meaning and properties.

Declarations may appear in any scope. Each declaration ends with a semicolon (just like [a statement](https://en.cppreference.com/c/language/statements "c/language/statements")) and consists of two(until C23)three(since C23) distinct parts:

<table><tbody><tr><td colspan="10"></td></tr><tr><td>specifiers-and-qualifiers declarators-and-initializers (optional) <code><b>;</b></code></td><td>(1)</td><td></td></tr><tr><td colspan="10"></td></tr><tr><td>attr-spec-seq specifiers-and-qualifiers declarators-and-initializers <code><b>;</b></code></td><td>(2)</td><td>(since C23)</td></tr><tr><td colspan="10"></td></tr><tr><td>attr-spec-seq <code><b>;</b></code></td><td>(3)</td><td>(since C23)</td></tr><tr><td colspan="10"></td></tr></tbody></table>

where

| specifiers-and-qualifiers | \- | whitespace-separated list of, in any order, - type specifiers:  - ``` 	void 	``` - the name of an [arithmetic type](https://en.cppreference.com/c/language/arithmetic_types "c/language/arithmetic types") - the name of an [atomic type](https://en.cppreference.com/c/language/atomic "c/language/atomic") - a name earlier introduced by a [typedef](https://en.cppreference.com/c/language/typedef "c/language/typedef") declaration - [`struct`](https://en.cppreference.com/c/language/struct "c/language/struct"), [`union`](https://en.cppreference.com/c/language/union "c/language/union"), or [`enum`](https://en.cppreference.com/c/language/enum "c/language/enum") specifier - a [typeof](https://en.cppreference.com/c/language/typeof "c/language/typeof") specifier (since C23)  - zero or one storage-class specifiers: [`typedef`](https://en.cppreference.com/c/language/typedef "c/language/typedef"), [`constexpr`](https://en.cppreference.com/c/language/constexpr "c/language/constexpr"), [`auto`](https://en.cppreference.com/c/language/auto "c/language/auto"),[ 	``` 	register 	``` 	, 	``` 	static 	``` 	, 	``` 	extern 	``` 	, `_Thread_local`](https://en.cppreference.com/c/language/storage_duration "c/language/storage duration") - zero or more type qualifiers: [`const`](https://en.cppreference.com/c/language/const "c/language/const"), [`volatile`](https://en.cppreference.com/c/language/volatile "c/language/volatile"), [`restrict`](https://en.cppreference.com/c/language/restrict "c/language/restrict"), [`_Atomic`](https://en.cppreference.com/c/language/atomic "c/language/atomic") - (only when declaring functions), zero or more function specifiers: [`inline`](https://en.cppreference.com/c/language/inline "c/language/inline"), [`_Noreturn`](https://en.cppreference.com/c/language/_Noreturn "c/language/ Noreturn") - zero or more alignment specifiers: [`_Alignas`](https://en.cppreference.com/c/language/_Alignas "c/language/ Alignas") (since C11)(until C23) [`alignas`](https://en.cppreference.com/c/language/alignas "c/language/alignas") (since C23) |
| --- | --- | --- |
| declarators-and-initializers | \- | comma-separated list of declarators (each declarator provides additional type information and/or the identifier to declare). Declarators may be accompanied by [initializers](https://en.cppreference.com/c/language/initialization "c/language/initialization"). The [enum](https://en.cppreference.com/c/language/enum "c/language/enum"), [struct](https://en.cppreference.com/c/language/struct "c/language/struct"), and [union](https://en.cppreference.com/c/language/union "c/language/union") declarations may omit declarators, in which case they only introduce the enumeration constants and/or tags. |
| attr-spec-seq | \- | (C23)optional list of [attributes](https://en.cppreference.com/c/language/attributes "c/language/attributes"), applied to the declared entities, or forms an attribute declaration if appears alone. |

1,2) Simple declaration. Introduces one or more identifiers which denotes objects, functions, struct/union/enum tags, typedefs, or enumeration constants.

3) Attribute declaration. Does not declares any identifier, and has implementation-defined meaning if the meaning is not specified by the standard.

For example,

```
int a, *b=NULL; // "int" is the type specifier,
                // "a" is a declarator
                // "*b" is a declarator and NULL is its initializer
const int *f(void); // "int" is the type specifier
                    // "const" is the type qualifier
                    // "*f(void)" is the declarator
enum COLOR {RED, GREEN, BLUE} c; // "enum COLOR {RED, GREEN, BLUE}" is the type specifier
                                 // "c" is the declarator
```

The type of each identifier introduced in a declaration is determined by a combination of the type specified by the and the type modifications applied by its. The type of a variable might also be inferred if

```
auto
```
specifier is used.

[Attributes](https://en.cppreference.com/c/language/attributes "c/language/attributes") (since C23) may appear in specifiers-and-qualifiers, in which case they apply to the type determined by the preceding specifiers.

### Declarators

Each declarator is one of the following:

<table><tbody><tr><td colspan="10"></td></tr><tr><td>identifier attr-spec-seq (optional)</td><td>(1)</td><td></td></tr><tr><td colspan="10"></td></tr><tr><td><code><b>(</b></code> declarator <code><b>)</b></code></td><td>(2)</td><td></td></tr><tr><td colspan="10"></td></tr><tr><td><code><b>*</b></code> attr-spec-seq (optional) qualifiers (optional) declarator</td><td>(3)</td><td></td></tr><tr><td colspan="10"></td></tr><tr><td>noptr-declarator <code><b>[</b></code> <code><b>static</b></code> (optional) qualifiers (optional) expression <code><b>]</b></code><p>noptr-declarator <code><b>[</b></code> qualifiers (optional) <code><b>*</b></code> <code><b>]</b></code></p></td><td>(4)</td><td></td></tr><tr><td colspan="10"></td></tr><tr><td>noptr-declarator <code><b>(</b></code> parameters-or-identifiers <code><b>)</b></code></td><td>(5)</td><td></td></tr><tr><td colspan="10"></td></tr></tbody></table>

1) the identifier that this declarator introduces.

2) any declarator may be enclosed in parentheses; this is required to introduce pointers to arrays and pointers to functions.

3) [pointer declarator](https://en.cppreference.com/c/language/pointer "c/language/pointer"): the declaration `S * cvr D`; declares `D` as a cvr-qualified pointer to the type determined by `S`.

4) [array declarator](https://en.cppreference.com/c/language/array "c/language/array"): the declaration `S D[N]` declares `D` as an array of `N` objects of the type determined by `S`. noptr-declarator is any other declarator except unparenthesized pointer declarator.

5) [function declarator](https://en.cppreference.com/c/language/function_declaration "c/language/function declaration"): the declaration `S D(params)` declared `D` as a function taking the parameters `params` and returning `S`. noptr-declarator is any other declarator except unparenthesized pointer declarator.

The reasoning behind this syntax is that when the identifier declared by the declarator appears in an expression of the same form as the declarator, it would have the type specified by the type specifier sequence.

```
struct C
{
    int member; // "int" is the type specifier
                // "member" is the declarator
} obj, *pObj = &obj;
// "struct C { int member; }" is the type specifier
// declarator "obj" defines an object of type struct C
// declarator "*pObj" declares a pointer to C,
// initializer "= &obj" provides the initial value for that pointer
 
int a = 1, *p = NULL, f(void), (*pf)(double);
// the type specifier is "int"
// declarator "a" defines an object of type int
//   initializer "=1" provides its initial value
// declarator "*p" defines an object of type pointer to int
//   initializer "=NULL" provides its initial value
// declarator "f(void)" declares a function taking void and returning int
// declarator "(*pf)(double)" defines an object of type pointer
//   to function taking double and returning int
 
int (*(*foo)(double))[3] = NULL;
// the type specifier is int
// 1. declarator "(*(*foo)(double))[3]" is an array declarator:
//    the type declared is "/nested declarator/ array of 3 int"
// 2. the nested declarator is "*(*foo)(double))", which is a pointer declarator
//    the type declared is "/nested declarator/ pointer to array of 3 int"
// 3. the nested declarator is "(*foo)(double)", which is a function declarator
//    the type declared is "/nested declarator/ function taking double and returning
//        pointer to array of 3 int"
// 4. the nested declarator is "(*foo)" which is a (parenthesized, as required by
//        function declarator syntax) pointer declarator.
//    the type declared is "/nested declarator/ pointer to function taking double
//        and returning pointer to array of 3 int"
// 5. the nested declarator is "foo", which is an identifier.
// The declaration introduces the identifier "foo" to refer to an object of type
// "pointer to function taking double and returning pointer to array of 3 int"
// The initializer "= NULL" provides the initial value of this pointer.

// If "foo" is used in an expression of the form of the declarator, its type would be
// int.
int x = (*(*foo)(1.2))[0];
```

The end of every declarator that is not part of another declarator is a [sequence point](https://en.cppreference.com/c/language/eval_order "c/language/eval order").

In all cases, attr-spec-seq is an optional sequence of [attributes](https://en.cppreference.com/c/language/attributes "c/language/attributes") (since C23). When appearing immediately after the identifier, it applies to the object or function being declared.

### Definitions

A *definition* is a declaration that provides all information about the identifiers it declares.

Every declaration of an [enum](https://en.cppreference.com/c/language/enum "c/language/enum") or a [typedef](https://en.cppreference.com/c/language/typedef "c/language/typedef") is a definition.

For functions, a declaration that includes the function body is a [function definition](https://en.cppreference.com/c/language/function_definition "c/language/function definition"):

```
int foo(double); // declaration
int foo(double x) { return x; } // definition
```

For objects, a declaration that allocates storage ([automatic or static](https://en.cppreference.com/c/language/storage_duration "c/language/storage duration"), but not extern) is a definition, while a declaration that does not allocate storage ([external declaration](https://en.cppreference.com/c/language/extern "c/language/extern")) is not.

```
extern int n; // declaration
int n = 10; // definition
```

For [structs](https://en.cppreference.com/c/language/struct "c/language/struct") and [unions](https://en.cppreference.com/c/language/union "c/language/union"), declarations that specify the list of members are definitions:

```
struct X; // declaration
struct X { int n; }; // definition
```

### Redeclaration

A declaration cannot introduce an identifier if another declaration for the same identifier in the same [scope](https://en.cppreference.com/c/language/scope "c/language/scope") appears earlier, except that

- Declarations of objects [with linkage](https://en.cppreference.com/c/language/storage_duration "c/language/storage duration") (external or internal) can be repeated:

```
extern int x;
int x = 10; // OK
extern int x; // OK

static int n;
static int n = 10; // OK
static int n; // OK
```

- Non-VLA [typedef](https://en.cppreference.com/c/language/typedef "c/language/typedef") can be repeated as long as it names the same type:

```
typedef int int_t;
typedef int int_t; // OK
```

- [struct](https://en.cppreference.com/c/language/struct "c/language/struct") and [union](https://en.cppreference.com/c/language/union "c/language/union") declarations can be repeated:

```
struct X;
struct X { int n; };
struct X;
```

These rules simplify the use of header files.

### Notes

| In C89, declarations within any [compound statement](https://en.cppreference.com/c/language/statements#Compound_statements "c/language/statements") (block scope) must appear in the beginning of the block, before any [statements](https://en.cppreference.com/c/language/statements "c/language/statements").  Also, in C89, functions returning  ``` int ``` may be implicitly declared by the [function call operator](https://en.cppreference.com/c/language/operator_other#Function_call "c/language/operator other") and function parameters of type ``` int ``` do not have to be declared when using old-style [function definitions](https://en.cppreference.com/c/language/function_definition "c/language/function definition"). | (until C99) |
| --- | --- |

Empty declarators are prohibited; a simple declaration must have at least one declarator or declare at least one struct/union/enum tag, or introduce at least one enumeration constant.

| If any part of a declarator is a [variable-length array](https://en.cppreference.com/c/language/array "c/language/array") (VLA) declarator, the entire declarator's type is known as "variably-modified type". Types defined from variably-modified types are also variably modified (VM).  Declarations of any variably-modified types may appear only at [block scope](https://en.cppreference.com/c/language/scope "c/language/scope") or function prototype scope and cannot be members of structs or unions. Although VLA can only have automatic or allocated [storage duration](https://en.cppreference.com/c/language/storage_duration "c/language/storage duration"), a VM type such as a pointer to a VLA may be static. There are other restrictions on the use of VM types, see [goto](https://en.cppreference.com/c/language/goto "c/language/goto"), [switch](https://en.cppreference.com/c/language/switch "c/language/switch"). longjmp | (since C99) |
| --- | --- |

| [static\_asserts](https://en.cppreference.com/c/language/_Static_assert "c/language/ Static assert") are considered to be declarations from the point of view of the C grammar (so that they may appear anywhere a declaration may appear), but they do not introduce any identifiers and do not follow the declaration syntax. | (since C11) |
| --- | --- |

| [Attribute](https://en.cppreference.com/c/language/attributes "c/language/attributes") declarations are also considered to be declarations (so that they may appear anywhere a declaration may appear), but they do not introduce any identifiers. A single `**;**` without attr-spec-seq is not an attribute declaration, but a statement. | (since C23) |
| --- | --- |

### References

- C23 standard (ISO/IEC 9899:2024):

- 6.7 Declarations (p: TBD)

- C17 standard (ISO/IEC 9899:2018):

- 6.7 Declarations (p: 78-105)

- C11 standard (ISO/IEC 9899:2011):

- 6.7 Declarations (p: 108-145)

- C99 standard (ISO/IEC 9899:1999):

- 6.7 Declarations (p: 97-130)

- C89/C90 standard (ISO/IEC 9899:1990):

- 3.5 Declarations

### See also

[C++ documentation](https://en.cppreference.com/cpp/language/declarations "cpp/language/declarations") for Declarations