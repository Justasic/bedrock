#include "server/bedrock.h"
#include "blocks/items.h"
#include "blocks/blocks.h"

struct item items[] = {
	{ITEM_NONE,               "",                   ITEM_FLAG_NONE},
	{ITEM_IRON_SHOVEL,        "Iron shovel",        ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_SHOVEL  | ITEM_FLAG_IRON    | ITEM_FLAG_STONE | ITEM_FLAG_WOOD},
	{ITEM_IRON_PICKAXE,       "Iron pickaxe",       ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_PICKAXE | ITEM_FLAG_IRON    | ITEM_FLAG_STONE | ITEM_FLAG_WOOD},
	{ITEM_IRON_AXE,           "Iron axe",           ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_AXE     | ITEM_FLAG_IRON    | ITEM_FLAG_STONE | ITEM_FLAG_WOOD},
	{ITEM_FLINT_AND_STEEL,    "Flint and steel",    ITEM_FLAG_DAMAGABLE},
	{ITEM_BOW,                "Bow",                ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_IRON_SWORD,         "Iron sword",         ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_SWORD   | ITEM_FLAG_IRON    | ITEM_FLAG_STONE | ITEM_FLAG_WOOD},
	{ITEM_WOODEN_SWORD,       "Wooden sword",       ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_SWORD   | ITEM_FLAG_WOOD},
	{ITEM_WOODEN_SHOVEL,      "Wooden shovel",      ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_SHOVEL  | ITEM_FLAG_WOOD},
	{ITEM_WOODEN_PICKAXE,     "Wooden pickaxe",     ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_PICKAXE | ITEM_FLAG_WOOD},
	{ITEM_WOODEN_AXE,         "Wooden axe",         ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_AXE     | ITEM_FLAG_WOOD},
	{ITEM_STONE_SWORD,        "Stone sword",        ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_SWORD   | ITEM_FLAG_STONE   | ITEM_FLAG_WOOD},
	{ITEM_STONE_SHOVEL,       "Stone shovel",       ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_SHOVEL  | ITEM_FLAG_STONE   | ITEM_FLAG_WOOD},
	{ITEM_STONE_PICKAXE,      "Stone pickaxe",      ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_PICKAXE | ITEM_FLAG_STONE   | ITEM_FLAG_WOOD},
	{ITEM_STONE_AXE,          "Stone axe",          ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_AXE     | ITEM_FLAG_STONE   | ITEM_FLAG_WOOD},
	{ITEM_DIAMOND_SWORD,      "Diamond sword",      ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_SWORD   | ITEM_FLAG_DIAMOND | ITEM_FLAG_IRON    | ITEM_FLAG_STONE | ITEM_FLAG_WOOD},
	{ITEM_DIAMOND_SHOVEL,     "Diamond shovel",     ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_SHOVEL  | ITEM_FLAG_DIAMOND | ITEM_FLAG_IRON    | ITEM_FLAG_STONE | ITEM_FLAG_WOOD},
	{ITEM_DIAMOND_PICKAXE,    "Diamond pickaxe",    ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_PICKAXE | ITEM_FLAG_DIAMOND | ITEM_FLAG_IRON    | ITEM_FLAG_STONE | ITEM_FLAG_WOOD},
	{ITEM_DIAMOND_AXE,        "Diamond axe",        ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_AXE     | ITEM_FLAG_DIAMOND | ITEM_FLAG_IRON    | ITEM_FLAG_STONE | ITEM_FLAG_WOOD},
	{ITEM_GOLD_SWORD,         "Gold sword",         ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_SWORD   | ITEM_FLAG_GOLD    | ITEM_FLAG_DIAMOND | ITEM_FLAG_IRON  | ITEM_FLAG_STONE | ITEM_FLAG_WOOD},
	{ITEM_GOLD_SHOVEL,        "Gold shovel",        ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_SHOVEL  | ITEM_FLAG_GOLD    | ITEM_FLAG_DIAMOND | ITEM_FLAG_IRON  | ITEM_FLAG_STONE | ITEM_FLAG_WOOD},
	{ITEM_GOLD_PICKAXE,       "Gold pickaxe",       ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_PICKAXE | ITEM_FLAG_GOLD    | ITEM_FLAG_DIAMOND | ITEM_FLAG_IRON  | ITEM_FLAG_STONE | ITEM_FLAG_WOOD},
	{ITEM_GOLD_AXE,           "Gold axe",           ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE | ITEM_FLAG_AXE     | ITEM_FLAG_GOLD    | ITEM_FLAG_DIAMOND | ITEM_FLAG_IRON  | ITEM_FLAG_STONE | ITEM_FLAG_WOOD},
	{ITEM_WOODEN_HOE,         "Wooden hoe",         ITEM_FLAG_DAMAGABLE | ITEM_FLAG_HOE         | ITEM_FLAG_WOOD},
	{ITEM_STONE_HOE,          "Stone hoe",          ITEM_FLAG_DAMAGABLE | ITEM_FLAG_HOE         | ITEM_FLAG_STONE   | ITEM_FLAG_WOOD},
	{ITEM_IRON_HOE,           "Iron hoe",           ITEM_FLAG_DAMAGABLE | ITEM_FLAG_HOE         | ITEM_FLAG_IRON    | ITEM_FLAG_STONE   | ITEM_FLAG_WOOD},
	{ITEM_DIAMOND_HOE,        "Diamond hoe",        ITEM_FLAG_DAMAGABLE | ITEM_FLAG_HOE         | ITEM_FLAG_DIAMOND | ITEM_FLAG_IRON    | ITEM_FLAG_STONE | ITEM_FLAG_WOOD},
	{ITEM_GOLD_HOE,           "Gold hoe",           ITEM_FLAG_DAMAGABLE | ITEM_FLAG_HOE         | ITEM_FLAG_GOLD    | ITEM_FLAG_DIAMOND | ITEM_FLAG_IRON  | ITEM_FLAG_STONE | ITEM_FLAG_WOOD},
	{ITEM_LEATHER_CAP,        "Leather cap",        ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_LEATHER_TUNIC,      "Leather tunic",      ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_LEATHER_PANTS,      "Leather pants",      ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_LEATHER_BOOTS,      "Leather boots",      ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_CHAIN_HELMET,       "Chain cap",          ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_CHAIN_CHESTPLATE,   "Chain chestplate",   ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_CHAIN_LEGGINGS,     "Chain leggings",     ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_CHAIN_BOOTS,        "Chain boots",        ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_IRON_HELMET,        "Iron cap",           ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_IRON_CHESTPLATE,    "Iron chestplate",    ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_IRON_LEGGINGS,      "Iron leggings",      ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_IRON_BOOTS,         "Iron boots",         ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_DIAMOND_HELMET,     "Diamond cap",        ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_DIAMOND_CHESTPLATE, "Diamond chestplate", ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_DIAMOND_LEGGINGS,   "Diamond leggings",   ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_DIAMOND_BOOTS,      "Diamond boots",      ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_GOLDEN_HELMET,      "Gold cap",           ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_GOLDEN_CHESTPLATE,  "Gold chestplate",    ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_GOLDEN_LEGGINGS,    "Gold leggings",      ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_GOLDEN_BOOTS,       "Gold boots",         ITEM_FLAG_DAMAGABLE | ITEM_FLAG_ENCHANTABLE},
	{ITEM_FISHING_ROD,        "Fishing rod",        ITEM_FLAG_DAMAGABLE},
	{ITEM_SHEARS,             "Shears",             ITEM_FLAG_DAMAGABLE}
};

