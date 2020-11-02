// Fig. 10.3: fig10_03.c
// Card shuffling and dealing program using structures

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define CARDS 52    //52張牌
#define FACES 13    //13個號碼
#define HANDS 5    //抽5次

//#define _DEBUG_     //debug開關

/* 枚舉變量定義 */
enum Mode{  
    pairMode = 1, 
    threeOfKindMode = 2, 
    fourOfKindMode = 3, 
    straightHandMode = 4, 
    flushHandMode = 5 
};  //End of enum: Mode

enum playerNum{ 
    playerNumA = 1, 
    playerNumB = 2, 
    playerNumC = 3 
};  //End of enum: player Numer

// card structure definition                  
struct card{                                 
    const char *face; // define pointer face
    const char *suit; // define pointer suit
    int face_num;
    int suit_num;
}; // end struct card

typedef struct card Card; // new type name for struct card  

// prototypes
void fillDeck( Card * const wDeck, const char * wFace[], const char * wSuit[] );
void shuffle( Card * const wDeck );
void deal( const Card * const wDeck ,Card * const hand, int playerNumber);

/*functions*/
int pair( const Card * const hand , const char * wFace[], int faceCounter[]);          //判斷手牌裡是否有 對子 & 雙對子
int threeOfKind( const Card * const hand, const char * wFace[], int faceCounter[]);    //判斷手牌裡是否有 3條，即：3個同數字、不同花色
int fourOfKind( const Card * const hand, const char * wFace[], int faceCounter[]);     //判斷手牌裡是否有 4條，即：4個同數字、不同花色 ->炸彈
int straightHand(const Card * const hand, const char * wFace[], int faceCounter[]);   //判斷手牌裡是否有 5張 或 以上連續數字牌組
int flushHand(const Card * const hand, const char * wFace[], int faceCounter[]);      //判斷手牌裡是否有 同花順、即：5張 或 以上同樣花色、連續數字牌組

size_t hands_Calculus(const Card * const hand, const char * wFace[], int faceCounter[], int getMode);   //手牌歸類處理

int main( void ) { 

    struct playerScore{ 
        /*取得分數*/
        int get_Pair;
        int get_ThreeOfKind;
        int get_FourOfKind;
        int get_StraightHand;
        int get_FlushHand;
        int get_totalScore; //總分數
    } PlayerA, PlayerB; // end struct player

    /*手牌範圍檢查*/
    if(HANDS > 52){
        printf("Error : HANDS Out of range! plz check the HANDS define!\n");
        puts("......End of run");
        return 0;
    }

    /*牌組*/
    Card deck[ CARDS ]; // define array of Cards
    Card handA[ HANDS ]; //手牌組
    Card handB[ HANDS ]; //手牌組

    // initialize array of pointers
    const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    // initialize array of pointers
    const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades"};

    int faceCounter[FACES+1];

    srand( time( NULL ) ); // randomize
    /*生成牌組 & 打亂牌組*/
    fillDeck( deck, face, suit ); // load the deck with Cards
    shuffle( deck ); // put Cards in random order    洗牌
    

    #ifdef _DEBGU_
        puts("\n\n---- Functions Start ----\n");

        pair(hand,face,faceCounter);    //判斷這 5 張牌裡是否有 對子 
        threeOfKind(hand,face,faceCounter);  //判斷這 5 張牌裡是否有 3張J
        fourOfKind(hand,face,faceCounter);   //判斷這 5 張牌裡是否有 4張A
        straightHand(hand,face,faceCounter); //判斷這 5 張牌裡是否有 5張連續的牌
        flushHand(hand,face,faceCounter);    //判斷這 5 張牌裡是否有 5張同樣花色的牌

        puts("\n---- End of program ----\n");
    #else
        printf("\n-------------------------------------------------\n\n");   //排版間隔
    /*玩家A 分數計算*/
        printf("Player_A's Hand contains of poker:\n\n");
        deal(deck, handA, playerNumA);
        puts("\n");
        PlayerA.get_Pair = pair(handA,face,faceCounter);
        PlayerA.get_ThreeOfKind = threeOfKind(handA,face,faceCounter);
        PlayerA.get_FourOfKind = fourOfKind(handA,face,faceCounter);
        PlayerA.get_StraightHand = straightHand(handA,face,faceCounter);
        PlayerA.get_FlushHand = flushHand(handA,face,faceCounter);
        PlayerA.get_totalScore = PlayerA.get_Pair + PlayerA.get_ThreeOfKind + PlayerA.get_FourOfKind + PlayerA.get_StraightHand + PlayerA.get_FlushHand;
        printf("\nThe total score is : %d\n", PlayerA.get_totalScore);

        printf("\n-------------------------------------------------\n\n");   //排版間隔
    /*玩家B 分數計算*/
        printf("Player_B's Hand contains of poker:\n\n");
        deal(deck, handB, playerNumB);
        puts("\n");
        PlayerB.get_Pair = pair(handB,face,faceCounter);
        PlayerB.get_ThreeOfKind = threeOfKind(handB,face,faceCounter);
        PlayerB.get_FourOfKind = fourOfKind(handB,face,faceCounter);
        PlayerB.get_StraightHand = straightHand(handB,face,faceCounter);
        PlayerB.get_FlushHand = flushHand(handB,face,faceCounter);
        PlayerB.get_totalScore = PlayerB.get_Pair + PlayerB.get_ThreeOfKind + PlayerB.get_FourOfKind + PlayerB.get_StraightHand + PlayerB.get_FlushHand;
        printf("\nThe total score is : %d\n", PlayerA.get_totalScore);
    /*玩家分數比較*/
        if(PlayerA.get_totalScore > PlayerB.get_totalScore){
            printf("\n\n** Player A is Winner!\n");
        }else if(PlayerA.get_totalScore == PlayerB.get_totalScore){
            printf("\n\n** Player A and Player B are Flat!\n");    //平手
        }else{
            printf("\n\n** Player B is Winner!\n");
        }

    #endif

   return 0;
} // end main

