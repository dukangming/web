/*˼·���Ƚ���һ��string����a[]��Ȼ��ȡ���������ֵ���Ӧ��ASCII�룬����num[]�У�֮���ж�ȡ�����Ƿ�Ϊ���ֵ�ASCII�룬��Ϊ���ֵ�ASCII�룬�����Ӧ��
string�ַ�����ֵת��Ϊint�ͣ��ٴ���num[]�У�֮�����num[]�������򲢵���a[]��˳�������������*/ 
 
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cout<<"������Ҫ������ٸ�Ԫ��"<<endl;
	cin>>n;
	string a[n];
	cout<<"������Ԫ��" <<endl; 
	//��ʼ��string����
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
	}
	int num[n];//num[]���ڴ��ASCII�� 
	//ȡASCII��
	for(int i=0;i<n;i++) 
	{
		num[i]=(int)a[i][0];
	}
	//��ȡ�����ֵ�ASCII���ʱ�򽫶�Ӧ��string�ַ���������ת��Ϊint�ͣ�����num[]���� 
	for(int i=0;i<n;i++)
	{
		if(num[i]>47&&num[i]<58)
		{
			num[i] = atoi(a[i].c_str());
		}
	}
	int temp1;//�����м�ֵ 
	string temp2;//�ַ����ַ����м�ֵ 
	//��������
	for(int i=0;i<n;i++) 
	{
		for(int j=0;j<n-i;j++)
		{
			if(num[j]>num[j+1])
			{
				//num[]���� 
				temp1=num[j]; 
				num[j]=num[j+1];
				num[j+1]=temp1;
				//��Ӧ��string����a[]һ������ 
				temp2=a[j];
				a[j]=a[j+1];
				a[j+1]=temp2;
			}
		}
	}
	for(int i=0;i<n;i++)//��ӡ 
	{
		cout<<a[i]<<" ";
	}
	return 0;
} 