## Exercises

### 2.1-1

> Using Figure 2.2 as a model, illustrate the operation of INSERTION-SORT on the array `A = { 31, 41, 59, 26, 41, 58 }`.

<img src="https://imgur.com/IpLRbre.png" alt="Screenshot of exercises 2-1.1" width="50%" />

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

### 2.3-1

> Using Figure 2.4 as a model, illustrate the operation of merge sort on the array `A = { 3, 41, 52, 26, 38, 57, 9, 49 }`.

<img src="https://imgur.com/hrKncTm.png" alt="Screenshot of E2.3-1" width="50%" />

### 2.3-2

> Rewrite the `MERGE` procedure so that it does not use sentinels, instead stopping once either array L or R has had all its elements copied back to A and then copying the remainder of the other array back into A.

```
MERGE(A, p, q, r)
    n1 = q - p + 1;
    n2 = r - q;
    let L[1..n1] and R[1..n2] be new arrays
    for i = 1 to n1
        L[i] = A[p + i - 1]
    for j = 1 to n2
        R[i] = A[q + j]
    i = 1
    j = 1
    for k = p to r
        if i > n1
            A[k] = R[j]
            j = j + 1
        else if j > n2
            A[k] = L[i]
            i = i + 1
        else if L[i] <= R[j]
            A[k] = L[i]
            i = i + 1
        else
            A[k] = R[j]
            j = j + 1
```

### 2.3-3

> Use mathematical induction to show that when `n` is an exact power of 2, the solution of the recurrence is `T(n) = nlgn`.
> <img src="https://imgur.com/RpluKr3.png" alt="Screenshot of E2.3-3#1" width="50%" />

<img src="https://imgur.com/IwLJl75.png" alt="Screenshot of E2.3-3#2" width="50%" />

### 2.3-4

> We can express insertion sort as a recursive procedure as follows. In order to sort `A[1..n]`, we recursively sort `A[1..n-1]` and then insert `A[n]` into the sorted array `A[1..n-1]`. Write a recurrence for the running time of this recursive version of insertion sort.

<img src="https://imgur.com/LBwopTD.png" alt="Screenshot of E2.3-4" width="50%" />

### 2.3.5

> Referring back to the searching problem (see Exercise 2.1-3), observe that if the sequence A is sorted, we can check the midpoint of the sequence against `v` and eliminate half of the sequence from further consideration. The binary search algorithm repeats this procedure, halving the size of the remaining portion of the sequence each time. Write pseudocode, either iterative or recursive, for binary search. Argue that the worst case running time of binary search is `Θ(lgn)`.

Pseudocode:

```
BINARY-SEARCH(A, v, lo, hi)
    if (lo > hi)
        return NIL
    mi = lo + (hi - lo) / 2
    if (A[mi] < v)
        return BINARY-SEARCH(A, v, mi + 1, hi)
    else if (A[mi] > v)
        return BINARY-SEARCH(A, v, lo, mi - 1)
    else
        return mi
```

### 2.3-6

> Observe that the while loop of lines 5–7 of the INSERTION-SORT procedure in Section 2.1 uses a linear search to scan (backward) through the sorted subarray `A[1..j-1]`. Can we use a binary search (see Exercise 2.3-5) instead to improve the overall worst case running time of insertion sort to `Θ(nlgn)`?

No. In each iteration, we can use binary search to find the right slot in `Θ(lgn)`, but to actually insert it, we still need to move `n` elements in worse case which takes `Θ(n)` time. So the total running time is still `Θ(n^2)` in worst case.

### 2.3-7

> Describe a `Θ(nlgn)` time algorithm that, given a set S of `n` integers and another integer `x`, determines whether or not there exist two elements in S whose sum is exactly `x`.

1. Sort the given S, takes `Θ(nlgn)`.
2. Iterate every element in sorted S, using binary search to find the element `x - S[i]`. Each iteration takes `Θ(lgn)`, so in worst case will take `Θ(nlgn)`.

So the overall running time in worst case is `Θ(nlgn)`.

---

## Problems

### 2.1 Insertion sort on small arrays in merge sort

> Although merge sort runs in `Θ(nlgn)` worst case time and insertion sort runs in `Θ(n^2)` worst case time, the constant factors in insertion sort can make it faster in practice for small problem sizes on many machines. Thus, it makes sense to **coarsen** the leaves of the recursion by using insertion sort within merge sort when subproblems become sufficiently small. Consider a modification to merge sort in which `n/k` sublists of length `k` are sorted using insertion sort and then merged using the standard merging mechanism, where `k` is a value to be determined.
>
> a. Show that insertion sort can sort the `n/k` sublists, each of length `k`, in `Θ(nk)` worst case time.
>
> b. Show how to merge the sublists in `Θ(nlg(n/k))` worst case time.
>
> c. Given that the modified algorithm runs in `Θ(nk + nlg(n/k))` worst case time, what is the largest value of `k` as a function of `n` for which the modified algorithm has the same running time as standard merge sort, in terms of Θ-notation?
>
> d. How should we choose `k` in practice?

a. Insertion sort's running time is `Θ(k^2)` for length `k`, so for `n/k` lists, the total running time is `Θ(k^2 * n / k) = Θ(nk)`.

b. Each leaf has `k` element, so the depth is `2^d * k = n => d = lg(n/k)`. And on each level of depth it takes `Θ(n)` to do the merge. So the total running time is `Θ(nlg(n/k))`.

c. `k = Θ(lgn)` according to https://walkccc.me/CLRS/Chap02/Problems/2-1/

d. The largest `k` which insertion sort is faster.

### 2.2 Correctness of bubblesort

