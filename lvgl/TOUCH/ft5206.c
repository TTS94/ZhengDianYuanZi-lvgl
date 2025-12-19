
#include <stdio.h>

#include "ft5206.h"
#include "touch.h"
#include "ctiic.h"
// #include "usart.h"
#include "delay.h" 
#include "string.h"
#include "lcd.h"
#include "gt9147.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
//ALIENTEK STM32������
//7����ݴ�����-FT5206 ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2019/9/19
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) �������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
 
//��FT5206д��һ������
//reg:��ʼ�Ĵ�����ַ
//buf:���ݻ�������
//len:д���ݳ���
//����ֵ:0,�ɹ�;1,ʧ��.
u8 FT5206_WR_Reg(u16 reg,u8 *buf,u8 len)
{
	u8 i;
	u8 ret=0;
	CT_IIC_Start();	 
	CT_IIC_Send_Byte(FT_CMD_WR);	//����д���� 	 
	CT_IIC_Wait_Ack(); 	 										  		   
	CT_IIC_Send_Byte(reg&0XFF);   	//���͵�8λ��ַ
	CT_IIC_Wait_Ack();  
	for(i=0;i<len;i++)
	{	   
    	CT_IIC_Send_Byte(buf[i]);  	//������
		ret=CT_IIC_Wait_Ack();
		if(ret)break;  
	}
    CT_IIC_Stop();					//����һ��ֹͣ����	    
	return ret; 
}
//��FT5206����һ������
//reg:��ʼ�Ĵ�����ַ
//buf:���ݻ�������
//len:�����ݳ���			  
void FT5206_RD_Reg(u16 reg,u8 *buf,u8 len)
{
	u8 i; 
 	CT_IIC_Start();	
 	CT_IIC_Send_Byte(FT_CMD_WR);   	//����д���� 	 
	CT_IIC_Wait_Ack(); 	 										  		   
 	CT_IIC_Send_Byte(reg&0XFF);   	//���͵�8λ��ַ
	CT_IIC_Wait_Ack();  
 	CT_IIC_Start();  	 	   
	CT_IIC_Send_Byte(FT_CMD_RD);   	//���Ͷ�����		   
	CT_IIC_Wait_Ack();	   
	for(i=0;i<len;i++)
	{	   
    	buf[i]=CT_IIC_Read_Byte(i==(len-1)?0:1); //������	  
	} 
    CT_IIC_Stop();//����һ��ֹͣ����     
} 

