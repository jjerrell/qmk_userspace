# Enabled unless explicitly disabled in the keymap
RGB_MATRIX_CUSTOM_USER ?= yes
ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
    ifeq ($(strip $(RGB_MATRIX_CUSTOM_USER)), yes)
        SRC += $(USER_PATH)/rgb/matrix/rgb_matrix.c
        CONFIG_H += $(USER_PATH)/rgb/matrix/config.h
        POST_CONFIG_H += $(USER_PATH)/rgb/matrix/config_post.h
    endif
endif
