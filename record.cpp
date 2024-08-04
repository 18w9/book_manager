#include "record.h"
//����
int Record:: BorrowBook(int readerid, int bookid) {//no0:��ѡ���ͼ��
	int number, borrowbook;
	string name;
	vector<Book> books = BorrowBookById(bookid);
	vector<Reader> readers = GetReaderById(readerid);
	if (books.empty()) {
		//cout << "���鲻����" << endl;
		return 1;
	}
	else {
		borrowbook = readers[0].GetNumber();
		number = books[0].GetNumber();
		name = books[0].GetName();
		if (number == 0 && borrowbook == 10) {
			return 2;
		} 
		else if (number == 0 && borrowbook!=10) {
			return 3;
		}
		else if (number != 0 && borrowbook == 10) {
			return 4;
		}
		else if (number > 0 && borrowbook < 10) {
			number -= 1;
			borrowbook += 1;
			sprintf_s(sql, "UPDATE book SET number='%d'""where id='%d'", number, bookid);
			mysql_query(con, sql);
			sprintf_s(sql, "UPDATE reader SET bnumber='%d'""where id='%d'", borrowbook, readerid);
			mysql_query(con, sql);

			sprintf_s(sql, "INSERT INTO borrowingrecords(readerid,bookid,quantity,bookStorage,bookname) values('%d','%d','%d','%d','%s')",
				readerid, bookid, borrowbook, number,name.c_str());
			mysql_query(con, sql);
			//cout << "�����ɹ�";
			return 0;
		}
	}
	return 0;
}

//����
int Record::BackBook(int readerid, int bookid) {
	int number, borrowbook;
	int borrowingid = 0;
	vector<Book> books = BorrowBookById(bookid);
	vector<Reader> readers = GetReaderById(readerid);
	sprintf_s(sql, "SELECT * FROM borrowingrecords where readerid ='%d' and bookid='%d'", readerid,bookid);
	mysql_query(con, sql);
	res = mysql_store_result(con);
	int num_rows = mysql_num_rows(res);
	if (num_rows == 0) {
		//cout << "�ö���δ�������" << endl;
		return 1;
	}
	else if (num_rows > 0) {
		borrowbook = readers[0].GetNumber();
		number = books[0].GetNumber();
		if (number != 10 && borrowbook != 0)  {
			while ((row = mysql_fetch_row(res))) {
				borrowingid = atoi(row[0]);
			}
			number += 1;
			borrowbook -= 1;
			sprintf_s(sql, "UPDATE book SET number='%d'""where id='%d'", number, bookid);
			mysql_query(con, sql);
			sprintf_s(sql, "UPDATE reader SET bnumber='%d'""where id='%d'", borrowbook, readerid);
			mysql_query(con, sql);
			sprintf_s(sql, "delete from  borrowingrecords where readerid='%d' and bookid='%d' and borrowingid= '%d'", readerid, bookid, borrowingid);
			mysql_query(con, sql);
			//cout << "�����ɹ�";
			return 0;
		}
	}
	return 0;
}


//��ȡ������
int Record::DataNumber() {
	sprintf_s(sql, "select * from borrowingrecords ");
	mysql_query(con, sql);
	res = mysql_store_result(con);
	int num_rows = mysql_num_rows(res);
	return num_rows;

}

//��ȡ������id
int Record::DataNumberById(int readerId) {
	sprintf_s(sql, "select * from borrowingrecords where readerid='%d' ",readerId);
	mysql_query(con, sql);
	res = mysql_store_result(con);
	int num_rows = mysql_num_rows(res);
	return num_rows;

}

//�鿴���н����¼
vector<Record> GetAllBorrowing(int page, int pageSize) {
	int pageoffset = (page - 1) * pageSize;
	vector<Record> records;
	sprintf_s(sql, "select * from borrowingrecords  order by borrowingid desc limit %d ,%d ", pageoffset, pageSize);
	mysql_query(con, sql);
	res = mysql_store_result(con);
	while ((row = mysql_fetch_row(res))) {
		Record r;
		r.SetBorrowingId(atoi(row[0]));
		r.SetReaderId(atoi(row[1]));
		r.SetBookId(atoi(row[2]));
		r.SetName(row[5]);

		records.push_back(r);
	}
	return records;
}

//����id�鿴�����¼
vector<Record> GetBorrowingById(int page, int pageSize,int readerId) {
	int pageoffset = (page - 1) * pageSize;
	vector<Record> records;
	sprintf_s(sql, "select * from borrowingrecords where readerid='%d' order by borrowingid desc limit %d ,%d ",readerId, pageoffset, pageSize);
	mysql_query(con, sql);
	res = mysql_store_result(con);
	while ((row = mysql_fetch_row(res))) {
		Record r;
		r.SetBorrowingId(atoi(row[0]));
		r.SetReaderId(atoi(row[1]));
		r.SetBookId(atoi(row[2]));
		r.SetName(row[5]);

		records.push_back(r);
	}
	return records;
}