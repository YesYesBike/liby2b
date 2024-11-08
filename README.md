liby2b - Personal Library
=========================

## Introduction
This is the collection of macros and functions that I prefer to use.
Some of them are provided from other open source projects.


### How to use
``make`` in the shell and include ``liby2b.a`` and ``liby2b.h`` on your code.


## Notice
* ``argv0`` is a global variable that indicates ``argv[0][0]``.
``ARGBEGIN`` macro sets ``argv0`` to the name of the program.

## List

### Macro

#### ARGBEGIN/ARGEND/ARGC()/ARGF()
They are used to get options from ``argv``.
Options end after an argument ``−−``, before an argument ``−``,
or before an argument that doesn’t begin with ``−``. 
ARGC() is the current option character.
ARGF() is the current option argument.

##### Usage
```c
int main(int argc, char *argv[])
{
    int aflag;
	char *b_arg;

    ARGBEGIN {
        case 'a':
            aflag++;
            break;
        case 'b':
			if ((b_arg = ARGF()) == NULL)
				err_exit("-b needs the arguements\n");

            printf("Arg: %s\n", b_arg);
            break;
        default:
			printf("'-%c': unknown option\n", ARGC());
            err_exit("Usage: %s [-a] [-b arg]\n", argv0);
    } ARGEND

    return 0;
}
```
##### Notice
They change the value of ``argc`` and ``argv``.
Use ``ARGF()`` once for each option.


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

#### nelen()
Returns the count of elements in the array.

##### Usage
```c
int main(void)
{
	char asdf[SIZE];
	
	printf("%d\n", nelem(asdf));	/* SIZE */

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
Difference is the return value. It returns ``dst`` while ``strcpy_s`` returns an error number.

##### Synopsis
```c
char *str_copy(char *restrict dst, size_t size, const char *restrict src)
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
