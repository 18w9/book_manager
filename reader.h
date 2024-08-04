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
	int readerId;//�û�id
	string name;//����
	int sex;//�Ա�
	string phone;//�绰����
	int number;//������
	string password;//����
	int identity;//���
	int tag;
	int lastOperator;
	string  updateTime;
public:
	void SetId(int id) { this->readerId = id; }            //���ܺ��� ������Ϣ
	void SetName(string name) { this->name = name; }
	void SetSex(int sex) { this->sex = sex; }
	void SetPhone(string phone) { this->phone = phone; }
	void SetNumber(int number) { this->number = number; }
	void SetPassword(string password) { this->password = password; }
	void SetIdentity(int identity) { this->identity = identity; }
	void SetTag(int tag) { this->tag = tag; }
	void SetLastOperator(int lastOperator) { this->lastOperator = lastOperator; }
	void SetUpdateTime(string updateTime) { this->updateTime = updateTime; }
	int GetId() {//���ܺ���   ��ȡ��Ϣ
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
	////����mysql
	//Reader(int id=1,string name="����", int sex=1, string phone="123456789", int number=0) {
	//	this->readerId = id;
	//	this->name = name;
	//	this->sex = sex;
	//	this->phone = phone;
	//	this->number = number;
	//}

	~Reader() {
	}

	//����
	int borrowbook(){
	}

	//��
	bool InsertReader(string name, int sex, string phone, string password, int bnumber, int identity, int tag, int lastOperate);

	//ɾ
	bool DeleteReader(int readerId, int manageId, int tag);

	//��
	bool UpdateReader(int id, string name, int sex, string phone, int identity);
	
	//������
	bool UpdateReaderName(int readerId, string name, int manageId);

	//���Ա�
	bool UpdateReaderSex(int readerId, int sex, int manageId);

	//�ĵ绰
	bool UpdateReaderPhone(int readerId, string phone, int manageId);

	//�ж��˺�
	int determineByPhone(string phone);

	//�ж��˺�
	int determineById(int id);

	//������
	bool UpdetaPassword(int id, string password);

	//��ȡ����id
	int GetreaderId(string phone);

	//��ȡ�������
	int GetReaderIdentity(string phone);

	//��֤����
	int VerifyPassword(string phone, string password);

	//�鿴������Ա
	void GetViceManager();

	//��ȡ����������
	int DataNumber(int identity);

};
//��
vector<Reader> GetReaderById(int id);

//�鿴���ж���
vector<Reader> GetAllReader(int page, int pageSize, int identity);