// 說明：有时需要从多个不同的头文件中选择一个引用到程序中。
//      例如，需要指定在不同的操作系统上使用的配置参数。
#if SYSTEM_1 
   # include "system_1.h"
#elif SYSTEM_2
   # include "system_2.h"
#elif SYSTEM_3
   ...
#endif