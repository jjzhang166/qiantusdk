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
Copyright:    www.qiantuai.com(盗版必究)
File name:    QT_BaseSDK.h
Description:  千图图像SDK.
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

    //基础功能
	/*************************************************
	Function:    QTSDK_Saturation
	Description: 饱和度调节.
	Input:       srcData-原始图像，格式为32位BGRA格式，执行后修为结果图像
	             width-原始图像宽度
				 height-原始图像高度
				 stride-原始图像的Stride
				 saturation-饱和度值，范围[-256,256]
	Output:      无.
	Return:      0-成功,其他失败.
	Others:      无.
	*************************************************/
    EXPORT int QTSDK_Saturation(unsigned char* srcData,int width, int height, int stride, int saturation);
	
	/*************************************************
	Function:    QTSDK_Lightness    
	Description: 明度调节
	Input:       srcData-原始图像，格式为32位BGRA格式，执行后修为结果图像
	             width-原始图像宽度
				 height-原始图像高度
				 stride-原始图像的Stride
				 lightness-明度值，范围[-100,100]
	Output:      无.
	Return:      0-成功,其他失败.
	Others:      无.
	*************************************************/
    EXPORT int QTSDK_Lightness(unsigned char* srcData,int width, int height, int stride, int lightness);//明度调节
	/*************************************************
	Function:    QTSDK_HueAndSaturation
	Description: 色相饱和度调节
	Input:       srcData-原始图像，格式为32位BGRA格式，执行后修为结果图像
	             width-原始图像宽度
				 height-原始图像高度
				 stride-原始图像的Stride
				 hue-色相值，范围[-180,180]
				 saturation-饱和度值，范围为[-100,100]
	Output:      无.
	Return:      0-成功,其他失败.
	Others:      无.
	*************************************************/
    EXPORT int QTSDK_HueAndSaturation(unsigned char* srcData,int width, int height, int stride,int hue, int saturation);//色相饱和度调节
	
	/*************************************************
	Function:    QTSDK_NLinearBright
	Description: 非线性亮度对比度调节
	Input:       srcData-原始图像，格式为32位BGRA格式，执行后修为结果图像
	             width-原始图像宽度
				 height-原始图像高度
				 stride-原始图像的Stride
				 brightness-亮度值，范围[-255,255]
				 contrast-对比度值，范围[-255,255]
				 threshold-调节阈值，范围[0,255]，默认值为128
	Output:      无.
	Return:      0-成功,其他失败.
	Others:      无.
	*************************************************/
	EXPORT int QTSDK_BrightContrast(unsigned char* srcData,int width,int height,int stride,int bright,int contrast,int threshold);//非线性亮度对比度调整
	
	/*************************************************
	Function:    QTSDK_ColorTemperature
	Description: 色温调节
	Input:       srcData-原始图像，格式为32位BGRA格式
	             width-原始图像宽度
				 height-原始图像高度
				 stride-原始图像的Stride
				 intensity-色温强度，范围[-50,50]；intensity < 0，冷色；intensity = 0,原图；intensity > 0，暖色；
	Output:      无.
	Return:      0-成功,其他失败.
	Others:      无.
	*************************************************/
    EXPORT int QTSDK_ColorTemperature(unsigned char* srcData,int width, int height, int stride, int intensity);
	
	/*************************************************
	Function:    QTSDK_HighlightShadowPrecise
	Description: 高光阴影调节
	Input:       srcData-原始图像，格式为32位BGRA格式
	             width-原始图像宽度
				 height-原始图像高度
				 stride-原始图像的Stride
				 highlight--高光强度值，取值范围为[-200,100]
				 shadow-阴影强度值，取值范围为[-200,100]
	Output:      无.
	Return:      0-成功,其他失败.
	Others:      无.
	*************************************************/
	EXPORT int QTSDK_HighlightShadow(unsigned char* srcData,int width, int height, int stride, float highlight, float shadow);
	/*************************************************
	Function:    QTSDK_ExposureAdjust
	Description: 曝光调节
	Input:       srcData-原始图像，格式为32位BGRA格式
	             width-原始图像宽度
				 height-原始图像高度
				 stride-原始图像的Stride
				 intensity--曝光强度值，取值范围为[-50,50]
	Output:      无.
	Return:      0-成功,其他失败.
	Others:      无.
	*************************************************/
    EXPORT int QTSDK_Exposure(unsigned char* srcData,int width, int height, int stride, int intensity);
	
	/*************************************************
	Function:    QTSDK_GammaCorrect
	Description: Gamma调整
	Input:       srcData-原始图像，格式为32位BGRA格式
	             width-原始图像宽度
				 height-原始图像高度
				 stride-原始图像的Stride
				 intensity-Gamma参数，范围[1,50],default-10
	Output:      无.
	Return:      0-成功,其他失败.
	Others:      无.
	*************************************************/
	EXPORT int QTSDK_GammaCorrect(unsigned char* srcData, int width, int height, int stride, int intensity);
	/*************************************************
	Function:    QTSDK_SharpenLaplace
	Description: 锐化调整
	Input:       srcData-原始图像，格式为32位BGRA格式
	             width-原始图像宽度
				 height-原始图像高度
				 stride-原始图像的Stride
				 intensity-锐化参数，范围[0,100]
	Output:      无.
	Return:      0-成功,其他失败.
	Others:      无.
	*************************************************/
	EXPORT int QTSDK_SharpenLaplace(unsigned char* srcData,int width, int height,int stride,int intensity);
	/*************************************************
	Function:    QTSDK_CalcWH
	Description: 计算图像变换之后的宽高及变换矩阵H，该接口先于ZPHOTO_ImageTransformation调用       
	Input:	     inputImgSize--输入图像宽高信息
				 angle--旋转角度值，取值范围为[-360-360]
				 scale--缩放变换值，取值大于0
				 transform_method--变换方法：
									 transform_scale缩放变换, 取值为0；
									 transform_rotation旋转变换, 取值为1；   
									 transform_rotation_scale缩放旋转变换, 取值为2；
									 transform_affine仿射变换, 取值为3；
									 transform_mirror_h水平镜像变换, 取值为4；
									 transform_mirror_v垂直镜像变换, 取值为5；
									 transform_offset平移变换, 取值为6；
				 outputImgSize--输出图像宽高信息
				 H--变换矩阵数组，长度为6
	Output:      无.
	Return:      0-成功,其他失败.
	Others:      无.
	*************************************************/
    EXPORT int QTSDK_CalcWH( int inputImgSize[2], float angle, float scale, int transform_method, int outputImgSize[2],float H[]);
	/*************************************************
	Function:    QTSDK_ImageTransformation
	Description: 图像变换
	Input:       srcData-原始图像，格式为32位BGRA格式
	             srcImgSize--原始图像宽高信息数组
                 dstData--结果图像Buffer，大小由接口ZPHOTO_CalcWH获得
				 dstImgSize--目标图像宽高信息数组
				 H--变换矩阵数组，长度为6
				 Interpolation_method--插值方法选择：interpolation_bilinear,interpolation_nearest
				 Transform_method--变换方法：
									 transform_scale缩放变换, 取值为0；
									 transform_rotation旋转变换, 取值为1；   
									 transform_rotation_scale缩放旋转变换, 取值为2；
									 transform_affine仿射变换, 取值为3；
									 transform_mirror_h水平镜像变换, 取值为4；
									 transform_mirror_v垂直镜像变换, 取值为5；
									 transform_offset平移变换, 取值为6；
	Output:      无.
	Return:      0-成功,其他失败.
	Others:      无.
	*************************************************/
    EXPORT int QTSDK_ImageTransformation(unsigned char *srcData, int srcImgSize[2], unsigned char *dstData, int dstImgSize[2], float H[], int Interpolation_method, int Transform_method);
	
	//For Android Development
	/*************************************************
	Function:    QTSDK_RGBA2BGRA
	Description: RGBA格式转BGRA格式，主要为android设置
	Input:       srcData-原始图像，格式为32位BGRA格式，执行后为结果图像
	             width-原始图像宽度
				 height-原始图像高度
				 stride-原始图像的Stride
	Output:      无.
	Return:      0-成功,其他失败.
	Others:      无.
	*************************************************/
	EXPORT int QTSDK_RGBA2BGRA(unsigned char* srcData, int width, int height, int stride);
	/*************************************************
	Function:    QTSDK_BGRA2RGBA
	Description: BGRA格式转RGBA格式，主要为android设置
	Input:       srcData-原始图像，格式为32位BGRA格式，执行后为结果图像
	             width-原始图像宽度
				 height-原始图像高度
				 stride-原始图像的Stride
	Output:      无.
	Return:      0-成功,其他失败.
	Others:      无.
	*************************************************/
    EXPORT int QTSDK_BGRA2RGBA(unsigned char* srcData, int width, int height, int stride);
	/*************************************************
	Function:    QTSDK_OverExposure
	Description: 过度曝光.
	Input:       srcData-原始图像，格式为32位BGRA格式，执行后修为结果图像
	             width-原始图像宽度
				 height-原始图像高度
				 stride-原始图像的Stride
	Output:      无.
	Return:      0-成功,其他失败.
	Others:      无.
	*************************************************/
    EXPORT int QTSDK_OverExposure(unsigned char *srcData, int width, int height, int stride);//过度曝光
	/*************************************************
	Function:    QTSDK_Desaturate
	Description: 去色
	Input:       srcData-原始图像，格式为32位BGRA格式，执行后修为结果图像
	             width-原始图像宽度
				 height-原始图像高度
				 stride-原始图像的Stride
				 ratio-调节程度[0, 100]
	Output:      无.
	Return:      0-成功,其他失败.
	Others:      无.
	*************************************************/
    EXPORT int QTSDK_Desaturate(unsigned char *srcData, int width, int height, int stride, int ratio);//去色
	/*************************************************
	Function:    QTSDK_Mosaic
	Description: 马赛克
	Input:       srcData-原始图像，格式为32位BGRA格式，执行后为结果图像
	             width-原始图像宽度
				 height-原始图像高度
				 stride-原始图像的Stride
				 size-Mosaic半径,范围为[0,200]
	Output:      无.
	Return:      0-成功,其他失败.
	Others:      无.
	*************************************************/
	EXPORT int QTSDK_Mosaic(unsigned char* srcData, int width, int height, int stride, int size);
		/*************************************************
	Function:    QTSDK_VirtualFilter
	Description:背景虚化
	Input:       srcData-原始图像，格式为32位BGRA格式
	             width-原始图像宽度
				 height-原始图像高度
				 stride-原始图像的Stride
				 x-虚化圆点x坐标
				 y-虚化圆点y坐标
				 blurIntensity-虚化程度参数，范围[1,100]
				 radius-虚化半径，范围[0,+]
	Output:      无.
	Return:      0-成功,其他失败.
	Others:      无.
	*************************************************/
	EXPORT int QTSDK_VirtualFilter(unsigned char* srcData,int width, int height,int stride,int x, int y, int blurIntensity, int radius);
	/*************************************************
	Function:    QTSDK_Filter
	Description:滤镜
	Input:       srcData-原始图像，格式为32位BGRA格式
	             width-原始图像宽度
				 height-原始图像高度
				 stride-原始图像的Stride
				 mapData-LUT
				 ratio-滤镜程度调节[0,100]
	Output:      无.
	Return:      0-成功,其他失败.
	Others:      无.
	*************************************************/
	EXPORT int QTSDK_Filter(unsigned char* srcData, int width, int height, int stride, unsigned char* mapData, int ratio);
	/*************************************************
	Function:    QTSDK_BeautySkin
	Description:美颜
	Input:       srcData-原始图像，格式为32位BGRA格式
	             width-原始图像宽度
				 height-原始图像高度
				 stride-原始图像的Stride
				 mapData-LUT
				 beautyRatio-滤镜程度调节[0,100]
				 filterRatio-滤镜程度调节[0,100]
	Output:      无.
	Return:      0-成功,其他失败.
	Others:      无.
	*************************************************/
	EXPORT int QTSDK_BeautySkin(unsigned char* srcData, int width, int height, int stride, unsigned char* mapData, int beautyRatio, int filterRatio);
