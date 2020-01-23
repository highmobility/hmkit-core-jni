/*
 * The MIT License
 *
 * Copyright (c) 2014- High-Mobility GmbH (https://high-mobility.com)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include "hmkit_core_debug_hal.h"
#include "hmbtcore.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hmkit_core_debug_hal_log(const char *str, ...){
    char *ptr;
    va_list list;
    va_start(list,str);
    vasprintf(&ptr,str,list);
    hmkit_core_debug_hal_log_hex((uint8_t *)ptr, strlen(ptr));
    free(ptr);
    va_end(list);
}

void hmkit_core_debug_hal_log_hex(const uint8_t *data, const uint16_t length){
   jbyteArray mac_ = (*envRef)->NewByteArray(envRef,length);
   (*envRef)->SetByteArrayRegion(envRef, mac_, 0, length, (const jbyte*) data );
   (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMBTHalLog, 0, mac_);
}