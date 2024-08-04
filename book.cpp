#include "book.h"
//增
bool Book::InsertBook(string name, string author, int category, string publisher, string publish_date, double price, int number, int tag, int lastOperate)
{
	string updateTime = GetTime();
	sprintf_s(sql, "insert into book(name,author,category,publisher,publish_date,price,number,tag,lastoperator,updatetime) values('%s','%s','%d','%s','%s','%lf','%d','%d','%d','%s')",
		name.c_str(), author.c_str(), category, publisher.c_str(), publish_date.c_str(), price, number,tag, lastOperate, updateTime.c_str());
	int ret = mysql_query(con, sql);
	if (ret > 0) {
		return false;

	}
	return true;
}

//删--数量
bool Book::DeleteBook(int bookId,int readerId,int tag)
{
	string updateTime = GetTime();
	sprintf_s(sql, "UPDATE book set tag='%d', lastoperator='%d',updatetime='%s' where id='%d'", tag, readerId, updateTime.c_str(),bookId);
	if (mysql_query(con, sql)) {
		return false;

	}
	return true;

}

//改
bool Book::UpdateBook(int no, string name, string author, int category, string publisher, string publish_date, double price, int number)
{
	string updateTime = GetTime();
	sprintf_s(sql, "UPDATE book SET name='%s',author='%s',category='%d',publisher='%s',publish_date='%s',price='%lf',number='%d'""where id='%d'",
		name.c_str(), author.c_str(), category, publisher.c_str(), publish_date.c_str(), price, number, no);
	if (mysql_query(con, sql)) {
		return false;

	}
	return true;

}

//改书名
bool Book::UpdateBookName(int bodkId, string name,int readerId) {
	string updateTime = GetTime();
	sprintf_s(sql, "UPDATE book SET name='%s',lastoperator='%d',updatetime='%s'""where id='%d'",name.c_str(),readerId, updateTime.c_str(),bookId);
	if (mysql_query(con, sql)) {
		return false;

	}
	return true;
}

//改作者
bool Book::UpdateBookAuthor(int bookId, string author,int readerId) {
	string updateTime = GetTime();
	sprintf_s(sql, "UPDATE book SET author='%s',lastoperator='%d',updatetime='%s'""where id='%d'", author.c_str(),readerId,updateTime.c_str(), bookId);
	if (mysql_query(con, sql)) {
		return false;

	}
	return true;
}

//改种类
bool Book::UpdateBookCategory(int bookId, int category,int readerId) {
	string updateTime = GetTime();
	sprintf_s(sql, "UPDATE book SET category='%d',lastoperator='%d',updatetime='%s'""where id='%d'", category,readerId,updateTime.c_str(), bookId);
	if (mysql_query(con, sql)) {
		return false;

	}
	return true;
}

//出版社
bool Book::UpdateBookPublisher(int bookId, string publisher,int readerId) {
	string updateTime = GetTime();
	sprintf_s(sql, "UPDATE book SET publisher='%s',lastoperator='%d',updatetime='%s'""where id='%d'", publisher.c_str(),readerId,updateTime.c_str(), bookId);
	if (mysql_query(con, sql)) {
		return false;

	}
	return true;
}

//改出版时间
bool Book::UpdateBookPublishDate(int bookId, string publish_date,int readerId) {
	string updateTime = GetTime();
	sprintf_s(sql, "UPDATE book SET publish_date='%s',lastoperator='%d',updatetime='%s'""where id='%d'", publish_date.c_str(),readerId,updateTime.c_str(), bookId);
	if (mysql_query(con, sql)) {
		return false;

	}
	return true;
}

//改价格
bool Book::UpdateBookPrice(int bookId, int price,int readerId) {
	string updateTime = GetTime();
	sprintf_s(sql, "UPDATE book SET price='%d',lastoperator='%d',updatetime='%s'""where id='%d'", price,readerId,updateTime.c_str(), bookId);
	if (mysql_query(con, sql)) {
		return false;

	}
	return true;
}

//改存储量
bool Book::UpdateBookNumber(int bookId, int number,int readerId) {
	string updateTime = GetTime();
	sprintf_s(sql, "UPDATE book SET number='%d',lastoperator='%d',updatetime='%s'""where id='%d'", number,readerId,updateTime.c_str(), bookId);
	if (mysql_query(con, sql)) {
		return false;

	}
	return true;
}



//根据id判断书籍是否存在
int Book::determineId(int id) {
	sprintf_s(sql, "SELECT * FROM book where id='%d' and tag='1'", id);
	mysql_query(con, sql);
	res = mysql_store_result(con);
	int num_rows = mysql_num_rows(res);
	return num_rows;
}

//根据书名判断书籍是否存在
int Book::determineName(string name) {
	sprintf_s(sql, "SELECT * FROM book where name='%s' and tag='1'", name.c_str());
	mysql_query(con, sql);
	res = mysql_store_result(con);
	int num_rows = mysql_num_rows(res);
	return num_rows;
}


//根据作者判断书籍是否存在
int Book::determineAuthor(string author) {
	sprintf_s(sql, "SELECT * FROM book where author='%s' and tag='1'", author.c_str());
	mysql_query(con, sql);
	res = mysql_store_result(con);
	int num_rows = mysql_num_rows(res);
	return num_rows;
}

//获取数据量
int Book::DataNumber() {
	sprintf_s(sql, "select * from book  where tag='1' ");
	mysql_query(con, sql);
	res = mysql_store_result(con);
	int num_rows = mysql_num_rows(res);
	return num_rows;

}

