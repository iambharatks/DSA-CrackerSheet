/* Program to split a circular linked list into two halves */
#include <stdio.h>
#include <stdlib.h>
/* structure for a Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void splitList(struct Node *head, struct Node **head1_ref, struct Node **head2_ref);
struct Node *newNode(int key)
{
    struct Node *temp = new Node(key);
    return temp;
}
/* Function to split a list (starting with head) into two lists.
head1_ref and head2_ref are references to head Nodes of
the two resultant linked lists */
void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}
int main()
{
    int t, n, i, x;
    scanf("%d", &t);
    while (t--)
    {
        struct Node *temp, *head = NULL;
        struct Node *head1 = NULL;
        struct Node *head2 = NULL;
        scanf("%d", &n);
        scanf("%d", &x);
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++)
        {
            scanf("%d", &x);
            temp->next = new Node(x);
            temp = temp->next;
        }
        temp->next = head;
        splitList(head, &head1, &head2);
        // printf("\nFirst Circular Linked List");
        printList(head1);
        // printf("\nSecond Circular Linked List");
        printList(head2);
    }
    return 0;
}

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node *middle = head, *fast = head, *current = head;
    Node *first, *second;
    Node *prev;
    do
    {
        middle = middle->next;
        fast = fast->next->next;

    } while (middle != head && fast != head && fast->next != head);

    while (current != middle)
    {
        first = new Node(current->data);
        if (*head1_ref == NULL)
            *head1_ref = first;
        else
            prev->next = first;
        prev = first;
        current = current->next;
    }
    if (fast->next == head)
    {
        first = new Node(current->data);
        prev->next = first;
        current = current->next;
    }
    first->next = *head1_ref;
    while (current != head)
    {
        second = new Node(current->data);
        if (*head2_ref == NULL)
            *head2_ref = second;
        else
            prev->next = second;
        prev = second;
        current = current->next;
    }
    second->next = *head2_ref;
}