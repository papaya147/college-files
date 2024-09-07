import java.util.Scanner;

public class Question8 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Cow cow = new Cow(s.next(), s.next());
        Cat cat = new Cat(s.next(), s.next());
        Dog dog = new Dog(s.next());
        cow.displaySound();
        cat.displaySound();
        dog.display();
        s.close();
    }
}

class Animal {
    String type = "Animal";
    String sound = "Sound";
    String eat = "Food it likes";
}

class Cow extends Animal {
    String name = "Cow";

    Cow(String sound, String eat) {
        this.sound = sound;
        this.eat = eat;
    }

    void displaySound() {
        System.out.println(this.name + " makes a " + this.sound + " sound and eats " + this.eat);
    }
}

class Cat extends Animal {
    String name = "Cat";

    Cat(String sound, String eat) {
        this.sound = sound;
        this.eat = eat;
    }

    void displaySound() {
        System.out.println(this.name + " makes a " + this.sound + " sound and eats " + this.eat);
    }
}

class Dog extends Animal {
    String name;

    Dog(String name) {
        this.name = name;
    }

    void display() {
        System.out.println(this.name + " is the dogs name");
    }
}
