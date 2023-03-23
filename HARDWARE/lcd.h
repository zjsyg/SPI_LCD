#ifndef __LCD_H
#define __LCD_H

#include "spi.h"
#include "gpio.h"

typedef struct  
{										    
	uint16_t 	width;			//LCD ���
	uint16_t 	height;			//LCD �߶�
	uint16_t 	id;				//LCD ID
	uint8_t  	dir;			//���������������ƣ�0��������1������
	uint16_t	wramcmd;		//��ʼдgramָ��
	uint16_t  	setxcmd;		//����x����ָ��
	uint16_t  	setycmd;		//����y����ָ��	 
}_lcd_dev; 	

extern _lcd_dev lcddev;	//����LCD��Ҫ����

//����LCD�ĳߴ�
#define LCD_W 240
#define LCD_H 320

//TFTLCD������Ҫ���õĺ���		   
extern uint16_t  POINT_COLOR;//Ĭ�Ϻ�ɫ    
extern uint16_t  BACK_COLOR; //������ɫ.Ĭ��Ϊ��ɫ

#define USE_HORIZONTAL  	 0//����Һ����˳ʱ����ת���� 	0-0����ת��1-90����ת��2-180����ת��3-270����ת

#define  CS_SET			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
#define  DC_SET			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
#define  RST_SET			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
#define  LED_SET			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);

#define  CS_RST			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
#define  DC_RST			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
#define  RST_RST			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
#define  LED_RST			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);

//������ɫ
#define WHITE       0xFFFF
#define BLACK      	0x0000	  
#define BLUE       	0x001F  
#define BRED        0XF81F
#define GRED 			 	0XFFE0
#define GBLUE			 	0X07FF
#define RED         0xF800
#define MAGENTA     0xF81F
#define GREEN       0x07E0
#define CYAN        0x7FFF
#define YELLOW      0xFFE0
#define BROWN 			0XBC40 //��ɫ
#define BRRED 			0XFC07 //�غ�ɫ
#define GRAY  			0X8430 //��ɫ
//GUI��ɫ

#define DARKBLUE      	 0X01CF	//����ɫ
#define LIGHTBLUE      	 0X7D7C	//ǳ��ɫ  
#define GRAYBLUE       	 0X5458 //����ɫ
//������ɫΪPANEL����ɫ 
 
#define LIGHTGREEN     	0X841F //ǳ��ɫ
#define LIGHTGRAY     0XEF5B //ǳ��ɫ(PANNEL)
#define LGRAY 			 		0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ

#define LGRAYBLUE      	0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE          0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)

void LCD_WR_REG(uint8_t data);
void LCD_WR_DATA(uint8_t data);
void LCD_WriteReg(uint8_t LCD_Reg, uint16_t LCD_RegValue);	   
void LCD_WriteRAM_Prepare(void);
void Lcd_WriteData_16Bit(uint16_t Data);
void LCD_SetWindows(uint16_t xStar, uint16_t yStar,uint16_t xEnd,uint16_t yEnd); 
void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);
void LCD_DrawPoint(uint16_t x,uint16_t y);
void LCD_Clear(uint16_t Color);
void LCD_RESET(void);
void LCD_direction(uint8_t direction);
void LCD_Init(void);



#endif
