// Copyright (c) 2012 The Richcoin developers
// Copyright (c) 2012 Litecoin Developers
 
 
#ifndef RICHCOIN_VERSION_H
#define RICHCOIN_VERSION_H

#include <string>

//
// client versioning
//

// These need to be macro's, as version.cpp's voodoo requires it
#define CLIENT_VERSION_MAJOR       0
#define CLIENT_VERSION_MINOR       8
#define CLIENT_VERSION_REVISION    8
#define CLIENT_VERSION_BUILD       8

static const int CLIENT_VERSION =
                           1000000 * CLIENT_VERSION_MAJOR
                         +   10000 * CLIENT_VERSION_MINOR 
                         +     100 * CLIENT_VERSION_REVISION
                         +       1 * CLIENT_VERSION_BUILD;

extern const std::string CLIENT_NAME;
extern const std::string CLIENT_BUILD;
extern const std::string CLIENT_DATE;

//
// network protocol versioning
//

static const int PROTOCOL_VERSION = 88888;

// earlier versions not supported as of Feb 2012, and are disconnected
static const int MIN_PROTO_VERSION = 88888;

// nTime field added to CAddress, starting with this version;
// if possible, avoid requesting addresses nodes older than this
static const int CADDR_TIME_VERSION = 88888;

// only request blocks from nodes outside this range of versions
static const int NOBLKS_VERSION_START = 88888;
static const int NOBLKS_VERSION_END = 88888;

// BIP 0031, pong message, is enabled for all versions AFTER this one
static const int BIP0031_VERSION = 88888;

#endif
