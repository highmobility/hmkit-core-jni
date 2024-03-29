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
#include "hmkit_core_persistence_hal.h"
#include "hmbtcore.h"
#include "hmkit_core_debug_hal.h"
#include <string.h>

uint32_t hmkit_core_persistence_hal_get_serial(uint64_t appContxtId, uint8_t *serial){

  jbyteArray serial_ = (*envRef)->NewByteArray(envRef,9);
  (*envRef)->SetByteArrayRegion(envRef, serial_, 0, 9, (const jbyte*) serial );
  jint ret = (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMPersistenceHalgetSerial, serial_);

  if ((*envRef)->ExceptionCheck(envRef)) {
      (*envRef)->ExceptionClear(envRef);
      return 0;
    }

  jbyte* content_array = (*envRef)->GetByteArrayElements(envRef, serial_, NULL);
  memcpy(serial,content_array,9);

  return ret;
}

uint32_t hmkit_core_persistence_hal_get_local_public_key(uint64_t appContxtId, uint8_t *public){

  jbyteArray public_ = (*envRef)->NewByteArray(envRef,64);
  (*envRef)->SetByteArrayRegion(envRef, public_, 0, 64, (const jbyte*) public );
  jint ret = (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMPersistenceHalgetLocalPublicKey, public_);

  if ((*envRef)->ExceptionCheck(envRef)) {
      (*envRef)->ExceptionClear(envRef);
      return 0;
    }

  jbyte* content_array = (*envRef)->GetByteArrayElements(envRef, public_, NULL);
  memcpy(public,content_array,64);

  return ret;
}

uint32_t hmkit_core_persistence_hal_get_local_private_key(uint64_t appContxtId, uint8_t *private){

  jbyteArray private_ = (*envRef)->NewByteArray(envRef,32);
  (*envRef)->SetByteArrayRegion(envRef, private_, 0, 32, (const jbyte*) private );
  jint ret = (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMPersistenceHalgetLocalPrivateKey, private_);

  if ((*envRef)->ExceptionCheck(envRef)) {
      (*envRef)->ExceptionClear(envRef);
      return 0;
    }

  jbyte* content_array = (*envRef)->GetByteArrayElements(envRef, private_, NULL);
  memcpy(private,content_array,32);

  return ret;
}

uint32_t hmkit_core_persistence_hal_get_device_certificate(uint64_t appContxtId, uint8_t *cert){

  jbyteArray cert_ = (*envRef)->NewByteArray(envRef,153);
  (*envRef)->SetByteArrayRegion(envRef, cert_, 0, 153, (const jbyte*) cert );
  jint ret = (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMPersistenceHalgetDeviceCertificate, cert_);

  if ((*envRef)->ExceptionCheck(envRef)) {
    (*envRef)->ExceptionClear(envRef);
    return 0;
  }

  jbyte* content_array = (*envRef)->GetByteArrayElements(envRef, cert_, NULL);
  memcpy(cert,content_array,153);

  return ret;
}

uint32_t hmkit_core_persistence_hal_get_ca_public_key(uint64_t appContxtId, uint8_t *public){

  jbyteArray public_ = (*envRef)->NewByteArray(envRef,64);
  (*envRef)->SetByteArrayRegion(envRef, public_, 0, 64, (const jbyte*) public );
  jint ret = (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMPersistenceHalgetCaPublicKey, public_);

  if ((*envRef)->ExceptionCheck(envRef)) {
      (*envRef)->ExceptionClear(envRef);
      return 0;
    }

  jbyte* content_array = (*envRef)->GetByteArrayElements(envRef, public_, NULL);
  memcpy(public,content_array,64);

  return ret;
}

uint32_t hmkit_core_persistence_hal_get_oem_ca_public_key(uint64_t appContxtId, uint8_t *public){
  jbyteArray public_ = (*envRef)->NewByteArray(envRef,64);
  (*envRef)->SetByteArrayRegion(envRef, public_, 0, 64, (const jbyte*) public );
  jint ret = (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMPersistenceHalgetOEMCaPublicKey, public_);

  if ((*envRef)->ExceptionCheck(envRef)) {
      (*envRef)->ExceptionClear(envRef);
      return 0;
    }

  jbyte* content_array = (*envRef)->GetByteArrayElements(envRef, public_, NULL);
  memcpy(public,content_array,64);

  return ret;
}

