#include<bits/stdc++.h>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     // ListNode* p1 = l1, *p2 = l2;          
     //int value = (l1->val + l2->val) % 10;
     //int tem = (l1->val + l2->val)/10;
     int carry = 0;
     //ListNode* l3 = new ListNode(value);
     ListNode* DummyHead = new ListNode(0), * p = DummyHead; //需要建立l3链表，但由于没有数据，用dummyHead
     while (l1 != nullptr || l2 != nullptr || carry != 0) //三个条件只要满足一个就要继续循环(做加法)
     {
         int v1 = l1 ? l1->val : 0;
         int v2 = l2 ? l2->val : 0;
         int value = (v1 + v2 + carry) % 10;
         carry = (v1 + v2 + carry) / 10;
         p->next  = new ListNode(value);
         p = p->next;
         l1 = l1? l1->next : nullptr;
         l2 = l2? l2->next : nullptr;
     }
     return DummyHead->next;
 }



int main()
{
    ListNode* tem2 = new ListNode(3);               // 用new 调用构造函数，构造新对象
    ListNode* tem1 = new ListNode(4, tem2);
    ListNode* l1 = new ListNode(2,tem1);
    
    ListNode* tem4 = new ListNode(4);
    ListNode* tem3 = new ListNode(6, tem4);
    ListNode* l2 = new ListNode(5, tem3);           

    // l1: 2 4 3,  l2: 5 6 4

    ListNode* l3 = addTwoNumbers(l1, l2);
    return 0;
    
}





