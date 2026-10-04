namespace PizzaProject
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }
       
        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.PanSize = new System.Windows.Forms.Panel();
            this.LabSize = new System.Windows.Forms.Label();
            this.BtnLarge = new System.Windows.Forms.RadioButton();
            this.BtnMed = new System.Windows.Forms.RadioButton();
            this.BtnSmall = new System.Windows.Forms.RadioButton();
            this.labText = new System.Windows.Forms.Label();
            this.PanToppings = new System.Windows.Forms.Panel();
            this.CheckGreenPaper = new System.Windows.Forms.CheckBox();
            this.CheckOlives = new System.Windows.Forms.CheckBox();
            this.CheckOnion = new System.Windows.Forms.CheckBox();
            this.CheckTomato = new System.Windows.Forms.CheckBox();
            this.CheckMushroom = new System.Windows.Forms.CheckBox();
            this.checkExtraCheese = new System.Windows.Forms.CheckBox();
            this.labToppings = new System.Windows.Forms.Label();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.backgroundWorker2 = new System.ComponentModel.BackgroundWorker();
            this.panel1 = new System.Windows.Forms.Panel();
            this.btnThink = new System.Windows.Forms.RadioButton();
            this.btnThin = new System.Windows.Forms.RadioButton();
            this.PanCrust = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.btnTakeout = new System.Windows.Forms.RadioButton();
            this.btnEatIn = new System.Windows.Forms.RadioButton();
            this.lapToEat = new System.Windows.Forms.Label();
            this.panel3 = new System.Windows.Forms.Panel();
            this.label10 = new System.Windows.Forms.Label();
            this.ToEat = new System.Windows.Forms.Label();
            this.labCrust = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.LapPrintSize = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.btnorder = new System.Windows.Forms.Button();
            this.btnReset = new System.Windows.Forms.Button();
            this.PanSize.SuspendLayout();
            this.PanToppings.SuspendLayout();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.panel3.SuspendLayout();
            this.SuspendLayout();
            // 
            // PanSize
            // 
            this.PanSize.BackColor = System.Drawing.Color.Transparent;
            this.PanSize.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.PanSize.Controls.Add(this.BtnLarge);
            this.PanSize.Controls.Add(this.BtnMed);
            this.PanSize.Controls.Add(this.BtnSmall);
            this.PanSize.Controls.Add(this.LabSize);
            this.PanSize.ForeColor = System.Drawing.Color.LightGoldenrodYellow;
            this.PanSize.Location = new System.Drawing.Point(365, 240);
            this.PanSize.Name = "PanSize";
            this.PanSize.Size = new System.Drawing.Size(164, 192);
            this.PanSize.TabIndex = 0;
            // 
            // LabSize
            // 
            this.LabSize.AutoSize = true;
            this.LabSize.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.LabSize.ForeColor = System.Drawing.Color.Gold;
            this.LabSize.Location = new System.Drawing.Point(3, 0);
            this.LabSize.Name = "LabSize";
            this.LabSize.Size = new System.Drawing.Size(74, 32);
            this.LabSize.TabIndex = 1;
            this.LabSize.Text = "Size";
            this.LabSize.Click += new System.EventHandler(this.label1_Click);
            // 
            // BtnLarge
            // 
            this.BtnLarge.AutoSize = true;
            this.BtnLarge.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.BtnLarge.ForeColor = System.Drawing.Color.Gold;
            this.BtnLarge.Location = new System.Drawing.Point(19, 141);
            this.BtnLarge.Name = "BtnLarge";
            this.BtnLarge.Size = new System.Drawing.Size(88, 29);
            this.BtnLarge.TabIndex = 2;
            this.BtnLarge.TabStop = true;
            this.BtnLarge.Text = "Large";
            this.BtnLarge.UseVisualStyleBackColor = true;
            this.BtnLarge.CheckedChanged += new System.EventHandler(this.radioButton3_CheckedChanged);
            // 
            // BtnMed
            // 
            this.BtnMed.AutoSize = true;
            this.BtnMed.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.BtnMed.ForeColor = System.Drawing.Color.Gold;
            this.BtnMed.Location = new System.Drawing.Point(19, 90);
            this.BtnMed.Name = "BtnMed";
            this.BtnMed.Size = new System.Drawing.Size(115, 29);
            this.BtnMed.TabIndex = 1;
            this.BtnMed.TabStop = true;
            this.BtnMed.Text = "Medium ";
            this.BtnMed.UseVisualStyleBackColor = true;
            this.BtnMed.CheckedChanged += new System.EventHandler(this.radioButton2_CheckedChanged);
            // 
            // BtnSmall
            // 
            this.BtnSmall.AutoSize = true;
            this.BtnSmall.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.BtnSmall.ForeColor = System.Drawing.Color.Gold;
            this.BtnSmall.Location = new System.Drawing.Point(19, 39);
            this.BtnSmall.Name = "BtnSmall";
            this.BtnSmall.Size = new System.Drawing.Size(87, 29);
            this.BtnSmall.TabIndex = 0;
            this.BtnSmall.TabStop = true;
            this.BtnSmall.Text = "Small";
            this.BtnSmall.UseVisualStyleBackColor = true;
            this.BtnSmall.CheckedChanged += new System.EventHandler(this.radioButton1_CheckedChanged);
            // 
            // labText
            // 
            this.labText.AutoSize = true;
            this.labText.BackColor = System.Drawing.Color.Transparent;
            this.labText.Font = new System.Drawing.Font("Microsoft Sans Serif", 36F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.labText.ForeColor = System.Drawing.Color.Gold;
            this.labText.Location = new System.Drawing.Point(566, 158);
            this.labText.Name = "labText";
            this.labText.Size = new System.Drawing.Size(591, 69);
            this.labText.TabIndex = 0;
            this.labText.Text = "MAKE YOUR PİZZA";
            this.labText.Click += new System.EventHandler(this.labText_Click);
            // 
            // PanToppings
            // 
            this.PanToppings.BackColor = System.Drawing.Color.Transparent;
            this.PanToppings.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.PanToppings.Controls.Add(this.CheckGreenPaper);
            this.PanToppings.Controls.Add(this.CheckOlives);
            this.PanToppings.Controls.Add(this.CheckOnion);
            this.PanToppings.Controls.Add(this.CheckTomato);
            this.PanToppings.Controls.Add(this.CheckMushroom);
            this.PanToppings.Controls.Add(this.checkExtraCheese);
            this.PanToppings.Controls.Add(this.labToppings);
            this.PanToppings.Location = new System.Drawing.Point(578, 240);
            this.PanToppings.Name = "PanToppings";
            this.PanToppings.Size = new System.Drawing.Size(386, 192);
            this.PanToppings.TabIndex = 2;
            this.PanToppings.Paint += new System.Windows.Forms.PaintEventHandler(this.PanToppings_Paint);
            // 
            // CheckGreenPaper
            // 
            this.CheckGreenPaper.AutoSize = true;
            this.CheckGreenPaper.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.CheckGreenPaper.ForeColor = System.Drawing.Color.Gold;
            this.CheckGreenPaper.Location = new System.Drawing.Point(226, 142);
            this.CheckGreenPaper.Name = "CheckGreenPaper";
            this.CheckGreenPaper.Size = new System.Drawing.Size(156, 29);
            this.CheckGreenPaper.TabIndex = 9;
            this.CheckGreenPaper.Text = "Green Paper";
            this.CheckGreenPaper.UseVisualStyleBackColor = true;
            this.CheckGreenPaper.CheckedChanged += new System.EventHandler(this.checkBox6_CheckedChanged);
            // 
            // CheckOlives
            // 
            this.CheckOlives.AutoSize = true;
            this.CheckOlives.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.CheckOlives.ForeColor = System.Drawing.Color.Gold;
            this.CheckOlives.Location = new System.Drawing.Point(226, 93);
            this.CheckOlives.Name = "CheckOlives";
            this.CheckOlives.Size = new System.Drawing.Size(95, 29);
            this.CheckOlives.TabIndex = 8;
            this.CheckOlives.Text = "Olives";
            this.CheckOlives.UseVisualStyleBackColor = true;
            this.CheckOlives.CheckedChanged += new System.EventHandler(this.checkBox5_CheckedChanged);
            // 
            // CheckOnion
            // 
            this.CheckOnion.AutoSize = true;
            this.CheckOnion.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.CheckOnion.ForeColor = System.Drawing.Color.Gold;
            this.CheckOnion.Location = new System.Drawing.Point(226, 39);
            this.CheckOnion.Name = "CheckOnion";
            this.CheckOnion.Size = new System.Drawing.Size(92, 29);
            this.CheckOnion.TabIndex = 7;
            this.CheckOnion.Text = "Onion";
            this.CheckOnion.UseVisualStyleBackColor = true;
            this.CheckOnion.CheckedChanged += new System.EventHandler(this.checkBox4_CheckedChanged);
            // 
            // CheckTomato
            // 
            this.CheckTomato.AutoSize = true;
            this.CheckTomato.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.CheckTomato.ForeColor = System.Drawing.Color.Gold;
            this.CheckTomato.Location = new System.Drawing.Point(7, 142);
            this.CheckTomato.Name = "CheckTomato";
            this.CheckTomato.Size = new System.Drawing.Size(107, 29);
            this.CheckTomato.TabIndex = 6;
            this.CheckTomato.Text = "Tomato";
            this.CheckTomato.UseVisualStyleBackColor = true;
            this.CheckTomato.CheckedChanged += new System.EventHandler(this.checkBox3_CheckedChanged);
            // 
            // CheckMushroom
            // 
            this.CheckMushroom.AutoSize = true;
            this.CheckMushroom.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.CheckMushroom.ForeColor = System.Drawing.Color.Gold;
            this.CheckMushroom.Location = new System.Drawing.Point(7, 93);
            this.CheckMushroom.Name = "CheckMushroom";
            this.CheckMushroom.Size = new System.Drawing.Size(135, 29);
            this.CheckMushroom.TabIndex = 5;
            this.CheckMushroom.Text = "Mushroom";
            this.CheckMushroom.UseVisualStyleBackColor = true;
            this.CheckMushroom.CheckedChanged += new System.EventHandler(this.checkBox2_CheckedChanged);
            // 
            // checkExtraCheese
            // 
            this.checkExtraCheese.AutoSize = true;
            this.checkExtraCheese.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.checkExtraCheese.ForeColor = System.Drawing.Color.Gold;
            this.checkExtraCheese.Location = new System.Drawing.Point(7, 39);
            this.checkExtraCheese.Name = "checkExtraCheese";
            this.checkExtraCheese.Size = new System.Drawing.Size(165, 29);
            this.checkExtraCheese.TabIndex = 4;
            this.checkExtraCheese.Text = "Extra Cheese";
            this.checkExtraCheese.UseVisualStyleBackColor = true;
            this.checkExtraCheese.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // labToppings
            // 
            this.labToppings.AutoSize = true;
            this.labToppings.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.labToppings.ForeColor = System.Drawing.Color.Gold;
            this.labToppings.Location = new System.Drawing.Point(3, 0);
            this.labToppings.Name = "labToppings";
            this.labToppings.Size = new System.Drawing.Size(140, 32);
            this.labToppings.TabIndex = 5;
            this.labToppings.Text = "Toppings";
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.Transparent;
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel1.Controls.Add(this.btnThink);
            this.panel1.Controls.Add(this.btnThin);
            this.panel1.Controls.Add(this.PanCrust);
            this.panel1.Location = new System.Drawing.Point(365, 447);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(224, 118);
            this.panel1.TabIndex = 3;
            // 
            // btnThink
            // 
            this.btnThink.AutoSize = true;
            this.btnThink.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.btnThink.ForeColor = System.Drawing.Color.Gold;
            this.btnThink.Location = new System.Drawing.Point(7, 78);
            this.btnThink.Name = "btnThink";
            this.btnThink.Size = new System.Drawing.Size(144, 29);
            this.btnThink.TabIndex = 6;
            this.btnThink.TabStop = true;
            this.btnThink.Text = "Thick Crust";
            this.btnThink.UseVisualStyleBackColor = true;
            // 
            // btnThin
            // 
            this.btnThin.AutoSize = true;
            this.btnThin.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.btnThin.ForeColor = System.Drawing.Color.Gold;
            this.btnThin.Location = new System.Drawing.Point(7, 37);
            this.btnThin.Name = "btnThin";
            this.btnThin.Size = new System.Drawing.Size(134, 29);
            this.btnThin.TabIndex = 5;
            this.btnThin.TabStop = true;
            this.btnThin.Text = "Thin Crust";
            this.btnThin.UseVisualStyleBackColor = true;
            // 
            // PanCrust
            // 
            this.PanCrust.AutoSize = true;
            this.PanCrust.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.PanCrust.ForeColor = System.Drawing.Color.Gold;
            this.PanCrust.Location = new System.Drawing.Point(3, 0);
            this.PanCrust.Name = "PanCrust";
            this.PanCrust.Size = new System.Drawing.Size(161, 32);
            this.PanCrust.TabIndex = 4;
            this.PanCrust.Text = "Crust Type";
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.Transparent;
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel2.Controls.Add(this.btnTakeout);
            this.panel2.Controls.Add(this.btnEatIn);
            this.panel2.Controls.Add(this.lapToEat);
            this.panel2.Location = new System.Drawing.Point(639, 447);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(313, 122);
            this.panel2.TabIndex = 4;
            this.panel2.Paint += new System.Windows.Forms.PaintEventHandler(this.panel2_Paint);
            // 
            // btnTakeout
            // 
            this.btnTakeout.AutoSize = true;
            this.btnTakeout.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.btnTakeout.ForeColor = System.Drawing.Color.Gold;
            this.btnTakeout.Location = new System.Drawing.Point(134, 64);
            this.btnTakeout.Name = "btnTakeout";
            this.btnTakeout.Size = new System.Drawing.Size(123, 29);
            this.btnTakeout.TabIndex = 6;
            this.btnTakeout.TabStop = true;
            this.btnTakeout.Text = "Take Out";
            this.btnTakeout.UseVisualStyleBackColor = true;
            this.btnTakeout.CheckedChanged += new System.EventHandler(this.btnTakeout_CheckedChanged);
            // 
            // btnEatIn
            // 
            this.btnEatIn.AutoSize = true;
            this.btnEatIn.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.btnEatIn.ForeColor = System.Drawing.Color.Gold;
            this.btnEatIn.Location = new System.Drawing.Point(7, 64);
            this.btnEatIn.Name = "btnEatIn";
            this.btnEatIn.Size = new System.Drawing.Size(89, 29);
            this.btnEatIn.TabIndex = 5;
            this.btnEatIn.TabStop = true;
            this.btnEatIn.Text = "Eat In";
            this.btnEatIn.UseVisualStyleBackColor = true;
            // 
            // lapToEat
            // 
            this.lapToEat.AutoSize = true;
            this.lapToEat.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.lapToEat.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.lapToEat.ForeColor = System.Drawing.Color.Gold;
            this.lapToEat.Location = new System.Drawing.Point(3, 0);
            this.lapToEat.Name = "lapToEat";
            this.lapToEat.Size = new System.Drawing.Size(201, 34);
            this.lapToEat.TabIndex = 4;
            this.lapToEat.Text = "Where To Eat";
            // 
            // panel3
            // 
            this.panel3.BackColor = System.Drawing.Color.Transparent;
            this.panel3.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel3.Controls.Add(this.label10);
            this.panel3.Controls.Add(this.ToEat);
            this.panel3.Controls.Add(this.labCrust);
            this.panel3.Controls.Add(this.label7);
            this.panel3.Controls.Add(this.LapPrintSize);
            this.panel3.Controls.Add(this.label6);
            this.panel3.Controls.Add(this.label5);
            this.panel3.Controls.Add(this.label4);
            this.panel3.Controls.Add(this.label3);
            this.panel3.Controls.Add(this.label2);
            this.panel3.Controls.Add(this.label1);
            this.panel3.Location = new System.Drawing.Point(991, 240);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(345, 361);
            this.panel3.TabIndex = 5;
            this.panel3.Paint += new System.Windows.Forms.PaintEventHandler(this.panel3_Paint);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label10.ForeColor = System.Drawing.Color.ForestGreen;
            this.label10.Location = new System.Drawing.Point(176, 313);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(34, 46);
            this.label10.TabIndex = 14;
            this.label10.Text = "-";
            // 
            // ToEat
            // 
            this.ToEat.AutoSize = true;
            this.ToEat.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.ToEat.ForeColor = System.Drawing.Color.DarkGoldenrod;
            this.ToEat.Location = new System.Drawing.Point(216, 271);
            this.ToEat.Name = "ToEat";
            this.ToEat.Size = new System.Drawing.Size(20, 25);
            this.ToEat.TabIndex = 13;
            this.ToEat.Text = "-";
            this.ToEat.Click += new System.EventHandler(this.ToEat_Click);
            // 
            // labCrust
            // 
            this.labCrust.AutoSize = true;
            this.labCrust.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.labCrust.ForeColor = System.Drawing.Color.DarkGoldenrod;
            this.labCrust.Location = new System.Drawing.Point(179, 215);
            this.labCrust.Name = "labCrust";
            this.labCrust.Size = new System.Drawing.Size(20, 25);
            this.labCrust.TabIndex = 12;
            this.labCrust.Text = "-";
            // 
            // label7
            // 
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label7.ForeColor = System.Drawing.Color.DarkGoldenrod;
            this.label7.Location = new System.Drawing.Point(8, 151);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(330, 58);
            this.label7.TabIndex = 11;
            this.label7.Text = "-";
            this.label7.Click += new System.EventHandler(this.label7_Click);
            // 
            // LapPrintSize
            // 
            this.LapPrintSize.AutoSize = true;
            this.LapPrintSize.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.LapPrintSize.ForeColor = System.Drawing.Color.DarkGoldenrod;
            this.LapPrintSize.Location = new System.Drawing.Point(83, 62);
            this.LapPrintSize.Name = "LapPrintSize";
            this.LapPrintSize.Size = new System.Drawing.Size(20, 25);
            this.LapPrintSize.TabIndex = 10;
            this.LapPrintSize.Text = "-";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label6.ForeColor = System.Drawing.Color.Gold;
            this.label6.Location = new System.Drawing.Point(4, 318);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(123, 25);
            this.label6.TabIndex = 9;
            this.label6.Text = "Total Price:";
            this.label6.Click += new System.EventHandler(this.label6_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label5.ForeColor = System.Drawing.Color.Gold;
            this.label5.Location = new System.Drawing.Point(2, 266);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(208, 32);
            this.label5.TabIndex = 8;
            this.label5.Text = "Where To Eat:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label4.ForeColor = System.Drawing.Color.Gold;
            this.label4.Location = new System.Drawing.Point(3, 209);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(170, 32);
            this.label4.TabIndex = 7;
            this.label4.Text = "Crust Type:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label3.ForeColor = System.Drawing.Color.Gold;
            this.label3.Location = new System.Drawing.Point(3, 107);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(149, 32);
            this.label3.TabIndex = 6;
            this.label3.Text = "Toppings:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label2.ForeColor = System.Drawing.Color.Gold;
            this.label2.Location = new System.Drawing.Point(3, 55);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(74, 32);
            this.label2.TabIndex = 5;
            this.label2.Text = "Size";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label1.ForeColor = System.Drawing.Color.Gold;
            this.label1.Location = new System.Drawing.Point(3, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(226, 32);
            this.label1.TabIndex = 4;
            this.label1.Text = "Order Summary";
            // 
            // btnorder
            // 
            this.btnorder.BackColor = System.Drawing.Color.DarkGreen;
            this.btnorder.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnorder.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.btnorder.ForeColor = System.Drawing.Color.White;
            this.btnorder.Location = new System.Drawing.Point(500, 575);
            this.btnorder.Name = "btnorder";
            this.btnorder.Size = new System.Drawing.Size(223, 37);
            this.btnorder.TabIndex = 6;
            this.btnorder.Text = "Order Pizza";
            this.btnorder.UseVisualStyleBackColor = false;
            this.btnorder.UseWaitCursor = true;
            this.btnorder.Click += new System.EventHandler(this.btnorder_Click);
            // 
            // btnReset
            // 
            this.btnReset.BackColor = System.Drawing.Color.Brown;
            this.btnReset.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnReset.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.btnReset.ForeColor = System.Drawing.Color.White;
            this.btnReset.Location = new System.Drawing.Point(753, 575);
            this.btnReset.Name = "btnReset";
            this.btnReset.Size = new System.Drawing.Size(223, 37);
            this.btnReset.TabIndex = 7;
            this.btnReset.Text = "Reset";
            this.btnReset.UseVisualStyleBackColor = false;
            this.btnReset.UseWaitCursor = true;
            this.btnReset.Click += new System.EventHandler(this.btnReset_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::PizzaProject.Properties.Resources.Gemini_Generated_Image_8f49698f49698f49;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(1819, 788);
            this.Controls.Add(this.btnReset);
            this.Controls.Add(this.btnorder);
            this.Controls.Add(this.panel3);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.PanToppings);
            this.Controls.Add(this.labText);
            this.Controls.Add(this.PanSize);
            this.ForeColor = System.Drawing.SystemColors.Control;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Pizza Order";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.PanSize.ResumeLayout(false);
            this.PanSize.PerformLayout();
            this.PanToppings.ResumeLayout(false);
            this.PanToppings.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.panel3.ResumeLayout(false);
            this.panel3.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel PanSize;
        private System.Windows.Forms.Label LabSize;
        private System.Windows.Forms.RadioButton BtnLarge;
        private System.Windows.Forms.RadioButton BtnMed;
        private System.Windows.Forms.RadioButton BtnSmall;
        private System.Windows.Forms.Label labText;
        private System.Windows.Forms.Panel PanToppings;
        private System.Windows.Forms.CheckBox CheckGreenPaper;
        private System.Windows.Forms.CheckBox CheckOlives;
        private System.Windows.Forms.CheckBox CheckOnion;
        private System.Windows.Forms.CheckBox CheckTomato;
        private System.Windows.Forms.CheckBox CheckMushroom;
        private System.Windows.Forms.CheckBox checkExtraCheese;
        private System.Windows.Forms.Label labToppings;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.ComponentModel.BackgroundWorker backgroundWorker2;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label PanCrust;
        private System.Windows.Forms.RadioButton btnThink;
        private System.Windows.Forms.RadioButton btnThin;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.RadioButton btnTakeout;
        private System.Windows.Forms.RadioButton btnEatIn;
        private System.Windows.Forms.Label lapToEat;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label LapPrintSize;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label ToEat;
        private System.Windows.Forms.Label labCrust;
        private System.Windows.Forms.Button btnorder;
        private System.Windows.Forms.Button btnReset;
    }
}

