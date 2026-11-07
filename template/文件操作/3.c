#include <stdio.h>
int main(){
    /*
    读数据：
    char *fgets( char *str, int count, FILE *stream );
    • 从文件流读取最多 count -1 个字符（末尾追加一个空字符 '\0'）存储于 str 字符数组。若遇
    文件尾或换行符则终止分析。
    • 返回值：成功时 str，失败时 NULL 。
    • 注意：gets(str) 与 fgets( str, count, stdin)；的语义区别。
    写数据：
    int fputs( const char *str, FILE *stream );
    • 熟悉的 puts等价于 fputs( str, stdout); 。
    • 返回值：成功时，返回非负值。失败时，返回 EOF 并设置错误指示。

    读数据：
    int fgetc( FILE *stream );
    • 熟悉的 getchar（非getc）等价于 fgetc(stdin);。
    • 从给定的输入流读取下一个字符。
    • 返回值：成功时为作为 unsigned char 获得并转换为 int 的字符，失败时为 EOF 。
    写数据：
    int fputc( int ch, FILE *stream );
    • 熟悉的 putchar等价于 fputc(stdout); 。
    • 返回值：成功时返回写入的字符。失败时返回 EOF 。

    */
    FILE *fp = fopen("3.txt","r");
    char buf[255];
    fgets(buf,255,fp);
    printf("%s",buf);
    fclose(fp);
    fp = fopen("3.txt","w");
    fputs(buf,fp);
    return 0;
}