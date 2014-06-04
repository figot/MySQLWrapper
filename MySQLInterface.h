#ifndef __MYSQL_INTERFACE_H__
#define __MYSQL_INTERFACE_H__

#include "winsock.h"
#include <iostream>
#include <string>
#include "mysql.h"
#include <vector>
#include <string>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "libmysql.lib")
using namespace std;

class MySQLInterface
{
public:  
	MySQLInterface();
	virtual ~MySQLInterface();

	bool connectMySQL(char* server, char* username, char* password, char* database,int port);
	bool createDatabase(std::string& dbname);
	bool createdbTable(const std::string& query);

	void errorIntoMySQL();
	bool writeDataToDB(string queryStr);
	bool getDatafromDB(string queryStr, std::vector<std::vector<std::string> >& data);
	void closeMySQL();

public:
	int errorNum;                    //错误代号
	const char* errorInfo;             //错误提示

private:
	MYSQL mysqlInstance;                      //MySQL对象，必备的一个数据结构
	MYSQL_RES *result;                 //用于存放结果 建议用char* 数组将此结果转存
};

#endif