#include"menu.h"

Operate operate;
Reader reader;
Book book;
Record record;
//初始界面
void InitialMenu() {
	cout << "*********************************" << endl;
	cout << "***           1.登录           ***" << endl;
	cout << "***           2.注册           ***" << endl;
	cout << "***           3.退出           ***" << endl;
	cout << "*********************************" << endl;
	string account;
	while (cout << "请选择:"&&cin >> account) {
		int n = atoi(account.c_str());
		switch (n) {
		case 1: {
			cout << "请输入账号(手机号):";
			string phone_number;
			cin >> phone_number;//输入账号
			while (size(phone_number) != 11) {
				cout << endl << "您输入的账号不符合规范(11位手机号)请重新输入账号:";
				cin >> phone_number;
			}
			int num_rows = reader.determineByPhone(phone_number);
			switch (num_rows)
			{
			case 0: {
				//读者不存在
				system("cls");
				cout << "未查询到此读者,请注册" << endl;
				string name, phone, password;
				int sex;
				int number = 0;
				int tag = 1;
				int identity = 1;
				cout << "姓名:";
				cin >> name;
				cout << endl << "性别(1-男，2-女):";
				cin >> sex;
				cout << endl << "电话号码(11位):";
				cin >> phone;
				cout << endl << "密码:";
				cin >> password;
				int lastOperator = 1;
				if (reader.InsertReader(name, sex, phone, password, identity, number, tag, lastOperator) == false) {
					cout << "添加失败";
					continue;
				}
				else {
					int readerId = reader.GetreaderId(phone_number);
					//跳转读者界面
					system("cls");
					InitialMenu();
					break;
					//ReaderMenu(readerId);
				}
			}break;

			case 1: {
				//用户存在
				system("cls");
				cout << endl << "请输入密码:";
				string password;
				cin >> password;
				int num_row = reader.VerifyPassword(phone_number, password);//
				while (num_row <= 0) {
					system("cls");
					cout << endl << "密码错误，请重新输入:";
					cin >> password;
					num_row = reader.VerifyPassword(phone_number, password);
				}
				cout << endl << "登陆成功" << endl;

				//获取登陆者id
				int readerId = reader.GetreaderId(phone_number);
				int identity = reader.GetReaderIdentity(phone_number);
				switch (identity)
				{
				case 1: {
					//跳转读者界面
					cout << endl << "用户为读者" << endl;
					ReaderMenu(readerId);
					break;

				}
				case 2: {
					//跳转副管理员界面
					cout << endl << "用户为副管理员" << endl;
					ViceManagerMenu(readerId);
					break;

				}
				case 3: {
					//跳转主管理员界面
					cout << endl << "用户为主管理员" << endl;
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

			cout << "姓名:";
			cin >> name;
			cout << endl << "性别(1-男，2-女):";
			cin >> sex;
			cout << endl << "电话号码(11位):";
			cin >> phone;
			cout << endl << "密码:";
			cin >> password;
			if (reader.InsertReader(name, sex, phone, password, number, identity, tag, NULL) == false) {
				cout << "添加失败,请重新选择" << endl;
				continue;
			}
			else {
				int readerId = reader.GetreaderId(phone);

				//跳转读者界面
				ReaderMenu(readerId);
			}
		}break;

		case 3:
			exit(0);

		default:
			cout << "给你一次重新选择的机会:\n" << endl;
			continue;
		}break;
	}
	
	
}

//读者界面
void ReaderMenu(int readerId) {
	system("cls");
	cout << "*********************************" << endl;
	cout << "***        选择以下功能       ***" << endl;
	cout << "***        1.查看书籍信息     ***" << endl;
	cout << "***        2.查看借书记录     ***" << endl;
	cout << "***        3.搜索书籍信息     ***" << endl;//---------------加一条搜索书籍
	cout << "***        4.更改读者密码     ***" << endl;
	cout << "***        5.借书             ***" << endl;
	cout << "***        6.还书             ***" << endl;
	cout << "***        7.退出             ***" << endl;
	cout << "*********************************" << endl;
	Operate operate;
	Record record;
	int identity = 1;
	int n;
	while (cout << "请选择:" && cin >> n) {
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
			cout << "请输入新密码:";
			cin >> password;
			reader.UpdetaPassword(readerId, password);
			if (reader.UpdetaPassword(readerId, password) == false) {
				cout << "更改失败" << endl;
				continue;
			}
		}continue;


		case 5: {
			int bookId;
			cout << endl << "请输入书籍id:";
			cin >> bookId;
			int n = record.BorrowBook(readerId, bookId);
			if (n == 1) {
				cout << "此书不存在" << endl;
				continue;
			}
			else if (n == 2) {
				cout << "该书存储量为0，且读者借书量已达上限" << endl;
				continue;
			}
			else if (n == 3) {
				cout << "该书存储量为0" << endl;
				continue;
			}
			else if (n == 4) {
				cout << "读者借书量已达上限" << endl;
				continue;
			}
			else if (n == 0) {
				cout << "操作成功" << endl;
				continue;
			}

		}

		case 6: {
			int bookId;
			cout << endl << "请输入书籍id:";
			cin >> bookId;
			int n = record.BackBook(readerId, bookId);
			if (n == 1) {
				cout << "读者未借过此书" << endl;
				continue;
			}
			else if (n == 0) {
				cout << "操作成功" << endl;
				continue;
			}
		}
		case 7:
			InitialMenu();
			break;

		default:
			cout << "给你一次重新选择的机会\n" << endl;
			continue;
		}break;
	}
}

//主管理员界面
void PrimaryManagerMenu(int id) {
	system("cls");
	cout << "*********************************" << endl;
	cout << "***        选择以下功能       ***" << endl;
	cout << "***        1.管理书籍信息     ***" << endl;
	cout << "***        2.管理读者信息     ***" << endl;
	cout << "***        3.管理副管理员     ***" << endl;
	cout << "***        4.查看借书记录     ***" << endl;
	cout << "***        5.更改自己密码     ***" << endl;
	cout << "***        6.退出             ***" << endl;
	cout << "*********************************" << endl;
	Operate o;
	int n;
	int identity = 3;
	while (cout << "请选择:" && cin >> n) {
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
			cout << "***        1.查看全部记录     ***" << endl;
			cout << "***        2.查看指定读者     ***" << endl;
			cout << "***        3.退出             ***" << endl;
			cout << "*********************************" << endl;
			while (cout << "请选择:" && cin >> n) {

				switch (n)
				{
				case 1: {
					ViewBorrowingRecord(identity, id);
					continue;
				}

				case 2: {
					int readerId;
					cout << "请输入读者id:";
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
			cout << "请输入新密码:";
			cin >> password;
			reader.UpdetaPassword(id, password);
			cout << "更改成功" << endl;
		}continue;

		case 6:
			InitialMenu();
			break;

		default:
			cout << "给你一次重新选择的机会\n" << endl;
			continue;
		}break;
	}
}

//副管理员界面
void ViceManagerMenu(int id) {
	system("cls");
	cout << "*********************************" << endl;
	cout << "***        选择以下功能       ***" << endl;
	cout << "***        1.管理书籍信息     ***" << endl;
	cout << "***        2.管理读者信息     ***" << endl;
	cout << "***        3.查看借书记录     ***" << endl;
	cout << "***        4.更改自己密码     ***" << endl;
	cout << "***        5.退出             ***" << endl;
	cout << "*********************************" << endl;
	Operate o;
	int n;
	int identity = 2;
	while (cout << "请选择:" && cin >> n) {
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
			cout << "***        1.查看全部记录     ***" << endl;
			cout << "***        2.查看指定读者     ***" << endl;
			cout << "***        3.退出             ***" << endl;
			cout << "*********************************" << endl;
			while (cout << "请选择:" && cin >> n) {

				switch (n)
				{
				case 1: {
					ViewBorrowingRecord(identity,id);
					continue;
				}

				case 2: {
					int readerId;
					cout << "请输入读者id:";
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
			cout << "请输入新密码:";
			cin >> password;
			reader.UpdetaPassword(id, password);
			cout << "更改成功";
		}continue;

		case 5:
			InitialMenu();
			break;
		default:
			cout << "给你一次重新选择的机会\n" << endl;
			continue;
		}break;
	}
}

//管理书籍界面
void ManageBookMenu(int identity,int id,int manageIdentity) {
	system("cls");
	cout << "*********************************" << endl;
	cout << "***        选择以下功能       ***" << endl;
	cout << "***        1.查看书籍信息     ***" << endl;
	cout << "***        2.增加书籍信息     ***" << endl;
	cout << "***        3.删除书籍信息     ***" << endl;
	cout << "***        4.更改书籍信息     ***" << endl;
	cout << "***        5.退出             ***" << endl;
	cout << "*********************************" << endl;
	Operate o;
	int n;
	while (cout << "请选择:" && cin >> n) {
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
			cout << "书名:";
			cin >> name;
			cout << endl << "作者:";
			cin >> author;
			cout << endl << "种类:";
			cin >> category;
			cout << endl << "出版社:";
			cin >> publisher;
			cout << endl << "出版时间(0000/00/00):";
			cin >> publish_date;
			cout << endl << "价格:";
			cin >> price;
			cout << endl << "存储量:";
			cin >> number;
			o.AddBook(name, author, category, publisher, publish_date, price, number,tag,id);
			cout << "存书成功";
			continue;
		}
		case 3: {
			int bookId;
			int tag = 0;
			cout << "书籍编号:";
			cin >> bookId;
			// TODO 未判断返回值
			o.DeleteBook(bookId,id,tag);
			cout << "删除成功" << endl;
			continue;
		}
		case 4: {
			int bookId;
			system("cls");
			cout << "****************************" << endl;
			cout << "***        1.更改书名     ***" << endl;
			cout << "***        2.更改作者     ***" << endl;
			cout << "***        3.更改种类     ***" << endl;
			cout << "***        4.更改出版社   ***" << endl;
			cout << "***        5.更改出版时间 ***" << endl;
			cout << "***        6.更改价格     ***" << endl;
			cout << "***        7.更改存储量   ***" << endl;
			cout << "***        8.退出         ***" << endl;
			cout << "****************************" << endl;
			while (cout << "请输入书籍编号:" && cin >> bookId) {
				if (book.determineId(bookId) > 0) {
					int s;
					while (cout << "请选择:" && cin >> s) {
						switch (s)
						{
						case 1: {
							cout << endl << "请输入书名:";
							string name;
							cin >> name;
							book.UpdateBookName(bookId, name,id);
							cout << "更改成功" << endl;
						}continue;

						case 2: {
							cout << endl << "请输入作者:";
							string author;
							cin >> author;
							book.UpdateBookAuthor(bookId, author,id);
							cout << "更改成功" << endl;
						}continue;

						case 3: {
							cout << endl << "请输入种类:";
							int category;
							cin >> category;
							book.UpdateBookCategory(bookId, category,id);
							cout << "更改成功" << endl;
						}continue;

						case 4: {
							cout << endl << "请输入出版社:";
							string publisher;
							cin >> publisher;
							book.UpdateBookPublisher(bookId, publisher,id);
							cout << "更改成功" << endl;
						}continue;

						case 5: {
							cout << endl << "请输入出版时间:";
							string publish_date;
							cin >> publish_date;
							book.UpdateBookPublishDate(bookId, publish_date,id);
							cout << "更改成功" << endl;
						}continue;

						case 6: {
							cout << endl << "请输入价格:";
							int price;
							cin >> price;
							book.UpdateBookPrice(bookId, price,id);
							cout << "更改成功" << endl;
						}continue;

						case 7: {
							cout << endl << "请输入存储量:";
							int number;
							cin >> number;
							book.UpdateBookNumber(bookId, number,id);
							cout << "更改成功" << endl;
						}continue;

						case 8:
							ManageBookMenu(identity, id, manageIdentity);
						default:
							cout << "给你一次重新选择的机会\n" << endl;
							continue;
						}
					}continue;
				}
				else {
					cout << "书籍不存在";
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
			cout << "给你一次重新选择的机会\n" << endl;
			continue;

		}break;
	}
}

//管理读者界面
void ManageReaderMenu(int identity,int manageId,int manageIdentity){
	system("cls");
	cout << "*********************************" << endl;
	cout << "***        选择以下功能       ***" << endl;
	cout << "***        1.查看读者信息     ***" << endl;
	cout << "***        2.增加读者信息     ***" << endl;
	cout << "***        3.删除读者信息     ***" << endl;
	cout << "***        4.更改读者信息     ***" << endl;
	cout << "***        5.退出             ***" << endl;
	cout << "*********************************" << endl;
	Operate o;
	int n;
	while (cout << "请选择:"&&cin >> n) {
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
			cout << "姓名:";
			cin >> name;
			cout << endl << "性别(1-男，2-女):";
			cin >> sex;
			cout << endl << "电话号码(11位):";
			cin >> phone;
			cout << endl << "密码:";
			cin >> password;
			//TODO 判断返回值，添加失败原因
			operate.AddReader(name, sex, phone, password, bnumber, identity, tag,manageId);
			continue;
		}

		case 3: {
			int readerId;
			int tag = 0;
			cout << "读者id:";
			cin >> readerId;
			o.DeleteReader(readerId, manageId, tag);
			continue;
		}
		case 4: {
			int readerId;
			system("cls");
			cout << "****************************" << endl;
			cout << "***        1.更改姓名     ***" << endl;
			cout << "***        2.更改性别     ***" << endl;
			cout << "***        3.更改电话号码 ***" << endl;
			cout << "***        4.退出         ***" << endl;
			cout << "****************************" << endl;
			//TODO 判断身份是否为管理员
			while (cout << "请输入:" && cin >> readerId) {
				if (reader.determineById(readerId) > 0) {
					int s;
					while (cout << "请选择:" && cin >> s) {
						switch (s)
						{
						case 1: {
							cout << endl << "请输入姓名:";
							string name;
							cin >> name;
							reader.UpdateReaderName(readerId, name, manageId);

						}continue;

						case 2: {
							cout << endl << "请输入性别:";
							int sex;
							cin >> sex;
							reader.UpdateReaderSex(readerId, sex, manageId);

						}continue;

						case 3: {
							cout << endl << "请输入电话号:";
							string phone;
							cin >> phone;
							reader.UpdateReaderPhone(readerId, phone, manageId);

						}continue;

						case 4:
						{
							ManageReaderMenu(identity, manageId, manageIdentity);
						}

						default:
							cout << "给你一次重新选择的机会\n" << endl;
							continue;
						}
					}
					continue;
				}
				else {
					cout << "用户不存在";
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
			cout << "给你一次重新选择的机会\n" << endl;
			continue;
		}break;
	}
}

//主管理员管理副管理员界面
void ManageViceMenu(int manageId,int manageIdentity) {
	system("cls");
	cout << "************************************" << endl;
	cout << "***        选择以下功能           ***" << endl;
	cout << "***        1.查看副管理员信息     ***" << endl;
	cout << "***        2.增加副管理员信息     ***" << endl;
	cout << "***        3.删除副管理员信息     ***" << endl;
	cout << "***        4.更改副管理员信息     ***" << endl;
	cout << "***        5.退出                ***" << endl;
	cout << "************************************" << endl;
	Operate o;
	int n;
	int identity = 3;
	while (cout << "请选择:" && cin >> n) {
		switch (n)
		{
		case 1: {
			identity = 2;
			ViewReader(identity, manageId, manageIdentity);
		}
			  continue;//---查看管理员函数

		case 2: {
			string name, phone, password;
			int sex;
			int identity = 2;
			int tag = 1;
			cout << "姓名:";
			cin >> name;
			cout << endl << "性别(1-男，2-女):";
			cin >> sex;
			cout << endl << "电话号码(11位):";
			cin >> phone;
			cout << endl << "密码:";
			cin >> password;
			operate.AddReader(name, sex, phone, password, NULL, 2, 1, manageId);
			continue;
		}

		case 3: {
			int id;
			int tag = 0;
			cout << "副管理员id:";
			cin >> id;
			o.DeleteReader(id,manageId,tag);
			continue;
		}
		case 4: {
			int readerId;
			system("cls");
			cout << "****************************" << endl;
			cout << "***        1.更改姓名     ***" << endl;
			cout << "***        2.更改性别     ***" << endl;
			cout << "***        3.更改电话号码 ***" << endl;
			cout << "***        4.退出         ***" << endl;
			cout << "****************************" << endl;
			while (cout << "请输入副管理员id:" && cin >> readerId) {
				if (reader.determineById(readerId) > 0) {
					int s;
					while (cout << "请选择:" && cin >> s) {
						switch (s)
						{
						case 1: {
							cout << endl << "请输入姓名:";
							string name;
							cin >> name;

							reader.UpdateReaderName(readerId, name, manageId);

						}continue;

						case 2: {
							cout << endl << "请输入性别:";
							int sex;
							cin >> sex;
							reader.UpdateReaderSex(readerId, sex, manageId);

						}continue;

						case 3: {
							cout << endl << "请输入电话号:";
							string phone;
							cin >> phone;
							reader.UpdateReaderPhone(readerId, phone, manageId);

						}continue;

						case 4:
						{
							ManageViceMenu(manageId, manageIdentity);
						}

						default:
							cout << "给你一次重新选择的机会\n" << endl;
							continue;
						}
					}
					continue;
				}
				else {
					cout << "用户不存在";
					continue;
				}
			}
		}
		case 5:
			PrimaryManagerMenu(manageId);
		default:
			cout << "给你一次重新选择的机会\n" << endl;
			continue;
		}break;
	}
}

//搜索书籍界面
void SearchBook(int readerId) {
	system("cls");
	cout << "************************" << endl;
	cout << "***   1.根据id搜索   ***" << endl;
	cout << "***   2.根据书名搜索 ***" << endl;
	cout << "***   3.根据作者搜索 ***" << endl;
	cout << "***   4.退出         ***" << endl;
	cout << "***********************" << endl;

	int n;
	while (cout << "请选择:" && cin >> n) {
		switch (n) {
		case 1: {
			int bookId;
			cout << "输入id:";
			cin >> bookId;//----判断是否有该书，在判断该书是否被删除
			ViewBookById(bookId,readerId);
		}continue;

		case 2: {
			string name;
			cout << "输入书名:";
			cin >> name;
			ViewBookByName(name,readerId);
		}continue;


		case 3: {
			string author;
			cout << "输入作者:";
			cin >> author;
			ViewBookByAuthor(author,readerId);
		}continue;

		case 4:
			ReaderMenu(readerId);
			break;
		default:
			cout << "给你一次重新选择的机会\n" << endl;
			continue;
		}break;

	}
}

//输出一页书籍数据
void OutputBook(int page, int pageSize) {
	vector<Book> books = GetAllBook(page, pageSize);
	if (books.empty()) {
		cout << "无记录" << endl;
	}
	else {
		cout << "书籍编号        书名         作者      种类              出版社       出版时间      价格       存储量   存在状态" << endl;
		cout << "书籍种类：1-动漫 2-小说 3-名著 4-绘本" << endl;
		for (vector<Book>::iterator it = books.begin(); it != books.end(); ++it)
		{
			Book b = *it;
			cout << setw(8) << b.GetId() << setw(12) << b.GetName() << setw(13) << b.GetAuthor() << setw(10) << b.GetCategory() << setw(20) << b.GetPublisher() << setw(15) << b.GetPublishDate() << setw(10) << b.GetPrice() << setw(10) << b.GetNumber() << setw(5) << b.GetTag() << endl;
		}
	}
}

//根据id输出一页书籍数据
void OutputBookById(int page, int pageSize,int bookId) {
	vector<Book> books = GetBookById(bookId, page, pageSize);
	if (books.empty()) {
		cout << "无记录" << endl;
	}
	else {
		cout << "书籍编号        书名         作者      种类              出版社       出版时间      价格       存储量   存在状态" << endl;
		cout << "书籍种类：1-动漫 2-小说 3-名著 4-绘本" << endl;
		for (vector<Book>::iterator it = books.begin(); it != books.end(); ++it)
		{
			Book b = *it;
			cout << setw(8) << b.GetId() << setw(12) << b.GetName() << setw(13) << b.GetAuthor() << setw(10) << b.GetCategory() << setw(20) << b.GetPublisher() << setw(15) << b.GetPublishDate() << setw(10) << b.GetPrice() << setw(10) << b.GetNumber() << setw(5) << b.GetTag() << endl;
		}
	}
}
//根据作者输出一页书籍数据
void OutputBookByAuthor(int page, int pageSize, string author) {
	vector<Book> books = GetBookByAuthor(author,page, pageSize);
	if (books.empty()) {
		cout << "无记录" << endl;
	}
	else {
		cout << "书籍编号        书名         作者      种类              出版社       出版时间      价格       存储量   存在状态" << endl;
		cout << "书籍种类：1-动漫 2-小说 3-名著 4-绘本" << endl;
		for (vector<Book>::iterator it = books.begin(); it != books.end(); ++it)
		{
			Book b = *it;
			cout << setw(8) << b.GetId() << setw(12) << b.GetName() << setw(13) << b.GetAuthor() << setw(10) << b.GetCategory() << setw(20) << b.GetPublisher() << setw(15) << b.GetPublishDate() << setw(10) << b.GetPrice() << setw(10) << b.GetNumber() << setw(5) << b.GetTag() << endl;
		}
	}
}
//根据书名输出一页书籍数据
void OutputBookByName(int page, int pageSize, string name) {
	vector<Book> books = GetBookByName(name, page, pageSize);
	if (books.empty()) {
		cout << "无记录" << endl;
	}
	else {
		cout << "书籍编号        书名         作者      种类              出版社       出版时间      价格       存储量   存在状态" << endl;
		cout << "书籍种类：1-动漫 2-小说 3-名著 4-绘本" << endl;
		for (vector<Book>::iterator it = books.begin(); it != books.end(); ++it)
		{
			Book b = *it;
			cout << setw(8) << b.GetId() << setw(12) << b.GetName() << setw(13) << b.GetAuthor() << setw(10) << b.GetCategory() << setw(20) << b.GetPublisher() << setw(15) << b.GetPublishDate() << setw(10) << b.GetPrice() << setw(10) << b.GetNumber() << setw(5) << b.GetTag() << endl;
		}
	}
}
//输出一页读者数据
void OutputReader(int page, int pageSize, int identity) {
	vector<Reader> readers = GetAllReader(page, pageSize, identity);
	if (readers.empty()) {
		cout << "无记录" << endl;
	}
	else {
		cout << "读者编号       姓名       性别     借书量    身份     最后操作者              操作时间" << endl;
		for (vector<Reader>::iterator it = readers.begin(); it != readers.end(); ++it)
		{
			Reader r = *it;
			cout << setw(5) << r.GetId() << setw(10) << r.GetName() << setw(8) << r.GetSex() << setw(20) << r.GetPhone() << setw(10) << r.GetNumber() << setw(5) << r.GetIdentity() << setw(5) << r.GetLastOperator() << setw(20) << r.GetUpdateTime() << endl;
		}
	}
}

//输出一页借书记录
void OutputBorrowing(int page, int pageSize) {
	vector<Record> records = GetAllBorrowing(page, pageSize);
	if (records.empty()) {
		cout << "无记录" << endl;
	}
	else {
		cout << "借书编号      读者id       书籍id     书名" << endl;
		for (vector<Record>::iterator it = records.begin(); it != records.end(); ++it)
		{
			Record r = *it;
			cout << setw(5) << r.GetBorrowingId() << setw(10) << r.GetReaderId() << setw(8) << r.GetBookId() << setw(20) << r.GetName() << endl;
		}
	}
}

//根据输出一页借书记录
void OutputBorrowingById(int page, int pageSize,int readerId) {
	vector<Record> records = GetBorrowingById(page, pageSize,readerId);
	if (records.empty()) {
		cout << "无记录" << endl;
	}
	else {
		cout << "借书编号      读者id       书籍id     书名" << endl;
		for (vector<Record>::iterator it = records.begin(); it != records.end(); ++it)
		{
			Record r = *it;
			cout << setw(5) << r.GetBorrowingId() << setw(10) << r.GetReaderId() << setw(8) << r.GetBookId() << setw(20) << r.GetName() << endl;
		}
	}
}
//查看书籍界面
void ViewBook(int id, int identity) {
	int totalDatas = book.DataNumber();//总数据数
	int pageSize = 5;
	int totalPages = totalDatas / pageSize;//总页数
	if (totalDatas % pageSize > 0) {
		totalPages = totalPages + 1;
	}
	int page = 1;
	system("cls");
	OutputBook(page, pageSize);
	cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
	cout << "请选择:";
	int s;
	while (cin >> s) {
		switch (s)
		{
		case 1: {
			if (page == totalPages) {
				cout << "该页为最后一页";
				cout << "请选择:";
				continue;
			}
			else {
				page += 1;
				system("cls");
				OutputBook(page, pageSize);
				cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
				cout << "请选择:";
				continue;
			}
		}
		case 2: {
			if (page == 1) {
				cout << "该页为第一页";
				cout << "请选择:";
				continue;
			}
			else {
				page -= 1;
				system("cls");
				OutputBook(page, pageSize);
				cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
				cout << "请选择:";
				continue;
			}
		}
		case 3: {
			cout << "请输入页数:";
			cin >> page;
			while (page<1 || page>totalPages) {
				cout << "请重新输入:";
				cin >> page;
			}
			system("cls");
			OutputBook(page, pageSize);
			cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
			cout << "请选择:";
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
			cout << "给你一次重新选择的机会\n" << endl;
			continue;
		}
	}
}

//根据id查看书籍
void ViewBookById(int bookId, int readerId) {
	int totalDatas = book.DataNumberById(bookId);//总数据数
	int pageSize = 5;
	int totalPages = totalDatas / pageSize;//总页数
	if (totalDatas % pageSize > 0) {
		totalPages = totalPages + 1;
	}
	int page = 1;
	system("cls");
	OutputBookById(page, pageSize, bookId);
	cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
	cout << "请选择:";
	int s;
	while (cin >> s) {
		switch (s)
		{
		case 1: {
			if (page == totalPages) {
				cout << "该页为最后一页";
				cout << "请选择:";
				continue;
			}
			else {
				page += 1;
				system("cls");
				OutputBookById(page, pageSize, bookId);
				cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
				cout << "请选择:";
				continue;
			}
		}
		case 2: {
			if (page == 1) {
				cout << "该页为第一页";
				cout << "请选择:";
				continue;
			}
			else {
				page -= 1;
				system("cls");
				OutputBookById(page, pageSize, bookId);
				cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
				cout << "请选择:";
				continue;
			}
		}
		case 3: {
			cout << "请输入页数:";
			cin >> page;
			while (page<1 || page>totalPages) {
				cout << "请重新输入:";
				cin >> page;
			}
			system("cls");
			OutputBookById(page, pageSize, bookId);
			cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
			cout << "请选择:";

		}
		case 4:
			SearchBook(readerId);
		default:
			cout << "给你一次重新选择的机会\n" << endl;
			continue;
		}
	}
}

//根据作者查看书籍界面
void ViewBookByAuthor(string author, int readerId) {
	int totalDatas = book.DataNumberByAuthor(author);//总数据数
	int pageSize = 5;
	int totalPages = totalDatas / pageSize;//总页数
	if (totalDatas % pageSize > 0) {
		totalPages = totalPages + 1;
	}
	int page = 1;
	system("cls");
	OutputBookByAuthor(page, pageSize, author);
	cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
	cout << "请选择:";
	int s;
	while (cin >> s) {
		switch (s)
		{
		case 1: {
			if (page == totalPages) {
				cout << "该页为最后一页";
				cout << "请选择:";
				continue;
			}
			else {
				page += 1;
				system("cls");
				OutputBookByAuthor(page, pageSize, author);
				cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
				cout << "请选择:";
				continue;
			}
		}
		case 2: {
			if (page == 1) {
				cout << "该页为第一页";
				cout << "请选择:";
				continue;
			}
			else {
				page -= 1;
				system("cls");
				OutputBookByAuthor(page, pageSize, author);
				cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
				cout << "请选择:";
				continue;
			}
		}
		case 3: {
			cout << "请输入页数:";
			cin >> page;
			while (page<1 || page>totalPages) {
				cout << "请重新输入:";
				cin >> page;
			}
			system("cls");
			OutputBookByAuthor(page, pageSize, author);
			cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
			cout << "请选择:";

		}
		case 4:
			SearchBook(readerId);
			break;
		default:
			cout << "给你一次重新选择的机会\n" << endl;
			continue;
		}
	}
}

//根据书名查看书籍界面
void ViewBookByName(string name, int readerId) {
	int totalDatas = book.DataNumberByName(name);//总数据数
	int pageSize = 5;
	int totalPages = totalDatas / pageSize;//总页数
	if (totalDatas % pageSize > 0) {
		totalPages = totalPages + 1;
	}
	int page = 1;
	system("cls");
	OutputBookByName(page, pageSize, name);
	cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
	cout << "请选择:";
	int s;
	while (cin >> s) {
		switch (s)
		{
		case 1: {
			if (page == totalPages) {
				cout << "该页为最后一页";
				cout << "请选择:";
				continue;
			}
			else {
				page += 1;
				system("cls");
				OutputBookByName(page, pageSize, name);
				cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
				cout << "请选择:";
				continue;
			}
		}
		case 2: {
			if (page == 1) {
				cout << "该页为第一页";
				cout << "请选择:";
				continue;
			}
			else {
				page -= 1;
				system("cls");
				OutputBookByName(page, pageSize, name);
				cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
				cout << "请选择:";
				continue;
			}
		}
		case 3: {
			cout << "请输入页数:";
			cin >> page;
			while (page<1 || page>totalPages) {
				cout << "请重新输入:";
				cin >> page;
			}
			system("cls");
			OutputBookByName(page, pageSize, name);
			cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
			cout << "请选择:";

		}
		case 4:
			SearchBook(readerId);
			break;
		default:
			cout << "给你一次重新选择的机会\n" << endl;
			continue;
		}
	}
}

//查看读者界面
void ViewReader(int identity, int manageId, int manageIdentity) {
	int totalDatas = reader.DataNumber(identity);//总数据数
	int pageSize = 5;
	int totalPages = totalDatas / pageSize;//总页数
	if (totalDatas % pageSize > 0) {
		totalPages = totalPages + 1;
	}
	int page = 1;

	int s;
	system("cls");
	OutputReader(page, pageSize, identity);
	cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
	cout << "请选择:";

	while (cin >> s) {
		cout << totalPages << endl;
		switch (s)
		{
		case 1: {
			if (page == totalPages) {
				cout << "该页为最后一页";
				cout << "请选择:";
				continue;
			}
			else {
				page += 1;
				system("cls");
				OutputReader(page, pageSize, identity);
				cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
				cout << "请选择:";
				continue;
			}
		}
		case 2: {
			if (page == 1) {
				cout << "该页为第一页";
				cout << "请选择:";

				continue;
			}
			else {
				page -= 1;
				system("cls");
				OutputReader(page, pageSize, identity);
				cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
				cout << "请选择:";
				continue;
			}
		}
		case 3: {
			cout << "请输入页数:";
			cin >> page;
			while (page<1 || page>totalPages) {
				cout << "请重新输入:";
				cin >> page;
			}
			system("cls");
			OutputReader(page, pageSize, identity);
			cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
			cout << "请选择:";
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
			cout << "给你一次重新选择的机会\n" << endl;
			continue;
		}
		break;
	}
}

//查看借书记录界面
void ViewBorrowingRecord(int identity, int manageId) {
	int totalDatas = record.DataNumber();//总数据数
	int pageSize = 5;
	int totalPages = totalDatas / pageSize;//总页数
	if (totalDatas % pageSize > 0) {
		totalPages = totalPages + 1;
	}
	int page = 1;

	int s;
	system("cls");
	OutputBorrowing(page, pageSize);
	cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
	cout << "请选择:";

	while (cin >> s) {
		cout << totalPages << endl;
		switch (s)
		{
		case 1: {
			if (page == totalPages) {
				cout << "该页为最后一页";
				cout << "请选择:";
				continue;
			}
			else {
				page += 1;
				system("cls");
				OutputBorrowing(page, pageSize);
				cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
				cout << "请选择:";
				continue;
			}
		}
		case 2: {
			if (page == 1) {
				cout << "该页为第一页";
				cout << "请选择:";

				continue;
			}
			else {
				page -= 1;
				system("cls");
				OutputBorrowing(page, pageSize);
				cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
				cout << "请选择:";
				continue;
			}
		}
		case 3: {
			cout << "请输入页数:";
			cin >> page;
			while (page<1 || page>totalPages) {
				cout << "请重新输入:";
				cin >> page;
			}
			system("cls");
			OutputBorrowing(page, pageSize);
			cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
			cout << "请选择:";
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
			cout << "给你一次重新选择的机会\n" << endl;
			continue;
		}
		break;
	}
}

//根据id查看借书记录界面
void ViewBorrowingRecordById(int identity, int manageId,int readerId) {
	int totalDatas = record.DataNumberById(readerId);//总数据数
	int pageSize = 5;
	int totalPages = totalDatas / pageSize;//总页数
	if (totalDatas % pageSize > 0) {
		totalPages = totalPages + 1;
	}
	int page = 1;

	int s;
	system("cls");
	OutputBorrowing(page, pageSize);
	cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
	cout << "请选择:";

	while (cin >> s) {
		cout << totalPages << endl;
		switch (s)
		{
		case 1: {
			if (page == totalPages) {
				cout << "该页为最后一页";
				cout << "请选择:";
				continue;
			}
			else {
				page += 1;
				system("cls");
				OutputBorrowing(page, pageSize);
				cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
				cout << "请选择:";
				continue;
			}
		}
		case 2: {
			if (page == 1) {
				cout << "该页为第一页";
				cout << "请选择:";
				continue;
			}
			else {
				page -= 1;
				system("cls");
				OutputBorrowing(page, pageSize);
				cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
				cout << "请选择:";
				continue;
			}
		}
		case 3: {
			cout << "请输入页数:";
			cin >> page;
			while (page<1 || page>totalPages) {
				cout << "请重新输入:";
				cin >> page;
			}
			system("cls");
			OutputBorrowing(page, pageSize);
			cout << "1.下一页  2.上一页  3.选择页数  4.退出  当前页数:" << page << "总页数:" << totalPages << endl;
			cout << "请选择:";
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
			cout << "给你一次重新选择的机会\n" << endl;
			continue;
		}
		break;
	}
}