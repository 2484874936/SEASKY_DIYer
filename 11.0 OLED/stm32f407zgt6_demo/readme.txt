������¼��

2019-7-28��
	1.��ֲST����stm32f4xx���¹̼� en.stm32f4_dsp_stdperiph_lib
	2.��ֲFreeRTOS���°汾������ͨ�� FreeRTOSv10.2.1
BaseType_t xTaskCreate( TaskFunction_t pxTaskCode,
						const char * const pcName,
						const uint16_t usStackDepth,
						void * const pvParameters,
						UBaseType_t uxPriority,
						TaskHandle_t * const pxCreatedTask )
������	pxTaskCode�� ��������
		pcName�� �������֣�һ������׷�ٺ͵��ԣ��������ֳ��Ȳ��ܳ�����configMAX_TASK_NAME_LEN��
		usStackDepth�� �����ջ��С��ע��ʵ�����뵽�Ķ�ջ�� usStackDepth �� 4 �������п�������������ջ��СΪ configMINIMAL_STACK_SIZE��
		pvParameters: ���ݸ��������Ĳ�����
		uxPriotiry: �������ȼ�����Χ 0~ configMAX_PRIORITIES-1��
		pxCreatedTask: �����������񴴽��ɹ��Ժ�᷵�ش����������������������ʵ��������������ջ���˲���������������������������� API �������ܻ�ʹ�õ���������
		
TaskHandle_t xTaskCreateStatic( TaskFunction_t pxTaskCode,
								const char * const pcName,
								const uint32_t ulStackDepth,
								void * const pvParameters,
								UBaseType_t uxPriority,
								StackType_t * const puxStackBuffer,S
								taticTask_t * const pxTaskBuffer )
������pxTaskCode�� ��������
	  pcName�� �������֣�һ������׷�ٺ͵��ԣ��������ֳ��Ȳ��ܳ�����configMAX_TASK_NAME_LEN��
	  usStackDepth�� �����ջ��С�����ڱ������Ǿ�̬���������������������ջ���û�������һ���Ǹ����飬�˲��������������Ĵ�С��
	  pvParameters: ���ݸ��������Ĳ�����
	  uxPriotiry: �������ȼ�����Χ 0~ configMAX_PRIORITIES-1��
	  puxStackBuffer: �����ջ��һ��Ϊ���飬��������ҪΪ StackType_t ���͡�
	  pxTaskBuffer: ������ƿ顣