# Core JNI

This repository contains our C Core JNI files. JNI is used in HMKit Android/OEM libraries to 
access the shared core features.

The shared JNI files are: Java and C classes and preBuilt OpenSSL binaries.

The Java JNI classes are released as a package, C files are used to build the core in HMKit 
Android/OEM repositories.


OpenSSL binaries for Linux are 1.1.0i, others 1.0.2.m.

### Setup

* git submodule update --init --recursive