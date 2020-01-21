#include "Thread.h"

//prints i love threads...
void I_Love_Threads()
{
	cout << "I Love Threads!! X_x" << endl;
}

//call to print 
void call_I_Love_Threads()
{
	std::thread t1(I_Love_Threads);
	t1.join();
}

//build a new vector and saves the primes from the old one
void getPrimes(int begin, int end, std::vector<int>& primes )
{
	int j = 0;
	bool prime;
	for (int i = begin; i < end; i++) // access all elements of vector
	{
		prime = false; 
		j = i / 2;
		for (int k = 2; k <= j; k++) 
		{
			if (i % k == 0) 
			{
				prime = true; 
				break;   
			}
		}
		if (!prime)
			primes.push_back(i); 
	}
}

//prints the vector
void printVector(std::vector<int> primes)
{
	for (int i = 0; i != primes.size(); i++)
		std::cout << primes.at(i) << " ";
	cout << endl;
}

//activates the get primes
std::vector<int> callGetPrimes(int begin, int end)
{
	clock_t t; //setting timer
	t = clock();
	std::vector<int> primes;
	std::thread t1(getPrimes, std::ref(begin), std::ref(end), std::ref(primes));
	t1.join();

	t = clock() - t;
	std::cout << "It took " << (((float)t) / CLOCKS_PER_SEC) << " seconds." << std::endl;
	return primes;
}

//write the prime numbers to file
void writePrimesToFile(int begin, int end, std::ofstream& file)
{
	int j = 0;
	bool prime;
	for (int i = begin; i < end; i++) // access all elements of vector
	{
		prime = false;
		j = i / 2;
		for (int k = 2; k <= j; k++)
		{
			if (i % k == 0)
			{
				prime = true;
				break;
			}
		}
		if (!prime)
			file << begin << std::endl;
	}
}

//activates the write primes file function
void callWritePrimesMultipleThreads(int begin, int end, std::string filePath, int N)
{
	std::ofstream myFile;
	myFile.open(filePath);

	int param1 = end / N;
	std::thread t1(writePrimesToFile, std::ref(begin), std::ref(param1), std::ref(myFile));
	//t1.join();

	std::thread t2(writePrimesToFile, std::ref(param1), std::ref(end), std::ref(myFile));
	//t2.join();
	myFile.close();
}