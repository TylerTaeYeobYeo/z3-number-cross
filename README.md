# Number Cross
1. This puzzle consists of a NxM grid where every cells are labeled with a positive integer.
2. The goal of the game is to determine the color of each cells either Black or White.
3. The labeled numbers on top (or each column) is the total value of the black cells within the column.
4. The labeled numbers on right (or end of each row) is the total value of the white cells within the row.
5. Each cells has a value between 1 to 9
6. There are no initial colors given.

For example:

```
8 1
5 2 2
6 1 6
3 4 4
```

### 1. The number on top of 1st column represents sum of the black cells in {5,6,3}. Which we can assume 5 and 3 are black cells.
### 2. The second number is 1 that we know among {2,1,4}, 1 is the only black cells.
