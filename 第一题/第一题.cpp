/*思路：先第一次遍历字符串，将每个字母出现次数记录；再第二次遍历字符串，找出第一个出现次数为一的字母，并返回他的索引*/ 


#include<iostream>
using namespace std;
const int MaxNum = 100;
struct SeqString//顺序表结构
{
    int length;//长度
    char c[MaxNum];//存储数据
};
typedef struct SeqString* PSeqString;

//声明 
PSeqString creatString();
int find(PSeqString p);

//创建并初始化一条字符串
PSeqString creatString()
{
    PSeqString pstr = new SeqString;
    cout << "输入其中一个字符串"<<endl;
    cin >> pstr->c;
    pstr->length = strlen(pstr->c);//字符串长度 
    return pstr;
}

//找到第一个不重复的字符，并返回它的索引 
int find(PSeqString p) 
{
    int a[256];
    int i,num=-1;
    memset(a,0,1024);//初始化数组 
    if(p->length)
	{          
        for(i=0;i<p->length;i++)//第一次遍历，记录每个字母出现次数 
        {
            a[p->c[i]]++;
        }
        for(i=0;i<p->length;i++)//找出第一个出现次数为一的字母，并记录他的索引 
        {
            if(a[p->c[i]]==1)
			{          
                num = i;
                break;
            }
        }
    }
    return num;//返回对应的索引或-1 
    
}

//主函数 
int main()
{
    PSeqString p = new SeqString;
    p = creatString();//创建并初始化字符串 
    int num=find(p);// 找到第一个不重复的字符，并返回它的索引 
    cout<<num<<endl;//打印 
    return 0; 
}