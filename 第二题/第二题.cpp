/*思路：将链表p->link=p->link->link;这样就能奇数对奇数偶数对偶数，然后提前定义一个 evenhead（偶数的第一个节点）等奇数结束后，
可以直接指向此节点做到奇数和偶数的更换*/ 

#include<iostream>
using namespace std;
struct Node; //单链表结点类型
typedef struct Node * PNode; //结点指针类型
struct Node { //单链表结点结构
	int num;//链表内数据 
	PNode link;
};
typedef struct Node * LinkList ; //单链表类型


//初始化并创建一个链表 
LinkList creatlink(int n) 
{
	LinkList llist=new Node;//llist为头节点 
	llist->link=NULL;
	PNode q=new Node;//q用来记录每次插入后的新位置 
	q=llist;
	cout<<"请输入数据"<<endl; 
	for(int i=n;i>0;--i)
	{
		
		PNode p=new Node;
		cin>>p->num;
		p->link=q->link;//插入节点 
		q->link=p;
		q=p;//记录新位置 
	}
	return llist;
}


//把所有的奇数节点和偶数节点分别排在一起
PNode oddevennum(LinkList llist){
	PNode head=llist->link;//head为第一个节点 
	PNode odd=head;//奇数节点为第一个节点 
	PNode even=head->link;//偶数节点为第二个节点 
	PNode evenhead=head->link;//方便用来记录当奇数节点到NULL后 ，再去指向偶数的第一个节点 
	while(even!=NULL&&even->link!=NULL){
            odd->link=odd->link->link;//奇数的->link变为 ->link->link
            odd=odd->link;//奇数下一个奇数 
            even->link=even->link->link;//偶数的->link变为 ->link->link
            even=even->link;//偶数下一个偶数
        }
        odd->link=evenhead;//奇数结束后去指向偶数的第一个节点 
        return head;
}

int main()
{
	int n;
	cout<<"请输入要输入数的个数"<<endl;
	cin>>n;
	LinkList p=new Node;
	p=creatlink(n);//初始化链表 
	PNode q;
	q=oddevennum(p);//把所有的奇数节点和偶数节点分别排在一起
	for(int i=n;i>0;--i)//打印 
	{
		cout<<q->num<<"->";
		q=q->link;
	}
	cout<<"NULL";
	return 0;
}

