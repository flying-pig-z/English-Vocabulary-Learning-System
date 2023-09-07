#include<iostream>
#include<fstream>
#include"systemManagement.h"
using namespace std;
int countW()
{
	fstream wordTxt;
	wordTxt.open("英语词汇.txt", ios::in);
	char buf[100];
	//行数,每读取一行行数加一
	int count = 0;
	while (wordTxt.getline(buf, sizeof(buf))) {
		if ((buf[0] >= 97 && buf[0] <= 122) || (buf[0] >= 65 && buf[0] <= 90))
			count++;
	}
	return count;
}
//display interface
void systemManagement::displayInterface() {
	cout << "-------------------------------------------" << endl;
	cout << "          四级词汇管理与抽查系统              "<<endl;
	cout << "                 0.退出系统                 " << endl;
	cout << "               1.词汇管理系统                 "<<endl;
	cout << "               2.词汇抽查系统                 "<<endl;
	cout << "-------------------------------------------" << endl;
	cout << "ps:总的词汇有" << countW() << "个" << endl;
};
void systemManagement::displayManageInterface() {
	cout << "-------------------------------------------" << endl;
	cout << "              0.返回上级目录                 " << endl;
	cout << "                1.添加单词                 " << endl;
	cout << "                2.删除单词                 " << endl;
	cout << "                3.修改单词                 " << endl;
	cout << "                4.查询单词                 " << endl;
	cout << "-------------------------------------------" << endl;
}
void systemManagement::displayCheckInterface() {
	cout << "-------------------------------------------" << endl;
	cout << "              0.返回上级目录                 " << endl;
	cout << "              1.抽查新的单词                 " << endl;
	cout << "              2.查看上次抽查                 " << endl;
	cout << "              3.复习上次抽查                 " << endl;
	cout << "-------------------------------------------" << endl;
}