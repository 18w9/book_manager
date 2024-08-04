#include"menu.h"

Operate operate;
Reader reader;
Book book;
Record record;
//��ʼ����
void InitialMenu() {
	cout << "*********************************" << endl;
	cout << "***           1.��¼           ***" << endl;
	cout << "***           2.ע��           ***" << endl;
	cout << "***           3.�˳�           ***" << endl;
	cout << "*********************************" << endl;
	string account;
	while (cout << "��ѡ��:"&&cin >> account) {
		int n = atoi(account.c_str());
		switch (n) {
		case 1: {
			cout << "�������˺�(�ֻ���):";
			string phone_number;
			cin >> phone_number;//�����˺�
			while (size(phone_number) != 11) {
				cout << endl << "��������˺Ų����Ϲ淶(11λ�ֻ���)�����������˺�:";
				cin >> phone_number;
			}
			int num_rows = reader.determineByPhone(phone_number);
			switch (num_rows)
			{
			case 0: {
				//���߲�����
				system("cls");
				cout << "δ��ѯ���˶���,��ע��" << endl;
				string name, phone, password;
				int sex;
				int number = 0;
				int tag = 1;
				int identity = 1;
				cout << "����:";
				cin >> name;
				cout << endl << "�Ա�(1-�У�2-Ů):";
				cin >> sex;
				cout << endl << "�绰����(11λ):";
				cin >> phone;
				cout << endl << "����:";
				cin >> password;
				int lastOperator = 1;
				if (reader.InsertReader(name, sex, phone, password, identity, number, tag, lastOperator) == false) {
					cout << "���ʧ��";
					continue;
				}
				else {
					int readerId = reader.GetreaderId(phone_number);
					//��ת���߽���
					system("cls");
					InitialMenu();
					break;
					//ReaderMenu(readerId);
				}
			}break;

			case 1: {
				//�û�����
				system("cls");
				cout << endl << "����������:";
				string password;
				cin >> password;
				int num_row = reader.VerifyPassword(phone_number, password);//
				while (num_row <= 0) {
					system("cls");
					cout << endl << "�����������������:";
					cin >> password;
					num_row = reader.VerifyPassword(phone_number, password);
				}
				cout << endl << "��½�ɹ�" << endl;

				//��ȡ��½��id
				int readerId = reader.GetreaderId(phone_number);
				int identity = reader.GetReaderIdentity(phone_number);
				switch (identity)
				{
				case 1: {
					//��ת���߽���
					cout << endl << "�û�Ϊ����" << endl;
					ReaderMenu(readerId);
					break;

				}
				case 2: {
					//��ת������Ա����
					cout << endl << "�û�Ϊ������Ա" << endl;
					ViceManagerMenu(readerId);
					break;

				}
				case 3: {
					//��ת������Ա����
					cout << endl << "�û�Ϊ������Ա" << endl;
					PrimaryManagerMenu(readerId);
					break;

				}
				default:
					break;
				}break;


			}break;

			default:
				break;
			}break;
		}

		case 2: {
			string name, phone, password;
			int sex;
			int identity = 1;
			int number = 0;
			int tag = 1;

			cout << "����:";
			cin >> name;
			cout << endl << "�Ա�(1-�У�2-Ů):";
			cin >> sex;
			cout << endl << "�绰����(11λ):";
			cin >> phone;
			cout << endl << "����:";
			cin >> password;
			if (reader.InsertReader(name, sex, phone, password, number, identity, tag, NULL) == false) {
				cout << "���ʧ��,������ѡ��" << endl;
				continue;
			}
			else {
				int readerId = reader.GetreaderId(phone);

				//��ת���߽���
				ReaderMenu(readerId);
			}
		}break;

		case 3:
			exit(0);

		default:
			cout << "����һ������ѡ��Ļ���:\n" << endl;
			continue;
		}break;
	}
	
	
}

