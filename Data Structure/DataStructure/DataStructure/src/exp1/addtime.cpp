#include <iostream>
#define Max_n 99999999

long add1()//����ۼ�
{
	long sum = 0;
	for (long i = 0; i <= Max_n; i++)
	{
		sum += i;
		//std::cout << "i=" << i << " sum=" << sum << std::endl;
	}
	return sum;
}

void Addtime1()
{
	clock_t t;
	long sum;
	t = clock();
	sum = add1();
	t = clock() - t;
	printf("Addtime1:\n");
	printf("���:1��%d֮��:%ld\n", Max_n, sum);
	printf("��ʱ:%lf��\n", ((float)t) / CLOCKS_PER_SEC);
}

long add2()
{
	return Max_n * (1 + Max_n) / 2;
}

void Addtime2()
{
	clock_t t;
	long sum;
	t = clock();
	sum = add2();
	t = clock() - t;
	printf("Addtime2:\n");
	printf("���:1��%d֮��:%ld\n", Max_n, sum);
	printf("��ʱ:%lf��\n", ((float)t) / CLOCKS_PER_SEC);
}

//int main()
//{
//	Addtime1();
//	Addtime2();
//	return 0;
//}