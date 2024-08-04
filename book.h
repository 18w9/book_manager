#pragma once
#include<iostream>
#include<cstring>
#include<iomanip>
#include<mysql.h>
#include<vector>
#include<string>
#include"Windows.h"
using namespace std;

extern MYSQL* con;
extern char sql[1024];
extern MYSQL_RES* res;
extern MYSQL_ROW row;


class Book {
private:
	int bookId;//编号
	string name;//书名
	string author;//作者名
	int category;//分类
	string publisher;//出版社
	string publish_date;//出版时间
	double price;//价格
	int number;//书的数量
	int tag;//存在状态
public:
	/*Book(int no=1,string name="海贼王", string category="动漫", string author="尾田荣一郎", string publisher = "集英社", string publish_date = "1997-12-24", double price=199, int number=10) {
		this->bookId = no;
		this->name = name;
		this->author = author;
		this->category = category;
		this->publisher = publisher;
		this->publish_date = publish_date;
		this->price = price;
		this->number = number;
	};*/

	string GetName() {
		return name;//获取书名
	}

	string GetAuthor() {
		return author;//获取作者名
	}

	int GetCategory() {
		return category;//获取图书分类
	}

	string GetPublisher() {
		return publisher;//获取出版社名字
	}

	string GetPublishDate() {
		return publish_date;//获取出版时间
	}

	double GetPrice() {
		return price;
	}
	int GetId() {
		return bookId;//获取编号
	}
	int GetNumber() {
		return number;
	}
	int GetTag() {
		return tag;
	}

	void SetId(int no) {
		this->bookId = no;//获取编号
	}

	void SetName(string name) {
		this->name = name;//设置书名
	}

	void SetAuthor(string author) {
		this->author = author;//设置作者名
	}

	void SetCategory(int category) {
		this->category = category;//设置种类名
	}

	void SetPublisher(string publisher) {
		this->publisher = publisher;//设置出版社名
	}

	void SetPublishDate(string publish_date) {
		this->publish_date = publish_date;//设置出版时间
	}

	void SetPrice(int price) {
		this->price = price;//设置书记价格
	}

	void SetNumber(int number) {
		this->number = number;
	}
	void SetTag(int tag) {
		this->tag = tag;
	}

	//录入书籍
	void addbook(int no, string name, string author, int category, string publisher, string publish_date, double price)
	{
		this->bookId = no;
		this->name = name;
		this->author = author;
		this->category = category;
		this->publisher = publisher;
		this->publish_date = publish_date;
		this->price = price;
	}

	//增
	bool InsertBook(string name, string author, int category, string publisher, string publish_date, double price, int number, int tag, int lastOperate);

	//删--数量
	bool DeleteBook(int bookId, int readerId, int tag);

	//改
	bool UpdateBook(int no, string name, string author, int category, string publisher, string publish_date, double price, int number);

	//改书名
	bool UpdateBookName(int bodkId, string name, int readerId);

	//改作者
	bool UpdateBookAuthor(int bookId, string author, int readerId);

	//改种类
	bool UpdateBookCategory(int bookId, int category,int readerId);

	//出版社
	bool UpdateBookPublisher(int bookId, string publisher,int readerId);

	//改出版时间
	bool UpdateBookPublishDate(int bookId, string publish_date,int readerId);

	//改价格
	bool UpdateBookPrice(int bookId, int price,int readerId);

	//改存储量
	bool UpdateBookNumber(int bookId, int number,int readrId);

	//根据id判断书籍是否存在
	int determineId(int id);


	//根据书名判断书籍是否存在
	int determineName(string name);

	//根据作者判断书籍是否存在
	int determineAuthor(string author);

	//获取数据量
	int DataNumber();

	//获取数据量
	int DataNumberByName(string name);

	//获取数据量
	int DataNumberByAuthor(string author);

	//获取数据量
	int DataNumberById(int bookId);
};
//根据编号查
vector<Book> BorrowBookById(int bookId);

//根据编号查
vector<Book> GetBookById(int bookId, int page, int pageSize);

//根据书名查
vector<Book> GetBookByName(string name, int page, int pageSize);

//根据作者查
vector<Book> GetBookByAuthor(string author,int page, int pageSize);

//查看所有信息
vector<Book> GetAllBook(int page,int pageSize);

//获取时间
string GetTime();
