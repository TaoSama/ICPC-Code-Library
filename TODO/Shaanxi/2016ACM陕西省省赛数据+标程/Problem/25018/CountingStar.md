Counting Star

5s

### Description

"Our Conquest is the Sea of Stars."

With the help of our powerful AI machine HE, scientists start an exciting project of sending space probes to the deep space.

Scientists have already got some pictures from Hubble Space Telescope, or I'd like to call them star maps. The star maps can be seen as a (n+1)*(n+1) pixel grid, every grid point has a brightness.

Scientists believe that those areas of higher brightness are more valuable for researching.

Inorder to use some special analysing algorithms, scientis decide to count the total brightness of some right-angled triangle areas. The triangle areas will start from (0,0).

Scientists will provide the star maps and tell you which areas should be counted and you are asked to answer it. The triangle areas will be given by its apexes position (0,0), (x,0), (x,y).

### Input

The first line is an integer T, indicates there will be T test cases.

For each test cases:

The first line is an integer n ($n\le 1000$), indicate the length and width of  the star map.

Next is a n*n grid, pixels are numbered from (1,1) to (n,n).

Then comes an integer m ($m \le 100000$), indicate the number of queries.

Each of next m lines contains 2 integers (x,y). ($1\le x,y\le n$)

### Output

For each test cases:

First output the case number like "Case #x:", x is the sequence number of that test case.

Then output m lines, each line is an integer number, means the brightness sum of the triangle areas by apexes position (0,0), (x,0), (x,y).

### Sample Input

```
2
3
1 2 3
4 5 6
7 8 9
2
2 2
3 2
3
1 1 1
2 2 2
3 3 3
1
2 3
```

### Sample Output

```
Case #1:
20
23
Case #2:
9
```