static int item_compare(const enum item_type *id, const struct item *item)
{
	if (*id < item->id)
		return -1;
	else if (*id > item->id)
		return 1;
	return 0;
}

typedef int (*compare_func)(const void *, const void *);

struct item *item_find(enum item_type id)
{
	static struct item i;
	struct item *item = bsearch(&id, items, sizeof(items) / sizeof(struct item), sizeof(struct item), (compare_func) item_compare);

	if (item == NULL)
	{
		struct block *block = block_find(id);

		if (block != NULL)
		{
			i.id = id;
			i.name = block->name;
			i.flags = ITEM_FLAG_BLOCK;

			item = &i;
		}
	}

	return item;
}

struct item *item_find_or_create(enum item_type id)
{
	static struct item i;
	struct item *item = item_find(id);

	if (item == NULL)
	{
		bedrock_log(LEVEL_DEBUG, "item: Unrecognized item %d", id);

		i.id = id;
		i.name = "Unknown";
		i.flags = 0;

		item = &i;
	}

	return item;
}

struct item *item_find_by_name(const char *name)
{
	unsigned i;
	struct block *block;

	for (i = 0; i < sizeof(items) / sizeof(struct item); ++i)
	{
		struct item *item = &items[i];

		if (!strcmp(name, item->name))
			return item;
	}

	block = block_find_by_name(name);
	if (block != NULL)
		return item_find_or_create(block->id);

	return NULL;
}

