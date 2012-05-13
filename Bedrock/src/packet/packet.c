#include "server/bedrock.h"
#include "packet/packet.h"
#include "packet/packet_handler.h"
#include "util/endian.h"

static struct c2s_packet_handler
{
	uint8_t id;
	uint8_t len;
	int (*handler)(bedrock_client *, const unsigned char *buffer, size_t len);
} packet_handlers[] = {
	{KEEP_ALIVE,    5,  packet_keep_alive},
	{LOGIN_REQUEST, 20, packet_login_request}
};

static int packet_compare(const uint8_t *id, const struct c2s_packet_handler *handler)
{
	if (*id < handler->id)
		return -1;
	else if (*id > handler->id)
		return 1;
	return 0;
}

int packet_parse(bedrock_client *client, const unsigned char *buffer, size_t len)
{
	uint8_t id = *buffer;
	int i;

	struct c2s_packet_handler *handler = bsearch(&id, packet_handlers, sizeof(packet_handlers) / sizeof(struct c2s_packet_handler), sizeof(struct c2s_packet_handler), packet_compare);
	if (handler == NULL)
	{
		bedrock_log(LEVEL_WARN, "Unrecognized packet 0x%x from %s, dropping client", id, bedrock_client_get_ip(client));
		bedrock_client_exit(client);
		return -1;
	}

	if (len < handler->len)
	{
		bedrock_log(LEVEL_WARN, "Invalid packet 0x%x from %s - paylad too short, dropping client", id, bedrock_client_get_ip(client));
		bedrock_client_exit(client);
		return -1;
	}

	i = handler->handler(client, buffer, len);

	if (i <= 0)
	{
		bedrock_log(LEVEL_WARN, "Invalid packet 0x%x from %s - invalid format, dropping client", id, bedrock_client_get_ip(client));
		bedrock_client_exit(client);
		return -1;
	}

	return i;
}

int packet_read_int(const unsigned char *buffer, size_t offset, void *dest, size_t dest_size)
{
	memcpy(dest, buffer + offset, dest_size);
	convert_from_big_endian(dest, dest_size);
	return dest_size;
}
