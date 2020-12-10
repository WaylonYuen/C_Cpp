//BUG:
//  ~Rank range為 1～4時, 結果會出錯

#include <stdio.h>
#include <stdlib.h>

#pragma region Define

//Functions定義
#define SWAP(a,b,t) ((t)=(a), (a)=(b), (b)=(t))

//布爾值定義
#define bool int
#define true 1
#define false 0

//各科權重
#define ChineseWeighted 0.4
#define EnglishWeighted 0.4
#define CSWeighted 0.2

#pragma endregion

//課程索引
enum Course {
    Chinese = 0,
    English = 1,
    CS = 2
};

#pragma region Struct

//成績表
typedef struct Achievement {
    int SeatNum;            //座號
    int Chinese;            //中文
    int English;            //英文
    int CS;                 //計概
    float TotalWeighted;    //加權總和
    float AverageWeighted;  //加權平均
} Student;

//科目表
typedef struct Subject {
    float TopRank;
    float AveRank;
    float LowRank;
    int FailedNum;
} Subject;

#pragma endregion

#pragma region Define Methods

int Input_StudentNumber(void);
void Input_StudentsAchievement(Student *Stu, int stuNum);
void Sort_AverageWeighted(Student *Stu, int stuNum);
void TopRank(int startIndex, int endIndex, Subject *subject, Student *stu);
void LowRank(int startIndex, int endIndex, Subject *subject, Student *stu);
void AveRank(Subject *subject, Student *stu, int stuNum);
void Failed(Subject *subject, Student *stu, int stuNum);
void Show_AllStudentAchievement(Student *Stu, int stuNum);
void Show_CoursesReport(Subject *subject, int stuNum);
void Calculate_RankRange(int stuNum);
void Check_ScoreRange(Student *Stu, int index);

#pragma endregion

#pragma region Global values

//Rank範圍
int TopRankNum;
int LowRankNum;

#pragma endregion

int main(void) {

    //宣告
    Subject subject[3]; //科目(目前有3個科目)
    Student Stu[60];    //最多60筆資料

    //輸入學生數目(最少15筆,最多60筆)
    int Counter = Input_StudentNumber();

    //輸入學生成績 & 計算個人成績
    Input_StudentsAchievement(Stu, Counter);

    //以加權平均由大到小排序
    Sort_AverageWeighted(Stu, Counter);

    //計算Rank(高標、底標)
    Calculate_RankRange(Counter);

    //Debug: Show rank range
    printf("\nRank range: %d  %d\n", TopRankNum, LowRankNum);

    //統計各科成績
    TopRank(0, TopRankNum, subject, Stu);       //計算各科高標平均分
    LowRank(LowRankNum, Counter, subject, Stu); //計算各科底標平均分
    AveRank(subject, Stu, Counter);             //計算各科全體平均
    Failed(subject, Stu, Counter);              //計算各科不及格人數

    //顯示所有學生的各科成績
    Show_AllStudentAchievement(Stu, Counter);
    
    //顯示各科目成績統計
    Show_CoursesReport(subject, Counter);

    return 0;
}

#pragma region Methods

//輸入學生數目(最少15筆,最多60筆)
int Input_StudentNumber(void) {

    int Counter;

    //最少15筆資料,且大於60筆資料需要重寫
    printf("Plz input data number.\n");
    while(true) {
        scanf("%d", &Counter);
        if(Counter >= 15 || Counter <= 60) {
            break;
        } else {
            printf("Plz intput dataNum again. 15~60\n");
        }
    }

    return Counter;
}

//輸入學生成績 & 計算個人分數
void Input_StudentsAchievement(Student *Stu, int stuNum) {
    printf("Plz input the data:\n");
    for (int i = 0; i < stuNum; i++) {

        //輸入成績資料
        printf("Student data %d\n", i);
        printf("Plz input SeatNumber、 Chinese、 English、 CS\n");

        scanf("%d", &Stu[i].SeatNum);
        //輸入分數 & 檢查分數範圍是否正確
        Check_ScoreRange(Stu, i);

        //計算加權
        Stu[i].TotalWeighted = 
            (Stu[i].Chinese * ChineseWeighted) +
            (Stu[i].English * EnglishWeighted) +
            (Stu[i].CS * CSWeighted);

        //加權平均
        Stu[i].AverageWeighted = Stu[i].TotalWeighted / 3;
    }
}

//以加權平均由大到小排序
void Sort_AverageWeighted(Student *Stu, int stuNum) {
    Student temp;
    for (int i = 0; i < stuNum; i++) {
        for (int j = 0; j < stuNum - 1; j++) {
            if(Stu[j].AverageWeighted < Stu[j+1].AverageWeighted) {
                SWAP(Stu[j], Stu[j+1], temp);
            }
        }      
    }
}