> Bubblesort is a popular, but inefficient, sorting algorithm. It works by repeatedly swapping adjacent elements that are out of order.
>
> ```
> BUBBLESORT(A)
>   for i = 1 to A.length - 1
>       for j = A.length downto i + 1
>           if A[j] < A[j - 1]
>               exchange A[j] with A[j - 1]
> ```
>
> a. Let `A'` denote the output of `BUBBLESORT(A)`. To prove that `BUBBLESORT` is correct, we need to prove that it terminates and that
>
> `A'[1] <= A'[2] <= ... <= A'[n]`, where `n = A.length`.
>
> In order to show that `BUBBLESORT` actually sorts, what else do we need to prove?
>
> b. State precisely a loop invariant for the for loop in lines 2–4, and prove that this loop invariant holds. Your proof should use the structure of the loop invariant proof presented in this chapter.
>
> c. Using the termination condition of the loop invariant proved in part (b), state a loop invariant for the for loop in lines 1–4 that will allow you to prove inequality in part (a). Your proof should use the structure of the loop invariant proof presented in this chapter.
>
> d. What is the worst case running time of bubblesort? How does it compare to the running time of insertion sort?

a. We need to prove `A'` contians exact elements as in `A`, but is in sorted order.

b. **Loop invariant:** At start of each iteration, subarray A[j..A.length] has exact same element as before, but with smallest element at A[j].

**Initialization:** Subarray has only one element. So invariant holds.

c**Maintenance:** Each iteration will exchange the smaller element to `A[j]`. So invariant holds.

**Termination:** When loop end, the smallest element has been exchanged to `A[i]` which holds the invariant.

c. **Loop invariant:** At start of each iteration, subarray `A[1..i-1]` contains `i - 1` smallest elements in Array `A` and is in sorted order.

**Initialization:** Subarray is empty.

**Maintenance:** According to part (b), the smallest element among `A[i..]` will be put into `A[i]`, so the invariant holds.

**Termination:** When loop end, all elements will be in sorted order.

d. Both have `Θ(n^2)` worst case running time.

### 2-3 Correctness of Horner’s rule

> The following code fragment implements Horner’s rule for evaluating a polynomial.
>
> <img src="https://imgur.com/MSo1uTk.png" alt="Screenshot of P2.3#1" width="50%" />
>
> given the coefficients `a0, a1, ..., an` and a value for `x`:
>
> ```
> y = 0
> for i = n downto 0
>   y = ai + x * y
> ```
>
> a. In terms of Θ-notation, what is the running time of this code fragment for Horner’s rule?
>
> b. Write pseudocode to implement the naive polynomial-evaluation algorithm that computes each term of the polynomial from scratch. What is the running time of this algorithm? How does it compare to Horner’s rule?
>
> c. Consider the following loop invariant:
>
> At the start of each iteration of the for loop,
>
> <img src="https://imgur.com/eYfCGIB.png" alt="Screenshot of P2.3#2" width="25%" />
>
> Interpret a summation with no terms as equaling `0`. Following the structure of the loop invariant proof presented in this chapter, use this loop invariant to show that, at termination, `y = P(x)`.
>
> d. Conclude by arguing that the given code fragment correctly evaluates a polynomial characterized by the coefficients `a0, a1, ..., an`.

a. `Θ(n)`

b. Pseudocode:

```
NAIVE-POLYNOMIAL-EVALUATION(x)
    y = 0
    for i = 0 to n
        y = y + a[i] * POW(x, i)
    return y

POW(x, i)
    mul = 1
    while i > 0
        mul = mul * x
        i = i - 1
    return mul
```

Running time is `Θ(n^2)`, because of nest loop.

c.**Initialization:**

`i = n => y = 0`

**Maintenance:**

<img src="https://imgur.com/mbLi7Rx.png" alt="Screenshot of P2.3" width="50%" />

**Termination:**

`i = -1 => y = P(x)`

### 2-4 Inversions

> Let `A[1..n]` be an array of `n` distinct numbers. If `i < j` and `A[i] > A[j]`, then the pair `(i, j)` is called an **inversion** of A.
>
> a. List the five inversions of the array `{ 2, 3, 8, 6, 1 }`.
>
> b. What array with elements from the set `{ 1, 2, ..., n }` has the most inversions? How many does it have?
>
> c. What is the relationship between the running time of insertion sort and the number of inversions in the input array? Justify your answer.
>
> d. Give an algorithm that determines the number of inversions in any permutation on `n` elements in `Θ(nlgn)` worst case time. (Hint: Modify merge sort.)

a. `(1, 5)`, `(2, 5)`, `(3, 4)`, `(3, 5)`, `(4, 5)`

b. A decreasingly ordered array has the most inversions which equals `n(n-1)/2`

c. If an array has `k` inversions, then the running time of insertion sort is `Θ(k)`.

d. When do merge sort, we keep counting inversions along the way. Pseudocode:

```
COUNT-INVERSIONS(A, lo, hi)
    if lo >= hi
        return 0
    mi = lo + (hi - lo) / 2
    left = COUNT-INVERSIONS(A, lo, mi)
    right = COUNT-INVERSIONS(A, mi + 1, hi)
    return MERGE(A, lo, mi, hi) + left + right

MERGE(A, lo, mi, hi)
    n1 = mi - lo + 1
    n2 = hi - mi
    let L[n1 + 1] and R[n2 + 1] be new array
    for i = 1 to n1
        L[i] = A[lo + i - 1]
    for j = 1 to n2
        R[j] = A[mi + j]
    L[n1 + 1] = ∞
    R[n2 + 1] = ∞
    i = 1
    j = 1
    count = 0
    for k = lo to hi
        if L[i] < R[j]
            A[k] = L[i]
            i = i + 1
        else
            count = count + n1 - i + 1
            A[k] = R[j]
            j = j + 1
    return count
```
