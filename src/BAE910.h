// 0xFC  Multifunction 1-wire slave device @@@
// works

#ifndef ONEWIRE_BAE910_H
#define ONEWIRE_BAE910_H

#include "OneWireItem.h"

typedef struct
{
//  --> reversed fields and write/read in reverse order to achieve swapped byte order
    uint32_t userp;
    uint32_t usero;
    uint32_t usern;
    uint32_t userm;
    uint16_t userl;
    uint16_t userk;
    uint16_t userj;
    uint16_t useri;
    uint8_t  userh;
    uint8_t  userg;
    uint8_t  userf;
    uint8_t  usere;
    uint8_t  userd;
    uint8_t  userc;
    uint8_t  userb;
    uint8_t  usera;
    uint16_t maxcps;
    uint16_t ovruncnt;
    uint16_t stalledcnt;
    uint16_t selectcnt;
    uint16_t resetcnt;
    uint32_t unused0x52;
    uint32_t unused0x4e;
    uint32_t alrt;
    uint32_t alct;
    uint16_t alcps;
    uint16_t alan;
    uint16_t alap;
    //
    uint16_t adc10;
    uint16_t pc3;
    uint16_t pc2;
    uint16_t pc1;
    uint16_t pc0;
    uint8_t  unused0x35;
    uint8_t  alarm;
    uint8_t  cnt;
    uint8_t  adc;
    uint8_t  pio;
    uint8_t  out;
    uint32_t count;
    uint32_t rtc;
    uint32_t adctotn;
    uint32_t adctotp;
    uint16_t cps;
    uint16_t maxan;
    uint16_t maxap;
    uint16_t adcan;
    uint16_t adcap;
    uint16_t duty4;
    uint16_t duty3;
    uint16_t duty2;
    uint16_t duty1;
    uint16_t period2;
    uint16_t period1;
    uint8_t  tpm2c;
    uint8_t  tpm1c;
    uint8_t  rtcc;
    uint8_t  alarmc;
    uint8_t  pioc;
    uint8_t  outc;
    uint8_t  cntc;
    uint8_t  adcc;
    uint16_t reserved;
} sBAE910;

typedef union {
    uint8_t bytes[0x80];
    sBAE910 field;
} mBAE910; // overlay with memory_array


class BAE910 : public OneWireItem
{
private:
    static constexpr uint8_t  BAE910_DEVICE_TYPE      = 0x02;  // Type 2 for BAE0910. Type 3 for BAE0911 (planned)
    static constexpr uint8_t  BAE910_CHIP_TYPE        = 0x01;  // Chip type= 0x01 for the MC9S08SH8, 8 pin package soic8
    static constexpr uint8_t  BAE910_SCRATCHPAD_SIZE  = 32;

protected:
    uint8_t scratchpad[BAE910_SCRATCHPAD_SIZE];
    virtual void extCommand(const uint8_t ecmd, const uint8_t payload_len = 0); // read payload from scratchpad

public:
    static constexpr uint8_t  BAE910_SW_VER           = 0x01;  // undefined data (0x00 = corrupted)
    static constexpr uint8_t  BAE910_BOOTSTRAP_VER    = 0x01;  // undefined data

    mBAE910 memory;

    static constexpr uint8_t family_code              = 0xFC;

    BAE910(uint8_t ID1, uint8_t ID2, uint8_t ID3, uint8_t ID4, uint8_t ID5, uint8_t ID6, uint8_t ID7);

    void duty(OneWireHub *hub);
};

#endif
