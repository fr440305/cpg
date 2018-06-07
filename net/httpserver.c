#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>

const char RSP[][] = {
	"HTTP/1.1 200 OK",
	"Content-Type: text/html;",
	"",
	"hello, world"
};

typedef struct {
	int srv_sk_id;
	struct sockaddr_in srv_addr;
} HttpServer;

/* # Creates a new http server.
 * @portnum: The port number that the server is listen to
 * @ret: the final http server
 *
 * It returns the error number */
int http_server_new(int portnum, HttpServer* ret) {
	int err = 0;

	memset((void*)(ret), 0, sizeof(HttpServer));
	/* create a new socket: */
	if ((ret->srv_sk_id = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		err = -1;
	/* set the address: */
	ret->srv_addr.sin_family = AF_INET;
	ret->srv_addr.sin_addr.s_addr = INADDR_ANY;
	ret->srv_addr.sin_port = htons(portnum);
	/* bind the address with the socket: */
	if (bind(
		ret->srv_sk_id,
		(struct sockaddr*)&(ret->srv_addr),
		sizeof(ret->srv_addr)) < 0
	) err = -2;

	return err;
}

http_server_set_url_handler() {
}

/* */
int http_server_listen(HttpServer* s) {
	if (listen(s->srv_sk_id, 5) != 0) {
		return -1;
	}
	return 0; /* good */
}

/* */
int http_server_close(HttpServer* server) {
}


int main (int argc, char** argv) {
	struct sockaddr_in server_addr, cli_addr;
	char buffer[256] = "";
	int srvsk = 0;
	int clisk = 0;
	int clisk_len = sizeof(cli_addr);
	int accept_amount = 1;

	if ((sock_id = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("SOCKET FAIL.");
		return 0;
	}
	printf("SOCK NUM = %d", sock_id);

	bzero( (void *)&server_addr, sizeof(server_addr));
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
		recv(new_sock_id, buffer, 255, 0);
		printf("AcceptAmount: %d, Content:\n%s\n\n", accept_amount, buffer);
		if ( send(new_sock_id, RESPONSE_PACKAGE, strlen(RESPONSE_PACKAGE), 0) < 0) {
			printf("ERROR ON WRITING");
		}
		close(new_sock_id);
		accept_amount ++;
	}
	return 0;
}
