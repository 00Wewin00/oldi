#ifndef DB_H
#define DB_H

// Обязательно нужны эти инклюды, иначе C++ не поймет std::string и std::vector в заголовке!
#include <qobject.h>
#include <string>
#include <QString>
#include <variant>
#include "common.h"
using namespace std;

using Packet_data =variant<logindata,registerdata>;
struct Packet 
{
    int type;
    Packet_data Data_info;
};
// Объявление функции (сигнатура)
int add_account(QString qusername, QString qpassword,int flag);
int check_account(QString qusername,QString qpassword);
#endif