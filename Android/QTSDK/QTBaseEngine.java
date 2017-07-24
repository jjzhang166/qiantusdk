package QTSDK;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;

import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.Bitmap.Config;
import android.util.Log;

public class QTBaseEngine {
	static {
	      System.loadLibrary("QTBASESDK");
	      Log.d("loadlibrary","load QTBASESDK done!");
	  }
		private static String LOG_TAG = "QTBASESDK";
	    public static AssetManager assetMgr = null;
		
		public static void initLib(AssetManager am) {
			assetMgr = am;
		}
		
		public static InputStream open_file_binary(String filepath) {
			InputStream stream = null;

			try {
				if (filepath == null)
					return null;
				
				stream = assetMgr.open(filepath);
				if (stream == null)
					return null;
				
				int len = stream.available();
				if (!stream.markSupported())
					Log.d(LOG_TAG, "markSupported = flase");
				stream.mark(len);
			} catch (IOException e) {
				Log.e(LOG_TAG, e.getMessage());
				
				if (e instanceof FileNotFoundException) {
					try {
						stream = new FileInputStream(filepath);
						
						int len = stream.available();
						if (!stream.markSupported())
							Log.d(LOG_TAG, "markSupported = flase");
						stream.mark(len);
					} catch (Exception e2) {
						Log.e(LOG_TAG, e2.getMessage());
					}
				}
			}

			return stream;
		}
		/////
		private native static int native_QTSDK_Saturation(Bitmap srcBitmap,int saturation);
		private native static int native_QTSDK_Lightness(Bitmap bitmap, int lightness);
		private native static int native_QTSDK_HueAndSaturation(Bitmap bitmap, int hue, int saturation);
		private native static int native_QTSDK_BrightContrast(Bitmap bitmap, int bright, int contrast, int threshold);
		private native static int native_QTSDK_ColorTemperature(Bitmap bitmap, int intensity);
		private native static int native_QTSDK_HighlightShadow(Bitmap bitmap, float highlight, float shadow);
		private native static int native_QTSDK_Exposure(Bitmap bitmap, int intensity);
		private native static int native_QTSDK_GammaCorrect(Bitmap bitmap, int intensity);
		private native static int native_QTSDK_CalcWH(int[] inputImgSize, float angle, float scale, int transform_method, int[] outputImgSize,float[] H);
		private native static int native_QTSDK_ImageTransformation(Bitmap bitmap,Bitmap dstbitmap, float[] H, int Interpolation_method, int Transform_method);
		private native static int native_QTSDK_OverExposure(Bitmap bitmap);
		private native static int native_QTSDK_Desaturate(Bitmap bitmap, int ratio);
	    private native static int native_QTSDK_Mosaic(Bitmap bitmap, int size);
	    private native static int native_QTSDK_VirtualFilter(Bitmap bitmap,int x, int y, int blurIntensity, int radius);
	    private native static int native_QTSDK_Sharpen(Bitmap bitmap, int intensity);
	    private native static int native_QTSDK_Filter(Bitmap bitmap, Bitmap map, int ratio);
	    private native static int native_QTSDK_BeautySkin(Bitmap bitmap, Bitmap map, int beautyRatio, int filterRatio);
		/////
		public Bitmap QTSDK_Sharpen(Bitmap srcBitmap,int intensity){
	  		
	  		Bitmap curBitmap = srcBitmap.copy(srcBitmap.getConfig(), false);
	  		native_QTSDK_Sharpen(curBitmap, intensity);		
	  		return curBitmap;
	      }
		public Bitmap QTSDK_Saturation(Bitmap srcBitmap,int saturation) {
				
				Bitmap curBitmap = srcBitmap.copy(srcBitmap.getConfig(), false);
				native_QTSDK_Saturation(curBitmap, saturation);		
				return curBitmap;
		}
		public Bitmap QTSDK_Lightness(Bitmap srcBitmap,int lightness) {
				
				Bitmap curBitmap = srcBitmap.copy(srcBitmap.getConfig(), false);
				native_QTSDK_Lightness(curBitmap, lightness);		
				return curBitmap;
		}
		public Bitmap QTSDK_HueAndSaturation(Bitmap srcBitmap, int hue, int saturation) {
			
			Bitmap curBitmap = srcBitmap.copy(srcBitmap.getConfig(), false);
			native_QTSDK_HueAndSaturation(curBitmap, hue, saturation);		
			return curBitmap;
	    }
	    public Bitmap QTSDK_BrightContrast(Bitmap srcBitmap, int bright, int contrast, int threshold) 
	    {		
			Bitmap curBitmap = srcBitmap.copy(srcBitmap.getConfig(), false);
			native_QTSDK_BrightContrast(curBitmap, bright, contrast, threshold);		
			return curBitmap;
	    }
	    public Bitmap QTSDK_ColorTemperature(Bitmap srcBitmap, int intensity) {
			
			Bitmap curBitmap = srcBitmap.copy(srcBitmap.getConfig(), false);
			native_QTSDK_ColorTemperature(curBitmap, intensity);		
			return curBitmap;
	    }
	    public Bitmap QTSDK_HighlightShadow(Bitmap srcBitmap, float highlight, float shadow) {
			
			Bitmap curBitmap = srcBitmap.copy(srcBitmap.getConfig(), false);
			native_QTSDK_HighlightShadow(curBitmap, highlight, shadow);		
			return curBitmap;
	    }
	    public Bitmap QTSDK_Exposure(Bitmap srcBitmap, int intensity) {
			
			Bitmap curBitmap = srcBitmap.copy(srcBitmap.getConfig(), false);
			native_QTSDK_Exposure(curBitmap, intensity);		
			return curBitmap;
	    }
	    public Bitmap QTSDK_GammaCorrect(Bitmap srcBitmap, int intensity) {
			
			Bitmap curBitmap = srcBitmap.copy(srcBitmap.getConfig(), false);
			native_QTSDK_GammaCorrect(curBitmap, intensity);		
			return curBitmap;
	    }
	    public void QTSDK_CalcWH(int[] inputImgSize, float angle, float scale, int transform_method, int[] outputImgSize,float[] H)
	    {
	    	native_QTSDK_CalcWH(inputImgSize, angle, scale, transform_method, outputImgSize,H);
	    }
	    public Bitmap QTSDK_ImageTransformation(Bitmap srcBitmap, int angle, float scale, int Interpolation_method) {
	    	int Transform_method = 1;
	    	Bitmap curBitmap = srcBitmap.copy(srcBitmap.getConfig(), false);
	    	if(angle == 90)
	    	{
	    		Transform_method = 7;
	    	}
	    	else if(angle == 180)
	    	{
	    		Transform_method = 8;
	    	}
	    	else if(angle == 270)
	    	{
	    		Transform_method = 9;
	    	}
	    	else
	    	{
	    		return curBitmap;
	    	}    	
			
			int stride = curBitmap.getWidth()*4;
			stride =( (stride % 4) == 0 ? stride : (stride + 4 - stride % 4));
			int[]mImgSize = new int[]{curBitmap.getWidth(), curBitmap.getHeight(), stride}; 
			float[] H = new float[]{0,0,0,0,0,0};
			int[]dstImgSize = new int[]{0,0,0};
			native_QTSDK_CalcWH(mImgSize, (float)angle, scale, Transform_method, dstImgSize, H);
			if(dstImgSize[0] == 0||dstImgSize[1] == 0)
				return curBitmap;
			Bitmap dstBitmap = Bitmap.createBitmap(dstImgSize[0], dstImgSize[1], Config.ARGB_8888);
			native_QTSDK_ImageTransformation(curBitmap, dstBitmap, H, Interpolation_method, Transform_method);		
			curBitmap.recycle();
			return dstBitmap;
	    }
	   
