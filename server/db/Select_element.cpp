#include "../db.h"
#include "../common.h"
#include <sqlite3.h>
#include <string>
#include <sqlite3.h>
using namespace std;
DbValue Select_element(string db_open,string table,string SearchTerm,string key_1,string key_2,string filter_1,string filter_2,int count){
    int code=code_eror;
    sqlite3 *db = nullptr;
    // Открываем тестовую базу
    if (sqlite3_open(db_open.c_str(), &db) != SQLITE_OK) {
        return code_eror_OpenDb;
    }
    else{
        sqlite3_stmt * stmt = nullptr;
    }
    return 0;
}