// 說明：如果一个头文件被引用两次，
//      编译器会处理两次头文件的内容，
//      这将产生错误。为了防止这种情况，
//      标准的做法是把文件的整个内容放在条件编译语句中
#ifndef HEADER_FILE
#define HEADER_FILE

void Output();

#endif