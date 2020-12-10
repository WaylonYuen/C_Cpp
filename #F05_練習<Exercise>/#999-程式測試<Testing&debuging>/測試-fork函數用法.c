// fork1.c
#include <stdio.h>
#include <unistd.h>

int main() {
  // 建立子行程
  fork();

  // 從這裡開始變成兩個行程

  // 兩個行程執行同樣的程式
  printf("Hello world!\n");

  return 0;
}