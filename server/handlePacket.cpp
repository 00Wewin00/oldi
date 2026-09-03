#include "logic.h"
#include "db.h"
#include <iostream>
#include <mutex>
#include <qobject.h>
#include <string>
#include <thread>
#include <QString>
#include <QIODevice>
using namespace std;
int handlePacket(QByteArray block){
    int type_struct;
    QDataStream in(&block,QIODevice::ReadOnly);
    in >> type_struct;
    switch(type_struct){
        case type_logindata:{
            logindata buffer_struct;
            in>>buffer_struct;
            if(in.status()!=QDataStream::Ok){
                return code_eror_IncompleteData;
            int result_check_account =check_account(buffer_struct.username, buffer_struct.password);
            switch(result_check_account){
                case code_succes: {
                // * dobawit esli polzowtel wwel horoszyj parol i imja  
                    break;
                }
            }
            }
            break;
        }
        default:

        break;
    }

}