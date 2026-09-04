#ifndef COMMON_H
#define COMMON_H
#include <QString>
#include <qobject.h>
using namespace std;
struct ClientInfo{
    int socket;
    string username;
};
enum status_code{
    status_OK,
    status_FAIL,
    status_EMPTY,
};
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
struct logindata
{
    const int type_struct=type_logindata;
    QString username ="error";
    QString password ="error";
    int status=status_EMPTY;
    friend QDataStream &operator>>(QDataStream&in,logindata& data){
        in>>data.username>>data.password>>data.flag_1>>data.flag_2;
        if(in.status()!=QDataStream::Ok){
            data.status=status_FAIL;
        }
        else  {
            data.status=status_OK;
        }
    return in;
    };
    int flag_1=0;
    int flag_2=0;

};
struct registerdata
{
    QString username = "error";
    QString password = "error";
};
#endif