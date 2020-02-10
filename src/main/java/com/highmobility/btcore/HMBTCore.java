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
package com.highmobility.btcore;

public class HMBTCore {
    //Init core
    //interface is class reference what implements HMBTCoreInterface
    public native void HMBTCoreInit(HMBTCoreInterface coreInterface);
    //Send clock beat to core
    public native void HMBTCoreClock(HMBTCoreInterface coreInterface);

    //CORE SENSING

    public native void HMBTCoreSensingReadNotification(HMBTCoreInterface coreInterface, byte[] mac, int characteristic);
    public native void HMBTCoreSensingReadResponse(HMBTCoreInterface coreInterface, byte[] data, int size, int offset, byte[] mac, int characteristic);

    public native void HMBTCoreSensingWriteResponse(HMBTCoreInterface coreInterface, byte[] mac, int characteristic);

    public native void HMBTCoreSensingPingNotification(HMBTCoreInterface coreInterface, byte[] mac, int characteristic);

    public native void HMBTCoreSensingProcessAdvertisement(HMBTCoreInterface coreInterface, byte[] mac, byte[] data, int size);
    public native void HMBTCoreSensingDiscoveryEvent(HMBTCoreInterface coreInterface, byte[] mac);
    public native void HMBTCoreSensingScanStart(HMBTCoreInterface coreInterface);

    public native void HMBTCoreSensingConnect(HMBTCoreInterface coreInterface, byte[] mac);
    public native void HMBTCoreSensingDisconnect(HMBTCoreInterface coreInterface, byte[] mac);

    //CORE LINK

    //Initialize link object in core
    public native void HMBTCorelinkConnect(HMBTCoreInterface coreInterface, byte[] mac);
    //Delete link object in core
    public native void HMBTCorelinkDisconnect(HMBTCoreInterface coreInterface, byte[] mac);

    //Forward link incoming data to core
    public native void HMBTCorelinkIncomingData(HMBTCoreInterface coreInterface, byte[] data, int size, byte[] mac, int characteristic);

    public native void HMBTCorelinkWriteResponse(HMBTCoreInterface coreInterface, byte[] mac, int characteristic);

    public native void HMBTCoreSendCustomCommand(HMBTCoreInterface coreInterface, int contentType, byte[] data, int size, byte[] mac, int version);

    public native void HMBTCoreSendReadDeviceCertificate(HMBTCoreInterface coreInterface, byte[] mac, byte[] nonce, byte[] caSignature);
    public native void HMBTCoreSendRegisterAccessCertificate(HMBTCoreInterface coreInterface, byte[] certificate);

    //Crypto
    public native void HMBTCoreCryptoCreateKeys(byte[] privateKey, byte[] publicKey);

    public native void HMBTCoreCryptoAddSignature(byte[] data, int size, byte[] privateKey, byte[] signature);
    public native int HMBTCoreCryptoValidateSignature(byte[] data, int size, byte[] pubKey, byte[] signature);

    public native int HMBTCoreCryptoJWTAddSignature(byte[] message, int size, byte[] private_key, byte[] signature);
    public native int HMBTCoreCryptoJWTsha(byte[] nonce, int size, byte[] hash);

    //Telematics
    public native void HMBTCoreTelematicsReceiveData(HMBTCoreInterface coreInterface, int length, byte[] data);
    public native void HMBTCoreSendTelematicsCommand(HMBTCoreInterface coreInterface, byte[] serial, byte[] nonce, int contentType, int length, byte[] data, int version);

    //Other
    public native void HMBTCoreSendRevoke(HMBTCoreInterface coreInterface, byte[] serial);
    public native void HMBTCoreSetLogLevel(HMBTCoreInterface coreInterface, int level);
    public native void HMBTCoreSetMTU(HMBTCoreInterface coreInterface, byte[] mac, byte[] mtu);
}
