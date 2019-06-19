#include "hm_bt_debug_hal.h"
#include "hmbtcore.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hm_bt_debug_hal_log(const char *str, ...){
    char *ptr;
    va_list list;
    va_start(list,str);
    vasprintf(&ptr,str,list);
    hm_bt_debug_hal_log_hex(ptr, strlen(ptr));
    free(ptr);
    va_end(list);
}

void hm_bt_debug_hal_log_hex(const uint8_t *data, const uint16_t length){
   jbyteArray mac_ = (*envRef)->NewByteArray(envRef,length);
   (*envRef)->SetByteArrayRegion(envRef, mac_, 0, length, (const jbyte*) data );
   (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMBTHalLog, 0, mac_);
}
