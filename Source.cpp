#include "Thread.h"
#define PATH "primes.txt"

int main()
{
	call_I_Love_Threads();

	std::vector<int> primes1;
	getPrimes(58, 100, primes1);

	std::vector<int> primes3 = callGetPrimes(93, 289);

	//callWritePrimesMultipleThreads(1, 100000, PATH, 2);
	std::vector<int> primes4 = callGetPrimes(0, 1000);
	printVector(primes4);
	std::vector<int> primes5 = callGetPrimes(0, 100000);
	printVector(primes5);
	std::vector<int> primes6 = callGetPrimes(0, 1000000);
	printVector(primes6);

	callWritePrimesMultipleThreads(1, 100000, PATH, 2);
	callWritePrimesMultipleThreads(0, 1000, PATH , 2);
	callWritePrimesMultipleThreads(0, 100000, PATH , 2);
	callWritePrimesMultipleThreads(0, 1000000, PATH, 2);
	system("pause");
	return 0;
}