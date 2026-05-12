# Header Files

```cpp id="e2v7i0"
#include<iostream>
```

Used for:

* input (`cin`)
* output (`cout`)

---

```cpp id="el4n4s"
#include<cmath>
```

Used for:

* `abs()` function

---

```cpp id="q84b4f"
#include<limits.h>
```

Used for:

* `INT_MAX`

---

# Namespace

```cpp id="gg4hyy"
using namespace std;
```

Allows using:

* `cout`
* `cin`
* `swap`

without writing `std::`

---

# Global Variable

```cpp id="m6sh16"
int g = 0;
```

Stores:

* number of moves made
* path cost in heuristic

---

# Print Function

```cpp id="5r4j8z"
void Print(int puzzle[])
```

Prints the 8-puzzle board.

---

```cpp id="fzyrbh"
for(int i = 0; i < 9; i++)
```

Loops through all 9 positions.

---

```cpp id="t1i0p0"
if(i % 3 == 0) cout << '\n';
```

Starts a new row every 3 elements.

Example:

```text id="rj6x89"
0 1 2
3 4 5
6 7 8
```

---

```cpp id="kqkqv9"
if(puzzle[i] == -1) cout << "_ ";
```

Prints `_` for empty tile.

---

```cpp id="9qu7qg"
else cout << puzzle[i] << " ";
```

Prints tile number.

---

# Move Functions

---

## moveLeft()

```cpp id="qbypp8"
void moveLeft(int start[], int position)
```

Moves empty tile left.

---

```cpp id="v85od2"
swap(start[position], start[position - 1]);
```

Swaps:

* empty tile
* left tile

---

# moveRight()

```cpp id="kml3hn"
swap(start[position], start[position + 1]);
```

Moves empty tile right.

---

# moveUp()

```cpp id="px92qt"
swap(start[position], start[position - 3]);
```

Moves empty tile up.

Why `-3`?

Because puzzle is 3×3.

---

# moveDown()

```cpp id="aehg3t"
swap(start[position], start[position + 3]);
```

Moves empty tile down.

---

# Copy Function

```cpp id="kn28tb"
void Copy(int temp[], int real[])
```

Copies one puzzle state into another.

---

```cpp id="6xmb66"
temp[i] = real[i];
```

Copies each element.

---

# Heuristic Function

```cpp id="mllg7o"
int heuristic(int start[], int goal[])
```

Calculates heuristic value.

Used for:

* selecting best move

---

```cpp id="j0f3r1"
int h = 0;
```

Stores heuristic cost.

---

# Nested Loops

```cpp id="uvcm0d"
for(int i = 0; i < 9; i++)
```

Checks every tile in start state.

---

```cpp id="3mwujw"
for(int j = 0; j < 9; j++)
```

Finds corresponding tile in goal state.

---

# Tile Match

```cpp id="i6wwlb"
if (start[i] == goal[j] && start[i] != -1)
```

Checks:

* same tile found
* not empty tile

---

# Manhattan Distance

```cpp id="jlwm5u"
h += abs((j - i) / 3) + abs((j - i) % 3);
```

Attempts to compute Manhattan distance.

Formula meaning:

|x_2-x_1|+|y_2-y_1|

This estimates distance from current position to goal.

---

# Return Cost

```cpp id="ow0vm8"
return h + g;
```

Returns:

f(n)=g(n)+h(n)

Where:

* `g` = moves made
* `h` = heuristic distance

---

# moveTile()

```cpp id="3a3h0m"
void moveTile(int start[], int goal[])
```

Chooses best next move.

---

# Find Empty Tile

```cpp id="dwlw51"
if(start[i] == -1)
```

Finds blank position.

---

```cpp id="gzc86l"
emptyAt = i;
```

Stores blank tile index.

---

# Temporary Boards

```cpp id="g5q7c4"
int t1[9],t2[9],t3[9],t4[9]
```

Stores:

* possible future states

---

# Initialize Costs

