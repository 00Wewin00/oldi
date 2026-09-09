#ifndef DB_H
#define DB_H

// Обязательно нужны эти инклюды, иначе C++ не поймет std::string и std::vector в заголовке!
#include <qobject.h>
#include <string>
#include <QString>
#include <variant>
#include "common.h"
using namespace std;
int check_element(string db_open,string table,string SearchTerm,string key_1,string key_2,string filter_1,string filter_2,int count);
DbValue Select_element();
#endif