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
	int bookId;//���
	string name;//����
	string author;//������
	int category;//����
	string publisher;//������
	string publish_date;//����ʱ��
	double price;//�۸�
	int number;//�������
	int tag;//����״̬
public:
	/*Book(int no=1,string name="������", string category="����", string author="β����һ��", string publisher = "��Ӣ��", string publish_date = "1997-12-24", double price=199, int number=10) {
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
		return name;//��ȡ����
	}

	string GetAuthor() {
		return author;//��ȡ������
	}

	int GetCategory() {
		return category;//��ȡͼ�����
	}

	string GetPublisher() {
		return publisher;//��ȡ����������
	}

	string GetPublishDate() {
		return publish_date;//��ȡ����ʱ��
	}

	double GetPrice() {
		return price;
	}
	int GetId() {
		return bookId;//��ȡ���
	}
	int GetNumber() {
		return number;
	}
	int GetTag() {
		return tag;
	}

	void SetId(int no) {
		this->bookId = no;//��ȡ���
	}

	void SetName(string name) {
		this->name = name;//��������
	}

	void SetAuthor(string author) {
		this->author = author;//����������
	}

	void SetCategory(int category) {
		this->category = category;//����������
	}

	void SetPublisher(string publisher) {
		this->publisher = publisher;//���ó�������
	}

	void SetPublishDate(string publish_date) {
		this->publish_date = publish_date;//���ó���ʱ��
	}

	void SetPrice(int price) {
		this->price = price;//������Ǽ۸�
	}

	void SetNumber(int number) {
		this->number = number;
	}
	void SetTag(int tag) {
		this->tag = tag;
	}

	//¼���鼮
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

	//��
	bool InsertBook(string name, string author, int category, string publisher, string publish_date, double price, int number, int tag, int lastOperate);

	//ɾ--����
	bool DeleteBook(int bookId, int readerId, int tag);

	//��
	bool UpdateBook(int no, string name, string author, int category, string publisher, string publish_date, double price, int number);

	//������
	bool UpdateBookName(int bodkId, string name, int readerId);

	//������
	bool UpdateBookAuthor(int bookId, string author, int readerId);

	//������
	bool UpdateBookCategory(int bookId, int category,int readerId);

	//������
	bool UpdateBookPublisher(int bookId, string publisher,int readerId);

	//�ĳ���ʱ��
	bool UpdateBookPublishDate(int bookId, string publish_date,int readerId);

	//�ļ۸�
	bool UpdateBookPrice(int bookId, int price,int readerId);

	//�Ĵ洢��
	bool UpdateBookNumber(int bookId, int number,int readrId);

	//����id�ж��鼮�Ƿ����
	int determineId(int id);


	//���������ж��鼮�Ƿ����
	int determineName(string name);

	//���������ж��鼮�Ƿ����
	int determineAuthor(string author);

	//��ȡ������
	int DataNumber();

	//��ȡ������
	int DataNumberByName(string name);

	//��ȡ������
	int DataNumberByAuthor(string author);

	//��ȡ������
	int DataNumberById(int bookId);
};
//���ݱ�Ų�
vector<Book> BorrowBookById(int bookId);

//���ݱ�Ų�
vector<Book> GetBookById(int bookId, int page, int pageSize);

//����������
vector<Book> GetBookByName(string name, int page, int pageSize);

//�������߲�
vector<Book> GetBookByAuthor(string author,int page, int pageSize);

//�鿴������Ϣ
vector<Book> GetAllBook(int page,int pageSize);

//��ȡʱ��
string GetTime();
