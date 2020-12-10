//BUG: 乘法有bug

#include <stdio.h>
#include <math.h>

#define bool int
#define True 1
#define false 0

#define ColumnSIZE 2
#define RowSIZE 2

enum Format { Row = 0, Column };

struct Matrix {
    int matrix[ColumnSIZE][RowSIZE];
    bool isError;
};

struct StringToInt {
    char StrData[100];
    int IntData;
    bool CanChange;
};


typedef struct Matrix matrix;
typedef struct StringToInt interchange;
typedef enum Format format;

char const Integer[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

interchange StrToInt(interchange data);

matrix Add(matrix A, matrix B) {

    matrix Ans;

    for (int i = 0; i < RowSIZE; i++) {
        for (int j = 0; j < ColumnSIZE; j++) {
            Ans.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
        }     
    }

    return Ans;
}

matrix Sub(matrix A, matrix B) {

    matrix Ans;

    for (int i = 0; i < RowSIZE; i++) {
        for (int j = 0; j < ColumnSIZE; j++) {
            Ans.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
        }     
    }

    return Ans;
}

//Have Bug
matrix Mul(matrix A, matrix B) {

    matrix Ans;

    int counter = 0;

    for (int i = 0; i < RowSIZE; i++) {

        for (int y = 0; y < RowSIZE; y++) {
            for (int x = 0; x < ColumnSIZE; x++) {
                Ans.matrix[i][y] += (A.matrix[i][x] * B.matrix[x][y]);   
            }
        }     
    }

    return Ans;
}

matrix Input(format form, matrix data) {

    interchange number, Ans;

    data.isError = false;

    switch (form) {

        //Row
        case 0:
            printf("Plz input Row data:\n");
            for (int y = 0; y < RowSIZE; y++) {
                for (int x = 0; x < ColumnSIZE; x++) { 
                
                    scanf("%s", number.StrData);
                    Ans = StrToInt(number);

                    if(Ans.CanChange) {
                        data.matrix[y][x] = Ans.IntData;
                    } else {
                        data.isError = True;
                        return data;
                    }

                }
            }   
            break;

        //Column
        case 1:
            printf("Plz input Column data:\n");
            for (int y = 0; y < RowSIZE; y++) {
                for (int x = 0; x < ColumnSIZE; x++) { 
                    scanf("%d", &data.matrix[x][y]);
                }
            }   
            break;
        
        default:
            break;
    }

    printf("\n");

    return data;
}

interchange StrToInt(interchange data) {

    int length = 0;
    int degital = 0;

    data.CanChange = false;
    data.IntData = 0;

    while(data.StrData[length] != '\0') {
        length++;
    }
    length--;

    for (int i = length; i >= 0; i--, degital++) {
        for (int j = 0; j < 10; j++) {
            if(data.StrData[i] == Integer[j]) {
                data.IntData += (j * (int)pow(10, degital));
                data.CanChange = True;  
            }
        }

        if(data.CanChange == false) {
            printf("Error input, plz retry again.\n");
            return data;
        } else {
            data.CanChange = false;
        }

    }

    data.CanChange = True;
    return data;
}

void Menu(void) {

    printf("");

}

void Show(matrix ShowAns) {

    printf("Ans is:\n");
    for (size_t i = 0; i < RowSIZE; i++) {
        for (size_t j = 0; j < RowSIZE; j++) {
            printf("%d ", ShowAns.matrix[i][j]);
        }
        printf("\n");
    }

}

int main(void) {

    struct Matrix A, B, Ans;

    char key;
    Menu();

    while(True){

        //其中一個錯,則需重新輸入
        do {
            A = Input(1, A);
        } while(A.isError);

        do {
            B = Input(0, B);
        } while(B.isError);

        do {
            char blank;
            scanf("%c", &blank);
            
            printf("Plz input the Fun\n");
            scanf("%c", &key);
            switch (key) {

                //退出程式
                case 'q':
                case 'Q':
                    printf("End of run...\n");
                    return 0;
                
                case '+':
                    Show(Add(A, B));
                    printf("\n");
                    break;

                case '-':
                    Show(Sub(A, B));
                    printf("\n");
                    break;

                case '*':
                    Show(Mul(A, B));
                    printf("\n");
                    break;
                
                default:
                    //Error input
                    printf("Error. Cannot found the Command '%c'. Plz try again.\n\n", key);
                    break;
            }

        } while(True);
    }

    return 0;
}