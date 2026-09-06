#ifndef DB_H
#define DB_H

// Обязательно нужны эти инклюды, иначе C++ не поймет std::string и std::vector в заголовке!
#include <qobject.h>
#include <string>
#include <QString>
#include <variant>
#include "common.h"
using namespace std;
int check_element(string db,string collune,string SearchTerm,string filter_1,string filter_2,int count);
#endif