// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "techworker.h"
#include "process_leader.h"
#include "version.h"
#include "action.h"

void          leader_start_keymap(void);
void          leader_start_secret(void);
bool          leader_end_keymap(void);
bool          leader_end_secret(void);
