#include "server/client.h"
#include "server/packet.h"

int packet_client_settings(struct client bedrock_attribute_unused *client, const bedrock_packet *packet)
{
	int offset = PACKET_HEADER_LENGTH;
	char locale[BEDROCK_MAX_STRING_LENGTH];
	uint8_t view_distance, chat_flags, difficulty, cape;

	packet_read_string(packet, &offset, locale, sizeof(locale));
	packet_read_int(packet, &offset, &view_distance, sizeof(view_distance));
	packet_read_int(packet, &offset, &chat_flags, sizeof(chat_flags));
	packet_read_int(packet, &offset, &difficulty, sizeof(difficulty));
	packet_read_int(packet, &offset, &cape, sizeof(cape));

	return offset;
}
