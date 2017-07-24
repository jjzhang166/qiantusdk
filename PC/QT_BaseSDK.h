/*----------------------------------------------------------------------------------------------
*
* This file is QIANTU's property. It contains QIANTU's trade secret, proprietary and
* confidential information. 
* 
* The information and code contained in this file is only for authorized QIANTU employees
* to design, create, modify, or review.
* 
* DO NOT DISTRIBUTE, DO NOT DUPLICATE OR TRANSMIT IN ANY FORM WITHOUT PROPER AUTHORIZATION.
* 
* If you are not an intended recipient of this file, you must not copy, distribute, modify, 
* or take any action in reliance on it. 
* 
* If you have received this file in error, please immediately notify QIANTU and
* permanently delete the original and any copy of any file and any printout thereof.
*
*---------------------------------------------------------------------------------------------*/
/*****************************************************************************
Copyright:    www.qiantuai.com(����ؾ�)
File name:    QT_BaseSDK.h
Description:  ǧͼͼ��SDK.
Author:       HZ
Version:      V1.0
Date:         2017-04-03
*****************************************************************************/

#ifndef __QTSDK_PHOTOENGINE_BASICFREE__
#define __QTSDK_PHOTOENGINE_BASICFREE__

#ifdef _MSC_VER

#ifdef __cplusplus
#define EXPORT extern "C" _declspec(dllexport)
#else
#define EXPORT __declspec(dllexport)
#endif

    //��������
	/*************************************************
	Function:    QTSDK_Saturation
	Description: ���Ͷȵ���.
	Input:       srcData-ԭʼͼ�񣬸�ʽΪ32λBGRA��ʽ��ִ�к���Ϊ���ͼ��
	             width-ԭʼͼ����
				 height-ԭʼͼ��߶�
				 stride-ԭʼͼ���Stride
				 saturation-���Ͷ�ֵ����Χ[-256,256]
	Output:      ��.
	Return:      0-�ɹ�,����ʧ��.
	Others:      ��.
	*************************************************/
    EXPORT int QTSDK_Saturation(unsigned char* srcData,int width, int height, int stride, int saturation);
	
	/*************************************************
	Function:    QTSDK_Lightness    
	Description: ���ȵ���
	Input:       srcData-ԭʼͼ�񣬸�ʽΪ32λBGRA��ʽ��ִ�к���Ϊ���ͼ��
	             width-ԭʼͼ����
				 height-ԭʼͼ��߶�
				 stride-ԭʼͼ���Stride
				 lightness-����ֵ����Χ[-100,100]
	Output:      ��.
	Return:      0-�ɹ�,����ʧ��.
	Others:      ��.
	*************************************************/
    EXPORT int QTSDK_Lightness(unsigned char* srcData,int width, int height, int stride, int lightness);//���ȵ���
	/*************************************************
	Function:    QTSDK_HueAndSaturation
	Description: ɫ�౥�Ͷȵ���
	Input:       srcData-ԭʼͼ�񣬸�ʽΪ32λBGRA��ʽ��ִ�к���Ϊ���ͼ��
	             width-ԭʼͼ����
				 height-ԭʼͼ��߶�
				 stride-ԭʼͼ���Stride
				 hue-ɫ��ֵ����Χ[-180,180]
				 saturation-���Ͷ�ֵ����ΧΪ[-100,100]
	Output:      ��.
	Return:      0-�ɹ�,����ʧ��.
	Others:      ��.
	*************************************************/
    EXPORT int QTSDK_HueAndSaturation(unsigned char* srcData,int width, int height, int stride,int hue, int saturation);//ɫ�౥�Ͷȵ���
	
	/*************************************************
	Function:    QTSDK_NLinearBright
	Description: ���������ȶԱȶȵ���
	Input:       srcData-ԭʼͼ�񣬸�ʽΪ32λBGRA��ʽ��ִ�к���Ϊ���ͼ��
	             width-ԭʼͼ����
				 height-ԭʼͼ��߶�
				 stride-ԭʼͼ���Stride
				 brightness-����ֵ����Χ[-255,255]
				 contrast-�Աȶ�ֵ����Χ[-255,255]
				 threshold-������ֵ����Χ[0,255]��Ĭ��ֵΪ128
	Output:      ��.
	Return:      0-�ɹ�,����ʧ��.
	Others:      ��.
	*************************************************/
	EXPORT int QTSDK_BrightContrast(unsigned char* srcData,int width,int height,int stride,int bright,int contrast,int threshold);//���������ȶԱȶȵ���
	
	/*************************************************
	Function:    QTSDK_ColorTemperature
	Description: ɫ�µ���
	Input:       srcData-ԭʼͼ�񣬸�ʽΪ32λBGRA��ʽ
	             width-ԭʼͼ����
				 height-ԭʼͼ��߶�
				 stride-ԭʼͼ���Stride
				 intensity-ɫ��ǿ�ȣ���Χ[-50,50]��intensity < 0����ɫ��intensity = 0,ԭͼ��intensity > 0��ůɫ��
	Output:      ��.
	Return:      0-�ɹ�,����ʧ��.
	Others:      ��.
	*************************************************/
    EXPORT int QTSDK_ColorTemperature(unsigned char* srcData,int width, int height, int stride, int intensity);
	
	/*************************************************
	Function:    QTSDK_HighlightShadowPrecise
	Description: �߹���Ӱ����
	Input:       srcData-ԭʼͼ�񣬸�ʽΪ32λBGRA��ʽ
	             width-ԭʼͼ����
				 height-ԭʼͼ��߶�
				 stride-ԭʼͼ���Stride
				 highlight--�߹�ǿ��ֵ��ȡֵ��ΧΪ[-200,100]
				 shadow-��Ӱǿ��ֵ��ȡֵ��ΧΪ[-200,100]
	Output:      ��.
	Return:      0-�ɹ�,����ʧ��.
	Others:      ��.
	*************************************************/
	EXPORT int QTSDK_HighlightShadow(unsigned char* srcData,int width, int height, int stride, float highlight, float shadow);
	/*************************************************
	Function:    QTSDK_ExposureAdjust
	Description: �ع����
	Input:       srcData-ԭʼͼ�񣬸�ʽΪ32λBGRA��ʽ
	             width-ԭʼͼ����
				 height-ԭʼͼ��߶�
				 stride-ԭʼͼ���Stride
				 intensity--�ع�ǿ��ֵ��ȡֵ��ΧΪ[-50,50]
	Output:      ��.
	Return:      0-�ɹ�,����ʧ��.
	Others:      ��.
	*************************************************/
    EXPORT int QTSDK_Exposure(unsigned char* srcData,int width, int height, int stride, int intensity);
	
	/*************************************************
	Function:    QTSDK_GammaCorrect
	Description: Gamma����
	Input:       srcData-ԭʼͼ�񣬸�ʽΪ32λBGRA��ʽ
	             width-ԭʼͼ����
				 height-ԭʼͼ��߶�
				 stride-ԭʼͼ���Stride
				 intensity-Gamma��������Χ[1,50],default-10
	Output:      ��.
	Return:      0-�ɹ�,����ʧ��.
	Others:      ��.
	*************************************************/
	EXPORT int QTSDK_GammaCorrect(unsigned char* srcData, int width, int height, int stride, int intensity);
	/*************************************************
	Function:    QTSDK_SharpenLaplace
	Description: �񻯵���
	Input:       srcData-ԭʼͼ�񣬸�ʽΪ32λBGRA��ʽ
	             width-ԭʼͼ����
				 height-ԭʼͼ��߶�
				 stride-ԭʼͼ���Stride
				 intensity-�񻯲�������Χ[0,100]
	Output:      ��.
	Return:      0-�ɹ�,����ʧ��.
	Others:      ��.
	*************************************************/
	EXPORT int QTSDK_SharpenLaplace(unsigned char* srcData,int width, int height,int stride,int intensity);
	/*************************************************
	Function:    QTSDK_CalcWH
	Description: ����ͼ��任֮��Ŀ�߼��任����H���ýӿ�����ZPHOTO_ImageTransformation����       
	Input:	     inputImgSize--����ͼ������Ϣ
				 angle--��ת�Ƕ�ֵ��ȡֵ��ΧΪ[-360-360]
				 scale--���ű任ֵ��ȡֵ����0
				 transform_method--�任������
									 transform_scale���ű任, ȡֵΪ0��
									 transform_rotation��ת�任, ȡֵΪ1��   
									 transform_rotation_scale������ת�任, ȡֵΪ2��
									 transform_affine����任, ȡֵΪ3��
									 transform_mirror_hˮƽ����任, ȡֵΪ4��
									 transform_mirror_v��ֱ����任, ȡֵΪ5��
									 transform_offsetƽ�Ʊ任, ȡֵΪ6��
				 outputImgSize--���ͼ������Ϣ
				 H--�任�������飬����Ϊ6
	Output:      ��.
	Return:      0-�ɹ�,����ʧ��.
	Others:      ��.
	*************************************************/
    EXPORT int QTSDK_CalcWH( int inputImgSize[2], float angle, float scale, int transform_method, int outputImgSize[2],float H[]);
	/*************************************************
	Function:    QTSDK_ImageTransformation
	Description: ͼ��任
	Input:       srcData-ԭʼͼ�񣬸�ʽΪ32λBGRA��ʽ
	             srcImgSize--ԭʼͼ������Ϣ����
                 dstData--���ͼ��Buffer����С�ɽӿ�ZPHOTO_CalcWH���
				 dstImgSize--Ŀ��ͼ������Ϣ����
				 H--�任�������飬����Ϊ6
				 Interpolation_method--��ֵ����ѡ��interpolation_bilinear,interpolation_nearest
				 Transform_method--�任������
									 transform_scale���ű任, ȡֵΪ0��
									 transform_rotation��ת�任, ȡֵΪ1��   
									 transform_rotation_scale������ת�任, ȡֵΪ2��
									 transform_affine����任, ȡֵΪ3��
									 transform_mirror_hˮƽ����任, ȡֵΪ4��
									 transform_mirror_v��ֱ����任, ȡֵΪ5��
									 transform_offsetƽ�Ʊ任, ȡֵΪ6��
	Output:      ��.
	Return:      0-�ɹ�,����ʧ��.
	Others:      ��.
	*************************************************/
    EXPORT int QTSDK_ImageTransformation(unsigned char *srcData, int srcImgSize[2], unsigned char *dstData, int dstImgSize[2], float H[], int Interpolation_method, int Transform_method);
	
	//For Android Development
	/*************************************************
	Function:    QTSDK_RGBA2BGRA
	Description: RGBA��ʽתBGRA��ʽ����ҪΪandroid����
	Input:       srcData-ԭʼͼ�񣬸�ʽΪ32λBGRA��ʽ��ִ�к�Ϊ���ͼ��
	             width-ԭʼͼ����
				 height-ԭʼͼ��߶�
				 stride-ԭʼͼ���Stride
	Output:      ��.
	Return:      0-�ɹ�,����ʧ��.
	Others:      ��.
	*************************************************/
	EXPORT int QTSDK_RGBA2BGRA(unsigned char* srcData, int width, int height, int stride);
	/*************************************************
	Function:    QTSDK_BGRA2RGBA
	Description: BGRA��ʽתRGBA��ʽ����ҪΪandroid����
	Input:       srcData-ԭʼͼ�񣬸�ʽΪ32λBGRA��ʽ��ִ�к�Ϊ���ͼ��
	             width-ԭʼͼ����
				 height-ԭʼͼ��߶�
				 stride-ԭʼͼ���Stride
	Output:      ��.
	Return:      0-�ɹ�,����ʧ��.
	Others:      ��.
	*************************************************/
    EXPORT int QTSDK_BGRA2RGBA(unsigned char* srcData, int width, int height, int stride);
	/*************************************************
	Function:    QTSDK_OverExposure
	Description: �����ع�.
	Input:       srcData-ԭʼͼ�񣬸�ʽΪ32λBGRA��ʽ��ִ�к���Ϊ���ͼ��
	             width-ԭʼͼ����
				 height-ԭʼͼ��߶�
				 stride-ԭʼͼ���Stride
	Output:      ��.
	Return:      0-�ɹ�,����ʧ��.
	Others:      ��.
	*************************************************/
    EXPORT int QTSDK_OverExposure(unsigned char *srcData, int width, int height, int stride);//�����ع�
	/*************************************************
	Function:    QTSDK_Desaturate
	Description: ȥɫ
	Input:       srcData-ԭʼͼ�񣬸�ʽΪ32λBGRA��ʽ��ִ�к���Ϊ���ͼ��
	             width-ԭʼͼ����
				 height-ԭʼͼ��߶�
				 stride-ԭʼͼ���Stride
				 ratio-���ڳ̶�[0, 100]
	Output:      ��.
	Return:      0-�ɹ�,����ʧ��.
	Others:      ��.
	*************************************************/
    EXPORT int QTSDK_Desaturate(unsigned char *srcData, int width, int height, int stride, int ratio);//ȥɫ
	/*************************************************
	Function:    QTSDK_Mosaic
	Description: ������
	Input:       srcData-ԭʼͼ�񣬸�ʽΪ32λBGRA��ʽ��ִ�к�Ϊ���ͼ��
	             width-ԭʼͼ����
				 height-ԭʼͼ��߶�
				 stride-ԭʼͼ���Stride
				 size-Mosaic�뾶,��ΧΪ[0,200]
	Output:      ��.
	Return:      0-�ɹ�,����ʧ��.
	Others:      ��.
	*************************************************/
	EXPORT int QTSDK_Mosaic(unsigned char* srcData, int width, int height, int stride, int size);
		/*************************************************
	Function:    QTSDK_VirtualFilter
	Description:�����黯
	Input:       srcData-ԭʼͼ�񣬸�ʽΪ32λBGRA��ʽ
	             width-ԭʼͼ����
				 height-ԭʼͼ��߶�
				 stride-ԭʼͼ���Stride
				 x-�黯Բ��x����
				 y-�黯Բ��y����
				 blurIntensity-�黯�̶Ȳ�������Χ[1,100]
				 radius-�黯�뾶����Χ[0,+]
	Output:      ��.
	Return:      0-�ɹ�,����ʧ��.
	Others:      ��.
	*************************************************/
	EXPORT int QTSDK_VirtualFilter(unsigned char* srcData,int width, int height,int stride,int x, int y, int blurIntensity, int radius);
	/*************************************************
	Function:    QTSDK_Filter
	Description:�˾�
	Input:       srcData-ԭʼͼ�񣬸�ʽΪ32λBGRA��ʽ
	             width-ԭʼͼ����
				 height-ԭʼͼ��߶�
				 stride-ԭʼͼ���Stride
				 mapData-LUT
				 ratio-�˾��̶ȵ���[0,100]
	Output:      ��.
	Return:      0-�ɹ�,����ʧ��.
	Others:      ��.
	*************************************************/
	EXPORT int QTSDK_Filter(unsigned char* srcData, int width, int height, int stride, unsigned char* mapData, int ratio);
	/*************************************************
	Function:    QTSDK_BeautySkin
	Description:����
	Input:       srcData-ԭʼͼ�񣬸�ʽΪ32λBGRA��ʽ
	             width-ԭʼͼ����
				 height-ԭʼͼ��߶�
				 stride-ԭʼͼ���Stride
				 mapData-LUT
				 beautyRatio-�˾��̶ȵ���[0,100]
				 filterRatio-�˾��̶ȵ���[0,100]
	Output:      ��.
	Return:      0-�ɹ�,����ʧ��.
	Others:      ��.
	*************************************************/
	EXPORT int QTSDK_BeautySkin(unsigned char* srcData, int width, int height, int stride, unsigned char* mapData, int beautyRatio, int filterRatio);
