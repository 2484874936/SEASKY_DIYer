#include "bsp_spi.h"

//������SPIģ��ĳ�ʼ�����룬���ó�����ģʽ 						  
//SPI�ڳ�ʼ��
//�������Ƕ�SPI1�ĳ�ʼ��
void mx_spi1_init(void)
{	        	
//              GND   ��Դ��
//              VCC   ��5V��3.3v��Դ
//              SCL   OLED_CLK(PA5)
//              SDA   OLED_MOSI(PA7)  
//				RST   OLED_RST(PA6)
//				DC    OLED_DC(PA4)
//				BUTTON_AD BUTTON_AD(PA3)
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	SPI_InitTypeDef SPI_InitStruct;
//	��ʼ��OLED_CLK(PA5)	OLED_MOSI(PA7)	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource5,GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource7,GPIO_AF_SPI1);
	
	//��λSPI1
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_SPI1,ENABLE);
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_SPI1,DISABLE);
	
	SPI_InitStruct.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
	SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low;
	SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
	SPI_InitStruct.SPI_NSS = SPI_NSS_Soft;
	SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;	//21M
	SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStruct.SPI_CRCPolynomial = 7;
	SPI_Init(SPI1,&SPI_InitStruct);
	SPI_Cmd(SPI1,ENABLE);
}   
//SPI1�ٶ����ú���
//SPI�ٶ�=fAPB2/��Ƶϵ��
//@ref SPI_BaudRate_Prescaler:SPI_BaudRatePrescaler_2~SPI_BaudRatePrescaler_256  
//fAPB2ʱ��һ��Ϊ84Mhz��
void SPI1_SetSpeed(u8 SPI_BaudRatePrescaler)
{
	assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_BaudRatePrescaler));//�ж���Ч��
	SPI1->CR1&=0XFFC7;						//λ3-5���㣬�������ò�����
	SPI1->CR1|=SPI_BaudRatePrescaler;		//����SPI1�ٶ� 
	SPI_Cmd(SPI1,ENABLE); 					//ʹ��SPI1
} 
//SPI1 ��дһ���ֽ�
//TxData:Ҫд����ֽ�
//����ֵ:��ȡ�����ֽ�
u8 SPI1_ReadWriteByte(u8 TxData)
{		 			 
  while (SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_TXE) == RESET){}//�ȴ���������  
  SPI_I2S_SendData(SPI1, TxData); //ͨ������SPIx����һ��byte  ����	
  while (SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RXNE) == RESET){}//�ȴ�������һ��byte  
  return SPI_I2S_ReceiveData(SPI1); //����ͨ��SPIx������յ�����		    
}








