#include"linkedlist.h"
#include<stack>
extern int m;
stack<int> st;

//Iterative Version
node* find_mid(node* head)
{
    node *slow,*fast;
    slow = fast = head;
    while(fast->next!=NULL)
    {
        fast = fast->next;
        if(!fast->next)
            return slow;
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

bool palindrome(node *head)
{
    node *temp = find_mid(head);
    node *cur = head;
    while(cur!=temp)
    {
        st.push(cur->data);
        cur = cur->next;
    }
    if(m%2==0)
        st.push(cur->data);
    cur = cur->next;
    while(cur!=NULL)
    {
        if(st.top()==cur->data)
        {
            cur = cur->next;
            st.pop();
        }
        else
            return 0;
    }
    return 1;
}

//Recursive Version

node* palin_recursive(node *head, int len)
{
    if(!head || len==0)
        return NULL;
    else if(len==1)
    {
        if(!(head->next))
            return head;
        else
            return head->next;
    }
    else if(len==2)
    {
        if(head->data == head->next->data)
            return head->next->next;
        else
            return NULL;
    }
    node *res = palin_recursive(head->next, len-2);
    if(!res)
        return NULL;
    if(res->data == head->data)
    {
        if(res->next==NULL)
            return res;
        else
            return res->next;
    }
    else
        return NULL;
}

int main()
{
    node *head, *temp;
    head = llist();
    printlist(head);
    cout<<endl<<endl<<"Iterative says: ";
    if(palindrome(head))
        cout<<"Yes.";
    else
        cout<<"No.";
    cout<<endl<<"Recursive says: ";
    if(palin_recursive(head,m))
        cout<<"Yes.";
    else
        cout<<"No.";
    return 0;
}
