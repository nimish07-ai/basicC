#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    int val;
};

struct Node * init(){
    int n;
    scanf("%d", &n);
    struct Node * head=NULL;
    struct Node * prev=NULL;

    for(int i=0; i<n; i++){
        int tmp;
        scanf("%d", &tmp);
        
        struct Node * curr=(struct Node *)malloc(sizeof(struct Node));
        curr->val=tmp;
        curr->next=NULL; 

        if(prev!=NULL){
            prev->next=curr;
        }
        else{
            head=curr;
        }
        prev=curr;
    }
    return head;
}


void print(struct Node * head){
    while(head){
        printf("%d ",head->val);
        head=head->next;
    }
    printf("\n");
}

struct Node * add_at_pos(struct Node * head){
    int n;
    scanf("%d",&n);
    int val;
    scanf("%d",&val);

    struct Node * curr=(struct Node *)malloc(sizeof(struct Node));
    curr->val=val;
    curr->next=NULL;

    if(n == 1){
        curr->next=head;
        return curr;
    }    


    int j =1;
    struct Node * prev=NULL;
    struct Node * ph=head;
    while(j<n && ph){
        prev=ph;
        ph=ph->next;
        j++;
    }

    if(j == n)
    {
        prev->next=curr;
        curr->next=ph;
    }

    return head;
}

struct Node * middle_val(struct Node * head){
    if(!head){
        return head;
    }

    struct Node * prev=head;
    struct Node * slow=head;
    struct Node * fast=head->next;

    while(fast && fast->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}


struct Node * recv(struct Node * head){
    if (!head){
        return head;
    }

    struct Node * prev =NULL;
    while(head){
        struct Node * tmp=head->next;
        head->next=prev;
        prev=head;
        head=tmp;
    }
    return prev;

}





int main(){
    struct Node * head=init();
    print(head);
    // head=add_at_pos(head);
    // print(head);

    // struct Node* mid=middle_val(head);
    // print(mid);
    head=recv(head);
    print(head);
    

    return 0;
}