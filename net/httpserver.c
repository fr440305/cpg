#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>

const char RESPONSE_PACKAGE[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html;\r\n\r\nhello, world";
const int PORT_NUMBER = 9999;

int main () {
	struct sockaddr_in server_addr, cli_addr;
	char buffer[256] = "";
	int sock_id = 0;
	int new_sock_id = 0;
	int cli_len = sizeof(cli_addr);
	int accept_amount = 1;

	if ((sock_id = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("SOCKET FAIL.");
		return 0;
	}
	printf("SOCK NUM = %d", sock_id);

	bzero( (void *)&server_addr, sizeof(server_addr)); //clean it.
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(PORT_NUMBER);
	if ( bind(sock_id, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		printf("BIND ERROR");
	}

	printf("BIND GOOD\n");

	listen(sock_id, 5);
	printf("LISTEN GOOD\n");

	while ((new_sock_id = accept( sock_id, (struct sockaddr*)&cli_addr, (socklen_t*)&cli_len)) >= 0) {
		/* read(new_sock_id, buffer, 255); */
		recv(new_sock_id, buffer, 255, 0);
		printf("AcceptAmount: %d, Content:\n%s\n\n", accept_amount, buffer);
		/*if ( write(new_sock_id, RESPONSE_PACKAGE, strlen(RESPONSE_PACKAGE)) < 0) {*/
		if ( send(new_sock_id, RESPONSE_PACKAGE, strlen(RESPONSE_PACKAGE), 0) < 0) {
			printf("ERROR ON WRITING");
		}
		/* shutdown(sock_id, SHUT_RDWR); */
		/* shutdown(new_sock_id, SHUT_RDWR); */
		close(new_sock_id);
		accept_amount ++;
	}
	return 0;
}
