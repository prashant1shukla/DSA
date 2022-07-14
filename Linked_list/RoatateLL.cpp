//Given the head of a linked list, rotate the list to the right by k places.


// ListNode* rotateRight(ListNode* head, int k) {
//         if(head==NULL)
//             return NULL;
//         if(k==0)
//             return head;
//         ListNode* curr=head;
//         ListNode* curr1=head;
//         ListNode* ans=head;
//         ListNode* prev=head;
//         int p=0;
//         while(curr1!=NULL)
//         {
//             p++;
//             curr1=curr1->next;
//         }
//         k=k%p;
//         if(k==0)
//             return head;
//         for(int i=0;i<k-1;i++)
//         {
//             if(curr==NULL)
//                 return NULL;
//             curr=curr->next;
//         }
//         while(curr->next!=NULL)
//         {
//             curr=curr->next;
//             prev=ans;
//             ans=ans->next;   
//         }
//         curr->next=head;
//         prev->next=NULL;
//         return ans;
//     }