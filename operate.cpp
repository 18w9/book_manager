#include"operate.h"


//��Ӷ���
void Operate::AddReader(string name, int sex, string phone, string password, int bnumber, int identity,int tag, int updateOperator) {
	reader.InsertReader(name, sex, phone, password, bnumber, identity,tag, updateOperator);

}

//ɾ������
void Operate::DeleteReader(int readerId,int manageId,int tag) {

	reader.DeleteReader(readerId, manageId, tag);

}

//���Ķ�����Ϣ
void Operate::UpdateReader(int id, string name, int sex, string phone, int identity) {
	reader.UpdateReader(id, name, sex, phone, identity);

}

//����鼮
void Operate::AddBook(string name, string author, int category, string publisher, string publish_date, double price, int number,int tag,int lastOperate) {
	book.InsertBook(name, author, category, publisher, publish_date, price, number, tag, lastOperate);

}

//ɾ���鼮
void Operate::DeleteBook(int no,int id,int tag) {
	book.DeleteBook(no,id,tag);
}

//�����鼮��Ϣ
void Operate::UpdateBook(int no, string name, string author, int category, string publisher, string publish_date, double price, int number) {
	book.UpdateBook(no, name, author, category, publisher, publish_date, price, number);

}
