// Fig. 10.3: fig10_03.c
// Card shuffling and dealing program using structures

//缺：分數權重、兩名玩家
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define CARDS 52    //52張牌
#define FACES 13    //13個號碼
#define HANDS 5    //抽5次

//#define _DEBUG_     //debug開關

enum Mode{ pairMode = 1, threeOfKindMode = 2, fourOfKindMode = 3, straightHandMode = 4, flushHandMode = 5 };
enum playerNum{ playerNumA = 1, playerNumB = 2, playerNumC = 2};
// card structure definition                  
struct card {                                 
    const char *face; // define pointer face
    const char *suit; // define pointer suit
    int face_num;
    int suit_num;
}; // end struct card

struct playerScoreMark{ 
    int get_playerHands;
    int get_totalScore;
} PlayerA, PlayerB; // end struct player

typedef struct card Card; // new type name for struct card  

// prototypes
void fillDeck( Card * const wDeck, const char * wFace[], const char * wSuit[] );
void shuffle( Card * const wDeck );
void show_wDeck(const Card * const wDeck);

void deal(const Card * const wDeck, Card * const hand, int playerNumber, int hands);


int main( void ) { 

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

    PlayerA.get_playerHands = 0;
    PlayerB.get_playerHands = 0;


    srand( time( NULL ) ); // randomize
    /*生成牌組 & 打亂牌組*/
    fillDeck( deck, face, suit ); // load the deck with Cards
    shuffle( deck ); // put Cards in random order    洗牌

    //show_wDeck(deck);

    deal(deck, handA, playerNumA, PlayerA.get_playerHands);

   return 0;
} // end main

// place strings into Card structures 產生牌組
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

void show_wDeck(const Card * const wDeck) {
    for (int i = 0; i < 52; i++) {
        printf( "%5s of %-8s%s", wDeck[i].face, wDeck[i].suit, (i+1) % 2 ? "  " : "\n" );
    }
    
}

//發牌
void deal(const Card * const wDeck, Card * const hand, int playerNumber, int hands) {

    //wDeck的起點和終點
    int getCard, endOfGet;    

    //計算
    getCard = playerNumber * hands;
    endOfGet = getCard + hands;

    //如果是第一個玩家則預設起點為
    if(playerNumber == 1) {
        getCard = 0;
        endOfGet = hands;
    }

    //發牌
    for (int i = getCard; i < endOfGet; i++) {
        hand[i] = wDeck[i];
    }

    //顯示
    for (int i = getCard; i < endOfGet; i++) {
        printf( "%5s of %-8s%s", hand[i].face, hand[i].suit, (i+1) % 2 ? "  " : "\n" );
    }
    

}

//計算手牌分數
int Calculus(const Card * const hand, int hands) {

    for (int i = 0; i < hands; i++) {
        if(hand[i].face_num == 10) {
            
        }
    }
    

}