/***************************************************************************
 *   Copyright (C) YEAR~YEAR by Your Name                                  *
 *   your-email@address.com                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcitx/ime.h>
#include <fcitx-config/fcitx-config.h>
#include <fcitx-config/xdg.h>
#include <fcitx-utils/log.h>
#include <fcitx-utils/utils.h>
#include <fcitx-utils/utf8.h>
#include <fcitx/instance.h>
#include <fcitx/context.h>
#include <fcitx/module.h>
#include <fcitx/hook.h>
#include <libintl.h>

#include "config.h"
#include "example-internal.h"

static void *FcitxExampleCreate(FcitxInstance *instance);
static void FcitxExampleDestroy(void *arg);
static void FcitxExampleReloadConfig(void *arg);
CONFIG_DEFINE_LOAD_AND_SAVE(Example, FcitxExampleConfig, "fcitx-example")
DECLARE_ADDFUNCTIONS(Example)

FCITX_DEFINE_PLUGIN(fcitx_spell, module, FcitxModule) = {
    .Create = FcitxExampleCreate,
    .Destroy = FcitxExampleDestroy,
    .SetFD = NULL,
    .ProcessEvent = NULL,
    .ReloadConfig = FcitxExampleReloadConfig
};

static void*
FcitxExampleCreate(FcitxInstance *instance)
{
    FcitxExample *example = fcitx_utils_new(FcitxExample);
    bindtextdomain("fcitx-example", LOCALEDIR);
    example->owner = instance;

    if (!ExampleLoadConfig(&example->config)) {
        free(example);
        return NULL;
    }

    FcitxExampleAddFunctions(instance);
    return example;
}

static void
FcitxExampleDestroy(void *arg)
{
    FcitxExample *example = (FcitxExample*)arg;
    free(example);
}

static void
FcitxExampleReloadConfig(void *arg)
{
    FcitxExample *example = (FcitxExample*)arg;
    ExampleLoadConfig(&example->config);
}

#include "fcitx-example-addfunctions.h"
