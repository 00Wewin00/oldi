#include "db.h"
#include "common.h"
#include "logic.h"
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <mutex>
#include <netinet/in.h>
#include <qcontainerfwd.h>
#include <qstringview.h>
#include <sqlite3.h>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>
#include <vector>
#include <variant>
#include <QString>
#include <QIODevice>
using namespace std;
mutex clients_mutex;
void handle_auth(int client_socket, vector<ClientInfo> &client){
    bool login = true;
    while (login) {
        uint32_t packet_size = 0;
        uint32_t byet_result=0;
        while(byet_result!=4){
        int byet = recv(client_socket, &packet_size, sizeof(int), 0);
        if (byet <= 0) {
        return;
        }
        byet_result+=byet;
    }
        if (packet_size > 1024 * 64){
            return;
        }
        QByteArray block;
        block.resize(packet_size);
        uint32_t body_read=0;
        while(body_read>packet_size){
            int byet= recv(client_socket,block.data()+body_read , packet_size-body_read, 0);
            if (byet>=0) return;
            body_read+=byet;
        }
        handlePacket(block);
    }
}
void podkluczenie(vector<ClientInfo> &client, int serverfd){
    if (listen(serverfd, 5) < 0) {
        cout << "Ошибка при вызове listen!\n";
        return;
    }
    cout << "Сервер слушает порт и ждет клиентов...\n";
    while (true) {
        int client_socket = accept(serverfd, nullptr, nullptr);
        thread reg(handle_auth, client_socket, ref(client));
        reg.detach();
    }
}
int main()
{
    // 1. Создаем "телефонный аппарат"
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    // 2. Настраиваем номер (порт 8080)
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    // 3. Подключаем аппарат к розетке
    bind(server_fd, (struct sockaddr *) &address, sizeof(address));
    // 4. Переводим в режим "жду звонка"
    vector<ClientInfo> clients;
    thread prosluszka(podkluczenie, ref(clients), server_fd);
    prosluszka.detach();
    //close(clients);
    while (true) {
        sleep(1);
    }
    close(server_fd);
    return 0;
}