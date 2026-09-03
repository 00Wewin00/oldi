#ifndef DB_H
#define DB_H

// Обязательно нужны эти инклюды, иначе C++ не поймет std::string и std::vector в заголовке!
#include <qobject.h>
#include <string>
#include <QString>
#include <variant>
using namespace std;
enum Typesdata
{
    type_logindata,
    type_register
};
enum code_result{
    code_succes,
    code_fail,
    code_eror,
    code_eror_OpenDb,
    code_eror_IncompleteData
};
enum status_code{
    status_OK,
    status_FAIL,
    status_EMPTY,
};
struct ClientInfo
{
    int socket;
    string username;
};
struct logindata
{
    const int type_struct=type_logindata;
    QString username ="error";
    QString password ="error";
    int status=status_EMPTY;
    friend QDataStream &operator>>(QDataStream&in,logindata& data){
        in>>data.username>>data.password;
        if(in.status()!=QDataStream::Ok){
            data.status=status_FAIL;
        }
        else  {
            data.status=status_OK;
        }
    return in;
    };

};
struct registerdata
{
    QString username = "error";
    QString password = "error";
};
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