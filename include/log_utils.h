/**
 * Copyright 2023 Legytma Soluções Inteligentes LTDA
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * log_utils.h
 *
 *  Created on: Aug 13, 2018
 *      Author: Alex M. F. Silva
 */

#pragma once

#include "esp_log.h"
#include "sdkconfig.h"

#ifndef UNUSED
	#if defined(__GNUC__)
		#define UNUSED(x) x __attribute__((unused))
	#elif defined(__LCLINT__)
		#define UNUSED(x) /*@unused@*/ x
	#else
		#define UNUSED(x) x
	#endif
#endif

#define LOG_TAG(t) static const char* UNUSED(TAG) = t
#define LOG_TAG_FILE() static const char* UNUSED(TAG) = __LINE__

#define LOGV(...) ESP_LOGV(TAG, ##__VA_ARGS__)
#define LOGD(...) ESP_LOGD(TAG, ##__VA_ARGS__)
#define LOGI(...) ESP_LOGI(TAG, ##__VA_ARGS__)
#define LOGW(...) ESP_LOGW(TAG, ##__VA_ARGS__)
#define LOGE(...) ESP_LOGE(TAG, ##__VA_ARGS__)

#define LOG_BUFFER_HEXDUMP(d, s, l) ESP_LOG_BUFFER_HEXDUMP(TAG, d, s, l)

#define LOG_BUFFER_V(d, s) LOG_BUFFER_HEXDUMP(d, s, ESP_LOG_VERBOSE)
#define LOG_BUFFER_D(d, s) LOG_BUFFER_HEXDUMP(d, s, ESP_LOG_DEBUG)
#define LOG_BUFFER_I(d, s) LOG_BUFFER_HEXDUMP(d, s, ESP_LOG_INFO)
#define LOG_BUFFER_W(d, s) LOG_BUFFER_HEXDUMP(d, s, ESP_LOG_WARN)
#define LOG_BUFFER_E(d, s) LOG_BUFFER_HEXDUMP(d, s, ESP_LOG_ERROR)

#define STRINGIFY_LN_2(X) #X
#define STRINGIFY_LN(X)   STRINGIFY_LN_2(X)
#define STR_LN            STRINGIFY_LN(__LINE__)

#define LOGLV(...) ESP_LOGV(TAG ":" STR_LN, ##__VA_ARGS__)
#define LOGLD(...) ESP_LOGD(TAG ":" STR_LN, ##__VA_ARGS__)
#define LOGLI(...) ESP_LOGI(TAG ":" STR_LN, ##__VA_ARGS__)
#define LOGLW(...) ESP_LOGW(TAG ":" STR_LN, ##__VA_ARGS__)
#define LOGLE(...) ESP_LOGE(TAG ":" STR_LN, ##__VA_ARGS__)

#define LOG_BUFFER_HEXDUMP_L(d, s, l) \
	ESP_LOG_BUFFER_HEXDUMP(TAG ":" STR_LN, d, s, l)

#define LOG_BUFFER_LV(d, s) LOG_BUFFER_HEXDUMP_L(d, s, ESP_LOG_VERBOSE)
#define LOG_BUFFER_LD(d, s) LOG_BUFFER_HEXDUMP_L(d, s, ESP_LOG_DEBUG)
#define LOG_BUFFER_LI(d, s) LOG_BUFFER_HEXDUMP_L(d, s, ESP_LOG_INFO)
#define LOG_BUFFER_LW(d, s) LOG_BUFFER_HEXDUMP_L(d, s, ESP_LOG_WARN)
#define LOG_BUFFER_LE(d, s) LOG_BUFFER_HEXDUMP_L(d, s, ESP_LOG_ERROR)

#define LOG_FUN(l, m) LOG##l("%s%s:%d", __func__, m, __LINE__)

#define LOG_FUN_START(l) LOG_FUN(l, " start")
#define LOG_FUN_END(l)   LOG_FUN(l, " end")

#define LOG_FUN_START_V LOG_FUN_START(V)
#define LOG_FUN_START_D LOG_FUN_START(D)
#define LOG_FUN_START_I LOG_FUN_START(I)
#define LOG_FUN_START_W LOG_FUN_START(W)
#define LOG_FUN_START_E LOG_FUN_START(E)

