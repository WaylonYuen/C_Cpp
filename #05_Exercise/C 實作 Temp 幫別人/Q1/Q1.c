#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Num = 3;

float WorkDayM = 3.49;
float WorkWeek = 3.99;
float Tax = 0.075;

struct Salary{
    char Name[100];
    int WorkDay;
    int WorkWeek;

    int Total;      //總工作時數
    float WeekS;    //每週薪水
    float MonthS;   //每月薪水
    float Tax;      //所得稅
    float Salarys;  //實質薪水
};

void Empolyee(struct Salary Empolyees){

    printf("請輸入第1位員工姓名: ");
    scanf("%s", Empolyees.Name);
    printf("請輸入每日工作時數(不含周末): ");
    scanf("%d", &Empolyees.WorkDay);
    printf("請輸入每日工作時數: ");
    scanf("%d", &Empolyees.WorkWeek);

    Empolyees.Total = Empolyees.WorkDay*5 + Empolyees.WorkWeek*2;
    Empolyees.WeekS = WorkDayM*Empolyees.WorkDay*5 + WorkWeek*Empolyees.WorkWeek*2;
    Empolyees.MonthS = Empolyees.WeekS*4;
    Empolyees.Tax = Empolyees.MonthS*Tax;
    Empolyees.Salarys = Empolyees.MonthS - Empolyees.Tax;
}

void PrintList(struct Salary Empolyees){
    printf("%s\t%d\t%.0f\t%.0f\t%.2f\t%.2f\n",Empolyees.Name, Empolyees.Total, Empolyees.WeekS, Empolyees.MonthS, Empolyees.Tax, Empolyees.Salarys);
}

int main(void){

    struct Salary Empo[Num];

    int i;
    for(i=0; i<Num; i++){
        Empolyee(Empo[i]);
    }

    printf("\n員工姓名\t總工作時數\t每周薪水\t每月薪水\t所得稅額\t實領薪水\n");
    printf("=======================================================================\n");
    for(i=0; i<Num; i++){
        PrintList(Empo[i]);
    }
}


