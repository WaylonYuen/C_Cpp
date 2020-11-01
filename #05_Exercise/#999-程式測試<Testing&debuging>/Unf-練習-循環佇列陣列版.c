// 添加資料加到 rear遇到front 表示資料已滿
// 取出資料取到 rear遇到front 表示資料已空

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

void func_Select(int data[], int front, int rear);
int pop(int data[], int front, int rear);
int push(int data[], int front, int rear);
void show(int data[], int front, int rear);

/* new functions */
int adjust(int data[], int front, int rear, int moveNumber);//Unf
int cutInLine(int data[], int front, int rear, int cutNumber);//Unf
int goAway(int data[], int front, int rear, int leaveNumber);//Unf

int main(){

    int data[SIZE];
    int front=0;
    int rear=0;

    puts("\n\nProgram start\n");
    func_Select(data, front, rear);

    return 0;
}

int adjust(int data[], int front, int rear, int moveNumber){

    //Unf

    return 0;
}

int pop(int data[], int front, int rear){
    if(front != rear){
        front++;  
        if(front <= SIZE-1){
            if(front == rear){
                puts("list is already Empty!\n");
            }
        }else{
            front = 0;
            if(front == rear){
                puts("list is already Empty!\n");
            }
        }
    }
    else{
        puts("list is already Empty!\n");
    }

    show(data, front, rear); 

    return front;
}

int push(int data[], int front, int rear){

    rear++;
    if(rear <= SIZE-1){
        if(rear != front){
            printf("Plz input the data\n"
                "---------------------------\n");
            scanf("%d", &data[rear]);
        }else{
            rear--;
            puts("list is already full!\n");
        }
    }
    else{
        rear=0;
        if(rear != front){
            printf("Plz input the data\n"
                "---------------------------\n");
            scanf("%d", &data[rear]);
 
        }
        else{
            rear = SIZE-1;
            puts("list is already full!\n");
        }
    }

    show(data, front, rear); 

    return rear;
}

void show(int data[], int front, int rear){
    int i,j;
    printf("show Data:\n");
    if(rear < front){
        printf(" [ ");
        /*前半段資料*/
        for(i=front+1; i<SIZE; i++){
            printf("\t%d ", data[i]);
        }
        /*後半段資料*/
        for(i=0; i<=rear; i++){
            printf("\t%d ", data[i]);
        }
        printf("\t] ");
    }else{
        printf(" [ ");
        for(i=front+1; i<=rear; i++){
            printf("\t%d ", data[i]);
        }
        printf("\t] ");
    }
    
    puts("\n");

}

void func_Select(int data[], int front, int rear){

    int information;
    int request;

    printf("Explain\n"
               "======================\n"
               "- 1 -       push\n"
               "- 2 -       pop\n"
               "- 3 -       show\n"
               "- 4 -       exit\n"
               "======================\n"
               "-Plz input the request: ");

    while(1){
               
        scanf("%d", &request);
        switch(request){
            case 1:
                rear = push(data, front, rear);
                break;
            case 2:
                front = pop(data, front, rear);
                break;
            case 3:
                show(data, front, rear);
                break;
            case 4:
                puts("\n\nEnd of run....\n");
                exit(1);
                break;
            default:
                puts("Error input\n");
                break;        
        }
    }

}