#else

#ifdef __cplusplus
extern "C" {
#endif    

    int QTSDK_Saturation(unsigned char* srcData,int width, int height, int stride, int saturation);//饱和度调节
    int QTSDK_Lightness(unsigned char* srcData,int width, int height, int stride, int lightness);//明度调节
    int QTSDK_HueAndSaturation(unsigned char* srcData,int width, int height, int stride,int hue, int saturation);//色相饱和度调节
	int QTSDK_BrightContrast(unsigned char* srcData,int width,int height,int stride,int bright,int contrast,int threshold);//非线性亮度对比度调整
    int QTSDK_ColorTemperature(unsigned char* srcData,int width, int height, int stride, int intensity);//色温调节
   	int QTSDK_HighlightShadow(unsigned char* srcData,int width, int height, int stride, float highlight, float shadow);//高光阴影调节
    int QTSDK_Exposure(unsigned char* srcData,int width, int height, int stride, int intensity);//曝光调节
    int QTSDK_CalcWH( int inputImgSize[2], float angle, float scale, int transform_method, int outputImgSize[2],float H[]);//
    int QTSDK_ImageTransformation(unsigned char *srcData, int srcImgSize[2], unsigned char *dstData, int dstImgSize[2], float H[], int Interpolation_method, int Transform_method);
	int QTSDK_GammaCorrect(unsigned char* srcData, int width, int height, int stride, int intensity);//Gamma调节
	int QTSDK_SharpenLaplace(unsigned char* srcData,int width, int height,int stride,int intensity);//锐化调节
	//For Android Development
	int QTSDK_RGBA2BGRA(unsigned char* srcData, int width, int height, int stride);
    int QTSDK_BGRA2RGBA(unsigned char* srcData, int width, int height, int stride);
	int QTSDK_OverExposure(unsigned char *srcData, int width, int height, int stride);//过度曝光
	int QTSDK_Desaturate(unsigned char *srcData, int width, int height, int stride, int ratio);//去色	
	int QTSDK_Mosaic(unsigned char* srcData, int width, int height, int stride, int size);//马赛克
	int QTSDK_VirtualFilter(unsigned char* srcData,int width, int height,int stride,int x, int y, int blurIntensity, int radius);
	int QTSDK_Filter(unsigned char* srcData, int width, int height, int stride, unsigned char* mapData, int ratio);
	int QTSDK_BeautySkin(unsigned char* srcData, int width, int height, int stride, unsigned char* mapData, int beautyRatio, int filterRatio);
	#ifdef __cplusplus
}
#endif


#endif



#endif
