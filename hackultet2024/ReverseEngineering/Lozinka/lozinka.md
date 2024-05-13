# Lozinka (50 points)

We are given a remote address which asks for a password and a binary file.

Using Ghidra to dissasemble the program, we see this in `main`:

```c
undefined8 main(void)

{
  long lVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  char cStack_e8;
  char cStack_e7;
  char cStack_e6;
  char cStack_e5;
  undefined auStack_78 [104];
  long lStack_10;
  
  lStack_10 = *(long *)(in_FS_OFFSET + 0x28);
  printf(&UNK_004b6004);
  fflush(stdout);
  __isoc99_scanf(&UNK_004b600e,&cStack_e8);
  lVar1 = strlen(&cStack_e8);
  if ((((lVar1 == 0x20) && (cStack_e8 == 'a')) && (cStack_e7 == 'G')) &&
     ((cStack_e6 == '8' && (cStack_e5 == '@')))) {
    uVar2 = fopen64(&UNK_004b6015,&UNK_004b6013);
    fread(auStack_78,100,1,uVar2);
    fclose(uVar2);
    puts(auStack_78);
    fflush(stdout);
  }
  if (lStack_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
```

And we see that we need to pass this if
```c
  if ((((lVar1 == 0x20) && (cStack_e8 == 'a')) && (cStack_e7 == 'G')) &&
     ((cStack_e6 == '8' && (cStack_e5 == '@')))) {
```
to get the flag, and also `lVar1 = strlen(&cStack_e8);`.

So the password we input needs to start with `aG8@` and be `0x20 = 32` characters long.

```sh
nc chal.hackultet.hr 13012
Lozinka: aG8@aaaaaaaaaaaaaaaaaaaaaaaaaaaa
CTF2024[348472324235]
```
