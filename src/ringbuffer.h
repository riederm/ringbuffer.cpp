
#pragma once

class RingBuffer {
    public:
        RingBuffer(int maxLength);

        void add(int value);

        bool remove(int* result); 

        int length();

    private:
        int maxLength;
        int* data;

        int r = 0;
        int w = 0;
        int len = 0;

        void move_rd();
        void move_wr();

};
