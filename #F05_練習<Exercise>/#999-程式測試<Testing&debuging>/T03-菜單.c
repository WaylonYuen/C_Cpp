#include<stdio.h>
#include<stdlib.h>

void Exitt();
void coor(int counterB[10][10]);

void menu(){
    printf( "菜單\n"
            "---------------------------------\n"
            "press 1 開始選項\n"
            "press 2 選擇您需要的座位號碼\n"
            "press 3 修改位置\n"
            "press 4 退出\n"
            "---------------------------------\n");
    int request;
    scanf("%d", &request);

    switch(request){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            Exitt();
            break;
        default:
            printf("Error\n");
            break;
    }
}

void Exitt(){
    exit(1);
}


void coor(int counterB[10][10]){


}


int main(){

    menu();


    return 0;
}