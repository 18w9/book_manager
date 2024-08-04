#pragma once

#include"record.h"

class Operate {
	Book book;
	Reader reader;
public:

	//添加读者
	void AddReader(string name, int sex, string phone, string password, int bnumber, int identity,int tag,int updateOperator);

	//删除读者
	void DeleteReader(int readerId, int manageId, int tag);

	//更改读者信息
	void UpdateReader(int id, string name, int sex, string phone, int identity);

	//查询读者信息
	//void SearchReader(int id);

	//添加书籍
	void AddBook(string name, string author, int category, string publisher, string publish_date, double price, int number,int tag, int lastOperate);

	//删除书籍
	void DeleteBook(int bookId,int readerId,int tag);

	//更改书籍信息
	void UpdateBook(int id, string name, string author, int category, string publisher, string publish_date, double price, int number);

	//查询书籍信息
	//void SearchBook(int id );

};
