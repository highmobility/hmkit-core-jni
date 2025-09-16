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
#ifndef ANDROID_WEAR_DIGITAL_KEY_HMBTCORE_H
#define ANDROID_WEAR_DIGITAL_KEY_HMBTCORE_H

#include <jni.h>

static jclass interfaceClassRef;
static jobject coreInterfaceRef;
static JNIEnv *envRef;

static jmethodID interfaceMethodHMBTHalInit;
static jmethodID interfaceMethodHMBTHalLog;
static jmethodID interfaceMethodHMBTHalScanStart;
static jmethodID interfaceMethodHMBTHalScanStop;
static jmethodID interfaceMethodHMBTHalAdvertisementStart;
static jmethodID interfaceMethodHMBTHalAdvertisementStop;
static jmethodID interfaceMethodHMBTHalConnect;
static jmethodID interfaceMethodHMBTHalDisconnect;
static jmethodID interfaceMethodHMBTHalServiceDiscovery;
static jmethodID interfaceMethodHMBTHalWriteData;
static jmethodID interfaceMethodHMBTHalReadData;
static jmethodID interfaceMethodHMBTHalTelematicsSendData;

static jmethodID interfaceMethodHMPersistenceHalgetSerial;
static jmethodID interfaceMethodHMPersistenceHalgetLocalPublicKey;
static jmethodID interfaceMethodHMPersistenceHalgetLocalPrivateKey;
static jmethodID interfaceMethodHMPersistenceHalgetDeviceCertificate;
static jmethodID interfaceMethodHMPersistenceHalgetCaPublicKey;
static jmethodID interfaceMethodHMPersistenceHalgetOEMCaPublicKey;
static jmethodID interfaceMethodHMPersistenceHaladdPublicKey;
static jmethodID interfaceMethodHMPersistenceHalgetPublicKey;
static jmethodID interfaceMethodHMPersistenceHalgetPublicKeyByIndex;
static jmethodID interfaceMethodHMPersistenceHalgetPublicKeyCount;
static jmethodID interfaceMethodHMPersistenceHalremovePublicKey;
static jmethodID interfaceMethodHMPersistenceHaladdStoredCertificate;
static jmethodID interfaceMethodHMPersistenceHalgetStoredCertificate;
static jmethodID interfaceMethodHMPersistenceHaleraseStoredCertificate;

static jmethodID interfaceMethodHMApiCallbackEnteredProximity;
static jmethodID interfaceMethodHMApiCallbackExitedProximity;
static jmethodID interfaceMethodHMApiCallbackCustomCommandIncoming;
static jmethodID interfaceMethodHMApiCallbackCustomCommandResponse;
static jmethodID interfaceMethodHMApiCallbackCustomCommandResponseError;
static jmethodID interfaceMethodHMApiCallbackGetDeviceCertificateFailed;
static jmethodID interfaceMethodHMApiCallbackPairingRequested;
static jmethodID interfaceMethodHMApiCallbackTelematicsCommandIncoming;

static jmethodID interfaceMethodHMCryptoHalGenerateNonce;

static jmethodID interfaceMethodHMApiCallbackRevokeResponse;
static jmethodID interfaceMethodHMApiCallbackRevokeIncoming;

static jmethodID interfaceMethodHMApiCallbackErrorCommandIncoming;

#endif //ANDROID_WEAR_DIGITAL_KEY_HMBTCORE_H
