#include <stdio.h>
#include <cstdlib>
using namespace std;

struct Node{
    int data;
    Node* link;
};
Node* head = new Node(); //malloc in c++

void insert_at_end(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->link = NULL;
    if (head == NULL){
        head = temp;
    }
    else{
        Node* temp1 = head;
        while(temp1->link != NULL){
            temp1 = temp1->link;
        }
        temp1->link = temp;
    }

}

void insert_at_any_position(int x, int n){          ///linked list indices - 0,1,2.....
    int count = 2;
    Node* temp = new Node();
    temp->data = x;

    Node* temp4 = head;
    while(count <= n){
        count++;
        temp4 = temp4->link;
    }
    if (n==0){
        temp->link = head;
        head = temp;
    }
    else{
        temp->link = temp4->link;
        temp4->link = temp;
    }

}

void delete_at_any_position(int n){       ///linked list indices - 0,1,2.....
    int count = 2;

    Node* temp4 = head;
    while(count <= n){
        count++;
        temp4 = temp4->link;
    }
    if (n==0){
        head = temp4->link;
        free(temp4);
    }
    else{
        Node* temp5 = temp4->link;
        temp4->link = temp4->link->link;
        free(temp5);
    }

}

void reverse_linked_list(){       ///linked list indices - 0,1,2.....
    Node* head2 = head;

    int count = 0;
    Node* temp1 = head;
    while(temp1 != NULL){
        temp1 = temp1->link;
        count++;
    }

    Node *temp6, *temp7;
    for (int i=count;i>=0;i--){
        temp6 = head2;
        temp7 = head;
        for (int j=1;j<i;j++){
            temp7 = temp7->link;
        }
        for (int k=1;k<count-i;k++){
            temp6 = temp6->link;
        }
        if (i==count){
            head2 = temp7;
        }
        else if (i==0){
            temp6->link = NULL;
        }
        else {
            temp6->link = temp7;
        }
    }
head = head2;
}

void reverse_linked_list2(){       ///linked list indices - 0,1,2.....
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while(current!=NULL){
        next = current->link;
        if (current->link == NULL){
            head = current;
        }
        current->link = prev;
        prev = current;
        current = next;
    }
}

void print_linked_list_recursion(Node* p){       ///linked list indices - 0,1,2.....
    if (p == NULL) return;

    //reverse print
    // print_linked_list_recursion(p->link);
    // printf("%d ", p->data);

    //normal print      
    printf("%d ", p->data);
    print_linked_list_recursion(p->link);
}

void print_linked_list(Node* temp2){       ///linked list indices - 0,1,2.....
    while(temp2 != NULL){
        printf("%d ", temp2->data);
        temp2 = temp2->link;
    }
}

void reverse_linked_list_recursion(Node* prev, Node* current){       ///linked list indices - 0,1,2.....
    if (current->link == NULL) {head = current;current->link = prev;return;}
    reverse_linked_list_recursion(current, current->link);
    current->link = prev;
}

int main(){

    head = NULL;
    printf("\nno. of Elements in list ??? = ");
    int n , i , x;
    scanf("%d", &n);

    printf("\nEnter a number = ");
    for (i=0;i<n;i++){
        scanf("%d", &x);
        insert_at_end(x);
    }

    insert_at_any_position(100,5);     ///linked list indices - 0,1,2.....
    delete_at_any_position(3);        ///linked list indices - 0,1,2.....
    
    printf("\nList = ");
    print_linked_list(head);
    reverse_linked_list_recursion(NULL, head);
    printf("\nreverse List = ");
    print_linked_list(head);

printf("\n");
}
