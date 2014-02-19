#ifndef USYNC_H
#define USYNC_H

#if SYNC_PLAYER

#include "sync-data.h"

extern float usync_values[SYNC_TRACK_COUNT];

/* tiny api */
#define usync_init() 1
void usync_update(float t);
#define usync_get_val(x) usync_values[x]

#else /* !SYNC_PLAYER */

#include "../lib/sync.h"

extern struct sync_device *usync_dev;
extern float usync_time;

int usync_init(void);
void usync_update(float t);
#define usync_get_val(track) sync_get_val(sync_get_track(usync_dev, "track_" #track), usync_time)

/* implement these yourself */
extern struct sync_cb usync_cb;
extern void *usync_data;

#endif /* !SYNC_PLAYER */

#endif /* !defined(USYNC_H) */
