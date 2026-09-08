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
                    int result_sql_query =sqlite3_step(stmt);
                    switch(result_sql_query){
                        case SQLITE_OK:{
                            code=code_succes;
                            break;
                        }
                        case SQLITE_DONE:{
                            code =code_fail;
                            break;
                        }
                        default:{
                            code=code_eror;
                            break;
                        }
                    }
                }
                break;
            }
            case 1:{
                string sql="SELECT "+SearchTerm+" FROM "+table+" WHERE "+key_1+" = :sqlfilter_2;";
                if (sqlite3_prepare_v2(db,sql.c_str(),-1,&stmt,nullptr)==SQLITE_OK) {
                    int index_filter_1 = sqlite3_bind_parameter_index(stmt,":sqlfilter_1");
                    sqlite3_bind_text(stmt,index_filter_1,filter_1.c_str(),-1,SQLITE_STATIC);
                    int result_sql_query =sqlite3_step(stmt);
                    switch(result_sql_query){
                        case SQLITE_OK:{
                            code=code_succes;
                            break;
                        }
                        case SQLITE_DONE:{
                            code =code_fail;
                            break;
                        }
                        default:{
                            code=code_eror;
                            break;
                        }
                    }
                }
                break;
            }
            case 2:{
                string sql="SELECT "+SearchTerm+" FROM "+table+" WHERE "+key_1+" = :sqlfilter_2 AND "+key_2+"= :sqlfilter_2;";
                if (sqlite3_prepare_v2(db,sql.c_str(),-1,&stmt,nullptr)==SQLITE_OK) {
                    int index_filter_1 = sqlite3_bind_parameter_index(stmt,":sqlfilter_1");
                    int index_filter_2 = sqlite3_bind_parameter_index(stmt,":sqlfilter_2");
                    sqlite3_bind_text(stmt,index_filter_1,filter_1.c_str(),-1,SQLITE_STATIC);
                    sqlite3_bind_text(stmt,index_filter_2,filter_2.c_str(),-1,SQLITE_STATIC);
                    int result_sql_query =sqlite3_step(stmt);
                    switch(result_sql_query){
                        case SQLITE_OK:{
                            code=code_succes;
                            break;
                        }
                        case SQLITE_DONE:{
                            code =code_fail;
                            break;
                        }
                        default:{
                            code=code_eror;
                            break;
                        }
                    }
                }
                break;
            }
        }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return code;
    }
};