// place strings into Card structures
void fillDeck( Card * const wDeck, const char * wFace[], const char * wSuit[] ) { 
    size_t i; // counter

   // loop through wDeck
    for (i=0; i<CARDS; ++i) { 
        wDeck[i].face = wFace[i % FACES];   //產生1～13編號 4組 到卡牌組
        wDeck[i].suit = wSuit[i / FACES];
        wDeck[i].face_num = i % FACES;
        wDeck[i].suit_num = i / FACES;
      
    } // end for
} // end function fillDeck

// shuffle cards 洗牌
void shuffle( Card * const wDeck ) { 
   size_t i; // counter
   size_t j; // variable to hold random value between 0 - 51
   Card temp; // define temporary structure for swapping Cards

   // loop through wDeck randomly swapping Cards
    for (i=0; i<CARDS; ++i) { 
        j = rand() % CARDS;

        /*SWAP*/
        temp = wDeck[i];      
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;      
    } // end for
} // end function shuffle

// deal cards 發牌 & 顯示手牌
void deal( const Card * const wDeck , Card * const hand, int playerNumber) { 
    size_t i; // counter

    size_t getCard, endOfGet;

    getCard = playerNumber * HANDS;
    endOfGet = getCard + HANDS;

    if(playerNumber == 1){
        getCard = 0;
        endOfGet = HANDS;
    }

   // loop through wDeck
    for (i=getCard; i<endOfGet; i++) {
        printf( "%5s of %-8s%s", wDeck[i].face, wDeck[i].suit, (i+1) % 2 ? "  " : "\n" );
        hand[i] = wDeck[i];
    } // end for

} // end function deal



// functions ------------------------------------------------------

// determines if there are any pairs in the hand 對子
int pair( const Card * const hand, const char * wFace[], int faceCounter[]) {

    int setScore = 0, weights = 1;  //Weights = 權重
    int i, num = 1; //loop counter
    bool request = hands_Calculus( hand, wFace, faceCounter, pairMode);

    /* 檢查手牌是否有 對子 */
    if(request){
        /* checking: is more than one pairs? */
        if( faceCounter[1] != -1 ){
            printf("1、 he hand contains is more than one pairs:\n");
            for(i=0; i<FACES; i++){
                if( faceCounter[i] == -1 ) break;
                printf("\t%d、 %s\n", num++, wFace[faceCounter[i]]);
            }
            puts("");
            setScore+=2;
        }else{
            //需添加 faceCounter[0] == -1 的檢查機制判斷是否為 -1，若是，則request來源錯誤。
            printf("1、 The hand contains a pair of : %s.\n", wFace[faceCounter[0]]);
            setScore++;
        }
    }else{  //沒有對子
        if(faceCounter[0] == -1){
            printf("1、 No pair in the hand contains.\n");
        }else{
            printf("1、 Error: pair() #i: is out of range.\n");
        }
    }

    return setScore * weights;
} // end function pair

