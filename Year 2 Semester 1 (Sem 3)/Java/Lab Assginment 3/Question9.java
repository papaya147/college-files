import java.util.Scanner;

public class Question9 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Truck t = new Truck(s.next(), s.nextInt());
        Car c = new Car(s.next(), s.nextInt());
        t.display();
        t.vehicleManufacturer();
        c.display();
        c.vehicleManufacturer();
        s.close();
    }
}

class Vehicle {
    String purpose;
    int wheels;

    void vehicleManufacturer() {
        System.out.println("The name of the vehicle manufacturer is Benz.");
    }
}

class Truck extends Vehicle {
    String name = "Truck";

    Truck(String purpose, int wheels) {
        this.purpose = purpose;
        this.wheels = wheels;
    }

    void display() {
        System.out.println(this.name + " has " + this.wheels + " wheels and is used for " + this.purpose);
    }

    void vehicleManufacturer() {
        System.out.println("The name of the vehicle manufacturer is Tata");
    }
}

class Car extends Vehicle {
    String name = "Car";

    Car(String purpose, int wheels) {
        this.purpose = purpose;
        this.wheels = wheels;
    }

    void display() {
        System.out.println(this.name + " has " + this.wheels + " wheels and is used for " + this.purpose);
    }

    void vehicleManufacturer() {
        System.out.println("The name of the vehicle manufacturer is Jaguar");
    }
}