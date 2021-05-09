## Exercises

### 1-2.2

> Suppose we are comparing implementations of insertion sort and merge sort on the same machine. For inputs of size `n`, insertion sort runs in `8n^2` steps, while merge sort runs in `64nlgn`steps. For which values of n does insertion sort beat merge sort?

| N   | Insertion Sort | Merge Sort |     |
| --- | -------------- | ---------- | --- |
| 2   | 32             | 38.5       |
| 3   | 72             | 91.6       |
| 4   | 128            | 154.1      |
| 5   | 200            | 223.7      |
| 6   | 288            | 298.8      |
| 7   | 392            | 378.6      | 👈  |
| 8   | 512            | 462.4      |

### 1-2.3

> What is the smallest value of n such that an algorithm whose running time is `100n^2` runs faster than an algorithm whose running time is `2^n` on the same machine?

| N   | `100n^2` | `2^n`  |     |
| --- | -------- | ------ | --- |
| 1   | 100      | 2      |
| ... | ...      | ...    |
| 12  | 14400    | 4096   |
| 13  | 16900    | 8192   |
| 14  | 19600    | 16384  |
| 15  | 22500    | 32768  | 👈  |
| 16  | 25600    | 65536  |
| 17  | 28900    | 131072 |

---

## Problems

### 1-1 Comparison of running times

> For each function `f(n)` and time `t` in the following table, determine the largest size `n` of a problem that can be solved in time `t`, assuming that the algorithm to solve the problem takes `f(n)` microseconds.

For the sake of saving time, I set the limit as one hundred million, every number bigger than it shows as `inf`.

![Screenshot of Problem 1-1](https://i.imgur.com/BeDDMXH.png)
