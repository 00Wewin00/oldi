#include "../db.h"
#include "../common.h"
#include <iostream>
#include <netinet/in.h>
#include <sqlite3.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>
#include <sqlite3.h>
using namespace std;
int check_element(string db_open,string table,string SearchTerm,string key_1,string key_2,string filter_1,string filter_2,int count){
    int code=code_eror;
    sqlite3 *db = nullptr;
    // Открываем тестовую базу
    if (sqlite3_open(db_open.c_str(), &db) != SQLITE_OK) {
        cout << "Ошибка открытия базы!" << endl;
        return code_eror_OpenDb;
    }
    else{
        sqlite3_stmt * stmt = nullptr;
        switch(count){
            case 0:{
                string sql="SELECT "+SearchTerm+" FROM "+table+";";
                if (sqlite3_prepare_v2(db,sql.c_str(),-1,&stmt,nullptr)==SQLITE_OK) {
                
                }
                break;
            }
            case 1:{
                string sql="SELECT "+SearchTerm+" FROM "+table+" WHERE "+key_1+" = ?;";
                if (sqlite3_prepare_v2(db,sql.c_str(),-1,&stmt,nullptr)==SQLITE_OK) {
                
                }
                break;
            }
            case 2:{
                string sql="SELECT "+SearchTerm+" FROM "+table+" WHERE "+key_1+" = ? AND "+key_2+"= ?;";
                if (sqlite3_prepare_v2(db,sql.c_str(),-1,&stmt,nullptr)==SQLITE_OK) {
                
                }
                break;
            }
        }
    }
};