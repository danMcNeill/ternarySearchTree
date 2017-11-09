#include <iostream>
using namespace std;
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <fcntl.h>
#include <time.h>
#include "TST.h"

int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1)
{
    long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
    result->tv_sec = diff / 1000000;
    result->tv_usec = diff % 1000000;

    return (diff<0);
}

void timeval_print(char *str, struct timeval *tv)
{
    printf("%s %ld sec, %06ld micro sec\n", str, tv->tv_sec, tv->tv_usec);
}


int main() {

	TST<int> test1, test2, test3, test4, test5, test6, test7, test8;
	struct timeval tvDiff , tvStart , tvEnd;





// TESTING INSERT UNBALANCED TREE
	/*// 16,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<16000; i++)
		test1.insert(i);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for unbalanced (straight line) tree (16,000 nodes): ", &tvDiff);
	cout << "\n";

	// 32,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<32000; i++)
		test2.insert(i);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for unbalanced (straight line) tree (32,000 nodes): ", &tvDiff);
	cout << "\n";

	// 64,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<64000; i++)
		test3.insert(i);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for unbalanced (straight line) tree (64,000 nodes): ", &tvDiff);
	cout << "\n";

	// 128,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<128000; i++)
		test4.insert(i);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for unbalanced (straight line) tree (128,000 nodes): ", &tvDiff);
	cout << "\n";
*/

// TESTING INSERT FOR "BALANCED" TREES

	 // 16,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<16000; i++)
		test5.insert((rand()%100000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for balanced (straight line) tree (16,000 nodes): ", &tvDiff);
	cout << "\n";

	// 32,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<32000; i++)
		test6.insert((rand()%100000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for balanced (straight line) tree (32,000 nodes): ", &tvDiff);
	cout << "\n";

	// 64,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<64000; i++)
		test7.insert((rand()%100000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for balanced (straight line) tree (64,000 nodes): ", &tvDiff);
	cout << "\n";

	// 128,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<1280000; i++)
		test8.insert((rand()%1000000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for balanced (straight line) tree (128,000 nodes): ", &tvDiff);
	cout << "\n";



// TESTING REMOVE UNBALANCED TREE
	// 16,000 nodes
	/*gettimeofday(&tvStart , NULL);

	for(int i=0; i<16000; i++)
		test1.remove((rand()%20000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for unbalanced (straight line) tree (16,000 nodes): ", &tvDiff);
	cout << "\n";

	// 32,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<32000; i++)
		test2.remove((rand()%100000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for unbalanced (straight line) tree (32,000 nodes): ", &tvDiff);
	cout << "\n";

	// 64,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<64000; i++)
		test3.remove((rand()%100000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for unbalanced (straight line) tree (64,000 nodes): ", &tvDiff);
	cout << "\n";

	// 128,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<128000; i++)
		test4.remove((rand()%100000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for unbalanced (straight line) tree (128,000 nodes): ", &tvDiff);
	cout << "\n";

*/


// TESTING REMOVE FOR "BALANCED" TREES

	/*// 16,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<16000; i++)
		test5.remove((rand()%100000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for balanced (straight line) tree (16,000 nodes): ", &tvDiff);
	cout << "\n";

	// 32,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<32000; i++)
		test6.remove((rand()%100000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for balanced (straight line) tree (32,000 nodes): ", &tvDiff);
	cout << "\n";

	// 64,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<64000; i++)
		test7.remove((rand()%100000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for balanced (straight line) tree (64,000 nodes): ", &tvDiff);
	cout << "\n";

	// 128,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<128000; i++)
		test8.remove((rand()%100000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for balanced (straight line) tree (128,000 nodes): ", &tvDiff);
	cout << "\n";

*/




// TESTING FIND UNBALANCED TREE
	// 16,000 nodes
	/*gettimeofday(&tvStart , NULL);

	for(int i=0; i<16000; i++)
		test1.find((rand()%100000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for unbalanced (straight line) tree (16,000 nodes): ", &tvDiff);
	cout << "\n";

	// 32,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<32000; i++)
		test2.find((rand()%100000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for unbalanced (straight line) tree (32,000 nodes): ", &tvDiff);
	cout << "\n";

	// 64,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<64000; i++)
		test3.find((rand()%100000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for unbalanced (straight line) tree (64,000 nodes): ", &tvDiff);
	cout << "\n";

	// 128,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<128000; i++)
		test4.find((rand()%100000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for unbalanced (straight line) tree (128,000 nodes): ", &tvDiff);
	cout << "\n";

	//test.display();
*/

// TESTING FIND FOR "BALANCED" TREES

	// 16,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<16000; i++)
		test5.find((rand()%100000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for balanced (straight line) tree (16,000 nodes): ", &tvDiff);
	cout << "\n";

	// 32,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<32000; i++)
		test6.find((rand()%100000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for balanced (straight line) tree (32,000 nodes): ", &tvDiff);
	cout << "\n";

	// 64,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<64000; i++)
		test7.find((rand()%100000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for balanced (straight line) tree (64,000 nodes): ", &tvDiff);
	cout << "\n";

	// 128,000 nodes
	gettimeofday(&tvStart , NULL);

	for(int i=0; i<128000; i++)
		test8.find((rand()%100000) + 1);

	gettimeofday(&tvEnd , NULL);
	timeval_subtract(&tvDiff, &tvEnd, &tvStart);

	timeval_print("runtime for balanced (straight line) tree (128,000 nodes): ", &tvDiff);
	cout << "\n";


	return 0;
}
