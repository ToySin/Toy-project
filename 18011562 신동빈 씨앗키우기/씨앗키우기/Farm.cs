using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace 씨앗키우기
{
    class Farm
    {
        public string Name = "밭";
        public string Category { get; set; }
        public int Level { get; set; }
        public int Sun { get; set; }
        public int Water { get; set; }
        private string direct = Directory.GetCurrentDirectory();
        public Image[] Pic = new Image[2];
       
        public Farm()
        {
            StreamReader sr
                = new StreamReader(new FileStream("save.txt", FileMode.Open));
            Level = Convert.ToInt32(sr.ReadLine());
            Category = sr.ReadLine();
            Sun = Convert.ToInt32(sr.ReadLine());
            Water = Convert.ToInt32(sr.ReadLine());
            sr.Close();
            UpdatePic();
            check();
        }
        public void UpdatePic()
        {
            if (Level == 0)
            {
                Pic[0] = Image.FromFile(direct + "/image/밭.PNG");
                Pic[1] = Image.FromFile(direct + "/image/밭.PNG");
            }
            else if (Level == 1)
            {
                Pic[0] = Image.FromFile(direct + "/image/씨앗1.PNG");
                Pic[1] = Image.FromFile(direct + "/image/씨앗2.PNG");
            }
            else if (Level == 2)
            {
                Pic[0] = Image.FromFile(direct + "/image/새순1.PNG");
                Pic[1] = Image.FromFile(direct + "/image/새순2.PNG");
            }
            else if (Level == 3)
            {
                if (Category == "나무")
                {
                    Pic[0] = Image.FromFile(direct + "/image/떡잎1.PNG");
                    Pic[1] = Image.FromFile(direct + "/image/떡잎2.PNG");
                }
                else if (Category == "선인장")
                {
                    Pic[0] = Image.FromFile(direct + "/image/아기선인장1.PNG");
                    Pic[1] = Image.FromFile(direct + "/image/아기선인장2.PNG");
                }
                else
                {
                    Pic[0] = Image.FromFile(direct + "/image/작은해초1.PNG");
                    Pic[1] = Image.FromFile(direct + "/image/작은해초2.PNG");
                }
            }
            else if (Level == 4)
            {
                if (Category == "나무")
                {
                    Pic[0] = Image.FromFile(direct + "/image/나무1.PNG");
                    Pic[1] = Image.FromFile(direct + "/image/나무2.PNG");
                }
                else if (Category == "선인장")
                {
                    Pic[0] = Image.FromFile(direct + "/image/어른선인장1.PNG");
                    Pic[1] = Image.FromFile(direct + "/image/어른선인장2.PNG");
                }
                else
                {
                    Pic[0] = Image.FromFile(direct + "/image/미역1.PNG");
                    Pic[1] = Image.FromFile(direct + "/image/미역2.PNG");
                }
            }
            else if (Level == 5)
            {
                if (Category == "나무")
                {
                    Pic[0] = Image.FromFile(direct + "/image/사과나무1.PNG");
                    Pic[1] = Image.FromFile(direct + "/image/사과나무2.PNG");
                }
                else if (Category == "선인장")
                {
                    Pic[0] = Image.FromFile(direct + "/image/넘어진선인장1.PNG");
                    Pic[1] = Image.FromFile(direct + "/image/넘어진선인장2.PNG");
                }
                else
                {
                    Pic[0] = Image.FromFile(direct + "/image/들깨미역국1.PNG");
                    Pic[1] = Image.FromFile(direct + "/image/들깨미역국2.PNG");
                }
            }
        }

        public void plantSeed()
        {
            Name = "씨앗";
            Level = 1;
            Sun = 10;
            Water = 10;
            UpdatePic();
        }
        
        public void check()
        {
            if (Sun + Water > 3000)
            {
                if (Category == "선인장")
                {
                    Name = "넘어진선인장";
                }
                else if (Category == "해초")
                {
                    Name = "들깨미역국";
                }
                else
                {
                    Name = "사과나무";
                }
                Level = 5;
            }

            else if (Sun + Water > 1600)
            {
                if (Category == "선인장")
                {
                    Name = "어른선인장";
                }
                else if (Category == "해초")
                {
                    Name = "미역";
                }
                else
                {
                    Name = "나무";
                }
                Level = 4;
            }

            else if (Sun + Water > 900)
            {
                if (Sun > Water + 500)
                {
                    Name = "아기선인장";
                    Category = "선인장";
                }
                else if (Sun + 500 < Water)
                {
                    Name = "작은해초";
                    Category = "해초";
                }
                else
                {
                    Name = "떡잎";
                    Category = "나무";
                }
                Level = 3;
            }

            else if (Sun + Water > 170)
            {
                Name = "새순";
                Level = 2;
            }

            UpdatePic();
        }
        
        public void giveSun()
        {
            Sun += Level * 10;
            check();
        }

        public void giveWater()
        {
            Water += Level * 10;
            check();
        }

        public void plantOff()
        {
            Name = "밭";
            Level = 0;
            Sun = 0;
            Water = 0;
            UpdatePic();
        }
    }
}
