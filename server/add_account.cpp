#include "db.h"
#include <iostream>
#include <netinet/in.h>
#include <sqlite3.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>
#include <QString>
using namespace std;
int add_account(QString qusername, QString qpassword,int flag)
{
    int code=code_eror;
    string username = qusername.toStdString();
    string password = qpassword.toStdString();
    sqlite3 *db = nullptr;
    // Открываем тестовую базу
    if (sqlite3_open("test.db", &db) != SQLITE_OK) {
        cout << "Ошибка открытия базы!" << endl;
        return code_eror_OpenDb;
    }
    sqlite3_stmt *stmt = nullptr;
    if(flag==0){
        string sql = "INSERT OR IGNORE INTO user (username, password) VALUES (?, ?);";
        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) == SQLITE_OK) {
            sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);
            sqlite3_step(stmt);
            // Проверяем, была ли реально добавлена строка
            if (sqlite3_changes(db) > 0) {
                code=code_succes;
            } else {
                code=code_fail;
            }
        }
    }
    else if(flag==1){
        string sql = "UPDATE user SET password =? WHERE username =?;";
        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) == SQLITE_OK) {
            sqlite3_bind_text(stmt, 1, password.c_str(), -1,SQLITE_STATIC);
            sqlite3_bind_text(stmt, 2, username.c_str(), -1, SQLITE_STATIC);
            sqlite3_step(stmt);
            if (sqlite3_changes(db) > 0) {
                code=code_succes;
            } else {
                code=code_eror;
            }
        }
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return code;
}