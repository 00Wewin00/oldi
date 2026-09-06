#include "logic.h"
#include "common.h"
#include <qobject.h>
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
            
            }
            
            break;
        }
        default:
        break;
    }
    // ! Need to add "return int"
}