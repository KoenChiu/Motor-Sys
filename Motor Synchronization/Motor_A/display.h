#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#define uint unsigned int
#define uchar unsigned char
sbit rs = P1^0; //1602 ������/ָ��ѡ�������
sbit rw = P1^1; //1602 �Ķ�д������
sbit en = P2^5; //1602 ��ʹ�ܿ�����

//sbit rs = P3^5; //1602 ������/ָ��ѡ�������
//sbit en = P3^4; //1602 ��ʹ�ܿ�����

extern void LCD_Display(uint location, uchar speed[]);
extern void lcd_init();
extern void lcd_wdat(uchar dat);
extern void lcd_wcom(uchar com);


#endif