	    public Bitmap QTSDK_OverExposure(Bitmap srcBitmap) {
			
			Bitmap curBitmap = srcBitmap.copy(srcBitmap.getConfig(), false);
			native_QTSDK_OverExposure(curBitmap);		
			return curBitmap;
	    }
	    
	    public Bitmap QTSDK_Desaturate(Bitmap srcBitmap, int ratio) {
			
			Bitmap curBitmap = srcBitmap.copy(srcBitmap.getConfig(), false);
			native_QTSDK_Desaturate(curBitmap, ratio);		
			return curBitmap;
	    }

	     public Bitmap QTSDK_Mosaic(Bitmap srcBitmap, int size) {
	  		
	  		Bitmap curBitmap = srcBitmap.copy(srcBitmap.getConfig(), false);
	  		native_QTSDK_Mosaic(curBitmap, size);		
	  		return curBitmap;
	      }
	    
	     public Bitmap QTSDK_VirtualFilter(Bitmap srcBitmap, int x, int y, int blurIntensity, int radius) {
	    		
	    		Bitmap curBitmap = srcBitmap.copy(srcBitmap.getConfig(), false);
	    		native_QTSDK_VirtualFilter(curBitmap, x, y, blurIntensity, radius);		
	    		return curBitmap;
	        }
	        public Bitmap QTSDK_Filter(Bitmap srcBitmap,Bitmap map, int ratio){
		  		
		  		Bitmap curBitmap = srcBitmap.copy(srcBitmap.getConfig(), false);
		  		Bitmap mapBitmap = map.copy(map.getConfig(), false);
		  		native_QTSDK_Filter(curBitmap, mapBitmap, ratio);		
		  		return curBitmap;
		      }
	        public Bitmap QTSDK_BeautySkin(Bitmap srcBitmap,Bitmap map, int beautyRatio, int filterRatio){
		  		
		  		Bitmap curBitmap = srcBitmap.copy(srcBitmap.getConfig(), false);
		  		Bitmap mapBitmap = map.copy(map.getConfig(), false);
		  		native_QTSDK_BeautySkin(curBitmap, mapBitmap, beautyRatio, filterRatio);		
		  		return curBitmap;
		      }

}