//計算高標範圍排名平均分數
void TopRank(int startIndex, int endIndex, Subject *subject, Student *stu) {
    
    //特定範圍分數加總
    for (int i = startIndex; i <= endIndex; i++) {
        subject[0].TopRank += stu[i].Chinese;
        subject[1].TopRank += stu[i].English;
        subject[2].TopRank += stu[i].CS;
    }
    
    //取平均
    int stuNum = endIndex - startIndex;
    for (int i = 0; i < 3; i++) {
        subject[i].TopRank = subject[i].TopRank / stuNum;
    }
}

//計算底標範圍排名平均分數
void LowRank(int startIndex, int endIndex, Subject *subject, Student *stu) {
    
    //特定範圍分數加總
    for (int i = startIndex; i <= endIndex; i++) {
        subject[0].LowRank += stu[i].Chinese;
        subject[1].LowRank += stu[i].English;
        subject[2].LowRank += stu[i].CS;
    }
    
    //取平均
    int stuNum = endIndex - startIndex;
    for (int i = 0; i < 3; i++) {
        subject[i].LowRank = subject[i].LowRank / stuNum;
    }
}

//計算平均分數
void AveRank(Subject *subject, Student *stu, int stuNum) {
    
    //特定範圍分數加總
    for (int i = 0; i < stuNum; i++) {
        subject[0].AveRank += stu[i].Chinese;
        subject[1].AveRank += stu[i].English;
        subject[2].AveRank += stu[i].CS;
    }

    //取平均
    for (int i = 0; i < 3; i++) {
        subject[i].AveRank = subject[i].AveRank / stuNum;
    }
}

//計算不及格人數
void Failed(Subject *subject, Student *stu, int stuNum) {
    
    for (int i = 0; i < stuNum; i++) {
        if(stu[i].Chinese < 60) {
            subject[Chinese].FailedNum++;
        }

        if(stu[i].English < 60) {
            subject[English].FailedNum++;
        }

        if(stu[i].CS < 60) {
            subject[CS].FailedNum++;
        }
    }
}

//顯示所有學生的各科成績
void Show_AllStudentAchievement(Student *Stu, int stuNum) {
    printf("\n\n各科權重: %.1f\t%.1f\t%.1f\n\n", ChineseWeighted, EnglishWeighted, CSWeighted);
    printf("Rank\t SeatNum\t Chinese\t English\t CS\t TotalWeighted\t AverageWeighted\n");
    for (int i = 0, rank = 1; i < stuNum; i++, rank++) {
        //printf("Student[%d]\n", i);
        printf("%d\t %d\t\t %d\t\t %d\t\t %d\t %.2f\t\t %.2f\n",
        rank,
        Stu[i].SeatNum, 
        Stu[i].Chinese, 
        Stu[i].English, 
        Stu[i].CS, 
        Stu[i].TotalWeighted, 
        Stu[i].AverageWeighted);
    }
}

//顯示各科目成績統計
void Show_CoursesReport(Subject *subject, int stuNum) {
    printf("\n============================================================================================\n\n");
    printf("Top Rank\t %.0f\t %.0f\t %.0f\n", subject[Chinese].TopRank, subject[English].TopRank, subject[CS].TopRank);
    printf("Ave Rank\t %.0f\t %.0f\t %.0f\n", subject[Chinese].AveRank, subject[English].AveRank, subject[CS].AveRank);
    printf("Low Rank\t %.0f\t %.0f\t %.0f\n", subject[Chinese].LowRank, subject[English].LowRank, subject[CS].LowRank);
    printf("Down Rank\t %d\t %d\t %d\n", subject[Chinese].FailedNum, subject[English].FailedNum, subject[CS].FailedNum);
}

//計算Rank(高標、底標)
void Calculate_RankRange(int stuNum) {

    TopRankNum = stuNum * 0.25;         //高標範圍終點
    if((TopRankNum % 10) >= 0.1) {      //題目要求: 不到一人以一人計算
        TopRankNum++;
    }
    LowRankNum = stuNum - TopRankNum;   //底標範圍起點
}

//檢查分數輸入的範圍是否正確
void Check_ScoreRange(Student *Stu, int index) {

    //中文分數範圍檢查
    while(true) {
        scanf("%d", &Stu[index].Chinese);
        if(0 > Stu[index].Chinese || Stu[index].Chinese > 100) {
            printf("Error score! the score should be between 0 to 100. plz try again (input Chinese score).\n");
        } else break;
    }

    //英文分數範圍檢查
    while(true) {
        scanf("%d", &Stu[index].English);
        if(0 > Stu[index].English || Stu[index].English > 100) {
            printf("Error score! the score should be between 0 to 100. plz try again (input English score).\n");
        } else break;
    }

    //計概分數範圍檢查
    while(true) {
        scanf("%d", &Stu[index].CS);
        if(0 > Stu[index].CS || Stu[index].CS > 100) {
            printf("Error score! the score should be between 0 to 100. plz try again (input CS score).\n");
        } else break;
    }
}

#pragma endregion