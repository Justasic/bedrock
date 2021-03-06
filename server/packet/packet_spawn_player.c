#include "server/client.h"
#include "server/packet.h"
#include "server/packets.h"
#include "blocks/items.h"
#include "nbt/nbt.h"

void packet_send_spawn_player(struct client *client, struct client *c)
{
	bedrock_packet packet;
	uint32_t abs_x, abs_y, abs_z;
	int8_t y, p;
	struct item_stack *weilded_item;
	struct item *item;
	uint8_t b = 127;

	weilded_item = &client->inventory[INVENTORY_HOTBAR_START + client->selected_slot];
	if (weilded_item->count)
		item = item_find_or_create(weilded_item->id);
	else
		item = item_find_or_create(ITEM_NONE);

	abs_x = c->x * 32;
	abs_y = c->y * 32;
	abs_z = c->z * 32;

	y = (c->yaw / 360.0) * 256;
	p = (c->pitch / 360.0) * 256;

	packet_init(&packet, SERVER_SPAWN_PLAYER);

	packet_pack_varuint(&packet, c->id);
	packet_pack_string(&packet, c->name); // XXX uuid?
	packet_pack_string(&packet, c->name);
	packet_pack_int(&packet, &abs_x, sizeof(abs_x));
	packet_pack_int(&packet, &abs_y, sizeof(abs_y));
	packet_pack_int(&packet, &abs_z, sizeof(abs_z));
	packet_pack_int(&packet, &y, sizeof(y));
	packet_pack_int(&packet, &p, sizeof(p));
	packet_pack_int(&packet, &item->id, sizeof(item->id));
	packet_pack_int(&packet, &b, sizeof(b)); // XXX metadata

	client_send_packet(client, &packet);

	packet_send_entity_head_look(client, c);
}
