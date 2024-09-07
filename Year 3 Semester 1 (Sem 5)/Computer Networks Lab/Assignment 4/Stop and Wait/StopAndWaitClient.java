import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.util.Arrays;

public class StopAndWaitClient {
    private static final int PACKET_SIZE = 1024;

    private InetAddress address;
    private DatagramSocket socket;
    private int port;

    public StopAndWaitClient(InetAddress address, int port) throws SocketException {
        this.port = port;
        this.address = address;
        socket = new DatagramSocket();
    }

    private byte[] stringToByteArray(String dataString) throws UnsupportedEncodingException {
        return dataString.getBytes("UTF-8");
    }

    private char[] stringToCharArray(String dataString) {
        String middle = dataString.substring(1, dataString.length() - 1);
        String elementsString[] = middle.split(", ");
        char elementsChar[] = new char[elementsString.length];

        for (int x = 0; x < elementsString.length; x++)
            elementsChar[x] = (char) Integer.parseInt(elementsString[x]);

        return elementsChar;
    }

    public void sendPacket(String dataString) throws IOException {
        byte data[] = stringToByteArray(dataString);
        DatagramPacket packet = new DatagramPacket(data, data.length, address, port);

        System.out.println("Sending acknowledgement.");
        socket.send(packet);
    }

    public char[] receivePacket() throws IOException {
        byte data[] = new byte[PACKET_SIZE];
        DatagramPacket packet = new DatagramPacket(data, data.length);
        socket.receive(packet);
        return stringToCharArray(Arrays.toString(data));
    }

    public String[] receiveTransmission() throws IOException {
        String messages[] = new String[10];

        for (int x = 1; x < messages.length; x++) {
            char data[] = receivePacket();
            System.out.print("Received packet... ");

            if (data[0] == '\0')
                break;

            messages[x] = new String(data);
            String index = messages[x].substring(0, 1);
            messages[x] = messages[x].substring(1, messages[x].length() - 1);

            sendPacket(index);
        }

        System.out.println("Destroyed connection.\n");

        return messages;
    }

    public static void main(String[] args) throws IOException {
        InetAddress address = InetAddress.getByName("localhost");
        int port = 5000;
        StopAndWaitClient sawc = new StopAndWaitClient(address, port);
        System.out.println("Initiating connection...");
        sawc.sendPacket("initiate");
        System.out.println();

        String messages[] = sawc.receiveTransmission();
        for (int x = 1; x < messages.length; x++)
            if (messages[x] != null)
                System.out.println("Message: " + messages[x]);
    }
}
