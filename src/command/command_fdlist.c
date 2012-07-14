#include "server/bedrock.h"
#include "server/command.h"
#include "util/fd.h"

#include <sys/time.h>
#include <sys/resource.h>

void command_fdlist(struct bedrock_client *client, int bedrock_attribute_unused argc, const char bedrock_attribute_unused **argv)
{
	bedrock_node *node;
	int engines = 0, files = 0, sockets = 0, pipes = 0, total = 0;
	struct rlimit rlim;

	bedrock_mutex_lock(&fdlist_mutex);
	LIST_FOREACH(&fdlist, node)
	{
		struct bedrock_fd *fd = node->data;
		char *type = "Unknown";

		switch (fd->type)
		{
			case FD_ENGINE:
				type = "FD Engine";
				++engines;
				break;
			case FD_FILE:
				type = "File";
				++files;
				break;
			case FD_SOCKET:
				type = "Socket";
				++sockets;
				break;
			case FD_PIPE:
				type = "Pipe";
				++pipes;
				break;
			default:
				break;
		}

		++total;

		command_reply(client, "#%d - %s - %s", fd->fd, type, fd->desc);
	}
	bedrock_mutex_unlock(&fdlist_mutex);

	command_reply(client, "Total: %d open FDs, %d engine, %d files, %d pipes, and %d sockets", total, engines, files, pipes, sockets);

	if (!getrlimit(RLIMIT_NOFILE, &rlim))
		command_reply(client, "Soft limit: %d, Hard limit: %d", rlim.rlim_cur, rlim.rlim_max);
}
