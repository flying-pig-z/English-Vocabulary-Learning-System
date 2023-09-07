#include<iostream>
#include<stdio.h>
#include<string>
#include<fstream>
#include <windows.h>
#include"wordManagement.h"
#include"systemManagement.h"
using namespace std;

//判断输入是否正确
int judgeInput(char* word)
{
	//如果前面单词不是英文单词错误
	if (word[0] < 97 || word[0]>122)
		return 0;
	else 
	{
		//如果没有错误
		int count = 0;
		for (int i = 0; i <= 99; i++)
		{
			if (word[i] == '.')
				count++;
		}
		if (count == 1)
			return 1;
		else 
			return 0;
	}
}

//判断输入的单词是否与文件读取到缓冲区的那一行相同，相同返回1,不同返回0
int compareInputAndBuf(char* buf, char* word)
{
	int localJudgement = 1;//如果发现不匹配，则此变量变为0

	for (int i = 0; i <= 99; i++)
	{
		//如果发现读取完毕，结束操作
		if (buf[i] == ' ' && word[i] == 0)
			break;
		else
		{
			//如果发现其中一个英文字符不同，结束操作，并改变localJudgement的值
			if (buf[i] != word[i])
			{
				localJudgement = 0;
				break;
			}
		}

	}
	if (buf[0] == 0 || buf[0] == ' ')//确保那一行开头就是英文
		localJudgement = 0;
	return localJudgement;
}


//判断单词是否存在的函数，存在返回所在的行数，不存在返回0
int wordExit(char* word)
{

	char buf[100] = { 0 };
	int count=0;
	//文件流对象
	ifstream ifs;
	ifs.open("英语词汇.txt", ios::in);
	//一行一行读取，并判断
	while (ifs.getline(buf, sizeof(buf)))
	{
		int localJudgement = 0;
		count++;
		//比较读取与输入的单词，相同返回行数
		if (compareInputAndBuf( buf, word) == 1)
		{
			ifs.close();
			return count;
		}

	}
	//找不到相同返回0
	ifs.close();
	return 0;
}





/*

add module


*/


//instructions for how to add words
void addInstructions() {
	
	cout << "请输入你要添加的单词" << endl;
	cout << "注意事项：";
	cout << "请认真按照格式输入，不然会导致抽查功能出错" << endl;
	cout << "例：" << endl;
	cout << "able adj.有能力的；出色的" << endl;
}
//the function of add words
void addword() 
{
	//输入要添加的单词
	char a[500] = { 0,0 };
	for (int i = 0; i <= 499; i++)
	{
		scanf_s("%c", &a[i], 1);
		if (a[i] == '\n')
			break;
	}
	//打开文件输入流
	ofstream ofs;
	ofs.open("英语词汇.txt", ios::app);
	//判断输入单词格式是否正确，正确则将该单词输入文档，错误发出提醒并返回
	if(judgeInput(a))
		ofs << a;
	else
	{
		printf("输入格式错误\n");
		Sleep(500);
	}
	//关闭文件输入流
	ofs.close();
}
//Judge whether to exit or continue
void exitOrContinue(int &j) {
	cout << "继续输入请按1,退出按0。" << endl;
	cin >> j;
	for (;;)
	{
		if (j != 0 && j != 1)
		{
			cout << "输入错误，请重新输入" << endl;
			cin >> j;
		}
		else
			break;
	}
}
void WordManagement::add() {
	for (;;)
	{
		system("cls");
		systemmanagement.displayManageInterface();
		getchar();
		//instructions for how to add words
		addInstructions();
		//the function of add words
		addword();
		//judge whether exit or continue
		int j;
		exitOrContinue(j);
		if (j == 0)
			break;
	}
}


/*

delete module


*/
//将文件中文字全部删除的函数
void allDelete() 
{
	ofstream ofs;
	//ios::trunc----重新删除文件再创建
	ofs.open("英语词汇.txt", ios::trunc);
	ofs << "";
	ofs.close();
	cout << "已经全删";
}

//确认是否全删
void ask()
{
	cout << "你确定要全删吗？真的吗？真的吗？？！" << endl;
	cout << "输入0取消全删，输入1全删" << endl;
}


