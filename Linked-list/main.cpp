#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        cout << "I am inside parameterized constructor with data: " << data << endl;
    }
    ~Node()
    {
        cout << "destructor called" << endl;
    }
};

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int getLengthLL(Node *head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    cout << "Length of linked list: " << length << endl;
    return length;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insertAttail(Node *&head, Node *&tail, int data)
{
    // create new node
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        // link the new node with the last node
        tail->next = newNode;
        // update the tail
        tail = newNode;
    }
}

void insertPosition(Node *&head, Node *&tail, int data, int position)
{
    int length = getLengthLL(head);
    // Get the current length of the linked list
    if (position < 1 || position > length + 1)
    {
        // Check for valid position
        cout << "Invalid position" << endl;
        return;
    }
    if (position == 1)
    { // Insert at the head
        insertAtHead(head, tail, data);
        return;
    }
    if (position == length + 1)
    { // Insert at the tail
        insertAttail(head, tail, data);
        return;
    }

    Node *newNode = new Node(data);
    // Create the new node
    Node *temp = head;
    int currentPosition = 1;
    while (currentPosition < position - 1)
    {
        temp = temp->next;
        currentPosition++;
    }
    newNode->next = temp->next; // Link the new node with the next node
    temp->next = newNode;       // Link the current node with the new node
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    int len = getLengthLL(head);
    // empty list
    if (head == NULL)
    {
        cout << "Cannot delete, linked list is empty" << endl;
        return;
    }
    if (position < 1 || position > len)
    {
        cout << "Invalid position" << endl;
        return;
    }
    // Deleting the only node in the list
    if (head == tail)
    {
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    // Deleting the head node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    // Deleting the tail node
    if (position == len)
    {
        Node *prev = head;
        while (prev->next != tail)
        {
            prev = prev->next;
        }
        prev->next = NULL;
        delete tail;
        tail = prev;
        return;
    }
    // Deleting a node from the middle
    Node *prev = NULL;
    Node *curr = head;
    for (int i = 1; i < position; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

int main()
{
    Node *head = NULL; // Initialize head as NULL
    Node *tail = NULL; // Initialize tail as NULL

    cout << "Creating first node" << endl;
    insertAttail(head, tail, 10);

    cout << "Creating second node" << endl;
    insertAtHead(head, tail, 20);

    cout << "Creating third node" << endl;
    insertAttail(head, tail, 30);

    cout << "Creating fourth node" << endl;
    insertAtHead(head, tail, 40);

    cout << "Creating fifth node" << endl;
    insertPosition(head, tail, 50, 3);

    printLL(head);
    getLengthLL(head);
    deleteNode(head, tail, 1);

    printLL(head);
    getLengthLL(head);

    return 0;
}
