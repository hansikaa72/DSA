#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertFront(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void insertBefore(int key, int value)
{
    struct Node *current, *newNode;
    current = head;

    while (current != NULL && current->data != key)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Song %d not found\n", key);
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = current;
    newNode->prev = current->prev;

    if (current->prev != NULL)
        current->prev->next = newNode;
    else
        head = newNode;

    current->prev = newNode;

    printf("Song inserted successfully\n");
}

void deleteSong(int key)
{
    struct Node *current;
    current = head;

    while (current != NULL && current->data != key)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Song %d not found\n", key);
        return;
    }

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        head = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
    printf("Song %d deleted\n", key);
}

void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("Playlist is empty\n");
        return;
    }

    temp = head;
    printf("Playlist: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int choice, value, key;

    while (1)
    {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Insert Song at Front\n");
        printf("2. Insert Song Before a Song\n");
        printf("3. Delete Song\n");
        printf("4. Display Playlist\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Song ID: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter Song ID before which to insert: ");
                scanf("%d", &key);

                printf("Enter new Song ID: ");
                scanf("%d", &value);

                insertBefore(key, value);
                break;

            case 3:
                printf("Enter Song ID to delete: ");
                scanf("%d", &key);
                deleteSong(key);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
