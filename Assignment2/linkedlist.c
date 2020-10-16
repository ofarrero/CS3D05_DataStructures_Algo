#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char data;
    struct Node *next; 
}Node;

void add_node(Node** list, char data){
    //allocate memory
    Node* newNode = (Node*) malloc(sizeof(Node));
    //add data
    newNode->data = data;
    //add link
    newNode->next = *list;
    //make head newNode
    *list = newNode;
}

void print_list(Node* list){
    while (list != NULL)
    {
        //print data
        printf("%c", list->data);
        //go to next link
        list = list->next;
    }
     printf("\n");
}

void remove_node(Node** list, char data) {
    Node* curr = *list;
    Node* prev;

    if(curr != NULL && curr->data == data){
        // if wanted data make head next link and free curr node
        *list = curr->next;
        free(curr);
        return;
    }else{
        //call function again if not wanted data
        remove_node(&curr->next, data);
    }
}

void reverse_list(Node** list){
    int numberLinksReversed = 0;
    Node* prev = NULL; 
    Node* curr = *list; 
    Node* next = NULL; 
    while (curr != NULL) { 
        next = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = next;
        numberLinksReversed++; 
    } 
    //priny no. changed links
    printf("%i links were changed \n",numberLinksReversed);
    *list = prev; 
}

void delete_list(Node** list){
    // delete each node until no nodes left
    if(*list){
        Node* next = (*list)->next;
        free(*list);
        *list = NULL;
        delete_list(&next);
    }
}

void add_node2(Node* list, char data, int offset){  
    /* 
    / where memory has already been allocated - ptr to size instead offset 
    / so you don't need to update the size
    */
    Node* newNode = list + (offset)*sizeof(Node);
    newNode->data = data;
    newNode->next = list + (offset+1)*sizeof(Node);
}

int main(int argc, char *argv[]){
    Node* head = NULL;
    add_node(&head, 'A');
    add_node(&head, 'B');
    add_node(&head, 'C');
    add_node(&head, 'D');
    print_list(head);
    reverse_list(&head);
    print_list(head);
    delete_list(&head);

    // allocate the memory upfront
    int MAX_NUMBER_NODES = 20;
    Node* head2 = (Node*) malloc(MAX_NUMBER_NODES* sizeof(Node) );
    int size = 0;
    add_node2(head2,'f',size);
    size++; 
    add_node2(head2,'g',size);
    size++;
    // this way we can iterate over the memory directly to traverse the list
    for (int i =0;i<size;i++){
        printf("Node: %c\n", (head2+i*sizeof(Node))->data);
    }
}