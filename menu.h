#pragma once

#include<iostream>
#include<iomanip>
#include<cstring>

#include"operate.h"

using namespace std;

//��ʼ����
void InitialMenu();

//���߽���
void ReaderMenu(int readerId);
 
//������Ա����
void PrimaryManagerMenu(int id);

//������Ա����
void ViceManagerMenu(int id);

//�����鼮����
void ManageBookMenu(int identity,int id,int manageIdentity);

//������߽���
void ManageReaderMenu(int identity,int id, int manageIdentity);

//������Ա��������Ա����
void ManageViceMenu(int manageId,int manageIdentity);

//�����鼮����
void SearchBook(int readerId);

//�鿴�鼮
void ViewBook(int id, int identity);

//����id�鿴�鼮
void ViewBookById(int bookId,int readerId);

//�������߲鿴�鼮����
void ViewBookByAuthor(string author, int readerId);

//���������鿴�鼮����
void ViewBookByName(string name, int readerId);

//���һҳ�鼮����
void OutputBook(int page, int pageSize);

//����id���һҳ�鼮����
void OutputBookById(int page, int pageSize, int bookId);

//�����������һҳ�鼮����
void OutputBookByAuthor(int page, int pageSize, string author);

//�����������һҳ�鼮����
void OutputBookByName(int page, int pageSize, string name);

//���һҳ��������
void OutputReader(int page, int pageSize, int identity);

//���һҳ�����¼
void OutputBorrowing(int page, int pageSize);

//�鿴�����¼����
void ViewBorrowingRecord(int identity, int manageId);

//���ݲ鿴�����¼����
void ViewBorrowingRecordById(int identity, int manageId, int readerId);

//�鿴���߽���
void ViewReader(int identity, int namegeId, int manageIdentity);

//�鿴�����¼����
void ViewReader(int identity, int manageId, int manageIdentity);
