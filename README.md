# Number Cross

## 1. About the Game (or Number Cross)

#### 1. This puzzle consists of a NxM grid where every cells are labeled with a positive integer.
#### 2. The goal of the game is to determine the color of each cells either Black or White.
#### 3. The labeled numbers on top (or each column) is the total value of the black cells within the column.
#### 4. The labeled numbers on right (or end of each row) is the total value of the white cells within the row.
#### 5. Each cells has a value between 1 to 9
#### 6. There are no initial colors given.

For example:

```
8 1
5 2 2
6 1 6
3 4 4
```

1. The number on top of 1st column represents sum of the black cells in {5,6,3}. Which we can assume 5 and 3 are black cells.
2. The second number is 1 that we know among {2,1,4}, 1 is the only black cells.
so the black cells are {5,1,3} and others are white cells.

## 2. How to Run

#### 1. Needs to install z3
#### 2. Designed for linux/unix environment
#### 3. Inputs are only fed by standard input
```
./a.out < input
```

## 3. Input

#### a. the name of the file isn't important
#### b. but the format should keep following:
##### i.   first row has to indicate the sum of black cells on each column
##### ii.  the last cell of each row (excluding the first row) should indicate the sum of white cells on each row.
##### iii. there should be no line feed after last line. (please keep this)

## 4. Output/Results

#### a. If it is unsatisfiable result, the program will provide a error message.
#### b. A file name 'formula' will be created, when program is executed. this file contains z3 input details.
#### c. A file name 'output' will be created, when program is succesfully runned. this file will show a table of 0 and 1, which each of them representing white and black cells.

## 5. Warnings

#### a. error will occur when there is a additional line feed at the end of the program.
#### b. Error, if z3 is not installed.

## 6. Quick Tryout

```
1. gcc hw1.c
2. ./a.out < input
```

### Or

```
1. ./Makefile
2. ./answer.out < input
```
