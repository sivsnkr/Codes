// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Alice rolled A standard six-sided dice.
At the same time, Bob rolled another B standard six-sided dice.



Alice wins if at least one of her dice matches one of Bob's dice.
Bob wins if that does not happen.


For example, if Alice rolls 1,3,3,6 and Bob rolls 2,3,5,5,5, Alice wins because they both rolled a 3.
On the other hand, if Alice rolls 1,3,3,6 and Bob rolls 4,4,4,2,4, Bob wins because all of Alice's dice show numbers different from those on Bob's dice.



Given A and B, what is the probability that Alice wins?


DEFINITION
Class:DisjointDiceValues
Method:getProbability
Parameters:int, int
Returns:double
Method signature:double getProbability(int A, int B)


NOTES
-Return values that differ from the reference solution by at most 1e-9 will be accepted as correct.


CONSTRAINTS
-A and B will be positive integers with A + B <= 16.


EXAMPLES

0)
1
1

Returns: 0.16666666666666663

Alice has one die and Bob has one die. With probability 1/6 Alice will roll the same value as Bob and win.

1)
4
1

Returns: 0.5177469135802468


Alice has four dice while Bob has one. Alice can view this game as her having four chances to roll the number that will come up on Bob's single die.


(An interesting historical fact: This example is closely related to a famous problem that was the motivation for Blaise Pascal to invent discrete probability. Empirically this game feels approximately fair, but as we see, Alice's win probability is actually slightly more than 50 percent.)


2)
1
4

Returns: 0.5177469135802468

The game is actually symmetric: the probability that one of Bob's dice matches Alice's single die is the same as it was when Alice had four dice and Bob just one.

3)
3
3

Returns: 0.7910236625514401

With three dice each it is already quite likely that at least one of their outcomes will match. The exact probability that Alice wins is 6151/7776.

// END CUT HERE
import java.util.*;
public class DisjointDiceValues {
	public double getProbability(int A, int B) {
		
	}
	public static void main(String[] args) {
		DisjointDiceValues temp = new DisjointDiceValues();
		System.out.println(temp.getProbability(int A, int B));
	}
}
