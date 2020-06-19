# ft_Printf
Codam's [42 Network] write-your-own-printf Project
>int         ft_printf ( const char * str, ... );

## Format:

```bash
ft_printf("[%][flags][width][.precision][conversion]", arguments)
```

## Flags:

```bash
 # 0 - + space
```

**[-]**
>Left-justify within the given field width; 
>Right justification is the default (see width sub-specifier).

**[+]**
>Forces to preceed the result with a plus or minus sign ( + or - ) even for positive numbers. 
>By default, only negative numbers are preceded with a - sign.

**[(sp)]**
>If no sign is going to be written, a blank space is inserted before the value.

**[#]**
>Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero. 
>Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow. 
>By default, if no digits follow, no decimal point is written.

**[0]**
>Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).


## Width:

**[(number)]**
>Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.

**[*]**
>The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.


## Precision:

**[. (number)]**

'For (d, i, o, u, x, X) types'
>Precision specifies the minimum number of digits to be written. 
>If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. 

'For %s type:'
>This is the maximum number of characters to be printed. 
>By default all characters are printed until the ending null character is encountered.

For %c type:'
>It has no effect. When no precision is specified, the default is 1.
>If the period is specified without an explicit value for precision, 0 is assumed.

[. *]
> The precision is not specified in the format string, but as an additional argument (value int) preceding the argument that has to be formatted. 
>The result is padded with space characters (by default), if required, on the left when right-justified, or on the right if left-justified.



## Conversions:

```bash
sSpdDioOuUxXcCbneEfFgGaA
```

- c - Character
- s - String of Characters (null-terminated)
- d - Signed Decimal Number (base 10)
- i - Signed integer. (base 10)
- u - Unsigned Decimal Number (base 10)
- o - Signed Octal Number (base 8)
- x - Unsigned Hexadecimal (base 16)
- X - Caption Letters Hexadecimal (base 16)
- p - Pointer Address (base 16 - without ox)
- %% - Prints a literal % character (this type doesn't accept any flags, width, precision, length fields).

extra

f - Decimal Float Point



## Special Characters:

The following character sequences can be used for special formats (standard ASCII values):

- \a - audible alert
- \b - backspace
- \f - form feed
- \n - newline
- \r - carriage return
- \t - tab
- \v - vertical tab
- \\ - backslash


