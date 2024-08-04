#pragma once

#include"reader.h"


class Record
{
private:
	int borrowingId;
	int readerId;
	int bookId;
	int quantity;
	int bookStorage;
	string name;
	Book B;
	Reader R;
public:

	//����
	int BorrowBook(int id, int no);

	//����
	int BackBook(int id, int no);

	//
	void SetBorrowingId(int borrowingId) {
		this->borrowingId = borrowingId;
	}

	void SetReaderId(int readerId) {
		this->readerId = readerId;
	}

	void SetBookId(int bookId) {
		this->bookId = bookId;
	}

	void SetQuantity(int quantity) {
		this->quantity = quantity;
	}

	void SetBookStorage(int bookStorage) {
		this->bookStorage = bookStorage;
	}
	void SetName(string name) {
		this->name = name;
	}

	int GetBorrowingId() {
		return borrowingId;
	}

	int GetReaderId() {
		return readerId;
	}

	int GetBookId() {
		return bookId;
	}

	int GetQuantity() {
		return quantity;
	}

	int GetBookStorage() {
		return bookStorage;
	}

	string GetName() {
		return name;
	}

	//��ȡ������
	int DataNumber();

	//��ȡ������id
	int DataNumberById(int readerId);
};

//�鿴�����¼
vector<Record> GetBorrowingById(int page, int pageSize, int readerId);

//�鿴���н����¼
vector<Record> GetAllBorrowing(int page, int pageSize);