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
#include "SocketLib.h"

int createSocket(sockaddr_in &sockAddr, struct hostent *host, int port) {
    bzero((char *) &sockAddr, sizeof(sockAddr));
    sockAddr.sin_family = AF_INET;
    if (host) {
        sockAddr.sin_addr.s_addr =
                inet_addr(inet_ntoa(*(struct in_addr *) *host->h_addr_list));
    }
    else {
        sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    }
    sockAddr.sin_port = htons(port);
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    return sd;
}
