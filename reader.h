#pragma once
#include<iostream>
using namespace std;
#include<mysql.h>
#include<iomanip>
#include<vector>
#include "str_code.h"
#include"book.h"


class Reader {
private:
	int readerId;//用户id
	string name;//姓名
	int sex;//性别
	string phone;//电话号码
	int number;//借书量
	string password;//密码
	int identity;//身份
	int tag;
	int lastOperator;
	string  updateTime;
public:
	void SetId(int id) { this->readerId = id; }            //功能函数 设置信息
	void SetName(string name) { this->name = name; }
	void SetSex(int sex) { this->sex = sex; }
	void SetPhone(string phone) { this->phone = phone; }
	void SetNumber(int number) { this->number = number; }
	void SetPassword(string password) { this->password = password; }
	void SetIdentity(int identity) { this->identity = identity; }
	void SetTag(int tag) { this->tag = tag; }
	void SetLastOperator(int lastOperator) { this->lastOperator = lastOperator; }
	void SetUpdateTime(string updateTime) { this->updateTime = updateTime; }
	int GetId() {//功能函数   获取信息
		return readerId;
	}
	string GetName() {
		return name;
	}
	int GetSex() {
		return sex;
	}
	string GetPhone() {
		return phone;
	}
	int GetNumber() {
		return number;
	}
	string GetPassword() {
		return password;
	}
	int GetIdentity() {
		return identity;
	}
	int GetTag() {
		return tag;
	}
	int GetLastOperator() {
		return lastOperator;
	}
	string GetUpdateTime() {
		return updateTime;
	}
	////连接mysql
	//Reader(int id=1,string name="张三", int sex=1, string phone="123456789", int number=0) {
	//	this->readerId = id;
	//	this->name = name;
	//	this->sex = sex;
	//	this->phone = phone;
	//	this->number = number;
	//}

	~Reader() {
	}

	//借书
	int borrowbook(){
	}

	//增
	bool InsertReader(string name, int sex, string phone, string password, int bnumber, int identity, int tag, int lastOperate);

	//删
	bool DeleteReader(int readerId, int manageId, int tag);

	//改
	bool UpdateReader(int id, string name, int sex, string phone, int identity);
	
	//改姓名
	bool UpdateReaderName(int readerId, string name, int manageId);

	//改性别
	bool UpdateReaderSex(int readerId, int sex, int manageId);

	//改电话
	bool UpdateReaderPhone(int readerId, string phone, int manageId);

	//判断账号
	int determineByPhone(string phone);

	//判断账号
	int determineById(int id);

	//改密码
	bool UpdetaPassword(int id, string password);

	//获取读者id
	int GetreaderId(string phone);

	//获取读者身份
	int GetReaderIdentity(string phone);

	//验证密码
	int VerifyPassword(string phone, string password);

	//查看副管理员
	void GetViceManager();

	//获取读者数据量
	int DataNumber(int identity);

};
//查
vector<Reader> GetReaderById(int id);

//查看所有读者
vector<Reader> GetAllReader(int page, int pageSize, int identity);