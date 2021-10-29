# NumberOfDifferentSummingEquations

Use two methods to solve the problem of finding the number of ways to add non-dulicate integers in descending order that has a sum of given integer.

## Goal

For a given integer, you want to find all possible ways to add different numbers together that has the sum equals to the given integer.

`9`

`9=8+1`

`9=7+2`

`9=6+3`

`9=6+2+1`

`9=5+4`

`9=5+3+1`

`9=4+3+2`

Thus, there are 7 ways to do that for 9.

## Solution with recursion

With recursion, you can print out all the equations, but it will take lots of time to do so when the input integer is big. Let's name the input `n`.

The base cases are numbers that cannot be divided anymore, which is `1` and `2`.

After base cases, you need a loop to go from `n-1` to `1`, and the iterator is the number you want to add to the equation. Thus, you need to bring in the last number you 

have in the equation, because the number you add to the equation should not bigger than the value before it.

Then, if the iterator is smaller than the last number, you can make the recursive call. This will handle the problems of `8=4+4` and `9=2+4+3`.

In order to print out all equations, you need to bring in a string, and add the number to the string with a `+` if you still need to going on.

However, this method reuse recursive calls with small inputs a lot, so it takes much longer time to find the solution for big numbers.

Thus, I will introduce the second method that you can store all data that you need in a `n*n` matrix.

## Solution with matrix

First, we need a matrix of size `(n+1)*(n+1)`. In position `(i,j)`, the number should be the number of ways to sum to i with the first number is j, and it should be the 

sum of `(j,i-j-1) to (j,0)`. 

For example, in position `(7,4)`, the number means that the number of ways to write `7=4+...`. The rest of the equation has a sum of 3, and the leading number should no

bigger than 4, the first number of the equation. Thus, it should be: `3=3`, `3=2+1`. 

To get the final answer for n, just sum from `(n,n-1) to (n,0)`. 

For more explicit explanation, you can look at the picture in the repository. 
