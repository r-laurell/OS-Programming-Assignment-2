# OS-Programming-Assignment-2
Given a system, use Banker's Algorithm to determine if it is safe or not.

Reanna Laurell
Programming Assignment #2
Operating Systems

Code Files: 
-	Source.cpp
Description: 
	For this programming assignment, we were required to implement a program based on Banker’s Algorithm for avoiding deadlock, to check if a given sequence is safe or unsafe. We could have either coded it in C or C++ in Linux/Unix.  Banker’s Algorithm is a deadlock avoidance algorithm that tests for a given set of data to see if it is safe or unsafe. It is called Banker’s Algorithm as it is used a lot in banks to help determine if they can give out a loan to a certain client or not. 
	We were given a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has ten instances, B has five instances and type C has seven instances, with the following information given: 
		Processes	Allocation 	Max	Available
				   A  B  C              A B C          A B C
		     P0                       0  1  0		7 5 3          3 3 2
		     P1		   2  0  0               3 2 2
		     P2		   3  0  2               9 0 2
		     P3		   2  1  1               2 2 2
		     P4 		   0  0  2 	4 3 3 
	With this given information, we had to determine if the system was in a safe state or not and if it was what is that safe state.  Through the code implementation that you will see in the results section below, the system does have a safe state. 

Results: 
	From programming Banker’s Algorithm, I was able to determine that the given sequence was considered a safe one and printed out the following result shown if Figure 1. 
 
Figure 1: Displaying the results of the safe sequence: 1 -> 3 -> 4 -> 0 -> 2
Conclusion: 
	From this programming assignment, I was able to gain a better understanding what the Banker’s Algorithm is and how to go about using it to figure out if a system is safe or not. By figuring out if a system is safe or not, you must go through each set of numbers in the array or matrix and compare the “need” to the “work”, determining which sets of data are true or false. Once that is done, you then want to start adding the work to the allocation data to check if all the results that were false change to true. Once this step is done you will be able to check if the finish result is true or false, or in the program written, 0 for false and 1 for true.
