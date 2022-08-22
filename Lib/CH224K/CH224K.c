#include "CH224K.h"

/////////////////////////////////
//
// CH224Kѡ��PDЭ������ų�ʼ��
//
// CFG1--PB0
// CFG2--PB1
// CFG3--PB2
//
////////////////////////////////
void CH224K_Init(void)
{
	GPIO_InitType GPIO_InitStructure;
  RCC_AHB_Peripheral_Clock_Enable(RCC_AHB_PERIPH_GPIOB);  // ����GPIOB��ʱ��
	
	GPIO_Structure_Initialize(&GPIO_InitStructure);
  GPIO_InitStructure.Pin            = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2;
  GPIO_InitStructure.GPIO_Mode      = GPIO_MODE_AF_PP;      // �����������
  GPIO_InitStructure.GPIO_Slew_Rate = GPIO_SLEW_RATE_FAST;   // ��������_��
  GPIO_InitStructure.GPIO_Pull      = GPIO_PULL_UP;          // �˿�����
  GPIO_Peripheral_Initialize(GPIOB, &GPIO_InitStructure);

	GPIO_Pins_Set(GPIOB, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2);  // ����ѡ�������ݶ˿�λ��
}

// 5VЭ��
void PD_5V(void)
{
	GPIO_Pins_Set(GPIOB, GPIO_PIN_0);
}

// 9VЭ��
void PD_9V(void)
{
	GPIO_Pins_Reset(GPIOB, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2);
}

// 12VЭ��
void PD_12V(void)
{
	GPIO_Pins_Set(GPIOB, GPIO_PIN_2);
	GPIO_Pins_Reset(GPIOB, GPIO_PIN_0 | GPIO_PIN_1);
}

// 15VЭ��
void PD_15V(void)
{
	GPIO_Pins_Set(GPIOB, GPIO_PIN_1 | GPIO_PIN_2);
	GPIO_Pins_Reset(GPIOB, GPIO_PIN_0);
}

// 20VЭ��
void PD_20V(void)
{
	GPIO_Pins_Set(GPIOB, GPIO_PIN_1);
	GPIO_Pins_Reset(GPIOB, GPIO_PIN_0| GPIO_PIN_2);
}



