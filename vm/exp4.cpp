
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int **arr, int x, int y, int n){

    // Check column
    for(int row = 0; row < x; row++){
        if(arr[row][y] == 1)
            return false;
    }

    // Check left diagonal
    int row = x;
    int col = y;

    while(row >= 0 && col >= 0){
        if(arr[row][col] == 1)
            return false;
        row--;
        col--;
    }

    // Check right diagonal
    row = x;
    col = y;

    while(row >= 0 && col < n){
        if(arr[row][col] == 1)
            return false;
        row--;
        col++;
    }

    return true;
}

bool nQueen(int **arr, int x, int n){

    // All queens placed
    if(x >= n)
        return true;

    for(int col = 0; col < n; col++){

        if(isSafe(arr, x, col, n)){

            arr[x][col] = 1;

            if(nQueen(arr, x + 1, n))
                return true;

            // Backtracking
            arr[x][col] = 0;
        }
    }

    return false;
}

int main(){

    int n;
    cin >> n;

    // Dynamic allocation
    int **arr = new int*[n];

    for(int i = 0; i < n; i++){
        arr[i] = new int[n];
        for(int j = 0; j < n; j++){
            arr[i][j] = 0;
        }
    }

    if(nQueen(arr, 0, n)){

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "No solution exists\n";
    }

    // Free memory
    for(int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}
```

---

# 🧠 Line-by-Line Explanation

## Header

```cpp id="h1"
#include<bits/stdc++.h>
```

Includes all standard C++ libraries.

---

## Namespace

```cpp id="h2"
using namespace std;
```

Avoids writing `std::` repeatedly.

---

# 🔍 isSafe() Function

This checks if we can place a queen at position `(x, y)`.

---

## Column Check

```cpp id="h3"
for(int row = 0; row < x; row++)
```

Checks only previous rows (important optimization).

---

```cpp id="h4"
if(arr[row][y] == 1)
```

If queen already exists in same column → unsafe.

---

## Left Diagonal Check

```cpp id="h5"
while(row >= 0 && col >= 0)
```

Moves diagonally up-left.

---

## Right Diagonal Check

```cpp id="h6"
while(row >= 0 && col < n)
```

Moves diagonally up-right.

---

# 👑 nQueen Function (Backtracking)

```cpp id="h7"
bool nQueen(int **arr, int x, int n)
```

Places queen row by row.

---

## Base Case

```cpp id="h8"
if(x >= n)
```

All queens placed successfully.

---

## Try All Columns

```cpp id="h9"
for(int col = 0; col < n; col++)
```

Try placing queen in every column.

---

## Safe Check

```cpp id="h10"
if(isSafe(arr, x, col, n))
```

Only proceed if position is valid.

---

## Place Queen

```cpp id="h11"
arr[x][col] = 1;
```

Place queen.

---

## Recursive Call

```cpp id="h12"
nQueen(arr, x + 1, n)
```

Move to next row.

---

## Backtracking

```cpp id="h13"
arr[x][col] = 0;
```

Undo move if it fails.

---

# 🧾 main() Function

## Input

```cpp id="h14"
cin >> n;
```

Board size.

---

## Dynamic Memory

```cpp id="h15"
int **arr = new int*[n];
```

Creates 2D board.

---

## Initialize Board

```cpp id="h16"
arr[i][j] = 0;
```

Empty board.

---

## Solve

```cpp id="h17"
nQueen(arr, 0, n)
```

Start from row 0.

---

## Print Solution

```cpp id="h18"
cout << arr[i][j]
```

Displays queen positions.

---

## Memory Cleanup (Important)

```cpp id="h19"
delete[] arr[i];
delete[] arr;
```

Prevents memory leak.

---

# ⚡ Complexity

Time complexity:

O(N!)

Because each row tries all columns recursively.

---

# 📘 Viva Questions

## 1. What is N-Queens problem?

Placing N queens on N×N board so that no two attack each other.

---

## 2. What is backtracking?

Trying all possibilities and undoing invalid choices.

---

## 3. Why recursion used?

Each row depends on previous row placement.

---

## 4. What is isSafe() function?

Checks whether queen can be placed safely.

---

## 5. Time complexity?

O(N!)

---

## 6. Why check only previous rows?

Because queens are placed row-wise top to bottom.

---

## 7. What is diagonal attack condition?

Same `(row-col)` or `(row+col)` values.

---

## 8. What is backtracking?

Undoing a wrong choice and trying another path.

---

## 9. Why dynamic memory used?

To create board of size decided at runtime.

---

## 10. Applications?

* AI search problems
* Constraint satisfaction problems
* Scheduling problems

---

If you want, I can also:

* show step-by-step recursion tree
* or convert this into C++ STL version (vector instead of pointers)
* or optimize it using bitmasking (very important for interviews)
