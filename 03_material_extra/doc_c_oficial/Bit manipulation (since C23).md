---
title: "Bit manipulation (since C23)"
source: "https://en.cppreference.com/c/numeric/bit_manip"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
<table><tbody><tr><td colspan="2"><h3>Functions</h3></td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/bit/stdc_leading_zeros">stdc_leading_zeros</a></p><p>(C23)</p></td><td>counts the number of consecutive <code>0</code> bits, starting from the most significant bit<br>(type-generic function macro)</td></tr><tr><td><p>(C23)</p></td><td>counts the number of consecutive <code>1</code> bits, starting from the most significant bit<br>(type-generic function macro)</td></tr><tr><td><p>(C23)</p></td><td>counts the number of consecutive <code>0</code> bits, starting from the least significant bit<br>(type-generic function macro)</td></tr><tr><td><p>(C23)</p></td><td>counts the number of consecutive <code>1</code> bits, starting from the least significant bit<br>(type-generic function macro)</td></tr><tr><td><p>(C23)</p></td><td>finds the first position of <code>0</code> bit, starting from the most significant bit<br>(type-generic function macro)</td></tr><tr><td><p>(C23)</p></td><td>finds the first position of <code>1</code> bit, starting from the most significant bit<br>(type-generic function macro)</td></tr><tr><td><p>(C23)</p></td><td>finds the first position of <code>0</code> bit, starting from the least significant bit<br>(type-generic function macro)</td></tr><tr><td><p>(C23)</p></td><td>finds the first position of <code>1</code> bit, starting from the least significant bit<br>(type-generic function macro)</td></tr><tr><td><p>(C23)</p></td><td>counts the number of <code>0</code> bits in an unsigned integer<br>(type-generic function macro)</td></tr><tr><td><p>(C23)</p></td><td>counts the number of <code>1</code> bits in an unsigned integer<br>(type-generic function macro)</td></tr><tr><td><p>(C23)</p></td><td>checks if a number is an integral power of 2<br>(type-generic function macro)</td></tr><tr><td><p>(C23)</p></td><td>finds the smallest number of bits needed to represent the given value<br>(type-generic function macro)</td></tr><tr><td><p>(C23)</p></td><td>finds the largest integral power of 2 not greater than the given value<br>(type-generic function macro)</td></tr><tr><td><p>(C23)</p></td><td>finds the smallest integral power of 2 not less than the given value<br>(type-generic function macro)</td></tr><tr><td colspan="2"><h3>Macro constants</h3></td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/numeric/bit/endian">__STDC_ENDIAN_LITTLE____STDC_ENDIAN_BIG__ __STDC_ENDIAN_NATIVE__</a></p><p>(C23)</p></td><td>indicates the endianness of scalar types<br>(macro constant)</td></tr></tbody></table>

### References

- C23 standard (ISO/IEC 9899:2024):

- 7.18 Bit and byte utilities <stdbit.h>

### See also

[C++ documentation](https://en.cppreference.com/cpp/utility/bit "cpp/utility/bit") for Bit manipulation