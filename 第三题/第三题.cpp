/*思路：先建立一个string数组a[]，然后取其各个数组值相对应的ASCII码，放入num[]中，之后判断取到的是否为数字的ASCII码，若为数字的ASCII码，则将相对应的
string字符串的值转化为int型，再存入num[]中，之后根据num[]进行排序并调整a[]的顺序，最终排序完成*/ 
 
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cout<<"请输入要输入多少个元素"<<endl;
	cin>>n;
	string a[n];
	cout<<"请输入元素" <<endl; 
	//初始化string数组
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
	}
	int num[n];//num[]用于存放ASCII码 
	//取ASCII码
	for(int i=0;i<n;i++) 
	{
		num[i]=(int)a[i][0];
	}
	//当取到数字的ASCII码的时候将对应的string字符串的数字转化为int型，存入num[]数组 
	for(int i=0;i<n;i++)
	{
		if(num[i]>47&&num[i]<58)
		{
			num[i] = atoi(a[i].c_str());
		}
	}
	int temp1;//数字中间值 
	string temp2;//字符或字符串中间值 
	//进行排序
	for(int i=0;i<n;i++) 
	{
		for(int j=0;j<n-i;j++)
		{
			if(num[j]>num[j+1])
			{
				//num[]排序 
				temp1=num[j]; 
				num[j]=num[j+1];
				num[j+1]=temp1;
				//对应的string数组a[]一起排序 
				temp2=a[j];
				a[j]=a[j+1];
				a[j+1]=temp2;
			}
		}
	}
	for(int i=0;i<n;i++)//打印 
	{
		cout<<a[i]<<" ";
	}
	return 0;
} 