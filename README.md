## Parallel Programing Codes
Implementing Tasks in OpenMP/MPI C++
The tasks are assignements for Parallel Programing Course in ITMO university.

#### Counting words in a line - OpenMp
The program aims to count words in a line. Any sequence of characters without separators is considered a word. Separators are spaces, tabs, newlines.

#### Finding the maximum value of a vector - OpenMp
The main goal of the program is to find the maximum value of a vector. In order to achieve that, I use the OpenMP reduction clause.
The program also studies the dependence of the runtime on the number of threads used (from 1 to 10)
for a vector that contains 1,000,000 elements.

#### Matrix multiplication - OpenMp
The program implements two dimension matrix multiplication with different loop orders.
For each loop order, the computation is done for one thread then for multiple threads
from 2 to 10. For each case the time of execution and the efficiency are measured. The
arrays are shared among threads, meanwhile the indices are private to prevent different
threads from editing them simultaneously.
