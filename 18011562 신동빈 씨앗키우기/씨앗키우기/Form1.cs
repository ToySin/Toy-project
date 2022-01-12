using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace 씨앗키우기
{
    public partial class Form1 : Form
    {
        Farm farm;
        int index = 0;
        public Form1()
        {
            InitializeComponent();
            farm = new Farm();
            farm.UpdatePic();
            farm.check();
            name_label.Text = farm.Name;
            sun_label.Text = "Sun: " + farm.Sun.ToString();
            water_label.Text = "Water: " + farm.Water.ToString();
        }

        public void UpdateForm()
        {
            name_label.Text = farm.Name;
            sun_label.Text = "Sun: " + farm.Sun.ToString();
            water_label.Text = "Water: " + farm.Water.ToString();
        }

        private void Plant_btn_Click(object sender, EventArgs e)
        {
            farm.plantSeed();
            UpdateForm();
        }

        private void Plantoff_btn_Click(object sender, EventArgs e)
        {
            farm.plantOff();
            UpdateForm();
        }

        private void Sun_btn_Click(object sender, EventArgs e)
        {
            farm.giveSun();
            UpdateForm();
        }

        private void Water_btn_Click(object sender, EventArgs e)
        {
            farm.giveWater();
            UpdateForm();
        }

        private void Save_btn_Click(object sender, EventArgs e)
        {
            StreamWriter sw
                = new StreamWriter(new FileStream("save.txt", FileMode.Create));
            sw.WriteLine(farm.Level);
            sw.WriteLine(farm.Category);
            sw.WriteLine(farm.Sun);
            sw.WriteLine(farm.Water);
            sw.Close();
        }

        private void Graphic_timer_Tick(object sender, EventArgs e)
        {
            if (index == 0)
                picture_label.Image = farm.Pic[index++];
            else
                picture_label.Image = farm.Pic[index--];            
        }
    }
}
