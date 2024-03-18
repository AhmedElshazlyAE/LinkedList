#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

node *head = NULL;

node *make(int data)
{
    node *n = malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

void insertFront(int data)
{
    node *n = make(data);
    n->next = head;
    head = n;
}

void insertEnd(int data)
{
    node *n = make(data);
    node *temp = head;

    if(head == NULL)
    {
        head = n;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAfter(int data,int key)
{
    node *n = make(data);
    node *temp = head;

    if(head == NULL)
    {
        return;
    }
    while (temp->next != NULL)
    {
        if(temp->data == key)
        {
            node *t = temp->next;
            temp->next = n;
            n->next = t;
            return;
        }
        temp = temp->next;
    }
    temp->next = n;
}


void insertBetween(int data,int a,int b)
{
    node *n = make(data);
    node *temp = head;

    if(head == NULL)
    {
        return;
    }
    while (temp->next != NULL)
    {
        if(temp->data == a && temp->next->data == b)
        {
            node *t = temp->next;
            temp->next = n;
            n->next = t;
            return;
        }
        temp = temp->next;
    }
    temp->next = n;
}

void deleteLast()
{
    node *temp = head;
    if(temp == NULL) return;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    free(temp->next);
}



void deleteFirst()
{
    if(head == NULL) return;
    node *temp = head;
    head = temp->next;
    free(temp);
    temp = NULL;
}

void deleteKey(int key)
{
    if(head->data == key)
    {
        node *delnode = head;
        head = head->next;
        free(delnode);
        return;
    }
    if(head == NULL) return;
    node *temp = head;
    while (temp->next != NULL)
    {
        if(temp->next->data == key)
        {
            node *delnode = temp->next;
            temp->next= temp->next->next;
            free(delnode);
            return;
        }
        temp = temp->next;
    }

}



void display()
{
    node *temp = head;
    while (temp)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
}

int main ()
{
    insertEnd(300);
    insertEnd(500);
    insertEnd(500);
    insertEnd(700);
    insertEnd(500);
    insertEnd(800);
    insertEnd(900);
    insertEnd(1000);
    insertBetween(700,500,800);
    display();
}
