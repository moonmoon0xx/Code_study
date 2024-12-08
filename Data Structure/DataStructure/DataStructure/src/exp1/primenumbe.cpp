/*********************************************************************
#素数:（也叫质数）是指在大于 1 的自然数中，除了 1 和它自身外，
不能被其他自然数整除的数。例如 2，3，5，7，11 等都是素数。

	*********************************************************************/
#include <iostream>
#include <time.h>
#include <math.h>
bool prime1(long n)
{
	long i;
	for (i = 2;i < n;i++)
		if (n % i == 0)
			return false;
	std::cout << n << "is prime" << std::endl;
}
void PrimeTime1(long n)
{
	clock_t t;
	long sum = 0;
	t = clock();
	for (int i = 2; i <= n; i++)
		if (prime1(i))
			sum++;
	t = clock() - t;
	printf("方法1:\n");
	printf("结果:2～%d的素数个数:%d\n", n, sum);
	printf("用时:%lf秒\n", ((float)t) / CLOCKS_PER_SEC);
}
bool prime2(long n)
{
	for (long i = 2; i <= (n / 2); i++)
		if (n % i == 0)
			return false;
	std::cout << n << "is prime" << std::endl;
}
void PrimeTime2(long n)
{
	clock_t t;
	long sum = 0;
	t = clock();
	for (int i = 2; i <= n; i++)
		if (prime2(i))
			sum++;
	t = clock() - t;
	printf("方法2:\n");
	printf("结果:2～%d的素数个数:%d\n", n, sum);
	printf("用时:%lf秒\n", ((float)t) / CLOCKS_PER_SEC);
}
//int main()
//{
//	PrimeTime1(100);
//	PrimeTime2(100);
//	return 0;
//}