#include "server/client.h"
#include "server/packet.h"

int packet_confirm_transaction(struct client bedrock_attribute_unused *client, bedrock_packet *p)
{
	uint8_t b;
	uint16_t s;

	packet_read_int(p, &b, sizeof(b));
	packet_read_int(p, &s, sizeof(s));
	packet_read_int(p, &b, sizeof(b));

	return ERROR_OK;
}

void packet_send_confirm_transaction(struct client *client, uint8_t window, int16_t action_number, uint8_t accepted)
{
	bedrock_packet packet;

	packet_init(&packet, SERVER_CONFIRM_TRANSACTION);

	packet_pack_int(&packet, &window, sizeof(window));
	packet_pack_int(&packet, &action_number, sizeof(action_number));
	packet_pack_int(&packet, &accepted, sizeof(accepted));

	client_send_packet(client, &packet);
}
