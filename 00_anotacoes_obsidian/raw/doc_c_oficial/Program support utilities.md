---
title: "Program support utilities"
source: "https://en.cppreference.com/c/program"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
### Program termination

The following functions manage program termination and resources cleanup.

<table><tbody><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/abort">abort</a></p></td><td>causes abnormal program termination (without cleaning up)<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/exit">exit</a></p></td><td>causes normal program termination with cleaning up<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/quick_exit">quick_exit</a></p><p>(C11)</p></td><td>causes normal program termination without completely cleaning up<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/_Exit">_Exit</a></p><p>(C99)</p></td><td>causes normal program termination without cleaning up<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/atexit">atexit</a></p></td><td>registers a function to be called on exit() invocation<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/at_quick_exit">at_quick_exit</a></p><p>(C11)</p></td><td>registers a function to be called on <a href="https://en.cppreference.com/c/program/quick_exit"><tt>quick_exit</tt></a> invocation<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/EXIT_status">EXIT_SUCCESSEXIT_FAILURE</a></p></td><td>indicates program execution execution status<br>(macro constant)</td></tr></tbody></table>

### Unreachable control flow

<table><tbody><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/unreachable">unreachable</a></p><p>(C23)</p></td><td>marks unreachable point of execution<br>(function macro)</td></tr></tbody></table>

### Communicating with the environment

<table><tbody><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/system">system</a></p></td><td>calls the host environment's command processor<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/getenv">getenvgetenv_s</a></p><p>(C11)</p></td><td>access to the list of environment variables<br>(function)</td></tr></tbody></table>

### Memory alignment query

<table><tbody><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/memalignment">memalignment</a></p><p>(C23)</p></td><td>queries the alignment of a pointer value<br>(function)</td></tr></tbody></table>

### Signals

Several functions and macro constants for signal management are provided.

<table><tbody><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/signal">signal</a></p></td><td>sets a signal handler for particular signal<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/raise">raise</a></p></td><td>runs the signal handler for particular signal<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/sig_atomic_t">sig_atomic_t</a></p></td><td>the integer type that can be accessed as an atomic entity from an asynchronous signal handler<br>(typedef)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/SIG_strategies">SIG_DFLSIG_IGN</a></p></td><td>defines signal handling strategies<br>(macro constant)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/SIG_ERR">SIG_ERR</a></p></td><td>error was encountered<br>(macro constant)</td></tr><tr><td colspan="2"><h5>Signal types</h5></td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/SIG_types">SIGABRTSIGFPESIGILLSIGINTSIGSEGVSIGTERM</a></p></td><td>defines signal types<br>(macro constant)</td></tr></tbody></table>

### Non-local jumps

<table><tbody><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/setjmp">setjmp</a></p></td><td>saves the context<br>(function macro)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/longjmp">longjmp</a></p></td><td>jumps to specified location<br>(function)</td></tr><tr><td colspan="2"><h5>Types</h5></td></tr><tr><td><p><a href="https://en.cppreference.com/c/program/jmp_buf">jmp_buf</a></p></td><td>execution context type<br>(typedef)</td></tr></tbody></table>

### References

- C23 standard (ISO/IEC 9899:2024):

- 7.13 Non-local jumps <setjmp.h> (p: 283-284)

- 7.14 Signal handling <signal.h> (p: 285-287)

- 7.24 General utilities <stdlib.h> (p: 356-374)

- 7.33.9 Signal handling <signal.h> (p: 458)

- 7.33.16 General utilities <stdlib.h> (p: 458)

- C17 standard (ISO/IEC 9899:2018):

- 7.13 Nonlocal jumps <setjmp.h> (p: 191-192)

- 7.14 Signal handling <signal.h> (p: 193-195)

- 7.22 General utilities <stdlib.h> (p: 248-262)

- 7.31.7 Signal handling <signal.h> (p: 332)

- 7.31.12 General utilities <stdlib.h> (p: 333)

- C11 standard (ISO/IEC 9899:2011):

- 7.13 Nonlocal jumps <setjmp.h> (p: 262-264)

- 7.14 Signal handling <signal.h> (p: 265-267)

- 7.22 General utilities <stdlib.h> (p: 340-360)

- 7.31.7 Signal handling <signal.h> (p: 455)

- 7.31.12 General utilities <stdlib.h> (p: 456)

- C99 standard (ISO/IEC 9899:1999):

- 7.13 Nonlocal jumps <setjmp.h> (p: 243-245)

- 7.14 Signal handling <signal.h> (p: 246-248)

- C89/C90 standard (ISO/IEC 9899:1990):

- 4.6 NON-LOCAL JUMPS <setjmp.h>

### See also

[C++ documentation](https://en.cppreference.com/cpp/utility/program "cpp/utility/program") for Program support utilities