//获取数据量
int Book::DataNumberByName(string name) {
	sprintf_s(sql, "select * from book  where tag='1'and name='%s' ",name.c_str());
	mysql_query(con, sql);
	res = mysql_store_result(con);
	int num_rows = mysql_num_rows(res);
	return num_rows;

}

//获取数据量
int Book::DataNumberByAuthor(string author) {
	sprintf_s(sql, "select * from book  where tag='1' and author='%s'",author.c_str());
	mysql_query(con, sql);
	res = mysql_store_result(con);
	int num_rows = mysql_num_rows(res);
	return num_rows;

}

//获取数据量
int Book::DataNumberById(int bookId) {
	sprintf_s(sql, "select * from book  where tag='1' and id='%d'",bookId);
	mysql_query(con, sql);
	res = mysql_store_result(con);
	int num_rows = mysql_num_rows(res);
	return num_rows;

}

//根据编号查
vector<Book> BorrowBookById(int bookId) {
	vector<Book> books;
	sprintf_s(sql, "select * from book  where tag='1' and id='%d' ", bookId);
	mysql_query(con, sql);
	res = mysql_store_result(con);
	while ((row = mysql_fetch_row(res))) {
		Book b;
		b.SetId(atoi(row[0]));
		b.SetName(row[1]);
		b.SetAuthor(row[2]);
		b.SetCategory(atoi(row[3]));
		b.SetPublisher(row[4]);
		b.SetPublishDate(row[5]);
		b.SetPrice(atoi(row[6]));
		b.SetNumber(atoi(row[7]));
		b.SetTag(atoi(row[8]));
		books.push_back(b);

	}
	return books;

}

//根据编号查
vector<Book> GetBookById(int bookId, int page, int pageSize) {
	int pageoffset = (page - 1) * pageSize;
	vector<Book> books;
	sprintf_s(sql, "select * from book  where tag='1' and id='%d' order by id desc limit %d ,%d ", bookId, pageoffset, pageSize);
	mysql_query(con, sql);
	res = mysql_store_result(con);
	while ((row = mysql_fetch_row(res))) {
		Book b;
		b.SetId(atoi(row[0]));
		b.SetName(row[1]);
		b.SetAuthor(row[2]);
		b.SetCategory(atoi(row[3]));
		b.SetPublisher(row[4]);
		b.SetPublishDate(row[5]);
		b.SetPrice(atoi(row[6]));
		b.SetNumber(atoi(row[7]));
		b.SetTag(atoi(row[8]));
		books.push_back(b);

	}
	return books;

}

//根据书名查
vector<Book> GetBookByName(string name, int page, int pageSize) {
	int pageoffset = (page - 1) * pageSize;
	vector<Book> books;
	sprintf_s(sql, "select * from book  where tag='1' and name like '%s' order by id desc limit %d ,%d ", (name+"%").c_str(), pageoffset, pageSize);
	mysql_query(con, sql);
	res = mysql_store_result(con);
	while ((row = mysql_fetch_row(res))) {
		Book b;

		b.SetId(atoi(row[0]));
		b.SetName(row[1]);
		b.SetAuthor(row[2]);
		b.SetCategory(atoi(row[3]));
		b.SetPublisher(row[4]);
		b.SetPublishDate(row[5]);
		b.SetPrice(atoi(row[6]));
		b.SetNumber(atoi(row[7]));
		b.SetTag(atoi(row[8]));
		books.push_back(b);

	}
	return books;

}

//根据作者查
vector<Book> GetBookByAuthor(string author,int page, int pageSize) {
	int pageoffset = (page - 1) * pageSize;
	sprintf_s(sql, "select * from book  where tag='1' and author='%s' order by id desc limit %d ,%d ", author.c_str(),pageoffset, pageSize);

	mysql_query(con, sql);
	res = mysql_store_result(con);
	vector<Book> books;
	while ((row = mysql_fetch_row(res))) {
		Book b;
		b.SetId(atoi(row[0]));
		b.SetName(row[1]);
		b.SetAuthor(row[2]);
		b.SetCategory(atoi(row[3]));
		b.SetPublisher(row[4]);
		b.SetPublishDate(row[5]);
		b.SetPrice(atoi(row[6]));
		b.SetNumber(atoi(row[7]));
		b.SetTag(atoi(row[8]));
		books.push_back(b);
	}
	return books;
}

//查看所有信息
vector<Book> GetAllBook(int page,int pageSize) {
	int pageoffset = (page-1) * pageSize;
	vector<Book> books;
	sprintf_s(sql, "select * from book  where tag='1' order by id desc limit %d ,%d ",pageoffset,pageSize);
	mysql_query(con, sql);
	res = mysql_store_result(con);
	while ((row = mysql_fetch_row(res))) {
		Book b;
		b.SetId(atoi(row[0]));
		b.SetName(row[1]);
		b.SetAuthor(row[2]);
		b.SetCategory(atoi(row[3]));
		b.SetPublisher(row[4]);
		b.SetPublishDate(row[5]);
		b.SetPrice(atoi(row[6]));
		b.SetNumber(atoi(row[7]));
		b.SetTag(atoi(row[8]));
		
		books.push_back(b);
	}
	return books;
}

//获取时间
string GetTime() {
	SYSTEMTIME ct;
	GetLocalTime(&ct);//local time
	string strA = to_string(ct.wYear);
	string strB = to_string(ct.wMonth);
	string strC = to_string(ct.wDay);
	string strD = to_string(ct.wHour);
	string strE = to_string(ct.wMinute);
	string strF = to_string(ct.wSecond);
	string result = strA + "/" + strB + "/" + strC + " " + strD + ":" + strE + ":" + strF;
	return result;
}