u8 CIP[5]; //������Ŵ���IC-GT911
//��ʼ��FT5206������
//����ֵ:0,��ʼ���ɹ�;1,��ʼ��ʧ�� 
u8 FT5206_Init(void)
{
	u8 temp[5];  		
	
	GPIO_InitTypeDef GPIO_Initure;

	__HAL_RCC_GPIOF_CLK_ENABLE();           	//����GPIOFʱ��
	
    GPIO_Initure.Pin=GPIO_PIN_11; 				//PF11
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  	//�������
    GPIO_Initure.Pull=GPIO_PULLUP;          	//����
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH;    //����
    HAL_GPIO_Init(GPIOF,&GPIO_Initure);
	
	GPIO_Initure.Pin=GPIO_PIN_10; 				//PF10
	GPIO_Initure.Mode=GPIO_MODE_INPUT;  		//����
	HAL_GPIO_Init(GPIOF,&GPIO_Initure);		

	CT_IIC_Init();      	//��ʼ����������I2C����  
	FT_RST=0;				//��λ
	delay_ms(20);
 	FT_RST=1;				//�ͷŸ�λ		    
	delay_ms(50);  	
	temp[0]=0;
	FT5206_WR_Reg(FT_DEVIDE_MODE,temp,1);	//������������ģʽ 
	FT5206_WR_Reg(FT_ID_G_MODE,temp,1);		//��ѯģʽ 
	temp[0]=22;								//������Чֵ��22��ԽСԽ����	
	FT5206_WR_Reg(FT_ID_G_THGROUP,temp,1);	//���ô�����Чֵ
	temp[0]=12;								//�������ڣ�����С��12�����14
	FT5206_WR_Reg(FT_ID_G_PERIODACTIVE,temp,1); 
	//��ȡ�汾�ţ��ο�ֵ��0x3003
	FT5206_RD_Reg(FT_ID_G_LIB_VERSION,&temp[0],2);  
	if(temp[0]==0X30&&temp[1]==0X03)//�汾:0X3003
	{ 
		printf("CTP ID:%x\r\n",((u16)temp[0]<<8)+temp[1]);
		return 0;
	} 
    else    //7�����Ĵ���IC����GTϵ�еģ�����������Ҫ����
    {
        GT9147_RD_Reg(GT_PID_REG,temp,4); //��ȡ��ƷID
        temp[4]=0;
        printf("CTP ID:%s\r\n", temp);  //��ӡID
        memcpy(CIP,temp, sizeof(u8)*4);
        temp[0]=0X02;
        GT9147_WR_Reg(GT_CTRL_REG,temp,1);  //����λGT9XXX 
        GT9147_RD_Reg(GT_CFGS_REG,temp,1);  //��ȡGT_CFGS_REG�Ĵ���
        delay_ms(10);
        temp[0]=0X00;
        GT9147_WR_Reg(GT_CTRL_REG,temp,1); //������λ, ���������״̬
        return 0;
    }
}

const u16 FT5206_TPX_TBL[5]={FT_TP1_REG,FT_TP2_REG,FT_TP3_REG,FT_TP4_REG,FT_TP5_REG};
//GT911����GT9xxϵ�У�����ֱ�ӵ���gt9147����غ궨��͵�����غ���
const u16 GT911_TPX_TBL[5]={GT_TP1_REG,GT_TP2_REG,GT_TP3_REG,GT_TP4_REG,GT_TP5_REG};
u8 g_gt_tnum=5;      //Ĭ��֧�ֵĴ���������(5�㴥��)

