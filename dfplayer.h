#ifndef INC_DFPLAYER_H_
#define INC_DFPLAYER_H_

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    DFPLAYER_EQ_NORMAL = 0,
    DFPLAYER_EQ_POP,
    DFPLAYER_EQ_ROCK,
    DFPLAYER_EQ_JAZZ,
    DFPLAYER_EQ_CLASSIC,
    DFPLAYER_EQ_BASE, // BASS?
} dfplayer_eq_t;

typedef enum {
    DFPLAYER_SRC_USB = 0,
    DFPLAYER_SRC_SD_CARD,
    DFPLAYER_SRC_AUX,
    DFPLAYER_SRC_SLEEP,
    DFPLAYER_SRC_FLASH,
} dfplayer_src_t;

typedef enum {
    DFPLAYER_MODE_SINGLE_PLAY = 0,
    DFPLAYER_MODE_FOLDER_REPEAT,
    DFPLAYER_MODE_SINGLE_REPEAT,
    DFPLAYER_MODE_RANOM,
} dfplayer_mode_t;

typedef struct {
    bool (*send_bytes)(uint8_t *, uint32_t);
} dfplayer_t;

bool dfplayer_reset(dfplayer_t *self);
bool dfplayer_set_eq(dfplayer_t *self, dfplayer_eq_t eq);
bool dfplayer_set_src(dfplayer_t *self, dfplayer_src_t src);
bool dfplayer_set_mode(dfplayer_t *self, dfplayer_mode_t mode);
bool dfplayer_set_volume(dfplayer_t *self, uint16_t volume);
bool dfplayer_select_track(dfplayer_t *self, uint16_t track);

#endif // INC_DFPLAYER_H_
