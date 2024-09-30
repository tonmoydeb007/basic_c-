#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node* head)
{
    struct node *ptr=head;
    printf("\n");
    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr= ptr->next;
    }
}
struct node* add_at_beg( struct node *head, int val)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = NULL;

    ptr->next = head;
    head = ptr;

    return head;
};

void add_at_end(struct node *head, int value)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = value;
    ptr->next = NULL;

    struct node* temp = head;
    while(temp->next != NULL){
         temp = temp->next;
    }
    temp ->next = ptr;

}

void add_at_pos(struct node* head, int val, int pos){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = NULL;

    struct node *temp1 = head;
    pos--;
    while(pos != 1){
        temp1 = temp1 ->next;
        pos--;
    }
    ptr-> next = temp1->next;
    temp1-> next = ptr;
}

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head ->data = 30;
    head ->next =NULL;
    display(head);
    head = add_at_beg(head, 20);
    add_at_end(head, 40);
    display(head);

    add_at_pos(head, 35, 3);
    display(head);
    return 0;
}