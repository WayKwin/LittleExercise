  unsigned int Bit_Reverse(unsigned int v)
    {
        v = ((v & 0x55555555) << 1) | ((v & 0xaaaaaaaa) >> 1);//1010101    0101010    
        v = ((v & 0x33333333) << 2) | ((v & 0xcccccccc) >> 2);//11001100   001100110011 
        v = ((v & 0x0f0f0f0f) << 4) | ((v & 0xf0f0f0f0) >> 4);
        v = ((v & 0x00ff00ff) << 8) | ((v & 0xff00ff00) >> 8);
        v = ((v & 0x0000ffff) << 16) | ((v & 0xffff0000) >> 16);
        return v;

    }