/* 3個J */
int threeOfKind(const Card * const hand, const char * wFace[], int faceCounter[]){

    int setScore = 0, weights = 3;  //Weights = 權重
    int i, num = 1; //loop counter
    bool request = hands_Calculus( hand, wFace, faceCounter, threeOfKindMode);

    /* 檢查手牌是否有 三條 */
    if(request){
        /* checking: is more than one three_of_kind? */
        if( faceCounter[1] != -1 ){
            printf("2、 The hand contains is more than one three_of_kind:\n");
            for(i=0; i<FACES; i++){
                if( faceCounter[i] == -1 ) break;
                printf("\t%d、 %s\n", num++, wFace[faceCounter[i]]);
            }
            puts("");
            //setScore = (i/2);    //5張牌不可能出現 2個 3條
        }else{
            //需添加 faceCounter[0] == -1 的檢查機制判斷是否為 -1，若是，則request來源錯誤。
            printf("2、 The hand contains a three_of_kind of : %s.\n", wFace[faceCounter[0]]);
            setScore+=1;
        }
    }else{  //沒有三條
        if(faceCounter[0] == -1){
            printf("2、 No three_of_kind in the hand contains.\n");
        }else{
            printf("2、 Error: pair() #i: is out of range.\n");
        }
    }

    return setScore * weights;
} // end function threeOfKind

/* 4個A */
int fourOfKind(const Card * const hand, const char * wFace[], int faceCounter[]){
    
    int setScore = 0, weights = 4;  //Weights = 權重
    int i, num = 1; //loop counter
    bool request = hands_Calculus( hand, wFace, faceCounter, fourOfKindMode);

    /* 檢查手牌是否有 炸彈 */
    if(request){
        /* checking: is more than one four_of_kind? */
        if( faceCounter[1] != -1 ){
            printf("3、 The hand contains is more than one four_of_kind:\n");
            for(i=0; i<FACES; i++){
                if( faceCounter[i] == -1 ) break;
                printf("\t%d、 %s\n", num++, wFace[faceCounter[i]]);
            }
            puts("");
            //setScore = (i/2);    //5張牌不可能出現 2個 4條
        }else{
            //需添加 faceCounter[0] == -1 的檢查機制判斷是否為 -1，若是，則request來源錯誤。
            printf("3、 The hand contains a four_of_kind of : %s.\n", wFace[faceCounter[0]]);
            setScore++;
        }
    }else{  //沒有炸彈
        if(faceCounter[0] == -1){
            printf("3、 No four_of_kind in the hand contains.\n");
        }else{
            printf("3、 Error: pair() #i: is out of range.\n");
        }
    }
    return setScore * weights;
} // end function fourOfKind



//判斷這 5 張牌裡是否有 5張連續的牌
int straightHand(const Card * const hand, const char * wFace[], int faceCounter[]){

    int setScore = 0, weights = 5;  //Weights = 權重
    int i, num = 1; //loop counter
    size_t request = hands_Calculus( hand, wFace, faceCounter, straightHandMode);

    /* 檢查手牌是否有  順子*/
    if( 5 <= request){
        /* checking: is more than one straiHand? */

        printf("4、 The hand contains a straight_Hand.\n");
        for(i=0; i<request; i++){
            if( faceCounter[i] == -1 ) break;
            printf("\t%d、 %s\n", num++, wFace[faceCounter[i]]);
        }
        setScore++;
    }else{  //沒有順子
        if(faceCounter[0] == -1){
            printf("4、 No straight_Hand in the hand contains.\n");
        }else{
            printf("4、 Error: straight_Hand() #i: is out of range.\n");
        }
    }
    return setScore * weights;
}

//判斷這 5 張牌裡是否有 5張同樣花色的牌
int flushHand(const Card * const hand, const char * wFace[], int faceCounter[]){

    int setScore = 0, weights = 6;  //Weights = 權重
    int i, num = 1; //loop counter
    size_t request = hands_Calculus( hand, wFace, faceCounter, flushHandMode);

    /* 檢查手牌是否有  順子*/
    if(request){
        /* checking: is more than one straiHand? */

        printf("5、 The hand contains a flush_Hand.\n");
        for(i=0; i<request; i++){
            if( faceCounter[i] == -1 ) break;
            printf("\t%d、 %s\n", num++, wFace[faceCounter[i]]);
        }
        puts("");
        setScore++;
    }else{  //沒有順子
        printf("5、 No flush_Hand in the hand contains.\n");
    }
    return setScore * weights;
}


