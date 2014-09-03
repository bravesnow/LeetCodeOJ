#include <iostream>
#include <string>
#include <climits>
using namespace std;
struct ListNode {
    //单链表结点
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void print(ListNode *L)
{//打印链表
    while (L){
	cout<<L->val<<endl;
	L = L->next;
    }
}
ListNode *insertionSortList(ListNode *head)
{//单链表插入排序
    if (head == NULL || head->next == NULL){
	return head;
    }
    ListNode dummy(INT_MIN);//定义一个监视哨，含最小值
    dummy.next = head;
    ListNode *cur = head;//待排序的当前结点指针
    while (cur->next){
	ListNode *p = &dummy;
	while (p->next != cur->next){
	    //从头结点，寻找插入的位置
	    if (p->next->val <= cur->next->val){
		p = p->next;
	    } else {
		//插入结点
		ListNode *temp = cur->next;
		cur->next = cur->next->next;
		temp->next = p->next;
		p->next = temp;
		break;
	    }
	}
	if (p->next == cur->next){
	    cur = cur->next;
	}		
    }
    return dummy.next;
}

int main(int argc, char *argv[])
{
    ListNode a(3),b(5),c(6),d(1),e(4);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;
    
    ListNode *head = insertionSortList(&a);
    print(head);
    return 0;
}

