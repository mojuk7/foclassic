#ifndef __CRYPT__
#define __CRYPT__

#include "Types.h"

class CryptManager
{
private:
    // Crc32 table
    uint crcTable[0x100];

public:
    // Init Crypt Manager
    CryptManager();

    // Returns Crc32 of data
    uint Crc32( uint8* data, uint len );

    // Continue calculate of Crc32
    void Crc32( uint8* data, uint len, uint& crc );

    // Returns CheckSum of data
    uint CheckSum( uint8* data, uint len );

    // Xor the data
    void XOR( char* data, uint len, char* xor_key, uint xor_len );

    // Password encrypt
    void DecryptPassword( char* data, uint len, uint key );

    // Client credentials SHA-2 hash
    void ClientPassHash( const char* name, const char* pass, char* pass_hash );

    // Xor the text
    void TextXOR( char* data, uint len, char* xor_key, uint xor_len );

    // Compress zlib
    uint8* Compress( const uint8* data, uint& data_len );

    // Uncompress zlib
    uint8* Uncompress( const uint8* data, uint& data_len, uint mul_approx );

    // Crypt text
//	void CryptText(char* text);

    // Uncrypt text
//	void UncryptText(char* text);

    bool   IsCacheTable( const char* cache_fname );
    bool   CreateCacheTable( const char* cache_fname );
    bool   SetCacheTable( const char* cache_fname );
    void   SetCache( const char* data_name, const uint8* data, uint data_len );
    uint8* GetCache( const char* data_name, uint& data_len );
};

extern CryptManager Crypt;

#endif // __CRYPT__
