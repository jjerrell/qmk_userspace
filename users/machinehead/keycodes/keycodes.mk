ifeq ($(strip $(PER_KEY_TAPPING)), yes)
    OPT_DEFS += -DPER_KEY_TAPPING
endif
CONFIG_H += $(USER_PATH)/keycodes/config.h

UNICODE_ENABLE        := no
UNICODEMAP_ENABLE     := no
UCIS_ENABLE           := no
ifeq ($(strip $(UNICODE_COMMON)), yes)
    OPT_DEFS += -DCUSTOM_UNICODE_ENABLE
    SRC += $(USER_PATH)/keycodes/unicode.c
endif

ifeq ($(strip $(LEADER_ENABLE)), yes)
    SRC += $(USER_PATH)/keycodes/leader.c
endif