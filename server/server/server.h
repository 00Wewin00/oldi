#ifndef SERVER_H
#define SERVER_H
#include <vector>
#include "../common.h"
#include <mutex>
using namespace std;
inline mutex global_clients;
inline vector<ClientInfo> clients;
void server();
#endif