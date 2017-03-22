Gprof:
Flat profile:

Each sample counts as 0.01 seconds.

 % time  | cumulative seconds | self seconds  |  calls | self s/call | total s/call | name  
--------- | --------- | --------- | --------- | --------- | --------- | ---------
  93.03 |    624.35 |   624.35 | 3140225889 |     0.00 |     0.00 |  cmpStr
   4.23 |    652.73 |    28.38 |        1 |    28.38 |   178.65 |  sort_bubble
   1.50 |    662.83 |    10.10 | 2432268473 |     0.00 |     0.00 |  swap
   1.14 |    670.46 |     7.62 |        1 |     7.62 |   491.11 |  sort_insert
   0.16 |    671.50 |     1.05 |                             main
   0.10 |    672.14 |     0.64 |        1 |     0.64 |     1.04 |  sort_quick
   0.02 |    672.28 |     0.14 |        4 |     0.03 |     0.03 |  arr_copy
   0.01 |    672.37 |     0.09 |        1 |     0.09 |     0.09 |  arr_read
   0.00 |    672.38 |     0.01 |    99999 |     0.00 |     0.00 |  merge
   0.00 |    672.39 |     0.01 |        1 |     0.01 |     0.01 |  arr_print
   0.00 |    672.39 |     0.00 |    72966 |     0.00 |     0.00 |  getMedian
   0.00 |    672.39 |     0.00 |        5 |     0.00 |     0.00 |  arr_clean
   0.00 |    672.39 |     0.00 |        1 |     0.00 |     0.31 |  sort_merge



	Call graph
	
granularity: each sample hit covers 2 byte(s) for 0.00% of 672.39 seconds

index | % time  |  self | children  |  called   |  name <spontaneous>
--------- | --------- | --------- | --------- | --------- | -----------                                             											 
[1] |    100.0 |    1.05 |  671.34 |        - |        main [1]
 |             |   7.62 |  483.49 |       1/1 |           sort_insert [3]
 |             |  28.38 |  150.26 |       1/1 |           sort_bubble [4]
 |             |   0.64 |    0.40 |       1/1 |           sort_quick [6]
 |             |   0.00 |    0.31 |       1/1 |           sort_merge [8]
 |             |   0.14 |    0.00 |       4/4 |           arr_copy [9]
 |             |   0.09 |    0.00 |       1/1 |           arr_read [10]
 |            |    0.01 |    0.00 |       1/1 |           arr_print [12]
 |            |    0.00 |    0.00 |       5/5 |           arr_clean [13]
 |            |    0.03 |    0.00 |  149418/3140225889 |     getMedian [11]
 |            |    0.30 |    0.00 | 1507340/3140225889 |     merge [7]
 |            |    0.36 |    0.00 | 1833039/3140225889 |     sort_quick [6]
 |            |  140.17 |    0.00 | 704982704/3140225889 |     sort_bubble [4]
 |           |   483.49 |    0.00 | 2431753388/3140225889 |     sort_insert [3]
[2] |     92.9 |  624.35 |    0.00 | 3140225889 |         cmpStr [2]
 |                7.62 |  483.49 |       1/1 |           main [1]
[3] |     73.0 |    7.62 |  483.49 |       1 |         sort_insert [3]
 |              483.49 |    0.00 | 2431753388/3140225889 |     cmpStr [2]
 |               28.38 |  150.26 |       1/1 |           main [1]
[4] |     26.6 |   28.38 |  150.26 |       1 |         sort_bubble [4]
 |          |    140.17 |    0.00 | 704982704/3140225889 |     cmpStr [2]
 |          |     10.10 |    0.00 | 2431653390/2432268473 |     swap [5]
 |          |      0.00 |    0.00 |   16053/2432268473 |     merge [7]
 |          |      0.00 |    0.00 |  599030/2432268473 |     sort_quick [6]
 |          |     10.10 |    0.00 | 2431653390/2432268473 |     sort_bubble [4]
[5] |      1.5 |   10.10 |    0.00 | 2432268473 |         swap [5]
 |          |    | |                 72965 |             sort_quick [6]
 |                0.64 |    0.40 |       1/1 |           main [1]
[6] |      0.2 |    0.64 |    0.40 |       1+72965 |   sort_quick [6]
 |         |       0.36 |    0.00 | 1833039/3140225889 |     cmpStr [2]
 |         |       0.00 |    0.03 |   72966/72966 |       getMedian [11]
 |         |       0.00 |    0.00 |  599030/2432268473 |     swap [5]
 |         |      | |                72965 |             sort_quick [6]
 |         |       0.01 |    0.30 |   99999/99999 |       sort_merge [8]
[7] |      0.0 |    0.01 |    0.30 |   99999 |         merge [7]
 |         |       0.30 |    0.00 | 1507340/3140225889 |     cmpStr [2]
 |         |       0.00 |    0.00 |   16053/2432268473 |     swap [5]
 |         |       |             | 199998 |             sort_merge [8]
 |         |       0.00 |    0.31 |       1/1 |           main [1]
[8] |      0.0 |    0.00 |    0.31 |       1+199998 |  sort_merge [8]
 |         |       0.01 |    0.30 |   99999/99999 |       merge [7]
 |         |       | |              199998 |             sort_merge [8]
 |         |       0.14 |    0.00 |       4/4 |           main [1]
[9] |      0.0 |    0.14 |    0.00 |       4 |         arr_copy [9]
 |         |       0.09 |    0.00 |       1/1 |           main [1]
[10] |     0.0 |    0.09 |    0.00 |       1 |         arr_read [10]
 |         |       0.00 |    0.03 |   72966/72966 |       sort_quick [6]
[11] |     0.0 |    0.00 |    0.03 |   72966 |         getMedian [11]
 |         |      0.03 |    0.00 |  149418/3140225889 |     cmpStr [2]
 |         |       0.01 |    0.00 |       1/1 |           main [1]
[12] |     0.0 |    0.01 |    0.00 |       1 |         arr_print [12]
 |         |       0.00 |    0.00 |       5/5 |           main [1]
[13] |     0.0 |    0.00 |    0.00 |       5 |         arr_clean [13]

Index | by function name
------ | ------
   [13] | arr_clean               
   [11] | getMedian                
   [8] | sort_merge
    [9] | arr_copy                
	[1] | main                    
	[6] | sort_quick
   [12] | arr_print                
   [7] | merge                    
   [5] | swap
   [10] | arr_read                 
   [4] | sort_bubble
    [2] | cmpStr                 
	[3] | sort_insert



VALGRIND: | _
--------- | --------------
==14129== | Memcheck, a memory error detector
==14129== | Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==14129== | Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==14129== | Command: ./SortProga notice_ath10k_firmware-5.txt 1000
==14129== | Parent PID: 13408
==14129== | 
==14129== | 
==14129== | HEAP SUMMARY:
==14129== |     in use at exit: 0 bytes in 0 blocks
==14129== |   total heap usage: 5,776 allocs, 5,776 frees, 329,093 bytes allocated
==14129== | 
==14129== | All heap blocks were freed -- no leaks are possible
==14129== | 
==14129== | For counts of detected and suppressed errors, rerun with: -v
==14129== | ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
