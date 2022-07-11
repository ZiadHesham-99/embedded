#define setBit(reg,bit)				reg|=(1<<bit)
#define resetBit(reg,bit)			reg&=~(1<<bit)
#define toggelBit(reg,bit)			reg^=(1<<bit)
#define evaluate(reg,bit)			(reg&(1<<bit))>>bit
#define IsBitClear(reg,bit)		!(reg&(1<<bit))>>bit
