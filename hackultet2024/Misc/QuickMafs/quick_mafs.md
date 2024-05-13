# Quick Mafs (60 points)

Straightforward task, we need to connect to a remote service and solve 100 math equations in 60 seconds.

This is the format of the tasks. The first line is always the same. After you enter the correct solution, it says `Točno` and gives you a new equation. The equations are of this format `int ( equation ) = ?`. The last line 2 lines give you the flag.

```text
Možeš li riješiti sljedećih 100 zadataka u 60 sekundi?
int( 66 - 4 + 7 * 2 / 2 * 4 ) = ?
```

Python script I cooked up.

```python
from sys import stdin, stdout

stdin.readline()

with open("results.txt", "a") as file:
    for line in stdin:
        file.write(line)
        if line.startswith("int"):
            result = str(int(eval(line[5:-7])))
            stdout.write(result)
            file.write(result + "\n")
            stdout.write("\n")
            stdout.flush()
```

and then pipe it into the challenge.

```sh
mknod bkpipe p
nc chal.hackultet.hr 13001 0<bkpipe | python3 main.py | tee bkpipe
```

Last 2 lines of `results.txt`:

```text
Uspješno riješeni svi zadatci, flag: CTF2024[144865892161]
Vrijeme potrebno za rješavanje  svih zadataka: 1.2556092739105225 sekundi
```
