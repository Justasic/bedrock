#include "server/client.h"
#include "server/packet.h"

void packet_send_player_list_item(struct client *client, struct client *c, uint8_t online)
{
	bedrock_packet packet;

	packet_init(&packet, SERVER_PLAYER_LIST);

	packet_pack_string(&packet, c->name);
	packet_pack_int(&packet, &online, sizeof(online));
	packet_pack_int(&packet, &c->ping, sizeof(c->ping));

	client_send_packet(client, &packet);
}
