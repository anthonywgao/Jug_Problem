# Jug_Problem
I like jugs

Input
Input to your program consists of 9 ints defining one puzzle. Ca, Cb, N, cfA, cfB, ceA, ceB, cpAB, cpBA. Ca and Cb are the capacities of 
jugs A and B, and N is the goal. the rest are the costs for each action. You will want to verify the costs are positive and 0 < Ca ≤ Cb and 
N ≤ Cb ≤ 1000. If the inputs are invalid solve will return -1.

Solution
If a solution exists, the solve function should generate a string, that if output would look like the sample output below. This string will 
store the steps as a series of instructions, one instruction per line, from the list of the potential output lines which will result in jug 
A being empty and jug B containing exactly N gallons of water. The last line for each puzzle should be the line "success X". (where X is 
the cost). There should be no empty lines nor any trailing spaces within this string. This string is "returned" via the reference 
parameter.
