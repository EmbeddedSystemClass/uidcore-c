/*
 * UID_bchainBTC.h
 *
 *  Created on: 5/aug/2016
 *      Author: M. Palumbi
 */
 
 
#ifndef __UID_BCHAINBTC_H
#define __UID_BCHAINBTC_H

#include "stdint.h"
#include "UID_globals.h"
#include "UID_identity.h"

#define CONTRACTS_CACHE_SIZE 200 // number of locally cached contracts
#define CLIENT_CACHE_SIZE 50 // number of locally cached client contracts
#define PROFILE_SIZE 40 // OP_RETURN lenght...
#define UID_NAME_LENGHT 16

#define UID_GETTXS "http://appliance2.uniquid.co:8080/insight-api/addrs/%s/txs?from=%d&to=%d"
//#define GETTXS "http://appliance1.uniquid.co:3001/insight-api/addrs/%s/txs?from=%d"
#define UID_SENDTX "http://appliance3.uniquid.co:8080/insight-api/tx/send"
//#define UID_SENDTX "http://appliance4.uniquid.co:3001/insight-api/tx/send"

typedef uint8_t UID_smart_contract[PROFILE_SIZE];

typedef struct
{
    BTC_Address serviceUserAddress;
    BTC_Address serviceProviderAddress;
    UID_smart_contract profile;
} UID_SecurityProfile;

typedef struct
{
    char serviceProviderName[UID_NAME_LENGHT];
    BTC_Address serviceProviderAddress;
    BTC_Address serviceUserAddress;
} UID_ClientProfile;

typedef struct {
    UID_SecurityProfile contractsCache[CONTRACTS_CACHE_SIZE];
    int validCacheEntries;
    UID_ClientProfile clientCache[CLIENT_CACHE_SIZE];
    int validClientEntries;
    pthread_mutex_t in_use;
} cache_buffer;

cache_buffer *UID_getContracts(UID_Identity *localIdentity);
UID_SecurityProfile *UID_matchContract(BTC_Address serviceUserAddress);
UID_ClientProfile *UID_matchProvider(char *name);
int UID_sendTx(char *signed_tx, char *ret, size_t size);

#endif