#else

#ifdef __cplusplus
extern "C" {
#endif    

    int QTSDK_Saturation(unsigned char* srcData,int width, int height, int stride, int saturation);//���Ͷȵ���
    int QTSDK_Lightness(unsigned char* srcData,int width, int height, int stride, int lightness);//���ȵ���
    int QTSDK_HueAndSaturation(unsigned char* srcData,int width, int height, int stride,int hue, int saturation);//ɫ�౥�Ͷȵ���
	int QTSDK_BrightContrast(unsigned char* srcData,int width,int height,int stride,int bright,int contrast,int threshold);//���������ȶԱȶȵ���
    int QTSDK_ColorTemperature(unsigned char* srcData,int width, int height, int stride, int intensity);//ɫ�µ���
   	int QTSDK_HighlightShadow(unsigned char* srcData,int width, int height, int stride, float highlight, float shadow);//�߹���Ӱ����
    int QTSDK_Exposure(unsigned char* srcData,int width, int height, int stride, int intensity);//�ع����
    int QTSDK_CalcWH( int inputImgSize[2], float angle, float scale, int transform_method, int outputImgSize[2],float H[]);//
    int QTSDK_ImageTransformation(unsigned char *srcData, int srcImgSize[2], unsigned char *dstData, int dstImgSize[2], float H[], int Interpolation_method, int Transform_method);
	int QTSDK_GammaCorrect(unsigned char* srcData, int width, int height, int stride, int intensity);//Gamma����
	int QTSDK_SharpenLaplace(unsigned char* srcData,int width, int height,int stride,int intensity);//�񻯵���
	//For Android Development
	int QTSDK_RGBA2BGRA(unsigned char* srcData, int width, int height, int stride);
    int QTSDK_BGRA2RGBA(unsigned char* srcData, int width, int height, int stride);
	int QTSDK_OverExposure(unsigned char *srcData, int width, int height, int stride);//�����ع�
	int QTSDK_Desaturate(unsigned char *srcData, int width, int height, int stride, int ratio);//ȥɫ	
	int QTSDK_Mosaic(unsigned char* srcData, int width, int height, int stride, int size);//������
	int QTSDK_VirtualFilter(unsigned char* srcData,int width, int height,int stride,int x, int y, int blurIntensity, int radius);
	int QTSDK_Filter(unsigned char* srcData, int width, int height, int stride, unsigned char* mapData, int ratio);
	int QTSDK_BeautySkin(unsigned char* srcData, int width, int height, int stride, unsigned char* mapData, int beautyRatio, int filterRatio);
	#ifdef __cplusplus
}
#endif


#endif



#endif
