---
title: "File input/output"
source: "https://en.cppreference.com/c/io"
author:
published:
created: 2026-05-26
description:
tags:
  - "clippings"
---
The [<stdio.h>](https://en.cppreference.com/c/header/stdio "c/header/stdio") header provides generic file operation support and supplies functions with narrow character input/output capabilities.

The [<wchar.h>](https://en.cppreference.com/c/header/wchar "c/header/wchar") header supplies functions with wide character input/output capabilities.

I/O streams are denoted by objects of type that can only be accessed and manipulated through pointers of type

```
FILE*
```
. Each stream is associated with an external physical device (file, standard input stream, printer, serial port, etc).

### Types

<table><tbody><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/FILE">FILE</a></p></td><td>object type, capable of holding all information needed to control a C I/O stream<br>(typedef)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fpos_t">fpos_t</a></p></td><td>non-array complete object type, capable of uniquely specifying a position and multibyte parser state in a file<br>(typedef)</td></tr></tbody></table>

### Predefined standard streams

<table><tbody><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/std_streams">stdinstdoutstderr</a></p></td><td>expression of type<pre><code>FILE*</code></pre>associated with the input stream<br>expression of type<pre><code>FILE*</code></pre>associated with the output stream<br>expression of type<pre><code>FILE*</code></pre>associated with the error output stream<br>(macro constant)</td></tr></tbody></table>

### Functions

<table><tbody><tr><td colspan="2"><h5>File access</h5></td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fopen">fopenfopen_s</a></p><p>(C11)</p></td><td>opens a file<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/freopen">freopenfreopen_s</a></p><p>(C11)</p></td><td>open an existing stream with a different name<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fclose">fclose</a></p></td><td>closes a file<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fflush">fflush</a></p></td><td>synchronizes an output stream with the actual file<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/setbuf">setbuf</a></p></td><td>sets the buffer for a file stream<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/setvbuf">setvbuf</a></p></td><td>sets the buffer and its size for a file stream<br>(function)</td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fwide">fwide</a></p><p>(C95)</p></td><td>switches a file stream between wide character I/O and narrow character I/O<br>(function)</td></tr><tr><td colspan="2"><h5>Direct input/output</h5></td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fread">fread</a></p></td><td>reads from a file<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fwrite">fwrite</a></p></td><td>writes to a file<br>(function)</td></tr><tr><td colspan="2"><h5>Unformatted input/output</h5></td></tr><tr><td colspan="2"><h6>Narrow character</h6></td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fgetc">fgetcgetc</a></p></td><td>gets a character from a file stream<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fgets">fgets</a></p></td><td>gets a character string from a file stream<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fputc">fputcputc</a></p></td><td>writes a character to a file stream<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fputs">fputs</a></p></td><td>writes a character string to a file stream<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/getchar">getchar</a></p></td><td>reads a character from stdin<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/gets">getsgets_s</a></p><p>(removed in C11)(C11)</p></td><td>reads a character string from stdin<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/putchar">putchar</a></p></td><td>writes a character to stdout<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/puts">puts</a></p></td><td>writes a character string to stdout<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/ungetc">ungetc</a></p></td><td>puts a character back into a file stream<br>(function)</td></tr><tr><td colspan="2"><h6>Wide character</h6></td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fgetwc">fgetwcgetwc</a></p><p>(C95)</p></td><td>gets a wide character from a file stream<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fgetws">fgetws</a></p><p>(C95)</p></td><td>gets a wide string from a file stream<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fputwc">fputwcputwc</a></p><p>(C95)</p></td><td>writes a wide character to a file stream<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fputws">fputws</a></p><p>(C95)</p></td><td>writes a wide string to a file stream<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/getwchar">getwchar</a></p><p>(C95)</p></td><td>reads a wide character from stdin<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/putwchar">putwchar</a></p><p>(C95)</p></td><td>writes a wide character to stdout<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/ungetwc">ungetwc</a></p><p>(C95)</p></td><td>puts a wide character back into a file stream<br>(function)</td></tr><tr><td colspan="2"><h5>Formatted input/output</h5></td></tr><tr><td colspan="2"><h6>Narrow character</h6></td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fscanf">scanffscanfsscanfscanf_sfscanf_ssscanf_s</a></p><p>(C11)(C11)(C11)</p></td><td>reads formatted input from stdin, a file stream or a buffer<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/vfscanf">vscanfvfscanfvsscanfvscanf_svfscanf_svsscanf_s</a></p><p>(C99)(C99)(C99)(C11)(C11)(C11)</p></td><td>reads formatted input from stdin, a file stream or a buffer<br>using variable argument list<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fprintf">printffprintfsprintfsnprintfprintf_sfprintf_ssprintf_ssnprintf_s</a></p><p>(C99)(C11)(C11)(C11)(C11)</p></td><td>prints formatted output to stdout, a file stream or a buffer<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/vfprintf">vprintfvfprintfvsprintfvsnprintfvprintf_svfprintf_svsprintf_svsnprintf_s</a></p><p>(C99)(C11)(C11)(C11)(C11)</p></td><td>prints formatted output to stdout, a file stream or a buffer<br>using variable argument list<br>(function)</td></tr><tr><td colspan="2"><h6>Wide character</h6></td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fwscanf">wscanffwscanfswscanfwscanf_sfwscanf_sswscanf_s</a></p><p>(C95)(C95)(C95)(C11)(C11)(C11)</p></td><td>reads formatted wide character input from stdin, a file stream or a buffer<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/vfwscanf">vwscanfvfwscanfvswscanfvwscanf_svfwscanf_svswscanf_s</a></p><p>(C99)(C99)(C99)(C11)(C11)(C11)</p></td><td>reads formatted wide character input from stdin, a file stream<br>or a buffer using variable argument list<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fwprintf">wprintffwprintfswprintfwprintf_sfwprintf_sswprintf_ssnwprintf_s</a></p><p>(C95)(C95)(C95)(C11)(C11)(C11)(C11)</p></td><td>prints formatted wide character output to stdout, a file stream or a buffer<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/vfwprintf">vwprintfvfwprintfvswprintfvwprintf_svfwprintf_svswprintf_svsnwprintf_s</a></p><p>(C95)(C95)(C95)(C11)(C11)(C11)(C11)</p></td><td>prints formatted wide character output to stdout, a file stream<br>or a buffer using variable argument list<br>(function)</td></tr><tr><td colspan="2"><h5>File positioning</h5></td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/ftell">ftell</a></p></td><td>returns the current file position indicator<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fgetpos">fgetpos</a></p></td><td>gets the file position indicator<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fseek">fseek</a></p></td><td>moves the file position indicator to a specific location in a file<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/fsetpos">fsetpos</a></p></td><td>moves the file position indicator to a specific location in a file<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/rewind">rewind</a></p></td><td>moves the file position indicator to the beginning in a file<br>(function)</td></tr><tr><td colspan="2"><h5>Error handling</h5></td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/clearerr">clearerr</a></p></td><td>clears errors<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/feof">feof</a></p></td><td>checks for the end-of-file<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/ferror">ferror</a></p></td><td>checks for a file error<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/perror">perror</a></p></td><td>displays a character string corresponding of the current error to stderr<br>(function)</td></tr><tr><td colspan="2"><h5>Operations on files</h5></td></tr><tr><td colspan="2"></td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/remove">remove</a></p></td><td>erases a file<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/rename">rename</a></p></td><td>renames a file<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/tmpfile">tmpfiletmpfile_s</a></p><p>(C11)</p></td><td>returns a pointer to a temporary file<br>(function)</td></tr><tr><td><p><a href="https://en.cppreference.com/c/io/tmpnam">tmpnamtmpnam_s</a></p><p>(C11)</p></td><td>returns a unique filename<br>(function)</td></tr></tbody></table>

### Macro constants

<table><tbody><tr><td colspan="2"></td></tr><tr><td><p>EOF</p></td><td>integer constant expression of type<pre><code>int</code></pre>and negative value</td></tr><tr><td><p>FOPEN_MAX</p></td><td>maximum number of files that can be open simultaneously<br>(macro constant)</td></tr><tr><td><p>FILENAME_MAX</p></td><td>size needed for an array of<pre><code>char</code></pre>to hold the longest supported file name</td></tr></tbody></table>

| \_PRINTF\_NAN\_LEN\_MAX  (C23) | the maximum number of characters output for any (possibly negated) NaN value   (macro constant) |
| --- | --- |

| BUFSIZ | size of the buffer used by setbuf   (macro constant) |
| --- | --- |
| \_IOFBF\_IOLBF\_IONBF | indicates the buffering mode (fully buffered / line buffered / unbuffered) to be set by setvbuf   (macro constant) |
| SEEK\_SETSEEK\_CURSEEK\_END | indicates the offset origin (beginning / current position / end) to be used by fseek   (macro constant) |
| TMP\_MAXTMP\_MAX\_S  (C11) | maximum number of unique filenames that can be generated by tmpnam / tmpnam\_s   (macro constant) |
| L\_tmpnamL\_tmpnam\_s  (C11) | size needed for an array of ``` char ``` to hold the result of / |

### References

- C23 standard (ISO/IEC 9899:2024):

- 7.21 Input/output <stdio.h> (p: TBD)

- 7.29 Extended multibyte and wide character utilities <wchar.h> (p: TBD)

- 7.31.11 Input/output <stdio.h> (p: TBD)

- 7.31.16 Extended multibyte and wide character utilities <wchar.h> (p: TBD)

- K.3.5 Input/output <stdio.h> (p: TBD)

- C17 standard (ISO/IEC 9899:2018):

- 7.21 Input/output <stdio.h> (p: TBD)

- 7.29 Extended multibyte and wide character utilities <wchar.h> (p: TBD)

- 7.31.11 Input/output <stdio.h> (p: TBD)

- 7.31.16 Extended multibyte and wide character utilities <wchar.h> (p: TBD)

- K.3.5 Input/output <stdio.h> (p: TBD)

- C11 standard (ISO/IEC 9899:2011):

- 7.21 Input/output <stdio.h> (p: 296-339)

- 7.29 Extended multibyte and wide character utilities <wchar.h> (p: 402-446)

- 7.31.11 Input/output <stdio.h> (p: 456)

- 7.31.16 Extended multibyte and wide character utilities <wchar.h> (p: 456)

- K.3.5 Input/output <stdio.h> (p: 586-603)

- C99 standard (ISO/IEC 9899:1999):

- 7.19 Input/output <stdio.h> (p: 262-305)

- 7.24 Extended multibyte and wide character utilities <wchar.h> (p: 348-392)

- 7.26.12 Extended multibyte and wide character utilities <wchar.h> (p: 402)

- C89/C90 standard (ISO/IEC 9899:1990):

- 4.9 INPUT/OUTPUT <stdio.h>

### See also

[C++ documentation](https://en.cppreference.com/cpp/io/c "cpp/io/c") for C-style file input/output