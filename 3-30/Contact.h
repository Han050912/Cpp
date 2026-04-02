#pragma once
#define NAME_MAX 100
#define SEX_MAX 4
#define TEL_MAX 11
#define ADDR_MAX 100
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

typedef struct SeqList Contact;

typedef struct PersonInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}PeoIfo;

//初始化通讯录
void InitContact(Contact* con);

//添加通讯录数据
void AddContact(Contact* con);

//删除通讯录数据
void DelContact(Contact* con);

//展⽰通讯录数据
void ShowContact(Contact* con);

//查找通讯录数据
void FindContact(Contact* con);

//修改通讯录数据
void ModifyContact(Contact* con);

//销毁通讯录数据
void DestroyContact(Contact* con);