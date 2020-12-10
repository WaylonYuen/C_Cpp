//Quesion:
//Construct Binary Search Tree from Preorder Traversal 順序遍歷二元搜尋樹(將Array 轉換成 Tree)
//Input: [ 8, 5, 1, 7, 10, 12 ]
//Output: [ 8, 5, 10, 1, 7, null, 12 ]

#include <stdio.h>
#include <stdlib.h> //調用 malloc函數所需的Library

//Tree節點
struct Node {
    int value;  //值/內容
    struct Node *left;  //左樹枝
    struct Node *right; //右樹枝
};

//副程式宣告
struct Node* BST_FromPreorder(int *preorder, int preorderSIZE);

//程式入口: 主程式(返回一個整數且不帶指令參數)
int main(void) {

    //宣告
    int BST_array[] = { 8, 5, 1, 7, 10, 12 };   //Input array

    //設定BST陣列大小( 每個整數大小為 4Bytes, 因此陣列大小是 n筆資料 除 int大小 )
    int SIZE = sizeof(BST_array) / sizeof(int);

    //傳入陣列轉換成樹
    struct Node *BST = BST_FromPreorder(BST_array, SIZE); 

    //output BST

    return 0;
}

//建立前置二元搜尋樹(參數: 需傳入整數陣列, 該陣列大小)
struct Node* BST_FromPreorder(int *preorder, int preorderSIZE) {

    //創建樹根並向系統請求分配記憶體,記憶體大小為Node結構
    struct Node *root = malloc(sizeof(struct Node));

    //設定樹根
    root->value = preorder[0];  //陣列第一個值是全局最大樹根

    //設定索引
    int leftBegin = 1;  // 索引0號是樹根可以直接忽略,因此直接由1號開始
    int leftEnd = leftBegin;    //初始化: 歸位

    //如果當前索引比全局樹根還要大,表示左樹枝資料到此結束(前置BST: 左樹枝必然比樹根小, 右樹枝必然比樹根大)
    //        root: 10
    //         /     \
    //   left: 8    right: 11
    while (leftEnd < preorder[0] && leftEnd < preorderSIZE) {//End索引不能比最大資料筆數還大,這意味著沒有右樹枝
        leftEnd++;  //索引移動
    }
    
    //設定樹根: 以遞迴形式設定 (參數: 傳入陣列索引起點資料, 左樹枝大小)
    root->left = BST_FromPreorder(&preorder[1], leftEnd - leftBegin);
    root->right = BST_FromPreorder(&preorder[leftEnd], preorderSIZE - leftEnd);

    //返回節點樹根
    return root;
}