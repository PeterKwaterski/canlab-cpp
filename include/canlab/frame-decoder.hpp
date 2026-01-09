#ifndef FRAME_DECODER_HPP
#define FRAME_DECODER_HPP

#include "canlab/data-types"
namespace canlab {
    /**
    * @brief converts a CAN frame in LSB/intel format to a physical value
    * 
    * Uses the dbcData along with a given CAN frame to extract a value with physical meaning
    * 
    * @param frame the CAN frame to extract a value from
    * @param sig the dbcData struct containing a representation of the signal to decode
    * @returns the physical value represented in the frame
    */
    float lsbToValue(uint8_t *frame, dbcData sig);

    /**
    * @brief converts a CAN frame in MSB/motorolla format to a physical value
    * 
    * Uses the dbcData along with a given CAN frame to extract a value with physical meaning
    * 
    * @param frame the CAN frame to extract a value from
    * @param sig the dbcData struct containing a representation of the signal to decode
    * @returns the physical value represented in the frame
    */
    float msbToValue(uint8_t *frame, dbcData sig);
}


#endif