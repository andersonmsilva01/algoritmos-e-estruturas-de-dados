---
title: "Functions - cppreference.com"
source: "https://en.cppreference.com/c/language/functions"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
## Functions

A function is a C language construct that associates a [compound statement](https://en.cppreference.com/c/language/statements#Compound_statements "c/language/statements") (the function body) with an [identifier](https://en.cppreference.com/c/language/identifier "c/language/identifier") (the function name). Every C program begins execution from the [main function](https://en.cppreference.com/c/language/main_function "c/language/main function"), which either terminates, or invokes other, user-defined or library functions.

```
// function definition.
// defines a function with the name "sum" and with the body "{ return x+y; }"
int sum(int x, int y) 
{
    return x + y;
}
```

A function is introduced by a [function declaration](https://en.cppreference.com/c/language/function_declaration "c/language/function declaration") or a [function definition](https://en.cppreference.com/c/language/function_definition "c/language/function definition").

Functions may accept zero or more *parameters*, which are initialized from the *arguments* of a [function call operator](https://en.cppreference.com/c/language/operator_other#Function_call "c/language/operator other"), and may return a value to its caller by means of the [return statement](https://en.cppreference.com/c/language/return "c/language/return").

```
int n = sum(1, 2); // parameters x and y are initialized with the arguments 1 and 2
```

The body of a function is provided in a [function definition](https://en.cppreference.com/c/language/function_definition "c/language/function definition"). Each non- [inline](https://en.cppreference.com/c/language/inline "c/language/inline") (since C99) function that is used in an expression (unless [unevaluated](https://en.cppreference.com/c/language/expressions#Unevaluated_expressions "c/language/expressions")) must be [defined only once](https://en.cppreference.com/c/language/extern#One_definition_rule "c/language/extern") in a program.

There are no nested functions (except where allowed through non-standard compiler extensions): each function definition must appear at file scope, and functions have no access to the local variables from the caller:

```
int main(void) // the main function definition
{
    int sum(int, int); // function declaration (may appear at any scope)
    int x = 1;  // local variable in main
    sum(1, 2); // function call

//    int sum(int a, int b) // error: no nested functions
//    {
//        return  a + b; 
//    }
}
int sum(int a, int b) // function definition
{
//    return x + a + b; //  error: main's x is not accessible within sum
    return a + b;
}
```

### References

- C23 standard (ISO/IEC 9899:2024):

- 6.7.7.4 Function declarators (including prototypes) (p: TBD)

- 6.9.2 Function definitions (p: TBD)

- C17 standard (ISO/IEC 9899:2018):

- 6.7.6.3 Function declarators (including prototypes) (p: 96-98)

- 6.9.1 Function definitions (p: 113-115)

- C11 standard (ISO/IEC 9899:2011):

- 6.7.6.3 Function declarators (including prototypes) (p: 133-136)

- C99 standard (ISO/IEC 9899:1999):

- 6.7.5.3 Function declarators (including prototypes) (p: 118-121)

- C89/C90 standard (ISO/IEC 9899:1990):

- 3.5.4.3 Function declarators (including prototypes)

### See also

[C++ documentation](https://en.cppreference.com/cpp/language/function "cpp/language/function") for Declaring functions