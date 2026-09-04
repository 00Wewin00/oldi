#include "../db.h"
#include <iostream>
#include <netinet/in.h>
#include <sqlite3.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>
#include <QString>
using namespace std;

int check_account(QString qusername,QString qpassword){
    int code=code_eror;
    string username = qusername.toStdString();
    string password = qpassword.toStdString();
    sqlite3 *db = nullptr;
    // Открываем тестовую базу
    if (sqlite3_open("test.db", &db) != SQLITE_OK) {
        cout << "Ошибка открытия базы!" << endl;
        return code_eror_OpenDb;
    }
    else{
    string sql = "SELECT id FROM user WHERE username = ? AND password = ? ;";
    sqlite3_stmt *stmt = nullptr;
    int status = 0;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) == SQLITE_OK) {
        sqlite3_bind_text(stmt,1,username.c_str(),-1,SQLITE_STATIC);
        sqlite3_bind_text(stmt,2,password.c_str(),-1,SQLITE_STATIC);
        if (sqlite3_step(stmt) == SQLITE_ROW) {
        // 🔥 ЭЛЕМЕНТ НАШЕЛСЯ!
            code = code_succes;
        } else {
            // ❌ Элемент НЕ найден
            code=code_fail;
        }
    sqlite3_finalize(stmt);
    }
}sqlite3_close(db);
return code;
}