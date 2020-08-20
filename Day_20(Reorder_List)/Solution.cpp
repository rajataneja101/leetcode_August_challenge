class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        stack<ListNode*> ListStack;
        ListNode *current=slow->next;
        while(current!=NULL){
            cout<<"Pushed "<<current->val<<endl;
            ListStack.push(current);
            current=current->next;
        }
        slow->next=NULL;
        ListNode *temp=NULL;
        slow=head;
        while(ListStack.size() > 0){
            temp=ListStack.top();
            temp->next=slow->next;
            slow->next=temp;
            slow=slow->next->next;
            cout<<"Popped "<<temp->val<<endl;
            ListStack.pop();
        }
        return;
    }
};