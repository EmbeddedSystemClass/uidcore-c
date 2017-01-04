/**
 * @file   UID_identity.h
 *
 * @date   3/aug/2016
 * @author M. Palumbi
 */
 
 
#ifndef __UID_IDENTITY_H
#define __UID_IDENTITY_H

#include <stdint.h>
#include "UID_globals.h"

#define UID_DEFAULT_IDENTITY_FILE "./identity.db"

typedef struct
{
    unsigned p_u;    // provider/user
    unsigned account;// extern/int
    unsigned n;
} UID_Bip32Path;


void UID_getLocalIdentity(char *keypriv_h);
int UID_getPubkeyAt(UID_Bip32Path *path, uint8_t public_key[33]);
int UID_signAt(UID_Bip32Path *path, uint8_t hash[32], uint8_t sig[64]);
char *UID_getTpub(void);

#endif
