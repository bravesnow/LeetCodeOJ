#include <iostream>
using namespace std;
struct ListNode {
    //������ṹ��(c++)
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void print(ListNode *L)
{//��ӡ����
    while (L){
	cout<<L->val<<endl;
	L = L->next;
    }
}
ListNode *mergeList(ListNode *h1, ListNode *h2){
    //�ϲ���������
    if (h1 == NULL)
	return h2;
    if (h2 == NULL)
	return h1;
    ListNode *h;//ͷָ��
    if (h1->val <= h2->val){
	h = h1;
	h1 = h1->next;
    }
    else {
	h = h2;
	h2 = h2->next;
    }
    ListNode *p = h;//βָ��
    while (h1 && h2){
	if (h1->val <= h2->val){
	    p->next = h1;
	    h1 = h1->next;
	    p = p->next;
	}
	else {
	    p->next = h2;
	    h2 = h2->next;
	    p = p->next;
	}	    
    }    
    if (h1)
	p->next = h1;
    if (h2)
	p->next = h2;
    return h;
}
ListNode *sortList(ListNode *head)
{
    //�鲢����O(nlogn)��ԭ������
    if (head == NULL || head->next == NULL){
	return head;
    }
    ListNode *fast = head, *slow = head;
    while (fast->next != NULL && fast->next->next != NULL){
	fast = fast->next->next;
	slow = slow->next;
    }
    fast = slow;
    slow = slow->next;
    fast->next = NULL;
    ListNode *h1 = sortList(head);
    ListNode *h2 = sortList(slow);
    return mergeList(h1,h2);
}
int main(int argc, char *argv[])
{
    //��������
    ListNode a(3),b(6),c(5),d(1),e(4);
    ListNode *head = &a;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;
    head = sortList(head);
    print(head);
    return 0;
}
