==5836== Memcheck, a memory error detector
==5836== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==5836== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==5836== Command: ./tp3 -t -s -i -d
==5836== Parent PID: 5819
==5836== 
==5836== Use of uninitialised value of size 8
==5836==    at 0x523496B: _itoa_word (_itoa.c:179)
==5836==    by 0x523800D: vfprintf (vfprintf.c:1642)
==5836==    by 0x5241015: printf (printf.c:33)
==5836==    by 0x109F10: printOptions (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==5836==    by 0x108D10: main (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==5836== 
==5836== Conditional jump or move depends on uninitialised value(s)
==5836==    at 0x5234975: _itoa_word (_itoa.c:179)
==5836==    by 0x523800D: vfprintf (vfprintf.c:1642)
==5836==    by 0x5241015: printf (printf.c:33)
==5836==    by 0x109F10: printOptions (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==5836==    by 0x108D10: main (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==5836== 
==5836== Conditional jump or move depends on uninitialised value(s)
==5836==    at 0x5238114: vfprintf (vfprintf.c:1642)
==5836==    by 0x5241015: printf (printf.c:33)
==5836==    by 0x109F10: printOptions (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==5836==    by 0x108D10: main (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==5836== 
==5836== Conditional jump or move depends on uninitialised value(s)
==5836==    at 0x5238C4C: vfprintf (vfprintf.c:1642)
==5836==    by 0x5241015: printf (printf.c:33)
==5836==    by 0x109F10: printOptions (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==5836==    by 0x108D10: main (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==5836== 
==5836== 
==5836== HEAP SUMMARY:
==5836==     in use at exit: 0 bytes in 0 blocks
==5836==   total heap usage: 13 allocs, 13 frees, 8,648 bytes allocated
==5836== 
==5836== All heap blocks were freed -- no leaks are possible
==5836== 
==5836== For counts of detected and suppressed errors, rerun with: -v
==5836== Use --track-origins=yes to see where uninitialised values come from
==5836== ERROR SUMMARY: 4 errors from 4 contexts (suppressed: 0 from 0)

```
