using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.Drawing.Imaging;
using System.Runtime.InteropServices;

namespace TestDemo
{
    unsafe class QTSDK
    {

        //QIANTU SDK
        [DllImport("QTBaseSDK.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.None, ExactSpelling = true)]
        private extern static int QTSDK_Saturation(byte* srcData,int width, int height, int stride, int saturation);
        [DllImport("QTBaseSDK.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.None, ExactSpelling = true)]
        private extern static int QTSDK_Lightness(byte* srcData, int width, int height, int stride, int lightness);
        [DllImport("QTBaseSDK.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.None, ExactSpelling = true)]
        private extern static int QTSDK_HueAndSaturation(byte* srcData, int width, int height, int stride, int hue, int saturation);
        [DllImport("QTBaseSDK.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.None, ExactSpelling = true)]
        private extern static int QTSDK_BrightContrast(byte* srcData, int width, int height, int stride, int bright, int contrast, int threshold);
        [DllImport("QTBaseSDK.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.None, ExactSpelling = true)]
        private extern static int QTSDK_ColorTemperature(byte* srcData, int width, int height, int stride, int intensity);
        [DllImport("QTBaseSDK.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.None, ExactSpelling = true)]
        private extern static int QTSDK_HighlightShadow(byte* srcData, int width, int height, int stride, float highlight, float shadow);
        [DllImport("QTBaseSDK.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.None, ExactSpelling = true)]
        private extern static int QTSDK_Exposure(byte* srcData, int width, int height, int stride, int intensity);
        [DllImport("QTBaseSDK.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.None, ExactSpelling = true)]
        private extern static int QTSDK_GammaCorrect(byte* srcData, int width, int height, int stride, int intensity);
        [DllImport("QTBaseSDK.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.None, ExactSpelling = true)]
        private extern static int QTSDK_SharpenLaplace(byte* srcData, int width, int height, int stride, int intensity);
        [DllImport("QTBaseSDK.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.None, ExactSpelling = true)]
        private extern static int QTSDK_CalcWH(int[] inputImgSize, float angle, float scale, int transform_method, int[] outputImgSize, float[] H);
        [DllImport("QTBaseSDK.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.None, ExactSpelling = true)]
        private extern static int QTSDK_ImageTransformation(byte* srcData, int[] srcImgSize, byte* dstData, int[] dstImgSize, float[] H, int Interpolation_method, int Transform_method);
        [DllImport("QTBaseSDK.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.None, ExactSpelling = true)]
        private extern static int QTSDK_RGBA2BGRA(byte* srcData, int width, int height, int stride);//
        [DllImport("QTBaseSDK.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.None, ExactSpelling = true)]
        private extern static int QTSDK_BGRA2RGBA(byte* srcData, int width, int height, int stride);
        [DllImport("QTBaseSDK.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.None, ExactSpelling = true)]
        private extern static int QTSDK_OverExposure(byte* srcData, int width, int height, int stride);
        [DllImport("QTBaseSDK.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.None, ExactSpelling = true)]
        private extern static int QTSDK_Desaturate(byte* srcData, int width, int height, int stride, int ratio);
        [DllImport("QTBaseSDK.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.None, ExactSpelling = true)]
        private extern static int QTSDK_Mosaic(byte* srcData, int width, int height, int stride, int size);//
        [DllImport("QTBaseSDK.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.None, ExactSpelling = true)]
        private extern static int QTSDK_VirtualFilter(byte* srcData, int width, int height, int stride, int x, int y, int blurIntensity, int radius);
        [DllImport("QTBaseSDK.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.None, ExactSpelling = true)]
        private extern static int QTSDK_Filter(byte* srcData, int width, int height, int stride, byte* mapData, int ratio);
        [DllImport("QTBaseSDK.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.None, ExactSpelling = true)]
        private extern static int QTSDK_BeautySkin(byte* srcData, int width, int height, int stride, byte* mapData, int beautyRatio, int filterRatio);
        /// <summary>
        /// ////////////////////////
        /// </summary>
        /// <param name="src"></param>
        /// <param name="saturation"></param>
        /// <returns></returns>
        public Bitmap QT_Saturation(Bitmap src, int saturation)
        {
            Bitmap a = new Bitmap(src);
            int w = a.Width;
            int h = a.Height;
            BitmapData srcData = a.LockBits(new Rectangle(0, 0, a.Width, a.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            QTSDK_Saturation((byte*)srcData.Scan0, w, h, srcData.Stride, saturation);
            a.UnlockBits(srcData);
            return a;
        }
        public Bitmap QT_Lightness(Bitmap src, int lightness)
        {
            Bitmap a = new Bitmap(src);
            int w = a.Width;
            int h = a.Height;
            BitmapData srcData = a.LockBits(new Rectangle(0, 0, a.Width, a.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            QTSDK_Lightness((byte*)srcData.Scan0, w, h, srcData.Stride, lightness);
            a.UnlockBits(srcData);
            return a;
        }
        public Bitmap QT_HueAndSaturation(Bitmap src, int hue, int saturation)
        {
            Bitmap a = new Bitmap(src);
            int w = a.Width;
            int h = a.Height;
            BitmapData srcData = a.LockBits(new Rectangle(0, 0, a.Width, a.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            QTSDK_HueAndSaturation((byte*)srcData.Scan0, w, h, srcData.Stride, hue, saturation);
            a.UnlockBits(srcData);
            return a;
        }
        public Bitmap QT_BrightContrast(Bitmap src, int bright, int contrast, int threshold)
        {
            Bitmap a = new Bitmap(src);
            int w = a.Width;
            int h = a.Height;
            BitmapData srcData = a.LockBits(new Rectangle(0, 0, a.Width, a.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            QTSDK_BrightContrast((byte*)srcData.Scan0, w, h, srcData.Stride, bright, contrast, threshold);
            a.UnlockBits(srcData);
            return a;
        }
        public Bitmap QT_ColorTemperature(Bitmap src, int intensity)
        {
            Bitmap a = new Bitmap(src);
            int w = a.Width;
            int h = a.Height;
            BitmapData srcData = a.LockBits(new Rectangle(0, 0, a.Width, a.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            QTSDK_ColorTemperature((byte*)srcData.Scan0, w, h, srcData.Stride, intensity);
            a.UnlockBits(srcData);
            return a;
        }
        public Bitmap QT_HighlightShadow(Bitmap src, float highlight, float shadow)
        {
            Bitmap a = new Bitmap(src);
            int w = a.Width;
            int h = a.Height;
            BitmapData srcData = a.LockBits(new Rectangle(0, 0, a.Width, a.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            QTSDK_HighlightShadow((byte*)srcData.Scan0, w, h, srcData.Stride, highlight, shadow);
            a.UnlockBits(srcData);
            return a;
        }
        public Bitmap QT_Exposure(Bitmap src, int intensity)
        {
            Bitmap a = new Bitmap(src);
            int w = a.Width;
            int h = a.Height;
            BitmapData srcData = a.LockBits(new Rectangle(0, 0, a.Width, a.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            QTSDK_Exposure((byte*)srcData.Scan0, w, h, srcData.Stride, intensity);
            a.UnlockBits(srcData);
            return a;
        }
        public Bitmap QT_GammaCorrect(Bitmap src, int intensity)
        {
            Bitmap a = new Bitmap(src);
            int w = a.Width;
            int h = a.Height;
            BitmapData srcData = a.LockBits(new Rectangle(0, 0, a.Width, a.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            QTSDK_GammaCorrect((byte*)srcData.Scan0, w, h, srcData.Stride, intensity);
            a.UnlockBits(srcData);
            return a;
        }
        public Bitmap QT_SharpenLaplace(Bitmap src, int intensity)
        {
            Bitmap a = new Bitmap(src);
            int w = a.Width;
            int h = a.Height;
            BitmapData srcData = a.LockBits(new Rectangle(0, 0, a.Width, a.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            QTSDK_SharpenLaplace((byte*)srcData.Scan0, w, h, srcData.Stride, intensity);
            a.UnlockBits(srcData);
            return a;
        }
        public int QT_CalcWH(int[] inputImgSize, float angle, float scale, int transform_method, int[] outputImgSize, float[] H)
        {
             return QTSDK_CalcWH(inputImgSize, angle, scale, transform_method, outputImgSize, H);
        }
        public Bitmap QT_ImageTransformation(Bitmap src, Bitmap newBitmap, float[] H, int Interpolation_method, int Transform_method)
        {
            Bitmap a = new Bitmap(src);
            int w = a.Width;
            int h = a.Height;
            BitmapData srcData = a.LockBits(new Rectangle(0, 0, a.Width, a.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            BitmapData newData = newBitmap.LockBits(new Rectangle(0, 0, newBitmap.Width, newBitmap.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            QTSDK_ImageTransformation((byte*)srcData.Scan0, new int[] { w, h, srcData.Stride }, (byte*)newData.Scan0, new int[] { newBitmap.Width, newBitmap.Height, newData.Stride }, H, Interpolation_method, Transform_method);
            a.UnlockBits(srcData);
            newBitmap.UnlockBits(newData);
            return a;
        }
        public Bitmap QT_RGBA2BGRA(Bitmap src)
        {
            Bitmap a = new Bitmap(src);
            int w = a.Width;
            int h = a.Height;
            BitmapData srcData = a.LockBits(new Rectangle(0, 0, a.Width, a.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            QTSDK_RGBA2BGRA((byte*)srcData.Scan0, w, h, srcData.Stride);
            a.UnlockBits(srcData);
            return a;
        }
        public Bitmap QT_BGRA2RGBA(Bitmap src)
        {
            Bitmap a = new Bitmap(src);
            int w = a.Width;
            int h = a.Height;
            BitmapData srcData = a.LockBits(new Rectangle(0, 0, a.Width, a.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            QTSDK_BGRA2RGBA((byte*)srcData.Scan0, w, h, srcData.Stride);
            a.UnlockBits(srcData);
            return a;
        }
        public Bitmap QT_OverExposure(Bitmap src)
        {
            Bitmap a = new Bitmap(src);
            int w = a.Width;
            int h = a.Height;
            BitmapData srcData = a.LockBits(new Rectangle(0, 0, a.Width, a.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            QTSDK_OverExposure((byte*)srcData.Scan0, w, h, srcData.Stride);
            a.UnlockBits(srcData);
            return a;
        }
        public Bitmap QT_Desaturate(Bitmap src, int ratio)
        {
            Bitmap a = new Bitmap(src);
            int w = a.Width;
            int h = a.Height;
            BitmapData srcData = a.LockBits(new Rectangle(0, 0, a.Width, a.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            QTSDK_Desaturate((byte*)srcData.Scan0, w, h, srcData.Stride, ratio);
            a.UnlockBits(srcData);
            return a;
        }
        public Bitmap QT_Mosaic(Bitmap src, int size)
        {
            Bitmap a = new Bitmap(src);
            int w = a.Width;
            int h = a.Height;
            BitmapData srcData = a.LockBits(new Rectangle(0, 0, a.Width, a.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            QTSDK_Mosaic((byte*)srcData.Scan0, w, h, srcData.Stride, size);
            a.UnlockBits(srcData);
            return a;
        }
        public Bitmap QT_VirtualFilter(Bitmap src, int x, int y, int blurIntensity, int radius)
        {
            Bitmap a = new Bitmap(src);
            int w = a.Width;
            int h = a.Height;
            BitmapData srcData = a.LockBits(new Rectangle(0, 0, a.Width, a.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            QTSDK_VirtualFilter((byte*)srcData.Scan0, w, h, srcData.Stride, x, y, blurIntensity, radius);
            a.UnlockBits(srcData);
            return a;
        }
        //LUT FILTER
        public Bitmap QT_Filter(Bitmap src, Bitmap map, int ratio)
        {
            Bitmap a = new Bitmap(src);
            int w = a.Width;
            int h = a.Height;
            BitmapData srcData = a.LockBits(new Rectangle(0, 0, a.Width, a.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            BitmapData mapData = map.LockBits(new Rectangle(0, 0, map.Width, map.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            QTSDK_Filter((byte*)srcData.Scan0, w, h, srcData.Stride, (byte*)mapData.Scan0, ratio);
            map.UnlockBits(mapData);
            a.UnlockBits(srcData);
            return a;
        }
        //BEAUTY SKIN
        public Bitmap QT_BeautySkin(Bitmap src, Bitmap map, int beautyRatio, int filterRatio)
        {
            Bitmap a = new Bitmap(src);
            int w = a.Width;
            int h = a.Height;
            BitmapData srcData = a.LockBits(new Rectangle(0, 0, a.Width, a.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            if (map != null)
            {
                BitmapData mapData = map.LockBits(new Rectangle(0, 0, map.Width, map.Height), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
                QTSDK_BeautySkin((byte*)srcData.Scan0, w, h, srcData.Stride, (byte*)mapData.Scan0, beautyRatio, filterRatio);
                map.UnlockBits(mapData);
            }
            else
            {
                QTSDK_BeautySkin((byte*)srcData.Scan0, w, h, srcData.Stride, null, beautyRatio, filterRatio);
            }
            a.UnlockBits(srcData);
            return a;
        }
    }
}
