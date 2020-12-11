/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

string SolutionStr = "The Sum is";
string ReturnValueStr = "The Return Sum is";

//  Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    /*创建单链表*/
	ListNode* createList(ListNode *head, int listNum)
	{
		int i;
		ListNode* phead=head; //不破坏头指针
		for(i=0; i<listNum; i++){
			ListNode* node=new ListNode;
			/* node->val=i */;   // no count 没有进位
			node->val=i + 4;     // has count 进位
			node->next=NULL;
			phead->next=node;
			phead=node;
		}
		cout<<"链表创建成功!\n";
        return head;
	}
    
    /*打印链表*/
	void printList(ListNode* head)
	{
		ListNode* phead=head;
		while(phead!=NULL)
		{
			cout<<phead->val<<" ";
			//cout<<phead->val * 2 <<" ";
			phead=phead->next;
		}
		cout<<"\n";
	}	

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=1;//记录l1的长度
        int len2=1;//记录l2的长度
        ListNode* p=l1; // list 1
        ListNode* q=l2; // list 2
        while(p->next!=NULL)//获取l1的长度
        {
            len1++;
            p=p->next;
        }
        while(q->next!=NULL)//获取l2的长度
        {
            len2++;
            q=q->next;
        }
        
        if(len1>len2)//l1较长，在l2末尾补零
        {
            for(int i=1;i<=len1-len2;i++)
            {
                q->next=new ListNode(0);
                q=q->next;
            }
        }
        else//l2较长，在l1末尾补零
        {
            for(int i=1;i<=len2-len1;i++)
            {
                p->next=new ListNode(0);
                p=p->next;
            }
        }

        p=l1;  // go back to set to the header of list 1
        q=l2;  // go back to set to the header of list 2
        bool count=false;//记录进位
        ListNode* l3=new ListNode(-1);//存放结果的链表
        ListNode* w=l3;//l3的移动指针, list 3 points to the header of w
        int sum=0;//记录相加结果
        while(p!=NULL&&q!=NULL)
        {
            sum= count + p->val + q->val;  // the sum of one bit
            w->next=new ListNode(sum%10);
            count= sum>=10 ? true:false;
            w=w->next;
            p=p->next; q=q->next; 
        }
        if(count)//若最后还有进位
        {
            w->next=new ListNode(1);   // last bit
            w=w->next;
        }
        return l3->next; 
    }
};

int main(void)
{
    ListNode* returnValue;
    ListNode* head1 = new ListNode();
    ListNode* head2 = new ListNode();
    ListNode* result;
    int listNumt1 = 4;
    int listNumt2 = 3;
    static ListNode* returnHead1;
    static ListNode* returnHead2;
    Solution t1 = Solution();
    returnHead1 = t1.createList(head1, listNumt1);  //list 1:  0->1->2->3
    cout << "first list is " << endl;
    t1.printList(returnHead1);   // print the list 1

    cout << "============= " << endl;

    returnHead2 = t1.createList(head2, listNumt2);  //list 2:  0->1->2
    cout << "Second list is " << endl;
    t1.printList(returnHead2); // print the list 2

    result =  t1.addTwoNumbers(returnHead1, returnHead2); // input the two lists head
    t1.printList(result);
    
    return 0;
    
}