//���߽���
void ReaderMenu(int readerId) {
	system("cls");
	cout << "*********************************" << endl;
	cout << "***        ѡ�����¹���       ***" << endl;
	cout << "***        1.�鿴�鼮��Ϣ     ***" << endl;
	cout << "***        2.�鿴�����¼     ***" << endl;
	cout << "***        3.�����鼮��Ϣ     ***" << endl;//---------------��һ�������鼮
	cout << "***        4.���Ķ�������     ***" << endl;
	cout << "***        5.����             ***" << endl;
	cout << "***        6.����             ***" << endl;
	cout << "***        7.�˳�             ***" << endl;
	cout << "*********************************" << endl;
	Operate operate;
	Record record;
	int identity = 1;
	int n;
	while (cout << "��ѡ��:" && cin >> n) {
		switch (n) {
		case 1: {
			int identity = 1;
			ViewBook(readerId, identity);
			continue;
		}
		case 2: {
			ViewBorrowingRecordById(identity, readerId, readerId);
			continue;
		}

		case 3:
			SearchBook(readerId);
			continue;
		case 4: {
			string password;
			cout << "������������:";
			cin >> password;
			reader.UpdetaPassword(readerId, password);
			if (reader.UpdetaPassword(readerId, password) == false) {
				cout << "����ʧ��" << endl;
				continue;
			}
		}continue;


		case 5: {
			int bookId;
			cout << endl << "�������鼮id:";
			cin >> bookId;
			int n = record.BorrowBook(readerId, bookId);
			if (n == 1) {
				cout << "���鲻����" << endl;
				continue;
			}
			else if (n == 2) {
				cout << "����洢��Ϊ0���Ҷ��߽������Ѵ�����" << endl;
				continue;
			}
			else if (n == 3) {
				cout << "����洢��Ϊ0" << endl;
				continue;
			}
			else if (n == 4) {
				cout << "���߽������Ѵ�����" << endl;
				continue;
			}
			else if (n == 0) {
				cout << "�����ɹ�" << endl;
				continue;
			}

		}

		case 6: {
			int bookId;
			cout << endl << "�������鼮id:";
			cin >> bookId;
			int n = record.BackBook(readerId, bookId);
			if (n == 1) {
				cout << "����δ�������" << endl;
				continue;
			}
			else if (n == 0) {
				cout << "�����ɹ�" << endl;
				continue;
			}
		}
		case 7:
			InitialMenu();
			break;

		default:
			cout << "����һ������ѡ��Ļ���\n" << endl;
			continue;
		}break;
	}
}

//������Ա����
void PrimaryManagerMenu(int id) {
	system("cls");
	cout << "*********************************" << endl;
	cout << "***        ѡ�����¹���       ***" << endl;
	cout << "***        1.�����鼮��Ϣ     ***" << endl;
	cout << "***        2.���������Ϣ     ***" << endl;
	cout << "***        3.��������Ա     ***" << endl;
	cout << "***        4.�鿴�����¼     ***" << endl;
	cout << "***        5.�����Լ�����     ***" << endl;
	cout << "***        6.�˳�             ***" << endl;
	cout << "*********************************" << endl;
	Operate o;
	int n;
	int identity = 3;
	while (cout << "��ѡ��:" && cin >> n) {
		switch (n) {
		case 1:
		{
			int manageIdentity = 3;
			ManageBookMenu(identity, id,manageIdentity);
		}
		case 2: {
			int manageIdentity = 3;
			ManageReaderMenu(identity, id,manageIdentity);
		}

		case 3: {
			int manageIdentity = 3;
			ManageViceMenu(id,manageIdentity);
		} 
		case 4: {
			int n;
			system("cls");
			cout << "*********************************" << endl;
			cout << "***        1.�鿴ȫ����¼     ***" << endl;
			cout << "***        2.�鿴ָ������     ***" << endl;
			cout << "***        3.�˳�             ***" << endl;
			cout << "*********************************" << endl;
			while (cout << "��ѡ��:" && cin >> n) {

				switch (n)
				{
				case 1: {
					ViewBorrowingRecord(identity, id);
					continue;
				}

				case 2: {
					int readerId;
					cout << "���������id:";
					cin >> readerId;
					ViewBorrowingRecordById(identity, id, readerId);
					continue;
				}
				case 3: {
					PrimaryManagerMenu(id);
				}
				default:
					break;
				}
			}
		}continue;

		case 5:
		{
			string password;
			cout << "������������:";
			cin >> password;
			reader.UpdetaPassword(id, password);
			cout << "���ĳɹ�" << endl;
		}continue;

		case 6:
			InitialMenu();
			break;

		default:
			cout << "����һ������ѡ��Ļ���\n" << endl;
			continue;
		}break;
	}
}

//������Ա����
void ViceManagerMenu(int id) {
	system("cls");
	cout << "*********************************" << endl;
	cout << "***        ѡ�����¹���       ***" << endl;
	cout << "***        1.�����鼮��Ϣ     ***" << endl;
	cout << "***        2.���������Ϣ     ***" << endl;
	cout << "***        3.�鿴�����¼     ***" << endl;
	cout << "***        4.�����Լ�����     ***" << endl;
	cout << "***        5.�˳�             ***" << endl;
	cout << "*********************************" << endl;
	Operate o;
	int n;
	int identity = 2;
	while (cout << "��ѡ��:" && cin >> n) {
		switch (n) {
		case 1: {
			int manageIdentity = 2;
			ManageBookMenu(identity, id, manageIdentity);
		}

		case 2: {
			int manageIdentity = 2;
			ManageReaderMenu(identity, id, manageIdentity);
		}

		case 3: {
			int n;
			system("cls");
			cout << "*********************************" << endl;
			cout << "***        1.�鿴ȫ����¼     ***" << endl;
			cout << "***        2.�鿴ָ������     ***" << endl;
			cout << "***        3.�˳�             ***" << endl;
			cout << "*********************************" << endl;
			while (cout << "��ѡ��:" && cin >> n) {

				switch (n)
				{
				case 1: {
					ViewBorrowingRecord(identity,id);
					continue;
				}

				case 2: {
					int readerId;
					cout << "���������id:";
					cin >> readerId;
					ViewBorrowingRecordById(identity, id, readerId);
					continue;
				}
				case 3: {
					ViceManagerMenu(id);
				}
				default:
					break;
				}
			}
		}continue;

		case 4: {
			string password;
			cout << "������������:";
			cin >> password;
			reader.UpdetaPassword(id, password);
			cout << "���ĳɹ�";
		}continue;

		case 5:
			InitialMenu();
			break;
		default:
			cout << "����һ������ѡ��Ļ���\n" << endl;
			continue;
		}break;
	}
}

