# Zmija (90 points)

We get a binary and we are told that this is a Python program.

Searching around the internet in order to find how to disassemble a Python program, I came across [pyxinstractor](https://github.com/extremecoders-re/pyinstxtractor), which can extract the contents of a PyInstaller generated executable.

Doing `grep "PYINSTALLER" zmija` we get a match, so lets try.

Running `python pyinstxtractor.py zmija` we extract the contents and we can see a `main.pyc` file which we can dissasemble with [pycdc](https://github.com/zrax/pycdc). 

After this, `./pycdc main.pyc` gives us
```text
# Source Generated with Decompyle++
# File: main.pyc (Python 3.10)

import sys
input_str = input()
flag = [
    4,
    1,
    5,
    8,
    9,
    3,
    7,
    2,
    6,
    7,
    8,
    2]
for i in range(0, len(flag)):
    if int(input_str[i]) != flag[i]:
        sys.exit(1)
print('CTF2024[', '', **('end',))
for i in flag:
    print(i, '', **('end',))
print(']')
```

So the flag is `CTF2024[415893726782]`
