#include <bits/stdc++.h>
Node *merge(Node * node1, Node * node2)
{
    Node *temp = new Node(0);
    Node *res = temp;
    while (node1 != NULL && node2 != NULL)
    {
        if (node1->data < node2->data)
        {
            temp->child = node1;
            node1 = node1->child;
            temp = temp->child;
        }
        else
        {
            temp->child = node2;
            node2 = node2->child;
            temp = temp->child;
        }
    }
    if (node1 != NULL)
    {
        temp->child = node1;
    }
    else
    {
        temp->child = node2;
    }
    return res->child;
}
Node *flattenLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    head->next = flattenLinkedList(head->next);
    head = merge(head, head->next);
    return head;
}
//time complexity : O(N) * O(2M)
//space complexity : O(n) // recursive stack space