//�����鼮����
void ManageBookMenu(int identity,int id,int manageIdentity) {
	system("cls");
	cout << "*********************************" << endl;
	cout << "***        ѡ�����¹���       ***" << endl;
	cout << "***        1.�鿴�鼮��Ϣ     ***" << endl;
	cout << "***        2.�����鼮��Ϣ     ***" << endl;
	cout << "***        3.ɾ���鼮��Ϣ     ***" << endl;
	cout << "***        4.�����鼮��Ϣ     ***" << endl;
	cout << "***        5.�˳�             ***" << endl;
	cout << "*********************************" << endl;
	Operate o;
	int n;
	while (cout << "��ѡ��:" && cin >> n) {
		switch (n) {
		case 1:
		{
			ViewBook(id,identity);
			continue;
		}
		case 2: {
			string name, author, publisher, publish_date;
			double price;
			int number, category;
			int tag = 1;
			cout << "����:";
			cin >> name;
			cout << endl << "����:";
			cin >> author;
			cout << endl << "����:";
			cin >> category;
			cout << endl << "������:";
			cin >> publisher;
			cout << endl << "����ʱ��(0000/00/00):";
			cin >> publish_date;
			cout << endl << "�۸�:";
			cin >> price;
			cout << endl << "�洢��:";
			cin >> number;
			o.AddBook(name, author, category, publisher, publish_date, price, number,tag,id);
			cout << "����ɹ�";
			continue;
		}
		case 3: {
			int bookId;
			int tag = 0;
			cout << "�鼮���:";
			cin >> bookId;
			// TODO δ�жϷ���ֵ
			o.DeleteBook(bookId,id,tag);
			cout << "ɾ���ɹ�" << endl;
			continue;
		}
		case 4: {
			int bookId;
			system("cls");
			cout << "****************************" << endl;
			cout << "***        1.��������     ***" << endl;
			cout << "***        2.��������     ***" << endl;
			cout << "***        3.��������     ***" << endl;
			cout << "***        4.���ĳ�����   ***" << endl;
			cout << "***        5.���ĳ���ʱ�� ***" << endl;
			cout << "***        6.���ļ۸�     ***" << endl;
			cout << "***        7.���Ĵ洢��   ***" << endl;
			cout << "***        8.�˳�         ***" << endl;
			cout << "****************************" << endl;
			while (cout << "�������鼮���:" && cin >> bookId) {
				if (book.determineId(bookId) > 0) {
					int s;
					while (cout << "��ѡ��:" && cin >> s) {
						switch (s)
						{
						case 1: {
							cout << endl << "����������:";
							string name;
							cin >> name;
							book.UpdateBookName(bookId, name,id);
							cout << "���ĳɹ�" << endl;
						}continue;

						case 2: {
							cout << endl << "����������:";
							string author;
							cin >> author;
							book.UpdateBookAuthor(bookId, author,id);
							cout << "���ĳɹ�" << endl;
						}continue;

						case 3: {
							cout << endl << "����������:";
							int category;
							cin >> category;
							book.UpdateBookCategory(bookId, category,id);
							cout << "���ĳɹ�" << endl;
						}continue;

						case 4: {
							cout << endl << "�����������:";
							string publisher;
							cin >> publisher;
							book.UpdateBookPublisher(bookId, publisher,id);
							cout << "���ĳɹ�" << endl;
						}continue;

						case 5: {
							cout << endl << "���������ʱ��:";
							string publish_date;
							cin >> publish_date;
							book.UpdateBookPublishDate(bookId, publish_date,id);
							cout << "���ĳɹ�" << endl;
						}continue;

						case 6: {
							cout << endl << "������۸�:";
							int price;
							cin >> price;
							book.UpdateBookPrice(bookId, price,id);
							cout << "���ĳɹ�" << endl;
						}continue;

						case 7: {
							cout << endl << "������洢��:";
							int number;
							cin >> number;
							book.UpdateBookNumber(bookId, number,id);
							cout << "���ĳɹ�" << endl;
						}continue;

						case 8:
							ManageBookMenu(identity, id, manageIdentity);
						default:
							cout << "����һ������ѡ��Ļ���\n" << endl;
							continue;
						}
					}continue;
				}
				else {
					cout << "�鼮������";
					continue;
				}
			}
		}
			
		case 5:
		{
			if (manageIdentity == 2) {
				ViceManagerMenu(id);
			}
			else if (manageIdentity == 3) {
				PrimaryManagerMenu(id);
			}
		}

		default:
			cout << "����һ������ѡ��Ļ���\n" << endl;
			continue;

		}break;
	}
}

