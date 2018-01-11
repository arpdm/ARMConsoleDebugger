using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace SYSInterface
{
    public partial class MainWindow : Window
    {

        private SerialLib serialLib = new SerialLib();

        /*****************************************************************************
        * Function :   MainWindow
        * Input    :   none
        * Output   :   none
        * Comment  :   main function runs on load
        ****************************************************************************/

        public MainWindow()
        {

            InitializeComponent();

            //Set the current system time
            setTimeStamp();

            //Configure all UI Objects
            configureCommPortComboBox();
            configureBaudRateComboBox();
            configureParityComboBox();
            configureDataBitsComboBox();
            configureStopBitsComboBox();
            configureHandshakeComboBox();

        }

        /*****************************************************************************
         * Function :   setTimeStamp
         * Input    :   none
         * Output   :   none
         * Comment  :   Gets the current system date time
         ****************************************************************************/

        private void setTimeStamp()
        {

            timeStampTxt.Text = DateTime.Now.ToString();

        }

        /*****************************************************************************
         * Function :   configureCommPortComboBox
         * Input    :   none
         * Output   :   none
         * Comment  :   
         ****************************************************************************/

        private void configureCommPortComboBox()
        {

            String[] commPorts = this.serialLib.GetCommPorts();

            //First clear all the items before re populating the dropdown
            comPortComboBox.Items.Clear();

            //Add all detectected comm ports to the combo box
            foreach (string port in commPorts)
            {

                comPortComboBox.Items.Add(port);

            }
        }

        /*****************************************************************************
         * Function :   configureBaudRateComboBox
         * Input    :   none
         * Output   :   none
         * Comment  :   
         ****************************************************************************/

        private void configureBaudRateComboBox()
        {

            baudRateComboBox.Items.Clear();
            baudRateComboBox.Items.Add(1200);
            baudRateComboBox.Items.Add(2400);
            baudRateComboBox.Items.Add(4800);
            baudRateComboBox.Items.Add(9600);
            baudRateComboBox.Items.Add(19200);
            baudRateComboBox.Items.Add(38400);
            baudRateComboBox.Items.Add(57600);
            baudRateComboBox.Items.Add(115200);

        }

        /*****************************************************************************
         * Function :   configureParityComboBox
         * Input    :   none
         * Output   :   none
         * Comment  :   
         ****************************************************************************/

        private void configureParityComboBox()
        {

            parityComboBox.Items.Clear();
            parityComboBox.Items.Add("None");
            parityComboBox.Items.Add("Even");
            parityComboBox.Items.Add("Odd");

        }

        /*****************************************************************************
         * Function :   configureDataBitsComboBox
         * Input    :   none
         * Output   :   none
         * Comment  :   
         ****************************************************************************/

        private void configureDataBitsComboBox()
        {

            dataBitsComboBox.Items.Clear();
            dataBitsComboBox.Items.Add("8 bits");
            dataBitsComboBox.Items.Add("7 bits");

        }

        /*****************************************************************************
         * Function :   configureStopBitsComboBox
         * Input    :   none
         * Output   :   none
         * Comment  :   
         ****************************************************************************/

        private void configureStopBitsComboBox()
        {

            stopBitsComboBox.Items.Clear();
            stopBitsComboBox.Items.Add("1 bit");
            stopBitsComboBox.Items.Add("2 bits");

        }

        /*****************************************************************************
         * Function :   configureHandshakeComboBox
         * Input    :   none
         * Output   :   none
         * Comment  :   
         ****************************************************************************/

        private void configureHandshakeComboBox()
        {

            handShakeComboBox.Items.Clear();
            handShakeComboBox.Items.Add("None");
            handShakeComboBox.Items.Add("RTS/CTS");

        }

        /*****************************************************************************
         * Function :   openCommBtn_Click
         * Input    :   none
         * Output   :   none
         * Comment  :   
         ****************************************************************************/

        private void openCommBtn_Click(object sender, RoutedEventArgs e)
        {


            //TODO: Initialize SerialLib
            //TODO: Open Connection
            //TODO: Clear the buffer

        }

        /*****************************************************************************
         * Function :   closeCommBtn_Click
         * Input    :   none
         * Output   :   none
         * Comment  :   
         ****************************************************************************/

        private void closeCommBtn_Click(object sender, RoutedEventArgs e)
        {


            //TODO: Clear the buffer
            //TODO: Close the SerialLib communication

        }

        /*****************************************************************************
         * Function :   clearBufferBtn_Click
         * Input    :   none
         * Output   :   none
         * Comment  :   
         ****************************************************************************/

        private void clearBufferBtn_Click(object sender, RoutedEventArgs e)
        {


        }
    }
}
