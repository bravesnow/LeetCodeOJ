#include <iostream>
using namespace std; 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void travel(ListNode *pNode)
{//当前结点遍历链表
    while (pNode) {
	cout<<pNode->val<<endl;
	pNode = pNode->next;
    }
}
ListNode *deleteDuplicates(ListNode *head)
{//解法不优。。。
    if (head == NULL || head->next == NULL) {
	return head;
    }
    ListNode dummy(0);
    ListNode *tailp = &dummy;    
    ListNode *curp = head, *nextp = head->next;
    while (nextp) {
	if (curp->val == nextp->val) {
	    nextp = nextp->next;
	    
	} else {
	    if (curp->next == nextp) {
		tailp->next = curp;
		tailp = tailp->next;
	    }
	    curp = nextp;
	    nextp = nextp->next;	    
	}
    }
    if (curp->next == NULL) {
	tailp->next = curp;
	tailp = tailp->next;
    }
    tailp->next = NULL;
    return dummy.next;
}
int main(int argc, char *argv[])
{
    ListNode a(1), b(2), c(3), d(4), e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    travel(deleteDuplicates(&a));

    return 0;
}