//������߽���
void ManageReaderMenu(int identity,int manageId,int manageIdentity){
	system("cls");
	cout << "*********************************" << endl;
	cout << "***        ѡ�����¹���       ***" << endl;
	cout << "***        1.�鿴������Ϣ     ***" << endl;
	cout << "***        2.���Ӷ�����Ϣ     ***" << endl;
	cout << "***        3.ɾ��������Ϣ     ***" << endl;
	cout << "***        4.���Ķ�����Ϣ     ***" << endl;
	cout << "***        5.�˳�             ***" << endl;
	cout << "*********************************" << endl;
	Operate o;
	int n;
	while (cout << "��ѡ��:"&&cin >> n) {
		switch (n)
		{
		case 1: {
			identity = 1;
			ViewReader(identity, manageId, manageIdentity);
		}
			  continue;	
		
		case 2: {
			string name, phone, password;
			int sex;
			int bnumber = 0;
			int identity = 1;
			int tag = 1;
			cout << "����:";
			cin >> name;
			cout << endl << "�Ա�(1-�У�2-Ů):";
			cin >> sex;
			cout << endl << "�绰����(11λ):";
			cin >> phone;
			cout << endl << "����:";
			cin >> password;
			//TODO �жϷ���ֵ�����ʧ��ԭ��
			operate.AddReader(name, sex, phone, password, bnumber, identity, tag,manageId);
			continue;
		}

		case 3: {
			int readerId;
			int tag = 0;
			cout << "����id:";
			cin >> readerId;
			o.DeleteReader(readerId, manageId, tag);
			continue;
		}
		case 4: {
			int readerId;
			system("cls");
			cout << "****************************" << endl;
			cout << "***        1.��������     ***" << endl;
			cout << "***        2.�����Ա�     ***" << endl;
			cout << "***        3.���ĵ绰���� ***" << endl;
			cout << "***        4.�˳�         ***" << endl;
			cout << "****************************" << endl;
			//TODO �ж�����Ƿ�Ϊ����Ա
			while (cout << "������:" && cin >> readerId) {
				if (reader.determineById(readerId) > 0) {
					int s;
					while (cout << "��ѡ��:" && cin >> s) {
						switch (s)
						{
						case 1: {
							cout << endl << "����������:";
							string name;
							cin >> name;
							reader.UpdateReaderName(readerId, name, manageId);

						}continue;

						case 2: {
							cout << endl << "�������Ա�:";
							int sex;
							cin >> sex;
							reader.UpdateReaderSex(readerId, sex, manageId);

						}continue;

						case 3: {
							cout << endl << "������绰��:";
							string phone;
							cin >> phone;
							reader.UpdateReaderPhone(readerId, phone, manageId);

						}continue;

						case 4:
						{
							ManageReaderMenu(identity, manageId, manageIdentity);
						}

						default:
							cout << "����һ������ѡ��Ļ���\n" << endl;
							continue;
						}
					}
					continue;
				}
				else {
					cout << "�û�������";
					continue;
				}
			}
		}
		case 5:
		{
			if (manageIdentity == 2) {
				ViceManagerMenu(manageId);
			}
			else if (manageIdentity == 3) {
				PrimaryManagerMenu(manageId);
			}
		}
		default:
			cout << "����һ������ѡ��Ļ���\n" << endl;
			continue;
		}break;
	}
}

//������Ա��������Ա����
void ManageViceMenu(int manageId,int manageIdentity) {
	system("cls");
	cout << "************************************" << endl;
	cout << "***        ѡ�����¹���           ***" << endl;
	cout << "***        1.�鿴������Ա��Ϣ     ***" << endl;
	cout << "***        2.���Ӹ�����Ա��Ϣ     ***" << endl;
	cout << "***        3.ɾ��������Ա��Ϣ     ***" << endl;
	cout << "***        4.���ĸ�����Ա��Ϣ     ***" << endl;
	cout << "***        5.�˳�                ***" << endl;
	cout << "************************************" << endl;
	Operate o;
	int n;
	int identity = 3;
	while (cout << "��ѡ��:" && cin >> n) {
		switch (n)
		{
		case 1: {
			identity = 2;
			ViewReader(identity, manageId, manageIdentity);
		}
			  continue;//---�鿴����Ա����

		case 2: {
			string name, phone, password;
			int sex;
			int identity = 2;
			int tag = 1;
			cout << "����:";
			cin >> name;
			cout << endl << "�Ա�(1-�У�2-Ů):";
			cin >> sex;
			cout << endl << "�绰����(11λ):";
			cin >> phone;
			cout << endl << "����:";
			cin >> password;
			operate.AddReader(name, sex, phone, password, NULL, 2, 1, manageId);
			continue;
		}

		case 3: {
			int id;
			int tag = 0;
			cout << "������Աid:";
			cin >> id;
			o.DeleteReader(id,manageId,tag);
			continue;
		}
		case 4: {
			int readerId;
			system("cls");
			cout << "****************************" << endl;
			cout << "***        1.��������     ***" << endl;
			cout << "***        2.�����Ա�     ***" << endl;
			cout << "***        3.���ĵ绰���� ***" << endl;
			cout << "***        4.�˳�         ***" << endl;
			cout << "****************************" << endl;
			while (cout << "�����븱����Աid:" && cin >> readerId) {
				if (reader.determineById(readerId) > 0) {
					int s;
					while (cout << "��ѡ��:" && cin >> s) {
						switch (s)
						{
						case 1: {
							cout << endl << "����������:";
							string name;
							cin >> name;

							reader.UpdateReaderName(readerId, name, manageId);

						}continue;

						case 2: {
							cout << endl << "�������Ա�:";
							int sex;
							cin >> sex;
							reader.UpdateReaderSex(readerId, sex, manageId);

						}continue;

						case 3: {
							cout << endl << "������绰��:";
							string phone;
							cin >> phone;
							reader.UpdateReaderPhone(readerId, phone, manageId);

						}continue;

						case 4:
						{
							ManageViceMenu(manageId, manageIdentity);
						}

						default:
							cout << "����һ������ѡ��Ļ���\n" << endl;
							continue;
						}
					}
					continue;
				}
				else {
					cout << "�û�������";
					continue;
				}
			}
		}
		case 5:
			PrimaryManagerMenu(manageId);
		default:
			cout << "����һ������ѡ��Ļ���\n" << endl;
			continue;
		}break;
	}
}

