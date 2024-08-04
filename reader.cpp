#include"Reader.h"
//��
bool Reader::InsertReader(string name, int sex, string phone, string password, int bnumber, int identity,int tag,int lastOperate)
{
	// �����ַ���Ϊutf8
	string updateTime = GetTime();
	sprintf_s(sql, "insert into reader(name,gender,phone_number,password,bnumber,identity,tag,lastoperator,updatetime) values('%s','%d','%s','%s','%d','%d','%d','%d','%s')",
		name.c_str(), sex, phone.c_str(), password.c_str(), bnumber, identity, tag, lastOperate, updateTime.c_str());
	int ret = mysql_query(con, sql);
	if (ret > 0) {
		fprintf(stderr, "���Ӳ���ʧ�� ret:%d msg��%s\n", ret, mysql_error(con));
		return false;
	}
	cout << "���ӳɹ�" << endl;
	return true;
}

//ɾ
bool Reader::DeleteReader(int readerId,int manageId,int tag)
{
	string updateTime = GetTime();
	sprintf_s(sql, "UPDATE reader set tag='%d',lastoperator='%d',updatetime='%s'"" where id='%d'", tag, manageId,updateTime.c_str(), readerId);
	if (mysql_query(con, sql)) {
		fprintf(stderr, "ɾ������ʧ�ܣ�%s\n", mysql_error(con));
		return false;
	}
	cout << "ɾ���ɹ�" << endl;
	return true;
}

//��
bool Reader::UpdateReader(int id, string name, int sex, string phone, int identity)
{
	sprintf_s(sql, "UPDATE reader SET name='%s',gender='%d',phone_number='%s', identity='%d'""where id='%d'", name.c_str(), sex, phone.c_str(),identity,id);
	if (mysql_query(con, sql)) {
		fprintf(stderr, "���²���ʧ�ܣ�%s\n", mysql_error(con));
		return false;
	}
	return true;
}

//������
bool Reader::UpdateReaderName(int readerId, string name,int manageId) {
	string updateTime = GetTime();
	sprintf_s(sql, "UPDATE reader SET name='%s',lastoperator='%d',updatetime='%s'""where id='%d'", name.c_str(), manageId,updateTime.c_str(), readerId);
	if (mysql_query(con, sql)) {
		fprintf(stderr, "���²���ʧ�ܣ�%s\n", mysql_error(con));
		return false;
	}
	return true;
}

//���Ա�
bool Reader::UpdateReaderSex(int readerId, int sex, int manageId) {
	string updateTime = GetTime();
	sprintf_s(sql, "UPDATE reader SET gender='%d',lastoperator='%d',updatetime='%s'""where id='%d'", sex, manageId, updateTime.c_str(), readerId);
	if (mysql_query(con, sql)) {
		fprintf(stderr, "���²���ʧ�ܣ�%s\n", mysql_error(con));
		return false;
	}
	return true;
}

//�ĵ绰
bool Reader::UpdateReaderPhone(int id, string phone, int manageId) {
	string updateTime = GetTime();
	sprintf_s(sql, "UPDATE reader SET phone_number='%s',lastoperator='%d',updatetime='%s'""where id='%d'", phone.c_str(), manageId,updateTime.c_str(), id);
	if (mysql_query(con, sql)) {
		fprintf(stderr, "���²���ʧ�ܣ�%s\n", mysql_error(con));
		return false;
	}
	return true;
}


//���ݵ绰���ж��˺�
int Reader::determineByPhone(string phone) {
	sprintf_s(sql, "SELECT * FROM reader where phone_number='%s' ", phone.c_str());
	mysql_query(con, sql);
	res = mysql_store_result(con);
	int num_rows = mysql_num_rows(res);
	return num_rows;
}

//����id�ж��˺�
int Reader::determineById(int id) {
	sprintf_s(sql, "SELECT * FROM reader where id='%d' ", id);
	mysql_query(con, sql);
	res = mysql_store_result(con);
	int num_rows = mysql_num_rows(res);
	return num_rows;
}


//������
bool Reader::UpdetaPassword(int readerId,string password)
{
	sprintf_s(sql, "UPDATE reader SET password='%s'""where id='%d'", password.c_str(), readerId);
	if (mysql_query(con, sql)) {
		return false;
	}
	return true;
}

