==6057== Memcheck, a memory error detector
==6057== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6057== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6057== Command: ./tp3 -t -s -i -d
==6057== Parent PID: 6040
==6057== 
==6057== Use of uninitialised value of size 8
==6057==    at 0x523496B: _itoa_word (_itoa.c:179)
==6057==    by 0x523800D: vfprintf (vfprintf.c:1642)
==6057==    by 0x5241015: printf (printf.c:33)
==6057==    by 0x109F10: printOptions (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==6057==    by 0x108D10: main (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==6057== 
==6057== Conditional jump or move depends on uninitialised value(s)
==6057==    at 0x5234975: _itoa_word (_itoa.c:179)
==6057==    by 0x523800D: vfprintf (vfprintf.c:1642)
==6057==    by 0x5241015: printf (printf.c:33)
==6057==    by 0x109F10: printOptions (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==6057==    by 0x108D10: main (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==6057== 
==6057== Conditional jump or move depends on uninitialised value(s)
==6057==    at 0x5238114: vfprintf (vfprintf.c:1642)
==6057==    by 0x5241015: printf (printf.c:33)
==6057==    by 0x109F10: printOptions (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==6057==    by 0x108D10: main (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==6057== 
==6057== Conditional jump or move depends on uninitialised value(s)
==6057==    at 0x5238C4C: vfprintf (vfprintf.c:1642)
==6057==    by 0x5241015: printf (printf.c:33)
==6057==    by 0x109F10: printOptions (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==6057==    by 0x108D10: main (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==6057== 
==6057== 
==6057== HEAP SUMMARY:
==6057==     in use at exit: 0 bytes in 0 blocks
==6057==   total heap usage: 13 allocs, 13 frees, 8,648 bytes allocated
==6057== 
==6057== All heap blocks were freed -- no leaks are possible
==6057== 
==6057== For counts of detected and suppressed errors, rerun with: -v
==6057== Use --track-origins=yes to see where uninitialised values come from
==6057== ERROR SUMMARY: 4 errors from 4 contexts (suppressed: 0 from 0)

```
