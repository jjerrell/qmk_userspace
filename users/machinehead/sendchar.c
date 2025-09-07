// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-3.0-or-later

#include "print.h"
#include "timer.h"

#ifdef VIRTSER_ENABLE
#    include "virtser.h"
#endif // VIRTSER_ENABLE

uint32_t sendchar_timer = 0;

int8_t drashna_sendchar(uint8_t c) {
    uint8_t ret    = 0;
    sendchar_timer = timer_read32();

    extern int8_t sendchar(uint8_t c);
    ret = sendchar(c);
#ifdef VIRTSER_ENABLE
    virtser_send(c);
#endif // VIRTSER_ENABLE
    return ret;
}