#define LOG_FUN_END_V LOG_FUN_END(V)
#define LOG_FUN_END_D LOG_FUN_END(D)
#define LOG_FUN_END_I LOG_FUN_END(I)
#define LOG_FUN_END_W LOG_FUN_END(W)
#define LOG_FUN_END_E LOG_FUN_END(E)

// #define printf(m, ...) LOGD(m, ##__VA_ARGS__)

#define LOG_COND(lt, lf, c, t, f) \
	if (c) {                      \
		LOG##lt(t);               \
	} else {                      \
		LOG#lf(f);                  \
	}

#define LOG_COND_VV(c, t, f) LOG_COND(V, V, c, t, f)
#define LOG_COND_DV(c, t, f) LOG_COND(D, V, c, t, f)
#define LOG_COND_IV(c, t, f) LOG_COND(I, V, c, t, f)
#define LOG_COND_WV(c, t, f) LOG_COND(W, V, c, t, f)
#define LOG_COND_EV(c, t, f) LOG_COND(E, V, c, t, f)
#define LOG_COND_VD(c, t, f) LOG_COND(V, D, c, t, f)
#define LOG_COND_DD(c, t, f) LOG_COND(D, D, c, t, f)
#define LOG_COND_ID(c, t, f) LOG_COND(I, D, c, t, f)
#define LOG_COND_WD(c, t, f) LOG_COND(W, D, c, t, f)
#define LOG_COND_ED(c, t, f) LOG_COND(E, D, c, t, f)
#define LOG_COND_VI(c, t, f) LOG_COND(V, I, c, t, f)
#define LOG_COND_DI(c, t, f) LOG_COND(D, I, c, t, f)
#define LOG_COND_II(c, t, f) LOG_COND(I, I, c, t, f)
#define LOG_COND_WI(c, t, f) LOG_COND(W, I, c, t, f)
#define LOG_COND_EI(c, t, f) LOG_COND(E, I, c, t, f)
#define LOG_COND_VW(c, t, f) LOG_COND(V, W, c, t, f)
#define LOG_COND_DW(c, t, f) LOG_COND(D, W, c, t, f)
#define LOG_COND_IW(c, t, f) LOG_COND(I, W, c, t, f)
#define LOG_COND_WW(c, t, f) LOG_COND(W, W, c, t, f)
#define LOG_COND_EW(c, t, f) LOG_COND(E, W, c, t, f)
#define LOG_COND_VE(c, t, f) LOG_COND(V, E, c, t, f)
#define LOG_COND_DE(c, t, f) LOG_COND(D, E, c, t, f)
#define LOG_COND_IE(c, t, f) LOG_COND(I, E, c, t, f)
#define LOG_COND_WE(c, t, f) LOG_COND(W, E, c, t, f)
#define LOG_COND_EE(c, t, f) LOG_COND(E, E, c, t, f)

#define BIT_STR  "%d"
#define BYTE_STR BIT_STR BIT_STR BIT_STR BIT_STR BIT_STR BIT_STR BIT_STR BIT_STR
#define U8_STR   BYTE_STR
#define U16_STR  U8_STR U8_STR
#define U32_STR  U16_STR U16_STR
#define U64_STR  U32_STR U32_STR

#define PRINT_BIT(b, p) (uint8_t)((b & (1 << p)) >> p)
#define PRINT_BYTE(b)                                                   \
	PRINT_BIT(b, 7), PRINT_BIT(b, 6), PRINT_BIT(b, 5), PRINT_BIT(b, 4), \
		PRINT_BIT(b, 3), PRINT_BIT(b, 2), PRINT_BIT(b, 1), PRINT_BIT(b, 0)
#define PRINT_UU(u)  PRINT_BYTE(u)
#define PRINT_U16(u) PRINT_BYTE(u >> 8), PRINT_BYTE(u)
#define PRINT_U32(u) PRINT_U16(u >> 16), PRINT_U16(u)
#define PRINT_U64(u) PRINT_U32(u >> 32), PRINT_U32(u)

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif
