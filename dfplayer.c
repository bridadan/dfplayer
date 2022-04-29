#include <assert.h>

#include "dfplayer.h"

typedef enum {
    DFPLAYER_CMD_NEXT_TRACK = 1,
    DFPLAYER_CMD_PREV_TRACK,
    DFPLAYER_CMD_SEL_TRACK,
    DFPLAYER_CMD_INC_VOL,
    DFPLAYER_CMD_DEC_VOL,
    DFPLAYER_CMD_SET_VOL,
    DFPLAYER_CMD_SET_EQ,
    DFPLAYER_CMD_SET_MODE,
    DFPLAYER_CMD_SET_SRC,
    DFPLAYER_CMD_SUSPEND,
    DFPLAYER_CMD_RESUME,
    DFPLAYER_CMD_RESET,
    DFPLAYER_CMD_PLAY,
    DFPLAYER_CMD_PAUSE,
    DFPLAYER_CMD_SET_FOLDER,
    DFPLAYER_CMD_ENABLE_LOOP,
    DFPLAYER_CMD_DISBALE_LOOP,
} dfplayer_cmd_t;

static bool dfplayer_send_command(
    dfplayer_t *self,
    dfplayer_cmd_t command,
    uint16_t data
) {
    uint8_t buffer[8];
    buffer[0] = 0x7E;
    buffer[1] = 0xFF;
    buffer[2] = 0x06;
    buffer[3] = command & 0xFF;
    buffer[4] = 0x00;
    buffer[5] = data >> 8;
    buffer[6] = data & 0xFF;
    buffer[7] = 0xEF;

    assert(self->send_bytes);
    return self->send_bytes(buffer, 8);
}

bool dfplayer_reset(dfplayer_t *self) {
    return dfplayer_send_command(self, DFPLAYER_CMD_RESET, 0);
}

bool dfplayer_set_eq(dfplayer_t *self, dfplayer_eq_t eq) {
    return dfplayer_send_command(self, DFPLAYER_CMD_SET_EQ, (uint16_t) (eq & 0xFFFF));
}

bool dfplayer_set_src(dfplayer_t *self, dfplayer_src_t src) {
    return dfplayer_send_command(self, DFPLAYER_CMD_SET_SRC, (uint16_t) (src & 0xFFFF));
}

bool dfplayer_set_mode(dfplayer_t *self, dfplayer_mode_t mode) {
    return dfplayer_send_command(self, DFPLAYER_CMD_SET_MODE, (uint16_t) (mode & 0xFFFF));
}

bool dfplayer_set_volume(dfplayer_t *self, uint16_t volume) {
    if (volume > 30) {
        volume = 30;
    }

    return dfplayer_send_command(self, DFPLAYER_CMD_SET_VOL, volume);
}

bool dfplayer_select_track(dfplayer_t *self, uint16_t track) {
    return dfplayer_send_command(self, DFPLAYER_CMD_SEL_TRACK, track);
}
