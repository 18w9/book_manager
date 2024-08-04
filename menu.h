#pragma once

#include<iostream>
#include<iomanip>
#include<cstring>

#include"operate.h"

using namespace std;

//初始界面
void InitialMenu();

//读者界面
void ReaderMenu(int readerId);
 
//主管理员界面
void PrimaryManagerMenu(int id);

//副管理员界面
void ViceManagerMenu(int id);

//管理书籍界面
void ManageBookMenu(int identity,int id,int manageIdentity);

//管理读者界面
void ManageReaderMenu(int identity,int id, int manageIdentity);

//主管理员管理副管理员界面
void ManageViceMenu(int manageId,int manageIdentity);

//搜索书籍界面
void SearchBook(int readerId);

//查看书籍
void ViewBook(int id, int identity);

//根据id查看书籍
void ViewBookById(int bookId,int readerId);

//根据作者查看书籍界面
void ViewBookByAuthor(string author, int readerId);

//根据书名查看书籍界面
void ViewBookByName(string name, int readerId);

//输出一页书籍数据
void OutputBook(int page, int pageSize);

//根据id输出一页书籍数据
void OutputBookById(int page, int pageSize, int bookId);

//根据作者输出一页书籍数据
void OutputBookByAuthor(int page, int pageSize, string author);

//根据书名输出一页书籍数据
void OutputBookByName(int page, int pageSize, string name);

//输出一页读者数据
void OutputReader(int page, int pageSize, int identity);

//输出一页借书记录
void OutputBorrowing(int page, int pageSize);

//查看借书记录界面
void ViewBorrowingRecord(int identity, int manageId);

//根据查看借书记录界面
void ViewBorrowingRecordById(int identity, int manageId, int readerId);

//查看读者界面
void ViewReader(int identity, int namegeId, int manageIdentity);

//查看借书记录界面
void ViewReader(int identity, int manageId, int manageIdentity);
