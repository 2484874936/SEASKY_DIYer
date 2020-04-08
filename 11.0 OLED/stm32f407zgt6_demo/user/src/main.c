#include "FreeRTOS.h"
#include "task.h"

#include "start_task.h"

#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "bsp_oled.h"
#include "bsp_spi.h"
#include "bsp_adc.h"
#include "bsp_gui.h"
//              GND   ��Դ��
//              VCC   ��5V��3.3v��Դ
//              SCL   OLED_CLK(PA5)
//              SDA   OLED_MOSI(PA7)  
//				RST   OLED_RST(PA6)
//				DC    OLED_DC(PA4)
//				BUTTON_AD BUTTON_AD(PA3)
int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//����ϵͳ�ж����ȼ�����4
	delay_init(168);		//��ʼ����ʱ����
	uart_init(115200);     	//��ʼ������
	LED_Init();		        //��ʼ��LED�˿�
	mx_adc_init();
	mx_spi1_init();
	mx_oled_init();
	oled_gui_init();
	create_start_task();	//������ʼ����            
    vTaskStartScheduler();  //�����������
	while(1){}
}





