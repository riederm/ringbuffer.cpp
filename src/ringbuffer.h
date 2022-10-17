
#pragma once

class RingBuffer {
    public:
        /**
        * constructs a ringbuffer that is able to hold up to maxLength elements
        */
        RingBuffer(int maxLength);

        /**
        * adds the given value into the end of the ring
        */
        void add(int value);

        /**
        * removes the oldest element from the ring and returns `true` 
        * if an element was returned via `int* result`,
        * returns `false` if the ring was empty
        */
        bool remove(int* result); 
        
        /**
        * returns the number of elements in the ring
        */
        int length();

    private:
        /**
        * the maximung number of elements in this ring
        */
        int maxLength;

        /**
        * array to hold the elements
        */
        int* data;

        /**
        * read ptr, points to the element that will be returned by the next remove-call
        */
        int r = 0;

        /**
        * write ptr, points to the element that will be overwritten by the next add-call
        */
        int w = 0;

        /**
        * the current number of elements in the ring
        */
        int len = 0;

};
