#ifndef GPIO_PRIV
#define GPIO_PRIV

#define GPIOA_BASE_ADDRESS  0x40020000
#define GPIOB_BASE_ADDRESS  0x40020400
#define GPIOC_BASE_ADDRESS  0x40020800

/* GPPIOA registers */ 
//#define GPIOA_MODER   *((uint32*)(GPIOA_BASE_ADDRESS+0x00))
//#define GPIOA_OTYPER  *((uint32*)(GPIOA_BASE_ADDRESS+0x04))
//#define GPIOA_OSPEEDR  *((uint32*)(GPIOA_BASE_ADDRESS+0x08))
//#define GPIOA_PUPDR   *((uint32*)(GPIOA_BASE_ADDRESS+0x0C))
//#define GPIOA_IDR     *((uint32*)(GPIOA_BASE_ADDRESS+0x10))
//#define GPIOA_ODR     *((uint32*)(GPIOA_BASE_ADDRESS+0x14))
//#define GPIOA_BSRR     *((uint32*)(GPIOA_BASE_ADDRESS+0x18))
//#define GPIOA_LCKR     *((uint32*)(GPIOA_BASE_ADDRESS+0x1C))
//#define GPIOA_AFRL     *((uint32*)(GPIOA_BASE_ADDRESS+0x20))
//#define GPIOA_AFRH     *((uint32*)(GPIOA_BASE_ADDRESS+0x24))




typedef struct
{
	u32 MODER  ;
	u32 OTYPER ;
	u32 OSPEEDR;
	u32 PUPDR  ;
	u32 IDR    ;
	u32 ODR    ;
	u32 BSRR   ;
	u32 LCKR   ;
	u32 AFRL   ;
	u32 AFRH   ;
}GPIO_t;

#define GPIOA     ((GPIO_t*)(GPIOA_BASE_ADDRESS))
#define GPIOB     ((GPIO_t*)(GPIOB_BASE_ADDRESS))
#define GPIOC     ((GPIO_t*)(GPIOC_BASE_ADDRESS))



#endif
