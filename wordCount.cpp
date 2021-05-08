#include<stdio.h>
#include<string.h>
int getCountNum(FILE *f);
int getWordNum(FILE *f);
int main(int argc,char *argv[]){
	//-c 或者 -w 
	char *parameter = argv[1]; 
	//文件路径 
	char *inputFileName = argv[2];
	//获取文件指针 
	FILE *f;
	f = fopen(inputFileName,"r"); 
	if(f != NULL && 0 == strcmp("-c",parameter)){
		//统计字符数 
		printf("字符数:%d",getCountNum(f));
	}else if(f != NULL &&  0 == strcmp("-w",parameter)){
		//统计单词数量 
		printf("单词数:%d",getWordNum(f));
	}
}
int getCountNum(FILE *f){
	int count = 0;
	//依次读取字符 
	while(fgetc(f) != EOF){ 
		count++;
	}
	return count;
}
int getWordNum(FILE *f){
	int count = 0; 
	char ch = ' ';
	char pre = ' ';
	//依次读取字符 
	while((ch = fgetc(f)) != EOF){ 
		if(ch == ' ' || ch == ','){
			//防止连续的空格和逗号的情况，以及开头为空格逗号的情况
			if(pre != ' ' && pre != ','){
				count++;
			}
			pre = ch;
			continue;
		}
		pre = ch;
	}
	//防止最后一个字符后面没有空格或逗号的情况
	if(pre != ' ' && pre != ','){
		printf("%c",pre);
		count++;
	}
	return count;
}
