---
title: "Statements - cppreference.com"
source: "https://en.cppreference.com/c/language/statements"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
## Statements

Statements are fragments of the C program that are executed in sequence. The body of any function is a compound statement, which, in turn is a sequence of statements and declarations:

```
int main(void)
{ // start of a compound statement
    int n = 1; // declaration (not a statement)
    n = n+1; // expression statement
    printf("n = %d\n", n); // expression statement
    return 0; // return statement
} // end of compound statement, end of function body
```

There are five types of statements:

1) [compound statements](#Compound_statements)

2) [expression statements](#Expression_statements)

3) [selection statements](#Selection_statements)

4) [iteration statements](#Iteration_statements)

5) [jump statements](#Jump_statements)

| An [attribute specifier sequence](https://en.cppreference.com/c/language/attributes "c/language/attributes") (attr-spec-seq) can be applied to an unlabeled statement, in which case (except for an expression statement) the attributes are applied to the respective statement. | (since C23) |
| --- | --- |

### Labels

Any statement can be *labeled*, by providing a name followed by a colon before the statement itself.

<table><tbody><tr><td colspan="10"></td></tr><tr><td>attr-spec-seq(optional)(since C23) identifier <code><b>:</b></code></td><td>(1)</td><td></td></tr><tr><td colspan="10"></td></tr><tr><td>attr-spec-seq(optional)(since C23) <code><b>case</b></code> constant-expression <code><b>:</b></code></td><td>(2)</td><td></td></tr><tr><td colspan="10"></td></tr><tr><td>attr-spec-seq(optional)(since C23) <code><b>default</b></code> <code><b>:</b></code></td><td>(3)</td><td></td></tr><tr><td colspan="10"></td></tr></tbody></table>

1) Target for [goto](https://en.cppreference.com/c/language/goto "c/language/goto").

2) Case label in a [switch](https://en.cppreference.com/c/language/switch "c/language/switch") statement.

3) Default label in a [switch](https://en.cppreference.com/c/language/switch "c/language/switch") statement.

Any statement (but not a declaration) may be preceded by any number of *labels*, each of which declares identifier to be a label name, which must be unique within the enclosing function (in other words, label names have [function scope](https://en.cppreference.com/c/language/scope "c/language/scope")).

Label declaration has no effect on its own, does not alter the flow of control, or modify the behavior of the statement that follows in any way.

| A label shall be followed by a statement. | (until C23) |
| --- | --- |
| A label can appear without its following statement. If a label appears alone in a block, it behaves as if it is followed by a [null statement](#Expression_statements).  The optional [attr-spec-seq](https://en.cppreference.com/c/language/attributes "c/language/attributes") is applied to the label. | (since C23) |

### Compound statements

A compound statement, or *block*, is a brace-enclosed sequence of statements and declarations.

<table><tbody><tr><td colspan="10"></td></tr><tr><td><code><b>{</b></code> statement <code>|</code> declaration...(optional) <code><b>} </b></code></td><td></td><td>(until C23)</td></tr><tr><td colspan="10"></td></tr><tr><td>attr-spec-seq(optional) <code><b>{</b></code> unlabeled-statement <code>|</code> label <code>|</code> declaration...(optional) <code><b>} </b></code></td><td></td><td>(since C23)</td></tr><tr><td colspan="10"></td></tr></tbody></table>

The compound statement allows a set of declarations and statements to be grouped into one unit that can be used anywhere a single statement is expected (for example, in an [if](https://en.cppreference.com/c/language/if "c/language/if") statement or an iteration statement):

```
if (expr) // start of if-statement
{ // start of block
  int n = 1; // declaration
  printf("%d\n", n); // expression statement
} // end of block, end of if-statement
```

Each compound statement introduces its own [block scope](https://en.cppreference.com/c/language/scope "c/language/scope").

The initializers of the variables with automatic [storage duration](https://en.cppreference.com/c/language/storage_duration "c/language/storage duration") declared inside a block and the VLA declarators are executed when flow of control passes over these declarations in order, as if they were statements:

```
int main(void)
{ // start of block
  { // start of block
       puts("hello"); // expression statement
       int n = printf("abc\n"); // declaration, prints "abc", stores 4 in n
       int a[n*printf("1\n")]; // declaration, prints "1", allocates 8*sizeof(int)
       printf("%zu\n", sizeof(a)); // expression statement
  } // end of block, scope of n and a ends
  int n = 7; // n can be reused
}
```

### Expression statements

An expression followed by a semicolon is a statement.

<table><tbody><tr><td colspan="10"></td></tr><tr><td>expression(optional) <code><b>;</b></code></td><td>(1)</td><td></td></tr><tr><td colspan="10"></td></tr><tr><td>attr-spec-seq expression <code><b>;</b></code></td><td>(2)</td><td>(since C23)</td></tr><tr><td colspan="10"></td></tr></tbody></table>

Most statements in a typical C program are expression statements, such as assignments or function calls.

An expression statement without an expression is called a *null statement*. It is often used to provide an empty body to a [for](https://en.cppreference.com/c/language/for "c/language/for") or [while](https://en.cppreference.com/c/language/while "c/language/while") loop. It can also be used to carry a label in the end of a compound statement or before a declaration:

```
puts("hello"); // expression statement
char *s;
while (*s++ != '\0')
    ; // null statement
```

| The optional [attr-spec-seq](https://en.cppreference.com/c/language/attributes "c/language/attributes") is applied to the expression.  An attr-spec-seq followed by `**;**` does not form an expression statement. It forms an [attribute declaration](https://en.cppreference.com/c/language/declarations "c/language/declarations") instead. | (since C23) |
| --- | --- |

### Selection statements

The selection statements choose between one of several statements depending on the value of an expression.

<table><tbody><tr><td colspan="10"></td></tr><tr><td>attr-spec-seq(optional)(since C23) <code><b>if</b></code> <code><b>(</b></code> expression <code><b>)</b></code> statement</td><td>(1)</td><td></td></tr><tr><td colspan="10"></td></tr><tr><td>attr-spec-seq(optional)(since C23) <code><b>if</b></code> <code><b>(</b></code> expression <code><b>)</b></code> statement <code><b>else</b></code> statement</td><td>(2)</td><td></td></tr><tr><td colspan="10"></td></tr><tr><td>attr-spec-seq(optional)(since C23) <code><b>switch</b></code> <code><b>(</b></code> expression <code><b>)</b></code> statement</td><td>(3)</td><td></td></tr><tr><td colspan="10"></td></tr></tbody></table>

1) [if](https://en.cppreference.com/c/language/if "c/language/if") statement

2) [if](https://en.cppreference.com/c/language/if "c/language/if") statement with an else clause

3) [switch](https://en.cppreference.com/c/language/switch "c/language/switch") statement

### Iteration statements

The iteration statements repeatedly execute a statement.

<table><tbody><tr><td colspan="10"></td></tr><tr><td>attr-spec-seq(optional)(since C23) <code><b>while</b></code> <code><b>(</b></code> expression <code><b>)</b></code> statement</td><td>(1)</td><td></td></tr><tr><td colspan="10"></td></tr><tr><td>attr-spec-seq(optional)(since C23) <code><b>do</b></code> statement <code><b>while</b></code> <code><b>(</b></code> expression <code><b>)</b></code> <code><b>;</b></code></td><td>(2)</td><td></td></tr><tr><td colspan="10"></td></tr><tr><td>attr-spec-seq(optional)(since C23) <code><b>for</b></code> <code><b>(</b></code> init-clause <code><b>;</b></code> expression(optional) <code><b>;</b></code> expression(optional) <code><b>)</b></code> statement</td><td>(3)</td><td></td></tr><tr><td colspan="10"></td></tr></tbody></table>

1) [while](https://en.cppreference.com/c/language/while "c/language/while") loop

2) [do-while](https://en.cppreference.com/c/language/do "c/language/do") loop

3) [for](https://en.cppreference.com/c/language/for "c/language/for") loop

### Jump statements

The jump statements unconditionally transfer flow control.

<table><tbody><tr><td colspan="10"></td></tr><tr><td>attr-spec-seq(optional)(since C23) <code><b>break</b></code> <code><b>;</b></code></td><td>(1)</td><td></td></tr><tr><td colspan="10"></td></tr><tr><td>attr-spec-seq(optional)(since C23) <code><b>continue</b></code> <code><b>;</b></code></td><td>(2)</td><td></td></tr><tr><td colspan="10"></td></tr><tr><td>attr-spec-seq(optional)(since C23) <code><b>return</b></code> expression(optional) <code><b>;</b></code></td><td>(3)</td><td></td></tr><tr><td colspan="10"></td></tr><tr><td>attr-spec-seq(optional)(since C23) <code><b>goto</b></code> identifier <code><b>;</b></code></td><td>(4)</td><td></td></tr><tr><td colspan="10"></td></tr></tbody></table>

1) [break](https://en.cppreference.com/c/language/break "c/language/break") statement

2) [continue](https://en.cppreference.com/c/language/continue "c/language/continue") statement

3) [return](https://en.cppreference.com/c/language/return "c/language/return") statement with an optional expression

4) [goto](https://en.cppreference.com/c/language/goto "c/language/goto") statement

### References

- C23 standard (ISO/IEC 9899:2024):

- 6.8 Statements and blocks (p: TBD)

- C17 standard (ISO/IEC 9899:2018):

- 6.8 Statements and blocks (p: 106-112)

- C11 standard (ISO/IEC 9899:2011):

- 6.8 Statements and blocks (p: 146-154)

- C99 standard (ISO/IEC 9899:1999):

- 6.8 Statements and blocks (p: 131-139)

- C89/C90 standard (ISO/IEC 9899:1990):

- 3.6 STATEMENTS

### See also

[C++ documentation](https://en.cppreference.com/cpp/language/statements "cpp/language/statements") for Statements