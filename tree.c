#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{

    int data ;
    struct node*left ;
    struct node*right ;
};

bool Get_Info( struct node *head , int val){

    if( head != NULL ){

        if( head->data == val ){
            return true ;
        }

        else {
            Get_Info(head->left,val);
            Get_Info(head->right,val);
        }
    }

    else {
        return false ;
    }
}

void FreeAll(struct node * head){

    if( head != NULL ){
        FreeAll(head->left);
        FreeAll(head->right);
        free(head);
    }
}

struct node * CreateNewNode( int *arr , int index , struct node*ele ){

    ele = (struct node*)malloc(sizeof(struct node));
    ele->data = arr[index];
    ele->left = NULL ;
    ele->right = NULL ;

    return ele ;
}

struct node * Add_Node( struct node*head , struct node*ptr){

    if( head == NULL ) return ptr ;

    if(ptr->data < head->data ){
        head->left = Add_Node(head->left , ptr);
    }

    else if(ptr->data > head->data ) {
        head->right = Add_Node(head->right , ptr);
    }

    return head ;
}

void Parkour_PreOrder( struct node*head){

    if( head != NULL ){
        printf("%d\t",head->data);
        Parkour_PreOrder(head->left);
        Parkour_PreOrder(head->right);
    }
}

void Parkour_InOrder(struct node*head){

    if( head != NULL ){

        Parkour_InOrder(head->left);
        printf("%d\t",head->data);     
        Parkour_InOrder(head->right);
    }
}

void Parkour_PostOrder( struct node * head){

    if( head != NULL ){
        Parkour_PostOrder(head->left);
        Parkour_PostOrder(head->right);
        printf("%d\t",head->data);
    }
}

int maxDepth(struct node* head) // hauteur
{
    if (head == NULL) return 0;

    else {

        int left_P = maxDepth(head->left);
        int right_P = maxDepth(head->right);
  
        if (left_P > right_P)
            return (left_P + 1);
        else
            return (right_P + 1);
    }
}

int main(void)
{
    struct node*ele = NULL ; // new element 
    struct node*head = NULL ; //la racine

    int arr[] = {10, 1, 4, 2, 12, 5, 6, 3, 14, 8 ,9 , 15, 11, 7, 13,16,0}; // array
    size_t size = sizeof(arr) / sizeof(arr[0]); // get the size of array ( FULL size in bit / the bit size of each element) == num of the elements

    for (int index = 0; index < size; index++)
    {
        ele = CreateNewNode(arr , index , ele);
        head = Add_Node(head , ele);
    }

    printf("Print the tree \n\n");

    ele = head ; printf("\nPre Order\n");
    Parkour_PreOrder(ele);

    ele = head ; printf("\nIn order\n");
    Parkour_InOrder(ele);

    ele = head ; printf("\nPost ordre \n");
    Parkour_PostOrder(ele);

    int levels = maxDepth(head);

    printf("\n\n%d level\n\n",levels);
}