# 05_Exercise File Structure & Number of Exercises
目錄最後更新日期 : 20-11-9th
```
. ...
.
├── #05_Exercise
.   .
.   ├── ...
.   ├── #003-判斷<Judgment>
.   .   .
.   .   ├── ...
.   .   ├── L1_20-1102N1v0_Judgment_骰子統計.c
.   .   ├── 
.   .   └── ...
.   .
.   ├── #004-迴圈<Loop>
.   .   .
.   .   ├── ...
.   .   ├── L1_20-1026N1v0_Loop_長方形.c
.   .   ├── 
.   .   ├──  ======== 三角形 ========
.   .   ├── L2_20-1026N2v0_Loop_左上三角形.c
.   .   ├── L2_20-1026N2v1_Loop_左上三角形加邊框.c
.   .   ├── L2_20-1026N3v0_Loop_左下三角形.c
.   .   ├── L2_20-1026N3v1_Loop_左下三角形加邊框.c
.   .   ├── L2_20-1026N4v0_Loop_右上三角形.c
.   .   ├── L2_20-1026N4v1_Loop_右上三角形加邊框.c
.   .   ├── L2_20-1026N5v0_Loop_右下三角形.c
.   .   ├── L2_20-1026N5v1_Loop_右下三角形加邊框.c  
.   .   ├── L2_20-1026N6v0_Loop_單數三角形_unF.c        //需更新
.   .   ├── L2_20-1026N6v1_Loop_單數三角形加邊框_unF.c   //需更新
.   .   ├── L2_20-1026N7v0_Loop_上等腰三角形.c
.   .   ├── L2_20-1026N7v1_Loop_上等腰三角形加邊框.c
.   .   ├── 
.   .   ├──  ======== 圓形 ========
.   .   ├── L3_20-1106N1v0_Loop_空心圓繪製.c
.   .   ├── L3_20-1106N2v0_Loop_實心圓繪製.c
.   .   ├── L3_20-1106N3v0_Loop_圓形繪製.c
.   .   └── ...
.   .
.   ├── #005-函數<Func>
.   .   .
.   .   ├── ...
.   .   ├── #xxx_xx-遞迴<Recursion>
.   .   .   .
.   .   .   ├── ...
.   .   .   ├── L2-20-1118N1v0_Func-Recursion_迴圈模擬.c
.   .   .   ├── L3_20-1117N1v0_Func-Recursion_二進位排列組合.c
.   .   .   ├── 
.   .   .   ├── 
.   .   .   └── ...
.   .   .
.   .   ├──
.   .   ├── 
.   .   ├── 
.   .   └── ...
.   .
.   ├── #006-陣列<Array>
.   .   .
.   .   ├── ...
.   .   ├── L1_20-1031N1v0_Array_投票系統_bug.c //
.   .   ├── L1_20-1031N1v1_Array_投票系統.c
.   .   ├── L1_20-1031N2v0_Array_溫控系統.c
.   .   ├── L2_19-0401N1v0_Array_解析陣列.c
.   .   ├── L2_19-0401N2v0_Array_奇偶數分割.c
.   .   ├── L2_20-1106N1v0_Array_售票系統_unF.c //需更新
.   .   ├── L2_20-1106N2v0_Array_數值搜尋_unF.c //需更新
.   .   └── ...
.   .
.   ├── #007-字串<Char>
.   .   .
.   .   ├── ...
.   .   ├── L2_20-1102N2v0_Char_字元統計.c
.   .   ├── L3_20-1102N3v0_Char_單詞搜尋.c
.   .   ├── L3_20-1102N3v1_Char_單詞搜尋.c
.   .   ├── L4_20-1105N1v0_Char_插入刪除單詞_unF.c   //需更新
.   .   ├── L5_20-1105N2v0_Char_單詞替換_unF.c      //需更新
.   .   ├── 
.   .   └── ...
.   .
.   └── ...
.
└── ...
```


## 文件命名標準
```
.


難度: L1 ~ n     // 1簡單 ~ n最難
介紹: Intro      // 介紹

日期: YY-MMDD    // 日期
編號: N1 ~ n     // 1早 ~ n晚              (同一天多個題目會以編號遞增形式表示)
版本: v0 ~ n     // 0舊 ~ n新              (同一題目不同方法實作會以版本遞增形式表示)
類別: name       // 練習題的練習目的         (習題所被分配到的練習類別)
題目: name       // 題目名稱                (題目要求要自己點進去看)
狀態: state      // 文件狀態                (請參考下方文件狀態表示法)
語言: 後綴        // 後綴表示使用的程式語言


//Temp
Unit test

├── ...
├── D   & _Self_Lebal-    DeBug
├── Err & _Self_Lebal-    Error
├── F   & _Self_Lebal-    finished
├── unF & _Self_Lebal-    Unfinished
├── T   & _Self_Lebal-    Testing
├── Opt & _Self_Lebal-    Optimization
├── C   & _Self_Lebal-    Checking
└── ...
```

 Self Label Explain:  

 ‘Main_Lebal_’ & ‘xxx-SSxx-name’  
---
 Explain: Condition_Theme-’Subject&number‘-nameCH-nameEn.Type  
 Example: Opt_002-FM03-平均值-Average.c  


 'Subject&number ——> Sub(n)_‘subject&number’ ⋯⋯'  
---
 Purpose: Solve the relationships of different Theme and same code  
 Explain: AAA_xxx -SSxx- sub(n)_SSxx - ‘⋯⋯’ -nameCH-nameEn.Type  
 Example:  
           1、(Ori Theme is 002) FM05-累加n次-Superposition.c  
           2、(new Theme is 004) F03-02FM05-累加n次-Superposition.c  
               Ori: FM05 is 002-FM05  
               new: F03 is 004-F03  
               In theme 004: F03-02FM05  



End  