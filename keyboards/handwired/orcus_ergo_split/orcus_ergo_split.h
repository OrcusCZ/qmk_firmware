/* Copyright 2021 Orcus
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    LB00, LB01, LB02, LB03, LB04, LB05, LB06, RB00, RB01, RB02, RB03, RB04, RB05, RB06, \
    LB10, LB11, LB12, LB13, LB14, LB15, LB16, RB10, RB11, RB12, RB13, RB14, RB15, RB16, \
    LB20, LB21, LB22, LB23, LB24, LB25, LB26, RB20, RB21, RB22, RB23, RB24, RB25, RB26, \
    LB30, LB31, LB32, LB33, LB34, LB35, LENC, RENC, RB31, RB32, RB33, RB34, RB35, RB36, \
    LB40, LB41, LB42, LB43, LB44,                         RB42, RB43, RB44, RB45, RB46, \
                LT02, LT03,                                     RT00, RT01, \
                LT12, LT13,                                     RT10, RT11, \
    LT20, LT21, LT22, LT23,                                     RT20, RT21, RT22, RT23 \
) { \
    { LB00, LB01, LB02, LB03, LB04, LB05, LB06 }, \
    { LB10, LB11, LB12, LB13, LB14, LB15, LB16 }, \
    { LB20, LB21, LB22, LB23, LB24, LB25, LB26 }, \
    { LB30, LB31, LB32, LB33, LB34, LB35, LENC }, \
    { LB40, LB41, LB42, LB43, LB44, LT02, LT03 }, \
    { KC_NO, LT20, LT21, LT22, LT23, LT12, LT13 }, \
    { RB00, RB01, RB02, RB03, RB04, RB05, RB06 }, \
    { RB10, RB11, RB12, RB13, RB14, RB15, RB16 }, \
    { RB20, RB21, RB22, RB23, RB24, RB25, RB26 }, \
    { RB31, RB32, RB33, RB34, RB35, RB36, RENC }, \
    { RT00, RT01, RB42, RB43, RB44, RB45, RB46 }, \
    { RT10, RT11, RT20, RT21, RT22, RT23, KC_NO } \
}
