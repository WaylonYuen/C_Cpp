#include <stdio.h>

#define SIZE 100                                //多項式長度上限
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))   //交換定義  

struct Polynomial {
    int Coef[SIZE];     //多項式系數
    int Exp[SIZE];      //多項式次方
    int PolyArrSIZE;    //多項式長度
};

void Input(int* Coef, int* Exp, int* ArrSIZE);
void Show(int* Coef, int* Exp, int* ArrSIZE);
void Initial(int* Coef, int* Exp);
void Mul(int* CoefA, int* ExpA, int* ArrSIZEA,  int* CoefB, int* ExpB, int* ArrSIZEB,  int* CoefAns, int* ExpAns, int* ArrSIZEAns);

//輸入多項式
void Input(int* Coef, int* Exp, int* ArrSIZE){

    Initial(Coef, Exp);
    int i = -1;

    do {
        i++;
        scanf("%d", &Coef[i]);
        scanf("%d", &Exp[i]);
    } while(Coef[i] != 0);

    *ArrSIZE = i--; //保存多項式長度
}

//輸出多項式內容(Test)
void Show(int* Coef, int* Exp, int* ArrSIZE){
    int i = 0, counter = 0;
    while(i != *ArrSIZE) {
        if(Exp[i] == 0) printf("%d", Coef[i]);
        else printf("%dX^%d", Coef[i], Exp[i]);
        if(counter != *ArrSIZE - 1) printf(" + ");    //Debug: A + B Debug +
        i++;
        counter++;
    }
    puts("");
}

//初始化
void Initial(int* Coef, int* Exp){
    int i;
    for(i = 0; i < SIZE; i++){
        Coef[i] = -1;
        Exp[i] = -1;
    }
}

void Mul(int* CoefA, int* ExpA, int* ArrSIZEA,  int* CoefB, int* ExpB, int* ArrSIZEB,  int* CoefAns, int* ExpAns, int* ArrSIZEAns){

    int i, j, k = 0;

    //乘法運算
    for (i = 0; i < *ArrSIZEA; i++) {
        for (j = 0; j < *ArrSIZEB; j++) {
            CoefAns[k] = CoefA[i] * CoefB[j];   //系數相乘
            ExpAns[k] = ExpA[i] + ExpB[j];      //次方相加
            k++;
        }
    }

    //同次方系數相加
    for (i = 0; i < k; i++) {
        for (j = i+1; j < k; j++) {
            if(ExpAns[i] == ExpAns[j]){
                CoefAns[i] += CoefAns[j];
                CoefAns[j] = 0;             //系數相加後將後者(系數B)歸 0
                ExpAns[j] = 0;              //系數相加後將後者(次方B)歸 0
            }
        }
    }   

    //按次方由大到小排序(冒泡)
    int CoefTemp, ExpTemp;
    for (i = 0; i < k - 1; i++) {
        for (j = 0; j < k - i - 1; j++) {
            if(ExpAns[j] < ExpAns[j+1]){
                SWAP(ExpAns[j], ExpAns[j+1], ExpTemp);
                SWAP(CoefAns[j], CoefAns[j+1], CoefTemp);
            }
        }
    }

    //計算次方合併後的答案長度
    for(i = 0; i < SIZE; i++){
        if(CoefAns[i] == 0) break;  //同次方相加後,由於後者被歸零,再經由大到小排序,判斷第一個系數出現 0 即為Ans長度
    }

    *ArrSIZEAns = i--;  //保存答案長度
}

int main(void){

    struct Polynomial polyA;
    struct Polynomial polyB;
    struct Polynomial Ans;

    //輸入第一個多項式
    printf("輸入Ploy : ");
    Input(polyA.Coef, polyA.Exp, &polyA.PolyArrSIZE);
    printf("多項式1 = ");
    Show(polyA.Coef, polyA.Exp, &polyA.PolyArrSIZE);

    puts(" ");

    //輸入第二個多項式
    printf("輸入Ploy : ");
    Input(polyB.Coef, polyB.Exp, &polyB.PolyArrSIZE);
    printf("多項式2 = ");
    Show(polyB.Coef, polyB.Exp, &polyB.PolyArrSIZE);

    //乘法
    Mul(polyA.Coef, polyA.Exp, &polyA.PolyArrSIZE,  polyB.Coef, polyB.Exp, &polyB.PolyArrSIZE,  Ans.Coef, Ans.Exp, &Ans.PolyArrSIZE);

    puts(" ");

    printf("乘法結果 = ");
    Show(Ans.Coef, Ans.Exp, &Ans.PolyArrSIZE);
    //printf("\n\n Length - %d", Ans.PolyArrSIZE);
    return 0;
}