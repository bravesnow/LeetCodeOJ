#include <iostream>
#include <string>
using namespace std;
struct ListNode {
    //c++中结构体单链表
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
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{//合并有序链表
    if (l1 == NULL)
	return l2;
    if (l2 == NULL)
	return l1;
    ListNode *h;//头指针
    if (l1->val <= l2->val){
	h = l1;
	l1 = l1->next;
    }
    else {
	h = l2;
	l2 = l2->next;
    }
    ListNode *p = h;//尾指针
    while (l1 && l2){
	if (l1->val <= l2->val){
	    p->next = l1;
	    l1 = l1->next;
	    p = p->next;
	}
	else {
	    p->next = l2;
	    l2 = l2->next;
	    p = p->next;
	}	    
    }    
    if (l1)
	p->next = l1;
    if (l2)
	p->next = l2;
    return h;
}
int main(int argc, char *argv[])
{
    ListNode a(3),b(5),c(6),d(1),e(4);
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    
    d.next = &e;
    e.next = NULL;
    
    ListNode *head = mergeTwoLists(&a,&d);
    print(head);
    return 0;
}
