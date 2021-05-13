## Exercises

### 3.1-1

> Let `f(n)` and `g(n)` be asymptotically nonnegative functions. Using the basic definition of Θ-notation, prove that `max(f(n), g(n)) = Θ(f(n) + g(n))`.

<img src="https://imgur.com/t8bN5Ty.png" alt="Screenshot of E3.1-1" width="50%" />

### 3.1-2

> Show that for any real constants `a` and `b`, where `b > 0`, that`(n + a)^b = Θ(n^b)`.

<img src="https://imgur.com/BqTFXe3.png" alt="Screenshot of E3.1-2" width="50%" />

### 3.1-3

> Explain why the statement, “The running time of algorithm A is at least `O(n^2)`” is meaningless.

Because this statement does not tell:

-   upper bound.
-   `O(n^2)` meanings any function smaller than `n^2`, so no lower bound either.

So it just says nothing about running time of algorithm A.

### 3.1-4

> Is `2^(n+1) = O(2^n)`? Is `2^(2n) = O(2^n)`?

It's easy to use the defination of big O notation to prove that:

`2^(n+1) = O(2^n)`

`2^(2n) != O(2^n)`

### 3.1-5

> Prove Theorem 3.1.

<img src="https://imgur.com/JhqACFP.png" alt="Screenshot of E3.1-5" width="50%" />

### 3.1-6

> Prove that the running time of an algorithm is `Θ(g(n))` if and only if its worst case running time is `O(g(n))` and its best case running time is `Ω(g(n))`.

Using the defination of these three asymptotic notations can easily prove. I'll just omit it. For complete prove, see https://walkccc.me/CLRS/Chap03/3.1/.

### 3.1-7

> Prove that `o(g(n)) ∩ ω(g(n))` is the empty set.

Same as 3.1-6. See https://walkccc.me/CLRS/Chap03/3.1/.

### 3.1-8

> We can extend our notation to the case of two parameters `n` and `m` that can go to infinity independently at different rates. For a given function `g(n, m)`, we denote by `O(g(n, m))` the set of functions
>
> <img src="https://imgur.com/Go8lpYY.png" alt="Screenshot of E3.1-8#1" width="50%" />
>
> Give corresponding definitions for `Ω(g(n, m))` and `Θ(g(n, m))`.

<img src="https://imgur.com/vXCNnaq.png" alt="Screenshot of E3.1-8#2" width="50%" />
