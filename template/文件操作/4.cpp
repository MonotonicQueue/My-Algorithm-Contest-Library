#include <stdio.h>
struct node{
    int a,b;
}c[12];
int main(){
    /*
    读数据：
    size_t fread( void *buffer, size_t size, size_t count, FILE *stream );
    • 从给定输入流 stream 读取至多 count 个 size 字节的对象到数组 buffer 中。
    • 返回成功读取的对象数，若出现错误或文件尾条件，则可能小于 count 。
    • fread 不区别文件尾和读错误，而调用者必须用 feof和 ferror鉴别是文件尾还是读错误。
    写数据：
    size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );
    • 写 count 个size字节的来自给定数组 buffer 的对象到输出流stream。
    • 返回成功写入的对象数，若错误发生则可能小于 count 。

    */
    FILE *fp = fopen("4.bin","rb");
    fread(c,sizeof(node),5,fp);
    printf("%d %d\n",c[0].a,c[3].b);
    // c[0] = {1,2};
    // c[1] = {1,3};
    // c[2] = {23,4};
    // c[3] = {1,5};
    // c[4] = {24,5};
    fclose(fp);
    fp = fopen("4.bin","wb");
    fwrite(c,sizeof(node),5,fp);
    return 0;
}