---
title: "Dynamic memory extensions"
source: "https://en.cppreference.com/c/experimental/dynamic"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
Extensions to the C Library Part II: Dynamic Allocation Functions, ISO/IEC TR 24731-2:2010, defines the following new components for the C standard library:

<table><tbody><tr><td><p>__STDC_ALLOC_LIB__</p></td><td>integer constant of type <code>long</code> indicating conformance level<br>(macro constant)</td></tr><tr><td colspan="2"></td></tr><tr><td><p>(dynamic memory TR)</p></td><td>opens a fixed-size memory buffer as an I/O stream<br>(function)</td></tr><tr><td><p>(dynamic memory TR)</p></td><td>opens a dynamically resized memory buffer as an I/O stream<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/experimental/dynamic/asprintf">asprintfaswprintfvasprintfvaswprintf</a></p><p>(dynamic memory TR)</p></td><td>variants of sprintf etc that write to automatically-allocated buffer and return a pointer to it<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/experimental/dynamic/getline">getlinegetwlinegetdelimgetwdelim</a></p><p>(dynamic memory TR)</p></td><td>read from a stream into an automatically resized buffer until delimiter/end of line<br>(function)</td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/experimental/dynamic/strdup">strdup</a></p><p>(dynamic memory TR)</p></td><td>allocate a copy of a string<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/experimental/dynamic/strndup">strndup</a></p><p>(dynamic memory TR)</p></td><td>allocate a copy of a string up to specified size<br>(function)</td></tr></tbody></table>

This library extension also introduces assignment-allocation character `**m**` for use with `**%s**`, `**%[**`, and `**%c**` conversion specifiers in fscanf and fwscanf family of functions.

### Notes

The functions `fmemopen`, `open_memstream`, `open_wmemstream`, `getdelim`, `getline`, `strdup`, `strndup`, and the extensions to `fscanf` are available in [POSIX (ISO/IEC 9945:2003)](http://pubs.opengroup.org/onlinepubs/9699919799/).

The functions `asprintf` and `vasprintf` are available in Linux Standard Base (ISO/IEC IS 23360:2006)