# C_Cpp Language
![Docker Image Version (latest semver)](https://img.shields.io/docker/v/Waylon/C_Cpp?color=red&label=C_Cpp&logo=release&logoColor=red)
C語言練習及教學題    
轉發或用於其他用途前請先參考 License.rm 的版權聲明細則.  

## File Structure
目錄最後更新日期 : 20-12-10th
```
.
├── #C_Cpp
.   .
.   ├── ...
.   ├── #F00-暫存<Temp>              # Temporary     //暫存資料
.   ├── #F01_文件<Docs>              # Documents     //一般文件
.   ├── #F02_外包<Helper>            # --            //別人幫忙寫的程式, 即外包出去的程式
.   ├── #F03_承包<Supporter>         # --            //我幫別人寫的程式, 即接下的案子
.   ├── #F04_課程<Course>            # --            //課程練習
.   ├── #F05_練習<Exercise>          # --            //實作練習
.   .   .
.   .   ├── ...
.   .   ├── ======== 基本練習(Base) ========
.   .   ├── ...
.   .   ├── #B01-入門程式<Fundamental>
.   .   .   .
.   .   .   ├── ...
.   .   .   ├── #B0101-準備_環境搭建<Environment>
.   .   .   ├── #B0102-基本_資料型態<Data_Type>
.   .   .   ├── #B0103-基本_運算符<Operator>
.   .   .   ├── #B0104-Null
.   .   .   └── End
.   .   .
.   .   ├── #B02-應用數學<Applied_Mathematics>
.   .   ├── #B03-條件判斷<Judgment>
.   .   ├── #B04-迴圈<Loop>
.   .   ├── #B05-函數<Func>
.   .   .   .
.   .   .   ├── ...
.   .   .   ├── #B0501-遞迴<Recursion>
.   .   .   ├── #B0502-Null
.   .   .   └── End
.   .   .
.   .   ├── #B06-陣列<Array>
.   .   ├── #B07-字串<String>
.   .   ├── #B08-源文件<Head>
.   .   ├── #B09-指標<Pointer>
.   .   ├── #B10-結構<Struct>
.   .   ├── #B11-Null
.   .   ├── ...
.   .   ├── ======== 進階練習(Advanced) ========
.   .   ├── ...
.   .   ├── #A01-巨集<Macro>
.   .   ├── #A02-動態連結庫<DLL>
.   .   ├── #A03-資料結構<Structure>
.   .   .   .
.   .   .   ├── ...
.   .   .   ├── #A0301-陣列<Array>
.   .   .   ├── #A0302-樹<Tree> (前中後置、深度及廣度)
.   .   .   ├── #A0303-鏈結串列<Linked lists>
.   .   .   ├── #A0304-佇列<Queue>
.   .   .   ├── #A0305-堆疊<Stick>
.   .   .   ├── #A0306-字典<Dictionary>
.   .   .   ├── #A0307-雜湊表<Hash table>
.   .   .   ├── #A0308-圖<Graphic>
.   .   .   ├── #A0309-Null
.   .   .   └── End
.   .   .
.   .   ├── #A04-C++物件導向<OOP>
.   .   .   .
.   .   .   ├── ...
.   .   .   ├── #A0401-類與名稱空間<Namespace>
.   .   .   ├── #A0402-引用<Quote>
.   .   .   ├── #A0403-深入函數<Advanced Func>
.   .   .   ├── #A0404-運算符重載<Operator Overloading>
.   .   .   ├── #A0405-封裝<Encapsulation>
.   .   .   ├── #A0406-繼承<Inheritance> (C++支持多重繼承)
.   .   .   ├── #A0407-多型<Polymorphism>
.   .   .   ├── #A0408-抽象<Abstract>
.   .   .   ├── #A0409-介面/接口<Interface> (進階API)
.   .   .   ├── #A0410-虛函數<Virtual>
.   .   .   ├── #A0411-靜態<Static>
.   .   .   ├── #A0412-流<Stream>
.   .   .   ├── #A0413-異常和錯誤處理<Catch>
.   .   .   ├── #A0414-單元測試<Unit test>
.   .   .   ├── #A0415-程式覆蓋率<Code coverage>
.   .   .   ├── #A0416-null
.   .   .   └── End
.   .   .
.   .   ├── ...
.   .   ├── ======== 高階練習(Senior) ========
.   .   ├── ...
.   .   ├── #S01-多線程<Thread> (多執行緒)
.   .   ├── #S02-網路程式<Network>
.   .   .   .
.   .   .   ├── ...
.   .   .   ├── #S0201-網路架構<TCP>
.   .   .   ├── #S0202-網路架構<UDP>
.   .   .   ├── #S0203-Null
.   .   .   └── End
.   .   .
.   .   ├── ======== 其他練習(More) ========
.   .   ├── ...
.   .   ├── #M01-演算法<Algorithmic>
.   .   ├── #M02-Null
.   .   └── End
.   .
.   ├── .gitignore              # git 附加說明文件 -> 忽略同步指定文件內容
.   ├── LICENSE.md              # --            (版權)  //版權聲明
.   ├── README.md               # --            (說明)  //內容說明
.   ├── Null
.   └── ...
.
└── End
```

## 文件名稱

```
文件名稱不能夠帶有的符號:
～ !
～ ()
～ []
...
```

# 環境

```
gcc/g++:        Apple clang version 11.0.0 (clang-1100.0.33.8)
Editor:         Visual Studio Code by Microsoft
Format:         UTF-8 / LF
Extensions:     C/C++
                Bracket Pair Colorizer
                Code Runner
                One Dark Pro

```
