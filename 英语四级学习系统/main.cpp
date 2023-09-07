#include<iostream>
#include"systemManagement.h"
#include"wordManagement.h"
#include"CheckSystem.h"
using namespace std;
//bug:当随便输入很长的奇怪数字，程序会发生死循环，缓冲区问题
void manage() {
	systemManagement systemmanagement;
	WordManagement wordmanagement;
	
	for (;;)
	{
		system("cls");
		systemmanagement.displayManageInterface();
		int judge1=0;
		cin >> judge1;
		switch (judge1)
		{
		case 0:
			break;
			//按1进行单词添加
		case 1:
			wordmanagement.add();
			break;
			//按2进行单词删除
		case 2:
			wordmanagement.deleteW();
			break;
			//按3进行单词修改
		case 3:
			wordmanagement.modify();
			break;
			//按4进行单词查询
		case 4:
			wordmanagement.find();
			break;
		default:
			cout << "输错了，请在输入一次\n" << endl;
			system("pause");
			continue;
		}
		if(judge1==0)
			break;
	}
	system("cls");
	systemmanagement.displayInterface();
}
void check() {
	CheckSystem checksystem;
	systemManagement systemmanagement;
	for (;;)
	{
		
		system("cls");
		systemmanagement.displayCheckInterface();
		int judge2;
		cin >> judge2;
		switch (judge2)
		{
		case 0:
			break;
		case 1:
			checksystem.checkWords();
			break;
		case 2:
			checksystem.viewSpotCheck();
			break;
		case 3:
			checksystem.reviewSpotCheck();
			break;
		default:
			cout << "输错了，请在输入一次\n" << endl;
			system("pause");
			continue;
		}
		if (judge2 == 0)
			break;

	}

	system("cls");
	systemmanagement.displayInterface();
}
int main()
{
	int judge = 0;
	systemManagement systemmanagement;
	//显示界面
	systemmanagement.displayInterface();
	for (;;) {
		cin>>judge;
		//各个操作
		switch (judge)
		{
		//按0退出
		case 0:
			break;
		//按1进入管理系统
		case 1:
			manage();
			break;
		//按2进入抽查系统
		case 2:
			check();
			break;
		default:
			cout << "输错了，请再输一次\n" << endl;
			system("pause");
		}
		if (judge == 0)
			break;
	}
}