void WordManagement::deleteW() {
	for (;;)
	{
		//刷新界面
		system("cls");
		systemmanagement.displayManageInterface();
		//选择界面
		cout << "请选择模式：" << endl
			<< "0.返回" << endl
			<< "1.清除全部（慎用！！！！！！）" << endl
			<< "2.清除单个单词" << endl;


		int localJudge1=0;//做出选择记录在变量中
		cin >> localJudge1;


		//全删和清除单个单词 
		if (localJudge1 == 1) //全删
		{
			
			ask();
			int judge2;
			cin >> judge2;
			if (judge2 == 0)
				break;
			else 
			{
				ask();
				cin >> judge2;
				if (judge2 == 0)
					break;
				else 
				{
					allDelete();
				}
			}
		}
		else if (localJudge1 == 2)
		{
			//输入单词
			cout << "请输入你要输入的单词\n";
			char word[100] = { 0 };
			scanf_s("%s", word, 100);
			//单词不存在
			if (wordExit(word) == 0)
			{
				cout << "单词不存在" << endl << "正在返回上级目录" << endl;
				Sleep(1000);
				break;
			}
			//单词存在
			else
			{
				printf("单词存在,正在删除\n");
				//原理：打开两个文件，先将词汇表中除那个词外其他单词移动到中间文件
				//再将中间内容写入词汇表
				fstream wordTxt;
				fstream mTxt;


				//第一步：检查是否是那个单词，如果不是将单词移动到另外一个文件
				wordTxt.open("英语词汇.txt", ios::in);
				mTxt.open("中间文件.txt", ios::out);
				char buf[100];
				while (wordTxt.getline(buf, sizeof(buf)))
				{
					
						if (compareInputAndBuf(buf, word) ==0)
						{
							//如果输入单词与读取到那行单词不同，则移动到中间文件
							mTxt << buf << endl;
						}
						
				}
				wordTxt.close();
				mTxt.close();


				//再将中间内容写入词汇表
				wordTxt.open("英语词汇.txt", ios::out);
				mTxt.open("中间文件.txt", ios::in);
				while (mTxt.getline(buf, sizeof(buf)))
				{
					wordTxt << buf << endl;
				}


				//操作完后退出
				system("cls");
				printf("删除成功");
				Sleep(1000);
				break;
			}

		}
		else if (localJudge1 == 0)
			break;
		else {
			printf("你输错了,正在返回。");
			Sleep(500);
			break;
		}
	}
}




/*

modify module


*/

//打印单词，并把单词所在行数返回给count,单词存在返回1，不存在返回0
int printWord(char* word, int& count)
{
	//开始寻找
	//文件内容读取到buf
	char buf[100] = { 0 };
	//创建文件流对象
	fstream read;
	read.open("英语词汇.txt", ios::in);
	if (wordExit(word) == 0)//单词不存在
	{
		printf("单词不存在,正在返回");
		Sleep(500);
		return wordExit(word);
	}
	else//单词存在
	{
		
			//一行一行读，然后进行比较
			while (read.getline(buf, sizeof(buf)))
			{
				count++;//计算此单词在哪一行
				//如果发现相同的单词，则进行打印
				if (compareInputAndBuf(buf,word)==1)
				{
						
					printf("%s\n", buf);
					read.close();
					break;
				}
			

			}
			return wordExit(word);
	}
}
//修改单词
void modifyWord(char *word,int count)
{
	int count1=0;
	fstream read;
	fstream write;
	read.open("英语词汇.txt",ios::in);
	write.open("中间词汇.txt", ios::out);
	char buf[100];
	while (read.getline(buf, sizeof(buf)))
	{
		count1++;
		if (count1 == count)
		{
			write << word << endl;
		}
		else
		{
			write << buf << endl;
		}

	}
	read.close();
	write.close();
	read.open("中间词汇.txt", ios::in);
	write.open("英语词汇.txt", ios::out);
	while (read.getline(buf, sizeof(buf)))
	{
		write << buf << endl;
	}
	read.close();
	write.close();

}
void WordManagement::modify() {
	//刷新界面
	system("cls");
	systemmanagement.displayManageInterface();
	//输入你要修改的单词
	cout << "请输入你要修改的单词:\n";
	char word[100]={0};
	scanf_s("%s", word, 100);


	int count=0;//这个词在哪一行
	int exit = 1;//是否存在

	//打印单词，并把单词所在行数返回给count,单词存在返回1，不存在返回0
	if (printWord(word, count)) 
	{
		
		//输入新的单词
		printf("请输入你单词修改后的形式:\n");
		char newword[100]={0};
		getchar();


		for (int i = 0; i <= 99; i++)
		{
			scanf_s("%c", &newword[i]);
			if (newword[i] == '\n')
				break;
		}


		if (judgeInput(newword))//如果输入单词格式正确
			//修改单词
			modifyWord(newword, count);
		else//如果输入单词格式错误
		{
			printf("单词格式错误,修改失败\n请按照：\naboard adv.在船(车)上；上船\n此格式进行修改\n");
			system("pause");
		}

		
	}
	

}




/*

find module


*/


void findWord(char* word)
{

	//开始寻找
	//文件内容读取到buf
	char buf[100] = { 0 };
	//创建文件流对象
	fstream read;
	read.open("英语词汇.txt", ios::in);
	if (wordExit(word) == 0)//单词不存在
	{
		printf("单词不存在\n");
		Sleep(200);
	}
	else//单词存在
	{

		//一行一行读，然后进行比较
		while (read.getline(buf, sizeof(buf)))
		{
			
				//如果发现匹配，则进行打印
				if (compareInputAndBuf(buf, word)==1)
				{
					read.close();
					printf("%s\n", buf);
					break;
				}
			}
		}
}

void WordManagement::find()
{
	int judge = 1;
	while(judge)
	{
		//刷新界面
		system("cls");
		systemmanagement.displayManageInterface();
		//输入要寻找的单词
		printf("请输入你要寻找的单词\n");
		char word[100] = { 0 };
		scanf_s("%s", word, 100);
		//寻找并与用户交互
		findWord(word);
		//判断要继续查询还是要退出
		printf("输入1继续，输入0退出\n");
		cin >> judge;
	}
	printf("正在退出\n");
	Sleep(500);

}
