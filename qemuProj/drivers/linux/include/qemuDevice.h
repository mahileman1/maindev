

typedef struct arrayRegs {
    uint32_t data[20];
} arrayRegs;

typedef struct sampleRegs {
    uint32_t signature;
    uint32_t version;
    uint32_t flags;
    uint32_t crc;
    arrayRegs data;
} sampleRegs;