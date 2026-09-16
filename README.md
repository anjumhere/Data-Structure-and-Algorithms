# Data Structures & Algorithms — C++ Practice

Daily DSA practice written in C++, working through the Apna College DSA playlist.
The repo also includes a small Brick Breaker game built with [Raylib](https://www.raylib.com/)
as a side project.

## Topics covered

- **Math problems** — digit manipulation, palindromes, Armstrong numbers,
  divisors, prime checking, HCF/GCD, factorial and the nth Fibonacci number.
- **Recursion** — recursion theory with a call-stack walkthrough, number
  printing with backtracking, and a Fibonacci (in-progress) problem.
- **Patterns** — star-pyramid patterns with fully documented formula derivations.
- **Game** — a Breakout-style Brick Breaker written with Raylib.

## Repository layout

```
.
├── game/           # Brick Breaker (Raylib, C++)
├── math-problems/  # number theory + basic DSA math problems
├── patterns/       # star-pattern printing
├── recursion/      # recursion theory, basics and problems
└── README.md
```

## Game — Brick Breaker

`game/main.cpp` is a Breakout-style arcade game built on top of Raylib.

**Features**
- Paddle controlled with the **←** / **→** arrow keys.
- Ball with wall + paddle collision and bounce physics.
- A **5 × 13** grid of breakable bricks (ORANGE) — each hit destroys a brick and
  adds **+1** to the score.
- **GAME OVER** screen when the ball falls past the bottom.
- Press **R** to restart: resets paddle, ball and score, and revives every brick.

**Build & run** (requires Raylib headers + `libraylib`):

```bash
g++ -std=c++17 game/main.cpp -lraylib -o game/brickbreaker
./game/brickbreaker
```

## Recursion

Each file is a self-contained program. Run one with:

```bash
g++ -std=c++17 recursion/pb01.cpp -o pb01 && ./pb01
```

| File        | Problem |
|-------------|---------|
| `basics.cpp` | Recursion theory: the two essential parts (base case + recursive case) and an ASCII call-stack diagram showing how each recursive call is pushed and popped. |
| `pb01.cpp`   | Print `"Hi"` n times using recursion — includes a full trace of `printHi(i, n)` for `n = 3`. |
| `pb02.cpp`   | Build an array of the first n Fibonacci numbers recursively (in progress). |
| `pb03.cpp`   | Number printing variants: print `n → 1`, print `1 → n` using backtracking, and print `n → 1` using backtracking. |

## Math Problems

Two sub-folders hold number-theory problems and basic math DSA exercises.

### `math-problems/problems.cpp`

A single file hosting several problems, each with a documented approach:

| # | Problem | Approach |
|---|---------|----------|
| 1a | Reverse an integer using a vector | Extract digits with `% 10`, push into a vector, drop with `/ 10`. |
| 1b | Count the digits of an integer | Same loop, `vec.size()` (or `log10(n) + 1`). |
| 3  | Reverse a number without a container | Rebuild digit-by-digit: `num = num * 10 + last`. |
| 4  | Palindrome check | Compare number with its reversed value. |
| 5  | Armstrong number check | Sum each digit raised to the digit count; uses `int64_t` to avoid overflow. |
| 6  | List all divisors | Loop `1..n`, mark each `n % i == 0`. |
| 7  | Prime number check | Trial division up to `sqrt(n)`. |
| 8  | HCF / GCD | Loop down from `min(n1, n2)` plus `std::gcd`. |

### `math-problems/dsa/`

| File | Problem |
|------|---------|
| `dsa.cpp`        | nth Fibonacci number (iterative, `O(n)`). |
| `factorial.cpp`  | Factorial of a number read from input. |
| `quadratic-eq.cpp` | Roots of `ax² + bx + c = 0` (GeeksforGeeks-style problem; returns `-1` for imaginary roots). |

## Patterns

`patterns/patterns.cpp` implements three star patterns in a single file, each
with a fully derived formula (spaces, stars, trailing spaces):

| Function | Pattern |
|----------|---------|
| `pat1(n)` | Pyramid — increasing odd star counts, `spaces = n - i - 1`, `stars = 2*i + 1`. |
| `pat2(n)` | Inverted pyramid — decreasing odd star counts, `stars = 2*n - 2*i - 1`. |
| `pat3(n)` | Diamond — `pat1` stacked directly on top of `pat2`. |

## Compiling any `.cpp`

Every problem file is standalone; compile and run with:

```bash
g++ -std=c++17 path/to/file.cpp -o out && ./out
```

## Progress

| Topic            | Status |
|------------------|--------|
| Math problems    | ✅ Done |
| Recursion        | 🔄 In progress (`pb02` incomplete) |
| Patterns         | ✅ Done |
| Brick Breaker game | ✅ Done |