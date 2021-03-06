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
#include "hmkit_core_connectivity_hal.h"
#include "hmkit_core.h"

#include "hmkit_core_conf_access.h"

#include "hmbtcore.h"
#include <unistd.h>

#define BLE_GATT_HVX_NOTIFICATION 0x01
#define MAX_CLIENTS 5

void hmkit_core_connectivity_hal_delay_ms(uint32_t number_of_ms){
  usleep(1000*number_of_ms);
}

uint32_t hmkit_core_connectivity_hal_scan_start(){
  (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMBTHalScanStart);

    if ((*envRef)->ExceptionCheck(envRef)) {
        (*envRef)->ExceptionClear(envRef);
    }

    return 0;
}

uint32_t hmkit_core_connectivity_hal_scan_stop(){
  (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMBTHalScanStop);

    if ((*envRef)->ExceptionCheck(envRef)) {
        (*envRef)->ExceptionClear(envRef);
    }

    return 0;
}

uint32_t hmkit_core_connectivity_hal_advertisement_start(uint8_t *issuerId, uint8_t *appId){
  jbyteArray issuer_ = (*envRef)->NewByteArray(envRef,4);
  (*envRef)->SetByteArrayRegion(envRef, issuer_, 0, 4, (const jbyte*) issuerId );

  jbyteArray appId_ = (*envRef)->NewByteArray(envRef,12);
  (*envRef)->SetByteArrayRegion(envRef, appId_, 0, 12, (const jbyte*) appId );
  (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMBTHalAdvertisementStart,issuer_,appId_);

    if ((*envRef)->ExceptionCheck(envRef)) {
        (*envRef)->ExceptionClear(envRef);
    }

    return 0;
}

uint32_t hmkit_core_connectivity_hal_advertisement_stop(){
  (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMBTHalAdvertisementStop);

    if ((*envRef)->ExceptionCheck(envRef)) {
        (*envRef)->ExceptionClear(envRef);
    }

    return 0;
}

uint32_t hmkit_core_connectivity_hal_write_data(uint64_t btcontxtId, uint8_t *mac, uint16_t length, uint8_t *data, hmkit_core_characteristic characteristic){

  jbyteArray mac_ = (*envRef)->NewByteArray(envRef,6);
  (*envRef)->SetByteArrayRegion(envRef, mac_, 0, 6, (const jbyte*) mac );

  jbyteArray data_ = (*envRef)->NewByteArray(envRef,length);
  (*envRef)->SetByteArrayRegion(envRef, data_, 0, length, (const jbyte*) data );

  (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMBTHalWriteData, mac_, length, data_, characteristic);

    if ((*envRef)->ExceptionCheck(envRef)) {
        (*envRef)->ExceptionClear(envRef);
    }

    return 0;
}

uint32_t hmkit_core_connectivity_hal_read_data(uint64_t btcontxtId, uint8_t *mac, uint16_t offset, hmkit_core_characteristic characteristic){
  jbyteArray mac_ = (*envRef)->NewByteArray(envRef,6);
  (*envRef)->SetByteArrayRegion(envRef, mac_, 0, 6, (const jbyte*) mac );

  (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMBTHalReadData, mac_, offset, characteristic);

    if ((*envRef)->ExceptionCheck(envRef)) {
        (*envRef)->ExceptionClear(envRef);
    }

    return 0;
}

uint32_t hmkit_core_connectivity_hal_service_discovery(uint8_t *mac){
  jbyteArray mac_ = (*envRef)->NewByteArray(envRef,6);
  (*envRef)->SetByteArrayRegion(envRef, mac_, 0, 6, (const jbyte*) mac );
  (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMBTHalServiceDiscovery, mac_);

    if ((*envRef)->ExceptionCheck(envRef)) {
        (*envRef)->ExceptionClear(envRef);
    }

    return 0;
}

uint32_t hmkit_core_connectivity_hal_init(){
  (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMBTHalInit);

    if ((*envRef)->ExceptionCheck(envRef)) {
        (*envRef)->ExceptionClear(envRef);
    }

  return 0;
}

uint32_t hmkit_core_connectivity_hal_clock(void){
  return 0;
}

uint32_t hmkit_core_connectivity_hal_connect(const uint8_t *mac, uint8_t macType){
  jbyteArray mac_ = (*envRef)->NewByteArray(envRef,6);
  (*envRef)->SetByteArrayRegion(envRef, mac_, 0, 6, (const jbyte*) mac );
  (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMBTHalConnect, mac_);

  if ((*envRef)->ExceptionCheck(envRef)) {
      (*envRef)->ExceptionClear(envRef);
  }

  return 0;
}

uint32_t hmkit_core_connectivity_hal_disconnect(uint64_t btcontxtId, uint8_t *mac){
  jbyteArray mac_ = (*envRef)->NewByteArray(envRef,6);
  (*envRef)->SetByteArrayRegion(envRef, mac_, 0, 6, (const jbyte*) mac );
  (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMBTHalDisconnect, mac_);

  if ((*envRef)->ExceptionCheck(envRef)) {
      (*envRef)->ExceptionClear(envRef);
  }

  return 0;
}

uint32_t hmkit_core_connectivity_hal_read_info(uint64_t btcontxtId, uint8_t *mac, uint16_t offset, hmkit_core_characteristic characteristic){
  return 0; //TODO for sensing
}

uint32_t hmkit_core_connectivity_hal_get_current_date_time(uint8_t *day, uint8_t *month, uint8_t *year, uint8_t *minute, uint8_t *hour){
  return 0;
}

uint32_t hmkit_core_connectivity_hal_telematics_send_data(uint64_t btcontxtId, uint8_t *issuer, uint8_t *serial, uint16_t length, uint8_t *data){

  jbyteArray issuer_ = (*envRef)->NewByteArray(envRef,4);
  (*envRef)->SetByteArrayRegion(envRef, issuer_, 0, 4, (const jbyte*) issuer );
  jbyteArray serial_ = (*envRef)->NewByteArray(envRef,9);
  (*envRef)->SetByteArrayRegion(envRef, serial_, 0, 9, (const jbyte*) serial );

  jbyteArray data_ = (*envRef)->NewByteArray(envRef,length);
  (*envRef)->SetByteArrayRegion(envRef, data_, 0, length, (const jbyte*) data );

  (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMBTHalTelematicsSendData, issuer_, serial_, length, data_);

    if ((*envRef)->ExceptionCheck(envRef)) {
        (*envRef)->ExceptionClear(envRef);
    }

    return 0;
}
