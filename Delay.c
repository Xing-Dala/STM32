#include "STM32F103.h"

//��ʱ������ʼ��
void Delay_Init(void)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8); //ѡ���ⲿʱ��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);		  //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
}

//΢����ʱ
void Delay_us(u16 n)
{
	u32 temp;
	SysTick->LOAD = n * 9;					  //ʱ�����
	SysTick->VAL = 0x00;					  //��ռ�����
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk; //��ʼ����
	do
	{
		temp = SysTick->CTRL;
	} while ((temp & 0x01) && !(temp & (1 << 16))); //�ȴ�ʱ�䵽��
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;		//�رռ�����
	SysTick->VAL = 0X00;							//��ռ�����
}

//������ʱ
void Delay_ms(u16 n)
{
	u32 temp;
	SysTick->LOAD = (u32)n * 9000;			  //ʱ�����
	SysTick->VAL = 0x00;					  //��ռ�����
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk; //��ʼ����
	do
	{
		temp = SysTick->CTRL;
	} while ((temp & 0x01) && !(temp & (1 << 16))); //�ȴ�ʱ�䵽��
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;		//�رռ�����
	SysTick->VAL = 0X00;							//��ռ�����
}

//����ʱ
void Delay_s(u16 n)
{
	for (u16 x = 0; x < n; x++)
	{
		u32 temp;
		SysTick->LOAD = 9000000;				  //ʱ�����
		SysTick->VAL = 0x00;					  //��ռ�����
		SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk; //��ʼ����
		do
		{
			temp = SysTick->CTRL;
		} while ((temp & 0x01) && !(temp & (1 << 16))); //�ȴ�ʱ�䵽��
		SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;		//�رռ�����
		SysTick->VAL = 0X00;							//��ռ�����
	}
}