```cpp id="2t0mwx"
f1 = INT_MAX
```

Initially set all move costs very large.

---

# Copy Current State

```cpp id="x1d18s"
Copy(t1, start);
```

Copies current puzzle into temp boards.

---

# Row and Column

```cpp id="qjv7q7"
int row = emptyAt / 3;
```

Gets row number.

---

```cpp id="h7v24y"
int col = emptyAt % 3;
```

Gets column number.

---

# Check Left Move

```cpp id="clsc0v"
if(col - 1 >= 0)
```

Checks if left move possible.

---

```cpp id="vxh0r2"
moveLeft(t1, emptyAt);
```

Simulates left move.

---

```cpp id="1jlwmr"
f1 = heuristic(t1, goal);
```

Computes heuristic after left move.

---

# Same Logic for:

* right
* up
* down

---

# Choose Best Move

```cpp id="r19o9v"
if(f1 <= f2 && f1 <= f3 && f1 <= f4 )
```

Chooses move with minimum heuristic.

---

```cpp id="hvjtpw"
moveLeft(start, emptyAt);
```

Actually performs move on original puzzle.

---

# solveEight()

```cpp id="lm4u4d"
void solveEight(int start[], int goal[])
```

Main recursive solver.

---

# Increase Move Count

```cpp id="kggk75"
g++;
```

Counts moves.

---

# Move Tile

```cpp id="7z8u4n"
moveTile(start, goal);
```

Chooses best move.

---

# Print State

```cpp id="4kkl8k"
Print(start);
```

Displays puzzle.

---

# Calculate Heuristic

```cpp id="0im7qf"
int f = heuristic(start, goal);
```

Gets total cost.

---

# Goal Check

```cpp id="qv0r9x"
if(f == g)
```

Checks if solved.

Because:

* when solved
* heuristic becomes 0
* therefore:

f=g+h=g+0=g

---

# Recursive Call

```cpp id="jlxmb1"
solveEight(start, goal);
```

Calls itself again.

This is recursion.

---

# solvable()

```cpp id="1qclo9"
bool solvable(int start[])
```

Checks whether puzzle can be solved.

---

# Inversion Count

```cpp id="zwlww1"
int invrs = 0;
```

Counts inversions.

---

# Ignore Empty Tile

```cpp id="93v5ji"
if(start[j] == -1) continue;
```

Blank tile not counted.

---

# Count Inversions

```cpp id="34gjd2"
if(start[i] > start[j]) invrs++;
```

Inversion means:
larger number before smaller number.

---

# Solvability Rule

```cpp id="l3l7ow"
return invrs & 1 ? false : true;
```

If inversions are:

* even → solvable
* odd → unsolvable

---

# main()

Program execution starts here.

---

# Arrays

```cpp id="t6qct2"
int start[9];
int goal[9];
```

Stores:

* initial state
* goal state

---

# Input Start State

```cpp id="2a9jeq"
cin >> start[i];
```

Reads puzzle.

---

# Input Goal State

```cpp id="ukg78s"
cin >> goal[i];
```

Reads desired configuration.

---

# Print Initial Board

```cpp id="9qu7i5"
Print(start);
```

Displays starting puzzle.

---

# Solvability Check

```cpp id="t1a5n0"
if(solvable(start))
```

Checks if puzzle can be solved.

---

# Start Solver

```cpp id="bwrbku"
solveEight(start, goal);
```

Begins solving process.

---

# Failure Case

```cpp id="zc1d2l"
cout << "\nImpossible To Solve\n";
```

Printed if puzzle unsolvable.

---

# Important Algorithm Note

Your code is NOT complete A*.

It is:

* greedy heuristic search
* recursive
* no backtracking
* no visited states

So it may:

* loop forever
* fail on difficult puzzles

---

# Core AI Formula Used

f(n)=g(n)+h(n)

Where:

* `g(n)` = moves so far
* `h(n)` = estimated distance to goal
* `f(n)` = total estimated cost
