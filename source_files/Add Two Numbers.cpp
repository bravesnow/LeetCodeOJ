#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void print(ListNode *L)
{//打印链表
    while (L){
	cout<<L->val<<" ";
	L = L->next;
    }
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummy(-1);//头结点
    ListNode *pa = l1, *pb = l2, *prev = &dummy;
    int carry = 0;//加法进位
    int value, a, b;
    while (pa || pb){
	a = pa == nullptr ? 0 : pa->val;
	b = pb == nullptr ? 0 : pb->val;
	
	value = (a + b + carry) % 10;
	carry = (a + b + carry) / 10;

	prev->next = new ListNode(value);
	prev = prev->next;
	
	pa = pa == nullptr ? nullptr : pa->next;
	pb = pb == nullptr ? nullptr : pb->next;
    }
    if (carry){
	prev->next = new ListNode(carry);
    }
    return dummy.next;
}

int main(int argc, char *argv[])
{
    ListNode *L;
    ListNode a(5), b(5);
    ListNode *L2;
    L = &a;
    L2 = &b;
    ListNode *re = addTwoNumbers(L, L2);
    print(re);
    return 0;
}
