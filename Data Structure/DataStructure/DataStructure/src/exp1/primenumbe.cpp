/*********************************************************************
#����:��Ҳ����������ָ�ڴ��� 1 ����Ȼ���У����� 1 ���������⣬
���ܱ�������Ȼ���������������� 2��3��5��7��11 �ȶ���������

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
	printf("����1:\n");
	printf("���:2��%d����������:%d\n", n, sum);
	printf("��ʱ:%lf��\n", ((float)t) / CLOCKS_PER_SEC);
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
	printf("����2:\n");
	printf("���:2��%d����������:%d\n", n, sum);
	printf("��ʱ:%lf��\n", ((float)t) / CLOCKS_PER_SEC);
}
//int main()
//{
//	PrimeTime1(100);
//	PrimeTime2(100);
//	return 0;
//}