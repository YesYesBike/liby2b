liby2b - Personal Library
=========================

## Introduction
This is the collection of macros and functions that I prefer to use.
Some of them are provided from other open source projects.


### How to use


## List

### Macro

#### ARGBEGIN/ARGEND
They are used to get option from ``argv``.

##### Usage
```c
int main(int argc, char *argv[])
{
    char *argv0 = "program";
    int aflag;

    ARGBEGIN {
        case 'a':
            aflag++;
            break;
        default:
            err_exit("Usage: %s [-a]\n", argv0);
    } ARGEND

    return 0;
}
```
##### Notice
They change the value of ``argc`` and ``argv``.

##### TODO
Add the feature to handle arguments of the option.


#### buf_clear()
It discards characters in ``stdin`` buffer. Use it instead of '``fflush(stdin)``'.

##### Usage
```c
int main(void)
{
    int a, b;

    printf("Enter the number: ");
    scanf("%d", &a);
    buf_clear();    /* prevent assigning b */

    printf("Enter the number: ");
    scanf("%d", &b);
    
    printf("%d + %d = %d\n", a, b, a+b);

    return 0;
}
```


### Error Function


#### err_exit()
It ``printf``s the message inside of parenthesis and ``exit(EXIT_FAILURE)``.

##### Synopsis
```c
void err_exit(char *fmt, ...)
```

##### Usage
```c
int main(void)
{
    int err_no = 404;
    char *err_msg = "Page Not Found";
    err_exit("%d: %s\n", err_no, err_msg);
}
```


### String Function


#### str_copy()
Work similar with ``strcpy_s``. It copies the null-terminated byte string from ``src`` to ``dst``.
Difference is the return value. It returns ``dst`` while ``strcpy_s`` returns error number.

##### Synopsis
```c
char *str_copy(char *restrict dst, size_t size, char *restrict src)
```

##### Usage
```c
#define SIZE 5

int main(void)
{
    char asdf[SIZE];
    char *str = "1234567890";

    puts(str_copy(asdf, SIZE, str));    /* 1234 */

    return 0;
}
```

##### Notice
Make sure them not overlapped.

##### Return Value
It returns ``dst``.