//�����鼮����
void SearchBook(int readerId) {
	system("cls");
	cout << "************************" << endl;
	cout << "***   1.����id����   ***" << endl;
	cout << "***   2.������������ ***" << endl;
	cout << "***   3.������������ ***" << endl;
	cout << "***   4.�˳�         ***" << endl;
	cout << "***********************" << endl;

	int n;
	while (cout << "��ѡ��:" && cin >> n) {
		switch (n) {
		case 1: {
			int bookId;
			cout << "����id:";
			cin >> bookId;//----�ж��Ƿ��и��飬���жϸ����Ƿ�ɾ��
			ViewBookById(bookId,readerId);
		}continue;

		case 2: {
			string name;
			cout << "��������:";
			cin >> name;
			ViewBookByName(name,readerId);
		}continue;


		case 3: {
			string author;
			cout << "��������:";
			cin >> author;
			ViewBookByAuthor(author,readerId);
		}continue;

		case 4:
			ReaderMenu(readerId);
			break;
		default:
			cout << "����һ������ѡ��Ļ���\n" << endl;
			continue;
		}break;

	}
}

//���һҳ�鼮����
void OutputBook(int page, int pageSize) {
	vector<Book> books = GetAllBook(page, pageSize);
	if (books.empty()) {
		cout << "�޼�¼" << endl;
	}
	else {
		cout << "�鼮���        ����         ����      ����              ������       ����ʱ��      �۸�       �洢��   ����״̬" << endl;
		cout << "�鼮���ࣺ1-���� 2-С˵ 3-���� 4-�汾" << endl;
		for (vector<Book>::iterator it = books.begin(); it != books.end(); ++it)
		{
			Book b = *it;
			cout << setw(8) << b.GetId() << setw(12) << b.GetName() << setw(13) << b.GetAuthor() << setw(10) << b.GetCategory() << setw(20) << b.GetPublisher() << setw(15) << b.GetPublishDate() << setw(10) << b.GetPrice() << setw(10) << b.GetNumber() << setw(5) << b.GetTag() << endl;
		}
	}
}

//����id���һҳ�鼮����
void OutputBookById(int page, int pageSize,int bookId) {
	vector<Book> books = GetBookById(bookId, page, pageSize);
	if (books.empty()) {
		cout << "�޼�¼" << endl;
	}
	else {
		cout << "�鼮���        ����         ����      ����              ������       ����ʱ��      �۸�       �洢��   ����״̬" << endl;
		cout << "�鼮���ࣺ1-���� 2-С˵ 3-���� 4-�汾" << endl;
		for (vector<Book>::iterator it = books.begin(); it != books.end(); ++it)
		{
			Book b = *it;
			cout << setw(8) << b.GetId() << setw(12) << b.GetName() << setw(13) << b.GetAuthor() << setw(10) << b.GetCategory() << setw(20) << b.GetPublisher() << setw(15) << b.GetPublishDate() << setw(10) << b.GetPrice() << setw(10) << b.GetNumber() << setw(5) << b.GetTag() << endl;
		}
	}
}
//�����������һҳ�鼮����
void OutputBookByAuthor(int page, int pageSize, string author) {
	vector<Book> books = GetBookByAuthor(author,page, pageSize);
	if (books.empty()) {
		cout << "�޼�¼" << endl;
	}
	else {
		cout << "�鼮���        ����         ����      ����              ������       ����ʱ��      �۸�       �洢��   ����״̬" << endl;
		cout << "�鼮���ࣺ1-���� 2-С˵ 3-���� 4-�汾" << endl;
		for (vector<Book>::iterator it = books.begin(); it != books.end(); ++it)
		{
			Book b = *it;
			cout << setw(8) << b.GetId() << setw(12) << b.GetName() << setw(13) << b.GetAuthor() << setw(10) << b.GetCategory() << setw(20) << b.GetPublisher() << setw(15) << b.GetPublishDate() << setw(10) << b.GetPrice() << setw(10) << b.GetNumber() << setw(5) << b.GetTag() << endl;
		}
	}
}
//�����������һҳ�鼮����
void OutputBookByName(int page, int pageSize, string name) {
	vector<Book> books = GetBookByName(name, page, pageSize);
	if (books.empty()) {
		cout << "�޼�¼" << endl;
	}
	else {
		cout << "�鼮���        ����         ����      ����              ������       ����ʱ��      �۸�       �洢��   ����״̬" << endl;
		cout << "�鼮���ࣺ1-���� 2-С˵ 3-���� 4-�汾" << endl;
		for (vector<Book>::iterator it = books.begin(); it != books.end(); ++it)
		{
			Book b = *it;
			cout << setw(8) << b.GetId() << setw(12) << b.GetName() << setw(13) << b.GetAuthor() << setw(10) << b.GetCategory() << setw(20) << b.GetPublisher() << setw(15) << b.GetPublishDate() << setw(10) << b.GetPrice() << setw(10) << b.GetNumber() << setw(5) << b.GetTag() << endl;
		}
	}
}
//���һҳ��������
void OutputReader(int page, int pageSize, int identity) {
	vector<Reader> readers = GetAllReader(page, pageSize, identity);
	if (readers.empty()) {
		cout << "�޼�¼" << endl;
	}
	else {
		cout << "���߱��       ����       �Ա�     ������    ���     ��������              ����ʱ��" << endl;
		for (vector<Reader>::iterator it = readers.begin(); it != readers.end(); ++it)
		{
			Reader r = *it;
			cout << setw(5) << r.GetId() << setw(10) << r.GetName() << setw(8) << r.GetSex() << setw(20) << r.GetPhone() << setw(10) << r.GetNumber() << setw(5) << r.GetIdentity() << setw(5) << r.GetLastOperator() << setw(20) << r.GetUpdateTime() << endl;
		}
	}
}

