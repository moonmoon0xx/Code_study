#include <iostream>
#include <string>

using namespace std;
int main()
{
	//�ַ���ƴ��
	/*string s1 = "Abc";
	string s2 = "Def";
	string s3 = s1 + s2;
	cout << "s1:" << s1 << " s2:" << s2 << endl;
	cout << "s3:" << s3;*/
	
	char charr[20];//δ����
	char charr2[20]{ 1,2 };
	string str;
	cout << "Length of string of charr :" << strlen(charr) << endl;//strlen �������һ��Ԫ�ؿ�ʼ��ֱ������\0�������
	cout << "Length of string of charr2 :" << strlen(charr2) << endl;
	cout << "Length of string of str :" << str.size() << endl;
	
	return 0;
}