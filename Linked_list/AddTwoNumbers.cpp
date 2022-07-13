// You are given two non-empty linked lists representing two non-negative integers. The digits are 
// stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return 
// the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.


// struct ListNode 
// {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };



//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         //long long int a=0,b=0;
//         ListNode *curr2=l1;
//         ListNode *curr1=l2;
//         int carry=0;
//         ListNode* ans=new ListNode();
//         ListNode *head=ans;
//         while(curr1!=NULL || curr2!=NULL)
//         {
//             if(curr1!=NULL && curr2!=NULL)
//             {
//                 int x=carry+curr1->val+curr2->val;
//                 carry=x/10;
//                 ans->next=new ListNode(x%10);
//                 curr1=curr1->next;
//                 curr2=curr2->next;
//                 ans=ans->next;
//             }
//             else if(curr1!=NULL)
//             {
//                 int x=carry+curr1->val;
//                 carry=x/10;
//                 ans->next=new ListNode(x%10);
//                 curr1=curr1->next;
//                 ans=ans->next;
//             }
//             else
//             {
//                 int x=carry+curr2->val;
//                 carry=x/10;
//                 ans->next=new ListNode(x%10);
//                 curr2=curr2->next;
//                 ans=ans->next;
//             }
//         }
//         if(carry!=0)
//         {
//             ans->next=new ListNode(carry);
//             ans=ans->next;
//         }
//         return head->next;
//     }