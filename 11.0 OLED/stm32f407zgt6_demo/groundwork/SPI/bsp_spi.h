#ifndef __BSP_SPI_H
#define __BSP_SPI_H
#include "sys.h" 	   

void mx_spi1_init(void);			 //��ʼ��SPI1��
void SPI1_SetSpeed(u8 SpeedSet); //����SPI1�ٶ�   
u8 SPI1_ReadWriteByte(u8 TxData);//SPI1���߶�дһ���ֽ�		 

#endif