//���һҳ�����¼
void OutputBorrowing(int page, int pageSize) {
	vector<Record> records = GetAllBorrowing(page, pageSize);
	if (records.empty()) {
		cout << "�޼�¼" << endl;
	}
	else {
		cout << "������      ����id       �鼮id     ����" << endl;
		for (vector<Record>::iterator it = records.begin(); it != records.end(); ++it)
		{
			Record r = *it;
			cout << setw(5) << r.GetBorrowingId() << setw(10) << r.GetReaderId() << setw(8) << r.GetBookId() << setw(20) << r.GetName() << endl;
		}
	}
}

//�������һҳ�����¼
void OutputBorrowingById(int page, int pageSize,int readerId) {
	vector<Record> records = GetBorrowingById(page, pageSize,readerId);
	if (records.empty()) {
		cout << "�޼�¼" << endl;
	}
	else {
		cout << "������      ����id       �鼮id     ����" << endl;
		for (vector<Record>::iterator it = records.begin(); it != records.end(); ++it)
		{
			Record r = *it;
			cout << setw(5) << r.GetBorrowingId() << setw(10) << r.GetReaderId() << setw(8) << r.GetBookId() << setw(20) << r.GetName() << endl;
		}
	}
}
//�鿴�鼮����
void ViewBook(int id, int identity) {
	int totalDatas = book.DataNumber();//��������
	int pageSize = 5;
	int totalPages = totalDatas / pageSize;//��ҳ��
	if (totalDatas % pageSize > 0) {
		totalPages = totalPages + 1;
	}
	int page = 1;
	system("cls");
	OutputBook(page, pageSize);
	cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
	cout << "��ѡ��:";
	int s;
	while (cin >> s) {
		switch (s)
		{
		case 1: {
			if (page == totalPages) {
				cout << "��ҳΪ���һҳ";
				cout << "��ѡ��:";
				continue;
			}
			else {
				page += 1;
				system("cls");
				OutputBook(page, pageSize);
				cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
				cout << "��ѡ��:";
				continue;
			}
		}
		case 2: {
			if (page == 1) {
				cout << "��ҳΪ��һҳ";
				cout << "��ѡ��:";
				continue;
			}
			else {
				page -= 1;
				system("cls");
				OutputBook(page, pageSize);
				cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
				cout << "��ѡ��:";
				continue;
			}
		}
		case 3: {
			cout << "������ҳ��:";
			cin >> page;
			while (page<1 || page>totalPages) {
				cout << "����������:";
				cin >> page;
			}
			system("cls");
			OutputBook(page, pageSize);
			cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
			cout << "��ѡ��:";
			continue;
		}
		case 4:
		{
			if (identity == 1) {
				ReaderMenu(id);
			}
			else if (identity == 2 || identity == 3) {
				ManageBookMenu(identity, id, identity);
			}
		}
		default:
			cout << "����һ������ѡ��Ļ���\n" << endl;
			continue;
		}
	}
}

