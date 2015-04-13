#include "includes.h"

uint Motor_Period = 100;
uint Motor_Hight = 50;
uint Motor_Hights = 50;
char high[4] = {'0','0','0','%'};
//int Encoder_i = 0;

void Motor_Init()
{
	Motor_IN1 = 1;
	Motor_IN2 = 0;
	Motor_EN = 1;
}
void Interrupt_T0() interrupt 1	 //PWM
{
	Motor_Hights--;
	if(Motor_Hights == 0)
	{
		Motor_EN = 0;
	   	Motor_Hights = 1;
	} 
	
	Motor_Period--;
	if(Motor_Period == 0)
	{
		Motor_EN = 1;
		Motor_Period = 100;
		Motor_Hights = Motor_Hight;
	}
	/*Encoder_i++;
	if(Encoder_i == 20000)
	{
		Encoder_i = 0;
		Encoder_Speed = 60 * Encoder_Count;
		Encoder_Count = 0;
	} */
	
	/*Motor_Hights--;
	if(Motor_Hights == 0)
	{
		Motor_EN = 0;
	   	Motor_Hights = 1;
	}*/
}

/*void Close_PWM()//�ر�PWM
{
	TR0 = 0;
	ET0 = 0;
} */
/*uchar HighRH = 0;
uchar HighRL = 0;
uchar LowRH = 0;
uchar LowRL = 0;
//sbit PWM_Pin = P1^1;

void PWM_Config(uchar dc) //����PWM������ռ�ձ�dc
{
	uint high, low;
//	ulong temp;

	//Period = (11059200/12)/fr; //һ�������������ֵ
	high = (Period * dc) / 100; //�ߵ�ƽ�������ֵ
	low = Period - high;//�͵�ƽ�������ֵ
	high = 65536 - high;//�ߵ�ƽ����ֵ
	low = 65536 - low;//�͵�ƽ����ֵ

	HighRH = (uchar) (high>>8);//�ߵ�ƽ����ֵ���ֽ�
	HighRL = (uchar) (high);//�ߵ�ƽ����ֵ���ֽ�
	LowRH = (uchar) (low>>8);//�͵�ƽ����ֵ���ֽ�
	LowRL = (uchar) (low);//�͵�ƽ����ֵ���ֽ�

	EA = 1;
	TMOD &= 0xF0;//����T0�Ŀ���λ
	TMOD |= 0x01;//����T0Ϊ����ģʽ1
	TH0 = HighRH;//����T0����ֵ
	TL0 = HighRL;
	ET0 = 1;//��T0�ж�
	TR0 = 1;//ʹ��T0�ж�
	IN_1 = 1;//PWM����ߵ�ƽ
	
}



void Interrupt_T0() interrupt 1	//����PWM������жϷ�����
{
	if (IN_1 == 1)
	{
		TH0 = LowRH;
		TL0 = LowRL;
		IN_1 = 0;
	}
	else 
	{
		TH0 = HighRH;
		TL0 = HighRL;
		IN_1 = 1;
	}
}*/



