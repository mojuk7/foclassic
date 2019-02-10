#ifndef __DATA_MASK__
#define __DATA_MASK__

#include "Defines.h"
#include "Types.h"

/*class CBitMask
   {
   public:
        void SetBit(uint x, uint y)
        {
                if(x>=width || y>=height) return;
                data[y*width_dw+x/32]|=1<<(x%32);
        }

        int GetBit(uint x, uint y)
        {
                if(x>=width || y>=height) return 0;
                return (data[y*width_dw+x/32]>>(x%32))&1;
        }

        void Fill(int fill)
        {
                memset(data,fill,width_dw*height*sizeof(uint));
        }

        CBitMask(uint width_bit, uint height_bit, uint* ptr, int fill)
        {
                if(!width_bit) width_bit=1;
                if(!height_bit) height_bit=1;
                width=width_bit;
                height=height_bit;
                width_dw=width/32;
                if(width%32) width_dw++;
                if(ptr)
                {
                        isAlloc=false;
                        data=ptr;
                }
                else
                {
                        isAlloc=true;
                        data=new uint[width_dw*height];
                }
                Fill(fill);
        }

        ~CBitMask()
        {
                if(isAlloc) delete[] data;
                data=NULL;
        }

   private:
        bool isAlloc;
        uint* data;
        uint width;
        uint height;
        uint width_dw;
   };*/

class C2BitMask
{
public:
    void Set2Bit( uint x, uint y, int val )
    {
        if( x >= width || y >= height ) return;
        uint8& b = data[y * width_b + x / 4];
        int    bit = (x % 4 * 2);
        UNSETFLAG( b, 3 << bit );
        SETFLAG( b, (val & 3) << bit );
    }

    int Get2Bit( uint x, uint y )
    {
        if( x >= width || y >= height ) return 0;
        return (data[y * width_b + x / 4] >> (x % 4 * 2) ) & 3;
    }

    void Fill( int fill )
    {
        memset( data, fill, width_b * height );
    }

    void Create( uint width_2bit, uint height_2bit, uint8* ptr )
    {
        if( !width_2bit ) width_2bit = 1;
        if( !height_2bit ) height_2bit = 1;
        width = width_2bit;
        height = height_2bit;
        width_b = width / 4;
        if( width % 4 ) width_b++;
        if( ptr )
        {
            isAlloc = false;
            data = ptr;
        }
        else
        {
            isAlloc = true;
            data = new uint8[width_b * height];
            Fill( 0 );
        }
    }

    uint8* GetData() { return data; }
    C2BitMask() { memset( this, 0, sizeof(C2BitMask) ); }
    C2BitMask( uint width_2bit, uint height_2bit, uint8* ptr ) { Create( width_2bit, height_2bit, ptr ); }
    ~C2BitMask()
    {
        if( isAlloc ) delete[] data;
        data = NULL;
    }

private:
    bool   isAlloc;
    uint8* data;
    uint   width;
    uint   height;
    uint   width_b;
};

class C4BitMask
{
public:
    void Set4Bit( uint x, uint y, uint8 val )
    {
        if( x >= width || y >= height ) return;
        uint8& b = data[y * width_b + x / 2];
        if( x & 1 ) b = (b & 0xF0) | (val & 0xF);
        else b = (b & 0xF) | (val << 4);
    }

    uint8 Get4Bit( uint x, uint y )
    {
        if( x >= width || y >= height ) return 0;
        uint8& b = data[y * width_b + x / 2];
        if( x & 1 ) return b & 0xF;
        else return b >> 4;
    }

    void Fill( int fill )
    {
        memset( data, fill, width_b * height );
    }

    C4BitMask( uint width_4bit, uint height_4bit, int fill )
    {
        if( !width_4bit ) width_4bit = 1;
        if( !height_4bit ) height_4bit = 1;
        width = width_4bit;
        height = height_4bit;
        width_b = width / 2;
        if( width & 1 ) width_b++;
        data = new uint8[width_b * height];
        Fill( fill );
    }

    ~C4BitMask()
    {
        delete[] data;
    }

private:
    uint8* data;
    uint   width;
    uint   height;
    uint   width_b;
};

class CByteMask
{
public:
    void SetByte( uint x, uint y, uint8 val )
    {
        if( x >= width || y >= height ) return;
        data[y * width + x] = val;
    }

    uint8 GetByte( uint x, uint y )
    {
        if( x >= width || y >= height ) return 0;
        return data[y * width + x];
    }

    void Fill( int fill )
    {
        memset( data, fill, width * height );
    }

    CByteMask( uint _width, uint _height, int fill )
    {
        if( !_width ) _width = 1;
        if( !_height ) _height = 1;
        width = _width;
        height = _height;
        data = new uint8[width * height];
        Fill( fill );
    }

    ~CByteMask()
    {
        delete[] data;
    }

private:
    uint8* data;
    uint   width;
    uint   height;
};


/*template<int Size>
   class CBitMask_
   {
   public:
        void SetBit(uint x, uint y, int val)
        {
                if(x>=width || y>=height) return;
                data[y*width_dw+x/32]|=1<<(x%32);
        }

        int GetBit(uint x, uint y)
        {
                if(x>=width || y>=height) return 0;
                return (data[y*width_dw+x/32]>>(x%32))&1;
        }

        void Fill(int fill)
        {
                memset(data,fill,width_dw*height*sizeof(uint));
        }

        CBitMask(uint width_bit, uint height_bit, int fill)
        {
                width=width_bit*Size;
                height=height_bit*Size;

                width_dw=width/32;
                if(width%32) width_dw++;

                data=new uint[width_dw*height];

                Fill(fill);
        }

        ~CBitMask()
        {
                delete[] data;
        }

   private:
        uint* data;
        uint width;
        uint height;
        uint width_dw;
   };*/

#endif // __DATA_MASK__
