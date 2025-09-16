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

jclass interfaceClassRef;
jobject coreInterfaceRef;
JNIEnv *envRef;

jmethodID interfaceMethodHMBTHalInit;
jmethodID interfaceMethodHMBTHalLog;
jmethodID interfaceMethodHMBTHalScanStart;
jmethodID interfaceMethodHMBTHalScanStop;
jmethodID interfaceMethodHMBTHalAdvertisementStart;
jmethodID interfaceMethodHMBTHalAdvertisementStop;
jmethodID interfaceMethodHMBTHalConnect;
jmethodID interfaceMethodHMBTHalDisconnect;
jmethodID interfaceMethodHMBTHalServiceDiscovery;
jmethodID interfaceMethodHMBTHalWriteData;
jmethodID interfaceMethodHMBTHalReadData;
jmethodID interfaceMethodHMBTHalTelematicsSendData;

jmethodID interfaceMethodHMPersistenceHalgetSerial;
jmethodID interfaceMethodHMPersistenceHalgetLocalPublicKey;
jmethodID interfaceMethodHMPersistenceHalgetLocalPrivateKey;
jmethodID interfaceMethodHMPersistenceHalgetDeviceCertificate;
jmethodID interfaceMethodHMPersistenceHalgetCaPublicKey;
jmethodID interfaceMethodHMPersistenceHalgetOEMCaPublicKey;
jmethodID interfaceMethodHMPersistenceHaladdPublicKey;
jmethodID interfaceMethodHMPersistenceHalgetPublicKey;
jmethodID interfaceMethodHMPersistenceHalgetPublicKeyByIndex;
jmethodID interfaceMethodHMPersistenceHalgetPublicKeyCount;
jmethodID interfaceMethodHMPersistenceHalremovePublicKey;
jmethodID interfaceMethodHMPersistenceHaladdStoredCertificate;
jmethodID interfaceMethodHMPersistenceHalgetStoredCertificate;
jmethodID interfaceMethodHMPersistenceHaleraseStoredCertificate;

jmethodID interfaceMethodHMApiCallbackEnteredProximity;
jmethodID interfaceMethodHMApiCallbackExitedProximity;
jmethodID interfaceMethodHMApiCallbackCustomCommandIncoming;
jmethodID interfaceMethodHMApiCallbackCustomCommandResponse;
jmethodID interfaceMethodHMApiCallbackCustomCommandResponseError;
jmethodID interfaceMethodHMApiCallbackGetDeviceCertificateFailed;
jmethodID interfaceMethodHMApiCallbackPairingRequested;
jmethodID interfaceMethodHMApiCallbackTelematicsCommandIncoming;

jmethodID interfaceMethodHMCryptoHalGenerateNonce;

jmethodID interfaceMethodHMApiCallbackRevokeResponse;
jmethodID interfaceMethodHMApiCallbackRevokeIncoming;

jmethodID interfaceMethodHMApiCallbackErrorCommandIncoming;

#endif //ANDROID_WEAR_DIGITAL_KEY_HMBTCORE_H
