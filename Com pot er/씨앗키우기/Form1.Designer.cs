namespace 씨앗키우기
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.plant_btn = new System.Windows.Forms.Button();
            this.plantoff_btn = new System.Windows.Forms.Button();
            this.water_btn = new System.Windows.Forms.Button();
            this.sun_btn = new System.Windows.Forms.Button();
            this.sun_label = new System.Windows.Forms.Label();
            this.water_label = new System.Windows.Forms.Label();
            this.name_label = new System.Windows.Forms.Label();
            this.save_btn = new System.Windows.Forms.Button();
            this.graphic_timer = new System.Windows.Forms.Timer(this.components);
            this.picture_label = new System.Windows.Forms.Label();
            this.condition_label = new System.Windows.Forms.Label();
            this.issun_label = new System.Windows.Forms.Label();
            this.iswater_label = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // plant_btn
            // 
            this.plant_btn.Location = new System.Drawing.Point(12, 218);
            this.plant_btn.Name = "plant_btn";
            this.plant_btn.Size = new System.Drawing.Size(200, 56);
            this.plant_btn.TabIndex = 1;
            this.plant_btn.Text = "씨앗심기";
            this.plant_btn.UseVisualStyleBackColor = true;
            this.plant_btn.Click += new System.EventHandler(this.Plant_btn_Click);
            // 
            // plantoff_btn
            // 
            this.plantoff_btn.Location = new System.Drawing.Point(218, 218);
            this.plantoff_btn.Name = "plantoff_btn";
            this.plantoff_btn.Size = new System.Drawing.Size(200, 56);
            this.plantoff_btn.TabIndex = 2;
            this.plantoff_btn.Text = "뽑아내기";
            this.plantoff_btn.UseVisualStyleBackColor = true;
            this.plantoff_btn.Click += new System.EventHandler(this.Plantoff_btn_Click);
            // 
            // water_btn
            // 
            this.water_btn.Location = new System.Drawing.Point(218, 280);
            this.water_btn.Name = "water_btn";
            this.water_btn.Size = new System.Drawing.Size(200, 56);
            this.water_btn.TabIndex = 3;
            this.water_btn.Text = "물주기";
            this.water_btn.UseVisualStyleBackColor = true;
            this.water_btn.Click += new System.EventHandler(this.Water_btn_Click);
            // 
            // sun_btn
            // 
            this.sun_btn.Location = new System.Drawing.Point(12, 280);
            this.sun_btn.Name = "sun_btn";
            this.sun_btn.Size = new System.Drawing.Size(200, 56);
            this.sun_btn.TabIndex = 4;
            this.sun_btn.Text = "햇빛쬐기";
            this.sun_btn.UseVisualStyleBackColor = true;
            this.sun_btn.Click += new System.EventHandler(this.Sun_btn_Click);
            // 
            // sun_label
            // 
            this.sun_label.AutoSize = true;
            this.sun_label.Location = new System.Drawing.Point(218, 111);
            this.sun_label.Name = "sun_label";
            this.sun_label.Size = new System.Drawing.Size(38, 12);
            this.sun_label.TabIndex = 5;
            this.sun_label.Text = "label1";
            // 
            // water_label
            // 
            this.water_label.AutoSize = true;
            this.water_label.Location = new System.Drawing.Point(218, 138);
            this.water_label.Name = "water_label";
            this.water_label.Size = new System.Drawing.Size(38, 12);
            this.water_label.TabIndex = 6;
            this.water_label.Text = "label2";
            // 
            // name_label
            // 
            this.name_label.AutoSize = true;
            this.name_label.Location = new System.Drawing.Point(218, 84);
            this.name_label.Name = "name_label";
            this.name_label.Size = new System.Drawing.Size(38, 12);
            this.name_label.TabIndex = 7;
            this.name_label.Text = "label3";
            // 
            // save_btn
            // 
            this.save_btn.Location = new System.Drawing.Point(218, 156);
            this.save_btn.Name = "save_btn";
            this.save_btn.Size = new System.Drawing.Size(200, 56);
            this.save_btn.TabIndex = 9;
            this.save_btn.Text = "저장하기";
            this.save_btn.UseVisualStyleBackColor = true;
            this.save_btn.Click += new System.EventHandler(this.Save_btn_Click);
            // 
            // graphic_timer
            // 
            this.graphic_timer.Enabled = true;
            this.graphic_timer.Interval = 660;
            this.graphic_timer.Tick += new System.EventHandler(this.Graphic_timer_Tick);
            // 
            // picture_label
            // 
            this.picture_label.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.picture_label.Location = new System.Drawing.Point(12, 12);
            this.picture_label.Name = "picture_label";
            this.picture_label.Size = new System.Drawing.Size(200, 200);
            this.picture_label.TabIndex = 10;
            // 
            // condition_label
            // 
            this.condition_label.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.condition_label.Location = new System.Drawing.Point(220, 12);
            this.condition_label.Name = "condition_label";
            this.condition_label.Size = new System.Drawing.Size(65, 65);
            this.condition_label.TabIndex = 11;
            // 
            // issun_label
            // 
            this.issun_label.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.issun_label.Location = new System.Drawing.Point(291, 12);
            this.issun_label.Name = "issun_label";
            this.issun_label.Size = new System.Drawing.Size(65, 65);
            this.issun_label.TabIndex = 12;
            // 
            // iswater_label
            // 
            this.iswater_label.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.iswater_label.Location = new System.Drawing.Point(362, 12);
            this.iswater_label.Name = "iswater_label";
            this.iswater_label.Size = new System.Drawing.Size(65, 65);
            this.iswater_label.TabIndex = 13;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(430, 347);
            this.Controls.Add(this.iswater_label);
            this.Controls.Add(this.issun_label);
            this.Controls.Add(this.condition_label);
            this.Controls.Add(this.picture_label);
            this.Controls.Add(this.save_btn);
            this.Controls.Add(this.name_label);
            this.Controls.Add(this.water_label);
            this.Controls.Add(this.sun_label);
            this.Controls.Add(this.sun_btn);
            this.Controls.Add(this.water_btn);
            this.Controls.Add(this.plantoff_btn);
            this.Controls.Add(this.plant_btn);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button plant_btn;
        private System.Windows.Forms.Button plantoff_btn;
        private System.Windows.Forms.Button water_btn;
        private System.Windows.Forms.Button sun_btn;
        private System.Windows.Forms.Label sun_label;
        private System.Windows.Forms.Label water_label;
        private System.Windows.Forms.Label name_label;
        private System.Windows.Forms.Button save_btn;
        private System.Windows.Forms.Timer graphic_timer;
        private System.Windows.Forms.Label picture_label;
        private System.Windows.Forms.Label condition_label;
        private System.Windows.Forms.Label issun_label;
        private System.Windows.Forms.Label iswater_label;
    }
}