//��ȡ����id
int Reader::GetreaderId(string phone) {
	sprintf_s(sql, "SELECT * FROM reader where phone_number ='%s'", phone.c_str());
	mysql_query(con, sql);
	res = mysql_store_result(con);
	int num_rows = mysql_num_rows(res);
	int readerId = 1;
	while ((row = mysql_fetch_row(res))) {
		readerId = atoi(row[0]);
	}
	return readerId;
}

//��ȡ�������
int Reader::GetReaderIdentity(string phone) {
	sprintf_s(sql, "SELECT * FROM reader where phone_number ='%s'", phone.c_str());
	mysql_query(con, sql);
	res = mysql_store_result(con);
	int num_rows = mysql_num_rows(res);
	int identity = 1;
	while ((row = mysql_fetch_row(res))) {
		identity = atoi(row[6]);
	}
	return identity;
}

//��֤����
int Reader::VerifyPassword(string phone,string password) {
	sprintf_s(sql, "SELECT * FROM reader where phone_number='%s' and password='%s' ", phone.c_str(), password.c_str());
	mysql_query(con, sql);
	res = mysql_store_result(con);
	int numrows = mysql_num_rows(res);
	return numrows;
}

//�鿴���ж���
vector<Reader> GetAllReader(int page,int pageSize, int identity) {
	int pageoffset = (page - 1) * pageSize;
	vector<Reader> readers;
	sprintf_s(sql, "select * from reader  where tag='1' and identity='%d'order by id desc limit %d ,%d ", identity,pageoffset, pageSize);
	mysql_query(con, sql);
	res = mysql_store_result(con);
	while ((row = mysql_fetch_row(res))) {
		Reader r;
		r.SetId(atoi(row[0]));
		r.SetName(row[1]);
		r.SetSex(atoi(row[2]));
		r.SetPhone(row[3]);
		r.SetPassword(row[4]);
		r.SetNumber(atoi(row[5]));
		r.SetIdentity(atoi(row[6]));
		r.SetTag(atoi(row[7]));
		r.SetLastOperator(atoi(row[8]));
		r.SetUpdateTime(row[9]);

		readers.push_back(r);

		//cout << setw(5) << r.GetId() << setw(10) << r.GetName() << setw(8) << r.GetSex() << setw(20) << r.GetPhone() << setw(10) << r.GetNumber() << setw(5) << r.GetIdentity() << endl;
	}
	return readers;
}


//��ȡ������
int Reader::DataNumber(int identity) {
	sprintf_s(sql, "select * from reader  where tag='1' and identity='%d' ",identity);
	mysql_query(con, sql);
	res = mysql_store_result(con);
	int num_rows = mysql_num_rows(res);
	return num_rows;

}
//�鿴������Ա
void Reader::GetViceManager() {
	sprintf_s(sql, "select * from borrowingrecords");
	mysql_query(con, sql);
	res = mysql_store_result(con);
	while ((row = mysql_fetch_row(res))) {
		int borrowingid = atoi(row[0]);
		int readerid = atoi(row[1]);
		int bookid = atoi(row[2]);
		int quantity = atoi(row[3]);
		int bookStorage = atoi(row[4]);
		cout << setw(5) << borrowingid << setw(10) << readerid << setw(10) << bookid << setw(10) << quantity << setw(10) << bookStorage << endl;
	}
}

//��
vector<Reader> GetReaderById(int id)
{
	vector<Reader> readers;
	sprintf_s(sql, "SELECT * FROM reader where id ='%d'", id);
	mysql_query(con, sql);
	res = mysql_store_result(con);
	int num_rows = mysql_num_rows(res);
	if (num_rows <= 0)return readers;
	while ((row = mysql_fetch_row(res))) {
		Reader* r = new Reader;
		r->SetId(atoi(row[0]));
		r->SetName(row[1]);
		r->SetSex(atoi(row[2]));
		r->SetPhone(row[3]);
		r->SetPassword(row[4]);
		r->SetNumber(atoi(row[5]));
		r->SetIdentity(atoi(row[6]));
		readers.push_back(*r);
	}
	return readers;
}