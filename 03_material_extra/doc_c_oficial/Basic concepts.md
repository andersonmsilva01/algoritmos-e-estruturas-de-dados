---
title: "Basic concepts"
source: "https://en.cppreference.com/c/language/basic_concepts"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
This section provides definitions for the specific terminology and the concepts used when describing the C programming language.

A C program is a sequence of text files (typically header and source files) that contain [declarations](https://en.cppreference.com/c/language/declarations "c/language/declarations"). They undergo [translation](https://en.cppreference.com/c/language/translation_phases "c/language/translation phases") to become an executable program, which is executed when the OS calls its [main function](https://en.cppreference.com/c/language/main_function "c/language/main function") (unless it is itself the OS or another *freestanding* program, in which case the entry point is implementation-defined).

Certain words in a C program have special meaning, they are [keywords](https://en.cppreference.com/c/keyword "c/keyword"). Others can be used as [identifiers](https://en.cppreference.com/c/language/identifier "c/language/identifier"), which may be used to identify [objects](https://en.cppreference.com/c/language/object "c/language/object"), [functions](https://en.cppreference.com/c/language/functions "c/language/functions"), [struct](https://en.cppreference.com/c/language/struct "c/language/struct"), [union](https://en.cppreference.com/c/language/union "c/language/union"), or [enumeration](https://en.cppreference.com/c/language/enum "c/language/enum") tags, their members, [typedef](https://en.cppreference.com/c/language/typedef "c/language/typedef") names, [labels](https://en.cppreference.com/c/language/statements#Labels "c/language/statements"), or [macros](https://en.cppreference.com/c/preprocessor/replace "c/preprocessor/replace").

Each identifier (other than macro) is only valid within a part of the program called its [scope](https://en.cppreference.com/c/language/scope "c/language/scope") and belongs to one of four kinds of [name spaces](https://en.cppreference.com/c/language/name_space "c/language/name space"). Some identifiers have [linkage](https://en.cppreference.com/c/language/storage_duration "c/language/storage duration") which makes them refer to the same entities when they appear in different scopes or translation units.

Definitions of functions include sequences of [statements](https://en.cppreference.com/c/language/statements "c/language/statements") and [declarations](https://en.cppreference.com/c/language/declarations "c/language/declarations"), some of which include [expressions](https://en.cppreference.com/c/language/expressions "c/language/expressions"), which specify the computations to be performed by the program.

[Declarations](https://en.cppreference.com/c/language/declarations "c/language/declarations") and [expressions](https://en.cppreference.com/c/language/expressions "c/language/expressions") create, destroy, access, and manipulate [objects](https://en.cppreference.com/c/language/object "c/language/object"). Each [object](https://en.cppreference.com/c/language/object "c/language/object"), [function](https://en.cppreference.com/c/language/functions "c/language/functions"), and [expression](https://en.cppreference.com/c/language/expressions "c/language/expressions") in C is associated with a [type](https://en.cppreference.com/c/language/type "c/language/type").

### See also

[C++ documentation](https://en.cppreference.com/cpp/language/basic_concepts "cpp/language/basic concepts") for Basic concepts