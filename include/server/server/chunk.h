#ifndef BEDROCK_SERVER_CHUNK_H
#define BEDROCK_SERVER_CHUNK_H

#include "server/bedrock.h"
#include "util/buffer.h"

struct bedrock_chunk
{
	/* Column this chunk is in */
	struct bedrock_column *column;
	/* Y coordinate */
	uint8_t y;

	/* True if this chunk is modified in memory */
	bool modified;

	/* These are pointers into the NBT structure for the column */
	uint8_t *blocks;
	uint8_t *data;
	uint8_t *skylight;
	uint8_t *blocklight;
};

extern struct bedrock_chunk *chunk_create(struct bedrock_column *column, uint8_t y);
extern struct bedrock_chunk *chunk_load(struct bedrock_column *column, uint8_t y, nbt_tag *tag);
extern uint8_t *chunk_get_block(struct bedrock_chunk *chunk, int32_t x, uint8_t y, int32_t z);
extern void chunk_free(struct bedrock_chunk *chunk);
extern struct bedrock_chunk *find_chunk_which_contains(struct bedrock_world *world, int32_t x, uint8_t y, int32_t z);

#endif // BEDROCK_SERVER_CHUNK_H