uint32_t hmkit_core_persistence_hal_add_access_certificate(uint64_t appContxtId, uint8_t *serial, uint8_t *cert, uint16_t size){

  jbyteArray serial_ = (*envRef)->NewByteArray(envRef,9);
  (*envRef)->SetByteArrayRegion(envRef, serial_, 0, 9, (const jbyte*) serial );

  jbyteArray cert_ = (*envRef)->NewByteArray(envRef,size);
  (*envRef)->SetByteArrayRegion(envRef, cert_, 0, size, (const jbyte*) cert );

  jint ret = (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMPersistenceHaladdPublicKey, serial_, cert_, size);

  if ((*envRef)->ExceptionCheck(envRef)) {
      (*envRef)->ExceptionClear(envRef);
      return 0;
    }

  return ret;
}

uint32_t hmkit_core_persistence_hal_get_access_certificate_count(uint64_t appContxtId, uint8_t *count){

  jintArray count_ = (*envRef)->NewIntArray(envRef,1);
  (*envRef)->SetIntArrayRegion(envRef, count_, 0, 1, (const jint*) count );

  jint ret = (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMPersistenceHalgetPublicKeyCount, count_);

  if ((*envRef)->ExceptionCheck(envRef)) {
      (*envRef)->ExceptionClear(envRef);
      return 0;
    }

  if(ret != 0){
    return ret;
  }

  jint* count_array = (*envRef)->GetIntArrayElements(envRef, count_, NULL);
  *count = count_array[0];

  return ret;
}

uint32_t hmkit_core_persistence_hal_get_access_certificate(uint64_t appContxtId, uint8_t *serial, uint8_t *cert, uint16_t *size){

  jbyteArray serial_ = (*envRef)->NewByteArray(envRef,9);
  (*envRef)->SetByteArrayRegion(envRef, serial_, 0, 9, (const jbyte*) serial );

  jbyteArray cert_ = (*envRef)->NewByteArray(envRef,178);
  (*envRef)->SetByteArrayRegion(envRef, cert_, 0, 178, (const jbyte*) cert );

  jintArray size_ = (*envRef)->NewIntArray(envRef,1);
  (*envRef)->SetIntArrayRegion(envRef, size_, 0, 1, (const jint*) size );

  jint ret = (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMPersistenceHalgetPublicKey, serial_, cert_, size_);

  if ((*envRef)->ExceptionCheck(envRef)) {
      (*envRef)->ExceptionClear(envRef);
      return 0;
    }

  if(ret != 0){
    return ret;
  }

  jbyte* serial_array = (*envRef)->GetByteArrayElements(envRef, serial_, NULL);
  memcpy(serial,serial_array,9);

  jint* size_array = (*envRef)->GetIntArrayElements(envRef, size_, NULL);
  *size = size_array[0];

  jbyte* cert_array = (*envRef)->GetByteArrayElements(envRef, cert_, NULL);
  memcpy(cert,cert_array,*size);

  return ret;
}

uint32_t hmkit_core_persistence_hal_get_access_certificate_by_index(uint64_t appContxtId, uint8_t index, uint8_t *cert, uint16_t *size){

    jbyteArray cert_ = (*envRef)->NewByteArray(envRef,178);
    (*envRef)->SetByteArrayRegion(envRef, cert_, 0, 178, (const jbyte*) cert );

    jintArray size_ = (*envRef)->NewIntArray(envRef,1);
    (*envRef)->SetIntArrayRegion(envRef, size_, 0, 1, (const jint*) size );

  jint ret = (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMPersistenceHalgetPublicKeyByIndex, index, cert_, size_);

  if ((*envRef)->ExceptionCheck(envRef)) {
      (*envRef)->ExceptionClear(envRef);
      return 0;
    }

  if(ret != 0){
    return ret;
  }

    jint* size_array = (*envRef)->GetIntArrayElements(envRef, size_, NULL);
    *size = size_array[0];

    jbyte* cert_array = (*envRef)->GetByteArrayElements(envRef, cert_, NULL);
    memcpy(cert,cert_array,*size);

  return ret;
}

