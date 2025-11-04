#ifndef GAMEPAD_OTA_H
#define GAMEPAD_OTA_H

#include "Update.h"
#include <SD.h>

#include "sd_card.h"

bool OTA_update(File &firmware);

#endif