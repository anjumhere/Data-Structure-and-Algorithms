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