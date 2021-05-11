## Exercises

### 2-1.1

> Using Figure 2.2 as a model, illustrate the operation of INSERTION-SORT on the array `A = { 31, 41, 59, 26, 41, 58 }`.

![Screenshot of exercises 2-1.1](https://imgur.com/IpLRbre.png)

### 2.1-2

> Rewrite the INSERTION-SORT procedure to sort into nonincreasing instead of nondecreasing order.

```
INSERTION-SORT-NONINCREASING(A)
    for j = 2 to A.length
        key = A[j]
        i = j - 1
        while i > 0 and A[i] < key
            A[i + 1] = A[i]
            i = i - 1
        A[i + 1] = key
```

### 2.1-3

> Consider the searching problem:
>
> **Input:** A sequence of n numbers `A = { a1, a2, ..., an }` and a value `v`.
>
> **Output:** An index `i` such that `v = A[i]` or the special value `NIL` if `v` does not appear in A.
>
> Write pseudocode for **linear search**, which scans through the sequence, looking for `v`. Using a loop invariant, prove that your algorithm is correct. Make sure that your loop invariant fulfills the three necessary properties.

Pseudocode:

```
LINEAR-SEARCH(A, v)
    for i = 1 to A.length
        if A[i] == v
            return i
    return NIL
```

**Loop invariant:**

At the start of each iteration, the subarray `A[1..i-1]` does not contain the tagret value `v`. And when it ends, it returns either a valid index `i` or `NIL`.

**Initialization:**

When `i = 1`, there is no subarray, so it does not contain `v`.

**Maintenance:**

The loop will continue only if `A[i] != v`, which means no `v` in the subarray `A[1..i]`. So in the next iteration, the invariant still holds.

**Termination:**

There are two cases that can terminate the algorithm:

-   find a `i` that `v = A[i]`, which then returns this `i`
-   `i` larger than `A.length`, which then returns `NIL`

Both results hold the invariant.

### 2.1-4

> Consider the problem of adding two n-bit binary integers, stored in two n-element arrays A and B. The sum of the two integers should be stored in binary form in an (n + 1)-element array C . State the problem formally and write pseudocode for adding the two integers.

**Input:** two n element arrays A, B, which contains only 1 or 0.

**Output:** an (n + 1) element array.

pseudocode:

```
ADD-BINARY(A, B)
    C = array[n + 1]
    carry = 0
    for i = A.length to 1
        sum = A[i] + B[i] + carry
        C[i + 1] = sum % 2 // C is longer than A and B by 1
        carry = sum / 2
    C[1] = carry
    return C
```

### 2.2-1

> Express the function `n^3/1000 - 100n^2 - 100n + 3` in terms of `Θ`-notation.

`Θ(n^3)`

### 2.2-2

> Consider sorting `n` numbers stored in array A by first finding the smallest element of A and exchanging it with the element in `A[1]`. Then find the second smallest element of A, and exchange it with `A[2]`. Continue in this manner for the first `n - 1` elements of A. Write pseudocode for this algorithm, which is known as **selection sort**. What loop invariant does this algorithm maintain? Why does it need to run for only the first `n - 1` elements, rather than for all `n` elements? Give the best-case and worst-case running times of selection sort in `Θ`-notation.

Pseudocode:

```
SELECTION-SORT(A)
    for i = 1 to A.length - 1
        min = i
        for j = i + 1 to A.length
            if A[j] < A[min]
                min = j
        SWAP(A, i, min)

SWAP(A, i, j)
    if i != j
        tmp = A[i]
        A[i] = A[j]
        A[j] = tmp
```

**Loop invariant:**

At the start of every iteration, the subarray A[1..i-1] is sorted.

**Initialization:**

There is no subarray when `i = 1`.

**Maintenance:**

In each iteration, subarray `A[i..]`'s minimal value is found, and swaped to index `i`, so make the subarray `A[1..i]` sorted.

**Termination:**
Every element in subarray[1..A.length-1] is sorted, and `A[A.length]` will have the maximal value. So the entire array A is now sorted.

Both best case and worst case running time is `Θ(n^2)`. Because no matter what input it takes, it needs to scan the rest subarray in each iteration to find the new minimal value.

### 2.2-3

> Consider linear search again (see Exercise 2.1-3). How many elements of the input sequence need to be checked on the average, assuming that the element being searched for is equally likely to be any element in the array? How about in the worst case? What are the average-case and worst-case running times of linear search in `Θ`-notation? Justify your answers.

In average case, `n/2` elements need to be searched.

In worse case, `n` elements need to be searched.

So the running time of both are `Θ(n)`.

### 2.2-4

> How can we modify almost any algorithm to have a good best-case running time?

I guess we just can't.