//����id�鿴�鼮
void ViewBookById(int bookId, int readerId) {
	int totalDatas = book.DataNumberById(bookId);//��������
	int pageSize = 5;
	int totalPages = totalDatas / pageSize;//��ҳ��
	if (totalDatas % pageSize > 0) {
		totalPages = totalPages + 1;
	}
	int page = 1;
	system("cls");
	OutputBookById(page, pageSize, bookId);
	cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
	cout << "��ѡ��:";
	int s;
	while (cin >> s) {
		switch (s)
		{
		case 1: {
			if (page == totalPages) {
				cout << "��ҳΪ���һҳ";
				cout << "��ѡ��:";
				continue;
			}
			else {
				page += 1;
				system("cls");
				OutputBookById(page, pageSize, bookId);
				cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
				cout << "��ѡ��:";
				continue;
			}
		}
		case 2: {
			if (page == 1) {
				cout << "��ҳΪ��һҳ";
				cout << "��ѡ��:";
				continue;
			}
			else {
				page -= 1;
				system("cls");
				OutputBookById(page, pageSize, bookId);
				cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
				cout << "��ѡ��:";
				continue;
			}
		}
		case 3: {
			cout << "������ҳ��:";
			cin >> page;
			while (page<1 || page>totalPages) {
				cout << "����������:";
				cin >> page;
			}
			system("cls");
			OutputBookById(page, pageSize, bookId);
			cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
			cout << "��ѡ��:";

		}
		case 4:
			SearchBook(readerId);
		default:
			cout << "����һ������ѡ��Ļ���\n" << endl;
			continue;
		}
	}
}

//�������߲鿴�鼮����
void ViewBookByAuthor(string author, int readerId) {
	int totalDatas = book.DataNumberByAuthor(author);//��������
	int pageSize = 5;
	int totalPages = totalDatas / pageSize;//��ҳ��
	if (totalDatas % pageSize > 0) {
		totalPages = totalPages + 1;
	}
	int page = 1;
	system("cls");
	OutputBookByAuthor(page, pageSize, author);
	cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
	cout << "��ѡ��:";
	int s;
	while (cin >> s) {
		switch (s)
		{
		case 1: {
			if (page == totalPages) {
				cout << "��ҳΪ���һҳ";
				cout << "��ѡ��:";
				continue;
			}
			else {
				page += 1;
				system("cls");
				OutputBookByAuthor(page, pageSize, author);
				cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
				cout << "��ѡ��:";
				continue;
			}
		}
		case 2: {
			if (page == 1) {
				cout << "��ҳΪ��һҳ";
				cout << "��ѡ��:";
				continue;
			}
			else {
				page -= 1;
				system("cls");
				OutputBookByAuthor(page, pageSize, author);
				cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
				cout << "��ѡ��:";
				continue;
			}
		}
		case 3: {
			cout << "������ҳ��:";
			cin >> page;
			while (page<1 || page>totalPages) {
				cout << "����������:";
				cin >> page;
			}
			system("cls");
			OutputBookByAuthor(page, pageSize, author);
			cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
			cout << "��ѡ��:";

		}
		case 4:
			SearchBook(readerId);
			break;
		default:
			cout << "����һ������ѡ��Ļ���\n" << endl;
			continue;
		}
	}
}

//���������鿴�鼮����
void ViewBookByName(string name, int readerId) {
	int totalDatas = book.DataNumberByName(name);//��������
	int pageSize = 5;
	int totalPages = totalDatas / pageSize;//��ҳ��
	if (totalDatas % pageSize > 0) {
		totalPages = totalPages + 1;
	}
	int page = 1;
	system("cls");
	OutputBookByName(page, pageSize, name);
	cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
	cout << "��ѡ��:";
	int s;
	while (cin >> s) {
		switch (s)
		{
		case 1: {
			if (page == totalPages) {
				cout << "��ҳΪ���һҳ";
				cout << "��ѡ��:";
				continue;
			}
			else {
				page += 1;
				system("cls");
				OutputBookByName(page, pageSize, name);
				cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
				cout << "��ѡ��:";
				continue;
			}
		}
		case 2: {
			if (page == 1) {
				cout << "��ҳΪ��һҳ";
				cout << "��ѡ��:";
				continue;
			}
			else {
				page -= 1;
				system("cls");
				OutputBookByName(page, pageSize, name);
				cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
				cout << "��ѡ��:";
				continue;
			}
		}
		case 3: {
			cout << "������ҳ��:";
			cin >> page;
			while (page<1 || page>totalPages) {
				cout << "����������:";
				cin >> page;
			}
			system("cls");
			OutputBookByName(page, pageSize, name);
			cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
			cout << "��ѡ��:";

		}
		case 4:
			SearchBook(readerId);
			break;
		default:
			cout << "����һ������ѡ��Ļ���\n" << endl;
			continue;
		}
	}
}

