#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

void main(){
    //duanluo 表示段落数，words表示某一段的单词数
    int duanluo = 0, words = 0;
    //min表示最小段落的单词数，max：最大段落的单词数，sum：单词总数
    int min = 65525, ave = 0, max = 0,sum = 0;
    FILE* fp;        //文件指针
    
    char buffer[MAX_LINE] ;        //缓冲区
    int len ;    //行字符个数
    int i;
    fp = fopen("test.txt","r");
    if(fp == NULL){
        printf("cannot open file!");
        exit(0);
    }
    //读取文件内容
    while(! feof(fp)){
        
        // fgets() 在读出 MAX_LINE 个字符之前，遇到 换行符 或 EOF 则读出结束
        if(fgets(buffer, MAX_LINE, fp) != NULL){
            duanluo ++;
            len = strlen(buffer);
            //遇到第一个空格之前已有一个单词
            words = 1;
            sum ++;
            //len - 1 是为了去掉换行符所占位置
            for(i = 0; i < len - 1; i++){
                if(buffer[i] == ' '){
                    words ++;
                    sum ++;
                }
            }
        }
        
        if(min > words){
            min = words;
        }
        if(max < words){
            max = words;
        }
        
    }

    fclose(fp);
    ave = sum / duanluo;
    //输出
    printf("\n\t 总单词数为 %d \n \n",sum);
    printf("\t 最小段落单词数为 %d \n \n",min);
    printf("\t 最大段落单词数为 %d \n \n",max);
    printf("\t 总段落数为 %d \n \n",duanluo);
    printf("\t 段落平均单词数为 %d \n",ave);

}