//ɨ�败����(���ò�ѯ��ʽ)
//mode:0,����ɨ��.
//����ֵ:��ǰ����״̬.
//0,�����޴���;1,�����д���
u8 FT5206_Scan(u8 mode)
{
	u8 buf[4];
	u8 i=0;
	u8 res=0;
	u8 temp;
    u16 tempsta;
	static u8 t=0;//���Ʋ�ѯ���,�Ӷ�����CPUռ����   
	t++;
	if((t%10)==0||t<10)//����ʱ,ÿ����10��CTP_Scan�����ż��1��,�Ӷ���ʡCPUʹ����
	{
		if(strcmp((char *)CIP,"911")==0) //����IC 911
        {
            GT9147_RD_Reg(GT_GSTID_REG,&mode,1); //��ȡ������״̬
            if((mode&0X80)&&((mode&0XF)<=g_gt_tnum))
            {
                i=0;
                GT9147_WR_Reg(GT_GSTID_REG,&i,1); //���־
            }
        }
        else
        {
            FT5206_RD_Reg(FT_REG_NUM_FINGER,&mode,1);//��ȡ�������״̬  
        }
		if((mode&0XF)&&((mode&0XF)<=g_gt_tnum))
		{
			temp=0XFF<<(mode&0XF);//����ĸ���ת��Ϊ1��λ��,ƥ��tp_dev.sta���� 
			tempsta=tp_dev.sta;    //���浱ǰ��tp_dev.staֵ
            tp_dev.sta=(~temp)|TP_PRES_DOWN|TP_CATH_PRES;
            tp_dev.x[g_gt_tnum-1]=tp_dev.x[0];//���津��0������,���������һ����
            tp_dev.y[g_gt_tnum-1]=tp_dev.y[0];

            delay_ms(4);    //��Ҫ����ʱ������������Ϊ�а�������

			for(i=0;i<g_gt_tnum;i++)
			{
				if(tp_dev.sta&(1<<i))		//������Ч?
				{
                    if(strcmp((char *)CIP,"911")==0) //����IC 911
                    {
                        GT9147_RD_Reg(GT911_TPX_TBL[i],buf,4);   //��ȡXY����ֵ
                        if(tp_dev.touchtype&0X01) //����
                        {
                            tp_dev.x[i]=(((u16)buf[1]<<8)+buf[0]);
                            tp_dev.y[i]=(((u16)buf[3]<<8)+buf[2]);
                        }
                        else
                        {
                            tp_dev.y[i]=((u16)buf[1]<<8)+buf[0];
                            tp_dev.x[i]=lcddev.width-(((u16)buf[3]<<8)+buf[2]);
                        }
                    }
                    else
                    {
                        FT5206_RD_Reg(FT5206_TPX_TBL[i],buf,4);	//��ȡXY����ֵ 
                        if(tp_dev.touchtype&0X01)//����
                        {
                            tp_dev.y[i]=((u16)(buf[0]&0X0F)<<8)+buf[1];
                            tp_dev.x[i]=((u16)(buf[2]&0X0F)<<8)+buf[3];
                        }else
                        {
                            tp_dev.x[i]=lcddev.width-(((u16)(buf[0]&0X0F)<<8)+buf[1]);
                            tp_dev.y[i]=((u16)(buf[2]&0X0F)<<8)+buf[3];
                        } 
                    }
					//printf("x[%d]:%d,y[%d]:%d\r\n",i,tp_dev.x[i],i,tp_dev.y[i]);
				}			
			} 
			res=1;
            if(tp_dev.x[0]>lcddev.width||tp_dev.y[0]>lcddev.height)  //�Ƿ�����(���곬����)
            {
                if((mode&0XF)>1)   // ��������������,�򸴵ڶ�����������ݵ���һ������.
                {
                    tp_dev.x[0]=tp_dev.x[1];
                    tp_dev.y[0]=tp_dev.y[1];
                    t=0;  // ����һ��,��������������10��,�Ӷ���������� 
                }
                else        // �Ƿ�����,����Դ˴�����(��ԭԭ����) 
                {
                    tp_dev.x[0]=tp_dev.x[g_gt_tnum-1];
                    tp_dev.y[0]=tp_dev.y[g_gt_tnum-1];
                    mode=0X80;
                    tp_dev.sta=tempsta;   // �ָ�tp_dev.sta 
                }
            }
            else t=0;      // ����һ��,��������������10��,�Ӷ���������� 
		}
	}
    
    if(strcmp((char *)CIP,"911")==0) //����IC 911
    {
        if((mode&0X8F)==0X80)//�޴����㰴��
        { 
            if(tp_dev.sta&TP_PRES_DOWN)	//֮ǰ�Ǳ����µ�
            {
                tp_dev.sta&=~TP_PRES_DOWN;	//��ǰ����ɿ�
            }else						//֮ǰ��û�б�����
            { 
                tp_dev.x[0]=0xffff;
                tp_dev.y[0]=0xffff;
                tp_dev.sta&=0XE0;	//�������Ч���	
            }	 
        } 	
    }
    else
    {
        if((mode&0X1F)==0)//�޴����㰴��
        { 
            if(tp_dev.sta&TP_PRES_DOWN)	//֮ǰ�Ǳ����µ�
            {
                tp_dev.sta&=~TP_PRES_DOWN;	//��ǰ����ɿ�
            }else						//֮ǰ��û�б�����
            { 
                tp_dev.x[0]=0xffff;
                tp_dev.y[0]=0xffff;
                tp_dev.sta&=0XE0;	//�������Ч���	
            }
        }
    }
	if(t>240)t=10;//���´�10��ʼ����
	return res;
}
 

























