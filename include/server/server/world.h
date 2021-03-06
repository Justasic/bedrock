#ifndef BEDROCK_SERVER_WORLD_H
#define BEDROCK_SERVER_WORLD_H

#include "util/list.h"
#include "nbt/tag.h"

#include <limits.h>

struct world
{
	char name[128];
	char path[PATH_MAX];
	nbt_tag *data;
	bedrock_list regions;

	int64_t creation;
	int64_t time;
};

extern bedrock_list world_list;

extern struct world *world_create(const char *name, const char *path);
extern bool world_load(struct world *world);
extern void world_save(struct world *world);
extern void world_save_all();
extern void world_free(struct world *world);
extern struct world *world_find(const char *name);

#endif // BEDROCK_SERVER_WORLD_H
