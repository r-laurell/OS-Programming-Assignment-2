/* 
	Operating System Assignment 2 - Banker's Algorithm
	Reanna Laurell, November 20th 2022
*/

#include <iostream>
using namespace std;

int main(){

	int loop1var; //looping through the need array (2d) as array 1
	int loop2var; //looping through the need array (2d) as array 2
	int proLoop;  //looping through the number of processes
	const int numPro = 5; //number of processes
	const int numReso = 3; //number of resources

	int alloc[5][3] = { { 0, 1, 0 }, //P0 | allocation matrix
						{ 2, 0, 0 }, //P1
						{ 3, 0, 2 }, //P2
						{ 2, 1, 1 }, //P3
						{ 0, 0, 2 } }; //P4

	int max[5][3] = { { 7, 5, 3 }, //P0  | max matrix
					{ 3, 2, 2 }, //P1
					{ 9, 0, 2 }, //P2
					{ 2, 2, 2 }, //P3
					{ 4, 3, 3 } }; //P4

	int avail[3] = { 3, 3, 2 }; //available resources

	//f is the result of if the algorithm is safe or not and should be 1 is safe 
	int result[numPro], ans[numPro], ind = 0;												//setting everything in array to zero
	for (proLoop = 0; proLoop < numPro; proLoop++) {
		result[proLoop] = 0;
	}
	int need[numPro][numReso];																//calc the need
	for (loop1var = 0; loop1var < numPro; loop1var++) {
		for (loop2var = 0; loop2var < numReso; loop2var++)
			need[loop1var][loop2var] = max[loop1var][loop2var] - alloc[loop1var][loop2var];
	}
	int index = 0;																			//index for each of the elements in the process 
	for (proLoop = 0; proLoop < 5; proLoop++) {
		for (loop1var = 0; loop1var < numPro; loop1var++) {
			if (result[loop1var] == 0) {

				int flag = 0;																//goes thorugh 3 times 
				for (loop2var = 0; loop2var < numReso; loop2var++) {
					if (need[loop1var][loop2var] > avail[loop2var]) {						//checking if the need is greater than the aviable space 
						flag = 1;															//safe
						break;	
					}
				}

				if (flag == 0) {															//unsafe sequence 
					ans[ind++] = loop1var;													//if index is safe it starts to fill the new one
					for (index = 0; index < numReso; index++)								//looping through all resources
						avail[index] += alloc[loop1var][index];								//adding each of the resources for this process to the available array
					result[loop1var] = 1;													//process is now considered safe
				}
			}
		}
	}

	int flag = 1;	

	// To check if sequence is safe or not
	for (int loop1var = 0; loop1var < numPro; loop1var++){
		if (result[loop1var] == 0){															//checking if the flag is 0 meaning the squence would not be safe
			flag = 0;
			cout << "The given sequence is not safe";
			break;
		}
	}

	if (flag == 1){																			//checking if flag is 1 stating that the given squence would be sage  
		cout << "Following is the SAFE Sequence" << endl;
		for (loop1var = 0; loop1var < numPro - 1; loop1var++)
			cout << ans[loop1var] << " -> ";
		cout << ans[numPro - 1] << endl;
	}

	return (0);
}
