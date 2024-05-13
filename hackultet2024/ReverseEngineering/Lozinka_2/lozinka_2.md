# Lozinka 2 (70 points)

Similarly to the first one, we get a remote addres and a binary.

Dissasembling with Ghidra and looking at `main` we get:

```c
undefined8 main(void)

{
  size_t sVar1;
  undefined8 uVar2;
  FILE *__stream;
  long in_FS_OFFSET;
  int local_104;
  char local_f8 [112];
  char local_88 [104];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  puts("Lozinka: ");
  __isoc99_scanf(&DAT_0010200e,local_f8);
  sVar1 = strlen(local_f8);
  if (sVar1 < 6) {
    printf("Prekratak unos");
    uVar2 = 0xffffffff;
  }
  else {
    __stream = fopen("./flag.txt","r");
    fread(local_88,100,1,__stream);
    fclose(__stream);
    local_104 = 0;
    while( true ) {
      sVar1 = strlen(local_f8);
      if (sVar1 <= (ulong)(long)local_104) break;
      if (local_f8[local_104] != local_88[local_104]) {
        uVar2 = 0xffffffff;
        goto LAB_0010136d;
      }
      local_104 = local_104 + 1;
    }
    puts(local_88);
    uVar2 = 0;
  }
LAB_0010136d:
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}
```

This one is also pretty simple, but it REALLY confused me at first, so let's break this down.

1. store the user input into `local_f8` and it must be at least 6 characters long.
2. store the flag into `local_88`
3. `sVar1` is the length of our input
4. check if the length of the input is smaller than the counter `local_104` and if so then break and print the flag
5. check if input[i] == flag[i] and if not end the program
6. increment the counter

What we want to happen is described at step 4. In order to do this, first of all the input must be at least 6 chars long. Then, it needs to match the flag on every character (since the length of the password must be <= than the counter) so that the `if` at step 4 passes, and we break out of the loop. 

We know that the flag starts with `CTF202`, so we can enter this (or `CTF2024` or `CTF2024[`) as the password to get the flag.

```
nc chal.hackultet.hr 13013
Lozinka:
CTF202
CTF2024[131224316901]
```
