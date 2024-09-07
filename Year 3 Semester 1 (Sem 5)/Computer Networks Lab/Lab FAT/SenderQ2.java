import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Arrays;

public class SenderQ2 {
    private static final int PACKET_SIZE = 1024;

    private InetAddress address;
    private DatagramSocket socket;
    private int port;

    public SenderQ2(int port) throws IOException {
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

    public static void main(String[] args) throws IOException {
        int port = 5000;
        SenderQ2 sq2 = new SenderQ2(port);
        System.out.println("Waiting for connection... ");
        sq2.receivePacket();
        System.out.println();

        System.out.println("Sending packet 0");
        sq2.sendPacket("0packet0");
        System.out.println("Sending packet 1");
        sq2.sendPacket("1packet1");
        System.out.println("Sending packet 2");
        sq2.sendPacket("2packet2");
        System.out.println("Sending packet 3");
        sq2.sendPacket("3packet3");
        System.out.println("Sending packet 4 ...packet lost");
        System.out.println("Sending packet 4");
        sq2.sendPacket("4packet4");
        System.out.println("Sending packet 5");
        sq2.sendPacket("5packet5");
        System.out.println("Sending packet 6");
        sq2.sendPacket("6packet6");
        System.out.println("Sending packet 7");
        sq2.sendPacket("7packet7");
        System.out.println("\nEnding connection.");
    }
}