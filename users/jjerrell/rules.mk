SRC += $(USER_PATH)/jjerrell.c

ifneq ($(strip $(NO_SECRETS)), yes)
    ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
        SRC += secrets.c
    endif
    ifeq ($(strip $(NO_SECRETS)), lite)
        OPT_DEFS += -DNO_SECRETS
    endif
endif

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
    SRC += $(USER_PATH)/lighting/rgb_custom.c
endif

LEADER_ENABLE = yes
EXTRAKEY_ENABLE = yes
AUTOCORRECT_ENABLE = yes
CAPS_WORD_ENABLE = yes

# space savers
LTO_ENABLE = yes

# reduce firmware size -- enable where needed
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
