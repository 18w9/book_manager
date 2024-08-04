#include<string>
#include<iostream>//mysql 文件
#include<cstdbool>
#include<mysql.h>
#include<vector>

#include "str_code.h"
#include"menu.h"

MYSQL* con;
char sql[1024];
MYSQL_RES* res;
MYSQL_ROW row;
void InitMysqlClient() {
	con = mysql_init(NULL);
	//设置编码，以防止乱码
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "gbk");
	//连接
	if (mysql_real_connect(con, "127.0.0.1", "root",
		"wxzmysql", "book_manager", 3306, NULL, 0) == NULL) {
		fprintf(stderr, "数据库连接错误:%s\n", mysql_error(con));
		exit(1);
	}
	else cout << "连接成功" << endl;
}

using namespace std;

int main()
{
	InitMysqlClient();
	InitialMenu();
	
 	system("pause");
	return 0;
}