//�鿴���߽���
void ViewReader(int identity, int manageId, int manageIdentity) {
	int totalDatas = reader.DataNumber(identity);//��������
	int pageSize = 5;
	int totalPages = totalDatas / pageSize;//��ҳ��
	if (totalDatas % pageSize > 0) {
		totalPages = totalPages + 1;
	}
	int page = 1;

	int s;
	system("cls");
	OutputReader(page, pageSize, identity);
	cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
	cout << "��ѡ��:";

	while (cin >> s) {
		cout << totalPages << endl;
		switch (s)
		{
		case 1: {
			if (page == totalPages) {
				cout << "��ҳΪ���һҳ";
				cout << "��ѡ��:";
				continue;
			}
			else {
				page += 1;
				system("cls");
				OutputReader(page, pageSize, identity);
				cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
				cout << "��ѡ��:";
				continue;
			}
		}
		case 2: {
			if (page == 1) {
				cout << "��ҳΪ��һҳ";
				cout << "��ѡ��:";

				continue;
			}
			else {
				page -= 1;
				system("cls");
				OutputReader(page, pageSize, identity);
				cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
				cout << "��ѡ��:";
				continue;
			}
		}
		case 3: {
			cout << "������ҳ��:";
			cin >> page;
			while (page<1 || page>totalPages) {
				cout << "����������:";
				cin >> page;
			}
			system("cls");
			OutputReader(page, pageSize, identity);
			cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
			cout << "��ѡ��:";
		}
			  continue;
		case 4:
		{
			if (identity == 1) {
				ManageReaderMenu(identity, manageId, manageIdentity);
			}
			else if (identity == 2) {
				ManageViceMenu(manageId, manageIdentity);
			}
		}
		default:
			cout << "����һ������ѡ��Ļ���\n" << endl;
			continue;
		}
		break;
	}
}

//�鿴�����¼����
void ViewBorrowingRecord(int identity, int manageId) {
	int totalDatas = record.DataNumber();//��������
	int pageSize = 5;
	int totalPages = totalDatas / pageSize;//��ҳ��
	if (totalDatas % pageSize > 0) {
		totalPages = totalPages + 1;
	}
	int page = 1;

	int s;
	system("cls");
	OutputBorrowing(page, pageSize);
	cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
	cout << "��ѡ��:";

	while (cin >> s) {
		cout << totalPages << endl;
		switch (s)
		{
		case 1: {
			if (page == totalPages) {
				cout << "��ҳΪ���һҳ";
				cout << "��ѡ��:";
				continue;
			}
			else {
				page += 1;
				system("cls");
				OutputBorrowing(page, pageSize);
				cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
				cout << "��ѡ��:";
				continue;
			}
		}
		case 2: {
			if (page == 1) {
				cout << "��ҳΪ��һҳ";
				cout << "��ѡ��:";

				continue;
			}
			else {
				page -= 1;
				system("cls");
				OutputBorrowing(page, pageSize);
				cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
				cout << "��ѡ��:";
				continue;
			}
		}
		case 3: {
			cout << "������ҳ��:";
			cin >> page;
			while (page<1 || page>totalPages) {
				cout << "����������:";
				cin >> page;
			}
			system("cls");
			OutputBorrowing(page, pageSize);
			cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
			cout << "��ѡ��:";
		}
			  continue;
		case 4:
		{
			if (identity == 3) {
				PrimaryManagerMenu(manageId);
			}
			else if (identity == 2) {
				ViceManagerMenu(manageId);
			}
		}
		default:
			cout << "����һ������ѡ��Ļ���\n" << endl;
			continue;
		}
		break;
	}
}

//����id�鿴�����¼����
void ViewBorrowingRecordById(int identity, int manageId,int readerId) {
	int totalDatas = record.DataNumberById(readerId);//��������
	int pageSize = 5;
	int totalPages = totalDatas / pageSize;//��ҳ��
	if (totalDatas % pageSize > 0) {
		totalPages = totalPages + 1;
	}
	int page = 1;

	int s;
	system("cls");
	OutputBorrowing(page, pageSize);
	cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
	cout << "��ѡ��:";

	while (cin >> s) {
		cout << totalPages << endl;
		switch (s)
		{
		case 1: {
			if (page == totalPages) {
				cout << "��ҳΪ���һҳ";
				cout << "��ѡ��:";
				continue;
			}
			else {
				page += 1;
				system("cls");
				OutputBorrowing(page, pageSize);
				cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
				cout << "��ѡ��:";
				continue;
			}
		}
		case 2: {
			if (page == 1) {
				cout << "��ҳΪ��һҳ";
				cout << "��ѡ��:";
				continue;
			}
			else {
				page -= 1;
				system("cls");
				OutputBorrowing(page, pageSize);
				cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
				cout << "��ѡ��:";
				continue;
			}
		}
		case 3: {
			cout << "������ҳ��:";
			cin >> page;
			while (page<1 || page>totalPages) {
				cout << "����������:";
				cin >> page;
			}
			system("cls");
			OutputBorrowing(page, pageSize);
			cout << "1.��һҳ  2.��һҳ  3.ѡ��ҳ��  4.�˳�  ��ǰҳ��:" << page << "��ҳ��:" << totalPages << endl;
			cout << "��ѡ��:";
		}
			  continue;
		case 4:
		{
			if (identity == 3) {
				PrimaryManagerMenu(manageId);
			}
			else if (identity == 2) {
				ViceManagerMenu(manageId);
			}
			else if (identity == 1) {
				ReaderMenu(manageId);

			}
			break;
		}
		default:
			cout << "����һ������ѡ��Ļ���\n" << endl;
			continue;
		}
		break;
	}
}