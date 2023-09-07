#include"checkSystem.h"
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<string.h>
using namespace std;


//统计文件中行数
int countlines() {
	fstream wordTxt;
	wordTxt.open("英语词汇.txt", ios::in);
	char buf[100];
	//行数,每读取一行行数加一
	int count=0;
	while (wordTxt.getline(buf, sizeof(buf))) {
		count++;
	}
	return count;
}
//抽查的过程
void processOfCheck(char buf[100]) {
	char answer[100] = { 0 };
	char rightAnswer[100] = { 0 };
	int judge = 0;
	for (int i = 0; i <= 99; i++) {

		//.后面是中文意思，可以开始打印
		if (buf[i] == '\0')
			break;
		if (judge == 1)
			printf("%c", buf[i]);
		if (buf[i] == ' ')
			judge = 1;
		if (judge == 0)
			rightAnswer[i] = buf[i];


	}
	printf("\n");
	printf("请输入该意思对应的单词\n");
	scanf_s("%s", answer, 100);
	if (strcmp(answer, rightAnswer) == 0) {
		printf("回答正确！\n\n");
	}
	else {
		printf("回答错误，你还有一次机会\n");
		scanf_s("%s", answer, 100);
		if (strcmp(answer, rightAnswer) == 0) {
			printf("回答正确！\n\n");
		}
		else {
			printf("回答错误,正确答案是%s\n\n", rightAnswer);
		}
	}
}
void CheckSystem::checkWords() 
{
	//设计随机数种子
	srand(time(0));
	//词典一共多少行
	int lines = countlines();
	//输入抽查单词的个数
	cout << "请输入要抽查单词的个数"<<endl;
	int num;
	cin >> num;
	
	//创建读写流
	fstream read;
	ofstream write;
	//指定读入的文件
	write.open("上次抽查的单词.txt", ios::out);
	

	//抽查num次
	for (int i = 1; i <= num; ) 
	{
		//生成随机数
		int randnum = rand() % lines;
		//写文件每次循环都重新打开，才能每一次从头开始读
		read.open("英语词汇.txt", ios::in);
		
		for (int j = 1; j <= randnum; j++)
		{
			read.getline(buf, sizeof(buf));
			
		}
		//如果是那行含有单词不是空白
		if ((buf[0] >= 97 && buf[0] <= 122) || (buf[0] >= 65 && buf[0] <= 90))
		{
			i++;
			//抽查单词的过程
			processOfCheck(buf);
			//保存单词便于复习
			write << buf << endl;
			
		}
		read.close();
	}
	write.close();
	system("pause");

}

void CheckSystem::viewSpotCheck()
{
	ifstream read;
	read.open("上次抽查的单词.txt", ios::in);
	while (read.getline(this->buf, sizeof(this->buf)))
	{
		printf("%s\n", buf);
	}
	system("pause");
}
void CheckSystem::reviewSpotCheck()
{
	ifstream read;
	read.open("上次抽查的单词.txt", ios::in);
	char rightAnswer[100]={0};
	char answer[100]={0};
	while (read.getline(this->buf, sizeof(this->buf)))
	{
		int judge = 0;
		for (int i = 0; i <= 99; i++) 
		{

			//.后面是中文意思，可以开始打印
			if (buf[i] == '\0')
				break;
			if (judge == 1)
				printf("%c", buf[i]);
			if (buf[i] == ' ')
				judge = 1;
			if (judge == 0)
				rightAnswer[i] = buf[i];
		}
		printf("\n");
		printf("请输入该意思对应的单词\n");
		scanf_s("%s", answer, 100);
		if (strcmp(answer, rightAnswer) == 0) {
			printf("回答正确！\n\n");
		}
		else {
			printf("回答错误，你还有一次机会\n");
			scanf_s("%s", answer, 100);
			if (strcmp(answer, rightAnswer) == 0) {
				printf("回答正确！\n\n");
			}
			else {
				printf("回答错误,正确答案是%s\n\n", rightAnswer);
			}
		}

	}
	system("pause");
}