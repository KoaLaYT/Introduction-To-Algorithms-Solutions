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

### 3.2-1

> Show that if `f(n)` and `g(n)` are monotonically increasing functions, then so are the functions `f(n) + g(n)` and `f(g(n))`, and if `f(n)` and `g(n)` are in addition nonnegative, then `f(n) * g(n)` is monotonically increasing.

<img src="https://imgur.com/5mXxWyU.png" alt="Screenshot of E3.2-1" width="50%" />

### 3.2-2

> Prove equation (3.16).

<img src="https://imgur.com/uPJrTdH.png" alt="Screenshot of E3.2-2" width="50%" />

### 3.2-3

> Prove equation (3.19). Also prove that `n! = ω(2^n)` and `n! = o(n^n)`.

Using the **Stirling’s approximation**, the result is fairly obvious.

<img src="https://imgur.com/q4qUzj4.png" alt="Screenshot of E3.2-3" width="50%" />

### 3.2-4

> Is the function `⎡lgn⎤!` polynomially bounded? Is the function `⎡lglgn⎤!` polynomially bounded?

I have no idea how to prove... See https://walkccc.me/CLRS/Chap03/3.2/.

### 3.2-5

> Which is asymptotically larger: `lg(lg*(n))` or `lg*(lgn)`?

See https://walkccc.me/CLRS/Chap03/3.2/.

### 3.2-6

> Show that the golden ratio and its conjugate both satisfy the equation `x2 = x + 1`.

<img src="https://imgur.com/HnDNl2f.png" alt="Screenshot of E3.2-6" width="50%" />

### 3.2-7

> Prove by induction that the `ith` Fibonacci number satisfies the equality:
>
> <img src="https://imgur.com/ISVWJAO.png" alt="Screenshot of E3.2-7#1" width="25%" />

<img src="https://imgur.com/fRZLSpr.png" alt="Screenshot of E3.2-7#2" width="50%" />

### 3.2-8

> Show that `klnk = Θ(n)` implies `k = Θ(n / ln(n))`.

See https://walkccc.me/CLRS/Chap03/3.2/.
