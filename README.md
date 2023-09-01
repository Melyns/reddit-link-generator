# reddit-link-generator
A simple program that generates purely random reddit short URLs. (Yes most of them redirect to a real post.)

# Usage:
```
reddit-link-generator.exe N
```
Where N represents the number of links you want to generate.

# Modes:
The script has four modes which can be called with a flag `-m` followed by mode number. By default, mode 1 is selected if the user doesn't explicitly use the `-m` flag.

- Mode 1: string with lower case charachters only. `-m1`
- Mode 2: string with one number at the beggining, and rest is lower case charachters. `-m2`
- Mode 3: string with 10 or 11 at the beggining, and rest is lower case charachters. `-m3`
- Mode 4: string with numbers only. `-m4`

# Outputs:

```
reddit-link-generator.exe 5
https://reddit.com/cexhlg
https://reddit.com/xmsdbl
https://reddit.com/bknbaj
https://reddit.com/iwkxfp
https://reddit.com/edwmlb
```

```
reddit-link-generator.exe 5 -m3
https://reddit.com/10pxrv
https://reddit.com/11koah
https://reddit.com/10uwie
https://reddit.com/11bbhs
https://reddit.com/11vjaa
```
