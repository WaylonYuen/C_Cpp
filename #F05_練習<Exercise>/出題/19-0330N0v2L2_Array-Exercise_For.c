// 編號：19-0330N0L2_Array-Exercise_For.c

// 程式類別：C語言
// 基礎題：陣列 ( 難度 ** )
// 題目：奇偶順序重組

// 時間：NULL ( 不限 )	//最佳 1s內
// 內存大小：128MB

// 創建一個SIZE為100的Arr 陣列並給予預設值 100 到 0，
// 其次將所有奇數順序(由小到大)存放到Arr，而偶數則
// 尾隨其後, 依序存放(由小到大)到Arr陣列中。

// 輸出格式：
// printf(“Arr[%d] = %d\n”, ??);  //問號為自定變數

// *注意：
// 不能使用外部覆蓋法，例如直接引用for i++ i<=50
// 來儲存奇數到Arr。

// *提示：
// 可以使用Arr2 來轉儲 Arr 中所有的奇數，
// 再使用Arr3 來轉儲 Arr 中所有的偶數，
// 再依次 轉儲到 Arr中。
// //缺點：需要額外更多的空間來做為暫時性儲存，浪費空間資源	

// Input  格式： NULL（無）
// Output 格式： 
// 	Arr[0] = 1
// 	Arr[1] = 3
// 	Arr[2] = 5
// 	…
// 	Arr[51] = 2
// 	Arr[52] = 4
// 	Arr[53] = 6 
// 	…

#include <stdio.h>
#define SIZE 100

int main(void){

    /*變量宣告*/
    int i;
    int count_Odd, count_Even;
    int Arr[SIZE];
    int Arr_odd_Num[50];
    int Arr_Even_Num[50];

    /*初始化Arr陣列中的數值：由100～1*/
    int counter = 0;
    for(i=SIZE; i>0; i--){
        Arr[counter] = i;
        //printf("Arr[%d] = %d\n", j, Arr[j]);  // Testing
        counter++;
    }

    /*奇偶分隔——分別存放在不同陣列中*/
    count_Odd = 50-1;   //50-1是因為 陣列編號為 0～49
    count_Even = 50-1;  //同上
    for(i=0; i<SIZE; i++){
        if(Arr[i]%2 == 1){//判斷是否為奇數,是：存放到 Arr_odd_Num陣列中; 否：存放到 Arr_Even_Num陣列中
            Arr_odd_Num[count_Odd] = Arr[i];
            count_Odd--;    //由於Arr是由大到小排序, 利用減減把較大的數值由後往前存,實現由小到大排序的反轉效果
        }else{
            Arr_Even_Num[count_Odd] = Arr[i];
            count_Even--;   //原理同上
        }
    }

    /*回存資料——奇偶同時存放到Arr陣列中*/
    for(i=0; i<SIZE-50; i++){//已知內100的奇偶數為50:50,因此可以同時儲存,這使得for循環上限為50次即可
        Arr[i] = Arr_odd_Num[i];    //存放奇數：Arr[0～49]
        /*偶數需要由50開始存放*/
        Arr[i+50] = Arr_Even_Num[i];//存放偶數：Arr[50～99]
    }

    /*輸出*/
    for(i=0; i<SIZE; i++){
        printf("Arr[%d] = %d\n", i, Arr[i]);
    }

    return 0;
}
