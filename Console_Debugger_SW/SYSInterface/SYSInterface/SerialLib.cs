using System;
using System.IO.Ports;
using System.Text;
using System.Threading;

public class SerialLib
{

    private static SerialPort serialPort = new SerialPort();

    //Serial Comm Configuration

    private int baudRate = 115200;
    private int dataBits = 8;
    private Parity parity = Parity.None;
    private string portName = "COM3";
    private StopBits stopBits = StopBits.One;
    private Handshake handshake = Handshake.None;

    //Rx Buffer Parameters

    private int rxTimeout = 500;

    /*****************************************************************************
     * Function :   GetCommPorts
     * Input    :   none
     * Output   :   List of detected comm ports
     * Comment  :   Gets all the comm ports detected from device manager
     ****************************************************************************/

    public string[] GetCommPorts()
    {

        string[] commPorts = SerialPort.GetPortNames();
        Console.WriteLine(SerialPort.GetPortNames());
        return commPorts;

    }

    /*****************************************************************************
     * Function :   OpenSerialConnection
     * Input    :   none
     * Output   :   none
     * Comment  :   Opens a new serial communication
     ****************************************************************************/

    public void Initialize(int baudRate, int dataBits, string portName, Parity parity, StopBits stopBits, Handshake handshake)
    {

        this.baudRate = baudRate;
        this.dataBits = dataBits;
        this.portName = portName;
        this.parity = parity;
        this.stopBits = stopBits;
        this.handshake = handshake;

    }

    /*****************************************************************************
     * Function :   OpenSerialConnection
     * Input    :   none
     * Output   :   none
     * Comment  :   Opens a new serial communication
     ****************************************************************************/

    public bool OpenSerialConnection()
    {

        try
        {

            serialPort.BaudRate = this.baudRate;
            serialPort.DataBits = this.dataBits;
            serialPort.Handshake = this.handshake;
            serialPort.Parity = this.parity;
            serialPort.PortName = this.portName;
            serialPort.StopBits = this.stopBits;
            serialPort.ReadTimeout = this.rxTimeout;


        }
        catch
        {

            return false;

        }

        //Open the serial port
        serialPort.Open();

        return true;

    }

    /*****************************************************************************
     * Function :   close
     * Input    :   none
     * Output   :   none
     * Comment  :   Close the serial connection
     ****************************************************************************/

    public void close()
    {


    }

    /*****************************************************************************
     * Function :   rxData
     * Input    :   none
     * Output   :   none
     * Comment  :   Reads individual bytes recieved from Peripheral device
     ****************************************************************************/

    public string rxData()
    {

        string rxData = serialPort.ReadLine();
        return rxData;

    }

}