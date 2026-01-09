#include "conversions.hpp"


using namespace canlab;

int64_t physToRaw(const dbcData &sig)
{
  double raw = (sig.value - sig.offset) / sig.scaleFactor;
  int64_t r = llround(raw);

  // clamp to bit width
  if (sig.numBits < 64)
  {
    int64_t min = sig.isSigned ? -(1LL << (sig.numBits - 1)) : 0;
    int64_t max = sig.isSigned ? (1LL << (sig.numBits - 1)) - 1
                               : (1LL << sig.numBits) - 1;

    if (r < min)
      r = min;
    if (r > max)
      r = max;
  }

  return r;
}