#include "server/client.h"
#include "server/packet.h"

void packet_send_change_game_state(struct client *client, uint8_t reason, float gamemode)
{
	bedrock_packet packet;

	packet_init(&packet, SERVER_CHANGE_GAME_STATE);

	packet_pack_int(&packet, &reason, sizeof(reason));
	packet_pack_int(&packet, &gamemode, sizeof(gamemode));
	client_send_packet(client, &packet);
}

