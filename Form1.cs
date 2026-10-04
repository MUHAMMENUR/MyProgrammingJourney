using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Printing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PizzaProject
{
    public partial class Form1 : Form
    {

         double GetSelectedSizePrice()
        {
            if(BtnSmall.Checked)
            {
                return 10;
            }
            else if (BtnMed.Checked)
            {
                return 20;
            }
            else if (BtnLarge.Checked)
            {
                return 30;
            }

            return 0;

        }

        double GetSelectedCrustPrice()
        {
            if (btnThin.Checked)
            {
                return 10;
            }
            else if (btnThink.Checked)
            {
                return 20;
            }
           
            return 0;
        }

        double CalculateToppingsPrice()
        {
            double toppingsPrice = 0;
            if (checkExtraCheese.Checked)
            {
                toppingsPrice += 10;
            }
            if (CheckMushroom.Checked)
            {
                toppingsPrice += 5;
            }
            if (CheckTomato.Checked)
            {
                toppingsPrice += 5;
            }
            if (CheckOnion.Checked)
            {
                toppingsPrice += 5;
            }
            if (CheckOlives.Checked)
            {
                toppingsPrice += 5;
            }
            if (CheckGreenPaper.Checked)
            {
                toppingsPrice += 5;
            }
            return toppingsPrice;
        }

        double GetSelectedWhereToEatPrice()
        {
            if (btnEatIn.Checked)
            {
                return 5;
            }
            else if (btnTakeout.Checked)
            {
                return 12;
            }
            return 0;
        }

        double CalculateTotalPrice()
        {
           return  GetSelectedSizePrice() + GetSelectedCrustPrice() + CalculateToppingsPrice() + GetSelectedWhereToEatPrice();
            
        }
        void UpdateOrderSummary()
        {
            if(BtnSmall.Checked)
            {
                LapPrintSize.Text = "Small";
            }
            else if (BtnMed.Checked)
            {
                LapPrintSize.Text = "Medium";
            }
            else if (BtnLarge.Checked)
            {
                LapPrintSize.Text = "Large";
            }

            if(btnThin.Checked)
            {
                labCrust.Text = "Thin";
            }
            else if (btnThink.Checked)
            {
                labCrust.Text = "Thick";
            }

            string toppings = "";
            if(checkExtraCheese.Checked)
            {
                toppings += "Extra Cheese, ";
            }
            if(CheckMushroom.Checked)
            {
                toppings += "Mushroom, ";
            }
            if(CheckTomato.Checked)
            {
                toppings += "Tomato, ";
            }
            if(CheckOnion.Checked)
            {
                toppings += "Onion, ";
            }
            if(CheckOlives.Checked)
            {
                toppings += "Olives, ";
            }
            if(CheckGreenPaper.Checked)
            {
                toppings += "Green Pepper, ";
            }
            if (toppings.EndsWith(", "))
            {
                toppings = toppings.Substring(0, toppings.Length - 2);
            }

            if(btnEatIn.Checked)
            {
                ToEat.Text = "Eat In";
            }
            else if (btnTakeout.Checked)
            {
                ToEat.Text = "Take Out";
            } 

            if (string.IsNullOrEmpty(toppings))
            {
                label7.Text = "No Toppings";
            }
            else
            {
                label7.Text = toppings;
            }

            label10.Text = "$" + CalculateTotalPrice().ToString();

        }

        void ResetForm()
        {
            BtnMed.Checked = true;

            btnThin.Checked = true;

            btnEatIn.Checked = true;

            checkExtraCheese.Checked = false;
            CheckMushroom.Checked = false;
            CheckTomato.Checked = false;
            CheckOnion.Checked = false;
            CheckOlives.Checked = false;
            CheckGreenPaper.Checked = false;

            PanSize.Enabled = true;
            PanCrust.Enabled = true;
            PanToppings.Enabled = true;
            panel2.Enabled = true;
            panel3.Enabled = true;
            panel1.Enabled = true;


            UpdateOrderSummary();
        }


        public Form1()
        {
            InitializeComponent();

            BtnSmall.CheckedChanged += AnyOption_CheckedChanged;
            BtnMed.CheckedChanged += AnyOption_CheckedChanged;
            BtnLarge.CheckedChanged += AnyOption_CheckedChanged;

            btnThin.CheckedChanged += AnyOption_CheckedChanged;
            btnThink.CheckedChanged += AnyOption_CheckedChanged;

            btnEatIn.CheckedChanged += AnyOption_CheckedChanged;
            btnTakeout.CheckedChanged += AnyOption_CheckedChanged;

            checkExtraCheese.CheckedChanged += AnyOption_CheckedChanged;
            CheckMushroom.CheckedChanged += AnyOption_CheckedChanged;
            CheckTomato.CheckedChanged += AnyOption_CheckedChanged;
            CheckOnion.CheckedChanged += AnyOption_CheckedChanged;
            CheckOlives.CheckedChanged += AnyOption_CheckedChanged;
            CheckGreenPaper.CheckedChanged += AnyOption_CheckedChanged;

        }

        private void GrSize_Enter(object sender, EventArgs e)
        {
            
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            ResetForm();

            Color overlayColor = Color.FromArgb(140, 0, 0, 0);

            PanSize.BackColor = overlayColor;
            PanToppings.BackColor = overlayColor;
            panel1.BackColor = overlayColor; 
            panel2.BackColor = overlayColor; 
            panel3.BackColor = overlayColor; 
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {

        }
        private void AnyOption_CheckedChanged(object sender, EventArgs e)
        {
            UpdateOrderSummary();
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox5_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox6_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void PanToppings_Paint(object sender, PaintEventArgs e)
        {

        }

        private void PanCrust_Paint(object sender, PaintEventArgs e)
        {

        }

        private void radioButton2_CheckedChanged_1(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged_1(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged_2(object sender, EventArgs e)
        {

        }

        private void btnTakeout_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void panel3_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void btnorder_Click(object sender, EventArgs e)
        {
            btnorder.BackColor = Color.DarkGreen;
            if (MessageBox.Show("Are you sure you want to confirm this order?", "Confirm Order",
                        MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                MessageBox.Show("Order Placed Successfully!", "Success",
                                MessageBoxButtons.OK, MessageBoxIcon.Information);

                PanSize.Enabled = false;
                panel1.Enabled = false;
                PanToppings.Enabled = false;
                panel2.Enabled = false;
                panel3.Enabled = false;
                
            }
        }

        private void btnReset_Click(object sender, EventArgs e)
        {
            ResetForm();
        }

        private void labText_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void ToEat_Click(object sender, EventArgs e)
        {

        }
    }
}
