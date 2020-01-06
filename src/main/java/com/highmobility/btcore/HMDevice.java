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

public class HMDevice {
    byte[] _mac = {0,0,0,0,0,0};
    byte[] _serial = {0,0,0,0,0,0,0,0,0};
    byte[] _appId = {0,0,0,0,0,0,0,0,0,0,0,0};
    int _isAuthorised = 0;

    public byte[] getMac() {
        return _mac;
    }

    public void setMac(byte[] mac) {
        copyBytesToJNI(mac,_mac);
    }

    public byte[] getSerial() {
        return _serial;
    }

    public void setSerial(byte[] serial) {
        copyBytesToJNI(serial,_serial);
    }

    public int getIsAuthenticated() {
        return _isAuthorised;
    }

    public void setIsAuthenticated(int isAuthorised) {
        _isAuthorised = isAuthorised;
    }

    public byte[] getAppId() {
        return _appId;
    }

    public void setAppId(byte[] appId) {
        copyBytesToJNI(appId,_appId);
    }

    private void copyBytesToJNI(byte[] from, byte[] to) {
        System.arraycopy(from, 0, to, 0, from.length);
    }
}
