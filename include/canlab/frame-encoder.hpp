#ifndef FRAME_ENCODER_HPP
#define FRAME_ENCODER_HPP

#include "canlab/data-types"
namespace canlab {
     /**
    * @brief converts a vector of physical values to a CAN frame
    * 
    * Encodes the values in the the input vector as a CAN frame, in LSB/intel format, 
    * that includes all of the signals passed in the vector
    * The resulting CAN frame is ready for transmission or other usage
    * 
    * @param frame the pointer to the front of the array that will store the new payload
    * @param framLength the number of bytes that the CAN frame/message spans
    * @param data the vector of values to translate via the DBC data into a CAN frame
    */
    void valuesToLsb(uint8_t *frame, int frameLength, const std::vector<dbcData> &data);

    /**
    * @brief converts a vector of physical values to a CAN frame
    * 
    * Encodes the values in the the input vector as a CAN frame, in MSB/motorolla format, 
    * that includes all of the signals passed in the vector
    * The resulting CAN frame is ready for transmission or other usage
    * 
    * @param frame the pointer to the front of the array that will store the new payload
    * @param framLength the number of bytes that the CAN frame/message spans
    * @param data the vector of values to translate via the DBC data into a CAN frame
    */
    void valuesToMsb(uint8_t *frame, int frameLength, const std::vector<dbcData> &data);
}


#endif