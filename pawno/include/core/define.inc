new global[4096];

#define or ||
#define and &&
#define f format
#define sendDebugMessage(%0,%1,%2) format(global, 144, %1, %2), SendClientMessage(%0, COLOR_RED, global)

// colors:

#define COLOR_RED 0xFF6347FF