
#include<bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node{

    int data;
    Node *next;

};

Node *create_node(int item, Node *next)
{
    Node *new_node = (Node *) malloc(sizeof(Node));

    if(new_node == NULL)
    {
        cout<<"Error !! Could not Create A New Node"<<endl;
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;

    return new_node;
}


Node *prepend(Node *head, int item)
{
    Node *new_node = create_node(item,head);

    return new_node;
}

Node *append(Node *head, int item)
{
    Node *new_node = create_node(item, NULL);

    if(head == NULL)
    {
        return new_node;
    }

    Node *current_node = head;

    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }

    current_node->next = new_node;

    return head;
}

void print_linked_list(Node *head)
{
    Node *current_node = head;
    while(current_node != NULL)
    {
        cout<<current_node->data<<endl;

        current_node = current_node->next;
    }

    cout<<endl<<endl;
}

int count (Node *head)
{

    if(head == NULL)
        return 0;

    Node *current_node = head;

    int cnt = 1;

    while(current_node->next != NULL)
    {
        current_node = current_node->next;
        cnt++;
    }

    return cnt;
}

Node *search(Node *head, int item)
{

    if(head == NULL)
        return NULL;

    Node *current_node = head;

    while(current_node != NULL)
    {
        if(current_node->data == item)
            return current_node;

        current_node = current_node->next;
    }

    return NULL;
}
Node *remove_node(Node *head, Node *node)
{
    if(node == head)
    {
        head = node->next;
        free(node);

        return head;
    }

    Node *current_node = head;

    while(current_node != NULL)
    {
        if(current_node->next == node)
            break;

        current_node = current_node->next;
    }

    if(current_node == NULL)
        return head;
    current_node->next = node->next;

    free(node);

    return head;
}

void insert(Node *node, int item)
{
    Node *new_node = create_node(item, node->next);

    node->next = new_node;
}


int main()
{
    cout<<"Hei there !"<<endl;

    Node *n, *m, *p, *head;

    // Creating a node

    n = create_node(11,NULL);
    head = n;



    cout<<"Number of Node = "<<count(head)<<endl;

    //Printing all element of linked list
    print_linked_list(head);


    // Adding a node before head
    head = prepend(head, 20);

    cout<<"Number of Node = "<<count(head)<<endl;
    print_linked_list(head);



    //Adding a node at the end of the linked list.
    head = append(head, 30);

    cout<<"Number of Node = "<<count(head)<<endl;
    print_linked_list(head);


    Node *pp;
    //searching a node through data.
    cout<<"Searching for 30"<<endl;
    pp = search(head, 30);


    if(pp != NULL)
        cout<<"Object found"<<endl<<endl;
    else
        cout<<"Object Not found"<<endl<<endl;


    insert(n,100);

    cout<<"Number of Node = "<<count(head)<<endl;
    print_linked_list(head);

    //removing a node of link list.
    head = remove_node(head,head);

    cout<<"Number of Node = "<<count(head)<<endl;
    print_linked_list(head);



    return 0;
}
