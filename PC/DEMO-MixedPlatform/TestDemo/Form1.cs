using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Imaging;
using System.IO;

namespace TestDemo
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        #region  Variables
        //image  path
        private String curFileName = null;
        //curren image instance
        private Bitmap curBitmap = null;
        //source image instance
        private Bitmap srcBitmap = null;
        //QTSDK instance
        QTSDK qt = new QTSDK();
        //bright
        private int brightValue = 0;
        //contrast
        private int contrastValue = 0;
        //light
        private int lightValue = 0;
        //saturation
        private int saturationValue = 0;
        //temperature
        private int temperatureValue = 0;
        //highlight
        private int highlightValue = 0;
        //shadow
        private int shadowValue = 0;
        //exposure
        private int exposureValue = 0;
        //gamma
        private int gammaValue = 0;
        //sharpen
        private int sharpenValue = 0;
        //desaturate
        private int desaturateValue = 0;
        //moscia
        private int mosciaValue = 0;
        //viatual filter
        private int virtualValue = 0;
        //softRatio
        private int softValue = 0;
        //filterRatio
        private int filterValue = 0;
        #endregion

        #region  Image Open&Save
        //open image
        public void OpenFile()
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "所有图像文件 | *.bmp; *.pcx; *.png; *.jpg; *.gif;" +
                   "*.tif; *.ico; *.dxf; *.cgm; *.cdr; *.wmf; *.eps; *.emf|" +
                   "位图( *.bmp; *.jpg; *.png;...) | *.bmp; *.pcx; *.png; *.jpg; *.gif; *.tif; *.ico|" +
                   "矢量图( *.wmf; *.eps; *.emf;...) | *.dxf; *.cgm; *.cdr; *.wmf; *.eps; *.emf";
            ofd.ShowHelp = true;
            ofd.Title = "打开图像文件";
            if (ofd.ShowDialog() == DialogResult.OK)
            {
                curFileName = ofd.FileName;
                try
                {
                    curBitmap = (Bitmap)System.Drawing.Image.FromFile(curFileName);
                    srcBitmap = new Bitmap(curBitmap);
                }
                catch (Exception exp)
                { MessageBox.Show(exp.Message); }
            }
        }
        //save image
        public void SaveFile()
        {
            SaveFileDialog sfd = new SaveFileDialog();
            sfd.Filter = @"Bitmap文件(*.bmp)|*.bmp|Jpeg文件(*.jpg)|*.jpg|PNG文件(*.png)|*.png|所有合适文件(*.bmp,*.jpg,*.png)|*.bmp;*.jpg;*.png";
            sfd.FilterIndex = 3;
            sfd.RestoreDirectory = true;
            if (sfd.ShowDialog() == DialogResult.OK)
            {
                ImageFormat format = ImageFormat.Jpeg;
                switch (Path.GetExtension(sfd.FileName).ToLower())
                {
                    case ".jpg":
                        format = ImageFormat.Jpeg;
                        break;
                    case ".bmp":
                        format = ImageFormat.Bmp;
                        break;
                    case ".png":
                        format = ImageFormat.Png;
                        break;
                    default:
                        MessageBox.Show("Unsupported image format was specified!");
                        return;
                }
                pictureBox1.Image.Save(sfd.FileName, format);
            }

        }
        //Open
        private void openBtn_Click(object sender, EventArgs e)
        {
            OpenFile();
            if (curBitmap != null)
            {
                pictureBox1.Image = (Image)curBitmap;
            }
        }
        //Save
        private void saveBtn_Click(object sender, EventArgs e)
        {
            if (pictureBox1.Image != null)
                SaveFile();
        }
        #endregion

        
        //contrast
        private void hScrollBar1_Scroll(object sender, ScrollEventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                textBox1.Text = hScrollBar1.Value.ToString();
                contrastValue = hScrollBar1.Value;
                curBitmap = qt.QT_BrightContrast(srcBitmap, brightValue, contrastValue, 128);
                pictureBox1.Image = curBitmap;
            }
        }
        //birght
        private void hScrollBar3_Scroll(object sender, ScrollEventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                textBox3.Text = hScrollBar3.Value.ToString();
                brightValue = hScrollBar3.Value;
                curBitmap = qt.QT_BrightContrast(srcBitmap, brightValue, contrastValue, 128);
                pictureBox1.Image = curBitmap;
            }
        }
        //lightness
        private void hScrollBar2_Scroll(object sender, ScrollEventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                textBox2.Text = hScrollBar2.Value.ToString();
                lightValue = hScrollBar2.Value;
                curBitmap = qt.QT_Lightness(srcBitmap, lightValue);
                pictureBox1.Image = curBitmap;
            }
        }
        //saturation
        private void hScrollBar4_Scroll(object sender, ScrollEventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                textBox4.Text = hScrollBar4.Value.ToString();
                saturationValue = hScrollBar4.Value;
                curBitmap = qt.QT_Saturation(srcBitmap, saturationValue);
                pictureBox1.Image = curBitmap;
            }
        }
        //color temperature
        private void hScrollBar5_Scroll(object sender, ScrollEventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                textBox5.Text = hScrollBar5.Value.ToString();
                temperatureValue = hScrollBar5.Value;
                curBitmap = qt.QT_ColorTemperature(srcBitmap, temperatureValue);
                pictureBox1.Image = curBitmap;
            }
        }
        //highlight
        private void hScrollBar6_Scroll(object sender, ScrollEventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                textBox6.Text = hScrollBar6.Value.ToString();
                highlightValue = hScrollBar6.Value;
                curBitmap = qt.QT_HighlightShadow(srcBitmap, highlightValue,shadowValue);
                pictureBox1.Image = curBitmap;
            }
        }
        //shadow
        private void hScrollBar7_Scroll(object sender, ScrollEventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                textBox7.Text = hScrollBar7.Value.ToString();
                shadowValue = hScrollBar7.Value;
                curBitmap = qt.QT_HighlightShadow(srcBitmap, highlightValue, shadowValue);
                pictureBox1.Image = curBitmap;
            }
        }

        private void hScrollBar8_Scroll(object sender, ScrollEventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                textBox8.Text = hScrollBar8.Value.ToString();
                exposureValue = hScrollBar8.Value;
                curBitmap = qt.QT_Exposure(srcBitmap, exposureValue);
                pictureBox1.Image = curBitmap;
            }
        }

        private void hScrollBar9_Scroll(object sender, ScrollEventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                textBox9.Text = hScrollBar9.Value.ToString();
                gammaValue = hScrollBar9.Value;
                curBitmap = qt.QT_GammaCorrect(srcBitmap, gammaValue);
                pictureBox1.Image = curBitmap;
            }
        }

        private void hScrollBar10_Scroll(object sender, ScrollEventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                textBox10.Text = hScrollBar10.Value.ToString();
                shadowValue = hScrollBar10.Value;
                curBitmap = qt.QT_SharpenLaplace(srcBitmap, sharpenValue);
                pictureBox1.Image = curBitmap;
            }
        }

        private void hScrollBar11_Scroll(object sender, ScrollEventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                textBox11.Text = hScrollBar11.Value.ToString();
                desaturateValue = hScrollBar11.Value;
                curBitmap = qt.QT_Desaturate(srcBitmap, desaturateValue);
                pictureBox1.Image = curBitmap;
            }
        }

        private void hScrollBar12_Scroll(object sender, ScrollEventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                textBox12.Text = hScrollBar12.Value.ToString();
                mosciaValue = hScrollBar12.Value;
                curBitmap = qt.QT_Mosaic(srcBitmap, mosciaValue);
                pictureBox1.Image = curBitmap;
            }
        }

        private void hScrollBar13_Scroll(object sender, ScrollEventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                textBox13.Text = hScrollBar13.Value.ToString();
                virtualValue = hScrollBar13.Value;
                curBitmap = qt.QT_VirtualFilter(srcBitmap, srcBitmap.Width / 2, srcBitmap.Height / 2,virtualValue, 100);
                pictureBox1.Image = curBitmap;
            }
        }
        //over exposure
        private void button1_Click(object sender, EventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                curBitmap = qt.QT_OverExposure(srcBitmap);
                pictureBox1.Image = curBitmap;
            }
        }
        //beauty skin
        private void hScrollBar14_Scroll(object sender, ScrollEventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                textBox14.Text = hScrollBar14.Value.ToString();
                softValue = hScrollBar14.Value;
                curBitmap = qt.QT_BeautySkin(srcBitmap,new Bitmap (Application.StartupPath + "\\beauty.png"),softValue,filterValue);
                //curBitmap = qt.QT_BeautySkin(srcBitmap, null, softValue, filterValue);
                pictureBox1.Image = curBitmap;
            }
        }

        private void hScrollBar15_Scroll(object sender, ScrollEventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                textBox15.Text = hScrollBar15.Value.ToString();
                filterValue = hScrollBar15.Value;
                curBitmap = qt.QT_BeautySkin(srcBitmap, new Bitmap(Application.StartupPath + "\\beauty.png"), softValue, filterValue);
                pictureBox1.Image = curBitmap;
            }
        }

        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            if (srcBitmap != null)
                pictureBox1.Image = srcBitmap;
        }

        private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
        {
            if (curBitmap != null)
                pictureBox1.Image = curBitmap;
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                switch (comboBox1.SelectedIndex)
                {
                    case 0:
                        curBitmap = qt.QT_Filter(srcBitmap, new Bitmap(Application.StartupPath + "\\Filter\\rixi.png"), 100);
                        break;
                    case 1:
                        curBitmap = qt.QT_Filter(srcBitmap, new Bitmap(Application.StartupPath + "\\Filter\\abaose.png"), 100);
                        break;
                    case 2:
                        curBitmap = qt.QT_Filter(srcBitmap, new Bitmap(Application.StartupPath + "\\Filter\\bingling.png"), 100);
                        break;
                    case 3:
                        curBitmap = qt.QT_Filter(srcBitmap, new Bitmap(Application.StartupPath + "\\Filter\\fenen.png"), 100);
                        break;
                    case 4:
                        curBitmap = qt.QT_Filter(srcBitmap, new Bitmap(Application.StartupPath + "\\Filter\\qingchun.png"), 100);
                        break;
                    case 5:
                        curBitmap = qt.QT_Filter(srcBitmap, new Bitmap(Application.StartupPath + "\\Filter\\ziyun.png"), 100);
                        break;
                    default:
                        break;
                }
                pictureBox1 .Image = curBitmap;
            }
        }
    }
}
