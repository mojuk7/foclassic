#ifndef ___EXCEPTION___
#define ___EXCEPTION___

// Uncomment for use minidumps (dmp) instead readable dumps (txt)
// #define EXCEPTION_MINIDUMP

void CatchExceptions( const char* app_name );
void CreateDump( const char* appendix );

#endif // ___EXCEPTION___
