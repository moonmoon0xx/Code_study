#include <iostream>
#include <string>

using namespace std;
int main()
{
	//字符串拼接
	/*string s1 = "Abc";
	string s2 = "Def";
	string s3 = s1 + s2;
	cout << "s1:" << s1 << " s2:" << s2 << endl;
	cout << "s3:" << s3;*/
	
	char charr[20];//未定义
	char charr2[20]{ 1,2 };
	string str;
	cout << "Length of string of charr :" << strlen(charr) << endl;//strlen 从数组第一个元素开始，直到遇到\0计数完毕
	cout << "Length of string of charr2 :" << strlen(charr2) << endl;
	cout << "Length of string of str :" << str.size() << endl;
	
	return 0;
}