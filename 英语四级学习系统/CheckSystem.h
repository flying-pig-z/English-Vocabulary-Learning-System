#pragma once
class CheckSystem
{
public:
	//抽查单词
	void checkWords();
	//查看上次抽查过的单词抽查记录
	void viewSpotCheck();
	//复习上次抽查过的单词
	void reviewSpotCheck();
	//储存从文件中读取的那一行字符
	char buf[100]={0};
};