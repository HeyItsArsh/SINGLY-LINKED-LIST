#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// FUNCTION PROTOTYPES
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAfterNode(int data, int key);
void deleteNode(int key);
void displayList();
void countNodes();
void demonstrateTraversal();
void freeAllNodes();

void pressEnter() {
    printf("\nPress Enter to continue...");
    getchar();
}

int main() {
    int choice, data, key;

    printf("===============================================================================\n");
    printf("              SINGLY LINKED LIST - COMPLETE IMPLEMENTATION\n");
    printf("                      WITH STEP-BY-STEP EXPLANATION\n");
    printf("===============================================================================\n\n");

    printf("Welcome to the Singly Linked List Demonstration!\n");
    printf("This program will show you every step of how a Singly Linked List works.\n");

    while (1) {
        printf("\n-------------------------------------------------------------------------------\n");
        printf("MAIN MENU\n");
        printf("-------------------------------------------------------------------------------\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Node\n");
        printf("4. Delete Node\n");
        printf("5. Display List\n");
        printf("6. Count Nodes\n");
        printf("7. Demonstrate Traversal\n");
        printf("8. Exit\n");
        printf("-------------------------------------------------------------------------------\n");
        printf("Enter your choice (1-8): ");
        scanf("%d", &choice);
        getchar(); // CONSUME NEW LINE

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                getchar();
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                getchar();
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter data of the node after which to insert: ");
                scanf("%d", &key);
                getchar();
                insertAfterNode(data, key);
                break;
            case 4:
                printf("Enter data of node to delete: ");
                scanf("%d", &key);
                getchar();
                deleteNode(key);
                break;
            case 5:
                displayList();
                break;
            case 6:
                countNodes();
                break;
            case 7:
                demonstrateTraversal();
                break;
            case 8:
                printf("\nThank you for using the Singly Linked List Demo!\n");
                printf("Hope you learned how Singly Linked Lists work!\n");
                freeAllNodes();
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void insertAtBeginning(int data) {
    printf("\n-------------------------------------------------------------------------------\n");
    printf("INSERTING AT BEGINNING - Data: %d\n", data);
    printf("-------------------------------------------------------------------------------\n");

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Allocating memory for new node with data: %d\n", data);
    printf("Memory allocated successfully at address: %p\n", newNode);
    newNode->data = data;
    newNode->next = head;

    printf("New node created successfully!\n   Address: %p\n   Data: %d\n", newNode, newNode->data);
    printf("   Next: %p\n", newNode->next);

    head = newNode;
    printf("New node set as head.\n");
    displayList();
}

void insertAtEnd(int data) {
    printf("\n-------------------------------------------------------------------------------\n");
    printf("INSERTING AT END - Data: %d\n", data);
    printf("-------------------------------------------------------------------------------\n");

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Allocating memory for new node with data: %d\n", data);
    printf("Memory allocated successfully at address: %p\n", newNode);
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        printf("List was empty. New node becomes the head.\n");
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        printf("New node added after node with data: %d\n", temp->data);
    }

    displayList();
}

void insertAfterNode(int data, int key) {
    printf("\n-------------------------------------------------------------------------------\n");
    printf("INSERTING AFTER NODE - Insert %d after node with data %d\n", data, key);
    printf("-------------------------------------------------------------------------------\n");

    struct Node *temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with data %d not found!\n", key);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Allocating memory for new node with data: %d\n", data);
    printf("Memory allocated successfully at address: %p\n", newNode);
    newNode->data = data;

    newNode->next = temp->next;
    temp->next = newNode;

    printf("New node inserted after node with data %d\n", key);
    displayList();
}

void deleteNode(int key) {
    printf("\n-------------------------------------------------------------------------------\n");
    printf("DELETING NODE - Data: %d\n", key);
    printf("-------------------------------------------------------------------------------\n");

    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    if (head->data == key) {
        head = head->next;
        printf("Deleting head node with data: %d (Address: %p)\n", temp->data, temp);
        free(temp);
        displayList();
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found!\n", key);
        return;
    }

    printf("Node found! Data: %d at address: %p\n", temp->data, temp);
    prev->next = temp->next;
    printf("Updating previous node (%d) next pointer to skip deleted node.\n", prev->data);
    free(temp);
    printf("Node deleted successfully!\n");
    displayList();
}

void displayList() {
    printf("\n-------------------------------------------------------------------------------\n");
    printf("CURRENT LIST STATUS\n");
    printf("-------------------------------------------------------------------------------\n");

    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Head pointer points to: %p\nList elements (forward traversal): ", head);
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");

    printf("\nPOINTER CONNECTIONS:\n");
    temp = head;
    while (temp != NULL) {
        printf("   Node %d:\n      Address: %p\n      Next -> %p\n", temp->data, temp, temp->next);
        temp = temp->next;
    }
}

void countNodes() {
    printf("\n-------------------------------------------------------------------------------\n");
    printf("COUNTING NODES IN THE LIST\n");
    printf("-------------------------------------------------------------------------------\n");

    struct Node *temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        printf("   Node %d: data = %d, address = %p\n", count, temp->data, temp);
        temp = temp->next;
    }

    printf("\nTOTAL NODES COUNTED: %d\n", count);
}

void demonstrateTraversal() {
    printf("\n-------------------------------------------------------------------------------\n");
    printf("DEMONSTRATING TRAVERSAL\n");
    printf("-------------------------------------------------------------------------------\n");

    if (head == NULL) {
        printf("List is empty! Nothing to traverse.\n");
        return;
    }

    struct Node *temp = head;
    int step = 1;

    printf("Starting from head node: %d\n\n", head->data);
    while (temp != NULL) {
        printf("Step %d: Current node = %d, Next node = ", step++, temp->data);
        if (temp->next)
            printf("%d\n", temp->next->data);
        else
            printf("NULL\n");
        temp = temp->next;
    }

    printf("Traversal complete.\n");
}

void freeAllNodes() {
    struct Node *temp = head;
    printf("\nCleaning up: Freeing all remaining nodes...\n");
    while (temp != NULL) {
        struct Node *next = temp->next;
        printf("   Freeing node with data: %d\n", temp->data);
        free(temp);
        temp = next;
    }
}
