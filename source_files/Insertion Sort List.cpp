#include <iostream>
#include <string>
#include <climits>
using namespace std;
struct ListNode {
    //��������
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
ListNode *insertionSortList(ListNode *head)
{//�������������
    if (head == NULL || head->next == NULL){
	return head;
    }
    ListNode dummy(INT_MIN);//����һ�������ڣ�����Сֵ
    dummy.next = head;
    ListNode *cur = head;//������ĵ�ǰ���ָ��
    while (cur->next){
	ListNode *p = &dummy;
	while (p->next != cur->next){
	    //��ͷ��㣬Ѱ�Ҳ����λ��
	    if (p->next->val <= cur->next->val){
		p = p->next;
	    } else {
		//������
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