uint32_t hmkit_core_persistence_hal_remove_access_certificate(uint64_t appContxtId, hmkit_core_certificate_t *certificate){

  jbyteArray serial_ = (*envRef)->NewByteArray(envRef,9);
  (*envRef)->SetByteArrayRegion(envRef, serial_, 0, 9, (const jbyte*) certificate->gaining_serial );
  jint ret = (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMPersistenceHalremovePublicKey, serial_);

  if ((*envRef)->ExceptionCheck(envRef)) {
      (*envRef)->ExceptionClear(envRef);
      return 0;
    }

  return ret;
}

uint32_t hmkit_core_persistence_hal_erase_access_certificate(uint64_t appContxtId, hmkit_core_certificate_t *certificate){

    return 0;
}

uint32_t hmkit_core_persistence_hal_add_stored_certificate(uint64_t appContxtId, uint8_t *cert, uint16_t size){

  jbyteArray cert_ = (*envRef)->NewByteArray(envRef,9);
  (*envRef)->SetByteArrayRegion(envRef, cert_, 0, 9, (const jbyte*) cert );
  jint ret = (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMPersistenceHaladdStoredCertificate, cert_, size);

  if ((*envRef)->ExceptionCheck(envRef)) {
      (*envRef)->ExceptionClear(envRef);
      return 0;
    }

  return ret;
}

uint32_t hmkit_core_persistence_hal_get_stored_certificate(uint64_t appContxtId, uint8_t *serial, uint8_t *cert, uint16_t *size){

  jbyteArray serial_ = (*envRef)->NewByteArray(envRef,9);
  (*envRef)->SetByteArrayRegion(envRef, serial_, 0, 9, (const jbyte*) serial );

  jbyteArray cert_ = (*envRef)->NewByteArray(envRef,180);
  (*envRef)->SetByteArrayRegion(envRef, cert_, 0, 180, (const jbyte*) cert );

  jintArray size_ = (*envRef)->NewIntArray(envRef,1);
  (*envRef)->SetIntArrayRegion(envRef, size_, 0, 1, (const jint*) size );

  jint ret = (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMPersistenceHalgetStoredCertificate, serial_, cert_, size_);

  if ((*envRef)->ExceptionCheck(envRef)) {
      (*envRef)->ExceptionClear(envRef);
      return 0;
    }

  jint* size_array = (*envRef)->GetIntArrayElements(envRef, size_, NULL);
  *size = size_array[0];

  jbyte* content_array = (*envRef)->GetByteArrayElements(envRef, cert_, NULL);
  memcpy(cert,content_array,*size);

  return ret;
}

uint32_t hmkit_core_persistence_hal_erase_stored_certificate(uint64_t appContxtId, uint8_t *serial){

  jbyteArray serial_ = (*envRef)->NewByteArray(envRef,9);
  (*envRef)->SetByteArrayRegion(envRef, serial_, 0, 9, (const jbyte*) serial );
  jint ret = (*envRef)->CallIntMethod(envRef, coreInterfaceRef, interfaceMethodHMPersistenceHaleraseStoredCertificate, serial_);

  if ((*envRef)->ExceptionCheck(envRef)) {
      (*envRef)->ExceptionClear(envRef);
      return 0;
    }

  return ret;
}

uint32_t hmkit_core_persistence_hal_get_appid_for_issuer_count(uint64_t appContxtId, uint8_t *issuer, uint8_t *count){
 return 0;
}

uint32_t hmkit_core_persistence_hal_get_appid_for_issuer(uint64_t appContxtId, uint8_t *issuer, uint8_t index, uint8_t *appid){
 return 0;
}

uint32_t hmkit_core_persistence_hel_set_command_count(uint64_t appContxtId, uint8_t *serial, uint8_t command, uint8_t count){
  return 0;
}

uint32_t hmkit_core_persistence_hel_get_command_count(uint64_t appContxtId, uint8_t *serial, uint8_t command, uint8_t *count){
  return 0;
}

uint32_t hmkit_core_persistence_hel_remove_all_command_counts(uint64_t appContxtId, uint8_t *serial){
  return 0;
}
