#ifndef DATA_TYPES_HPP
#define DATA_TYPES_HPP

namespace canlab {
    /**
    * @brief datatype representing a specific CAN signal from a DBC along with a physical value
    */
    typedef struct {
        float value;
        int startBit;
        int numBits;
        float scaleFactor = 1.0f;
        float offset = 0.0f;
        bool isSigned;
    } dbcData;

    /**
    * @brief datatype representing the payload of a CAN frame, e.i. the length and the data bytes
    */
    typedef struct {
        uint8_t len;
        uint8_t data[8];
    } CanFrame;
}
#endif