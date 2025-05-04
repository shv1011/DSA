# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void InsertBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void InsertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
void InsertEnd(struct Node** head_ref, int new_data) {
    struct Node*new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
void DeleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
}
int searchNode(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key)
            return 1;
        current = current->next;
    }
    return 0;
}
void sortedLinkedList(struct Node** head_ref) {
    struct Node* current = *head_ref , * index = NULL;
    int temp;
    if (head_ref == NULL)
        return;
    else{
         while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}
}
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main() {
    struct Node* head = NULL;
    InsertEnd(&head, 1);
    InsertEnd(&head, 2);
    InsertEnd(&head, 3);
    InsertBeginning(&head, 0);
    InsertAfter(head->next, 5);
    printf("Created Linked List: ");
    printList(head);
    DeleteNode(&head, 2);
    printf("\nLinked List after Deletion of 2: ");
    printList(head);
    printf("\nSorted Linked List: ");
    sortedLinkedList(&head);
    printList(head);
    int searchKey = 3;
    if (searchNode(head, searchKey))
        printf("\nElement %d found in the list", searchKey);
    else
        printf("\nElement %d not found in the list", searchKey);
    return 0;
}