/*手牌歸類處理*/
size_t hands_Calculus(const Card * const hand, const char * wFace[], int faceCounter[], int getMode){

    /*define the variable*/
    unsigned int counter[FACES][ 4+1 ] = {0};  //手牌歸類統計，其中 FACES為牌面數目； 4為牌面花色數目； +1為手牌 相同數字的總數統計
    unsigned int pairSave[30] = {0};

    enum returnValue{ finished = 5, noValue = -1 };

    size_t i, j, r, p;    // loop counters
    size_t faceMax = 0, suitMax = 0;
    size_t first, brokenCounter = 0;

    /* value setting */
    for(i=0; i<FACES; i++)
        faceCounter[i] = -1;   //初始化內容為 -1

    /* Debug: value checking */
        #ifdef _DEBUG_
        /* check: getMode */
            printf("Debug: hands_Calculus()\t #getMode: %d\n", getMode);
        /* check: faceCounter[] */
            printf("Debug: hands_Calculus():\n\t#faceCounter[FACES]:\n");
            for(i=0; i<FACES; i++) 
                printf("\t\tset faceCounter[%lu]\t=\t%d\n", i, faceCounter[i]);
            puts("End Debug\n\n");
        #endif

    /* Counter */
    for (r=0; r<HANDS; ++r){
        ++counter[hand[r].face_num][hand[r].suit_num];    //計算手牌，將手牌歸類
        ++counter[hand[r].face_num][4]; // 0～3為牌面花色； 4為手牌相同數字的總數統計
    }

    /* Debug: counter[FACES][4] -> Display */
        #ifdef _DEBUG_
            /* check: counter[][] */
            printf("Debug: hands_Calculus():\n\t#counter[FACES][4]:\n");
            for(i=0; i<FACES; i++){ 
                printf("\t\t");
                printf("set coutner[%lu][]:\t", i);  
                for(j=0; j<=4; j++){
                    printf("%u\t", counter[i][j]);
                    if( j==3 ){ printf(" =\t");}
                }
                puts("");
            }
            puts("End Debug\n\n");
        #endif



    /*手牌統計*/
    i = 0;  // i 統計符合條件的數量
    for (p=0; p<4; p++){ //牌面花色統計
        for(r=0; r<FACES; r++){ //牌面數字統計
            switch (getMode) {
                case 1: //getMode 1 = a pair
                    if(counter[r][4] == 2){
                        faceCounter[i] = r; //儲存 對子
                        i++;
                    }
                    break;

                case 2: //getMode 2 = three of kind
                    if(counter[r][4] == 3){
                        faceCounter[i] = r; //儲存 3條
                        i++;
                    }
                    break;

                case 3: //getMode 3 = four of kind 炸彈
                    if(counter[r][4] == 4){
                        faceCounter[i] = r; //儲存 4條炸彈
                        i++;
                    }
                    break;

                case 4: //getMode 4 = straight Hand 順子
                    //統計最長順子長度
                    if(counter[r][4] > 0){
                        i++;
                        if(faceMax < i){
                            faceMax = i;
                        }
                    }else{
                        i = 0;
                    }
                    break;

                case 5: //getMode 3 = flush Hand 同花順
                    //統計最長順子長度
                    if(counter[r][p] > 0){
                        i++;
                        if(faceMax < i)
                            faceMax = i;
                    }else{
                        i = 0;
                    }
                    //獲得 faceMax值
                    break;
                
                default:
                    printf("Error!\tgetMode variable out of range!\n");
                    puts("checking\n"); //自動修正： 未寫
                    break;
            }

            // if((5 <= i) && (getMode == 4) && (r == FACES-1)){
            //     return true;
            // }else{
            //     return false;
            // }
        }

        #ifdef _DEBUG_
            printf("Debug: hands_Calculus()\t$ counter #i: %lu\n", i);
            puts("\n\n");
        #endif

        /* return Mode 1 to 4 */
        if( 0 < getMode && getMode <= 4 ){    
            if( getMode == 4){
                return ( 5 <= faceMax) ? faceMax : false;
            }
            return (0 < i) ? true : false;
        }

        /* 計算同花中最長多少順*/
        if(suitMax < faceMax){  //faceMax值在此花色中最長的寫入 suitMax
            suitMax = faceMax;
        }else{
            faceMax = 0; //清除
        }
    }
    return ((5 <= suitMax) && (getMode == 5)) ? true : false;
}
