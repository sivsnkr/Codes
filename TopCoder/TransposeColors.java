// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
We have an array with N rows and N columns, both numbered starting from 0.
We also have one temporary storage space.
Each cell of the array contains a token, the temporary storage is empty.
There are N colors: for each i, all tokens in row i have color i.


We want to transpose the colors. More precisely, we want to rearrange the tokens so that for each i all tokens in column i will have color i.
We have to do this in a sequence of steps.
In each step we must take one of the tokens and move it to the only available free space.
Find and return any shortest sequence of such moves that transposes the colors in the given array.


(Tokens that share the same color are identical. In the final solution they can be placed in any order. In particular, their final order from the top to the bottom of the column does not have to match their initial order from the left to the right of the row.)



Cells of the array are numbered in row major order starting from 0, so the cell (row r, column c) has the number r*N+c.
The temporary storage space has the next available number: N*N.


Return a int[] describing your solution: for each move, output the number of the location from which you move the token. (Specifying the destination for the move is not necessary, as there is always exactly one empty location.)


DEFINITION
Class:TransposeColors
Method:move
Parameters:int
Returns:int[]
Method signature:int[] move(int N)


CONSTRAINTS
-N will be between 1 and 40, inclusive.


EXAMPLES

0)
1

Returns: { }

There is a single purple token on the cell (0, 0). For N = 1 this is also the desired final configuration, so it is optimal to do nothing.

1)
2

Returns: {2, 1, 4 }

The return value describes the following solution:

move a token from row 1, column 0 (location 2) to the empty temporary storage space
move a token from row 0, column 1 (location 1) to the now-empty location 2
move the token from the temporary storage space (location 4) to the now-empty location 1


This sequence of operations takes three moves. It essentially uses the temporary storage space as a temporary variable and swaps the tokens in the top right and the bottom left corner of the board.


There is one other correct answer for this test case: the sequence {1, 2, 4} that swaps the same two tokens but does so in the opposite order.


2)
3

Returns: {1, 5, 6, 2, 7, 3, 9 }

Below we show a sequence of what the array looks like in the beginning, and then after each step.
The letters A, B, C represent the three token colors. In the first step we move one token of color A into the temporary location, in the last step we return it back. A period denotes an empty space.


AAA   A.A   ABA   ABA   AB.   ABC   ABC   ABC
BBB   BBB   BB.   BBC   BBC   BBC   .BC   ABC
CCC   CCC   CCC   .CC   ACC   A.C   ABC   ABC


// END CUT HERE
import java.util.*;
public class TransposeColors {
	public int[] move(int N) {
		
	}
	public static void main(String[] args) {
		TransposeColors temp = new TransposeColors();
		System.out.println(temp.move(int N));
	}
}
