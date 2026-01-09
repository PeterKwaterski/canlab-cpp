#ifndef CONVERSIONS_HPP
#define CONVERSIONS_HPP

#include <vector>
#include "canlab.hpp"

namespace canlab {
    /**
    * @brief Converts physical values into the raw version transmitted in CAN frames
    * @param sig the dbcData object containing the signal corresponding to the raw value
    * @returns 64 bit integer containing the raw unscaled CAN value
    */
    int64_t physToRaw(const dbcData &sig);
}
#endif