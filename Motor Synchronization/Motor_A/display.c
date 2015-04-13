#include "includes.h"

void lcd_wcom(uchar com) //1602 д����� ��Ƭ���� 1602 д����
{ 
	rs=0; //ѡ��ָ��Ĵ���
	rw=0; //ѡ��д
	P0=com; //������������
	delay_ms(1); //��ʱһС����� �� 1602 ׼����������
	en=1; //ʹ���ߵ�ƽ�仯�� �������� 1602 �� 8 λ���ݿ�
	en=0;
}
void lcd_wdat(uchar dat) //1602 д���ݺ���
{
	rs=1; //ѡ�����ݼĴ���
	rw=0; //ѡ��д
	P0=dat; //��Ҫ��ʾ����������
	delay_ms(1); //��ʱһС����� �� 1602 ׼����������
	en=1; //ʹ���ߵ�ƽ�仯�� �������� 1602 �� 8 λ���ݿ�
	en=0;
}

void LCD_Display(uint location, uchar Display_Part[])
{
	int i=0;
	lcd_wcom(location); 
	for(i=0;Display_Part[i] != 0;i++)
	{
		lcd_wdat(Display_Part[i]);
		delay_ms(1);
	}
}

void lcd_init() //1602 ��ʼ������
{
	lcd_wcom(0x38); //8 λ���ݣ� ˫�У� 5*7 ����
	lcd_wcom(0x0c); //������ʾ���� �ع�꣬ ��겻��˸
	lcd_wcom(0x06); //��ʾ��ַ������ ��дһ�����ݺ� ��ʾλ������һλ
	lcd_wcom(0x01); //����
	LCD_Display(0x80,"Speed:");
	LCD_Display(0x80+0x09,"rpm");
}


