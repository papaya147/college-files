import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Arrays;

public class StopAndWaitServer {
    private static final int PACKET_SIZE = 1024;

    private InetAddress address;
    private DatagramSocket socket;
    private int port;

    public StopAndWaitServer(int port) throws IOException {
        this.port = port;
        this.socket = new DatagramSocket(port);
    }

    private char[] stringToCharArray(String dataString) {
        String middle = dataString.substring(1, dataString.length() - 1);
        String elementsString[] = middle.split(", ");
        char elementsInt[] = new char[elementsString.length];

        for (int x = 0; x < elementsString.length; x++)
            elementsInt[x] = (char) Integer.parseInt(elementsString[x]);

        return elementsInt;
    }

    private byte[] stringToByteArray(String dataString) throws UnsupportedEncodingException {
        return dataString.getBytes("UTF-8");
    }

    private char[] receivePacket() throws IOException {
        byte data[] = new byte[PACKET_SIZE];
        DatagramPacket packet = new DatagramPacket(data, data.length);
        socket.receive(packet);
        System.out.println("Received acknowledgement.");

        this.address = packet.getAddress();
        this.port = packet.getPort();
        return stringToCharArray(Arrays.toString(data));
    }

    private void sendPacket(String dataString) throws IOException {
        byte dataByte[] = stringToByteArray(dataString);
        DatagramPacket packet = new DatagramPacket(dataByte, dataByte.length,
                this.address, this.port);
        socket.send(packet);
    }

    private boolean checkAck(int expectedPacketNumber, char data[]) {
        return ((char) expectedPacketNumber) == (data[0] - '0');
    }

    private void sendData(String dataString) throws IOException {
        int packetNumber = 1;

        for (int x = 0; x <= dataString.length() / 1023; x++) {
            String data = Integer.toString(packetNumber);
            if (x + PACKET_SIZE - 1 < dataString.length() - 1)
                data += dataString.substring(x, x + PACKET_SIZE - 1);
            else
                data += dataString.substring(x, dataString.length());

            boolean ack = false;
            while (!ack) {
                System.out.print("Sending packet " + packetNumber + "... ");
                sendPacket(data);
                char response[] = receivePacket();
                ack = checkAck(packetNumber, response);
            }

            packetNumber++;
        }

        sendPacket("");
    }

    public static void main(String[] args) throws IOException {
        int port = 5000;
        String data = "Hi my name is Abhinav Dinesh Srivatsa.\nMy registeration number is: 21BDS0340.";
        StopAndWaitServer saws = new StopAndWaitServer(port);
        System.out.println("Waiting for connection... ");
        saws.receivePacket();
        System.out.println();

        saws.sendData(data);
        System.out.println("\nEnding connection.");
    }
}
