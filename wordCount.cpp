#include<stdio.h>
#include<string.h>
int getCountNum(FILE *f);
int getWordNum(FILE *f);
int main(int argc,char *argv[]){
	//-c ���� -w 
	char *parameter = argv[1]; 
	//�ļ�·�� 
	char *inputFileName = argv[2];
	//��ȡ�ļ�ָ�� 
	FILE *f;
	f = fopen(inputFileName,"r"); 
	if(f != NULL && 0 == strcmp("-c",parameter)){
		//ͳ���ַ��� 
		printf("�ַ���:%d",getCountNum(f));
	}else if(f != NULL &&  0 == strcmp("-w",parameter)){
		//ͳ�Ƶ������� 
		printf("������:%d",getWordNum(f));
	}
}
int getCountNum(FILE *f){
	int count = 0;
	//���ζ�ȡ�ַ� 
	while(fgetc(f) != EOF){ 
		count++;
	}
	return count;
}
int getWordNum(FILE *f){
	int count = 0; 
	char ch = ' ';
	char pre = ' ';
	//���ζ�ȡ�ַ� 
	while((ch = fgetc(f)) != EOF){ 
		if(ch == ' ' || ch == ','){
			//��ֹ�����Ŀո�Ͷ��ŵ�������Լ���ͷΪ�ո񶺺ŵ����
			if(pre != ' ' && pre != ','){
				count++;
			}
			pre = ch;
			continue;
		}
		pre = ch;
	}
	//��ֹ���һ���ַ�����û�пո�򶺺ŵ����
	if(pre != ' ' && pre != ','){
		printf("%c",pre);
		count++;
	}
	return count;
}
