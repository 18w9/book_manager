#pragma once

#include <iostream>
#include <codecvt> // codecvt_utf8
#include <locale>  // wstring_conver
#include<string>

//#pragma execution_character_set("utf-8");
//#pragma execution_character_set("utf-8mb3") 

/*bool Book::insert_book(string name, string author, string category, string publisher, string publish_date, double price, int number)
{
	// 设置字符集为utf8
	//string  name_utf8 = StringToUTF8(name0);
	char sql[1024];
	//sprintf_s(sql, "insert into reader(name,gender,phone_number) values('%s','%d','%s')", name_utf8.c_str(), sex0, phone0.c_str());
	sprintf_s(sql, "insert into book(name,author,category,publisher,publish_date,price,number) values('%s','%s','%s','%s','%s','%lf','%d')",
		name.c_str(), author.c_str(), category.c_str(), publisher.c_str(), publish_date.c_str(), price, number);
	cout << sql;
	int ret = mysql_query(con, sql);
	if (ret > 0) {
		fprintf(stderr, "增加操作失败 ret:%d msg：%s\n", ret, mysql_error(con));
		return false;

	}
	return true;
}*/
using namespace std;
/*
* 宽字节转utf8
*/
string wstring_2_utf8(wstring& wide_string);
/*
* uft8转宽字节
*/
wstring wstring_from_utf8(string& bype_string);

string StringToUTF8(string& gbkData);

/*
* 多字节转宽字节
* 本函数会返回new分配的outStr，需要手动调用delete[]释放内存.
*/
void _CA2W(wchar_t** outStr, size_t& outLen, const char* inStr, int inLen);

/*
* 宽字节转多字节
* 本函数会返回new分配的outStr，需要手动调用delete[]释放内存.
*/
void _W2CA(char** outStr, size_t& outLen, const wchar_t* inStr, int inLen);



