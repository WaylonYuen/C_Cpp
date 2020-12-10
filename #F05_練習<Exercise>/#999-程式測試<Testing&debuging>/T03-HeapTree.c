#include <stdlib.h>
#include <stdio.h>
typedef struct Node{
    int value;
    struct Node * left;
    struct Node * right;
}Node;
int heightOfTree(Node * root);

/*arring data in tree.*/
void reheapify(Node * N){
    Node * M;
    int V1,V2,temp;

    V1 = N->value;

    while(N->left != NULL && N->right != NULL){
        if (N->left->value > N->right->value){
            M = N->left;
        }
        else if (N->left->value < N->right->value){
            M = N->right;
        }

        V2 = M->value;

        if (V1 >= V2){
            return;
        } else {
            temp = N -> value;
            N -> value = M -> value;
            M -> value = temp;

            N = M;
            V1 = N -> value;
        }
    }
}

void printLevel(Node * root, int level){
    if (root == NULL) return;
    //if (level == 1) printf("%d ",root -> value);
    if (level == 1) reheapify(root);
    else if (level > 1){
        printLevel(root -> left, level-1);
        printLevel(root -> right, level-1);
    }
}

void heapify(Node * heap){
    int height = heightOfTree(heap);

    for(int i = height;i >= 1;i--) printLevel(heap,i);
}

/*building and printing tree*/
Node *newEmptyTree(void) {
    Node *new = malloc(sizeof (Node));
    if (new == NULL) {
        printf("Failed allocation.\n");
        return NULL;
    }
    new->value = 0;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// make a heap from part of an array
Node *heap_from_array(int arr[], int index, int elements) {
    // when we're past the end of the array, there's nothing to do anymore
    if (index >= elements) return NULL;

    // Otherwise, get us a new tree
    Node *this = newEmptyTree();
    // store current element
    this->value = arr[index];
    // fill left subtree
    this->left = heap_from_array(arr, 2*index + 1, elements);
    // fill right
    this->right = heap_from_array(arr, 2*index + 2, elements);
    // done, return the thing
    return this;
}

void printPre(Node * root){
    Node * parent = root;
    if (parent == NULL) return;

    printf("%d ",parent -> value);
    printPre(parent -> left);
    printPre(parent -> right);
}
int heightOfTree(Node * root){
    if (root == NULL) return 0;
    else{
        int leftHieght = heightOfTree(root -> left);
        int rightHeight = heightOfTree(root -> right);

        if (leftHieght > rightHeight) return leftHieght+1;
        else return rightHeight+1;
    }
}
int main(void){
    int array[] = {2,4,5,7,3,10,8,1,9,6};
    Node * heap = NULL;
    heap = heap_from_array(array,0,10);
    printf("Height of tree: %d\n",heightOfTree(heap));
    printPre(heap);
    printf("\n");
    heapify(heap);
    printPre(heap);
    printf("\n");
    return 0;
}