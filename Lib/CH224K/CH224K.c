#include "CH224K.h"

/////////////////////////////////
//
// CH224K选择PD协议的引脚初始化
//
// CFG1--PB0
// CFG2--PB1
// CFG3--PB2
//
////////////////////////////////
void CH224K_Init(void)
{
	GPIO_InitType GPIO_InitStructure;
  RCC_AHB_Peripheral_Clock_Enable(RCC_AHB_PERIPH_GPIOB);  // 开启GPIOB的时钟
	
	GPIO_Structure_Initialize(&GPIO_InitStructure);
  GPIO_InitStructure.Pin            = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2;
  GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_AF_PP;      // 复用推挽输出
  GPIO_InitStructure.GPIO_Slew_Rate = GPIO_SLEW_RATE_FAST;   // 摆率配置_快
  GPIO_InitStructure.GPIO_Pull      = GPIO_PULL_UP;          // 端口上拉
  GPIO_Peripheral_Initialize(GPIOB, &GPIO_InitStructure);

	GPIO_Pins_Set(GPIOB, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2);  // 设置选定的数据端口位。
}

// 5V协议
void PD_5V(void)
{
	GPIO_Pins_Set(GPIOB, GPIO_PIN_0);
}

// 9V协议
void PD_9V(void)
{
	GPIO_Pins_Reset(GPIOB, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2);
}

// 12V协议
void PD_12V(void)
{
	GPIO_Pins_Set(GPIOB, GPIO_PIN_2);
	GPIO_Pins_Reset(GPIOB, GPIO_PIN_0 | GPIO_PIN_1);
}

// 15V协议
void PD_15V(void)
{
	GPIO_Pins_Set(GPIOB, GPIO_PIN_1 | GPIO_PIN_2);
	GPIO_Pins_Reset(GPIOB, GPIO_PIN_0);
}

// 20V协议
void PD_20V(void)
{
	GPIO_Pins_Set(GPIOB, GPIO_PIN_1);
	GPIO_Pins_Reset(GPIOB, GPIO_PIN_0| GPIO_PIN_2);
}



