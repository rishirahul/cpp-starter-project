/*
 * Copyright © 2024 Rishi Rahul <rishi@blitzfill.com>
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the “Software”), to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
*/

#include "Client.h"
#include "SocketLib.h"
#include "version.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
using namespace std;
//Client side
int main(int argc, char *argv[]) {
    std::cout << "starting: " <<  PROJECT_NAME << " version: " << PROJECT_VER <<  " githash: " << GIT_HASH << std::endl;
    //we need 2 things: ip address and port number, in that order
    if (argc != 3) {
        cerr << "Usage: ip_address port" << endl;
        exit(0);
    } //grab the IP address and port number
    char *serverIp = argv[1];
    int port = atoi(argv[2]);
    //create a message buffer
    char msg[1500];
    //setup a socket and connection tools
    struct hostent *host = gethostbyname(serverIp);
    sockaddr_in sendSockAddr;
    int clientSd = createSocket(sendSockAddr, host, port);
    //try to connect...
    int status = connect(clientSd,
                         (sockaddr * ) & sendSockAddr, sizeof(sendSockAddr));
    if (status < 0) {
        cout << "Error connecting to socket!" << endl;
        return -1;
    }
    cout << "Connected to the server!" << endl;
    int bytesRead, bytesWritten = 0;
    struct timeval start1, end1;
    gettimeofday(&start1, NULL);
    while (1) {
        cout << ">";
        string data;
        getline(cin, data);
        memset(&msg, 0, sizeof(msg));//clear the buffer
        strcpy(msg, data.c_str());
        if (data == "exit") {
            send(clientSd, (char *) &msg, strlen(msg), 0);
            break;
        }
        bytesWritten += send(clientSd, (char *) &msg, strlen(msg), 0);
        cout << "Awaiting server response..." << endl;
        memset(&msg, 0, sizeof(msg));//clear the buffer
        bytesRead += recv(clientSd, (char *) &msg, sizeof(msg), 0);
        if (!strcmp(msg, "exit")) {
            cout << "Server has quit the session" << endl;
            break;
        }
        cout << "Server: " << msg << endl;
    }
    gettimeofday(&end1, NULL);
    close(clientSd);
    cout << "********Session********" << endl;
    cout << "Bytes written: " << bytesWritten <<
         " Bytes read: " << bytesRead << endl;
    cout << "Elapsed time: " << (end1.tv_sec - start1.tv_sec)
         << " secs" << endl;
    cout << "Connection closed" << endl;
    return 0;
}