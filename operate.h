#pragma once

#include"record.h"

class Operate {
	Book book;
	Reader reader;
public:

	//��Ӷ���
	void AddReader(string name, int sex, string phone, string password, int bnumber, int identity,int tag,int updateOperator);

	//ɾ������
	void DeleteReader(int readerId, int manageId, int tag);

	//���Ķ�����Ϣ
	void UpdateReader(int id, string name, int sex, string phone, int identity);

	//��ѯ������Ϣ
	//void SearchReader(int id);

	//����鼮
	void AddBook(string name, string author, int category, string publisher, string publish_date, double price, int number,int tag, int lastOperate);

	//ɾ���鼮
	void DeleteBook(int bookId,int readerId,int tag);

	//�����鼮��Ϣ
	void UpdateBook(int id, string name, string author, int category, string publisher, string publish_date, double price, int number);

	//��ѯ�鼮��Ϣ
	//void SearchBook(int id );

};
