#include "server/client.h"

extern int packet_keep_alive(bedrock_client *client, const unsigned char *buffer, size_t len);
extern int packet_login_request(bedrock_client *client, const unsigned char *buffer, size_t len);
extern int packet_handshake(bedrock_client *client, const unsigned char *buffer, size_t len);