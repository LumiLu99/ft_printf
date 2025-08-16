# ft_printf
This project implements a simplified version of ```printf``` called ```ft_printf```. 

It handles a variety of format specifiers and writes formatted output to the standard output (stdout).

### Supported format specifiers
- ```%c``` → Character. Prints a single character.

- ```%s``` → String. Prints a string.

- ```%p``` → Pointer address (in hexadecimal). Prints a pointer address.

- ```%d``` / %i → Signed decimal integer. Prints integers.

- ```%u``` → Unsigned decimal integer. Prints non-negative integers.

- ```%x``` → Unsigned hexadecimal (lowercase). Prints hexadecimals in lowercase only.

- %X → Unsigned hexadecimal (uppercase). Prints hexadecimals in uppercase only.

  ## Usage
  Clone the repository and compile:
  ```
  https://github.com/LumiLu99/ft_printf.git
  ```
  ```
  make
  ```

Example:
```
int main()
{
    int len1, len2;

    len1 = ft_printf("%x\n", 666666);
    ft_printf("ft_printf len: %d\n", len1);
}
```
Output:
```
a2e8a
ft_printf len: 5
```


