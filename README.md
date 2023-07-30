# bits
for flags

This header file released for helps use 8 flags in one char variable instead of 8 bool variables.
- You can use 1+ byte decimal types.
- You can use _nt_macro to avoid type casts.

**Do not use bool to save flags inside!**

[EXAMPLE] [NO TYPE CASTS]
```
...
char flags;
_nt_setbit(&flags, 0, 0b1);
if(_nt_getbit(f,0)) doSomething;
...
```
[EXAMPLE] [NO TYPE CASTS]
```
...
long long flags;
#define setFlag(a) _nt_setbit(&flags,3,a)
#define isFlag     _nt_getbit(f,3)
setFlag(1);
if(isFlag) doSomething;
...
```
[EXAMPLE] [TYPE CASTS]
```
...
char flags;
setbit( (lint*) &flags, 0, 0b1);
if(getbit( (lint) flags, 0)) doSomething;
...
```
[EXAMPLE] [TYPE CASTS]
```
...
int flags;
#define setFlag(a) setbit( (lint*) &flags,3,a)
#define isFlag     getbit( (lint) f,3)
setFlag(1);
if(isFlag) doSomething;
...
```
