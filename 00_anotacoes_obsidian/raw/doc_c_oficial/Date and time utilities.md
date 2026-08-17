---
title: "Date and time utilities"
source: "https://en.cppreference.com/c/chrono"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
### Functions

<table><tbody><tr><td colspan="2"><h5>Time manipulation</h5></td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/chrono/difftime">difftime</a></p></td><td>computes the difference between times<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/chrono/time">time</a></p></td><td>returns the current calendar time of the system as time since epoch<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/chrono/clock">clock</a></p></td><td>returns raw processor clock time since the program is started<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/chrono/timespec_get">timespec_get</a></p><p>(C11)</p></td><td>returns the calendar time in seconds and nanoseconds based on a given time base<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/chrono/timespec_getres">timespec_getres</a></p><p>(C23)</p></td><td>returns the resolution of calendar time based on a given time base<br>(function)</td></tr><tr><td colspan="2"><h5>Format conversions</h5></td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/chrono/asctime">asctimeasctime_s</a></p><p>(deprecated in C23)(C11)</p></td><td>converts a tm object to a textual representation<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/chrono/ctime">ctimectime_s</a></p><p>(deprecated in C23)(C11)</p></td><td>converts a time_t object to a textual representation<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/chrono/strftime">strftime</a></p></td><td>converts a tm object to custom textual representation<br>(function)</td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/chrono/wcsftime">wcsftime</a></p><p>(C95)</p></td><td>converts a tm object to custom wide string textual representation<br>(function)</td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/chrono/gmtime">gmtimegmtime_rgmtime_s</a></p><p>(C23)(C11)</p></td><td>converts time since epoch to calendar time expressed as Coordinated Universal Time (UTC)<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/chrono/localtime">localtimelocaltime_rlocaltime_s</a></p><p>(C23)(C11)</p></td><td>converts time since epoch to calendar time expressed as local time<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/chrono/mktime">mktime</a></p></td><td>converts calendar time to time since epoch<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/chrono/timegm">timegm</a></p><p>(C23)</p></td><td>converts calendar time to time since epoch, ignoring the Daylight Saving Time flag<br>(function)</td></tr></tbody></table>

### Constants

<table><tbody><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/chrono/CLOCKS_PER_SEC">CLOCKS_PER_SEC</a></p></td><td>number of processor clock ticks per second<br>(macro constant)</td></tr></tbody></table>

### Types

<table><tbody><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/chrono/tm">tm</a></p></td><td>calendar time type<br>(struct)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/chrono/time_t">time_t</a></p></td><td>calendar time since epoch type<br>(typedef)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/chrono/clock_t">clock_t</a></p></td><td>processor time since era type<br>(typedef)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/chrono/timespec">timespec</a></p><p>(C11)</p></td><td>time in seconds and nanoseconds<br>(struct)</td></tr></tbody></table>

### References

- C23 standard (ISO/IEC 9899:2024):

- 7.27 Date and time <time.h> (p: TBD)

- 7.29.5.1 The wcsftime function (p: TBD)

- 7.31.14 Date and time <time.h> (p: TBD)

- C17 standard (ISO/IEC 9899:2018):

- 7.27 Date and time <time.h> (p: 284-291)

- 7.29.5.1 The wcsftime function (p: 320-321)

- 7.31.14 Date and time <time.h> (p: 333)

- C11 standard (ISO/IEC 9899:2011):

- 7.27 Date and time <time.h> (p: 388-397)

- C99 standard (ISO/IEC 9899:1999):

- 7.23 Date and time <time.h> (p: 338-347)

- C89/C90 standard (ISO/IEC 9899:1990):

- 4.12 DATE AND TIME <time.h>

### See also

[C++ documentation](https://en.cppreference.com/cpp/chrono/c "cpp/chrono/c") for C Date and time utilities