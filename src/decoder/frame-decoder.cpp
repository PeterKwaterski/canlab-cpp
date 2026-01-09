#include "canlab/frame-decoder.hpp"

using namespace canlab;

float lsbToValue(uint8_t *frame, dbcData sig)
{
  int64_t raw = 0;
  for (int i = 0; i < sig.numBits; ++i)
  {
    int frameBit = sig.startBit + i;
    int byte = frameBit / 8;
    int bit = frameBit % 8;
    raw |= ((frame[byte] >> bit) & 1) << i;
  }
  if (sig.isSigned)
  {
    int64_t sign = 1LL << (sig.numBits - 1);
    if (raw & sign)
    {
      raw |= ~((1LL << sig.numBits) - 1);
    }
  }

  return static_cast<float>(raw) * sig.scaleFactor + sig.offset;
}

float msbToValue(uint8_t *frame, dbcData sig)
{
  int64_t raw = 0;

  int byte = sig.startBit / 8;
  int bit = sig.startBit % 8;

  for (int i = 0; i < sig.numBits; ++i)
  {
    raw = (raw << 1) | ((frame[byte] >> bit) & 1);

    bit -= 1;
    if (bit < 0)
    {
      bit = 7;
      byte += 1;
    }
  }

  if (sig.isSigned)
  {
    int sign = 1LL << (sig.numBits - 1);
    if (raw & sign)
    {
      raw |= ~((1LL << sig.numBits) - 1);
    }
  }
  return static_cast<float>(raw) * sig.scaleFactor + sig.offset;
}