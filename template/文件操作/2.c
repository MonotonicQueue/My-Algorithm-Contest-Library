#include <stdio.h>
int main(){
    /*
    fscanf(文件,"",)
    读数据：
    int fscanf( FILE *stream, const char  *format, ... );
    • 熟悉的 scanf等价于 fscanf( stdin, format, ... );。
    • 返回值：成功接收参数的数量（可以为零），或者若输入首个参数赋值前发生失败则为EOF。
    • 如何从键盘这类无尽文本流读数据，必须思考合适的终止方法。
    写数据：
    int fprintf( FILE *stream, const char *format, ... );
    • 熟悉的 printf等价于 fprintf( stdout, format, ... ); 。
    • 返回值：输出的字符数，或若出现输出错误或编码错误则为负值。

    */
    FILE *fp = fopen("2.txt","r");
    int n;
    fscanf(fp,"%d",&n);
    printf("%d",n);
    
   fclose(fp);
   fp = fopen("2.txt","w");
   fprintf(fp,"114514");
    return 0;
}