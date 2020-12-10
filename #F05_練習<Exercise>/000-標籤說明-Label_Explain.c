//
//  Lebal 
//
//  000-標籤說明-Label_Explain.c
//  Version 1.0
//	
//  Created by Waylon.Yuen on 16/10/2018.
//  Last modified by Waylon.Yuen on 22/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明：X
//  操作：X
//  原理：X
//  優化：X
//

#include<stdio.h>

int main(){
    
    printf(
            " Main Label(Condition) Explain\n"
            "------------------------------------------\n"
            " D   & _Self_Lebal-    DeBug\n"
            /* #可編譯 
                1、未定義行為
                2、資料溢位
                3、輸出資料有誤
                4、不符合預期的行為
                */

            " Err & _Self_Lebal-    Error\n"
            /* #不可編譯
                1、編譯器報錯（檢查C標準：C89、C99 ⋯⋯）
                */

            " F   & _Self_Lebal-    finished\n"
            /* #完成品
                1、暫時沒發現重大的BUG
                2、可持續優化
                3、已知BUG ——> 在可控範圍內且可透過優化解決
                */

            " UnF & _Self_Lebal-    Unfinished\n"
            /* #待完成
                1、未達到預期進度
                2、缺少重要Functions
                */

            " T   & _Self_Lebal-    Testing\n"
            /* #測試
                1、零時檔案
                2、等待調適
                3、Function文檔
                */
            
            " Opt & _Self_Lebal-    Optimizationg\n\n"
            /* #最佳化 —— ”需優化“標籤
                1、等待優化
                */
            
            " C & _Self_Lebal-      Checking\n"
            /* #檢查
                1、檢查說明欄位所有標籤(版本、名稱、最後修改日期等)是否為 最新&完善
                2、檢查內容是否有備註
                3、是否有進行優化
                */

           );

    puts("\n");

    printf(
            " Self Label Explain:\n\n"
            " ‘Main_Lebal_’ & ‘xxx-SSxx-name’\n"
            "---------------------------------------------------------\n"
            " Explain: Condition_Theme-’Subject&number‘-nameCH-nameEn.Type\n"
            " Example: Opt_002-FM03-平均值-Average.c\n"
            /* 範例：狀態_主題-‘範疇&編號’-中文名稱-英文名稱.格式   // 完整格式
               縮寫：1、狀態_‘範疇&編號’-中文名稱-英文名稱.格式     // 在本地文件夾可省略‘主題’
                    2、‘範疇&編號’-中文名稱-英文名稱.格式         // 省略狀態即為默認‘Finished’
                    3、‘範疇&編號’-英文名稱.格式                 // 省略中文名稱解決兼容問題
                */
            "\n\n"
            " 'Subject&number ——> Sub(n)_‘subject&number’ ⋯⋯'\n"// 子——‘範疇&編號’
            "---------------------------------------------------------\n"
            " Purpose: Solve the relationships of different Theme and same code\n"//解決不同主題之間相同代碼的問題
            " Explain: AAA_xxx -SSxx- sub(n)_SSxx - ‘⋯⋯’ -nameCH-nameEn.Type\n"
            " Example:\n"
            "           1、(Ori Theme is 002) FM05-累加n次-Superposition.c\n"
            "           2、(new Theme is 004) F03-02FM05-累加n次-Superposition.c\n"
            "               Ori: FM05 is 002-FM05\n"
            "               new: F03 is 004-F03\n"
            "               In theme 004: F03-02FM05\n"
            /* 說明：
                SSxx: 本地定義
                sub_SSxx: 初始定義(最初 or 在其他主體下的定義) 
                
               定義：
                   SSxx-sub(1)_SSxx ⋯⋯ sub(n)_SSxx   
                    新 <—————————————————> 舊

               例子：
                初始定義： 在#002 先定義了 FM05-累加n次-Superposition.c
                本地定義： 現在又要在新的地方定義相同的code(理由：範疇可能是初始文檔的內容，而運用了本地文檔的方法)
                            例如： 累加n次，是屬於 #002-數學 & 計算<Math_Calculate> 的範疇
                                  而且又運用了 #004-迴圈<Lop> 的方法
                         本地文件定義則：
                            在初始定義的名稱 前 加上本地前綴以表示本地定義，同時補上初始定義的主題編號
                                例如： 初始定義: FM05-累加n次-Superposition.c
                                      本地新定義: F03_02FM05-累加n次-Superposition.c
                                      F03: 本地定義
                                       02: 初始定義主題編號( #002 ) 省略符號及最高位
                                      F03_02FM05: 底線表示關聯
                多次定義： 
                    以最原始定義為初始定義
                    例如：
                            #002 文件下有 FM05-累加n次-Superposition.c
                            #004 文件下有 F03_02FM05-累加n次-Superposition.c
                            如今又要添加新的本地定義 #026 則：
                                只需參考最原始的初始定義，即：#002 的 FM05-累加n次-Superposition.c
                                新的本地定義為: A54-02FM05-累加n次-Superposition.c
                    比較：
                        本地定義(1): F03_02FM05-累加n次-Superposition.c
                        本地定義(2): A54-02FM05-累加n次-Superposition.c
                        本地定義(n): ???-02FM05-累加n次-Superposition.c
                */
           );    

    printf("\n");       
    
    puts("\n\nEnd\n");
    
    return 0;
}
