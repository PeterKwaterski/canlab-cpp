#include "canlab/frame-encoder.hpp"

using namespace canlab;

void valuesToLsb(uint8_t *frame, int frameLength, const std::vector<dbcData> &signals)
{
  memset(frame, 0, frameLength);
  for (const auto &sig : signals)
  {
    int64_t raw = physToRaw(sig) & ((1LL << sig.numBits) - 1);

    for (int i = 0; i < sig.numBits; ++i)
    {
      int frameBit = sig.startBit + i;
      int byte = frameBit / 8;
      int bit = frameBit % 8;

      if (byte >= frameLength)
      {
        continue;
      }
      frame[byte] &= ~(1 << bit);
      frame[byte] |= ((raw >> i) & 1) << bit;
    }
  }
}

void valuesToMsb(uint8_t *frame, int frameLength, const std::vector<dbcData> &signals)
{
  memset(frame, 0, frameLength);
  for (const auto &sig : signals)
  {
    int64_t raw = physToRaw(sig) & ((1LL << sig.numBits) - 1);

    int byte = sig.startBit / 8;
    int bit = sig.startBit % 8;

    for (int i = 0; i < sig.numBits; ++i)
    {
      int raw_bit = (raw >> (sig.numBits - 1 - i)) & 1;

      if (0 <= byte && byte < frameLength)
      {
        frame[byte] &= ~(1 << bit);
        frame[byte] |= raw_bit << bit;
      }

      bit -= 1;
      if (bit < 0)
      {
        bit = 7;
        byte += 1;
      }
    }
  }
}