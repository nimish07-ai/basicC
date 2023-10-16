#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
  struct Node *prev;    
  int val;
  struct Node *next;
} node;


node * InitLL(){

    printf("Enter N for number of link list");
    int n;
    scanf("%d",&n);
    node * head=NULL;

    node * prev=NULL;
    for(int i=0;i<n;i++)
    {
        int curr =0;
        printf ("%d node",i);
        scanf("%d",&curr);
        node * Cn=(node *)malloc(sizeof(node));
        Cn->val=curr;
        Cn->next=NULL;
        if (prev!=NULL){
            prev->next=Cn;
        }
        else{
            head=Cn;
         
        }

     prev=Cn;
    }


    return head;

} 

void printLL(node * head){
    printf("\n Current LinkList  is \n");
    while (head){
        printf("--> %d ",head->val);
        head=head->next;
    }
    printf("\n");
}

node * AddatPos(node *head, int pos){
    int ca;
    node * hh=head;


    printf("Enter the number at pos %d",pos);
    scanf("%d",&ca);

    node * curr=(node *)malloc(sizeof(node));
    curr->val=ca;
    if (pos == 1){
        curr->next=head;
        return curr;
    }

    int j=1;
    node * prev=NULL;
    while (j < pos && hh){
        prev=hh;
        hh=hh->next;
        j+=1;
    }

    if(j == pos){
    curr->next=hh;
    prev->next=curr;
 

    }

       return head;
}


node* Send_middle_node( node * head){
    if(!head)
    {
        return head;
    }

    node *slow=head;
    node *fast=head->next;

    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}

int Send_middle_pos( node * head){
    if(!head)
    {
        return -1;
    }
    int i=1;
    node *slow=head;
    node *fast=head->next;

    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        i+=1;
    }

    return i;
}

node* DellAtpos(node *head, int pos){
        if(pos == 1 && head){
            node *temp=head->next;
            free(head);
            return temp;
        }

        node * temp=head;
        int i=1;
        node *prev=NULL;
        while(temp && i<pos)
        {
            prev=temp;
            temp=temp->next;
            i+=1;
        }
        if(pos == i){
        prev->next=temp->next;
        free(temp);
        return head;
        }
        else{
        printf("out of bond");
        return head;
        }

    
    }

node * Reverse(node *head){
        if(!head){
            return head;
        }

        node * prev=NULL;

        while(head){
            node * temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }

        return prev;

    }



node * Create_Copy(node *head){

    if(!head){
        return head;
    }
    node * proxy=(node *) malloc(sizeof(node));
     node * proxyHead=proxy;

    while(head){
    node * curr=(node *) malloc(sizeof(node));
  
    curr->val=head->val;
    //   printf("%d ",curr->val);
    
    proxy->next=curr;
    proxy=curr;
    head=head->next;
    }
    

    return proxyHead->next;

} 


void checkPalindrome(node * head){

    node * dummy=Create_Copy(head);
        printLL(dummy);
    node *midle = Send_middle_node(dummy);
    midle = Reverse(midle->next);

    while(midle ){
        if(dummy ->val != midle->val){
        printf("Not palindrome");
        return ;
        }
        dummy = dummy->next;
        midle = dummy->next;
    }   
    printf("palindrome");
}







void printLLN(node * head,int n){
    printf("\n Current LinkList  is \n");
    int i=n;
    while (head){
        // printf("%d ",i);
        if (i == n){
        printf("--> %d ",head->val);
        i=0;
        }
        i+=1;
        head=head->next;

    }
    printf("\n");
}


int main()
{
    node * head= InitLL();
    // head=Addat(head);
    
    printLL(head);
    checkPalindrome(head);
    // head=DellAtpos(head,2);
    // printLL(head);

    // head=Reverse(head);
    // printLL(head);
    // printLLN(head,3);
    return 0;

}